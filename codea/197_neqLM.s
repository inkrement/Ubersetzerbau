assert exists feldkontext
	.comm s2,3,3
	.comm s1,3,3
	.comm s0,3,3
	.text

	.globl f
	.type f, @function
f:
	movq %rdi, %r10
	movq (%r10,1,8), %r10
	cmpq $82629813614160400, %r10
	setne %al
	and $1, %rax
	neg %rax
	ret
