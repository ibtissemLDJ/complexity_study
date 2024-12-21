#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 
int key(int num, int digit) {
    if (digit == 0) {
        return num % 10;       
    } else if (digit == 1) {
        return (num / 10) % 10;
    } else if (digit == 2) {
        return (num / 100) % 10; 
    }
    return 0; 
}

void SortAux(int arr[], int size, int digit) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (key(arr[j], digit) > key(arr[j + 1], digit)) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void RadixSort(int arr[], int size) {
    for (int i = 0; i < 3; i++) {
        SortAux(arr, size, i);
    }
}
void randomly(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] =  rand() % 901 + 100;;  
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
  printf("the sotrted array (redix sort ) \n");
  RadixSort(numbers, size);
  printArray(numbers, size);                                   
  return 0;
}
