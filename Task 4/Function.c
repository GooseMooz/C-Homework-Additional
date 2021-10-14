#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

double isProgression(char path[55], double* result) {
    double is = 0;
    double a;
    int counter = 1;
    double* dynArr = malloc(sizeof(double) * 1);
    FILE* inp = fopen(path, "r");
    if (inp == NULL) {
        printf("Can't open file\n");
        exit(1);
    }
    while (fscanf(inp, "%lf", &a) == 1) {
        dynArr[counter - 1] = a;
        counter += 1;
        dynArr = realloc(dynArr, sizeof(double) * counter);
    }
    double d = dynArr[1] - dynArr[0];
    int cnt = 0;
    for (int i = 1; i < counter; i++) {
        if (dynArr[i] - dynArr[i - 1] == d) {
            cnt += 1;
        }
    }
    free(dynArr);
    if (cnt + 2 == counter) {
        is = 1;
    }
    *result = is;
    return 0;
}