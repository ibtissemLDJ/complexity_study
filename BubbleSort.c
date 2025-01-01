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
 bool change = true ; 
 int i ; 
 while (change)
 {
   change = false;
   for (i=0 ;i<n-1 ; i++){
    if (Array[i]>Array[i+1]){
       Swap(&Array[i],&Array[i+1]);
       change=true;
    }
   }
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
  clock_t t1, t2;
  double execution_time;
  int numbers [100];
  int size = 100 ; 
  printf("the array befor sorting:");
  randomly(numbers, size);
  printArray(numbers, size);
  printf("the sotrted array ( bubble sort ) \n");
  t1 = clock();
  BubbleSort(numbers, size);
  t2 = clock();
  printArray(numbers, size); 
  execution_time = (double)(t2 - t1)/ CLOCKS_PER_SEC;
  printf("The execution time is  %lf seconds\n", execution_time);
  return 0;
}