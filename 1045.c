// author: Aldemir Silva | date: November 6th 2024

#include <stdio.h>
#include <stdlib.h>

void insertionSort(double v[], int n) {
  double chave;
  int j;
  for (int i = 1; i < n; i++) {
    chave = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > chave) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = chave;
  }
}

int main() {
  double *v = malloc(sizeof(double) * 3);
  scanf("%lf %lf %lf", &v[0], &v[1], &v[2]);

  insertionSort(v, 3);

  if (v[2] >= v[1] + v[0]) {
    printf("NAO FORMA TRIANGULO\n");
    free(v);
    return 0;
  }
  if (v[2] * v[2] == v[1] * v[1] + v[0] * v[0])
    printf("TRIANGULO RETANGULO\n");
  if (v[2] * v[2] > v[1] * v[1] + v[0] * v[0])
    printf("TRIANGULO OBTUSANGULO\n");
  if (v[2] * v[2] < v[1] * v[1] + v[0] * v[0])
    printf("TRIANGULO ACUTANGULO\n");
  if (v[2] == v[1] && v[1] == v[0]) {
    printf("TRIANGULO EQUILATERO\n");
    free(v);
    return 0;
  }
  if (v[2] == v[1] || v[2] == v[0] || v[1] == v[0])
    printf("TRIANGULO ISOSCELES\n");
  free(v);
  return 0;
}
