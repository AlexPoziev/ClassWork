#include "list.h"
#include <stdio.h>

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

    printf("Input name of file with length less than 20: ");
    char fileName[20] = {0};
    scanf("%s", fileName);

    int errorCode = getListFromFile("test.txt", list);
    if (errorCode == -1) {
        printf("No file with this name exists");
        deleteList(&list);
        
        return 0;
    }
    if (errorCode == 1) {
        printf("Not enough memory");
        deleteList(&list);

        return 1;
    }

    printf("List %s", isSymmetric(list) ? "is symmetrical" : "isn't symmetrical");

    deleteList(&list);

    return 0;
}
