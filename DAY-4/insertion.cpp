#include <stdio.h>

void insertNumber(int arr[], int *n, int pos, int num) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = num;
    (*n)++;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; // current size of the array
    int pos = 2; // position where to insert
    int num = 25; // number to be inserted

    insertNumber(arr, &n, pos, num);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

