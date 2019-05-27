//
//  fetchStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef fetchStage_h
#define fetchStage_h
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include "printInternalReg.h"

struct fetchStateStruct {
  unsigned char *instBase; // Where the program starts in memory
  unsigned char *lastAddr; // The last valid address in memory of the program

  uint64_t PC;   // The program counter associated with this instruction
                 // it is first set when initializeFetchStage is called


  // Add fields here to capture stage registers and state associated
  // with processing and managing the stage.
  nibble icode;
  nibble ifun;
  nibble rA;
  nibble rB;
  uint64_t valC;
  uint64_t valP;


  // holds the original icode and ifun in an exception
  nibble exception_icode;
  nibble exception_ifun;

  int bubble_ctr; // tracks bubble positions

};

struct fetchStateStruct processFetchStage(int tick);
struct fetchStateStruct getFetchState();
int initializeFetchState(int memoryFileFD, uint64_t initialPC);
void updateFetchStage();
void setFetchHazard(int bubble_ctr);
int checkAddr2Exception();
#endif /* fetchStage_h */
