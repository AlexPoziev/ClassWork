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

        addValue(list, value);

        eofCheck = fgetc(file);
        if (eofCheck == EOF) {
            fclose(file);
            return 0;
        }
    }

    fclose(file);

    return 0;
}