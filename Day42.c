/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Stack structure
struct Stack {
    int items[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push operation
void push(struct Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = value;
    }
}

// Pop operation
int pop(struct Stack* s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    }
    return -1; // Stack is empty
}

// Queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};
// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}
// Enqueue operation
void enqueue(struct Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++q->rear] = value;
    }
}
// Dequeue operation
int dequeue(struct Queue* q) {
    if (q->front <= q->rear) {
        return q->items[q->front++];
    }
    return -1; // Queue is empty
}
int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        enqueue(&q, value);
    }

    struct Stack s;
    initStack(&s);

    // Reverse the queue using stack
    while (q.front <= q.rear) {
        push(&s, dequeue(&q));
    }

    // Print the reversed queue
    while (s.top >= 0) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    return 0;
}

