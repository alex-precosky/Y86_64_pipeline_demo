//
//  executeStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "executeStage.h"
#include "memoryStage.h"
#include "decodeStage.h"
#include "printInternalReg.h"
#include "instructionSpecifications.h"


// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct executeStateStruct es;

struct executeStateStruct initializeExecuteStage()
{
  es.icode = NOP;
  es.ifun = 0;
  es.PC = 0;
  es.srcA=0xF;
  es.srcB=0xF;
  es.rA=0xF;
  es.rB=0xF;
  es.destE=0xF;
  es.destM=0xF;
  return es;
}

struct executeStateStruct processExecuteStage(int tick) {
  // This function probably remains empty but here is sample of 
  // printing
  
//  printReg("E", 10, 8, 2, 2, 0, UNNEEDED_REG, UNNEEDED_REG,
//	     1, 3, 4,
//	   1, 4, 0xF, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, getInstructionMnemonic(2,2));

  char instr[50];
  getInstructionOrExceptionMnemonic(instr, es.icode, es.ifun, es.exception_icode, es.exception_ifun, es.PC);


  printReg("  E", // char* stage
	   tick, // int tick
	   es.PC, // PC
	   es.icode, // icode
	   es.ifun, // ifun
	   0, UNNEEDED_REG, UNNEEDED_REG, // regsValid, rA, rB
	   1, es.srcA, es.srcB, // srcValid, srcA, srcB
	   1, es.destE, es.destM, // dstValid, destE, destM
	   0, UNNEEDED_ADDR, // valCValid, valC
	   0, UNNEEDED_ADDR, // valPValid, valP
	   instr); // char* instr


  return es;
}

void updateExecuteStage(struct decodeStateStruct ds)
{
  es.icode = ds.icode;
  es.ifun = ds.ifun;
  es.PC = ds.PC;
  
  es.rA = ds.rA;
  es.rB = ds.rB;
  es.srcA = ds.srcA;
  es.srcB = ds.srcB;
  es.destE = ds.destE;
  es.destM = ds.destM;
  es.valP = ds.valP;

  es.exception_icode = ds.exception_icode;
  es.exception_ifun = ds.exception_ifun;
}
