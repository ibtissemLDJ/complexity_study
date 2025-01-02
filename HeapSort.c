#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void swap(int *A, int *B)
{
    int x;
    x = *A;
    *A = *B;
    *B = x;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void randomly(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    srand(time(NULL));
    clock_t t1, t2;
    double execution_time;
    int size;
    printf("Enter the size of the array \n"); // 1
    scanf("%d", &size);                       // 1
    int numbers[size];
    printf("the array befor sorting:");
    randomly(numbers, size);
    printArray(numbers, size);
    printf("the sotrted array ( Heap  sort ) \n");
    t1 = clock();
    heapSort(numbers, size);
    t2 = clock();
    printArray(numbers, size);
    execution_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("The execution time is  %lf seconds\n", execution_time);

    return 0;
}