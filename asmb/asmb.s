	.text
	.globl _asmb
#	.type asma, @function
_asmb:

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

	## 3. compare bytewise
	pminub %xmm0, %xmm1

	## 4. first operand xmm0 is result of smallest values (return it)
	movdqa %xmm1, (%rdx)

LBB0_3:
	xorl %eax, %eax  					# zero function return
	popq	%rbp						# pop frame pointer
	ret
