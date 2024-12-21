#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
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
int partition(int tab[], int p, int r)
{
    int pivot = tab[p];
    int i = p, j = r, temp;

    while (i < j)
    {

        while (j > i && tab[j] > pivot)
        {
            j--;
        }

        while (i < j && tab[i] <= pivot)
        {
            i++;
        }

        if (i < j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }

    tab[p] = tab[j];
    tab[j] = pivot;

    return j;
}
void QuickSort(int tab[], int p, int r) {
    if (p < r) {
        int q = partition(tab, p, r); 
        QuickSort(tab, p, q - 1);   
        QuickSort(tab, q + 1, r);    
    }
}
int main()
{
    srand(time(NULL));
    int numbers[100];
    int size = 100;
    printf("the array befor sorting:");
    randomly(numbers, size);
    printArray(numbers, size);
    printf("the sotrted array ( quick sort ) \n");
    QuickSort(numbers,0, size-1);
    printArray(numbers, size);
    return 0;
}