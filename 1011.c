#include <stdio.h>
#include "math.h"

#define PI 3.14159

double area(double raio) {
    return (4.0/3.0)*PI*pow(raio,3);
}

int main(void) {
    double raio;
    scanf("%lf", &raio);
    printf("VOLUME = %.3lf\n", area(raio));
    return 0;
}