#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(void) {
    double lambda, sum = 0, s, div;
    int a;
    scanf("%lf", &lambda);
    if (lambda <= 0 || lambda >= 1) {
        printf("Lambda bad\n");
        return 0;
    }

    FILE* inp = fopen("data.txt", "r");
    int counter = 0;
    if (inp == NULL) {
        printf("Can't open file\n");
        fclose(inp);
        return 1;
    }
    while (fscanf(inp, "%d", &a) == 1) {
        sum += a;
        sum *= lambda;
        counter += 1;
    }
    sum /= lambda;
    div = (1 - lambda) * (1 - pow(lambda, counter));
    s = div * sum;
    fclose(inp);
    printf("Answer: %lf", s);
    return 505;
}
