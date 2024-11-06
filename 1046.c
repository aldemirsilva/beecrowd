// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>

int main() {
  int hora_inicial, hora_final;

  scanf("%d %d", &hora_inicial, &hora_final);

  int horas = hora_final - hora_inicial;

  if (horas < 0)
    horas += 24;

  if (horas == 0)
    horas = 24;

  printf("O JOGO DUROU %d HORA(S)\n", horas);

  return 0;
}