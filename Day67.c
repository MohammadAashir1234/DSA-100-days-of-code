/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>
// Define structure for a stack node
struct StackNode {
    int val;
    struct StackNode* next;
};
// Define structure for a stack
struct Stack {
    struct StackNode* top;
};
// Create a new stack
struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}
// Push an element onto the stack
void push(struct Stack* s, int val) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->val = val;
    temp->next = s->top;
    s->top = temp;
}
// Pop an element from the stack
int pop(struct Stack* s) {
    if (s->top == NULL) return -1; // Stack is empty
    struct StackNode* temp = s->top;
    int val = temp->val;
    s->top = s->top->next;
    free(temp);
    return val;
}
// Check if stack is empty
int isStackEmpty(struct Stack* s) {
    return s->top == NULL;
}
// Perform DFS for topological sort
void dfs(int v, int n, int adj[n][n], int visited[n], struct Stack* s) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) { // If there is an edge and not visited
            dfs(i, n, adj, visited, s);
        }
    }
    push(s, v); // Push vertex to stack after visiting all neighbors
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0; // Initialize adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Add edge to adjacency matrix
    }
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    struct Stack* s = createStack();
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj, visited, s);
        }
    }
    // Print topological order
    while (!isStackEmpty(s)) {
        printf("%d ", pop(s));
    }
    return 0;
}
