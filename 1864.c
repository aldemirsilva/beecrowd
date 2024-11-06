// author: Aldemir Silva | date: November 6th 2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int c;
  scanf("%d", &c);
  char *q = malloc(sizeof(char) * 35);
  strcpy(q, "LIFE IS NOT A PROBLEM TO BE SOLVED");
  for (int i = 0; i < c; i++)
    printf("%c", q[i]);
  printf("\n");
  free(q);
}
