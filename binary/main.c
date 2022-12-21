#include "binary.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    if (!getDecimalFromBinaryTest()) {
        printf("Tests Failed");
        return 1;
    }

    printf("Input binary number: ");
    char binary[sizeof(int) * 8] = {0};
    scanf("%s", binary);
    char *decimal = getDecimalFromBinary(binary, (int)strlen(binary));
    if (decimal == NULL) {
        printf("Not enough memory");
        return 1;
    }

    printf("Decimal representation: %s", decimal);

    free(decimal);

    return 0;
}
