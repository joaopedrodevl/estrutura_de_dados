#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void criaFila(Fila *f)
{
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
}

int filaVazia(Fila *f)
{
    return f->tamanho == 0;
}

int tamanhoDaFila(Fila *f)
{
    return f->tamanho;
}

void exibeFila(Fila *f)
{
    printf("[");
    No *aux = f->inicio;
    while (aux != NULL)
    {
        aux->prox == NULL ? printf("%d", aux->dado) : printf("%d, ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}

int insereNaFila(Fila *f, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;

    if (f->tamanho == 0){
        f->inicio = novo;
        f->fim = novo;
    } else {
        novo->ant = f->fim;
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tamanho++;
    return 1;
}

int removeDaFila(Fila *f)
{
    if (filaVazia(f))
        return -1;
    
    No *aux = f->inicio;
    f->inicio = aux->prox;

    free(aux);
    f->tamanho--;
    return 1;
}