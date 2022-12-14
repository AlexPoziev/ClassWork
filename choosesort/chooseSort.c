#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *firstNumber, int *secondNumber) {
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void evenChooseSort(int array[], int size) {
    if (size == 1) {
        return;
    }

    for (int i = 0; i < size; i += 2) {
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

bool correctTest(void) {
    int firstArray[5] = {5, 4, 3, 2, 1};

    evenChooseSort(firstArray, 5);

    return firstArray[0] == 1 && firstArray[1] == 4 && firstArray[2] == 3 && firstArray[3]== 2 && firstArray[4] == 5;
}

int main() {
    if (!correctTest()) {
        printf("Test Failed");
        return 1;
    }

    printf("Input array length: ");
    int size = 0;
    scanf("%d", &size);
    while (size < 1) {
        printf("Count of numbers cannot be negative or zero, repeat input: ");
        scanf("%d", &size);
    }

    int *array = (int*)(calloc(size, sizeof(int)));
    if (array == NULL) {
        printf("Not enough memory");
        return 1;
    }

    printf("Print all numbers by enter: \n");

    for (int i = 0; i < size; ++i) {
        int isString = scanf("%d", (&array[i]));
        while (isString == 0) {
            printf("Entered value is not a number, repeat input: \n");
            fflush(stdin);
            isString = scanf("%d", &array[i]);
        }
    }

    evenChooseSort(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
