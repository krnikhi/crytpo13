#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(char* str, char* key) {
    int x, len = strlen(str), keyLen = strlen(key);
    for (x = 0; x < len - keyLen; x++) {
        key[keyLen + x] = key[x % keyLen];
    }
    key[len] = '\0';
}

void vigenereEncrypt(char* str, char* key) {
    for (int i = 0; str[i]; i++) {
        str[i] = ((str[i] + key[i]) % 26) + 'A';
    }
}

void vigenereDecrypt(char* str, char* key) {
    for (int i = 0; str[i]; i++) {
        str[i] = (((str[i] - key[i]) + 26) % 26) + 'A';
    }
}

int main() {
    char str[] = "VIGENERECIPHER";
    char key[] = "KEY";
    char fullKey[100];
    strcpy(fullKey, key);

    generateKey(str, fullKey);
    vigenereEncrypt(str, fullKey);
    printf("Encrypted: %s\n", str);

    vigenereDecrypt(str, fullKey);
    printf("Decrypted: %s\n", str);
    return 0;
}
