#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    
    // Extract digits and construct the reversed number
    while (num != 0) {
        int digit = num % 10;    // Get the last digit
        reversed = reversed * 10 + digit; // Append the digit to reversed number
        num /= 10;               // Remove the last digit from the original number
    }
    
    return reversed;
}

int main() {
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Call the function and display the result
    printf("Reversed number: %d\n", reverseNumber(number));

    return 0;
}

