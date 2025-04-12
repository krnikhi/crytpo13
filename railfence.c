#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char* text, int rails, char* result) {
    int len = strlen(text);
    int idx = 0;

    for (int r = 0; r < rails; r++) {
        for (int i = r; i < len; i += rails) {
            result[idx++] = text[i];
        }
    }
    result[idx] = '\0';
}

void railFenceDecrypt(char* text, int rails, char* result) {
    int len = strlen(text);
    int idx = 0;

    for (int r = 0; r < rails; r++) {
        for (int i = r; i < len; i += rails) {
            result[i] = text[idx++];
        }
    }
    result[len] = '\0';
}

int main() {
    char msg[] = "RAILFENCECIPHER";
    char encrypted[100], decrypted[100];

    railFenceEncrypt(msg, 3, encrypted);
    printf("Encrypted: %s\n", encrypted);

    railFenceDecrypt(encrypted, 3, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
