0x100:                      | sum_function:
0x100: 30f20010000000000000 | 	irmovq $a, %rdx
0x10a: 6300                 | 	xorq   %rax, %rax
0x10c:                      | L2:
0x10c: 50320000000000000000 | 	mrmovq (%rdx), %rbx
0x116: 6030                 | 	addq   %rbx, %rax
0x118: 30f30400000000000000 | 	irmovq 0x4, %rbx
0x122: 6032                 | 	addq   %rbx, %rdx
0x124: 30f33010000000000000 | 	irmovq $aend, %rbx
0x12e: 6123                 | 	subq   %rdx, %rbx
0x130: 740c010000000   | 	jne   L2

