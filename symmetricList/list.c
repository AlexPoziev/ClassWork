#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ListElement {
    int value;
    struct ListElement *next;
    struct ListElement *previous;
} ListElement;

typedef struct List {
    ListElement *head;
} List;

List* createList(void) {
    List *temp = malloc(sizeof(List));
    temp->head = NULL;

    return temp;
}

int addValue(List *list, int value) {
    if (list == NULL) {
        return -1;
    }

    ListElement* temp = malloc(sizeof(ListElement));
    if (temp == NULL) {
        return 1;
    }

    temp->value = value;
    temp->next = list->head;
    temp->previous = NULL;
    if (list->head != NULL) {
        list->head->previous = temp;
    }

    list->head = temp;

    return 0;
}

void deleteList(List **list) {
    if (*list == NULL || list == NULL) {
        return;
    }

    ListElement *current = (*list)->head;
    ListElement *previous = NULL;

    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }

    free(*list);
    *list = NULL;
}

int getListFromFile(char *fileName, List *list) {
    if (list == NULL) {
        return -1;
    }

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return -1;
    }

    while (!feof(file)) {
        int value = 0;
        int eofCheck = fscanf(file,"%d", &value);
        if (eofCheck == EOF) {
            fclose(file);
            return 0;
        }

        int errorCode = addValue(list, value);
        if (errorCode) {
            return 1;
        }

        eofCheck = fgetc(file);
        if (eofCheck == EOF) {
            fclose(file);
            return 0;
        }
    }

    fclose(file);

    return 0;
}

ListElement* getLastElement(List *list){
    ListElement *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

bool isSymmetric(List *list) {
    if (list == NULL || list->head == NULL) {
        return true;
    }

    ListElement *lastElement = getLastElement(list);
    ListElement *frontElement = list->head;
    while (lastElement != frontElement && lastElement->next != frontElement) {
        if (frontElement->value != lastElement->value) {
            return false;
        }
        frontElement = frontElement->next;
        lastElement = lastElement->previous;
    }

    return true;
}

bool createListTest(void) {
    List *list = createList();
    if (list == NULL) {
        return false;
    }

    bool test = list != NULL;

    deleteList(&list);

    return test;
}

bool addValueTest(void) {
    List *list = createList();
    if (list == NULL) {
        return false;
    }

    int errorCode = addValue(list, 1);
    if (errorCode == 1) {
        deleteList(&list);
        return false;
    }
    errorCode = addValue(list, 2);
    if (errorCode == 1) {
        deleteList(&list);
        return false;
    }

    bool firstTest = list->head->value == 2;
    bool secondTest = list->head->next->value == 1;

    deleteList(&list);

    return firstTest && secondTest;
}

bool deleteListTest(void) {
    List *list = createList();
    if (list == NULL) {
        return false;
    }

    bool firstTest = list != NULL;

    deleteList(&list);

    bool secondTest = list == NULL;

    return firstTest && secondTest;
}

bool getListFromFileTest(void) {
    List *list = createList();

    int errorCode = getListFromFile("secondTest.txt", list);
    if (errorCode == 1) {
        deleteList(&list);
        return false;
    }
    bool firstTest = list->head->value == 10;
    bool secondTest = list->head->next->value == 20;
    bool thirdTest = list->head->next->next->value == 30;
    bool fourthTest = list->head->next->next->next->value == 20;
    bool fifthTest = list->head->next->next->next->next->value == 10;

    deleteList(&list);

    return firstTest && secondTest && thirdTest && fourthTest && fifthTest;
}

bool isSymmetricTest(void) {
    List *list = createList();

    int errorCode = getListFromFile("firstTest.txt", list);
    if (errorCode == 1) {
        deleteList(&list);
        return false;
    }

    bool firstTest = isSymmetric(list);
    deleteList(&list);

    errorCode = getListFromFile("secondTest.txt", list);
    if (errorCode == 1) {
        deleteList(&list);
        return false;
    }

    bool secondTest = isSymmetric(list);

    deleteList(&list);

    return !firstTest && secondTest;
}

bool listTest(void) {
    return createListTest() && addValueTest() && deleteListTest()
        && getListFromFileTest() && isSymmetricTest();
}