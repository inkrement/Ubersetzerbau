	.text
	.globl asmb
	.type asmb, @function

####
# rdi erstes argument
# rsi zweites argument
# rdx orinaler string
# rcx zählregister
#
# rbx pminub.. oder bl
####

# STEP 1 reset zählregister

xor %rbx, %rbx

asmb:

loop:

	movb (%rdi, %rbx), %r8b
	movb (%rsi, %rbx), %r9b
	
	cmp $0, %r8b
	je exit
	cmp $0, %r9b
	je exit

	# STEP 2 copy param byte-wise


	# 1 byte insertn und extrahieren
	PINSRB $0x00, %r8d, %xmm1
	PINSRB $0x00, %r9d, %xmm2

	# Step 3: calculate and write to result
	pminub %xmm1, %xmm2

	PEXTRB $0x00 , %xmm2, (%rdx, %rbx)

	# Step 3: increment
	inc %rbx

	jmp loop

	# Step 4 conditional loop

exit:
	movb $0, %r8b
	PINSRB $0x00, %r8d, %xmm1
	PEXTRB $0x00 , %xmm1, (%rdx, %rbx)
	ret
