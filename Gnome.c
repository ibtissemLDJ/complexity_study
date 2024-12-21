#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void GnomeSort(int arr[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        if (arr[i] <= arr[i + 1])
        {
            i++;
        }
        else
        {

            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;

            if (i > 0)
            {
                i--;
            }
            else
            {
                i = 0;
            }
        }
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
    int numbers[100];
    int size = 100;
    printf("the array befor sorting:");
    randomly(numbers, size);
    printArray(numbers, size);
    printf("the sotrted array ( Gnome sort ) \n");
    GnomeSort(numbers, size);
    printArray(numbers, size);
    return 0;
}