	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %r10
	addq $1, %r10
	or $82629813614160400, %r10
	movq %r10, %rax
	ret
