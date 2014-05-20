assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	movq (%rax,0,8), %rax
	or $168434714562168210, %rax
	ret
