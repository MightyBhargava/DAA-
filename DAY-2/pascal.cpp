#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate binomial coefficient (nCr)
int binomialCoefficient(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        // Print leading spaces for center alignment
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Print the numbers in the row
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }

        // Move to the next line after each row
        printf("\n");
    }
}

int main() {
    int rows;

    // Input the number of rows
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    // Print Pascal's Triangle
    printPascalsTriangle(rows);

    return 0;
}

