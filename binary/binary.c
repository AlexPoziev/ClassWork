#include "binary.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *getDecimalFromBinary(const char *binary, int arraySize) {
    int sum = 0;
    int current = 1;

    char *stringSum = calloc(10, sizeof(char));
    if (stringSum == NULL) {
        return NULL;
    }

    for (int i = (int)arraySize - 1; i >= 0; --i) {
        sum += (binary[i] - '0')* current;
        current <<= 1;
    }

    sprintf(stringSum, "%d", sum);

    return stringSum;
}

bool getDecimalFromBinaryTest(void) {
    char *decimal = getDecimalFromBinary("11", 2);
    bool firstTest = !strcmp("3", decimal);

    free(decimal);

    decimal = getDecimalFromBinary("0", 1);
    bool secondTest = !strcmp("0", decimal);

    free(decimal);

    decimal = getDecimalFromBinary("001", 3);
    bool thirdTest = !strcmp("1", decimal);

    free(decimal);

    return firstTest && secondTest && thirdTest;
}