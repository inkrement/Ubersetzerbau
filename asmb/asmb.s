	.text
	.globl _asmb
#	.type asmb, @function

_asmb:

xor %rcx, %rcx
pxor %xmm2, %xmm2
pxor %xmm3, %xmm3 # mask

loop:

	movb (%rdi, %rcx), %r8b
	movb (%rsi, %rcx), %r9b
	
	#cmp $0, %r8b
	#je exit
	#cmp $0, %r9b
	#je exit

	PINSRB $0x00, %r8d, %xmm1
	PINSRB $0x00, %r9d, %xmm2

	pminub %xmm1, %xmm2

	CMPEQPS %xmm2, %xmm3
	je exit


	PEXTRB $0x00 , %xmm2, (%rdx, %rcx)

	inc %rcx
	jmp loop

exit:
	movb $0, (%rdx, %rcx)
	ret
