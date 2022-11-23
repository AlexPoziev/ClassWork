#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    if (!treeTest()) {
        printf("Tests Failed");
        return 1;
    }

    Tree *tree = createTree();
    if (tree == NULL) {
        printf("Not enough memory");
        return 1;
    }

    printf("Input array size more than 0: ");
    unsigned int arraySize = 0;
    scanf("%u", &arraySize);

    int *array = calloc(arraySize, sizeof(int));
    if (array == NULL) {
        printf("Not enough memory");
        deleteTree(&tree);

        return 1;
    }

    printf("Input values of array by enter: \n");
    for (int i = 0; i < arraySize; ++i) {
        scanf("%d", &array[i]);
    }

    int errorCode = sortArrayByTree(array, arraySize, tree);
    if (errorCode == 1) {
        printf("Not enough memory");
        free(array);
        deleteTree(&tree);

        return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }

    deleteTree(&tree);
    free(array);

    return 0;
}
