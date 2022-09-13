#include <stdio.h>

int main(void) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int horas = c-a;
    if (!horas) horas = 24;
    int minutos = d-b;
    if (minutos < 0) {
        horas += minutos;
        minutos += 60;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
    return 0;
}