// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>

int main() {
  int tempo, horas = 0, minutos = 0, segundos = 0;
  scanf("%d", &tempo);
  horas = tempo / 3600;
  minutos = (tempo % 3600) / 60;
  segundos = tempo % 60;
  printf("%d:%d:%d\n", horas, minutos, segundos);
  return 0;
}
