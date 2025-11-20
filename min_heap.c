#include <stdio.h>

void heapify(int arr[], int i, int n) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr, smallest, n);
    }
}

int extractMin(int arr[], int *heap_size) {
    
  if(*heap_size <= 0) return -1;

    int root = arr[0];
    arr[0] = arr[*heap_size - 1];
    (*heap_size)--;

    heapify(arr, 0, *heap_size);
    return root;
}

void heapSort(int arr[], int n) {
    
    int orig_n = n;

    
    for (int i = orig_n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, orig_n);
    }

    ;

    int sorted[orig_n];
    int heap_size = orig_n;

    
    for (int i = 0; i < orig_n; i++) {
        sorted[i] = extractMin(arr, &heap_size);
    }

 
    for (int i = 0; i < orig_n; i++) {
        arr[i] = sorted[i];
    }
}

int main() {
    int arr[] = {2,1,4,5,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
