#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void Swap(int *A, int *B)
{
    int x;
    x = *A;
    *A = *B;
    *B = x;
}

void BubbleSort(int Array[], int n)
{
    bool change = true; //1
    int i;
    //(6(n-1) +1 +1+n-1+2(n-2) )(n) = (6n -6 +2 +n -1 +2n -4 )n = 9n²-9n
    while (change) // n
    {
        change = false; // 1
        for (i = 0; i < n - 1; i++) //1+n-1+2(n-2)
        { // n-1
            if (Array[i] > Array[i + 1])
            {                                   // 2(n-1)
                Swap(&Array[i], &Array[i + 1]); // 3(n-1)
                change = true;                  // 1(n-1)
            }
        }
    }
}
void randomly(int *arr, int size)
{
    for (int i = 0; i < size; i++) //1+size+2(size-1) = 3size -1
    {
        arr[i] = rand() % 100; // 2size
    }
}

/*void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}*/

int main()
{
    srand(time(NULL));
    clock_t t1, t2;
    double execution_time;
    int size;
    printf("Enter the size of the array "); // 1
    scanf("%d", &size);                     // 1
    int numbers[size];
   // printf("the array befor sorting:");             // 1
    randomly(numbers, size);                        // 5size-1
   // printArray(numbers, size);                      // size
   // printf("the sotrted array ( bubble sort ) \n"); /// 1
    t1 = clock();
    BubbleSort(numbers, size); // 9n²-9n+1
    t2 = clock();
    //printArray(numbers, size); // size
    execution_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("The execution time is  %lf seconds\n", execution_time);
    return 0;
}