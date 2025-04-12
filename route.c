#include <stdio.h>
#include <string.h>

#define SIZE 4

void fillMatrix(char* text, char matrix[SIZE][SIZE]) {
    int len = strlen(text), idx = 0;
    for (int i = 0; i < SIZE && idx < len; i++) {
        for (int j = 0; j < SIZE && idx < len; j++) {
            matrix[i][j] = text[idx++];
        }
    }
}

void routeEncrypt(char* text, char* result) {
    char matrix[SIZE][SIZE];
    fillMatrix(text, matrix);
    int idx = 0;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            result[idx++] = matrix[i][j];
        }
    }
    result[idx] = '\0';
}

void routeDecrypt(char* text, char* result) {
    char matrix[SIZE][SIZE];
    int idx = 0;

    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            matrix[i][j] = text[idx++];
        }
    }

    idx = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[idx++] = matrix[i][j];
        }
    }
    result[idx] = '\0';
}

int main() {
    char msg[] = "ROUTECIPHERTEST";
    char encrypted[100], decrypted[100];

    routeEncrypt(msg, encrypted);
    printf("Encrypted: %s\n", encrypted);

    routeDecrypt(encrypted, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
