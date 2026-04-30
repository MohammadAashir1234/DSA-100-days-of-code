/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

// Min-heap utility
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int size) {
    int i = size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int heap[], int size) {
    int i = 0;
    while (2*i + 1 < size) {
        int left = 2*i + 1, right = 2*i + 2, smallest = left;
        if (right < size && heap[right] < heap[left]) smallest = right;
        if (heap[i] <= heap[smallest]) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void push(int heap[], int *size, int val) {
    heap[(*size)++] = val;
    heapifyUp(heap, *size);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size);
    return root;
}

int peek(int heap[]) {
    return heap[0];
}

// Comparator for qsort (sort by start time)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

// Function to find minimum rooms
int minMeetingRooms(int intervals[][2], int n) {
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int heap[n]; // min-heap for end times
    int size = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end   = intervals[i][1];

        // Free rooms that ended before current start
        while (size > 0 && peek(heap) <= start) {
            pop(heap, &size);
        }

        // Allocate current meeting
        push(heap, &size, end);

        if (size > maxRooms) maxRooms = size;
    }
    return maxRooms;
}

int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];
    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int rooms = minMeetingRooms(intervals, n);
    printf("Minimum number of rooms required: %d\n", rooms);

    return 0;
}
