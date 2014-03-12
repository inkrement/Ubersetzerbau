	.text
	.globl asma
	.type asma, @function

	.data
mask: 
         .align
         .size mask, 16
         .fill 16, 1, 0xFF

asma:

# Funktions-Prolog
.LFB0:
	pushq	%rbp						# frame pointer backup
	movq	%rsp, %rbp					# set new frame pointer

Ltmp4:
	.align	4, 0x90						

	## 1. copy rsi to xmm0
	movdqa (%rsi), %xmm0

	## 2. copy rdi to xmm1
	movdqa (%rdi), %xmm1

    movdqa %xmm0, %xmm2

    PCMPEQD %xmm2, %xmm2

    PXOR %xmm2, %xmm0

    PXOR %xmm2, %xmm1

	## 6. take minimal 
	pminub %xmm0, %xmm1

	PXOR %xmm2, %xmm0

	## 8. first operand xmm0 is result of smallest values (return it)
	movdqa %xmm0, (%rdx)

LBB0_3:
	xorl %eax, %eax  					# zero function return
	popq	%rbp						# pop frame pointer
	ret
