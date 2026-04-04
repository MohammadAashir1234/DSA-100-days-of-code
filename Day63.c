/*Problem: Perform DFS starting from a given source vertex using recursion.
Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
// Define structure for adjacency list node
struct AdjNode {
    int dest;
    struct AdjNode* next;
};
// Define structure for graph
struct Graph {
    int V;
    struct AdjNode** adjList;
};
// Create new adjacency list node
struct AdjNode* newAdjNode(int dest) {
    struct AdjNode* node = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    node->dest = dest;
    node->next = NULL;
    return node;
}
// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct AdjNode**)malloc(V * sizeof(struct AdjNode*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct AdjNode* node = newAdjNode(dest);
    node->next = graph->adjList[src];
    graph->adjList[src] = node;
    // For undirected graph, add edge from dest to src
    // node = newAdjNode(src);
    // node->next = graph->adjList[dest];
    // graph->adjList[dest] = node;
}
// DFS function
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct AdjNode* temp = graph->adjList[vertex];
    while (temp) {
        if (!visited[temp->dest]) {
            DFS(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    scanf("%d", &s);
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(graph, s, visited);
    return 0;
}
