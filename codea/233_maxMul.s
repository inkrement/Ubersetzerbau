assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
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
	movq %rdi, %r11
	movq (%r11,1,8), %r11
	movq (%r11,1,8), %r11
	movq %rdi, %r9
	movq (%r9,1,8), %r9
	movq (%r9,1,8), %r9
	imulq %r9, %r11
	imulq $2, %r11
	movq %rcx, %r11
	movq %rdi, %r8
	movq (%r8,1,8), %r8
	movq (%r8,1,8), %r8
	movq %rdi, %rcx
	movq (%rcx,1,8), %rcx
	movq (%rcx,1,8), %rcx
	imulq %rcx, %r8
	imulq $2, %r8
	imulq %r9, %r11
	imulq %r11, %r10
	ret
