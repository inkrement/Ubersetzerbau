assert exists feldkontext
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
	addq $8, %r10
	movq (%r10,2,8), %r10
	movq (%r10,1,8), %r10
	cmp %r10, %rax
	setg %al
	and $1, %rax
	neg %rax
	ret
