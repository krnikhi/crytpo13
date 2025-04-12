#include <stdio.h>
#include <string.h>

void beaufortCipher(char* text, char* key) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        text[i] = ((key[i % strlen(key)] - text[i] + 26) % 26) + 'A';
    }
}

int main() {
    char msg[] = "BEAUFORTCIPHER";
    char key[] = "KEY";

    beaufortCipher(msg, key);
    printf("Encrypted: %s\n", msg);

    beaufortCipher(msg, key);
    printf("Decrypted: %s\n", msg);
    return 0;
}
