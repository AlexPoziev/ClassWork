#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

bool isPalindrome(char *string) {
    unsigned int leftSide = 0;
    unsigned int rightSide = strlen(string) - 1;
    // zero length case
    if (rightSide == -1) {
        return true;
    }

    while (leftSide < rightSide) {
        while (leftSide < rightSide && string[leftSide] == ' ') {
            ++leftSide;
        }
        while (leftSide < rightSide && string[rightSide] == ' ') {
            --rightSide;
        }
        if (leftSide >= rightSide) {
            return true;
        }

        if (string[leftSide] != string[rightSide]) {
            return false;
        }

        ++leftSide;
        --rightSide;
    }

    return true;
}

bool trueTest(void) {
    bool firstTest = isPalindrome("");
    bool secondTest = isPalindrome("a");
    bool thirdTest = isPalindrome("abba");
    bool fourthTest = isPalindrome("12521");
    bool fifthTest = isPalindrome("aborrow or rob a");

    return firstTest && secondTest && thirdTest && fourthTest && fifthTest;
}

bool falseTest(void) {
    bool firstTest = isPalindrome("ab");
    bool secondTest = isPalindrome("133");
    bool thirdTest = isPalindrome("borrow and rob");

    return !firstTest && !secondTest && !thirdTest;
}

int main(void) {
    if (!trueTest() || !falseTest()) {
        printf("Tests Failed");
        return -1;
    }

    printf("Print string with length less than 100: ");

    char *string = calloc(MAX_STRING_LENGTH, sizeof(char));
    if (string == NULL) {
        printf("Not enough memory");
        return 1;
    }

    scanf("%[^\n]", string);

    printf("It's %s", isPalindrome(string) ? "a palindrome" : "not a palindrome");

    free()
    return 0;
}
