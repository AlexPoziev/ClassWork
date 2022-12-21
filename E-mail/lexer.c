#include "lexer.h"

typedef enum State {
    start,
    userName,
    atSign,
    addressTail,
    addressDot,
    signAfterDot    // 1234@mail.r.com
} State;

bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

bool isLetter(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

bool isSpecificSign(char symbol) {
    return symbol == '.' || symbol == '_' || symbol == '%'
            || symbol == '+' || symbol == '-';
}

bool isEmailAddress(const char *expression) {
    State currentState = start;
    unsigned int currentPosition = 0;

    while (expression[currentPosition] != '\0') {
        char currentSymbol = expression[currentPosition];
        ++currentPosition;

        switch (currentState) {
            case start: {
                if (isDigit(currentSymbol) || isLetter(currentSymbol) || isSpecificSign(currentSymbol)) {
                    currentState = userName;
                    break;
                }

                return false;
            }

            case userName: {
                if (isDigit(currentSymbol) || isLetter(currentSymbol) || isSpecificSign(currentSymbol)) {
                    break;
                }
                if (currentSymbol == '@') {
                    currentState = atSign;
                    break;
                }

                return false;
            }

            case atSign: {
                if (isDigit(currentSymbol) || isLetter(currentSymbol) || currentSymbol == '-') {
                    currentState = addressTail;
                    break;
                }

                return false;
            }

            case addressTail: {
                if (isDigit(currentSymbol) || isLetter(currentSymbol) || currentSymbol == '-') {
                    break;
                }
                if (currentSymbol == '.') {
                    currentState = addressDot;
                    break;
                }

                return false;
            }

            case addressDot: {
                if (isLetter(currentSymbol)) {
                    currentState = signAfterDot;
                    break;
                }
                if (isDigit(currentSymbol) || currentSymbol == '-') {
                    currentState = addressTail;
                    break;
                }

                return false;
            }

            case signAfterDot: {
                if (isDigit(currentSymbol) || isLetter(currentSymbol) || currentSymbol == '-') {
                    currentState = addressTail;
                    break;
                }

                return false;
            }
        }
    }

    return currentState == signAfterDot;
}