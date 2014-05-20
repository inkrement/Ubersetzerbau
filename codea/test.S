assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
assert exists feldkontext
	.comm n,6,6
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

	.globl neg
	.type neg, @function
neg:
	movq %rdi, %rax
	notq %rax
	negq %rax
	notq %rax
	ret

	.globl f
	.type f, @function
f:
	movq %rsi, %rax
	movq %rdi, %r10
	addq $4, %r10
	addq %r10, %rax
	ret

	.globl f
	.type f, @function
f:
	movq %rdi, %rax
	movq (%rax,5,8), %rax
	negq %rax
	movq %rdi, %r10
	movq (%r10,2,8), %r10
	movq %rdi, %r9
	movq (%r9,1,8), %r9
	or %r10, %r9
	movq %r9, %r10
	movq %rdi, %r11
	movq (%r11,5,8), %r11
	movq %rdi, %r9
	movq (%r9,4,8), %r9
	addq $5, %r9
	imulq %r9, %r11
	movq %rdi, %r9
	movq (%r9,4,8), %r9
	movq %rdi, %r8
	movq (%r8,3,8), %r8
	notq %r8
	imulq %r8, %r9
	addq %r9, %r11
	addq %r11, %r10
	addq %r10, %rax
	ret
