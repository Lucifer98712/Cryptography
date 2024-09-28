#include <stdio.h>
#include <stdbool.h>

// Function to calculate the nth term in the Lucas-Lehmer sequence
unsigned long long lucasLehmer(unsigned long long p) {
    if (p == 2) {
        return 4; // The second term in the sequence is always 4
    }

    unsigned long long s = 4;

    for (unsigned long long i = 3; i <= p; i++) {
        s = (s * s - 2) % ((1ULL << p) - 1);
    }

    return s;
}

// Function to check if a Mersenne number is prime using Lucas-Lehmer test
bool isMersennePrime(unsigned long long p) {
    return lucasLehmer(p) == 0;
}

int main() {
    unsigned long long exponent;

    // Input the exponent for the Mersenne number (2^exponent - 1)
    printf("Enter the exponent (p) for the Mersenne number (2^p - 1): ");
    scanf("%llu", &exponent);

    // Check if the exponent is greater than or equal to 2
    if (exponent < 2) {
        printf("Exponent must be greater than or equal to 2.\n");
        return 1; // Exit with an error code
    }

    // Check if the Mersenne number is prime using Lucas-Lehmer test
    if (isMersennePrime(exponent)) {
        printf("2^%llu - 1 is a Mersenne prime.\n", exponent);
    } else {
        printf("2^%llu - 1 is not a Mersenne prime.\n", exponent);
    }

    return 0;
}
