assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	addq $16, %rax
	movq (%rax,2,8), %rax
	movq (%rax,2,8), %rax
	movq %rdi, %r10
	addq $8, %r10
	movq (%r10,2,8), %r10
	movq (%r10,1,8), %r10
	imulq %r10, %rax
	ret
