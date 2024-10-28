#include <stdio.h>
#define MAX 100
void printArray(int arr[], int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int low, int mid, int high) {
    int temp[MAX];
    int i = low, k = low, j = mid + 1;
    while ((i <= mid) && (j <= high)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
    printf("Array after merging from index %d to %d: ", low, high);
    printArray(arr, low, high);
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main() {
    int arr[MAX], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, 0, n - 1);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, 0, n - 1);
    return 0;
}