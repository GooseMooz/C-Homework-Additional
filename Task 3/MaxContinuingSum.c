#include "Header.h"
#include "stdio.h"
#include "stdlib.h"

double MaxContinuingSum(char path[9], double* result) {
    double a;
    double sumMax = 0;
    double sumCur = 0;
    FILE* inp = fopen(path, "r");
    if (inp == NULL) {
        printf("Can't open file\n");
        exit(1);
    }
    while (fscanf(inp, "%lf", &a) == 1) {
        double sumPrev = sumCur;
        sumCur += a;
        if (sumMax < sumCur) {
            sumMax = sumCur;
        }
        if (sumCur <= 0) {
            sumCur = 0;
        }
    }
    *result = sumMax;
    return 0;
}
