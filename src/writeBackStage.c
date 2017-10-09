//
//  writeBackStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "writeBackStage.h"
#include "instructionSpecifications.h"
#include "printInternalReg.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct writeBackStateStruct wbs;

struct writeBackStateStruct initializeWriteBackStage()
{
  wbs.PC=0;
  wbs.icode=NOP;
  wbs.destE = 0xF;
  wbs.destM = 0xF;

  return wbs;
  
}

struct writeBackStateStruct processWriteBackStage(int tick) {
  
 

//  printReg("W", 82, 0x299, 7, 2, 0, UNNEEDED_REG, UNNEEDED_REG,
//	   0, UNNEEDED_REG, UNNEEDED_REG,
//	   1, 0xF, 0xF, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, 
//	   getInstructionMnemonic(7, 2));
  

  int isValidFunction = validFunctionCode(wbs.icode, wbs.ifun);
  char* instr;
  char* exceptionStr = "Exception";
  if(isValidFunction)
    instr = getInstructionMnemonic(wbs.icode, wbs.ifun);
  else
    instr = exceptionStr;

  printReg("W", // char* stage
	   tick, // int tick
	   wbs.PC, // PC
	   wbs.icode, // icode
	   wbs.ifun, // ifun
	   0, UNNEEDED_REG, UNNEEDED_REG, // regsValid, rA, rB
	   0, UNNEEDED_REG, UNNEEDED_REG, // srcValid, srcA, srcB
	   1, wbs.destE, wbs.destM, // dstValid, destE, destM
	   0, UNNEEDED_ADDR, // valCValid, valC
	   0, UNNEEDED_ADDR, // valPValid, valP
	   instr); // char* instr

  return wbs;
}

void updateWriteBackStage(struct memoryStateStruct ms)
{
  wbs.PC = ms.PC;
  wbs.icode = ms.icode;
  wbs.ifun = ms.ifun;
  wbs.destE = ms.destE;
  wbs.destM = ms.destM;
}
