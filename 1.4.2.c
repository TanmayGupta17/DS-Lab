#include <stdio.h>

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void selectionSort(int arr[], int n) {
    if (n == 1)
        return;
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
    selectionSort(arr, n - 1);
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}