#include <stdio.h>
#include <string.h>

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int detInverse(int det) {
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1)
            return i;
    }
    return -1;
}

void hillEncrypt(char* text, int key[2][2], char* result) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int a = text[i] - 'A';
        int b = text[i+1] - 'A';

        result[i] = mod26(a * key[0][0] + b * key[0][1]) + 'A';
        result[i+1] = mod26(a * key[1][0] + b * key[1][1]) + 'A';
    }
    result[len] = '\0';
}

void hillDecrypt(char* text, int key[2][2], char* result) {
    int det = mod26(key[0][0] * key[1][1] - key[0][1] * key[1][0]);
    int invDet = detInverse(det);
    if (invDet == -1) {
        printf("Inverse doesn't exist!\n");
        return;
    }

    int invKey[2][2] = {
        { mod26(key[1][1] * invDet), mod26(-key[0][1] * invDet) },
        { mod26(-key[1][0] * invDet), mod26(key[0][0] * invDet) }
    };

    hillEncrypt(text, invKey, result);
}

int main() {
    char msg[] = "HE";
    int key[2][2] = { {3, 3}, {2, 5} };
    char encrypted[10], decrypted[10];

    hillEncrypt(msg, key, encrypted);
    printf("Encrypted: %s\n", encrypted);

    hillDecrypt(encrypted, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
