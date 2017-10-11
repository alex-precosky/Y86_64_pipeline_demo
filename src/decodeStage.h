//
//  decodeStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef decodeStage_h
#define decodeStage_h
#include <sys/types.h>
#include "instructionSpecifications.h"
#include "fetchStage.h"

struct decodeStateStruct {

  uint64_t PC;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
  nibble icode;
  nibble ifun;
  nibble rA;
  nibble rB;
  uint64_t valC;
  uint8_t valA;
  uint8_t valB;
  uint64_t valP;
  nibble srcA;
  nibble srcB;
  nibble destE;
  nibble destM;

  int bubble_ctr;
};

struct decodeStateStruct initializeDecodeStage();
struct decodeStateStruct processDecodeStage(int tick);

void updateDecodeStage(struct fetchStateStruct fs);
void setDecodeHazard(int bubble_ctr);

#endif /* decodeStage_h */
