// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>

int main() {
  int hora_inicial, minuto_inicial, hora_final, minuto_final;

  scanf("%d %d %d %d", &hora_inicial, &minuto_inicial, &hora_final, &minuto_final);

  int horas = hora_final - hora_inicial;
  int minutos = minuto_final - minuto_inicial;

  if (horas == 0 && minutos == 0)
    horas = 24;

  if (horas < 0 && minutos > 0)
    horas += 24;

  if (horas > 0 && minutos < 0) {
    horas--;
    minutos += 60;
  }

  if (horas < 0 && minutos < 0) {
    horas += 23;
    minutos += 60;
  }

  if (horas == 0 && minutos < 0) {
    horas = 23;
    minutos += 60;
  }


  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);

  return 0;
}
