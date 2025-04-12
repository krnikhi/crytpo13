#include <stdio.h>
#include <string.h>

void generateNGrams(char* text, int n) {
    int len = strlen(text);
    printf("%d-grams:\n", n);
    for (int i = 0; i <= len - n; i++) {
        for (int j = 0; j < n; j++) {
            putchar(text[i + j]);
        }
        printf("\n");
    }
}

int main() {
    char text[] = "NGRAMEXAMPLE";
    int n = 3;

    generateNGrams(text, n);
    return 0;
}
