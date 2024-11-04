#include <stdio.h>

int main() {
  int cod, qtd;

  scanf("%d %d", &cod, &qtd);

  switch (cod) {
    case 1:
      printf("Total: R$ %.2lf\n", (double) (4.00f * qtd));
      break;

    case 2:
      printf("Total: R$ %.2lf\n", (double) (4.50f * qtd));
      break;

    case 3:
      printf("Total: R$ %.2lf\n", (double) (5.00f * qtd));
      break;

    case 4:
      printf("Total: R$ %.2lf\n", (double) (2.00f * qtd));
      break;

    case 5:
      printf("Total: R$ %.2lf\n", (double) (1.50f * qtd));
      break;

    default:
      break;
  }
  return 0;
}
