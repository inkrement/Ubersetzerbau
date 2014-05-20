	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	addq $1, %rax
	movq %rsi, %r10
	addq $1, %r10
	addq %r10, %rax
	ret
