//
//  decodeStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//
#include "fetchStage.h"
#include "decodeStage.h"
#include "instructionSpecifications.h"
#include "executeStage.h"
#include "printInternalReg.h"
#include <string.h>

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 

static struct decodeStateStruct ds;

struct decodeStateStruct initializeDecodeStage()
{
  ds.icode = NOP;
  ds.ifun = 0;
  ds.PC=0;
  ds.valC = 0x8181818181818181;
  ds.valP = 0x8181818181818181;
  ds.rA = 0xF;
  ds.rB = 0xF;
  ds.srcA = 0xF;
  ds.srcB = 0xF;
  ds.destE = 0xF;
  ds.destM = 0xF;
  return ds;
}

struct decodeStateStruct processDecodeStage(int tick) {

  // Add code to perform fetch stage processing. 

  // The following line illustrates how to print information for this stage. 
  // This is an example only and you should delete it or replace it with an 
  // appropriate one. 

//     printReg("D W", 10, 11, 3, 0, 1, 15, 7,
//	     1, 15, 15, 
//	      1, 7, 15, 1, 0x1473817134381 , 1, 10+10, "irmovq" );


  int isValidFunction = validFunctionCode(ds.icode, ds.ifun);
  char* instr;

  char exceptionStr[25];
  if(isValidFunction)
    instr = getInstructionMnemonic(ds.icode, ds.ifun);
  else
    {
      sprintf(exceptionStr, "ADDR EXCEP pc = %x", ds.PC);
      instr = exceptionStr;
    }


  if( ds.icode == IRMOV || ds.icode == RRMOV )
    ds.destE = ds.rB;
  else
    ds.destE = 0xF;

  char stage[4];

 if(ds.bubble_ctr == 0)
    strcpy(stage, "  D");
  else if(ds.bubble_ctr==1)
    strcpy(stage, "D W");
  else if(ds.bubble_ctr==2)
    strcpy(stage, "D M");
  else if(ds.bubble_ctr==3)
    strcpy(stage, "D E");


  printReg(stage, // char* stage
	   tick, // int tick
	   ds.PC, // PC
	   ds.icode, // icode
	   ds.ifun, // ifun
	   1, ds.rA, ds.rB, // regsValid, rA, rB
	   1, ds.srcA, ds.srcB, // srcValid, srcA, srcB
	   1, ds.destE, ds.destM, // dstValid, destE, destM
	   1, ds.valC, // valCValid, valC
	   1, ds.valP, // valPValid, valP
	   instr); // char* instr


     return ds;

}

void updateDecodeStage(struct fetchStateStruct fs)
{
  ds.PC = fs.PC;
  ds.icode = fs.icode;
  ds.ifun = fs.ifun;
  ds.valC = fs.valC;
  ds.valP = fs.valP;
  ds.rA = fs.rA;
  ds.rB = fs.rB;
}


void setDecodeHazard(int bubble_ctr)
{
  ds.bubble_ctr = bubble_ctr;
}
