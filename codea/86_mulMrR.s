assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	addq $8, %rax
	movq (%rax,1,8), %rax
	movq %rsi, %r10
	imulq %r10, %rax
	ret
