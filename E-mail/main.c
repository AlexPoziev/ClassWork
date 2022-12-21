#include <stdio.h>
#include "lexer.h"
#include "lexerTests.h"

int main() {
    if (!lexerTest()) {
        printf("Tests Failed");
        return 1;
    }

    printf("Input string, with length less than 100, to check is it specific e-mail address: ");
    char email[100] = {0};
    scanf("%s", email);

    printf("String %s e-mail address", isEmailAddress(email) ? "is" : "isn't")
    return 0;
}
