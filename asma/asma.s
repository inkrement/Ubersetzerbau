        .text
        .globl asma
        .type asma, @function

asma:
	movdqu (%rsi), %xmm8
	movdqu (%rdi), %xmm9

	PCMPEQD %xmm10, %xmm10

	PXOR %xmm10, %xmm8
	PXOR %xmm10, %xmm9

	pminub %xmm9, %xmm8

	PXOR %xmm10, %xmm8

	movdqu %xmm8, (%rdx)

	ret
