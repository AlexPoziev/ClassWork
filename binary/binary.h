#pragma once

#include <stdbool.h>

// return char array decimal representation by binary number string
// return NULL if not enough memory
// gotten char need to deallocate after work with it by free()
char* getDecimalFromBinary(const char *binary, int arraySize);

// test of getDecimalFromBinary function
bool getDecimalFromBinaryTest(void);