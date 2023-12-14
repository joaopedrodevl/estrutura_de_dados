#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Lista l;
    criaLista(&l);
    exibeLista(&l);
    insereNoFim(&l, 1);
    exibeLista(&l);
    insereNoComeco(&l, 11);
    insereNoFim(&l, 12);
    insereNaPosicao(&l, 145, 1);
    insereNaPosicao(&l, 139, 2);
    exibeLista(&l);
    removeNaPosicao(&l, 1);
    removeNaPosicao(&l, 0);
    exibeLista(&l);
    printf("Valor por posicao: %d", obtemValorPorPosicao(&l, 0));
    printf("Posicao do valor: %d", obtemPosicaoPorValor(&l, 1));

    return 0;
}
