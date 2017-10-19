                            | # Modification of asum code to compute absolute values of entries.
                            | # This version uses a conditional jump
                            | # Execution begins at address 0 
0x000:                      | 	.pos 0 
0x000: 30f40002000000000000 | 	irmovq stack, %rsp  	# Set up stack pointer  
0x00a: 801400000000000000   | 	call main		# Execute main program
0x013: 00                   | 	halt			# Terminate program 
                            | 
                            | 
0x014: 30f78000000000000000 | main:	irmovq array,%rdi	
0x01e: 30f60400000000000000 | 	irmovq $4,%rsi
0x028: 803200000000000000   | 	call absSum		# absSum(array, 4)
0x031: 90                   | 	ret 
                            | /* $begin abs-sum-jmp-ys */
                            | # long absSum(long *start, long count)
                            | # start in %rdi, count in %rsi
0x032:                      | absSum:
0x032: 30f80800000000000000 | 	irmovq $8,%r8           # Constant 8
0x03c: 30f90100000000000000 | 	irmovq $1,%r9	        # Constant 1
0x046: 6300                 | 	xorq %rax,%rax		# sum = 0
0x048: 6266                 | 	andq %rsi,%rsi		# Set condition codes
0x04a: 707200000000000000   | 	jmp  test
0x053:                      | loop:
0x053: 50a70000000000000000 | 	mrmovq (%rdi),%r10	# x = *start
0x05d: 63bb                 | 	xorq %r11,%r11          # Constant 0
0x05f: 61ab                 | 	subq %r10,%r11		# -x
0x061: 716c00000000000000   | 	jle pos			# Skip if -x <= 0
0x06a: 20ba                 | 	rrmovq %r11,%r10	# x = -x
0x06c:                      | pos:
0x06c: 60a0                 | 	addq %r10,%rax          # Add to sum
0x06e: 6087                 | 	addq %r8,%rdi           # start++
0x070: 6196                 | 	subq %r9,%rsi           # count--
0x072:                      | test:
0x072: 745300000000000000   | 	jne    loop             # Stop when 0
0x07b: 90                   | 	ret
                            | /* $end abs-sum-jmp-ys */
                            | 
                            | 
                            | # Array of 4 elements
0x080:                      | 	.align 8 	
0x080: 0d000d000d000000     | array:	.quad 0x0000000d000d000d
0x088: 40ff3fff3fffffff     | 	.quad 0xffffff3fff3fff40  # -0x000000c000c000c0
0x090: 000b000b000b0000     | 	.quad 0x00000b000b000b00
0x098: 0060ff5fff5fffff     | 	.quad 0xffff5fff5fff6000  # -0x0000a000a000a000  
                            | 
                            | 
                            | # The stack starts here and grows to lower addresses
0x200:                      | 	.pos 0x200		
0x200:                      | stack:	 
