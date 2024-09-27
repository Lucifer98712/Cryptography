#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt text using Vigenère cipher
void vigenereEncrypt(char plaintext[], char keyword[], char ciphertext[]) {
    int keyLen = strlen(keyword);
    int textLen = strlen(plaintext);

    for (int i = 0, j = 0; i < textLen; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = isupper(currentChar) ? 'A' : 'a';
            char shift = keyword[j % keyLen];
            j++;

            ciphertext[i] = ((currentChar - base + shift - 'A') % 26) + base;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = currentChar;
        }
    }
    ciphertext[textLen] = '\0';
}

int main() {
    char plaintext[100], keyword[100], ciphertext[100];

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Input the keyword
    printf("Enter the keyword: ");
    fgets(keyword, sizeof(keyword), stdin);

    // Remove newline character from the input
    len = strlen(keyword);
    if (len > 0 && keyword[len - 1] == '\n') {
        keyword[len - 1] = '\0';
    }

    // Encrypt using Vigenère cipher
    vigenereEncrypt(plaintext, keyword, ciphertext);

    // Display the Vigenère ciphertext
    printf("Vigenere Ciphertext: %s\n", ciphertext);

    return 0;
}
