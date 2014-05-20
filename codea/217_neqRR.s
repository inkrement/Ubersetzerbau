	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	addq $3, %rax
	movq %rsi, %r10
	cmp %rax, %r10
	setne %al
	and $1, %rax
	neg %rax
	ret
