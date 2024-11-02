#include <stdio.h>
#define NO_OF_BILLS 7

int main() {
  int contagem[7] = {0}, indice, valor, cedulas[] = {100, 50, 20, 10, 5, 2, 1}, resposta;
  scanf("%d", &valor);
  resposta = valor;
  for (indice = 0; indice < NO_OF_BILLS; indice++) {
    while (cedulas[indice] <= valor) {
      valor -= cedulas[indice];
      contagem[indice]++;
    }
  }
  printf("%d\n", resposta);
  for (indice = 0; indice < NO_OF_BILLS; indice++)
    printf("%d nota(s) de R$ %d,00\n", contagem[indice], cedulas[indice]);
}
