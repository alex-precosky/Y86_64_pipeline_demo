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


  char instr[50];
  getInstructionOrExceptionMnemonic(instr, ms.icode, ms.ifun, ms.exception_icode, ms.exception_ifun, ms.PC);


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

  ms.exception_icode = es.exception_icode;
  ms.exception_ifun = es.exception_ifun;
}
