#
# Result asma.c
#
# i = rax (eax)
# rsi = erste Argument (s)
# rdi = zweite Argument (t)
# rdx = zweites Rückgaberegister (u)
#
# cl enthält immer das neue u (entweder ts[i] oder s[i])
# 

	.section	__TEXT,__text,regular,pure_instructions
	.globl	_asma
	.align	4, 0x90
_asma:                                  ## @asma
	.cfi_startproc						## beginning of a function
## BB#0:
	pushq	%rbp						## save frame pointer
Ltmp2:
	.cfi_def_cfa_offset 16				## http://stackoverflow.com/questions/7534420/gas-explanation-of-cfi-def-cfa-offset
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp					## neuen Framepointer setzen
Ltmp4:
	.cfi_def_cfa_register %rbp			## set new CFA
	xorl	%eax, %eax					## eax = eax xor eax
	.align	4, 0x90						## http://stackoverflow.com/questions/14544617/what-does-the-align-directive-do
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1

## ModR/M-Adressierung Dsiplacement(Base, Index, Scale)
## (%rsi, %rax) = %rsi + %rax
	movb	(%rsi,%rax), %r8b			## move byte from (%rsi, %rax) to %r8b 
	movb	(%rdi,%rax), %cl 			## move from (%rdi,%rax) to %cmpl

## Vergleiche untere 8 Bit von rcx (cl) mit unteren 8 bit von r8 (r8b)
	cmpb	%r8b, %cl
## jump if above (CF=0 and ZF=0) ergebnis von cmpb 
## hatte keinen Übertrag und nicht null.
## http://stackoverflow.com/questions/9617877/assembly-jg-jnle-jl-jnge-after-cmp
	ja	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1

## u[i] = (s[i]>t[i]) ? s[i] : t[i];
	movb	%r8b, %cl 					## schiebe r8b -> cl
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
	movb	%cl, (%rdx,%rax)
	incq	%rax
	cmpl	$16, %eax
	jne	LBB0_1
## BB#4:
	popq	%(%rdi,%rax)
	ret
	.cfi_endproc


.subsections_via_symbols
