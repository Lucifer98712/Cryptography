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

    // Find and display the GCD using Euclidean algorithm
    int gcd = gcdEuclidean(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
