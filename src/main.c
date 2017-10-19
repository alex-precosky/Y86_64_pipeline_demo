//
//  main.c
//  A2
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "printInternalReg.h"
#include "fetchStage.h"
#include "instructionSpecifications.h"
#include "decodeStage.h"
#include "executeStage.h"
#include "memoryStage.h"
#include "writeBackStage.h"

int main(int argc, char **argv) {
    
    int machineCodeFD = -1;       // File descriptor of file with object code
    
    // Verify that the command line has an appropriate number
    // of arguments
    
    if (argc < 2 || argc > 4) {
        printf("Usage: %s InputFilename [startingOffset] [ClockTicks]\n", argv[0]);
        return ERROR_RETURN;
    }
    
    // First argument is the file to open, attempt to open it
    // for reading and verify that the open did occur.
    machineCodeFD = open(argv[1], O_RDONLY);
    
    if (machineCodeFD < 0) {
        printf("Failed to open: %s\n", argv[1]);
        return ERROR_RETURN;
    }
    
    // Get the initial offset into the file
    
    uint64_t PC = 0;
    if (3 <= argc) {
        // See man page for strtol() as to why
        // we check for errors by examining errno
        errno = 0;
        PC = strtol(argv[2], NULL, 0);
        if (errno != 0) {
            perror("Invalid offset on command line");
            return ERROR_RETURN;
        }
    }
    
    // Get the count of how many clock ticks to run for.
    int endTime = -1;
    if (4 == argc) {
        errno = 0;
        endTime = strtol(argv[3], NULL, 0);
        if (errno != 0) {
            perror("Invalid end time on command line");
            return ERROR_RETURN;
        }
    }
    
    if (initializeFetchState(machineCodeFD, PC)) {
        printf("Initialization of fetch stage failed\n");
        return -99;
    };
   
    printf("Opened %s, starting offset 0x%016llX stop time = %d\n",
	   argv[1], PC, endTime);

    // initialize stages with NOP instructions from address zero
    struct writeBackStateStruct wbs = initializeWriteBackStage();
    struct memoryStateStruct ms = initializeMemoryStage();
    struct executeStateStruct es = initializeExecuteStage();
    struct decodeStateStruct ds = initializeDecodeStage();
    struct fetchStateStruct fs = getFetchState();

    int OK = 1;
    int bubble_position = -1; // 3=decode, 2=execute, 1=memory, 0=write back, -1=no bubble
    

    for (int clock = 0; OK ; clock++) {
      wbs = processWriteBackStage(clock);
      ms = processMemoryStage(clock);
      es = processExecuteStage(clock);
      ds = processDecodeStage(clock);
      fs = processFetchStage(clock);      
      printf("\n");
      // Here might be a good spot to add code or make function calls 
      // to check for hazards cause stage registers to be updated etc.

      // checking for a hazard and there not being a bubble already
      if(((fs.rA == ds.destE && fs.rA != UNNEEDED_REG) 
	  ||(fs.rB == ds.destE && fs.rB != UNNEEDED_REG && fs.icode != IRMOV)
	  ||(fs.rB == ds.destM && fs.rB != UNNEEDED_REG)
	  ||(fs.rA == ds.rB && ds.icode == MATH)
	  ||(fs.rB == ds.rB && ds.icode == MATH)
	  ||(fs.icode==PUSH && ds.icode==PUSH)
	  ||(fs.icode==POP && ds.icode==PUSH)
	  ||(fs.icode==POP && ds.icode==POP)
	  ||(fs.icode==PUSH && ds.icode==POP)
	  ||(fs.rA == ds.destM && fs.rA != UNNEEDED_REG)
	  )
	 && bubble_position < 0 && clock > 0)
	{
	  printf("Hazard\n");

	  bubble_position = 3;
	  
	  updateFetchStage();
	  updateDecodeStage(fs);

	  setFetchHazard(bubble_position);
	  setDecodeHazard(bubble_position);

	  bubble_position--;
	}
      else if( (fs.icode==RET 
	       || (fs.rB==es.destE && fs.rB != UNNEEDED_REG && fs.icode != IRMOV)
		||(fs.rA==es.destE && fs.rA != UNNEEDED_REG))
	       && bubble_position < 0)
	{
	  printf("Hazard\n");

	  bubble_position = 2;
	  
	  updateFetchStage();
	  updateDecodeStage(fs);

	  setFetchHazard(bubble_position);
	  setDecodeHazard(bubble_position);

	  bubble_position--;
	}
      else if( ((fs.rB==ms.destE && fs.rB != UNNEEDED_REG)
		||(fs.rA==ms.destE && fs.rA != UNNEEDED_REG))
	       && bubble_position < 0)
	{
	  printf("Hazard\n");

	  bubble_position = 1;
	  
	  updateFetchStage();
	  updateDecodeStage(fs);

	  setFetchHazard(bubble_position);
	  setDecodeHazard(bubble_position);

	  bubble_position--;
	}
      else if(bubble_position == 2) // previously detected bubble in progress
	{
	  setFetchHazard(bubble_position);
	  setDecodeHazard(bubble_position);

	  // next processExecute will be a NOP
	  ds.icode = NOP;
	  
	  updateExecuteStage(ds);
	  bubble_position--;

	}
      else if(bubble_position == 1) 
	{
	  ds.icode = NOP;
	  setFetchHazard(1);
	  setDecodeHazard(1);
	  bubble_position--;
	}
      else if(bubble_position == 0)
	{
	  ds.icode = NOP;
	  setFetchHazard(0);
	  setDecodeHazard(0);
	  bubble_position--;
	}
      else
	{
	  setFetchHazard(0);
	  setDecodeHazard(0);
	  updateFetchStage();
	  updateDecodeStage(fs);
	  updateExecuteStage(ds);
	  bubble_position--;
	}

      // no matter what, update execute, memory and write back stages
      updateExecuteStage(ds);
      updateMemoryStage(es);
      updateWriteBackStage(ms);


      if (endTime != -1) {
	if (clock >= endTime) {
	  printf("Time expired %d %d \n", clock, endTime);
	  OK = 0;
	}
      }
      
      // terminate on HALT instruction or exception being retired
      if(wbs.icode==HALT || wbs.icode==ADDRESSING_EXCEPTION  || wbs.icode==ADDRESSING_EXCEPTION2 || wbs.icode == INVALIDINSTRUCTION_EXCEPTION)
	OK = 0;
    }

    printf("Normal termination\n");
    return SUCCESS;
}


