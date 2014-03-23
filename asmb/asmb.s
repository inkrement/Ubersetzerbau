# http://de.wikibooks.org/wiki/Assembler-Programmierung_f%C3%BCr_x86-Prozessoren/_Befehlsreferenz
# http://cs.stanford.edu/people/eschkufz/x64/x64.html

        .text
        .globl _asmb
#        .type asmb, @function

_asmb:

	# STEP 1
	movdqu (%rdi), %xmm1 #first
	movdqu (%rsi), %xmm2 #second
	movdqu (%rdx), %xmm4 #result (original)

	movdqa %xmm1, %xmm3

	# STEP 2
	pminub %xmm2, %xmm3

	# STEP 3
	pxor %xmm0, %xmm0		# set xmm0 zeromask
	PCMPEQB %xmm3, %xmm0	# compare with 0 and store in xmm0
	pslldq $0x01, %xmm0		# shift mask


	# STEP 4
	pblendvb %xmm4, %xmm3

	movdqu %xmm3, (%rdx)

	ret
