//
//  printInternalReg.h
//  A2
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//
/* This file contiains the prototypes and
 constants needed to use the routines
 defined in printRoutines.c
 */
#ifndef printInternalReg_h
#define printInternalReg_h
#include <stdint.h>
#include "instructionSpecifications.h"
#define PRINTERROR -1
#define PRINTSUCCESS 0



void printReg(char *stage, int tick, 
              uint64_t PC, nibble icode, nibble ifun,
              int regsValid, nibble rA, nibble rB,
              int srcValid, nibble srcA, nibble srcB,
              int dstvalid,  nibble destE, nibble destM,
              int  valCValid, uint64_t valC,
              int valPValid, int64_t valP, char * instr);


#endif /* printInternalReg_h */
