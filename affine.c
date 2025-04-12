#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

void affineEncrypt(char* text, int a, int b) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((a * (text[i] - base) + b) % 26) + base;
        }
    }
}

void affineDecrypt(char* text, int a, int b) {
    int a_inv = modInverse(a);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((a_inv * ((text[i] - base - b + 26)) % 26)) + base;
        }
    }
}

int main() {
    char msg[100] = "AFFINECIPHER";
    int a = 5, b = 8;

    affineEncrypt(msg, a, b);
    printf("Encrypted: %s\n", msg);

    affineDecrypt(msg, a, b);
    printf("Decrypted: %s\n", msg);
    return 0;
}
