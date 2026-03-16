/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for insert)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify down (for extractMin)
void heapifyDown(int index) {
    while (2 * index + 1 < heapSize) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heapSize && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heapSize && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert element
void insert(int val) {
    if (heapSize == MAX) {
        printf("Heap full\n");
        return;
    }
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

// Extract minimum element
int extractMin() {
    if (heapSize == 0) return -1;
    int minVal = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return minVal;
}

// Peek minimum element
int peek() {
    if (heapSize == 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}