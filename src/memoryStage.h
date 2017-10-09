//
//  memoryStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef memoryStage_h
#define memoryStage_h

#include <stdio.h>
#include "instructionSpecifications.h"
#include "executeStage.h"
struct memoryStateStruct {
    uint64_t PC; // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
  nibble icode;
  nibble ifun;
  uint8_t destE;
  uint8_t destM;
  uint64_t valE;
};

struct memoryStateStruct initializeMemoryStage(void);
struct memoryStateStruct processMemoryStage(int tick);
void updateMemoryStage(struct executeStateStruct es);
#endif /* memoryStage_h */
