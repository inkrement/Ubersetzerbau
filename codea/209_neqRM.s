assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rsi, %rax
	addq $1, %rax
	movq %rdi, %r10
	movq (%r10,0,8), %r10
	cmp %rax, %r10
	setne %al
	and $1, %rax
	neg %rax
	ret
