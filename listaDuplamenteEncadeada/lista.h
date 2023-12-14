#include <stdio.h>

typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
    int posicaoPositiva;
    int posicaoNegativa;
} No;

typedef struct lista {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void criaLista(Lista *l);
int listaVazia(Lista *l);
int tamanhoDaLista(Lista *l);
void exibeLista(Lista *l);
int insereNoComeco(Lista *l, int dado);
int insereNoFim(Lista *l, int dado);
int insereNaPosicao(Lista *l, int dado, int pos);
int removeOPrimeiro(Lista *l);
int removeNoFim(Lista *l);
int removeNaPosicao(Lista *l, int pos);
int obtemValorPorPosicao(Lista *l, int pos);
int obtemPosicaoPorValor(Lista *l, int dado);