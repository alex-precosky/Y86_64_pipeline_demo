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
# DO NOT DELETE

decodeStage.o: fetchStage.h /usr/include/stdio.h /usr/include/_stdio.h
decodeStage.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
decodeStage.o: /usr/include/sys/_posix_availability.h
decodeStage.o: /usr/include/Availability.h
decodeStage.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
decodeStage.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
decodeStage.o: /usr/include/i386/_types.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_types.h
decodeStage.o: /usr/include/sys/_types/_va_list.h
decodeStage.o: /usr/include/machine/types.h /usr/include/i386/types.h
decodeStage.o: /usr/include/sys/_types/_int8_t.h
decodeStage.o: /usr/include/sys/_types/_int16_t.h
decodeStage.o: /usr/include/sys/_types/_int32_t.h
decodeStage.o: /usr/include/sys/_types/_int64_t.h
decodeStage.o: /usr/include/sys/_types/_u_int8_t.h
decodeStage.o: /usr/include/sys/_types/_u_int16_t.h
decodeStage.o: /usr/include/sys/_types/_u_int32_t.h
decodeStage.o: /usr/include/sys/_types/_u_int64_t.h
decodeStage.o: /usr/include/sys/_types/_intptr_t.h
decodeStage.o: /usr/include/sys/_types/_uintptr_t.h
decodeStage.o: /usr/include/sys/_types/_size_t.h
decodeStage.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
decodeStage.o: /usr/include/sys/_types/_off_t.h
decodeStage.o: /usr/include/sys/_types/_ssize_t.h
decodeStage.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
decodeStage.o: /usr/include/fcntl.h /usr/include/sys/fcntl.h
decodeStage.o: /usr/include/sys/_types/_mode_t.h
decodeStage.o: /usr/include/sys/_types/_pid_t.h
decodeStage.o: /usr/include/sys/_types/_o_sync.h
decodeStage.o: /usr/include/sys/_types/_o_dsync.h
decodeStage.o: /usr/include/sys/_types/_seek_set.h
decodeStage.o: /usr/include/sys/_types/_s_ifmt.h
decodeStage.o: /usr/include/sys/_types/_timespec.h
decodeStage.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/types.h
decodeStage.o: /usr/include/sys/appleapiopts.h /usr/include/machine/endian.h
decodeStage.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
decodeStage.o: /usr/include/libkern/_OSByteOrder.h
decodeStage.o: /usr/include/libkern/i386/_OSByteOrder.h
decodeStage.o: /usr/include/sys/_types/_u_char.h
decodeStage.o: /usr/include/sys/_types/_u_short.h
decodeStage.o: /usr/include/sys/_types/_u_int.h
decodeStage.o: /usr/include/sys/_types/_caddr_t.h
decodeStage.o: /usr/include/sys/_types/_dev_t.h
decodeStage.o: /usr/include/sys/_types/_blkcnt_t.h
decodeStage.o: /usr/include/sys/_types/_blksize_t.h
decodeStage.o: /usr/include/sys/_types/_gid_t.h
decodeStage.o: /usr/include/sys/_types/_in_addr_t.h
decodeStage.o: /usr/include/sys/_types/_in_port_t.h
decodeStage.o: /usr/include/sys/_types/_ino_t.h
decodeStage.o: /usr/include/sys/_types/_ino64_t.h
decodeStage.o: /usr/include/sys/_types/_key_t.h
decodeStage.o: /usr/include/sys/_types/_nlink_t.h
decodeStage.o: /usr/include/sys/_types/_id_t.h
decodeStage.o: /usr/include/sys/_types/_uid_t.h
decodeStage.o: /usr/include/sys/_types/_clock_t.h
decodeStage.o: /usr/include/sys/_types/_time_t.h
decodeStage.o: /usr/include/sys/_types/_useconds_t.h
decodeStage.o: /usr/include/sys/_types/_suseconds_t.h
decodeStage.o: /usr/include/sys/_types/_rsize_t.h
decodeStage.o: /usr/include/sys/_types/_errno_t.h
decodeStage.o: /usr/include/sys/_types/_fd_def.h
decodeStage.o: /usr/include/sys/_types/_fd_setsize.h
decodeStage.o: /usr/include/sys/_types/_fd_set.h
decodeStage.o: /usr/include/sys/_types/_fd_clr.h
decodeStage.o: /usr/include/sys/_types/_fd_zero.h
decodeStage.o: /usr/include/sys/_types/_fd_isset.h
decodeStage.o: /usr/include/sys/_types/_fd_copy.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_attr_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_cond_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_once_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_t.h
decodeStage.o: /usr/include/sys/_pthread/_pthread_key_t.h
decodeStage.o: /usr/include/sys/_types/_fsblkcnt_t.h
decodeStage.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/sys/uio.h
decodeStage.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
decodeStage.o: /usr/include/sys/unistd.h
decodeStage.o: /usr/include/sys/_types/_posix_vdisable.h
decodeStage.o: /usr/include/_types/_uint64_t.h
decodeStage.o: /usr/include/_types/_uint32_t.h /usr/include/sys/select.h
decodeStage.o: /usr/include/sys/_types/_timeval.h
decodeStage.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_select.h
decodeStage.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
decodeStage.o: /usr/include/inttypes.h /usr/include/sys/_types/_wchar_t.h
decodeStage.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
decodeStage.o: /usr/include/_types/_uint16_t.h
decodeStage.o: /usr/include/_types/_intmax_t.h
decodeStage.o: /usr/include/_types/_uintmax_t.h /usr/include/stdlib.h
decodeStage.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
decodeStage.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
decodeStage.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
decodeStage.o: /usr/include/mach/machine/_structs.h
decodeStage.o: /usr/include/mach/i386/_structs.h
decodeStage.o: /usr/include/sys/_types/_sigaltstack.h
decodeStage.o: /usr/include/sys/_types/_ucontext.h
decodeStage.o: /usr/include/sys/resource.h /usr/include/alloca.h
decodeStage.o: /usr/include/sys/_types/_ct_rune_t.h
decodeStage.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
decodeStage.o: /usr/include/sys/errno.h printInternalReg.h
decodeStage.o: instructionSpecifications.h decodeStage.h executeStage.h
decodeStage.o: /usr/include/string.h /usr/include/strings.h
decodeStage.o: /usr/include/secure/_strings.h /usr/include/secure/_string.h
executeStage.o: executeStage.h instructionSpecifications.h
executeStage.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
executeStage.o: /usr/include/sys/_types/_int16_t.h
executeStage.o: /usr/include/sys/_types/_int32_t.h
executeStage.o: /usr/include/sys/_types/_int64_t.h
executeStage.o: /usr/include/_types/_uint8_t.h
executeStage.o: /usr/include/_types/_uint16_t.h
executeStage.o: /usr/include/_types/_uint32_t.h
executeStage.o: /usr/include/_types/_uint64_t.h /usr/include/sys/_types.h
executeStage.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
executeStage.o: /usr/include/sys/_posix_availability.h
executeStage.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
executeStage.o: /usr/include/sys/_pthread/_pthread_types.h
executeStage.o: /usr/include/sys/_types/_intptr_t.h
executeStage.o: /usr/include/machine/types.h /usr/include/i386/types.h
executeStage.o: /usr/include/sys/_types/_u_int8_t.h
executeStage.o: /usr/include/sys/_types/_u_int16_t.h
executeStage.o: /usr/include/sys/_types/_u_int32_t.h
executeStage.o: /usr/include/sys/_types/_u_int64_t.h
executeStage.o: /usr/include/sys/_types/_uintptr_t.h
executeStage.o: /usr/include/_types/_intmax_t.h
executeStage.o: /usr/include/_types/_uintmax_t.h decodeStage.h
executeStage.o: /usr/include/sys/types.h /usr/include/sys/appleapiopts.h
executeStage.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
executeStage.o: /usr/include/sys/_endian.h
executeStage.o: /usr/include/libkern/_OSByteOrder.h
executeStage.o: /usr/include/libkern/i386/_OSByteOrder.h
executeStage.o: /usr/include/sys/_types/_u_char.h
executeStage.o: /usr/include/sys/_types/_u_short.h
executeStage.o: /usr/include/sys/_types/_u_int.h
executeStage.o: /usr/include/sys/_types/_caddr_t.h
executeStage.o: /usr/include/sys/_types/_dev_t.h
executeStage.o: /usr/include/sys/_types/_blkcnt_t.h
executeStage.o: /usr/include/sys/_types/_blksize_t.h
executeStage.o: /usr/include/sys/_types/_gid_t.h
executeStage.o: /usr/include/sys/_types/_in_addr_t.h
executeStage.o: /usr/include/sys/_types/_in_port_t.h
executeStage.o: /usr/include/sys/_types/_ino_t.h
executeStage.o: /usr/include/sys/_types/_ino64_t.h
executeStage.o: /usr/include/sys/_types/_key_t.h
executeStage.o: /usr/include/sys/_types/_mode_t.h
executeStage.o: /usr/include/sys/_types/_nlink_t.h
executeStage.o: /usr/include/sys/_types/_id_t.h
executeStage.o: /usr/include/sys/_types/_pid_t.h
executeStage.o: /usr/include/sys/_types/_off_t.h
executeStage.o: /usr/include/sys/_types/_uid_t.h
executeStage.o: /usr/include/sys/_types/_clock_t.h
executeStage.o: /usr/include/sys/_types/_size_t.h
executeStage.o: /usr/include/sys/_types/_ssize_t.h
executeStage.o: /usr/include/sys/_types/_time_t.h
executeStage.o: /usr/include/sys/_types/_useconds_t.h
executeStage.o: /usr/include/sys/_types/_suseconds_t.h
executeStage.o: /usr/include/sys/_types/_rsize_t.h
executeStage.o: /usr/include/sys/_types/_errno_t.h
executeStage.o: /usr/include/sys/_types/_fd_def.h
executeStage.o: /usr/include/sys/_types/_fd_setsize.h
executeStage.o: /usr/include/sys/_types/_fd_set.h
executeStage.o: /usr/include/sys/_types/_fd_clr.h
executeStage.o: /usr/include/sys/_types/_fd_zero.h
executeStage.o: /usr/include/sys/_types/_fd_isset.h
executeStage.o: /usr/include/sys/_types/_fd_copy.h
executeStage.o: /usr/include/sys/_pthread/_pthread_attr_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_cond_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_once_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_t.h
executeStage.o: /usr/include/sys/_pthread/_pthread_key_t.h
executeStage.o: /usr/include/sys/_types/_fsblkcnt_t.h
executeStage.o: /usr/include/sys/_types/_fsfilcnt_t.h fetchStage.h
executeStage.o: /usr/include/stdio.h /usr/include/_stdio.h
executeStage.o: /usr/include/Availability.h
executeStage.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
executeStage.o: /usr/include/sys/_types/_va_list.h
executeStage.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
executeStage.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
executeStage.o: /usr/include/fcntl.h /usr/include/sys/fcntl.h
executeStage.o: /usr/include/sys/_types/_o_sync.h
executeStage.o: /usr/include/sys/_types/_o_dsync.h
executeStage.o: /usr/include/sys/_types/_seek_set.h
executeStage.o: /usr/include/sys/_types/_s_ifmt.h
executeStage.o: /usr/include/sys/_types/_timespec.h
executeStage.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/uio.h
executeStage.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
executeStage.o: /usr/include/sys/unistd.h
executeStage.o: /usr/include/sys/_types/_posix_vdisable.h
executeStage.o: /usr/include/sys/select.h /usr/include/sys/_types/_timeval.h
executeStage.o: /usr/include/sys/_types/_sigset_t.h
executeStage.o: /usr/include/sys/_select.h /usr/include/sys/_types/_uuid_t.h
executeStage.o: /usr/include/gethostuuid.h /usr/include/inttypes.h
executeStage.o: /usr/include/sys/_types/_wchar_t.h /usr/include/stdlib.h
executeStage.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
executeStage.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
executeStage.o: /usr/include/machine/_mcontext.h
executeStage.o: /usr/include/i386/_mcontext.h
executeStage.o: /usr/include/mach/machine/_structs.h
executeStage.o: /usr/include/mach/i386/_structs.h
executeStage.o: /usr/include/sys/_types/_sigaltstack.h
executeStage.o: /usr/include/sys/_types/_ucontext.h
executeStage.o: /usr/include/sys/resource.h /usr/include/alloca.h
executeStage.o: /usr/include/sys/_types/_ct_rune_t.h
executeStage.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
executeStage.o: /usr/include/sys/errno.h printInternalReg.h memoryStage.h
fetchStage.o: fetchStage.h /usr/include/stdio.h /usr/include/_stdio.h
fetchStage.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
fetchStage.o: /usr/include/sys/_posix_availability.h
fetchStage.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
fetchStage.o: /usr/include/_types.h /usr/include/sys/_types.h
fetchStage.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_types.h
fetchStage.o: /usr/include/sys/_types/_va_list.h /usr/include/machine/types.h
fetchStage.o: /usr/include/i386/types.h /usr/include/sys/_types/_int8_t.h
fetchStage.o: /usr/include/sys/_types/_int16_t.h
fetchStage.o: /usr/include/sys/_types/_int32_t.h
fetchStage.o: /usr/include/sys/_types/_int64_t.h
fetchStage.o: /usr/include/sys/_types/_u_int8_t.h
fetchStage.o: /usr/include/sys/_types/_u_int16_t.h
fetchStage.o: /usr/include/sys/_types/_u_int32_t.h
fetchStage.o: /usr/include/sys/_types/_u_int64_t.h
fetchStage.o: /usr/include/sys/_types/_intptr_t.h
fetchStage.o: /usr/include/sys/_types/_uintptr_t.h
fetchStage.o: /usr/include/sys/_types/_size_t.h
fetchStage.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
fetchStage.o: /usr/include/sys/_types/_off_t.h
fetchStage.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
fetchStage.o: /usr/include/secure/_common.h /usr/include/fcntl.h
fetchStage.o: /usr/include/sys/fcntl.h /usr/include/sys/_types/_mode_t.h
fetchStage.o: /usr/include/sys/_types/_pid_t.h
fetchStage.o: /usr/include/sys/_types/_o_sync.h
fetchStage.o: /usr/include/sys/_types/_o_dsync.h
fetchStage.o: /usr/include/sys/_types/_seek_set.h
fetchStage.o: /usr/include/sys/_types/_s_ifmt.h
fetchStage.o: /usr/include/sys/_types/_timespec.h
fetchStage.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/types.h
fetchStage.o: /usr/include/sys/appleapiopts.h /usr/include/machine/endian.h
fetchStage.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
fetchStage.o: /usr/include/libkern/_OSByteOrder.h
fetchStage.o: /usr/include/libkern/i386/_OSByteOrder.h
fetchStage.o: /usr/include/sys/_types/_u_char.h
fetchStage.o: /usr/include/sys/_types/_u_short.h
fetchStage.o: /usr/include/sys/_types/_u_int.h
fetchStage.o: /usr/include/sys/_types/_caddr_t.h
fetchStage.o: /usr/include/sys/_types/_dev_t.h
fetchStage.o: /usr/include/sys/_types/_blkcnt_t.h
fetchStage.o: /usr/include/sys/_types/_blksize_t.h
fetchStage.o: /usr/include/sys/_types/_gid_t.h
fetchStage.o: /usr/include/sys/_types/_in_addr_t.h
fetchStage.o: /usr/include/sys/_types/_in_port_t.h
fetchStage.o: /usr/include/sys/_types/_ino_t.h
fetchStage.o: /usr/include/sys/_types/_ino64_t.h
fetchStage.o: /usr/include/sys/_types/_key_t.h
fetchStage.o: /usr/include/sys/_types/_nlink_t.h
fetchStage.o: /usr/include/sys/_types/_id_t.h
fetchStage.o: /usr/include/sys/_types/_uid_t.h
fetchStage.o: /usr/include/sys/_types/_clock_t.h
fetchStage.o: /usr/include/sys/_types/_time_t.h
fetchStage.o: /usr/include/sys/_types/_useconds_t.h
fetchStage.o: /usr/include/sys/_types/_suseconds_t.h
fetchStage.o: /usr/include/sys/_types/_rsize_t.h
fetchStage.o: /usr/include/sys/_types/_errno_t.h
fetchStage.o: /usr/include/sys/_types/_fd_def.h
fetchStage.o: /usr/include/sys/_types/_fd_setsize.h
fetchStage.o: /usr/include/sys/_types/_fd_set.h
fetchStage.o: /usr/include/sys/_types/_fd_clr.h
fetchStage.o: /usr/include/sys/_types/_fd_zero.h
fetchStage.o: /usr/include/sys/_types/_fd_isset.h
fetchStage.o: /usr/include/sys/_types/_fd_copy.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_attr_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_cond_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_once_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_t.h
fetchStage.o: /usr/include/sys/_pthread/_pthread_key_t.h
fetchStage.o: /usr/include/sys/_types/_fsblkcnt_t.h
fetchStage.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/sys/uio.h
fetchStage.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
fetchStage.o: /usr/include/sys/unistd.h
fetchStage.o: /usr/include/sys/_types/_posix_vdisable.h
fetchStage.o: /usr/include/_types/_uint64_t.h /usr/include/_types/_uint32_t.h
fetchStage.o: /usr/include/sys/select.h /usr/include/sys/_types/_timeval.h
fetchStage.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_select.h
fetchStage.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
fetchStage.o: /usr/include/inttypes.h /usr/include/sys/_types/_wchar_t.h
fetchStage.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
fetchStage.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_intmax_t.h
fetchStage.o: /usr/include/_types/_uintmax_t.h /usr/include/stdlib.h
fetchStage.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
fetchStage.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
fetchStage.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
fetchStage.o: /usr/include/mach/machine/_structs.h
fetchStage.o: /usr/include/mach/i386/_structs.h
fetchStage.o: /usr/include/sys/_types/_sigaltstack.h
fetchStage.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
fetchStage.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
fetchStage.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
fetchStage.o: /usr/include/sys/errno.h printInternalReg.h
fetchStage.o: instructionSpecifications.h /usr/include/sys/stat.h
fetchStage.o: /usr/include/sys/mman.h decodeStage.h /usr/include/string.h
fetchStage.o: /usr/include/strings.h /usr/include/secure/_strings.h
fetchStage.o: /usr/include/secure/_string.h
instructionSpecifications.o: instructionSpecifications.h
instructionSpecifications.o: /usr/include/stdint.h
instructionSpecifications.o: /usr/include/sys/_types/_int8_t.h
instructionSpecifications.o: /usr/include/sys/_types/_int16_t.h
instructionSpecifications.o: /usr/include/sys/_types/_int32_t.h
instructionSpecifications.o: /usr/include/sys/_types/_int64_t.h
instructionSpecifications.o: /usr/include/_types/_uint8_t.h
instructionSpecifications.o: /usr/include/_types/_uint16_t.h
instructionSpecifications.o: /usr/include/_types/_uint32_t.h
instructionSpecifications.o: /usr/include/_types/_uint64_t.h
instructionSpecifications.o: /usr/include/sys/_types.h
instructionSpecifications.o: /usr/include/sys/cdefs.h
instructionSpecifications.o: /usr/include/sys/_symbol_aliasing.h
instructionSpecifications.o: /usr/include/sys/_posix_availability.h
instructionSpecifications.o: /usr/include/machine/_types.h
instructionSpecifications.o: /usr/include/i386/_types.h
instructionSpecifications.o: /usr/include/sys/_pthread/_pthread_types.h
instructionSpecifications.o: /usr/include/sys/_types/_intptr_t.h
instructionSpecifications.o: /usr/include/machine/types.h
instructionSpecifications.o: /usr/include/i386/types.h
instructionSpecifications.o: /usr/include/sys/_types/_u_int8_t.h
instructionSpecifications.o: /usr/include/sys/_types/_u_int16_t.h
instructionSpecifications.o: /usr/include/sys/_types/_u_int32_t.h
instructionSpecifications.o: /usr/include/sys/_types/_u_int64_t.h
instructionSpecifications.o: /usr/include/sys/_types/_uintptr_t.h
instructionSpecifications.o: /usr/include/_types/_intmax_t.h
instructionSpecifications.o: /usr/include/_types/_uintmax_t.h
instructionSpecifications.o: /usr/include/unistd.h /usr/include/_types.h
instructionSpecifications.o: /usr/include/sys/unistd.h
instructionSpecifications.o: /usr/include/sys/_types/_posix_vdisable.h
instructionSpecifications.o: /usr/include/sys/_types/_seek_set.h
instructionSpecifications.o: /usr/include/sys/_types/_size_t.h
instructionSpecifications.o: /usr/include/Availability.h
instructionSpecifications.o: /usr/include/AvailabilityInternal.h
instructionSpecifications.o: /usr/include/sys/_types/_ssize_t.h
instructionSpecifications.o: /usr/include/sys/_types/_uid_t.h
instructionSpecifications.o: /usr/include/sys/_types/_gid_t.h
instructionSpecifications.o: /usr/include/sys/_types/_off_t.h
instructionSpecifications.o: /usr/include/sys/_types/_pid_t.h
instructionSpecifications.o: /usr/include/sys/_types/_useconds_t.h
instructionSpecifications.o: /usr/include/sys/_types/_null.h
instructionSpecifications.o: /usr/include/sys/select.h
instructionSpecifications.o: /usr/include/sys/appleapiopts.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_def.h
instructionSpecifications.o: /usr/include/sys/_types/_timespec.h
instructionSpecifications.o: /usr/include/sys/_types/_timeval.h
instructionSpecifications.o: /usr/include/sys/_types/_time_t.h
instructionSpecifications.o: /usr/include/sys/_types/_suseconds_t.h
instructionSpecifications.o: /usr/include/sys/_types/_sigset_t.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_setsize.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_set.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_clr.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_isset.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_zero.h
instructionSpecifications.o: /usr/include/sys/_types/_fd_copy.h
instructionSpecifications.o: /usr/include/sys/_select.h
instructionSpecifications.o: /usr/include/sys/_types/_dev_t.h
instructionSpecifications.o: /usr/include/sys/_types/_mode_t.h
instructionSpecifications.o: /usr/include/sys/_types/_uuid_t.h
instructionSpecifications.o: /usr/include/gethostuuid.h /usr/include/stdio.h
instructionSpecifications.o: /usr/include/_stdio.h
instructionSpecifications.o: /usr/include/sys/_types/_va_list.h
instructionSpecifications.o: /usr/include/sys/stdio.h
instructionSpecifications.o: /usr/include/secure/_stdio.h
instructionSpecifications.o: /usr/include/secure/_common.h
instructionSpecifications.o: /usr/include/string.h
instructionSpecifications.o: /usr/include/sys/_types/_rsize_t.h
instructionSpecifications.o: /usr/include/sys/_types/_errno_t.h
instructionSpecifications.o: /usr/include/strings.h
instructionSpecifications.o: /usr/include/secure/_strings.h
instructionSpecifications.o: /usr/include/secure/_string.h
main.o: /usr/include/stdio.h /usr/include/_stdio.h /usr/include/sys/cdefs.h
main.o: /usr/include/sys/_symbol_aliasing.h
main.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
main.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
main.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/sys/_pthread/_pthread_types.h
main.o: /usr/include/sys/_types/_va_list.h /usr/include/machine/types.h
main.o: /usr/include/i386/types.h /usr/include/sys/_types/_int8_t.h
main.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
main.o: /usr/include/sys/_types/_int64_t.h
main.o: /usr/include/sys/_types/_u_int8_t.h
main.o: /usr/include/sys/_types/_u_int16_t.h
main.o: /usr/include/sys/_types/_u_int32_t.h
main.o: /usr/include/sys/_types/_u_int64_t.h
main.o: /usr/include/sys/_types/_intptr_t.h
main.o: /usr/include/sys/_types/_uintptr_t.h
main.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
main.o: /usr/include/sys/stdio.h /usr/include/sys/_types/_off_t.h
main.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
main.o: /usr/include/secure/_common.h /usr/include/fcntl.h
main.o: /usr/include/sys/fcntl.h /usr/include/sys/_types/_mode_t.h
main.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_o_sync.h
main.o: /usr/include/sys/_types/_o_dsync.h
main.o: /usr/include/sys/_types/_seek_set.h /usr/include/sys/_types/_s_ifmt.h
main.o: /usr/include/sys/_types/_timespec.h
main.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/types.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/endian.h
main.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
main.o: /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h
main.o: /usr/include/sys/_types/_u_char.h /usr/include/sys/_types/_u_short.h
main.o: /usr/include/sys/_types/_u_int.h /usr/include/sys/_types/_caddr_t.h
main.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_blkcnt_t.h
main.o: /usr/include/sys/_types/_blksize_t.h /usr/include/sys/_types/_gid_t.h
main.o: /usr/include/sys/_types/_in_addr_t.h
main.o: /usr/include/sys/_types/_in_port_t.h /usr/include/sys/_types/_ino_t.h
main.o: /usr/include/sys/_types/_ino64_t.h /usr/include/sys/_types/_key_t.h
main.o: /usr/include/sys/_types/_nlink_t.h /usr/include/sys/_types/_id_t.h
main.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/_types/_clock_t.h
main.o: /usr/include/sys/_types/_time_t.h
main.o: /usr/include/sys/_types/_useconds_t.h
main.o: /usr/include/sys/_types/_suseconds_t.h
main.o: /usr/include/sys/_types/_rsize_t.h /usr/include/sys/_types/_errno_t.h
main.o: /usr/include/sys/_types/_fd_def.h
main.o: /usr/include/sys/_types/_fd_setsize.h
main.o: /usr/include/sys/_types/_fd_set.h /usr/include/sys/_types/_fd_clr.h
main.o: /usr/include/sys/_types/_fd_zero.h
main.o: /usr/include/sys/_types/_fd_isset.h
main.o: /usr/include/sys/_types/_fd_copy.h
main.o: /usr/include/sys/_pthread/_pthread_attr_t.h
main.o: /usr/include/sys/_pthread/_pthread_cond_t.h
main.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
main.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_once_t.h
main.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
main.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
main.o: /usr/include/sys/_pthread/_pthread_t.h
main.o: /usr/include/sys/_pthread/_pthread_key_t.h
main.o: /usr/include/sys/_types/_fsblkcnt_t.h
main.o: /usr/include/sys/_types/_fsfilcnt_t.h /usr/include/sys/uio.h
main.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
main.o: /usr/include/sys/unistd.h /usr/include/sys/_types/_posix_vdisable.h
main.o: /usr/include/_types/_uint64_t.h /usr/include/_types/_uint32_t.h
main.o: /usr/include/sys/select.h /usr/include/sys/_types/_timeval.h
main.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_select.h
main.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
main.o: /usr/include/inttypes.h /usr/include/sys/_types/_wchar_t.h
main.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
main.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_intmax_t.h
main.o: /usr/include/_types/_uintmax_t.h /usr/include/stdlib.h
main.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
main.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
main.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
main.o: /usr/include/mach/machine/_structs.h
main.o: /usr/include/mach/i386/_structs.h
main.o: /usr/include/sys/_types/_sigaltstack.h
main.o: /usr/include/sys/_types/_ucontext.h /usr/include/sys/resource.h
main.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
main.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
main.o: /usr/include/sys/errno.h /usr/include/sys/stat.h
main.o: /usr/include/sys/mman.h printInternalReg.h
main.o: instructionSpecifications.h fetchStage.h decodeStage.h executeStage.h
main.o: memoryStage.h writeBackStage.h
memoryStage.o: memoryStage.h /usr/include/stdio.h /usr/include/_stdio.h
memoryStage.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
memoryStage.o: /usr/include/sys/_posix_availability.h
memoryStage.o: /usr/include/Availability.h
memoryStage.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
memoryStage.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
memoryStage.o: /usr/include/i386/_types.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_types.h
memoryStage.o: /usr/include/sys/_types/_va_list.h
memoryStage.o: /usr/include/machine/types.h /usr/include/i386/types.h
memoryStage.o: /usr/include/sys/_types/_int8_t.h
memoryStage.o: /usr/include/sys/_types/_int16_t.h
memoryStage.o: /usr/include/sys/_types/_int32_t.h
memoryStage.o: /usr/include/sys/_types/_int64_t.h
memoryStage.o: /usr/include/sys/_types/_u_int8_t.h
memoryStage.o: /usr/include/sys/_types/_u_int16_t.h
memoryStage.o: /usr/include/sys/_types/_u_int32_t.h
memoryStage.o: /usr/include/sys/_types/_u_int64_t.h
memoryStage.o: /usr/include/sys/_types/_intptr_t.h
memoryStage.o: /usr/include/sys/_types/_uintptr_t.h
memoryStage.o: /usr/include/sys/_types/_size_t.h
memoryStage.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
memoryStage.o: /usr/include/sys/_types/_off_t.h
memoryStage.o: /usr/include/sys/_types/_ssize_t.h
memoryStage.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
memoryStage.o: instructionSpecifications.h /usr/include/stdint.h
memoryStage.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
memoryStage.o: /usr/include/_types/_uint32_t.h
memoryStage.o: /usr/include/_types/_uint64_t.h
memoryStage.o: /usr/include/_types/_intmax_t.h
memoryStage.o: /usr/include/_types/_uintmax_t.h executeStage.h decodeStage.h
memoryStage.o: /usr/include/sys/types.h /usr/include/sys/appleapiopts.h
memoryStage.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
memoryStage.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
memoryStage.o: /usr/include/libkern/i386/_OSByteOrder.h
memoryStage.o: /usr/include/sys/_types/_u_char.h
memoryStage.o: /usr/include/sys/_types/_u_short.h
memoryStage.o: /usr/include/sys/_types/_u_int.h
memoryStage.o: /usr/include/sys/_types/_caddr_t.h
memoryStage.o: /usr/include/sys/_types/_dev_t.h
memoryStage.o: /usr/include/sys/_types/_blkcnt_t.h
memoryStage.o: /usr/include/sys/_types/_blksize_t.h
memoryStage.o: /usr/include/sys/_types/_gid_t.h
memoryStage.o: /usr/include/sys/_types/_in_addr_t.h
memoryStage.o: /usr/include/sys/_types/_in_port_t.h
memoryStage.o: /usr/include/sys/_types/_ino_t.h
memoryStage.o: /usr/include/sys/_types/_ino64_t.h
memoryStage.o: /usr/include/sys/_types/_key_t.h
memoryStage.o: /usr/include/sys/_types/_mode_t.h
memoryStage.o: /usr/include/sys/_types/_nlink_t.h
memoryStage.o: /usr/include/sys/_types/_id_t.h
memoryStage.o: /usr/include/sys/_types/_pid_t.h
memoryStage.o: /usr/include/sys/_types/_uid_t.h
memoryStage.o: /usr/include/sys/_types/_clock_t.h
memoryStage.o: /usr/include/sys/_types/_time_t.h
memoryStage.o: /usr/include/sys/_types/_useconds_t.h
memoryStage.o: /usr/include/sys/_types/_suseconds_t.h
memoryStage.o: /usr/include/sys/_types/_rsize_t.h
memoryStage.o: /usr/include/sys/_types/_errno_t.h
memoryStage.o: /usr/include/sys/_types/_fd_def.h
memoryStage.o: /usr/include/sys/_types/_fd_setsize.h
memoryStage.o: /usr/include/sys/_types/_fd_set.h
memoryStage.o: /usr/include/sys/_types/_fd_clr.h
memoryStage.o: /usr/include/sys/_types/_fd_zero.h
memoryStage.o: /usr/include/sys/_types/_fd_isset.h
memoryStage.o: /usr/include/sys/_types/_fd_copy.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_attr_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_cond_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_once_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_t.h
memoryStage.o: /usr/include/sys/_pthread/_pthread_key_t.h
memoryStage.o: /usr/include/sys/_types/_fsblkcnt_t.h
memoryStage.o: /usr/include/sys/_types/_fsfilcnt_t.h fetchStage.h
memoryStage.o: /usr/include/fcntl.h /usr/include/sys/fcntl.h
memoryStage.o: /usr/include/sys/_types/_o_sync.h
memoryStage.o: /usr/include/sys/_types/_o_dsync.h
memoryStage.o: /usr/include/sys/_types/_seek_set.h
memoryStage.o: /usr/include/sys/_types/_s_ifmt.h
memoryStage.o: /usr/include/sys/_types/_timespec.h
memoryStage.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/uio.h
memoryStage.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
memoryStage.o: /usr/include/sys/unistd.h
memoryStage.o: /usr/include/sys/_types/_posix_vdisable.h
memoryStage.o: /usr/include/sys/select.h /usr/include/sys/_types/_timeval.h
memoryStage.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_select.h
memoryStage.o: /usr/include/sys/_types/_uuid_t.h /usr/include/gethostuuid.h
memoryStage.o: /usr/include/inttypes.h /usr/include/sys/_types/_wchar_t.h
memoryStage.o: /usr/include/stdlib.h /usr/include/sys/wait.h
memoryStage.o: /usr/include/sys/signal.h /usr/include/machine/signal.h
memoryStage.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
memoryStage.o: /usr/include/i386/_mcontext.h
memoryStage.o: /usr/include/mach/machine/_structs.h
memoryStage.o: /usr/include/mach/i386/_structs.h
memoryStage.o: /usr/include/sys/_types/_sigaltstack.h
memoryStage.o: /usr/include/sys/_types/_ucontext.h
memoryStage.o: /usr/include/sys/resource.h /usr/include/alloca.h
memoryStage.o: /usr/include/sys/_types/_ct_rune_t.h
memoryStage.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
memoryStage.o: /usr/include/sys/errno.h printInternalReg.h writeBackStage.h
printInternalReg.o: /usr/include/stdio.h /usr/include/_stdio.h
printInternalReg.o: /usr/include/sys/cdefs.h
printInternalReg.o: /usr/include/sys/_symbol_aliasing.h
printInternalReg.o: /usr/include/sys/_posix_availability.h
printInternalReg.o: /usr/include/Availability.h
printInternalReg.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
printInternalReg.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
printInternalReg.o: /usr/include/i386/_types.h
printInternalReg.o: /usr/include/sys/_pthread/_pthread_types.h
printInternalReg.o: /usr/include/sys/_types/_va_list.h
printInternalReg.o: /usr/include/machine/types.h /usr/include/i386/types.h
printInternalReg.o: /usr/include/sys/_types/_int8_t.h
printInternalReg.o: /usr/include/sys/_types/_int16_t.h
printInternalReg.o: /usr/include/sys/_types/_int32_t.h
printInternalReg.o: /usr/include/sys/_types/_int64_t.h
printInternalReg.o: /usr/include/sys/_types/_u_int8_t.h
printInternalReg.o: /usr/include/sys/_types/_u_int16_t.h
printInternalReg.o: /usr/include/sys/_types/_u_int32_t.h
printInternalReg.o: /usr/include/sys/_types/_u_int64_t.h
printInternalReg.o: /usr/include/sys/_types/_intptr_t.h
printInternalReg.o: /usr/include/sys/_types/_uintptr_t.h
printInternalReg.o: /usr/include/sys/_types/_size_t.h
printInternalReg.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
printInternalReg.o: /usr/include/sys/_types/_off_t.h
printInternalReg.o: /usr/include/sys/_types/_ssize_t.h
printInternalReg.o: /usr/include/secure/_stdio.h
printInternalReg.o: /usr/include/secure/_common.h /usr/include/unistd.h
printInternalReg.o: /usr/include/sys/unistd.h
printInternalReg.o: /usr/include/sys/_types/_posix_vdisable.h
printInternalReg.o: /usr/include/sys/_types/_seek_set.h
printInternalReg.o: /usr/include/_types/_uint64_t.h
printInternalReg.o: /usr/include/_types/_uint32_t.h
printInternalReg.o: /usr/include/sys/_types/_uid_t.h
printInternalReg.o: /usr/include/sys/_types/_gid_t.h
printInternalReg.o: /usr/include/sys/_types/_pid_t.h
printInternalReg.o: /usr/include/sys/_types/_useconds_t.h
printInternalReg.o: /usr/include/sys/select.h /usr/include/sys/appleapiopts.h
printInternalReg.o: /usr/include/sys/_types/_fd_def.h
printInternalReg.o: /usr/include/sys/_types/_timespec.h
printInternalReg.o: /usr/include/sys/_types/_timeval.h
printInternalReg.o: /usr/include/sys/_types/_time_t.h
printInternalReg.o: /usr/include/sys/_types/_suseconds_t.h
printInternalReg.o: /usr/include/sys/_types/_sigset_t.h
printInternalReg.o: /usr/include/sys/_types/_fd_setsize.h
printInternalReg.o: /usr/include/sys/_types/_fd_set.h
printInternalReg.o: /usr/include/sys/_types/_fd_clr.h
printInternalReg.o: /usr/include/sys/_types/_fd_isset.h
printInternalReg.o: /usr/include/sys/_types/_fd_zero.h
printInternalReg.o: /usr/include/sys/_types/_fd_copy.h
printInternalReg.o: /usr/include/sys/_select.h
printInternalReg.o: /usr/include/sys/_types/_dev_t.h
printInternalReg.o: /usr/include/sys/_types/_mode_t.h
printInternalReg.o: /usr/include/sys/_types/_uuid_t.h
printInternalReg.o: /usr/include/gethostuuid.h printInternalReg.h
printInternalReg.o: /usr/include/stdint.h /usr/include/_types/_uint8_t.h
printInternalReg.o: /usr/include/_types/_uint16_t.h
printInternalReg.o: /usr/include/_types/_intmax_t.h
printInternalReg.o: /usr/include/_types/_uintmax_t.h
printInternalReg.o: instructionSpecifications.h
writeBackStage.o: writeBackStage.h /usr/include/stdio.h /usr/include/_stdio.h
writeBackStage.o: /usr/include/sys/cdefs.h
writeBackStage.o: /usr/include/sys/_symbol_aliasing.h
writeBackStage.o: /usr/include/sys/_posix_availability.h
writeBackStage.o: /usr/include/Availability.h
writeBackStage.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
writeBackStage.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
writeBackStage.o: /usr/include/i386/_types.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_types.h
writeBackStage.o: /usr/include/sys/_types/_va_list.h
writeBackStage.o: /usr/include/machine/types.h /usr/include/i386/types.h
writeBackStage.o: /usr/include/sys/_types/_int8_t.h
writeBackStage.o: /usr/include/sys/_types/_int16_t.h
writeBackStage.o: /usr/include/sys/_types/_int32_t.h
writeBackStage.o: /usr/include/sys/_types/_int64_t.h
writeBackStage.o: /usr/include/sys/_types/_u_int8_t.h
writeBackStage.o: /usr/include/sys/_types/_u_int16_t.h
writeBackStage.o: /usr/include/sys/_types/_u_int32_t.h
writeBackStage.o: /usr/include/sys/_types/_u_int64_t.h
writeBackStage.o: /usr/include/sys/_types/_intptr_t.h
writeBackStage.o: /usr/include/sys/_types/_uintptr_t.h
writeBackStage.o: /usr/include/sys/_types/_size_t.h
writeBackStage.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
writeBackStage.o: /usr/include/sys/_types/_off_t.h
writeBackStage.o: /usr/include/sys/_types/_ssize_t.h
writeBackStage.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
writeBackStage.o: instructionSpecifications.h /usr/include/stdint.h
writeBackStage.o: /usr/include/_types/_uint8_t.h
writeBackStage.o: /usr/include/_types/_uint16_t.h
writeBackStage.o: /usr/include/_types/_uint32_t.h
writeBackStage.o: /usr/include/_types/_uint64_t.h
writeBackStage.o: /usr/include/_types/_intmax_t.h
writeBackStage.o: /usr/include/_types/_uintmax_t.h memoryStage.h
writeBackStage.o: executeStage.h decodeStage.h /usr/include/sys/types.h
writeBackStage.o: /usr/include/sys/appleapiopts.h
writeBackStage.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
writeBackStage.o: /usr/include/sys/_endian.h
writeBackStage.o: /usr/include/libkern/_OSByteOrder.h
writeBackStage.o: /usr/include/libkern/i386/_OSByteOrder.h
writeBackStage.o: /usr/include/sys/_types/_u_char.h
writeBackStage.o: /usr/include/sys/_types/_u_short.h
writeBackStage.o: /usr/include/sys/_types/_u_int.h
writeBackStage.o: /usr/include/sys/_types/_caddr_t.h
writeBackStage.o: /usr/include/sys/_types/_dev_t.h
writeBackStage.o: /usr/include/sys/_types/_blkcnt_t.h
writeBackStage.o: /usr/include/sys/_types/_blksize_t.h
writeBackStage.o: /usr/include/sys/_types/_gid_t.h
writeBackStage.o: /usr/include/sys/_types/_in_addr_t.h
writeBackStage.o: /usr/include/sys/_types/_in_port_t.h
writeBackStage.o: /usr/include/sys/_types/_ino_t.h
writeBackStage.o: /usr/include/sys/_types/_ino64_t.h
writeBackStage.o: /usr/include/sys/_types/_key_t.h
writeBackStage.o: /usr/include/sys/_types/_mode_t.h
writeBackStage.o: /usr/include/sys/_types/_nlink_t.h
writeBackStage.o: /usr/include/sys/_types/_id_t.h
writeBackStage.o: /usr/include/sys/_types/_pid_t.h
writeBackStage.o: /usr/include/sys/_types/_uid_t.h
writeBackStage.o: /usr/include/sys/_types/_clock_t.h
writeBackStage.o: /usr/include/sys/_types/_time_t.h
writeBackStage.o: /usr/include/sys/_types/_useconds_t.h
writeBackStage.o: /usr/include/sys/_types/_suseconds_t.h
writeBackStage.o: /usr/include/sys/_types/_rsize_t.h
writeBackStage.o: /usr/include/sys/_types/_errno_t.h
writeBackStage.o: /usr/include/sys/_types/_fd_def.h
writeBackStage.o: /usr/include/sys/_types/_fd_setsize.h
writeBackStage.o: /usr/include/sys/_types/_fd_set.h
writeBackStage.o: /usr/include/sys/_types/_fd_clr.h
writeBackStage.o: /usr/include/sys/_types/_fd_zero.h
writeBackStage.o: /usr/include/sys/_types/_fd_isset.h
writeBackStage.o: /usr/include/sys/_types/_fd_copy.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_attr_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_cond_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_condattr_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_mutex_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_mutexattr_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_once_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_rwlock_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_rwlockattr_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_t.h
writeBackStage.o: /usr/include/sys/_pthread/_pthread_key_t.h
writeBackStage.o: /usr/include/sys/_types/_fsblkcnt_t.h
writeBackStage.o: /usr/include/sys/_types/_fsfilcnt_t.h fetchStage.h
writeBackStage.o: /usr/include/fcntl.h /usr/include/sys/fcntl.h
writeBackStage.o: /usr/include/sys/_types/_o_sync.h
writeBackStage.o: /usr/include/sys/_types/_o_dsync.h
writeBackStage.o: /usr/include/sys/_types/_seek_set.h
writeBackStage.o: /usr/include/sys/_types/_s_ifmt.h
writeBackStage.o: /usr/include/sys/_types/_timespec.h
writeBackStage.o: /usr/include/sys/_types/_filesec_t.h /usr/include/sys/uio.h
writeBackStage.o: /usr/include/sys/_types/_iovec_t.h /usr/include/unistd.h
writeBackStage.o: /usr/include/sys/unistd.h
writeBackStage.o: /usr/include/sys/_types/_posix_vdisable.h
writeBackStage.o: /usr/include/sys/select.h
writeBackStage.o: /usr/include/sys/_types/_timeval.h
writeBackStage.o: /usr/include/sys/_types/_sigset_t.h
writeBackStage.o: /usr/include/sys/_select.h
writeBackStage.o: /usr/include/sys/_types/_uuid_t.h
writeBackStage.o: /usr/include/gethostuuid.h /usr/include/inttypes.h
writeBackStage.o: /usr/include/sys/_types/_wchar_t.h /usr/include/stdlib.h
writeBackStage.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
writeBackStage.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
writeBackStage.o: /usr/include/machine/_mcontext.h
writeBackStage.o: /usr/include/i386/_mcontext.h
writeBackStage.o: /usr/include/mach/machine/_structs.h
writeBackStage.o: /usr/include/mach/i386/_structs.h
writeBackStage.o: /usr/include/sys/_types/_sigaltstack.h
writeBackStage.o: /usr/include/sys/_types/_ucontext.h
writeBackStage.o: /usr/include/sys/resource.h /usr/include/alloca.h
writeBackStage.o: /usr/include/sys/_types/_ct_rune_t.h
writeBackStage.o: /usr/include/sys/_types/_rune_t.h /usr/include/errno.h
writeBackStage.o: /usr/include/sys/errno.h printInternalReg.h
