#include <stdio.h>
#include <string.h>

void autoKeyEncrypt(char* text, char* key) {
    int len = strlen(text);
    for (int i = strlen(key); i < len; i++) {
        key[i] = text[i - strlen(key)];
    }
    key[len] = '\0';

    for (int i = 0; i < len; i++) {
        text[i] = ((text[i] + key[i]) % 26) + 'A';
    }
}

void autoKeyDecrypt(char* text, char* key) {
    int len = strlen(text);
    char currentKey[100];
    strcpy(currentKey, key);

    for (int i = 0; i < len; i++) {
        char p = ((text[i] - currentKey[i] + 26) % 26) + 'A';
        currentKey[strlen(currentKey)] = p;
        text[i] = p;
    }
    text[len] = '\0';
}

int main() {
    char msg[] = "AUTOKEYCIPHER";
    char key[100] = "KEY";

    autoKeyEncrypt(msg, key);
    printf("Encrypted: %s\n", msg);

    strcpy(key, "KEY");
    autoKeyDecrypt(msg, key);
    printf("Decrypted: %s\n", msg);
    return 0;
}
