#include <stdio.h>

int main() {
    int rows;

    // Input the number of rows for the pyramid
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop for each row
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces to center the numbers
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

