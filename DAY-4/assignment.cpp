#include <stdio.h>
#include <limits.h>

#define N 4

int minValue(int a, int b) {
    return (a < b) ? a : b;
}

int findMinCost(int cost[N][N], int n, int row[], int col[], int l, int totalCost) {
    if (l == n) {
        return totalCost;
    }

    int minCost = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!row[l] && !col[i]) {
            row[l] = 1;
            col[i] = 1;
            int currCost = findMinCost(cost, n, row, col, l + 1, totalCost + cost[l][i]);
            minCost = minValue(minCost, currCost);
            row[l] = 0;
            col[i] = 0;
        }
    }

    return minCost;
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
    int row[N] = {0};
    int col[N] = {0};

    int minCost = findMinCost(cost, N, row, col, 0, 0);
    printf("Minimum assignment cost: %d\n", minCost);
    
    return 0;
}

