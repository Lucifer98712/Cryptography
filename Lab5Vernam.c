#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key for Vernam cipher
void generateRandomKey(int length, char key[]) {
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % 26;
    }
    key[length] = '\0';
}

// Function to encrypt text using Vernam cipher
void vernamEncrypt(char plaintext[], char key[], char ciphertext[]) {
    int textLen = strlen(plaintext);

    for (int i = 0; i < textLen; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char base = isupper(currentChar) ? 'A' : 'a';
            char shift = key[i];

            ciphertext[i] = ((currentChar - base + shift - 'A') % 26) + base;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = currentChar;
        }
    }
    ciphertext[textLen] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Generate a random key for Vernam cipher
    generateRandomKey(len, key);

    // Encrypt using Vernam cipher
    vernamEncrypt(plaintext, key, ciphertext);

    // Display the Vernam ciphertext and the key
    printf("Vernam Key: %s\n", key);
    printf("Vernam Ciphertext: %s\n", ciphertext);

    return 0;
}
