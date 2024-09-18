#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Function to create the Playfair matrix based on the keyword
void createPlayfairMatrix(char key[], char matrix[][SIZE]) {
    int i, j, k, flag = 0;
    char *keyUnique = (char *)malloc(strlen(key) * sizeof(char));

    // Remove duplicate letters from the keyword
    for (i = 0; i < strlen(key); i++) {
        if (strchr(keyUnique, key[i]) == NULL) {
            keyUnique[flag++] = key[i];
        }
    }
    keyUnique[flag] = '\0';

    // Fill the matrix with the keyword
    k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (k < strlen(keyUnique)) {
                matrix[i][j] = keyUnique[k++];
            } else {
                char ch;
                do {
                    ch = 'A' + rand() % 26;
                } while (strchr(keyUnique, ch) != NULL);
                matrix[i][j] = ch;
            }
        }
    }

    free(keyUnique);
}

// Function to find the positions of a letter in the Playfair matrix
void findPosition(char matrix[][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') {
        ch = 'I';
    }

    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to encrypt a digraph using Playfair cipher
void encryptDigraph(char matrix[][SIZE], char digraph[], char ciphertext[]) {
    int row1, col1, row2, col2;
    findPosition(matrix, digraph[0], &row1, &col1);
    findPosition(matrix, digraph[1], &row2, &col2);

    if (row1 == row2) {
        // Same row: Replace each letter with the letter to its right (circular)
        ciphertext[0] = matrix[row1][(col1 + 1) % SIZE];
        ciphertext[1] = matrix[row2][(col2 + 1) % SIZE];
    } else if (col1 == col2) {
        // Same column: Replace each letter with the letter below it (circular)
        ciphertext[0] = matrix[(row1 + 1) % SIZE][col1];
        ciphertext[1] = matrix[(row2 + 1) % SIZE][col2];
    } else {
        // Form a rectangle and replace with opposite corners
        ciphertext[0] = matrix[row1][col2];
        ciphertext[1] = matrix[row2][col1];
    }
}

// Function to apply Playfair cipher encryption to the plaintext
void playfairEncrypt(char plaintext[], char key[]) {
    char matrix[SIZE][SIZE];
    createPlayfairMatrix(key, matrix);

    // Prepare the plaintext
    int i, j, k = 0;
    int len = strlen(plaintext);
    char *preparedText = (char *)malloc((2 * len) * sizeof(char));

    for (i = 0; i < len; i++) {
        preparedText[k++] = plaintext[i];
        if (i < len - 1 && plaintext[i] == plaintext[i + 1]) {
            preparedText[k++] = 'X'; // Insert 'X' between repeated letters
        }
    }

    if (k % 2 == 1) {
        preparedText[k++] = 'X'; // Append 'X' if the number of letters is odd
    }

    preparedText[k] = '\0';

    // Encrypt the digraphs
    char *ciphertext = (char *)malloc(k * sizeof(char));
    for (i = 0; i < k; i += 2) {
        encryptDigraph(matrix, &preparedText[i], &ciphertext[i]);
    }
    ciphertext[k] = '\0';

    // Display the Playfair ciphertext
    printf("Playfair Ciphertext: %s\n", ciphertext);

    free(preparedText);
    free(ciphertext);
}

int main() {
    char plaintext[100], key[] = "MONARCHY";

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Encrypt using Playfair cipher
    playfairEncrypt(plaintext, key);

    return 0;
}
