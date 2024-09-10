#include <stdio.h>

void loadContainers(int weights[], int n, int capacity) {
    int totalWeight = 0;
    printf("Containers loaded with weights: ");
    for (int i = 0; i < n; i++) {
        if (totalWeight + weights[i] <= capacity) {
            totalWeight += weights[i];
            printf("%d ", weights[i]);
        }
    }
    printf("\nTotal weight loaded: %d\n", totalWeight);
}

int main() {
    int weights[] = {2, 5, 4, 7, 1, 3, 8};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 10;

    loadContainers(weights, n, capacity);
    return 0;
}

