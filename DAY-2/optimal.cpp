#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from i to j
float sum(float p[], int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += p[k];
    return s;
}

// Function to calculate the optimal cost of a binary search tree
float optimalBST(float p[], float q[], int n) {
    float cost[n+1][n+1];  // cost[i][j] will store the cost of subtree from i to j
    float weight[n+1][n+1]; // weight[i][j] will store the total weight of subtree from i to j

    // Initialize cost and weight matrices
    for (int i = 0; i <= n; i++) {
        cost[i][i] = q[i]; // cost of an empty tree (dummy node)
        weight[i][i] = q[i]; 
    }

    // Fill the matrices in a bottom-up manner
    for (int length = 1; length <= n; length++) { // length is the number of nodes in the subtree
        for (int i = 0; i <= n - length; i++) {
            int j = i + length; // subtree ranges from i to j

            // Initialize cost to a large value
            cost[i][j] = INT_MAX;
            weight[i][j] = weight[i][j-1] + p[j] + q[j]; // Compute the weight for this range

            // Try making each key the root and find the minimum cost
            for (int r = i + 1; r <= j; r++) {
                float c = cost[i][r-1] + cost[r][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }

            // Add the weight to the optimal cost
            cost[i][j] += weight[i][j];
        }
    }

    return cost[0][n]; // The minimum cost for the full tree is stored in cost[0][n]
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    float p[n+1], q[n+1];
    printf("Enter the probabilities of the keys (p[i]):\n");
    for (int i = 1; i <= n; i++) {
        printf("p[%d]: ", i);
        scanf("%f", &p[i]);
    }

    printf("Enter the probabilities of the dummy keys (q[i]):\n");
    for (int i = 0; i <= n; i++) {
        printf("q[%d]: ", i);
        scanf("%f", &q[i]);
    }

    float result = optimalBST(p, q, n);
    printf("The minimum cost of the Optimal Binary Search Tree is: %.2f\n", result);

    return 0;
}

