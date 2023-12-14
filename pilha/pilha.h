#include <stdio.h>

typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
    int tamanho;
} Pilha;

void criaPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int tamanhoDaPilha(Pilha *p);
void exibePilha(Pilha *p);
int insereNaPilha(Pilha *p, int dado);
int removeDaPilha(Pilha *p);