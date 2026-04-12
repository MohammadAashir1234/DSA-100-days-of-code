/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
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
// Perform Kahn's Algorithm for topological sort
void kahn(int n, int adj[n][n]) {
    int inDegree[n];
    for (int i = 0; i < n; i++) inDegree[i] = 0;
    // Calculate in-degrees
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j]) inDegree[j]++;
    struct Queue* q = createQueue();
    // Enqueue vertices with in-degree 0
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0) enqueue(q, i);
    while (!isEmpty(q)) {
        int curr = dequeue(q);
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0) enqueue(q, i);
            }
        }
    }
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
    kahn(n, adj);
    return 0;
}
