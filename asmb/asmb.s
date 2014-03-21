# http://de.wikibooks.org/wiki/Assembler-Programmierung_f%C3%BCr_x86-Prozessoren/_Befehlsreferenz
# http://cs.stanford.edu/people/eschkufz/x64/x64.html

        .text
        .globl asma
        .type asma, @function

asma:
	movdqu (%rsi), %xmm8
	movdqu (%rdi), %xmm9

	xor %ecx, %ecx #auf null setzen

	copy:

		pextrb imm8, xmm, m8

		cmp $0,  # xmm1 byte an stelle %ecx
		jmp end

		## 6. copy byte
		mov ()()

		inc %ecx
		jmp copy

	end:



	pminub %xmm9, %xmm8

	movdqu %xmm8, (%rdx)

	ret
