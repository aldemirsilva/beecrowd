// author: Aldemir Silva  | date: November 3rd 2024

#include <stdio.h>

int main() {
  double x, y;

  scanf("%lf %lf", &x, &y);
  if (x == 0.0f && y == 0.0f)
    printf("Origem\n");

  else if (x > 0.0f && y > 0.0f)
    printf("Q1\n");

  else if (x < 0.0f && y > 0.0f)
    printf("Q2\n");

  else if (x < 0.0 && y < 0.0)
    printf("Q3\n");

  else if (x > 0.0 && y < 0.0)
    printf("Q4\n");

  else if (y == 0.0f)
    printf("Eixo X\n");

  else if (x == 0.0f)
    printf("Eixo Y\n");
  return 0;
}
