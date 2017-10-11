//
//  printInternalReg.c
//  A2
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include "printInternalReg.h"

//
//  printReg() takes the input parameters described below and formats them for
//           consistent printing.
//
//  PC  - the address that the program counter is at when the instruction is retrieved
//  icode - the instruction code
//  ifun  - the function code for the instruction
//  regsValid - Not all instructions set the rA and rB values. If an instruction
//              has an rA and rB value this is set to a non-zero value and to
//              0 if rA and rB is not valid.
//  rA - the rA value, if regsValid is zero this can be anything.
//  rB - the rB value, if regsValid is zero this can be anything.
//
// srcValid - Not all instructions set the srcA and srcB values If stage has a srcA or srcB value
//              then set this value to non-zero to have the values printed
//  srcA - the srcA value, if srcValid is zero this can be anything.
//  srcB - the srcB value, if srcValid is zero this can be anything.
//
// dstValid - If this value is non-zero then print the dstM and dstE values
//  dstE - the dstE value, if dstValid is zero this can be anything.
//  dstM - the dstM value, if dstValid is zero this can be anything.
//
//  valCValid - Not all instructions have a valC value. If an instruction has a
//              a valC value this is set to any non-zero value otherwise it is set
//              to zero.
//  valC - if valCValid is true (i.e. non-zero)  then this contains the value of valC such that
//         when it is printed as an unsigned integer it has the expected value. For example if the
//         the instruction were mrmovq 32(%r9), %r10 then valC in memory, in little endian
//         format would be  20 00 00 00 00 00 00 00, but when we print it as an integer, in hex,
//         it would print 0000000000000020
// valPValid - if this value is non-zero then print the value of valP.
// valP     This is the value of valP as deteremined during the fetch stage.
// instr    This is the string representation of the instruction mnemonic. Note that if the
//          instruction is an unconditional jump then it is reported as jmp, and if it is
//          an unconditional move then it is reported as rrmovq. The mnemonics are to
//          be the ones from the text book.

void printReg(char *stage, int tick,
              uint64_t PC, nibble icode, nibble ifun,
              int regsValid, nibble rA, nibble rB,
              int srcValid, nibble srcA, nibble srcB,
              int dstValid,  nibble destE, nibble destM,
              int  valCValid, uint64_t valC,
              int valPvalid, int64_t valP, char * instr)  {
    
    
    static int currentLine = 0; // This variable is used to determine the line number being printed so that
    // a header line can be periodically printed.
    
    // Print the header line every 20 lines
    if (!(currentLine++ % 20)) {
        
        printf("\nStg    Time    PC           icode ifun   rA rB  sA sB dstE DstM     valC            valP           Instruction\n");
        
    }
    
    
    // print the program counter (only the low order 4 bytes are printed)
    printf(" %-3s   %4d    %08llX :    %2X    %2X  ", stage, tick, PC, icode, ifun);
    
    
    // If required print the register values
    if (regsValid) {
        printf(" %2X %2X  ", rA, rB);
    } else {
        printf("  -  -  ");
    }
    
    if (srcValid) {
      printf("%2X  %2X  ", srcA, srcB);
    } else {
      printf(" -   -  ");
    }

    if (dstValid) {
         printf("%2X  %2X  ", destE, destM);    }
    else {
        printf(" -   -  ");
    }
    
    // Print valC, if present
    if (valCValid) {
        printf("%016llX ", valC);
    } else {
        printf("%17s", " ");
    }
    
    if (valPvalid) {
    // Print valP and the instruction mnemonic.
    printf("%016llX   %s\n", valP, instr);
    } else {
        printf("%16s   %s\n", " ", instr);
    }
        
}


