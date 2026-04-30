/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

// Structure to hold value and original index
typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void *a, const void *b) {
    return ((Pair*)a)->val - ((Pair*)b)->val;
}

// Merge function that counts smaller elements on right
void merge(int arr[], int idx[], int count[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    int tempIdx[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            tempIdx[k] = idx[i];
            count[idx[i]] += (j - mid - 1); // all elements already moved from right are smaller
            i++;
        } else {
            temp[k] = arr[j];
            tempIdx[k] = idx[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        tempIdx[k] = idx[i];
        count[idx[i]] += (j - mid - 1);
        i++; k++;
    }
    while (j <= right) {
        temp[k] = arr[j];
        tempIdx[k] = idx[j];
        j++; k++;
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
        idx[left + i] = tempIdx[i];
    }
}

void mergeSort(int arr[], int idx[], int count[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, idx, count, left, mid);
        mergeSort(arr, idx, count, mid + 1, right);
        merge(arr, idx, count, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], idx[n], count[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        idx[i] = i;
        count[i] = 0;
    }

    mergeSort(arr, idx, count, 0, n - 1);

    printf("Smaller elements on right for each position:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}
