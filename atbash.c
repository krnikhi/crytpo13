#include <stdio.h>
#include <string.h>
#include <ctype.h>

void atbashCipher(char* text) {
    for (int i = 0; text[i]; i++) {
        if (isupper(text[i])) {
            text[i] = 'Z' - (text[i] - 'A');
        } else if (islower(text[i])) {
            text[i] = 'z' - (text[i] - 'a');
        }
    }
}

int main() {
    char msg[100] = "ATBASHCIPHER";
    atbashCipher(msg);
    printf("Encrypted: %s\n", msg);
    atbashCipher(msg);  // Reversing again
    printf("Decrypted: %s\n", msg);
    return 0;
}
