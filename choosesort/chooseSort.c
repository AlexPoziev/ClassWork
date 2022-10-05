#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *firstNumber, int *secondNumber) {
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void EvenChooseSort(int array[], int size) {
    if (size == 1) {
        return;
    }

    for (int i = 0; i < size; i += 2){
        int minIndex = i;
        for (int j = i + 2; j < size; j += 2) {
            int min = array[i];

            if (array[j] < min) {
                min = array[j];
                minIndex = j;
            }

        }
        if (i != minIndex) {
            swap(&array[i], &array[minIndex]);
        }
    }
}

bool correctTest() {
    int firstArray[5] = {5, 4, 3, 2, 1};
    int secondArray[1] = {5};


}

int main() {
    if (!correctTest()) {
        printf("Test Failed");
        return 1;
    }

    printf("Input array length: ");
    int size = 0;
    scanf("%d", &size);

    int *array = (int*)(calloc(size, sizeof(int)));
    if (array == NULL) {
        return 1;
    }

    printf("Print all numbers by enter: \n");

    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    EvenChooseSort(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}
