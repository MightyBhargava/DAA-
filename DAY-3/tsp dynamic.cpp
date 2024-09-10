#include <stdio.h>

#define INF 9999999

int tsp(int graph[][4], int pos, int visited, int n, int dp[][16]) {
    if (visited == ((1 << n) - 1))
        return graph[pos][0];
    
    if (dp[pos][visited] != -1)
        return dp[pos][visited];
    
    int ans = INF;
    
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, city, visited | (1 << city), n, dp);
            ans = (ans < newAns) ? ans : newAns;
        }
    }
    
    return dp[pos][visited] = ans;
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int dp[4][16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < (1 << 4); j++) {
            dp[i][j] = -1;
        }
    }
    
    printf("Minimum cost of Travelling Salesman is %d\n", tsp(graph, 0, 1, 4, dp));
    
    return 0;
}

