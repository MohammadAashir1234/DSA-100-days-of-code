/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void *a, const void *b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return x[0] - y[0];
}

void mergeIntervals(int intervals[][2], int n) {
    if (n == 0) return;

    // Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Start with the first interval
    int start = intervals[0][0];
    int end   = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= end) {
            // Overlap → extend the end
            if (intervals[i][1] > end)
                end = intervals[i][1];
        } else {
            // No overlap → print previous merged interval
            printf("[%d, %d] ", start, end);
            // Reset to current interval
            start = intervals[i][0];
            end   = intervals[i][1];
        }
    }
    // Print the last merged interval
    printf("[%d, %d]\n", start, end);
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int intervals[n][2];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("Merged intervals: ");
    mergeIntervals(intervals, n);

    return 0;
}
