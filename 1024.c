// author: Aldemir Silva | date: November 3rd 2024

#include <stdio.h>
#include <string.h>

void inverteLinha(char s[], int n) {
  int i = 0, j = n - i - 1;
  if (s) {
    while (i < j) {
      char temp = s[j];
      s[j] = s[i];
      s[i] = temp;
      i++;
      j--;
    }
  }
}

int main() {
  static char linha[1001];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%*c%[^\n]", linha);
    int tam = strlen(linha);

    for (int j = 0; j < tam; j++) {
      if ((65 <= linha[j] && linha[j] <= 90) || (97 <= linha[j] && linha[j] <= 122))
        linha[j] += 3;
    }

    inverteLinha(linha, tam);

    for (int k = tam / 2; k < tam; k++)
      if (32 <= linha[k] <= 126)
        linha[k] -= 1;

    printf("%s\n", linha);
    memset(linha, 0, tam);
  }
  return 0;
}
