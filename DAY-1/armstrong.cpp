#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum = num, remainder, result = 0, n = 0;
    
    // Find the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }
    
    originalNum = num;
    
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    
    return (result == num);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    
    return 0;
}

