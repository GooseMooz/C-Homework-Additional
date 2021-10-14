#include <stdio.h>
#include "Header.h"

int main(void) {
    double result;
    isProgression("C:\\Users\\user\\CLionProjects\\MSU\\Task_4\\data.txt", &result);
    if (result == 1) {
        printf("True");
    }
    else {
        printf("False");
    }
    return 0;
}