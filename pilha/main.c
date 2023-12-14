#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Pilha p;
    criaPilha(&p);
    exibePilha(&p);
    insereNaPilha(&p, 10);
    insereNaPilha(&p, 20);
    insereNaPilha(&p, 30);
    removeDaPilha(&p);
    removeDaPilha(&p);
    removeDaPilha(&p);
    insereNaPilha(&p, 10);
    insereNaPilha(&p, 20);
    insereNaPilha(&p, 30);
    exibePilha(&p);

    return 0;
}
