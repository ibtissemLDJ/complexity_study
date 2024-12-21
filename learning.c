#include <stdio.h>

// Function that modifies the array
void processArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // Modify each element in the array
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    // Pass the array to the function
    processArray(numbers, size);

    printf("\nModified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
