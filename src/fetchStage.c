//
//  fetchStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "fetchStage.h"
#include "instructionSpecifications.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include "decodeStage.h"
#include <string.h>

// Use this struct to store state information for this stage. By making it
// static the structure and its fields can be accessed in this file
// but not in the reset of the program.
static struct fetchStateStruct fs;


// This maps the file into main memory so that pointers can be used to access
// the instruction directly

int initializeFetchState(int memoryFileFD, uint64_t initialPC)
{
  struct stat statBuff;

  if (fstat(memoryFileFD, &statBuff)) {
    return -2;
  }

  // Do the actual mapping.
  fs.instBase =  mmap(0, statBuff.st_size, PROT_READ,
                      MAP_PRIVATE, memoryFileFD, 0);
  if (fs.instBase == MAP_FAILED) {
    return -3;
  }
  fs.lastAddr = fs.instBase + statBuff.st_size;
  fs.PC = initialPC;

  fs.icode = NOP;
  fs.ifun = 0;

  fs.bubble_ctr = 0;

  return 0;
}

struct fetchStateStruct getFetchState()
{
  return fs;
}


int checkAddr2Exception()
{
  if(fs.instBase + fs.valP > fs.lastAddr) {
    fs.exception_icode = fs.icode;
    fs.exception_ifun = fs.ifun;
    fs.icode = ADDRESSING_EXCEPTION2;
    fs.valP = fs.PC;
    return 1;
  }
  return 0;
}

struct fetchStateStruct processFetchStage(int tick) {

  unsigned char* icodePtr = fs.instBase + fs.PC;

  if(icodePtr > fs.lastAddr) {
    fs.icode=ADDRESSING_EXCEPTION;
    fs.ifun = 0xf;
  } else {
    fs.icode = (*(icodePtr) & 0xF0) >> 4;
    fs.ifun = *(fs.instBase + fs.PC) & 0x0F;

    if(!validFunctionCode(fs.icode, fs.ifun)) {
      fs.exception_icode = fs.icode;
      fs.exception_ifun = fs.ifun;

      fs.icode = INVALIDINSTRUCTION_EXCEPTION;
      fs.ifun = 0xf;
    }
  }

  if( fs.icode == HALT ) {
    fs.valP = fs.PC + 1;
    fs.rA = 0xF;
    fs.rB = 0xF;
  } else if( fs.icode == ADDRESSING_EXCEPTION) {
    fs.rA = 0xF;
    fs.rB = 0xF;
    fs.valC = 0;
    fs.valP = fs.PC;
  } else if( fs.icode == NOP) {
    fs.valP = fs.PC + 1;
    fs.rA = 0xF;
    fs.rB = 0xF;
    fs.valC = 0;
  } else if( fs.icode == RRMOV) { //rrmovq, cmovXX
      fs.valP = fs.PC + 2;
      fs.valC = 0x00;
      if(!checkAddr2Exception()) {
        fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
        fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      }
  } else if( fs.icode == IRMOV) {
    fs.valP = fs.PC + 10;
    fs.rA = UNNEEDED_REG;
    if(!checkAddr2Exception()) {
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
    } else {
      fs.valC = 0;
    }

  } else if( fs.icode == RMMOV) {
    fs.valP = fs.PC + 10;
    if(!checkAddr2Exception()) {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
    } else {
      fs.valC = 0;
    }
  } else if( fs.icode == MRMOV) {
    fs.valP = fs.PC + 10;
    if(!checkAddr2Exception()) {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
      fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 2);
    } else {
      fs.valC = 0;
    }
  } else if( fs.icode == MATH) {
    fs.valP = fs.PC + 2;
    if(!checkAddr2Exception())
      {
        fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
        fs.rB = *(fs.instBase + fs.PC + 1) & 0x0F;
      }

  } else if( fs.icode == JUMP) {
    fs.valP = fs.PC+9;
    if(!checkAddr2Exception()) {
      fs.valC = *(uint64_t *)(fs.instBase + fs.PC + 1);
    } else {
      fs.valC = 0;
    }
    fs.rA = UNNEEDED_REG;
    fs.rB = UNNEEDED_REG;

  } else if( fs.icode == CALL) {
    fs.valP = fs.PC+9;
    fs.rA = UNNEEDED_REG;
    fs.rB = UNNEEDED_REG;
    if(!checkAddr2Exception()) {
      fs.valC = *(uint64_t *)(fs.instBase+fs.PC+1);
    } else {
      fs.valC = 0;
    }

  } else if( fs.icode == RET) {
    fs.valP = fs.PC+1;
    fs.rA = UNNEEDED_REG;
    fs.rB = UNNEEDED_REG;

  } else if( fs.icode == PUSH) {
    fs.rB = UNNEEDED_REG;
    fs.valP = fs.PC+2;
    if(!checkAddr2Exception()) {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
    }

  } else if( fs.icode == POP) {
    fs.rB = 0xF;
    fs.valP = fs.PC+2;
    if(!checkAddr2Exception()) {
      fs.rA = *(fs.instBase + fs.PC + 1) >> 4;
    }
  }

  char instr[50];
  getInstructionOrExceptionMnemonic(instr, fs.icode, fs.ifun, fs.exception_icode, fs.exception_ifun, fs.PC);

  char stage[4];
  if(fs.bubble_ctr == 0) {
    strcpy(stage, "  F");
  } else if(fs.bubble_ctr==1) {
    strcpy(stage, "F W");
  } else if(fs.bubble_ctr==2) {
    strcpy(stage, "F M");
  } else if(fs.bubble_ctr==3) {
    strcpy(stage, "F E");
  }

  printReg(stage,                         // char* stage
           tick,                          // int tick
           fs.PC,                         // PC
           fs.icode,                      // icode
           fs.ifun,                       // ifun
           1, fs.rA, fs.rB,               // regsValid, rA, rB
           0, UNNEEDED_REG, UNNEEDED_REG, // srcValid, srcA, srcB
           0, UNNEEDED_REG, UNNEEDED_REG, // dstValid, destE, destM
           1, fs.valC,                    // valCValid, valC
           1, fs.valP,                    // valPValid, valP
           instr);                        // char* instr

  return fs;
}

void updateFetchStage()
{

  if(fs.icode == JUMP || fs.icode == CALL)
    fs.PC = fs.valC;
  else
    fs.PC = fs.valP;

}

void setFetchHazard(int bubble_ctr)
{
  fs.bubble_ctr = bubble_ctr;
}
