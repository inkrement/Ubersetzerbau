        .text
        .globl _asmb
#        .type asmb, @function

####
# rdi erstes argument
# rsi zweites argument
# rdx orinaler string
# rcx zählregister
#
# rbx pminub.. oder bl
####

# STEP 1 reset zählregister

xor %rax, %rax

_asmb:

loop:
	# STEP 2 copy param byte-wise

	movb (%rdi, %rax, 1), %r8b
	movb (%rdi, %rax, 1), %r9b
	movb (%rdx, %rax, 1), %r10b

	PINSRB $0x01, %r8d, %xmm1
	PINSRB $0x01, %r9d, %xmm2

	# Step 3: calculate and write to result
	pminub %xmm1, %xmm2

	PEXTRB $0x01 , %xmm2, (%rdi, %rax,1)

	# Step 3: increment
	incl %eax

	# Step 4 conditional loop

	cmp $0, %r10b
	jne loop


exit:
	ret
