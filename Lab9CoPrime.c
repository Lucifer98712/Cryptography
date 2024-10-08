#include <stdio.h>

// Function to find the GCD using Euclidean algorithm
int gcdEuclidean(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if two numbers are co-prime
int areCoprime(int num1, int num2) {
    return gcdEuclidean(num1, num2) == 1;
}

int main() {
    int num1, num2;

    // Input two positive integers
    printf("Enter the first positive integer: ");
    scanf("%d", &num1);

    printf("Enter the second positive integer: ");
    scanf("%d", &num2);

    // Check if the input is positive
    if (num1 <= 0 || num2 <= 0) {
        printf("Both numbers should be positive integers.\n");
        return 1; // Exit with an error code
    }

    // Check if the numbers are co-prime and display the result
    if (areCoprime(num1, num2)) {
        printf("%d and %d are co-prime numbers.\n", num1, num2);
    } else {
        printf("%d and %d are not co-prime numbers.\n", num1, num2);
    }

    return 0;
}
