//
//  instructionSpecifications.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "instructionSpecifications.h"
#include <unistd.h>

// mnemoics for the various intructions

char* instructionNameMap[NUMINSTRUCTIONS] = {
    "halt", "nop", "E_REG" , "irmovq", "rmmovq", "mrmovq",
    "E_MAT", "E_JMP", "call", "ret", "pushq", "popq"
};

char* mathOperations[MATHOPCNT] = {
    "addq", "subq", "andq", "xorq", "mulq", "divq", "modq"
};

char* jmpOperations[JUMPINSTCNT] = {
    "jmp", "jle", "jl", "je", "jne", "jge", "jg"
};

char* movOperations[MOVINSTCNT] = {
    "rrmovq", "cmovle", "cmovl", "cmove", "cmovne", "cmovge", "cmovg"
};


// Assumes that icode and ifun are valid
// Input: icode - instruction code
//        ifun  - function code
// Output: A pointer to the mnemonic for the instruction

char * getInstructionMnemonic(nibble icode, nibble ifun) {
    if (icode == RRMOV) {
        return movOperations[ifun];
    }
    if (icode == MATH) {
        return mathOperations[ifun];
    }
    if (icode == JUMP) {
        return jmpOperations[ifun];
    }
    return instructionNameMap[icode];
}

// This function checks to determine if the instruction code is valid.
// If it is invalid 0 is returned. If it is valid then 1 is returned

// Input: icode 
// Output: 0 if invalid non-zero if valid
int validInstruction(nibble icode) {
    
    if (icode > LASTVALIDOPCODE) return 0;
    
    return 1;
}

// This function verifies that the function code for the given instruction
// code is valid
// Input: icode - instruction code
//        ifun  - function code
// Output: 0 if the function code is invalid 
//         non-zero if valid
//         For instructions that don't use the function code
//         it must be 0.
int validFunctionCode(nibble icode, nibble ifun) {
    
    switch (icode) {
        case RRMOV:
            if (ifun >= MOVINSTCNT) return 0;
            break;
        case MATH:
            if (ifun >= MATHOPCNT) return 0;
            break;
        case JUMP:
            if (ifun >= JUMPINSTCNT) return 0;
            break;
        default:
            if (ifun != 0) return 0;
    }
    return 1;
}

// Determine how many bytes this instruction occupies in memory. The icode and
// ifun byte are included in this count
// Input: iCode -  instruction code
// Ouput The number of bytes the instruction occupies. If the instruction is 
// not none then 0s is returned. 
int getInstructionSize(nibble iCode) {
    
    int len;
    
    switch (iCode) {
        case  HALT:
        case  NOP:
        case  RET:
            len = 1;
            break;
        case RRMOV:
        case MATH:
        case PUSH:
        case POP:
            len = 2;
            break;
        case JUMP:
        case CALL:
            len = 9;
            break;
        case IRMOV:
        case RMMOV:
        case MRMOV:
            len = 10;
            break;
        default:
            len = 0;
    }
    return len;
}


