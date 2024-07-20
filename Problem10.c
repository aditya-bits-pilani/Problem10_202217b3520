#include <stdio.h>

/* Function to merge the subarrays of a[] */
void merge(int a[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1; // Size of the first subarray
    int n2 = end - mid;     // Size of the second subarray

    // Temporary arrays to hold the subarrays
    int LeftArray[n1], RightArray[n2];

    // Copy data to temporary arrays LeftArray[] and RightArray[]
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    // Initial indexes for the temporary arrays and the merged array
    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = beg; // Initial index of the merged subarray

    // Merge the temporary arrays back into a[beg..end]
    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        } else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of LeftArray[], if any
    while (i < n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of RightArray[], if any
    while (j < n2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

/* Function to implement merge sort */
void mergeSort(int a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2; // Find the midpoint
        mergeSort(a, beg, mid);    // Sort the first half
        mergeSort(a, mid + 1, end); // Sort the second half
        merge(a, beg, mid, end);    // Merge the sorted halves
    }
}

/* Function to print the array */
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting, array elements are - \n");
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    printf("After sorting, array elements are - \n");
    printArray(a, n);
    return 0;
}