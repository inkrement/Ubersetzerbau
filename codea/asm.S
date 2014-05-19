	.text

	.globl funf
	.type funf, @function
funf:
	movq $5, %rax
	ret

	.globl zwei
	.type zwei, @function
zwei:
	movq $2, %rax
	ret
