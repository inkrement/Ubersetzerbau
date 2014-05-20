assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %r10
	movq (%r10,1,8), %r10
	addq $4869875336, %r10
	movq %r10, %rax
	ret
