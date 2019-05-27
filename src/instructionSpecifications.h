//
//  instructionSpecifications.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef instructionSpecifications_h
#define instructionSpecifications_h
#include <stdint.h>
typedef unsigned char nibble;

#define ERROR_RETURN -1
#define SUCCESS 0
#define HALT 0
#define NOP  1
#define RRMOV 2
#define IRMOV 3
#define RMMOV 4
#define MRMOV 5
#define MATH  6
#define JUMP  7
#define CALL  8
#define RET   9
#define PUSH  10
#define POP   11
#define NUMINSTRUCTIONS 12
#define LASTVALIDOPCODE 11
#define ADDRESSING_EXCEPTION 0xFD
#define ADDRESSING_EXCEPTION2 0xFE
#define INVALIDINSTRUCTION_EXCEPTION 0xFF
#define MATHOPCNT 7
#define JUMPINSTCNT 7
#define MOVINSTCNT 7

#define UNNEEDED_REG   0xf
#define UNNEEDED_ADDR  0x8181818181818181
#define STACK_PTR 4

int getInstructionSize(nibble opCode);
int validInstruction(nibble icode);
int validFunctionCode(nibble icode, nibble ifun);

char *getInstructionMnemonic(nibble icode, nibble ifun);

void getInstructionOrExceptionMnemonic(char* dest,
                                       nibble icode,
                                       nibble ifun,
                                       nibble exception_icode,
                                       nibble exception_ifun,
                                       uint64_t PC);

#endif /* instructionSpecifications_h */
