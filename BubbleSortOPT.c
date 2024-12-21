#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h> 
void Swap(int *A, int *B) {
    int x;
    x = *A;  
    *A = *B;  
    *B = x;   
}

void BubbleSort(int Array [], int n ){
 int m= n-1;
 bool change = true ; 
 int i ; 
 while (change)
 {
   change = false;
   for (i=0 ;i<m ; i++){
    if (Array[i]>Array[i+1]){
       Swap(&Array[i],&Array[i+1]);
       change=true;
    }
   }
   m--;
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
  printf("the sotrted array ( bubble sort OPT ) \n");
  BubbleSort(numbers, size);
  printArray(numbers, size);                                   
  return 0;
}