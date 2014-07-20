	.text

	.globl oder
	.type oder, @function
oder:
	movq %rdi, %rax
	movq %rsi, %r11
	or %rax, %r11
	movq %r11, %rax
	movq %rdx, %r11
	or %rax, %r11
	movq %r11, %rax
	ret