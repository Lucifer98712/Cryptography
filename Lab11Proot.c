#include <stdio.h>
#include <stdbool.h>

// Function to calculate the Euler Totient Function for a given number
int eulerTotient(int n) {
    int result = n; // Initialize result as n

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            // i is a prime factor of n
            while (n % i == 0) {
                n /= i;
            }
            // Reduce result using the formula (result * (1 - 1/p))
            result -= result / i;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    if (n > 1) {
        result -= result / n;
    }

    return result;
}

// Function to check if an integer is a primitive root modulo m
bool isPrimitiveRoot(int g, int m) {
    if (g <= 0 || m <= 0) {
        return false; // g and m should be positive integers
    }

    int totient = eulerTotient(m);

    // Check if g and m are coprime
    if (eulerTotient(g) != totient) {
        return false;
    }

    // Check if powers of g generate all numbers from 1 to m-1
    for (int i = 1; i < m; i++) {
        int power = 1;
        for (int j = 0; j < totient; j++) {
            power = (power * g) % m;
            if (power == i) {
                break;
            }
        }
        if (power != i) {
            return false; // g is not a primitive root
        }
    }

    return true; // g is a primitive root modulo m
}

int main() {
    int g, m;

    // Input two positive integers
    printf("Enter the potential primitive root (g): ");
    scanf("%d", &g);

    printf("Enter the modulus (m): ");
    scanf("%d", &m);

    // Check if the potential primitive root is indeed a primitive root
    if (isPrimitiveRoot(g, m)) {
        printf("%d is a primitive root modulo %d.\n", g, m);
    } else {
        printf("%d is not a primitive root modulo %d.\n", g, m);
    }

    return 0;
}
