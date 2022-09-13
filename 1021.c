/* Problema 1021 do beecrowd */

#include<stdio.h>
#define NO_OF_BILLS 6
#define NO_OF_COINS 6

int main()
{
    int contCedulas[NO_OF_BILLS] = {0}, contMoedas[NO_OF_COINS] = {0}, indice;
    
    double cedulas[] = {100.00f, 50.00f, 20.00f, 10.00f, 5.00f, 2.00f},
    moedas[] = {1.00f, 0.50f, 0.25f, 0.10f, 0.05f, 0.01f}, valor;
	
    scanf("%lf", &valor);

    for (indice = 0; indice < NO_OF_BILLS; indice++)
    {
        while (cedulas[indice] <= valor)
        {
            valor -= cedulas[indice];
            contCedulas[indice]++;
        }
    }

    for (indice = 0; indice < NO_OF_COINS; indice++)
    {
        while (moedas[indice] <= valor)
        {
            valor -= moedas[indice];
            contMoedas[indice]++;
        }
    }

    printf("NOTAS:\n");
    for(indice = 0; indice < NO_OF_BILLS; indice++)
        printf("%d nota(s) de R$ %.2f\n", contCedulas[indice], cedulas[indice]);
    printf("MOEDAS:\n");
    for (indice = 0; indice < NO_OF_COINS; indice++)
        printf("%d moeda(s) de R$ %.2f\n", contMoedas[indice], moedas[indice]);
}
