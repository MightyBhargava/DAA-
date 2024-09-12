#include <stdio.h>

#define SIZE 100

void insert_number(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) {
        printf("Position %d not available in the list.\n", pos);
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void print_list(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int n = 5; 
    int value, pos;

    printf("Insert at the beginning:\n");
    value = 10;
    insert_number(arr, &n, 0, value);  
    print_list(arr, n);

    printf("Insert in the middle:\n");
    value = 20;
    insert_number(arr, &n, n / 2, value); 
    print_list(arr, n);

    printf("Insert at the last:\n");
    value = 30;
    insert_number(arr, &n, n, value);  
    print_list(arr, n);

    printf("Insert at an unavailable position:\n");
    value = 40;
    insert_number(arr, &n, 100, value);  
    print_list(arr, n);

    return 0;
}

