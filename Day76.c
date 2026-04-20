/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // undirected
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}
