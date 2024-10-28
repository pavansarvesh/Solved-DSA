#include <stdio.h>

// QuickSort function
void quickSort(int array[], int front, int last) {
    if (front < last) {
        int pivot = front;
        int i = front;
        int j = last;
        int temp;

        // Partitioning the array
        while (i < j) {
            while (array[i] <= array[pivot] && i < last)
                i++;
            while (array[j] > array[pivot])
                j--;
            if (i < j) {
                // Swap array[i] and array[j]
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                for (int i = 0; i < last; i++) {
                    printf("%d\t", array[i]);
                }
                printf("\n");
            }
        }

        // Swap pivot element with array[j]
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        for (int i = 0; i < last; i++) {
            printf("%d\t", array[i]);
        }
        printf("\n");

        // Recursively apply quicksort to partitions
        quickSort(array, front, j - 1);
        quickSort(array, j + 1, last);
    }
}

int main() {
    int n;

    printf("Array size: ");
    scanf("%d", &n);

    int arr[n];  // Declare the array dynamically based on input size

    // Getting input
    for (int i = 0; i < n; i++) {
        printf("Enter index %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Printing unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Call to quickSort
    quickSort(arr, 0, n - 1);

    // Printing sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
