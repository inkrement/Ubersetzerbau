assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rsi, %rax
	movq %rdi, %r10
	movq (%r10,0,8), %r10
	imulq %r10, %rax
	ret
