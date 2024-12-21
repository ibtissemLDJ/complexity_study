#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 
void swap(int *A, int *B) {
    int x;
    x = *A;  
    *A = *B;  
    *B = x;   
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void randomly(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main (){
  srand(time(NULL));
  int numbers [100];
  int size = 100 ; 
  printf("the array befor sorting:");
  randomly(numbers, size);
  printArray(numbers, size);
  printf("the sotrted array ( Heap  sort ) \n");
  heapSort(numbers, size);
  printArray(numbers, size);                                   
  return 0;
}