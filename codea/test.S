	.comm a,3,3
	.text

	.globl oder
	.type oder, @function
oder:
	movq %rdi, %rax
	movq %rsi, %r11
	or %rax, %r11
	movq %r11, %rax
	movq %rdx, %r10
	or %rax, %r10
	movq %r10, %rax
	ret

	.globl greater
	.type greater, @function
greater:
	movq %rdi, %rax
	movq %rsi, %r10
	cmp %r10, %rax
	setg %al
	and $1, %rax
	neg %rax
	ret

	.globl neq
	.type neq, @function
neq:
	movq %rdi, %rax
	movq %rsi, %r10
	cmp %rax, %r10
	setne %al
	and $1, %rax
	neg %rax
	ret
