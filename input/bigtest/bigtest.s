0x000: 0a00000000000000     | .quad   10
0x008: 8977000000000000     | .quad   0x7789
                            | 
                            | 
                            | 
                            | 
0x100:                      | .pos 0x100
                            | 	# let's just enumerate a bunch of instructions
                            | 	# do a move across all the registers
0x100: 2000                 | 	rrmovq  %rax, %rax
0x102: 2001                 | 	rrmovq  %rax, %rcx
0x104: 2002                 | 	rrmovq  %rax, %rdx
0x106: 2003                 | 	rrmovq  %rax, %rbx
0x108: 2006                 | 	rrmovq   %rax, %rsi
0x10a: 2007                 | 	rrmovq  %rax, %rdi
0x10c: 2004                 | 	rrmovq  %rax, %rsp
0x10e: 2005                 | 	rrmovq  %rax, %rbp
                            | 
0x110: 2016                 | 	rrmovq   %rcx, %rsi
0x112: 2026                 | 	rrmovq   %rdx, %rsi
0x114: 2036                 | 	rrmovq   %rbx, %rsi
0x116: 2066                 | 	rrmovq    %rsi, %rsi
0x118: 2076                 | 	rrmovq   %rdi, %rsi
0x11a: 2046                 | 	rrmovq   %rsp, %rsi
0x11c: 2056                 | 	rrmovq   %rbp, %rsi
                            | 
0x11e: 30f0efbeadde00000000 | 	irmovq  $0xdeadbeef, %rax 
0x128: 30f1efbeadde00000000 | 	irmovq  $0xdeadbeef, %rcx
0x132: 30f2efbeadde00000000 | 	irmovq  $0xdeadbeef, %rdx
0x13c: 30f3efbeadde00000000 | 	irmovq  $0xdeadbeef, %rbx
0x146: 30f6efbeadde00000000 | 	irmovq  $0xdeadbeef, %rsi
0x150: 30f7efbeadde00000000 | 	irmovq  $0xdeadbeef, %rdi
0x15a: 30f4efbeadde00000000 | 	irmovq  $0xdeadbeef, %rsp
0x164: 30f5efbeadde00000000 | 	irmovq  $0xdeadbeef, %rbp
                            | 
                            | 
0x500:                      | .pos 0x500
0x500:                      | .align 8
0x500: 4000edfeaddeefbe0000 | 	rmmovq  %rax, 0xbeefdeadfeed(%rax)
0x50a: 4001addeefbe00000000 | 	rmmovq  %rax, 0xbeefdead(%rcx)
0x514: 4002addeefbe00000000 | 	rmmovq  %rax, 0xbeefdead(%rdx)
0x51e: 4003edfeaddeefbe0000 | 	rmmovq  %rax, 0xbeefdeadfeed(%rbx)
0x528: 4006addeefbe00000000 | 	rmmovq  %rax, 0xbeefdead(%rsi)
0x532: 4007addeefbe00000000 | 	rmmovq  %rax, 0xbeefdead(%rdi)
0x53c: 4004edfeaddeefbe0000 | 	rmmovq  %rax, 0xbeefdeadfeed(%rsp)
0x546: 4005eddfeafdee0b0000 | 	rmmovq  %rax, 0xbeefdeadfed(%rbp)
                            | 
0x550: 4000addeefbe00000000 | 	rmmovq  %rax, 0xbeefdead(%rax)
0x55a: 4010addeefbe00000000 | 	rmmovq  %rcx, 0xbeefdead(%rax)
0x564: 4020addeefbe00000000 | 	rmmovq  %rdx, 0xbeefdead(%rax)
0x56e: 4030addeefbe00000000 | 	rmmovq  %rbx, 0xbeefdead(%rax)
0x578: 406089887777addeefbe | 	rmmovq  %rsi, 0xbeefdead77778889(%rax)
0x582: 4070addeefbe00000000 | 	rmmovq  %rdi, 0xbeefdead(%rax)
0x58c: 4040addeefbe00000000 | 	rmmovq  %rsp, 0xbeefdead(%rax)
0x596: 4050addeefbe00000000 | 	rmmovq  %rbp, 0xbeefdead(%rax)
                            | 
                            | 
0x5a0: 5000addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rax
0x5aa: 5001addeefbe00000000 | 	mrmovq  0xbeefdead(%rcx),%rax
0x5b4: 5002addeefbe00000000 | 	mrmovq  0xbeefdead(%rdx),%rax
0x5be: 5003addeefbe00000000 | 	mrmovq  0xbeefdead(%rbx),%rax
0x5c8: 5006addeefbe00000000 | 	mrmovq  0xbeefdead(%rsi),%rax
0x5d2: 5007addeefbe00000000 | 	mrmovq  0xbeefdead(%rdi),%rax
0x5dc: 5004addeefbe00000000 | 	mrmovq  0xbeefdead(%rsp),%rax
0x5e6: 5005addeefbe00000000 | 	mrmovq  0xbeefdead(%rbp),%rax
                            | 				     
0x5f0: 5000addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rax
0x5fa: 5010addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rcx
0x604: 5020addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rdx
0x60e: 5030addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rbx
0x618: 5060addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rsi
0x622: 5070addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rdi
0x62c: 5040addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rsp
0x636: 5050addeefbe00000000 | 	mrmovq  0xbeefdead(%rax),%rbp
                            | 
