#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long int iterationFibonacci(unsigned number) {
    if (number == 0) {
        return 0;
    }
    unsigned long int back = 0;
    unsigned long int next = 1;

    for (int i = 1; i < number; ++i) {
        unsigned long int temp = next;
        next += back;
        back = temp;
    }

    return next;
}

short checkForRules(int *number, int fibonacci) {
    *number = iterationFibonacci(fibonacci);

    if (*number > 1000000) {
        return -1;
    }
    return (*number % 2) ? 0 : 1;
}

bool correctTestIteration(void) {
    return !iterationFibonacci(0) && iterationFibonacci(1) == 1 && iterationFibonacci(10) == 55 && iterationFibonacci(25) == 75025;
}
//4613732
int main() {
    int sum = 0;
    for (int i = 1; i < 1000; ++i) {
        int number = iterationFibonacci(i);
        if (number <= 1000000 && !(number % 2)) {
            printf("%d \n", number);
            sum += number;
        } else if (number > 1000000) {
            break;
        }

    }
    printf("%d", sum);
    return 0;
}
