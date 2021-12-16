#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

double deleteRare(char path[55], double* result) {
    double a;
    int counter = 1;
    int amt = 0;
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

    double* dict = malloc(sizeof(double) * 2);
    if (dict == NULL) {
        printf("Can't locate memory\n");
    }
    int dictCounter = 2;
    int innerCounter = 1;
    dict[0] = dynArr[0];
    for(int i = 0; i < (counter - 1); i++) {
        for(int k = 0; k < dictCounter; k++) {
            if(dict[k] != dynArr[i]) {
                innerCounter += 1;
            }
        }
        if(innerCounter == dictCounter) {
            dict[innerCounter - 1] = dynArr[i];
            dictCounter += 1;
            dict = realloc(dict, sizeof(double) * dictCounter);
        }
        if(innerCounter == 0) {
            break;
        }
        innerCounter = 0;
    }
    int* counter_dict = malloc(sizeof(double) * (dictCounter - 1));
    for(int i = 0; i < (counter - 1); i++) {
        for(int k = 0; k < (dictCounter - 1); k++) {
            if(dynArr[i] == dict[k]) {
                counter_dict[k] += 1;
            }
        }
    }

    int min = 10000000;
    int repeater = 0;
    for(int i = 0; i < (dictCounter - 1); i++) {
        if(min > counter_dict[i]) {
            min = counter_dict[i];
        }
    }

    for(int i = 0; i < (dictCounter - 1); i++) {
        if(min == counter_dict[i]) {
            repeater += 1;
        }
    }
    amt = min * repeater;
    double endSize = (counter - 1) - amt;
    free(dynArr);
    free(dict);
    free(counter_dict);
    *result = endSize;
    return 0;
}