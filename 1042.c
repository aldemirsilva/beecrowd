// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d\n", v[i]);
}

int compara(const void *a, const void *b) {
  int l = *(int*) a;
  int r = *(int*) b;
  return l - r;
}

int main() {
  int *vetor = malloc(sizeof(int) * 3), *vetorOrd = malloc(sizeof(int) * 3);

  scanf("%d %d %d", &vetor[0], &vetor[1], &vetor[2]);

  for (int i = 0; i < 3; i++)
    vetorOrd[i] = vetor[i];

  qsort(vetorOrd, 3, sizeof(int), compara);
  imprimeVetor(vetorOrd, 3);
  printf("\n");
  imprimeVetor(vetor, 3);
  free(vetorOrd);
  free(vetor);
  return 0;
}
