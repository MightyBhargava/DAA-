#include <stdio.h>

// Function to compute binomial coefficient C(n, k)
int binomialCoeff(int n, int k) {
    int C[n+1][k+1];
    
    // Initialize all entries of table to 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            // Base cases: C(n, 0) = 1 and C(n, n) = 1
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j]; // Recursive relation
        }
    }
    
    return C[n][k];
}

int main() {
    int n, k;
    
    // Input n and k
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    // Compute and display the binomial coefficient
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    
    return 0;
}

