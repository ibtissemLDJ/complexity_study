#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
int key(int num, int digit)
{ // 3 complexty
    if (digit == 0)
    {
        return num % 10;
    }
    else if (digit == 1)
    {
        return (num / 10) % 10;
    }
    else if (digit == 2)
    {
        return (num / 100) % 10;
    }
    return 0;
}

void SortAux(int arr[], int size, int digit)
{
    for (int i = 0; i < size - 1; i++)//1+ size + 2(size -1)
    {// size
        for (int j = 0; j < size - i - 1; j++)//1+ size-i +2(size-i-1)
        {  // 10 size - i  
            if (key(arr[j], digit) > key(arr[j + 1], digit))
            { // 10

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void RadixSort(int arr[], int size)
{
    for (int i = 0; i < 3; i++)//1+3 + 2*3
    {//3 
        SortAux(arr, size, i);
    }
}
void randomly(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 901 + 100;
        ;
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
    printf("the array befor sorting:");           // 1 complexty
    randomly(numbers, size);                      // 3 size cpmlexity
   // printArray(numbers, size);                    // 1size complexity
    printf("the sotrted array (redix sort ) \n"); // 1 complexity
    t1 = clock();
    RadixSort(numbers, size);
    t2 = clock();
    //printArray(numbers, size); // 1 size complexity
    execution_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("The execution time is  %lf seconds\n", execution_time);

    return 0;
}
