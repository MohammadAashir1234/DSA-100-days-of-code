/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0;

    // Check all possible subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }
    return maxLen;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = longestZeroSumSubarray(arr, n);
    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}
