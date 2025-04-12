#include <stdio.h>
#include <string.h>
#include <ctype.h>

void augustCipher(char* text, int shift) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

int main() {
    char msg[100] = "AUGUSTCIPHER";
    int shift = 5;
    augustCipher(msg, shift);
    printf("Encrypted: %s\n", msg);
    augustCipher(msg, 26 - shift);  // Decrypt
    printf("Decrypted: %s\n", msg);
    return 0;
}
