# This is a hack to pass arguments to the run command
# You can run the fetch program by giving doing the following
# make run arg1 arg2
# where arg1 and arg2 are the arguments to the fetch program

ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

all: pipe

CC=gcc
CLIBS=-lc
CFLAGS=-g -Werror-implicit-function-declaration -pedantic -std=c99

SRC=decodeStage.c executeStage.c fetchStage.c instructionSpecifications.c main.c memoryStage.c printInternalReg.c writeBackStage.c
OBJ = $(SRC:.c=.o)

pipe: $(OBJ)
	$(CC) -g -o pipe $(OBJ)

clean:
	rm -f *.o
	rm -f pipe

.PHONY: run
run: pipe  
	./pipe $(RUN_ARGS)

decodeStage.o: decodeStage.h instructionSpecifications.h executeStage.h printInternalReg.h
executeStage.o: executeStage.h instructionSpecifications.h
executeStage.o: memoryStage.h printInternalReg.h
fetchStage.o: fetchStage.h printInternalReg.h instructionSpecifications.h decodeStage.h
instructionSpecifications.o: instructionSpecifications.h
main.o: printInternalReg.h instructionSpecifications.h fetchStage.h decodeStage.h executeStage.h
main.o: memoryStage.h writeBackStage.h
memoryStage.o: memoryStage.h instructionSpecifications.h writeBackStage.h printInternalReg.h
printInternalReg.o: printInternalReg.h instructionSpecifications.h
writeBackStage.o: writeBackStage.h instructionSpecifications.h printInternalReg.h
