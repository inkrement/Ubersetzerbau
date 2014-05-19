	.file	"test.c"
	.text
	.globl	same
	.type	same, @function
same:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	same, .-same
	.section	.rodata
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$2, %edi
	call	funf
	movq	%rax, %rdx
	movl	$.LC0, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$2, %edi
	call	same
	movq	%rax, %rdx
	movl	$.LC0, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.4-1ubuntu1~12.04) 4.6.4"
	.section	.note.GNU-stack,"",@progbits
