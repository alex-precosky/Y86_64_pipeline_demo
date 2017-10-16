//
//  executeStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef executeStage_h
#define executeStage_h
#include "instructionSpecifications.h"
#include "decodeStage.h"
#include <stdio.h>

struct executeStateStruct {
    uint64_t PC ;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
  uint8_t icode;
  uint8_t ifun;
  uint64_t valE;
  uint64_t valA;
  uint8_t valC;
  uint8_t destE;
  uint8_t destM;
  uint8_t srcA;
  uint8_t srcB;
  nibble rA;
  nibble rB;
  uint64_t valP;

  // holds the original icode and ifun in an exception
  nibble exception_icode;
  nibble exception_ifun;

};

struct executeStateStruct initializeExecuteStage();
struct executeStateStruct processExecuteStage(int tick) ;
void updateExecuteStage(struct decodeStateStruct ds);

#endif /* executeStage_h */
