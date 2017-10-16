//
//  writeBackStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef writeBackStage_h
#define writeBackStage_h

#include <stdio.h>
#include "instructionSpecifications.h"
#include "memoryStage.h"
struct writeBackStateStruct {
    uint64_t PC;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
  uint64_t destE;
  uint64_t destM;
  nibble icode;
  nibble ifun;
  uint64_t valP;

  // holds the original icode and ifun in an exception
  nibble exception_icode;
  nibble exception_ifun;
} ;

struct writeBackStateStruct initializeWriteBackStage();
struct writeBackStateStruct processWriteBackStage(int tick) ;
void updateWriteBackStage(struct memoryStateStruct ms);

#endif /* writeBackStage_h */