0x600:                      | .pos 0x600
0x600:                      | .align 8
0x600: 6000                 | 	addq  %rax, %rax
0x602: 6001                 | 	addq  %rax, %rcx
0x604: 6002                 | 	addq  %rax, %rdx
0x606: 6003                 | 	addq  %rax, %rbx
0x608: 6006                 | 	addq  %rax, %rsi
0x60a: 6007                 | 	addq  %rax, %rdi
0x60c: 6004                 | 	addq  %rax, %rsp
0x60e: 6005                 | 	addq  %rax, %rbp
                            | 
0x610: 6016                 | 	addq   %rcx, %rsi
0x612: 6026                 | 	addq   %rdx, %rsi
0x614: 6036                 | 	addq   %rbx, %rsi
0x616: 6066                 | 	addq   %rsi, %rsi
0x618: 6076                 | 	addq   %rdi, %rsi
0x61a: 6046                 | 	addq   %rsp, %rsi
0x61c: 6056                 | 	addq   %rbp, %rsi
                            | 
                            | 
0x61e: 6010                 | 	addq   %rcx, %rax
0x620: 6018                 | 	addq   %rcx, %r8
0x622: 6029                 | 	addq   %rdx, %r9
0x624: 603a                 | 	addq   %rbx, %r10
0x626: 606b                 | 	addq   %rsi, %r11
0x628: 607c                 | 	addq   %rdi, %r12
0x62a: 604d                 | 	addq   %rsp, %r13
0x62c: 605e                 | 	addq   %rbp, %r14
                            | 
                            | 
0x62e: 60e5                 | 	addq   %r14, %rbp
0x630: 60c8                 | 	addq   %r12, %r8
0x632: 60c9                 | 	addq   %r12, %r9
0x634: 60ba                 | 	addq   %r11, %r10
0x636: 60ab                 | 	addq   %r10, %r11
0x638: 609c                 | 	addq   %r9, %r12
0x63a: 608d                 | 	addq   %r8, %r13
0x63c: 604e                 | 	addq   %rsp, %r14
                            | 
0x63e: 6116                 | 	subq   %rcx, %rsi
0x640: 6226                 | 	andq   %rdx, %rsi
0x642: 6336                 | 	xorq   %rbx, %rsi
                            | 
                            | 
0x644: 70adddda0000000000   | 	jmp  0xdaddad
0x64d: 71adddda0000000000   | 	jle  0xdaddad
0x656: 72daddda0000000000   | 	jl   0xdaddda
0x65f: 73adddda0000000000   | 	je   0xdaddad
0x668: 74adddda0000000000   | 	jne  0xdaddad
0x671: 75adddda0000000000   | 	jge  0xdaddad
0x67a: 76adddda0000000000   | 	jg   0xdaddad
                            | 	
0x683: 2200                 | 	cmovl  %rax, %rax
0x685: 2201                 | 	cmovl  %rax, %rcx
0x687: 2202                 | 	cmovl  %rax, %rdx
0x689: 2203                 | 	cmovl  %rax, %rbx
0x68b: 2206                 | 	cmovl  %rax, %rsi
0x68d: 2207                 | 	cmovl  %rax, %rdi
0x68f: 2204                 | 	cmovl  %rax, %rsp
0x691: 2205                 | 	cmovl  %rax, %rbp
                            | 
0x693: 90                   | 	ret
                            | 	
0x694: 2216                 | 	cmovl   %rcx, %rsi
0x696: 2226                 | 	cmovl   %rdx, %rsi
0x698: 2236                 | 	cmovl   %rbx, %rsi
0x69a: 2266                 | 	cmovl   %rsi, %rsi
0x69c: 2276                 | 	cmovl   %rdi, %rsi
0x69e: 2246                 | 	cmovl   %rsp, %rsi
0x6a0: 2256                 | 	cmovl   %rbp, %rsi
                            | 
0x6a2: 805634129078563412   | 	call    0x1234567890123456
                            | 	
0x6ab: 2116                 | 	cmovle   %rcx, %rsi
0x6ad: 2226                 | 	cmovl   %rdx, %rsi
0x6af: 2436                 | 	cmovne   %rbx, %rsi
0x6b1: 2566                 | 	cmovge   %rsi, %rsi
0x6b3: 2676                 | 	cmovg   %rdi, %rsi
                            | 
0x6b5: a00f                 | 	pushq   %rax
0x6b7: a01f                 | 	pushq   %rcx
0x6b9: a02f                 | 	pushq   %rdx
0x6bb: a03f                 | 	pushq   %rbx
0x6bd: a06f                 | 	pushq   %rsi
0x6bf: a07f                 | 	pushq   %rdi
0x6c1: a04f                 | 	pushq   %rsp
0x6c3: a05f                 | 	pushq   %rbp
                            | 
0x6c5: b00f                 | 	popq   %rax
0x6c7: b01f                 | 	popq   %rcx
0x6c9: b02f                 | 	popq   %rdx
0x6cb: b03f                 | 	popq   %rbx
0x6cd: b06f                 | 	popq   %rsi
0x6cf: b07f                 | 	popq   %rdi
0x6d1: b04f                 | 	popq   %rsp
0x6d3: b05f                 | 	popq   %rbp
                            | 
                            | 
                            | 
                            | 
                            | 	
