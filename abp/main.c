#include "arv.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Arvore arv;
    criar(&arv);
   
    Funcionario f1 = {"Joao", 10.0, 100, "123"};
    Funcionario f2 = {"Maria", 10.0, 100, "456"};
    Funcionario f3 = {"Jose", 10.0, 100, "789"};
    Funcionario f4 = {"Ana", 10.0, 100, "101"};
    Funcionario f5 = {"Pedro", 10.0, 100, "112"};
    Funcionario f6 = {"Paulo", 10.0, 100, "131"};

    insere(&arv, f1);
    insere(&arv, f2);
    insere(&arv, f3);
    insere(&arv, f4);
    insere(&arv, f5);
    insere(&arv, f6);
    exibir(arv.raiz, 0);

    printf("%d\n", busca(arv.raiz, "112"));
    printf("%d\n", busca(arv.raiz, "100"));

    printf("%d\n", remover(&arv, "112"));

    return 0;
}
