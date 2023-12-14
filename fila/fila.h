#include <stdio.h>

typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct Fila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void criaFila(Fila *f);
int filaVazia(Fila *f);
int tamanhoDaFila(Fila *f);
void exibeFila(Fila *f);
int insereNaFila(Fila *f, int dado);
int removeDaFila(Fila *f);