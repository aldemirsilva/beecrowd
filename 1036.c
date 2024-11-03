// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, delta, raiz1, raiz2;
  scanf("%lf %lf %lf", &a, &b, &c);

  delta = pow(b, 2) - 4 * a * c;
  if (delta < 0 || a == 0)
    printf("Impossivel calcular\n");
  else {
    raiz1 = (-b + sqrt(delta)) / (2 * a);
    raiz2 = (-b - sqrt(delta)) / (2 * a);
    printf("R1 = %.5lf\n", raiz1);
    printf("R2 = %.5lf\n", raiz2);
  }
  return 0;
}
