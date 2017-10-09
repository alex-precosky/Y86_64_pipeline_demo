#This is a hack to pass arguments to the run command and probably only 
#works with gnu make. 
#You can run the fetch program by giving doing the following
# make run arg1 arg2
# where arg1 and arg2 are the arguments to the fetch program
#
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

depend: $(SRC)
	makedepend $(SRC)

clean:
	rm -f *.o
	rm -f pipe

.PHONY: run
run: pipe  
	./pipe $(RUN_ARGS)

# DO NOT DELETE

decodeStage.o: decodeStage.h /usr/include/sys/types.h /usr/include/features.h
decodeStage.o: /usr/include/sys/cdefs.h
decodeStage.o: /usr/include/bits/wordsize.h 
decodeStage.o: /usr/include/time.h /usr/include/endian.h
decodeStage.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
decodeStage.o: /usr/include/sys/select.h
decodeStage.o: /usr/include/sys/sysmacros.h
decodeStage.o: instructionSpecifications.h
decodeStage.o: /usr/include/stdint.h executeStage.h
decodeStage.o: /usr/include/stdio.h
decodeStage.o:  /usr/include/wchar.h
decodeStage.o: printInternalReg.h
executeStage.o: executeStage.h instructionSpecifications.h
executeStage.o: /usr/include/stdint.h /usr/include/features.h
executeStage.o: /usr/include/sys/cdefs.h
executeStage.o: /usr/include/bits/wordsize.h
executeStage.o: /usr/include/stdio.h
executeStage.o: /usr/include/wchar.h 
executeStage.o: memoryStage.h
executeStage.o: printInternalReg.h
fetchStage.o: fetchStage.h /usr/include/stdio.h /usr/include/features.h
fetchStage.o: /usr/include/time.h
fetchStage.o: /usr/include/sys/types.h /usr/include/endian.h
fetchStage.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
fetchStage.o: /usr/include/sys/select.h
fetchStage.o: /usr/include/sys/sysmacros.h
fetchStage.o: /usr/include/sys/uio.h
fetchStage.o: /usr/include/unistd.h
fetchStage.o: /usr/include/getopt.h
fetchStage.o: /usr/include/inttypes.h /usr/include/stdint.h
fetchStage.o: /usr/include/stdlib.h
fetchStage.o: /usr/include/alloca.h 
fetchStage.o: /usr/include/errno.h 
fetchStage.o: printInternalReg.h
fetchStage.o: instructionSpecifications.h /usr/include/sys/stat.h
fetchStage.o: /usr/include/sys/mman.h 
fetchStage.o: decodeStage.h
instructionSpecifications.o: instructionSpecifications.h
instructionSpecifications.o: /usr/include/stdint.h /usr/include/features.h
instructionSpecifications.o: /usr/include/sys/cdefs.h
instructionSpecifications.o: /usr/include/bits/wordsize.h
instructionSpecifications.o: /usr/include/unistd.h
instructionSpecifications.o: /usr/include/getopt.h
main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h 
main.o: /usr/include/wchar.h
main.o: /usr/include/fcntl.h
main.o: /usr/include/time.h
main.o: /usr/include/sys/types.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h
main.o: /usr/include/sys/select.h  
main.o: /usr/include/sys/sysmacros.h 
main.o: /usr/include/sys/uio.h /usr/include/unistd.h
main.o: /usr/include/getopt.h
main.o: /usr/include/inttypes.h /usr/include/stdint.h
main.o: /usr/include/stdlib.h
main.o: /usr/include/alloca.h 
main.o: /usr/include/errno.h 
main.o: /usr/include/sys/stat.h
main.o: /usr/include/sys/mman.h
main.o: printInternalReg.h
main.o: instructionSpecifications.h fetchStage.h decodeStage.h executeStage.h
main.o: memoryStage.h writeBackStage.h
memoryStage.o: memoryStage.h /usr/include/stdio.h /usr/include/features.h
memoryStage.o: /usr/include/sys/cdefs.h
memoryStage.o: /usr/include/bits/wordsize.h
memoryStage.o: /usr/include/wchar.h
memoryStage.o: instructionSpecifications.h
memoryStage.o: /usr/include/stdint.h
memoryStage.o: writeBackStage.h printInternalReg.h
printInternalReg.o: /usr/include/stdio.h /usr/include/features.h
printInternalReg.o: /usr/include/sys/cdefs.h
printInternalReg.o: /usr/include/bits/wordsize.h
printInternalReg.o: /usr/include/wchar.h
printInternalReg.o: /usr/include/unistd.h
printInternalReg.o: /usr/include/getopt.h
printInternalReg.o: printInternalReg.h /usr/include/stdint.h
printInternalReg.o: instructionSpecifications.h
writeBackStage.o: writeBackStage.h /usr/include/stdio.h
writeBackStage.o: /usr/include/features.h
writeBackStage.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
writeBackStage.o: /usr/include/wchar.h
writeBackStage.o: instructionSpecifications.h
writeBackStage.o: /usr/include/stdint.h
writeBackStage.o: printInternalReg.h
