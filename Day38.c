/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
    int count;
} Deque;

// Create deque
Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(capacity * sizeof(int));
    dq->capacity = capacity;
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
    return dq;
}

// Check if empty
bool empty(Deque* dq) {
    return dq->count == 0;
}

// Size
int size(Deque* dq) {
    return dq->count;
}

// Push front
void push_front(Deque* dq, int val) {
    if (dq->count == dq->capacity) {
        printf("Deque full\n");
        return;
    }
    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = val;
    dq->count++;
    if (dq->rear == -1) dq->rear = dq->front;
}

// Push back
void push_back(Deque* dq, int val) {
    if (dq->count == dq->capacity) {
        printf("Deque full\n");
        return;
    }
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->arr[dq->rear] = val;
    dq->count++;
}

// Pop front
int pop_front(Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->count--;
    return val;
}

// Pop back
int pop_back(Deque* dq) {
    if (empty(dq)) return -1;
    int val = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    dq->count--;
    return val;
}

// Front element
int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

// Back element
int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

// Clear deque
void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->count = 0;
}

// Display deque
void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque empty\n");
        return;
    }
    int i = dq->front;
    for (int c = 0; c < dq->count; c++) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
    }
    printf("\n");
}

// Demo
int main() {
    Deque* dq = createDeque(10);

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_back(dq, 30);

    printf("Deque: ");
    display(dq);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));

    printf("Pop front: %d\n", pop_front(dq));
    printf("Pop back: %d\n", pop_back(dq));

    printf("Deque after pops: ");
    display(dq);

    clear(dq);
    printf("Deque cleared. Empty? %s\n", empty(dq) ? "Yes" : "No");

    free(dq->arr);
    free(dq);
    return 0;
}