#include <stdbool.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 256

void symbolsPrinter(int *array) {
    for (int i = 0; i < MAX_BUFFER_SIZE; ++i) {
        if (array[i] > 0) {
            printf("symbol '%d', %d times \n", i, array[i]);
        }
    }
}

void symbolsCounter(FILE *file, const char *fileName) {
    file = fopen(fileName, "r");
    int symbolsCount[MAX_BUFFER_SIZE] = {0};
    char temp[MAX_BUFFER_SIZE] = {0};
    while (!feof(file)) {
        fgets(temp, MAX_BUFFER_SIZE, file);
        int i = 0;
        while (temp[i] != '\n' && temp[i] != '\0') {
            ++symbolsCount[temp[i]];
            ++i;
        }
    }
    symbolsPrinter(symbolsCount);

    fclose(file);
}

bool correctTest(void) {
    const char* fileName = "test.txt";
    
}

int main() {
    const char* fileName = "test.txt";
    FILE *file = NULL;
    symbolsCounter(file, fileName);
    return 0;
}
