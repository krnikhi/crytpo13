#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char* text, int shift) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void caesarDecrypt(char* text, int shift) {
    caesarEncrypt(text, 26 - shift);
}

int main() {
    char msg[100] = "HELLOCAESAR";
    int shift = 3;

    caesarEncrypt(msg, shift);
    printf("Encrypted: %s\n", msg);

    caesarDecrypt(msg, shift);
    printf("Decrypted: %s\n", msg);
    return 0;
}
