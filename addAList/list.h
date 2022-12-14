#pragma once

#include <stdbool.h>
#include <stdio.h>

// pointer to list element
typedef struct ListElement ListElement;

typedef struct List List;

// create list, need to check not NULL pointer \/
List* createList(void);

// put to head
int putToLastPosition(List *list, char* string);

// delete List, second parameter if got 1 - free memory for pointers of contacts, else doesn't \/
void deleteList(List **list, bool isAllocated);

// add all string that starting by 'a' to the end of list
void addAStartedToEnd(List *list, int *errorCode);

bool addAStartedToEndTest(void);