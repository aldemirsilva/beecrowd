// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *valor = malloc(10 * sizeof(char));
  unsigned inteiro, fracao, atual;
  const unsigned notas[] = {100, 50, 20, 10, 5, 2};
  const unsigned moedas[] = {100, 50, 25, 10, 5, 1};

  scanf("%s", valor);

  inteiro = atoi(strtok(valor, "."));
  fracao = atoi(strtok(NULL, "."));

  atual = inteiro;

  printf("NOTAS:\n");
  for (int i = 0; i < 6; i++) {
    printf("%d nota(s) de R$ %d.00\n", atual / notas[i], notas[i]);
    atual %= notas[i];
  }

  fracao += atual * 100;
  printf("MOEDAS:\n");
  for (int j = 0; j < 6; j++) {
    printf("%d moeda(s) de R$ %.2f\n", fracao / moedas[j], (float) (moedas[j] / 100.00));
    fracao %= moedas[j];
  }
  free(valor);
  return 0;
}
