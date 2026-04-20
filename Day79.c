/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
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

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;

    // Dijkstra’s algorithm (simple array version)
    for (int count = 1; count <= n; count++) {
        int u = -1;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
