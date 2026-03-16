/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#include <stdlib.h>

// Queue structure
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* data;   
    int front;
    int back;    
    int size;    
} Queue;

// Make a queue
Queue* makeQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        printf("No memory\n");
        exit(1);
    }
    q->size = size;
    q->front = 0;
    q->back = -1;
    q->data = (int*)malloc(q->size * sizeof(int));
    if (!q->data) {
        printf("No memory\n");
        exit(1);
    }
    return q;
}

// Add to queue
void add(Queue* q, int value) {
    if (q->back == q->size - 1) {
        printf("Queue full\n");
        return;
    }
    q->back++;
    q->data[q->back] = value;
}

// Remove from queue
int removeItem(Queue* q) {
    if (q->front > q->back) {
        printf("Queue empty\n");
        exit(1);
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

// Show queue
void show(Queue* q) {
    for (int i = q->front; i <= q->back; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter count: ");
    scanf("%d", &n);

    Queue* q = makeQueue(n);
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        add(q, value);
    }

    printf("Queue: ");
    show(q);

    // Free memory
    free(q->data);
    free(q);

    return 0;
}
