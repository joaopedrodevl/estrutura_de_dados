#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ordena_selecao(int tam, char vetor[tam][5])
{
    int i, j, min;
    char aux[5];

    for (i = 0; i < tam - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tam; j++)
        {
            if (strcmp(vetor[j], vetor[min]) < 0)
            {
                min = j;
            }
        }
        if (i != min)
        {
            strcpy(aux, vetor[min]);
            strcpy(vetor[min], vetor[i]);
            strcpy(vetor[i], aux);
        }
    }
}

void mostra_vetor(int tam, char vetor[tam][5])
{
    for (int i = 0; i < tam; i++)
    {
        printf("%s\n", vetor[i]);
    }
}

int main(int argc, char const *argv[])
{
    // Vetor de strings com input por scanf
    int tam = 0;
    scanf("%d", &tam);
    char vetor[tam][5];
    char str[5];

    for (int i = 0; i < tam; i++)
    {
        scanf("%s", vetor[i]);
    }

    ordena_selecao(tam, vetor);
    mostra_vetor(tam, vetor);

    return 0;
}
