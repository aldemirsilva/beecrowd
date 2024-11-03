// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>

int main() {
  double n1, n2, n3, n4, media, exame;
  scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
  media = (2.0f * n1 + 3.0f * n2 + 4.0f * n3 + 1.0f * n4) / 10.0f;

  if (media >= 7) {
    printf("Media: %.1lf\n", media);
    printf("Aluno aprovado.\n");
  } else if (media < 5) {
    printf("Media: %.1lf\n", media);
    printf("Aluno reprovado.\n");
  } else if (media >= 5 && media <= 6.9) {
    printf("Media: %.1lf\n", media);
    printf("Aluno em exame.\n");
    scanf("%lf", &exame);
    printf("Nota do exame: %.1lf\n", exame);
    media = (media + exame) / 2;
    if (media >= 5) printf("Aluno aprovado.\n");
    else printf("Aluno reprovado.\n");
    printf("Media final: %.1lf\n", media);
  }
  return 0;
}
