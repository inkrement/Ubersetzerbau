	.text
	.globl asma
	.type asma, @function
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

	## 3. create mask
	movdqa $0xFFFFFFFF , %xmm2

	## 4. s xmm0 invertieren
    andps %xmm0, %xmm2

	## 5. t xmm1 invertieren
	andps %xmm1, %xmm2

	## 6. take minimal 
	pminub %xmm0, %xmm1

	## 7. invert result
	andps %xmm1, %xmm2

	## 8. first operand xmm0 is result of smallest values (return it)
	movdqa %xmm1, (%rdx)

LBB0_3:
	xorl %eax, %eax  					# zero function return
	popq	%rbp						# pop frame pointer
	ret
