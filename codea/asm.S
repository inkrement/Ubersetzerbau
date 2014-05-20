	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	movq %rsi, %r10
	cmp %rax, %r10
	setne %al
	and $1, %rax
	neg %rax
	ret
