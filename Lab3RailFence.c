#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt text using Rail Fence cipher
void railFenceEncrypt(char plaintext[], int rails, char ciphertext[]) {
    int len = strlen(plaintext);
    char fence[rails][len];
    
    // Initialize fence matrix with spaces
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            fence[i][j] = ' ';
        }
    }

    // Fill in the fence matrix with the plaintext
    int row = 0, dir = 1;  // direction: 1 for down, -1 for up
    for (int i = 0; i < len; i++) {
        fence[row][i] = plaintext[i];
        row += dir;
        if (row == 0 || row == rails - 1) {
            dir = -dir;  // change direction when reaching the top or bottom rail
        }
    }

    // Read off the ciphertext from the fence
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (fence[i][j] != ' ') {
                ciphertext[k++] = fence[i][j];
            }
        }
    }
    ciphertext[k] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    int rails;

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input the number of rails
    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    // Remove newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Encrypt using Rail Fence cipher
    railFenceEncrypt(plaintext, rails, ciphertext);

    // Display the Rail Fence ciphertext
    printf("Rail Fence Ciphertext: %s\n", ciphertext);

    return 0;
}
