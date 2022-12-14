#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct ListElement {
    char* string;
    struct ListElement *next;
} ListElement;

typedef struct List {
    ListElement *head;
    ListElement *lastElement;
} List;

List* createList(void) {
    List *temp = malloc(sizeof(List));
    temp->head = NULL;

    return temp;
}

int putToLastPosition(List *list, char* string) {
    if (list == NULL || string == NULL) {
        return -1;
    }

    ListElement *newElement = calloc(1, sizeof(ListElement));
    if (newElement == NULL) {
        return 1;
    }

    newElement->string = calloc(strlen(string) + 1, sizeof(char));
    if (newElement->string == NULL) {
        free(newElement);
        return 1;
    }

    strcpy(newElement->string, string);

    if (list->head == NULL) {
        list->head = newElement;
        list->lastElement = newElement;

        return 0;
    }

    list->lastElement->next = newElement;
    list->lastElement = newElement;

    return 0;
}

void deleteList(List **list, bool isAllocated) {
    if (*list == NULL) {
        free(*list);
        return;
    }

    ListElement *temp = (*list)->head;
    while (temp != NULL) {
        (*list)->head = (*list)->head->next;
        if (isAllocated) {
            free(temp->string);
        }

        temp = (*list)->head;
    }

    free(*list);
    *list = NULL;
}

void addAStartedToEnd(List *list, int *errorCode) {
    if (list == NULL) {
        *errorCode = -1;
        return;
    }

    ListElement *lastPosition = list->lastElement;
    if (list->lastElement == NULL) {
        return;
    }

    ListElement *currentTemp= list->head;

    while (currentTemp != lastPosition) {
        if (currentTemp->string != NULL && currentTemp->string[0] == 'a') {
            *errorCode = putToLastPosition(list, currentTemp->string);
            if (*errorCode) {
                return;
            }
        }

        currentTemp = currentTemp->next;
    }

    if (currentTemp->string != NULL && currentTemp->string[0] == 'a') {
        *errorCode = putToLastPosition(list, currentTemp->string);
        if (*errorCode) {
            return;
        }
    }
}

bool addAStartedToEndTest(void) {

}