#include "arv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar(Arvore *a) { a->raiz = NULL; }

// in-ordem
/*void exibir2(NoArv *r){
  if (r!=NULL){
    exibir2(r->esq);
    printf("%d ",r->dado);
    exibir2(r->dir);
  }
}*/

void exibir(NoArv *r, int n)
{
    if (r != NULL)
    {
        char galho[] = "---";
        exibir(r->esq, n + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%s", galho);
        }
        printf("%s\n", r->dado.matricula);
        exibir(r->dir, n + 1);
    }
}

NoArv *inserir_rec(NoArv *raiz, Funcionario dado)
{
    if (raiz == NULL)
    {
        NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
        novo->dado = dado;
        novo->esq = novo->dir = NULL;
        raiz = novo;
    }
    else
    {
        if (strcmp(dado.matricula, raiz->dado.matricula) < 0)
        {
            raiz->esq = inserir_rec(raiz->esq, dado);
        }
        else
        {
            if (strcmp(dado.matricula, raiz->dado.matricula) > 0)
                raiz->dir = inserir_rec(raiz->dir, dado);
            else return NULL;
        }
    }
    return raiz;
}

void insere(Arvore *a, Funcionario dado) { a->raiz = inserir_rec(a->raiz, dado); }

int inserir(Arvore *a, Funcionario valor)
{
    NoArv *novo = malloc(sizeof(NoArv));
    // arvore vazia
    if (novo == NULL)
        return 0;
    novo->dado = valor;
    novo->esq = novo->dir = NULL;
    if (a->raiz == NULL)
    {
        a->raiz = novo;
        return 1;
    }
    // arvore com elementos
    NoArv *atual = a->raiz;
    NoArv *anterior = NULL;
    while (atual != NULL)
    {
        anterior = atual;
        if (strcmp(valor.matricula, atual->dado.matricula) == 0)
            return 0;
        if (strcmp(valor.matricula, atual->dado.matricula) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    // indicando a posicao do novo no
    if (strcmp(valor.matricula, anterior->dado.matricula) > 0)
        anterior->dir = novo;
    else
        anterior->esq = novo;
    return 1;
}

int busca(NoArv *raiz, char *matricula)
{
    NoArv *atual = raiz;
    while (atual != NULL)
    {
        if (strcmp(matricula, atual->dado.matricula) == 0)
            return 1;
        if (strcmp(matricula, atual->dado.matricula) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

NoArv *sucessor(NoArv *atual)
{
    NoArv *pai = atual;

    atual = atual->esq;
    if (atual->dir == NULL)
    {
        return atual;
    }

    while (atual->dir != NULL)
    {
        pai = atual;
        atual = atual->dir;
    }

    NoArv *aux = pai->dir;
    pai->dir = NULL;
    return aux;
}

int remover(Arvore *a, char *matricula)
{
    if (busca(a->raiz, matricula) == 0)
        return 0;

    // Procura o elemento a ser deletado
    NoArv *atual = a->raiz;
    NoArv *pai = atual;
    while (strcmp(matricula, atual->dado.matricula) != 0)
    {
        pai = atual;
        if (strcmp(matricula, atual->dado.matricula) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    // No folha
    if (atual->dir == NULL && atual->esq == NULL)
    {
        if (atual == a->raiz)
        {
            free(atual); // raiz
            a->raiz = NULL;
        }
        else
        {
            if (strcmp(pai->dir->dado.matricula, matricula) == 0)
            {
                free(pai->dir); // free(atual)
                pai->dir = NULL;
            }
            else
            {
                free(pai->esq); // free(atual)
                pai->esq = NULL;
            }
        }
        return 1;
    }

    // No so com filho da direita
    if (atual->dir != NULL && atual->esq == NULL)
    {
        if (atual == a->raiz)
        {
            a->raiz = atual->dir;
            free(atual);
        }
        else if (strcmp(pai->dir->dado.matricula, matricula) == 0)
        {
            NoArv *temp = pai->dir;
            pai->dir = atual->dir;
            free(temp);
        }
        else
        {
            NoArv *temp = pai->esq;
            pai->esq = atual->dir;
            free(temp);
        }
        return 1;
    }

    // No so com filho da esquerda
    if (atual->dir == NULL && atual->esq != NULL)
    {
        if (atual == a->raiz)
        {
            a->raiz = atual->esq;
            free(atual);
        }
        else if (strcmp(pai->dir->dado.matricula, matricula) == 0)
        {
            NoArv *temp = pai->dir;
            pai->dir = atual->esq;
            free(temp);
        }
        else
        {
            NoArv *temp = pai->dir;
            pai->esq = atual->esq;
            free(temp);
        }

        return 1;
    }

    // No com filho a direita e esquerda
    if (atual->dir != NULL && atual->esq != NULL)
    {
        NoArv *suc = sucessor(atual);
        if (atual == a->raiz)
            a->raiz = suc;
        else if (strcmp(pai->dir->dado.matricula, matricula) == 0)
            pai->dir = suc;
        else
            pai->esq = suc;
        suc->dir = atual->dir;
        if (atual->esq != suc)
            suc->esq = atual->esq;
        NoArv *temp = atual;
        free(temp);
    }
    return 1;
}
