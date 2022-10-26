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
        answer[i] = 0;
    }
    for (int i = 0; i < arraySize; ++i) {
        if (tempArray[i] == max) {
            answer[current] = array[i];
            ++current;
        }
    }
    free(tempArray);

    return answer;
}

bool correctTest(void) {
    int testArray[5] = {45, -18, 9, 53, 0};

    int *temp = countMax(testArray, 5);
    if (temp == NULL) {
        return false;
    }

    bool correct = temp[0] == 45 && temp[1] == -18 && temp[2] == 9 && temp[3] == 0;

    free(temp);

    return correct;
}

int printMaxValue(int *array, int arraySize) {
    int *temp = countMax(array, arraySize);
    if (temp == NULL) {
        return 1;
    }
    int i = 0;
    if (temp[i] == 0) {
        printf("0");
        return 0;
    }
    while (temp[i] != 0) {
        printf("%d", temp[i]);
        ++i;
    }

    free(temp);

    return 0;
}

int main() {
    if (!correctTest()) {
        printf("Tests failed");
        return 1;
    }

    printf("Input size of array less than 50: ");
    int arraySize = 0;
    scanf("%d", &arraySize);
    while (arraySize <= 0 || arraySize >= 50) {
        printf("Please, repeat input: ");
        scanf("%d", &arraySize);
    }

    int *array = calloc(arraySize, sizeof(int));
    if (array == NULL) {
        printf("Not enough memory");
        return 1;
    }

    printf("Print value of array: ");
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    int errorCode = printMaxValue(array, arraySize);
    if (errorCode) {
        printf("Not enough memory");
        return 1;
    }

    return 0;
}

