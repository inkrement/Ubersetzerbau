# http://de.wikibooks.org/wiki/Assembler-Programmierung_f%C3%BCr_x86-Prozessoren/_Befehlsreferenz
# http://cs.stanford.edu/people/eschkufz/x64/x64.html

        .text
        .globl asma
        .type asma, @function

asma:
	movdqu (%rsi), %xmm8
	movdqu (%rdi), %xmm9

	xor %eax, %eax #auf null setzen

copy:

	pextrb $1, %xmm8, %eax

	#cmp $0 %AH,  # xmm1 byte an stelle %ecx
	# end

	## 6. copy byte

	inc %AH
	jmp copy

	#end:



	pminub %xmm9, %xmm8
	movdqu %xmm8, (%rdx)
	ret
