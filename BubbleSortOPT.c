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

void BubbleSortOpt(int Array[], int n)
{
    int m = n - 1;      // 1
    bool change = true; // 1
    int i;              // 6m+2 (m(m+1)/2)
    while (change)      // n-1
    {
        change = false; // 1
        // 6m
        for (i = 0; i < m; i++)
        { // m
            if (Array[i] > Array[i + 1])
            {                                   // 2
                Swap(&Array[i], &Array[i + 1]); // 3
                change = true;                  // 1
            }
        }
        m--; // 1
    }
}
void randomly(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
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
    printf("Enter the size of the array \n"); // 1
    scanf("%d", &size);                       // 1
    int numbers[size];
    printf("the array befor sorting:");                 // 1
    randomly(numbers, size);                            // 2size
   // printArray(numbers, size);                          // size
    printf("the sotrted array ( bubble sort OPT ) \n"); // 1
    t1 = clock();
    BubbleSortOpt(numbers, size); //
    t2 = clock();
   // printArray(numbers, size);
    execution_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("The execution time is  %lf seconds\n", execution_time);
    return 0;
}