#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gronsfeldCipher(char* text, int key[], int keyLen, int encrypt) {
    for (int i = 0; text[i]; i++) {
        int shift = key[i % keyLen];
        if (!encrypt) shift = 26 - shift;
        text[i] = ((text[i] - 'A' + shift) % 26) + 'A';
    }
}

int main() {
    char msg[] = "GRONSFELDCIPHER";
    int key[] = {3, 1, 4, 1, 5};
    int keyLen = 5;

    gronsfeldCipher(msg, key, keyLen, 1);
    printf("Encrypted: %s\n", msg);

    gronsfeldCipher(msg, key, keyLen, 0);
    printf("Decrypted: %s\n", msg);
    return 0;
}
