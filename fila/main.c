#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Fila f;
    criaFila(&f);
    exibeFila(&f);
    insereNaFila(&f, 1);
    exibeFila(&f);
    insereNaFila(&f, 2);
    exibeFila(&f);
    removeDaFila(&f);
    exibeFila(&f);
    removeDaFila(&f);
    exibeFila(&f);

    return 0;
}
