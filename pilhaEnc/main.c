#include "pilhaenc.h"
#include <stdio.h>

void limparTela()
{
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

    system(CLEAR);
}

void menu()
{
    printf("\nEditor de Pilha v1.0\n");
    printf("========================\n");
    printf("1- Inicializar\n");
    printf("2- Empilhar\n");
    printf("3- Desempilhar\n");
    printf("4- Elemento do topo\n");
    printf("5- Imprimir pilha\n");
    printf("6- Inverter elementos da pilha\n");
    printf("7- Esvaziar a pilha\n");
    printf("8- Mudar de pilha\n");
    printf("0- Sair\n");
}

int main(int argc, char const *argv[])
{
    PilhaEnc p1, p2, p3;
    int opcao, valor, dadoParamentro, pilhaAtual = 1, retorno, confirmacao, p1Iniciada = 0, p2Iniciada = 0, p3Iniciada = 0;

    do {
        menu();
        printf("Digite a opção: [ ]");
        scanf("%d", &opcao);
        limparTela();
        printf("Opcao escolhida: [%d]\n", opcao);

        switch(opcao){
            case 1:
                if(pilhaAtual == 1 && p1Iniciada == 0){
                    criarPilha(&p1);
                    p1Iniciada = 1;
                    printf("Pilha 1 inicializada!\n");
                }
                else if(pilhaAtual == 2 && p2Iniciada == 0){
                    criarPilha(&p2);
                    p2Iniciada = 1;
                    printf("Pilha 2 inicializada!\n");
                }
                else if(pilhaAtual == 3 && p3Iniciada == 0){
                    criarPilha(&p3);
                    p3Iniciada = 1;
                    printf("Pilha 3 inicializada!\n");
                }
                else
                    printf("Pilha já iniciada!\n");
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if(pilhaAtual == 1 && p1Iniciada == 1){
                    empilhar(&p1, valor);
                    printf("Valor empilhado!\n");
                }
                else if(pilhaAtual == 2 && p2Iniciada == 1){
                    empilhar(&p2, valor);
                    printf("Valor empilhado!\n");
                }
                else if(pilhaAtual == 3 && p3Iniciada == 1){
                    empilhar(&p3, valor);
                    printf("Valor empilhado!\n");
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            case 3:
                if(pilhaAtual == 1 && p1Iniciada == 1){
                    retorno = desempilhar(&p1, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Valor desempilhado: %d\n", dadoParamentro);
                    }
                }
                else if(pilhaAtual == 2 && p2Iniciada == 1){
                    desempilhar(&p2, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Valor desempilhado: %d\n", dadoParamentro);
                    }
                }
                else if(pilhaAtual == 3 && p3Iniciada == 1){
                    desempilhar(&p3, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Valor desempilhado: %d\n", dadoParamentro);
                    }
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            case 4:
                if(pilhaAtual == 1){
                    retorno = topo(p1, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Topo: %d\n", dadoParamentro);
                    }
                }
                else if(pilhaAtual == 2){
                    retorno = topo(p2, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Topo: %d\n", dadoParamentro);
                    }
                }
                else if(pilhaAtual == 3){
                    retorno = topo(p3, &dadoParamentro);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Topo: %d\n", dadoParamentro);
                    }
                }
                else
                    printf("Pilha invalida!\n");
                break;
            case 5:
                if(pilhaAtual == 1 && p1Iniciada == 1){
                    retorno = exibir(p1);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    }
                }
                else if(pilhaAtual == 2 && p2Iniciada == 1){
                    retorno = exibir(p2);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    }
                }
                else if(pilhaAtual == 3 && p3Iniciada == 1){
                    retorno = exibir(p3);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    }
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            case 6:
                if(pilhaAtual == 1 && p1Iniciada == 1){
                    retorno = inverter(&p1);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha invertida!\n");
                    }
                }
                else if(pilhaAtual == 2 && p2Iniciada == 1){
                    retorno = inverter(&p2);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha invertida!\n");
                    }
                }
                else if(pilhaAtual == 3 && p3Iniciada == 1){
                    retorno = inverter(&p3);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha invertida!\n");
                    }
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            case 7:
                printf("Deseja esvaziar a pilha? [1 - Sim | 2 - Não]: ", confirmacao);
                scanf("%d", &confirmacao);
                if(confirmacao != 1){
                    printf("Operação cancelada!\n");
                    break;
                }
                if(pilhaAtual == 1 && p1Iniciada == 1){
                    retorno = esvaziar(&p1);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha esvaziada!\n");
                    }
                }
                else if(pilhaAtual == 2 && p2Iniciada == 1){
                    retorno = esvaziar(&p2);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha esvaziada!\n");
                    }
                }
                else if(pilhaAtual == 3 && p3Iniciada == 1){
                    retorno = esvaziar(&p3);
                    if (retorno == -1) {
                        printf("Pilha vazia!\n");
                    } else {
                        printf("Pilha esvaziada!\n");
                    }
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            case 8:
                printf("Digite a pilha: ");
                scanf("%d", &pilhaAtual);
                if(pilhaAtual == 1){
                    printf("Pilha 1 selecionada!\n");
                }
                else if(pilhaAtual == 2){
                    printf("Pilha 2 selecionada!\n");
                }
                else if(pilhaAtual == 3){
                    printf("Pilha 3 selecionada!\n");
                }
                else
                    printf("Pilha não iniciada!\n");
                break;
            default:
                if (opcao != 0){
                    printf("Opcao invalida!\n");
                    break;
                }
                printf("Saindo...\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}