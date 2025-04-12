#include <stdio.h>
#include <string.h>

void sortKey(char* key, int order[]) {
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        order[i] = 1;
        for (int j = 0; j < len; j++) {
            if (key[j] < key[i] || (key[j] == key[i] && j < i)) {
                order[i]++;
            }
        }
    }
}

void myszkowskiEncrypt(char* text, char* key, char* result) {
    int len = strlen(key), textLen = strlen(text);
    int rows = (textLen + len - 1) / len;
    char grid[rows][len];
    int idx = 0;

    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < len; j++) 
            grid[i][j] = (idx < textLen) ? text[idx++] : 'X';

    int order[20];
    sortKey(key, order);
    idx = 0;

    for (int k = 1; k <= len; k++) {
        for (int j = 0; j < len; j++) {
            if (order[j] == k) {
                for (int i = 0; i < rows; i++) {
                    result[idx++] = grid[i][j];
                }
            }
        }
    }
    result[idx] = '\0';
}

int main() {
    char msg[] = "MYSZKOWSKICIPHER";
    char key[] = "BANANA";
    char encrypted[100];

    myszkowskiEncrypt(msg, key, encrypted);
    printf("Encrypted: %s\n", encrypted);

    return 0;
}
