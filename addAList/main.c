#include <stdio.h>
#include "list.h"

int main() {
    if (!listTest()) {
        printf("Tests Failed");
        return 1;
    }

    List *list = createList();
    if (list == NULL) {
        printf("Not enough memory");
        return 1;
    }

    int errorCode = 0;

    errorCode = putToLastPosition(list, "abc");
    if (errorCode) {
        printf("Not enough memory");
        return 1;
    }
    errorCode = putToLastPosition(list, "bbc");
    if (errorCode) {
        printf("Not enough memory");
        return 1;
    }
    errorCode = putToLastPosition(list, "ac");
    if (errorCode) {
        printf("Not enough memory");
        return 1;
    }

    printf("Current List:\n");
    printList(list);

    addAStartedToEnd(list, &errorCode);
    if (errorCode == 1) {
        printf("Not enough memory");
        return 1;
    }

    printf("\nList after changing:\n");
    printList(list);

    deleteList(&list, true);

    return 0;
}
