/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Create empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation
void enqueue(Queue* q, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // maintain circular link
    }
}

// Dequeue operation
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue empty\n");
        exit(1);
    }

    int val;
    if (q->front == q->rear) {
        val = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        Node* temp = q->front;
        val = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front; // maintain circular link
        free(temp);
    }
    return val;
}

// Display queue elements
void displayQueue(Queue* q) {
    if (q->front == NULL) {
        return;
    }
    Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    Queue* q = createQueue();

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    displayQueue(q);

    return 0;
}