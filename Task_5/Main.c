#include <stdio.h>
#include "Header.h"

int main(void) {
    double result;
    deleteRare("C:\\Users\\user\\CLionProjects\\MSU\\Task_5\\data.txt", &result);
    printf("%lf", result);
    return 0;
}