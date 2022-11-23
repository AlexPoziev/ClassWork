#include "list.h"
#include <stdio.h>

int main() {
    List *list = createList();
    if (list == NULL) {
        printf("Not enough memory");
        return 1;
    }

    getListFromFile("test.txt", list);

    return 0;
}
