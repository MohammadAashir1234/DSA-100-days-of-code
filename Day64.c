/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
// Define structure for a queue node
struct QueueNode {
    int val;
    struct QueueNode* next;
};
// Define structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};
// Create a new queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
// Enqueue an element
void enqueue(struct Queue* q, int val) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->val = val;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
// Dequeue an element
int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1; // Queue is empty
    struct QueueNode* temp = q->front;
    int val = temp->val;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL; // Queue is now empty
    free(temp);
    return val;
}
// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}
// Perform BFS
void bfs(int n, int adj[n][n], int s) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    struct Queue* q = createQueue();
    visited[s] = 1;
    enqueue(q, s);
    while (!isEmpty(q)) {
        int curr = dequeue(q);
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}
int main() {
    int n, s;
    scanf("%d", &n);
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);
    bfs(n, adj, s);
    return 0;
}
