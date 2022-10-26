#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long int iterationFibonacci(unsigned number) {
    if (number == 0) {
        return 0;
    }
    unsigned long int back = 0;
    unsigned long int next = 1;

    for (int i = 2; i < number; ++i) {
        unsigned long int temp = next;
        next += back;
        back = temp;
    }

    return next;
}

int evenFibonacci(void) {
    const int maxValue = 1000000;
    int number = 0;
    int sum = 0;
    int i = 0;

    while (number < maxValue) {
        if (number % 2 == 0) {
            sum +=number;
        }
        ++i;
        number = iterationFibonacci(i);
    }

    return sum;
}

bool correctTestIteration(void) {
    const int rightAnswer = 1089154;
    int answer = evenFibonacci();

    return answer == rightAnswer;
}
//4613732
int main() {
    if (!correctTestIteration()) {
        printf("Test failed");
        return 1;
    }

    printf("Sum of even fibonacci numbers: %d", evenFibonacci());

    return 0;
}
