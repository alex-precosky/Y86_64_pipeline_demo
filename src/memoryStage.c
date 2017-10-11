//
//  memoryStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "memoryStage.h"
#include "writeBackStage.h"
#include "executeStage.h"
#include "printInternalReg.h"
#include "instructionSpecifications.h"


// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct memoryStateStruct ms;


struct memoryStateStruct initializeMemoryStage(void)
{
  ms.PC=0;
  ms.icode=NOP;
  ms.ifun=0;
  ms.destE=0xF;
  ms.destM=0xF;
  ms.valE = 0xF;

  return ms;
}

struct memoryStateStruct processMemoryStage(int tick) {

  // probably empty as well but here is sample of printing
//   printReg("M", 10, 45, 1, 0, 0, UNNEEDED_REG, UNNEEDED_REG,
//	     0, UNNEEDED_REG, UNNEEDED_REG,
//            1, 0xf, 0xf, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, "NOP");

  int isValidFunction = validFunctionCode(ms.icode, ms.ifun);
  char* instr;
  char* exceptionStr = "Exception";
  if(isValidFunction)
    instr = getInstructionMnemonic(ms.icode, ms.ifun);
  else
    instr = exceptionStr;

  printReg("  M", // char* stage
	   tick, // int tick
	   ms.PC, // PC
	   ms.icode, // icode
	   0, // ifun
	   0, UNNEEDED_REG, UNNEEDED_REG, // regsValid, rA, rB
	   0, UNNEEDED_REG, UNNEEDED_REG, // srcValid, srcA, srcB
	   1, ms.destE, ms.destM, // dstValid, destE, destM
	   0, UNNEEDED_ADDR, // valCValid, valC
	   0, UNNEEDED_ADDR, // valPValid, valP
	   instr); // char* instr


  return ms;
}

void updateMemoryStage(struct executeStateStruct es)
{
  ms.icode = es.icode;
  ms.ifun = es.ifun;
  ms.PC= es.PC;
  ms.valE = es.valE;
  ms.destE = es.destE;
  ms.destM = es.destM;
  ms.valP = es.valP;
}
