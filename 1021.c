// author: Aldemir Silva | date: November 3rd 2024

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *value = malloc(10 * sizeof(char));
  unsigned whole, fraction, current;
  const unsigned notes[] = {100, 50, 20, 10, 5, 2};
  const unsigned coins[] = {100, 50, 25, 10, 5, 1};

  scanf("%s", value);

  whole = atoi(strtok(value, "."));
  fraction = atoi(strtok(NULL, "."));

  current = whole;

  printf("NOTAS:\n");
  for (int i = 0; i < 6; i++) {
    printf("%d nota(s) de R$ %d.00\n", current / notes[i], notes[i]);
    current %= notes[i];
  }

  fraction += current * 100;
  printf("MOEDAS:\n");
  for (int j = 0; j < 6; j++) {
    printf("%d moeda(s) de R$ %.2f\n", fraction / coins[j], (float) (coins[j] / 100.00));
    fraction %= coins[j];
  }
  free(value);
  return 0;
}
