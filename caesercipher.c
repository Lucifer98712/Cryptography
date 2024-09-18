#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to encrypt text using Caesar cipher
void encrypt(char plaintext[], int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            // Check if the character is uppercase or lowercase
            char base = isupper(plaintext[i]) ? 'A' : 'a';

            // Apply the Caesar cipher encryption
            plaintext[i] = (plaintext[i] - base + key) % 26 + base;
        }
    }
}

// Function to decrypt text using Caesar cipher
void decrypt(char ciphertext[], int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            // Check if the character is uppercase or lowercase
            char base = isupper(ciphertext[i]) ? 'A' : 'a';

            // Apply the Caesar cipher decryption
            ciphertext[i] = (ciphertext[i] - base - key + 26) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int key;

    // Input the text to be encrypted
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    // Input the key
    printf("Enter the key (an integer): ");
    scanf("%d", &key);

    // Encrypt the text
    encrypt(text, key);
    printf("\nCipher text: %s", text);

    // Allow the user to change the key
    printf("\nEnter a new key to decrypt the cipher text: ");
    scanf("%d", &key);

    // Decrypt the cipher text
    decrypt(text, key);
    printf("\nDecrypted text: %s\n", text);

    return 0;
}
