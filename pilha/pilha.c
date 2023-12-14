#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void criaPilha(Pilha *p)
{
    p->topo = NULL;
    p->tamanho = 0;
}

int pilhaVazia(Pilha *p)
{
    return p->tamanho == 0;
}

int tamanhoDaPilha(Pilha *p)
{
    return p->tamanho;
}

void exibePilha(Pilha *p)
{
    printf("[");
    No *aux = p->topo;
    while (aux != NULL)
    {
        aux->ant == NULL ? printf("%d", aux->dado) : printf("%d, ", aux->dado);
        aux = aux->ant;
    }
    printf("]\n");
}

int insereNaPilha(Pilha *p, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    novo->ant = p->topo;
    p->topo = novo;

    p->tamanho++;
    return 1;
}

int removeDaPilha(Pilha *p)
{
    if (pilhaVazia(p))
        return -1;

    No *aux = p->topo;
    p->topo = aux->ant;

    p->tamanho--;
    free(aux);
    return 1;
}