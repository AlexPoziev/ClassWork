#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

int changeRepeats(FILE *file, char *string) {
    if (file == NULL) {
        return 1;
    }
    int currentPosition = 0;

    char currentSymbol = (char)fgetc(file);
    if (currentSymbol == -1) {
        return 0;
    }

    while (!feof(file)) {
        char previousSymbol = currentSymbol;
        currentSymbol = (char)fgetc(file);
        if (currentSymbol == -1) {
            if (string[currentPosition - 1] != previousSymbol) {
                string[currentPosition] = previousSymbol;
            }
            break;
        }
        if (currentSymbol != previousSymbol) {
            string[currentPosition] = previousSymbol;
            ++currentPosition;
            if (currentPosition >= 1000) {
                return -1;
            }
        }
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

    free(fileName);

    char* string = calloc(1000, sizeof(char));
    if (string == NULL) {
        printf("Not enough memory");
        fclose(file);

        return 1;
    }

    int errorCode = changeRepeats(file, string);
    if (errorCode == -1) {
        printf("File is too big");
        free(string);
        free(file);

        return -1;
    }

    printf("Final string: %s", string);

    fclose(file);
    free(string);

    return 0;
}
