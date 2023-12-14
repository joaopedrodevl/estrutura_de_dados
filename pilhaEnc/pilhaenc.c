#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

void criarPilha(PilhaEnc *p){
    p->topo = NULL;
}

int pilhaVazia(PilhaEnc p){
    return p.topo == NULL;
}

int tamanhoPilha(PilhaEnc p){
    No *aux = p.topo;

    int i = 0;
    for (; aux != NULL; aux = aux->prox)
        i++;

    return i;
}

int empilhar(PilhaEnc *p, int dado){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;

    if (pilhaVazia(*p)){
        p->topo = novo;
        return 1;
    }

    novo->prox = p->topo;
    p->topo = novo;
    return 1;
}

int desempilhar(PilhaEnc *p, int *dado){
    if (pilhaVazia(*p)) {
        *dado = 0;
        return -1;
    };

    No *aux = p->topo;
    *dado = aux->dado;
    p->topo = aux->prox;

    free(aux);
    return 1;
}

int topo(PilhaEnc p, int *dado){
    if (pilhaVazia(p)) {
        *dado = 0;
        return -1;
    }

    *dado = p.topo->dado;
    return 1;
}

int exibir(PilhaEnc p){
    if (pilhaVazia(p))
        return -1;
    No *aux = p.topo;

    printf("[");
    while (aux != NULL){
        aux->prox == NULL ? printf("%d", aux->dado) : printf("%d, ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
    return 1;
}

int inverter(PilhaEnc *p){
    if (pilhaVazia(*p))
        return -1;

    PilhaEnc p2;
    criarPilha(&p2);

    while(!pilhaVazia(*p)){
        int dado;
        desempilhar(p, &dado);
        empilhar(&p2, dado);
    }

    *p = p2;

    return 1;
}

int esvaziar(PilhaEnc *p){
    if (pilhaVazia(*p))
        return -1;

    while(!pilhaVazia(*p)){
        int dado;
        desempilhar(p, &dado);
    }

    return 1;
}