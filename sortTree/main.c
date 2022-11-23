#include "binaryTree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Tree *tree = createTree();

    int *array = calloc(5, sizeof(int));
    array[0] = 5;
    array[1] = 5;
    array[2] = 5;
    array[3] = 5;
    array[4] = 1;


    sortArrayByTree(array, 5, tree);

    return 0;
}
