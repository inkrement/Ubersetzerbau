	.section	__TEXT,__text,regular,pure_instructions
	.globl	_asma
	.align	4, 0x90
_asma:                                  ## @asma
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp

Ltmp4:
	.cfi_def_cfa_register %rbp			## set new CFA

## 16 byte alignment. with nop (no operation) as padding
#
# http://stackoverflow.com/questions/14544617/what-does-the-align-directive-do
# http://stackoverflow.com/questions/18413107/align-directive-proper-usage-with-align5-and-0x90
##
	.align	4, 0x90						

## copy rsi to xmm0
movdqa %rsi, %xmm0

## copy rdi to xmm1
movdqa %rdi, %xmm1

## compare bytewise
pminub %xmm0, %xmm1

## first operand xmm0 is result of smallest values (return it)
movdqa %xmm0, %rdx

LBB0_3:
	popq	%rbp
	ret
	.cfi_endproc


.subsections_via_symbols
