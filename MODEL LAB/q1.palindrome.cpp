#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {

        if (!isalnum(str[start])) {
            start++;
        } else if (!isalnum(str[end])) {
            end--;
        } else if (tolower(str[start]) != tolower(str[end])) {
            return 0;  
        } else {
            start++;
            end--;
        }
    }
    return 1;  
}

int main() {
    char input[100];
    printf("Enter a string or number: ");
    scanf("%s", input);  

    if (is_palindrome(input)) {
        printf("%s is a Palindrome\n", input);
    } else {
        printf("%s is NOT a Palindrome\n", input);
    }

    return 0;
}

