#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int symbolsPrinter(int *array) {
    if (array == NULL) {
        return 1;
    }
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        if (array[i] > 0) {
            printf("symbol '%d', %d times \n", i, array[i]);
        }
    }

    free(array);

    return 0;
}

int* symbolsCounter(FILE *file, const char *fileName) {
    file = fopen(fileName, "r");
    int *symbolsCount = calloc(MAX_BUFFER_SIZE, sizeof(int));
    if (symbolsCount == NULL) {
        return symbolsCount;
    }
    char temp[MAX_BUFFER_SIZE] = {0};
    while (!feof(file)) {
        fgets(temp, MAX_BUFFER_SIZE, file);
        int i = 0;
        while (temp[i] != '\n' && temp[i] != '\0') {
            ++symbolsCount[temp[i]];
            ++i;
        }
    }

    fclose(file);

    return symbolsCount;
}

int symbolsCountPrinter(FILE *file, const char *fileName) {
    int errorCode = symbolsPrinter(symbolsCounter(file, fileName));
    return errorCode;
}

bool correctTest(void) {
    const char* fileName = "test.txt";
    FILE *file = NULL;
    int *test = symbolsCounter(file, fileName);
    if (test == NULL) {
        return false;
    }

    bool check = test[33] == 3 && test[49] == 3 && test[50] == 1 && test[51] == 3
            && test[63] == 2 && test[97] == 5 && test[98] == 3;

    free(test);

    return check;
}

int main() {
    if (!correctTest()) {
        printf("Test Failed");
        return 1;
    }

    printf("Print name of .txt file with name length less than 20: ");
    char fileName[20] = {0};
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File with this name doesn't exist");
        fclose(file);
        return 1;
    }
    fclose(file);

    int errorCode = symbolsCountPrinter(file, fileName);
    if (errorCode == 1) {
        printf("Not enough memory");
        return 1;
    }
    return 0;
}
