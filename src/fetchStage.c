//
//  fetchStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "fetchStage.h"
#include "instructionSpecifications.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include "decodeStage.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct fetchStateStruct fs;


// This maps the file into main memory so that pointers can be used to access
// the instruction directly

int initializeFetchState(int memoryFileFD, uint64_t initialPC) {
    struct stat statBuff;
    
    if (fstat(memoryFileFD, &statBuff)) {
        return -2;
    }
 
    // Do the actual mapping.
    fs.instBase =  mmap(0, statBuff.st_size, PROT_READ,
                                MAP_PRIVATE, memoryFileFD, 0);
    if (fs.instBase == MAP_FAILED) {
        return -3;
    }
    fs.lastAddr = fs.instBase + statBuff.st_size;
    fs.PC = initialPC;

    fs.icode = NOP;
    fs.ifun = 0;

    return 0;
}

struct fetchStateStruct getFetchState()
{
  return fs;
}

struct fetchStateStruct processFetchStage(int tick) {


  fs.icode = (*(fs.instBase + fs.PC) & 0xF0) >> 4;
  fs.ifun = *(fs.instBase + fs.PC) & 0x0F;
  

  if( fs.icode == HALT )
    {
      fs.valP = fs.PC + 1;
    }
  else if( fs.icode == NOP)
    {
      fs.valP = fs.PC + 1;
    }
  else if( fs.icode == RRMOV) //rrmovq, cmovXX
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valP = fs.PC + 2;
    }
  else if( fs.icode == IRMOV)
    {
      fs.rA = 0xf;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
      fs.valP = fs.PC + 10;
    }
  else if( fs.icode == RMMOV)
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
      fs.valP = fs.PC + 10;
    }
  else if( fs.icode == MRMOV)
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
      fs.valP = fs.PC + 10;
    }
  else if( fs.icode == MATH) // OPq
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valP = fs.PC + 2;
    }
  else if( fs.icode == JUMP)
    {
      fs.valP = *(uint64_t *)(fs.instBase + fs.PC + 1);
    }
  else if( fs.icode == CALL)
    {
      fs.valP = *(uint64_t *)(fs.instBase+fs.PC+1);
    }
  else if( fs.icode == RET)
    {
      fs.valP = fs.PC+1;
    }
  else if( fs.icode == PUSH)
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = 0xF;
      fs.valP = fs.PC+2;
    }
  else if( fs.icode == POP)
    {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = 0xF;
      fs.valP = fs.PC+2;
    }

  

  // This example is for a stall
  //printReg("F W", 10, 0x100, 6,  2, 1, 10, 11,
	//   1, 10, 11,
	 //  0, UNNEEDED_REG, UNNEEDED_REG, 1, 0, 1, 12, "andq");
  // Something that uses valC
//  printReg("F", 12, 100, 7,  0, 1, 0xf , 0xF,
//	   0, UNNEEDED_REG, UNNEEDED_REG, 
//	   0, UNNEEDED_REG, UNNEEDED_REG, 1, 0x1234567811, 1, 109, 
 //          getInstructionMnemonic(7, 0));

  int isValidFunction = validFunctionCode(fs.icode, fs.ifun);
  char* instr;
  char* exceptionStr = "Exception";
  if(isValidFunction)
    instr = getInstructionMnemonic(fs.icode, fs.ifun);
  else
    instr = exceptionStr;

  printReg("F", // char* stage
	   tick, // int tick
	   fs.PC, // PC
	   fs.icode, // icode
	   fs.ifun, // ifun
	   1, fs.rA, fs.rB, // regsValid, rA, rB
	   0, UNNEEDED_REG, UNNEEDED_REG, // srcValid, srcA, srcB
	   0, UNNEEDED_REG, UNNEEDED_REG, // dstValid, destE, destM
	   1, fs.valC, // valCValid, valC
	   1, fs.valP, // valPValid, valP
	   instr); // char* instr
	   

  return fs;
}
