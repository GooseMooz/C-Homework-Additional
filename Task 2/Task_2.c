#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double fileopen(double x) {
    double a;
    double ans = 0;
    FILE* inp = fopen("C:\\Users\\user\\CLionProjects\\MSU\\data.txt", "r");
    if (inp == NULL) {
        printf("Can't open file\n");
        fclose(inp);
        return 1;
    }
    while (fscanf(inp, "%lf", &a) == 1) {
        ans += a * a * pow(x, a - 1);
    }
    fclose(inp);
    return ans;
}

int main(void) {
    double input;
    scanf("%lf", &input);
    double answer = fileopen(input);
    printf("%lf", answer);
}