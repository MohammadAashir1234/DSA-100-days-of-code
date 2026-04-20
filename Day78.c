/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INT_MAX;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int key[MAX], mstSet[MAX];
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; // start from vertex 1
    int totalWeight = 0;

    // Prim’s algorithm
    for (int count = 1; count <= n; count++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}
