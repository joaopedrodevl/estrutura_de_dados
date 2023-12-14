#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void criaLista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
}

int listaVazia(Lista *l){
    return l->tamanho == 0;
}

int tamanhoDaLista(Lista *l){
    return l->tamanho;
}

void exibeLista(Lista *l){
    printf("[");
    No *aux = l->inicio;
    while (aux != NULL){
        aux->prox == NULL ? printf("%d", aux->dado) : printf("%d, ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}


int insereNoComeco(Lista *l, int dado){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;
    
    if (listaVazia(l)){
        l->inicio = novo;
        l->fim = novo;
    } else {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }

    l->tamanho++;
    return 1;
}

int insereNoFim(Lista *l, int dado){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->ant = l->fim;
    novo->prox = NULL;

    if (listaVazia(l)){
        return insereNoComeco(l, dado);
    } 

    l->fim->prox = novo;
    l->fim = novo;

    l->tamanho++;
    return 1;
}

int insereNaPosicao(Lista *l, int dado, int pos){
    if (pos < 0 || pos > l->tamanho) return -1;

    if (listaVazia(l) || pos == 0){
        if (pos != 0) return -1;
        return insereNoComeco(l, dado);
    }

    if (pos == l->tamanho) return insereNoFim(l, dado);

    No *novo = (No*)malloc(sizeof(No));
    No *aux = l->inicio;

    for (int i = 0; i < pos; i++)
        aux = aux->prox;

    novo->dado = dado;
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant->prox = novo;
    aux->ant = novo;

    l->tamanho++;
    return 1;
}

int removeOPrimeiro(Lista *l){
    if (listaVazia(l)) return -1;

    No *aux = l->inicio;
    l->inicio = aux->prox;

    free(aux);
    l->tamanho--;
    return 1;
}

int removeNoFim(Lista *l){
    if (listaVazia(l)) return -1;

    No *aux = l->fim;
    l->fim = aux->ant;
    l->fim->prox = NULL;

    free(aux);
    l->tamanho--;
    return 1;
}

int removeNaPosicao(Lista *l, int pos){
    if (pos < 0 || pos >= l->tamanho) return -1;
    if (listaVazia(l)) return -1;

    if (pos == 0) return removeOPrimeiro(l);
    if (pos == l->tamanho - 1) return removeNoFim(l);

    No *aux = l->inicio;
    int cont = 0;

    for (int i = 0; i < pos; i++)
        aux = aux->prox;

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;

    free(aux);
    l->tamanho--;
    return 1;
}

int obtemValorPorPosicao(Lista *l, int pos){
    if (pos < 0 || pos >= l->tamanho) return -1;
    if (listaVazia(l)) return -1;

    if (pos == 0) return l->inicio->dado;
    if (pos == l->tamanho-1) return l->fim->dado;

    No *aux = l->inicio;
    int cont = 0;

    for (int i = 0; i < pos+1; i++){
        if (i == pos)
            return aux->dado;
        aux = aux->prox;
    }

    return -1;
}

int obtemPosicaoPorValor(Lista *l, int dado){
    if (listaVazia(l)) return -1;

    No *aux = l->inicio;

    for (int i = 0; i < l->tamanho; i++){
        if (aux->dado == dado)
            return i;
        aux = aux->prox;
    }

    return -1;
}