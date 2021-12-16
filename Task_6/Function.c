#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

double rotate(char path[55], double* result) {
    double a;
    int counter = 1;
    double* dynArr = malloc(sizeof(double) * 1);
    if (dynArr == NULL) {
        printf("Can't locate memory\n");
    }
    FILE* inp = fopen(path, "r");
    if (inp == NULL) {
        printf("Can't open file\n");
        exit(1);
    }
    while (fscanf(inp, "%lf", &a) == 1) {
        dynArr[counter - 1] = a;
        counter += 1;
        dynArr = realloc(dynArr, sizeof(double) * counter);
        if (dynArr == NULL) {
            printf("Can't locate memory\n");
        }
    }
    for(int i = 0; i < counter - 1; i++) {
        printf("%lf ", dynArr[i]);
    }
    printf("\n");
    printf("\n");
    int min_one_index;
    int min_two_index;
    int min_counter = 0;
    for(int i = 1; i < counter - 2; i++) {
        if(dynArr[i] < dynArr[i + 1] && dynArr[i] < dynArr[i - 1]) {
            min_counter += 1;
            if(min_counter % 2 == 1) {
                min_one_index = i;
            }
            else {
                min_two_index = i;
            }
            if(min_counter % 2 == 0) {
                double saver = dynArr[min_one_index];
                dynArr[min_one_index] = dynArr[min_two_index];
                dynArr[min_two_index] = saver;
            }
        }
    }
    for(int i = 0; i < counter - 1; i++) {
        printf("%lf ", dynArr[i]);
    }
    free(dynArr);
    return 0;
}