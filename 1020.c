#include <stdio.h>

int main() {
  int entrada, anos = 0, meses = 0, dias = 0;
  scanf("%d", &entrada);
  anos = entrada / 365;
  meses = (entrada % 365) / 30;
  dias = (entrada % 365) % 30;
  printf("%d ano(s)\n", anos);
  printf("%d mes(es)\n", meses);
  printf("%d dia(s)\n", dias);
}
