#include <stdio.h>

int x[100];
int n;

void subsetSum(int s[], int sum, int start, int curr_sum) {
    if (curr_sum == sum) {
        printf("{ ");
        for (int i = 0; i < n; i++)
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("}\n");
        return;
    }
    
    if (start >= n || curr_sum > sum)
        return;

    x[start] = 1;
    subsetSum(s, sum, start + 1, curr_sum + s[start]);
    
    x[start] = 0;
    subsetSum(s, sum, start + 1, curr_sum);
}

int main() {
    int s[] = {10, 7, 5, 18, 12, 20, 15};
    n = sizeof(s) / sizeof(s[0]);
    int sum = 35;

    printf("Subsets that sum to %d are:\n", sum);
    subsetSum(s, sum, 0, 0);

    return 0;
}

