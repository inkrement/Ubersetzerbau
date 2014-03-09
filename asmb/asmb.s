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

	## 3. copy u to xmm2
	movdqa (%rdx), %xmm2

	## 4. compare bytewise
	pminub %xmm0, %xmm1

	## 5. copy xmm1->xmm2 until xmm2[i] == 0


	xor %ecx, %ecx //auf null setzen

copy:
	cmp $0,  /* xmm1 byte an stelle %ecx */
	jmp end

	## 6. copy byte
	mov ()()

	inc %ecx
	jmp copy

end:



	## 6. first operand xmm0 is result of smallest values (return it)
	movdqa %xmm2, (%rdx)

LBB0_3:
	xorl %eax, %eax  					# zero function return
	popq	%rbp						# pop frame pointer
	ret
