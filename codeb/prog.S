	.text

	.globl mysgn
	.type mysgn, @function
mysgn:
	movq %rdi, %rax
	# calculate greater one between %rdi and 0 to %rax (reg & imm)
	movq $0, %rax
	movq $-1, %r10
	cmpq $0, %rdi
	cmovleq %r10, %rax
	movq %rdi, %r11
	# calculate greater one between %rdi and 0 to %r11 (reg & imm)
	movq $0, %r11
	movq $-1, %r9
	cmpq $0, %rdi
	cmovleq %r9, %r11
	cmp $-1, %r11
	jz cond_1
	cmp $-1, %rax
	jz cond_2
	jmp cond_3
cond_1:
	movq $1, %rax
	ret
	jmp cond_3
cond_2:
	movq $-1, %rax
	ret
	jmp cond_3
cond_3:
	movq $0, %rax
	ret
