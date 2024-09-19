#include <stdio.h>

// Function to perform modular addition
int modAdd(int a, int b, int modulus) {
    return (a + b) % modulus;
}

// Function to perform modular subtraction
int modSub(int a, int b, int modulus) {
    return (a - b + modulus) % modulus;
}

// Function to perform modular multiplication
int modMul(int a, int b, int modulus) {
    return (a * b) % modulus;
}

// Function to perform modular division
int modDiv(int a, int b, int modulus) {
    // Calculate the modular multiplicative inverse of b
    // (assuming modulus is a prime number for simplicity)
    int inverse = 1;
    while ((b * inverse) % modulus != 1) {
        inverse++;
    }

    // Use the inverse to perform division
    return modMul(a, inverse, modulus);
}

int main() {
    int a, b, modulus;

    // Input two integers and the modulus
    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);
    printf("Enter the modulus: ");
    scanf("%d", &modulus);

    // Perform modular arithmetic operations
    printf("\nModular Addition: %d + %d mod %d = %d\n", a, b, modulus, modAdd(a, b, modulus));
    printf("Modular Subtraction: %d - %d mod %d = %d\n", a, b, modulus, modSub(a, b, modulus));
    printf("Modular Multiplication: %d * %d mod %d = %d\n", a, b, modulus, modMul(a, b, modulus));
    
    if (b != 0) {
        printf("Modular Division: %d / %d mod %d = %d\n", a, b, modulus, modDiv(a, b, modulus));
    } else {
        printf("Modular Division is undefined (division by zero).\n");
    }

    return 0;
}
