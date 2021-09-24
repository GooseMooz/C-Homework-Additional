#include "stdio.h"
#include "Header.h"

int main(void) {
    double result;
    MaxContinuingSum("data.txt", &result);
    printf("%lf", result);
    return 0;
}