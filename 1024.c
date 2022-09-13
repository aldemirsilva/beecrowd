#include <stdio.h>
#include <stdlib.h>

void inverteLinha(char s[], int n) {
    int i=0, j=n-i-1;
    char *temp;
    while (i < j) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}

int main(void)
{
    int i, linhas;
    scanf("%d", &linhas);
    char *texto = calloc(sizeof(char), 1000*linhas);

    for (i = 0; i < linhas*1000; i+=1000)
        scanf("%[^\n]%*c", &texto[i]);

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 65 && texto[i] <= 122) {
            texto[i] += 3;
        }
    }

    for (i = 0; i < linhas*1000; i+=1000) {
        
    }
}
