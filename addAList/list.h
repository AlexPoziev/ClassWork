#pragma once

#include <stdbool.h>

typedef struct List List;

// create list, need to check not NULL pointer \/
List* createList(void);

// put to head
int putToLastPosition(List *list, char* string);

// delete List, second parameter if got 1 - free memory for pointers of contacts, else doesn't \/
void deleteList(List **list, bool isAllocated);

// add all string that starting by 'a' to the end of list
// errorCode gets values:
// 1 if not enough memory
// -1 if pointer to list is NULL
void addAStartedToEnd(List *list, int *errorCode);

// test of all list functions
bool listTest(void);

// print list in a row
void printList(List *list);