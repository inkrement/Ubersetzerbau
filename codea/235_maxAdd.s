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
	movq %rdi, %r10
	movq (%r10,1,8), %r10
	movq (%r10,1,8), %r10
	movq %r8, %r11
	movq %rdi, %r9
	movq (%r9,1,8), %r9
	movq (%r9,1,8), %r9
	addq %r9, %r11
	addq %r11, %r10
	addq $1, %r10
	movq %r10, %rax
	ret
