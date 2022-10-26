#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int sumNumber(int number) {
    number = abs(number);
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
    if (tempArray == NULL) {
        return NULL;
    }
    for (int i = 0; i < arraySize; ++i) {
        tempArray[i] = sumNumber(array[i]);
        if (tempArray[i] > max) {
            max = tempArray[i];
        }
    }
    int *answer = calloc(50, sizeof(int));
    if (answer == NULL) {
        return NULL;
    }
    int current = 0;
    for (int i = 0; i < 50; ++i) {
        answer[i] = -1;
    }
    for (int i = 0; i < arraySize; ++i) {
        if (tempArray[i] == max) {
            answer[current] = array[i];
        }
    }
    free(tempArray);

    return answer;
}

int printMaxValue(int *array, int arraySize) {
    int *temp = countMax(array, arraySize);
    if (temp == NULL) {
        return 1;
    }
    int i = 0;
    while (temp[i] != -1) {
        printf("%d", array[i]);
        ++i;
    }

    free(temp);

    return 0;
}

int main() {
    printf("Input size of array less than 50: ");
    int arraySize = 0;
    scanf("%d", &arraySize);
    int *array = calloc(arraySize, sizeof(int));
    if (array == NULL) {
        printf("Not enough memory");
        return 1;
    }
    printf("Print value of array: ");
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    printMaxValue(array, arraySize);

    return 0;
}
