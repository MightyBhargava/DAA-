#include <stdio.h>

int even_fibonacci_sum(int n) {
    int a = 0, b = 1;  
    int sum_even = 0;
    
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            sum_even += a;
        }
        int next = a + b;
        a = b;
        b = next;
    }

    return sum_even;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int result = even_fibonacci_sum(n);
    printf("Sum of Fibonacci numbers at even indexes up to %dth term: %d\n", n, result);

    return 0;
}

