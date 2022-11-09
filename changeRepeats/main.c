#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

int changeRepeats(FILE *file, char *string) {
    char currentSymbol
    while (!feof(file)) {
        fgetc(file)
    }

    return 0;
}

int main(void) {
    printf("Print file name with name length less than 20 and which contains less than 1000 symbol: ");
    char *fileName = calloc(20, sizeof(char));
    if (fileName == NULL) {
        printf("Not enough memory");
        return 1;
    }
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File with this name doesn't exist");
        free(fileName);
        return -1;
    }

    char* string = calloc(1000, sizeof(char));
    if (string == NULL) {
        printf("Not enough memory");
        free(fileName);
        fclose(file);
    }

    return 0;
}
