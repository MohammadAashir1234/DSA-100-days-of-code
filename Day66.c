/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
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
// Perform DFS to detect cycle
int dfs(int v, int n, int adj[n][n], int visited[n], int recStack[n]) {
    visited[v] = 1;
    recStack[v] = 1; // Add to recursion stack
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) { // If there is an edge
            if (!visited[i]) {
                if (dfs(i, n, adj, visited, recStack)) return 1; // Cycle found
            } else if (recStack[i]) {
                return 1; // Cycle found
            }
        }
    }
    recStack[v] = 0; // Remove from recursion stack
    return 0; // No cycle found
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
        adj[u][v] = 1; // Directed edge from u to v
    }
    int visited[n], recStack[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
