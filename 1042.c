#include <stdio.h>
#include <stdlib.h>

void ordenaInsercao(int v[], int tamanho)
{
    int i, j, chave;
    
    for(j = 1; j < tamanho; j++ )
    {
        i = j-1;
        chave = v[j];
        while(i >= 0 && v[i] > chave)
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = chave;
    }
}

// Função que recebe um vetor e o tamanho do vetor como entradas e imprime o conteúdo do vetor
void imprimeVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", v[i]);
}

int main()
{
    // Declara os ponteiros para inteiro que serão os endereços iniciais dos vetores
    int *vetor, *vetorOrd;

    // Aloca espaço para armazenar os 3 inteiros de que a solução necessita
    vetor = (int *) malloc(3*sizeof(int));
    vetorOrd = (int *) malloc(3*sizeof(int));

    // Lê 3 inteiros do stream de entrada padrão e faz com que o vetor "vetor" aponte para cada um deles
    scanf("%d %d %d", &vetor[0], &vetor[1], &vetor[2]);

    // Copia os "vetor" para o "vetorOrd"
    for (int i = 0; i < 3; i++) vetorOrd[i] = vetor[i];

    // Ordena o vetor utilizando o método insertion sort
    ordenaInsercao(vetorOrd, 3);

    // Imprime o vetor ordenado
    imprimeVetor(vetorOrd, 3);
    printf("\n");
    
    // Imprime o vetor na ordem em que foi lido (antes de a ordenação ter sido executada)
    imprimeVetor(vetor, 3);
    
    // Libera os espaços alocados dinamicamente para evitar vazamento de memória
    free(vetor);
    free(vetorOrd);
    return 0;
}
