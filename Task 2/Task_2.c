#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double fileopen(double x, double* summary, double* answer) {
    double a;
    double ans = 0;
    double sum = 0;
    double counter = 0;
    FILE* inp = fopen("data.txt", "r");
    if (inp == NULL) {
        printf("Can't open file\n");
        fclose(inp);
        return 1;
    }
    while (fscanf(inp, "%lf", &a) == 1) {
        sum += a * pow(x, counter);
        if (counter != 0) {
            ans += a * counter * pow(x, counter - 1);
        }
        counter += 1;
    }
    *summary = sum;
    *answer = ans;
    fclose(inp);
    return 0;
}

int main(void) {
    double input, sum, der;
    scanf("%lf", &input);
    fileopen(input, &sum, &der);
    printf("%lf \n", sum);
    printf("%lf", der);
}
