#include <stdio.h>

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

int main() {
    int n;

    // Input a positive integer
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Check if the input is positive
    if (n <= 0) {
        printf("The input should be a positive integer.\n");
        return 1; // Exit with an error code
    }

    // Calculate and display Euler Totient Function
    int result = eulerTotient(n);
    printf("Euler Totient Function for %d is: %d\n", n, result);

    return 0;
}
