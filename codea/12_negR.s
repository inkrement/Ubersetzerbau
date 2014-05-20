	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rsi, %rax
	addq $1, %rax
	negq %rax
	ret
