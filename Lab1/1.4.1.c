#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int l = 0, r = sizeof(arr) / sizeof(arr[0]) - 1;
    int x = 10;
    int result = binarySearch(arr, l, r, x);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}