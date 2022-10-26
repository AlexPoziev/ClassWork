#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sumNumber(int number) {
    int sum = 0;
    while (number > 0) {
        int temp = number % 10;
        sum += temp;
        number /= 10;
    }

    return sum;
}

int* countMax(int *array, int arraySize) {
    int max = 0;
    int *tempArray = calloc(arraySize, sizeof(int));
    for (int i = 0; i < arraySize; ++i) {
        tempArray[i] = sumNumber(array[i]);
        if (tempArray[i] > max) {
            max = tempArray[i];
        }
    }
    
    for (int i = 0; i < arraySize; ++i) {
        if (tempArray[i] == max) {
            max = tempArray[i];
        }
    }
}

int main() {
    printf("Input size of array less than 50: ");
    int arraySize = scanf("%d", arraySize);
    while (arraySize < 0 || arraySize >= 50) {}
    return 0;
}
