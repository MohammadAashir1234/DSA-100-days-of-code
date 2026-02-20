/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = __INT_MAX__;
    int pair[2];

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            pair[0] = arr[left];
            pair[1] = arr[right];
        }
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d %d\n", pair[0], pair[1]);

    return 0;
}