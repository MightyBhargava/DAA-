#include <stdio.h>
#define INF 99999999 // A large value representing infinity
#define N 4          // Number of cities

int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

// Memoization table to store subproblem results
int dp[1 << N][N];  // 2^N subsets, N possible cities

// Function to implement TSP using Dynamic Programming
int tsp(int mask, int pos) {
    // If all cities have been visited, return distance to starting city
    if (mask == (1 << N) - 1) {
        return dist[pos][0];  // Return to the starting city
    }

    // If this subproblem has already been solved, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try visiting all other cities and find the optimal solution
    for (int city = 0; city < N; city++) {
        // Check if the city has not been visited
        if ((mask & (1 << city)) == 0) {
            // Recursively calculate the minimum distance
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = (newAns < ans) ? newAns : ans;
        }
    }

    // Store the result in the dp table
    return dp[mask][pos] = ans;
}

int main() {
    // Initialize memoization table with -1 (unvisited states)
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    // Start TSP from city 0 with the mask representing only city 0 visited
    int result = tsp(1, 0);

    // Print the minimum travel cost
    printf("The minimum cost of travelling all cities is: %d\n", result);

    return 0;
}

