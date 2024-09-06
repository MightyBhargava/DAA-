#include <stdio.h>

// Function to calculate the sum of digits
int sumOfDigits(int num) {
    int sum = 0;
    
    // Handle negative numbers
    num = num < 0 ? -num : num;

    // Sum the digits
    while (num > 0) {
        sum += num % 10;  // Add the last digit to sum
        num /= 10;        // Remove the last digit
    }

    return sum;
}

int main() {
    int num;

    // Input the number
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Calculate and print the sum of digits
    printf("Sum of digits: %d\n", sumOfDigits(num));

    return 0;
}

