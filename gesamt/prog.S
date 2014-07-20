	.text

	.globl mysgn
	.type mysgn, @function
mysgn:
	movq %rdi, %rax
	# greateri between 0 and %rdi to %rax (reg & imm)
	movq $0, %rax
	movq $-1, %r10
	cmpq $0, %rdi
	cmovlq %r10, %rax
	movq %rdi, %r10
	# greateri2
	movq $0, %r10
	movq $-1, %r11
	cmpq $0, %rdi
	cmovgq %r11, %r10
	cmp $0, %r10
	jl cond_1
	cmp $0, %rax
	jl cond_2
	jmp cond_3
cond_1:
	movq $1, %rax
	ret
cond_2:
	movq $-1, %rax
	ret
cond_3:
	movq $0, %rax
	ret
