#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Reversed number is %d\n", reverseNumber(num));
    return 0;
}

