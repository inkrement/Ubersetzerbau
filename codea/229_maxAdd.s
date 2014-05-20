assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
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
	movq %rdi, %r9
	movq (%r9,1,8), %r9
	movq (%r9,1,8), %r9
	movq %rdi, %r8
	movq (%r8,1,8), %r8
	movq (%r8,1,8), %r8
	addq %r8, %r9
	addq $3, %r9
	movq %r9, %r11
	movq %rdi, %r8
	movq (%r8,1,8), %r8
	movq (%r8,1,8), %r8
	movq %rdi, %rcx
	movq (%rcx,1,8), %rcx
	movq (%rcx,1,8), %rcx
	addq %rcx, %r8
	addq $3, %r8
	movq %r8, %r9
	addq %r9, %r11
	addq $2, %r11
	movq %r11, %r10
	movq %rdx, %r11
	movq %rdi, %rcx
	movq (%rcx,1,8), %rcx
	movq (%rcx,1,8), %rcx
	movq %rdi, %rdx
	movq (%rdx,1,8), %rdx
	movq (%rdx,1,8), %rdx
	addq %rdx, %rcx
	addq $3, %rcx
	movq %rcx, %r8
	movq %rdi, %rdx
	movq (%rdx,1,8), %rdx
	movq (%rdx,1,8), %rdx
	movq %rdi, %rsi
	movq (%rsi,1,8), %rsi
	movq (%rsi,1,8), %rsi
	addq %rsi, %rdx
	addq $3, %rdx
	movq %rdx, %rcx
	addq %rcx, %r8
	addq $2, %r8
	movq %r8, %r9
	addq %r9, %r11
	addq %r11, %r10
	addq $1, %r10
	movq %r10, %rax
	ret
