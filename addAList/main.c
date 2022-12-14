#include <stdio.h>
#include "list.h"

int main() {
    List *list = createList();
    if (list == NULL) {
        printf("Not enough memory");
        return 1;
    }

    putToLastPosition(list, "abc");
    putToLastPosition(list, "bbc");
    putToLastPosition(list, "ac");
    putToLastPosition(list, "bc");

    int errorCode = 0;
    addAStartedToEnd(list, &errorCode);

    return 0;
}
