/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
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
// Print adjacency list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct AdjNode* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printGraph(graph);
    return 0;
}

