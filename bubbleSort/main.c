#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[50];
    float valor_hora;
    int horas_mes;
} Funcionario;

void bubble_sort(int tam, Funcionario *vf){
    Funcionario aux;
    for (int i = 0; i < tam; i++){
        for (int j = 1; j < tam - 1; j++){
            if (strcmp(vf[j-1].nome, vf[j].nome) > 0){
                aux = vf[j];
                vf[j] = vf[j - 1];
                vf[j - 1] = aux;
            }
        }
    }
}

void mostrar_funcionarios(int tam, Funcionario *vf){
    for (int i = 0; i < tam; i++){
        printf("Nome: %s\n", vf[i].nome);
        printf("Valor hora: %.2f\n", vf[i].valor_hora);
        printf("Horas mes: %d\n", vf[i].horas_mes);
        printf("====================================\n");
    }
}

Funcionario *busca_func(int n, Funcionario *vf, char *nome){
    int menor = 0, maior = n-1, meio;

    while (menor <= maior){
        meio = (menor + maior)/2;
        if (strcmp(vf[meio].nome, nome) == 0)
            return &vf[meio];
        else if (strcmp(vf[meio].nome, nome) < 0)
            menor = meio + 1;
        else
            maior = meio - 1;
    }

    return NULL;
}

Funcionario *buscabin_func(int n, Funcionario *vf[], char *nome){
    int menor = 0, maior = n-1, meio;

    while (menor <= maior){
        meio = (menor + maior)/2;
        if (strcmp(vf[meio]->nome, nome) == 0)
            return vf[meio];
        else if (strcmp(vf[meio]->nome, nome) < 0)
            menor = meio + 1;
        else
            maior = meio - 1;
    }

    return NULL;
}

void mostra_funcionario(Funcionario *f){
    if (f == NULL)
        printf("Funcionario nao encontrado\n");
    printf("Nome: %s\n", f->nome);
    printf("Valor hora: %.2f\n", f->valor_hora);
    printf("Horas mes: %d\n", f->horas_mes);
    printf("====================================\n");
}

void mostra_funcionario2(Funcionario **f){
    if (f == NULL)
        printf("Funcionario nao encontrado\n");
    printf("Nome: %s\n", (*f)->nome);
    printf("Valor hora: %.2f\n", (*f)->valor_hora);
    printf("Horas mes: %d\n", (*f)->horas_mes);
    printf("====================================\n");
}

Funcionario *exibe_top3_salarios(int n, Funcionario *vf[]){
    Funcionario *atual;
    int j, i;
    for (int i = 1; i<n; i++){
        atual = vf[i];
        j = i - 1;
        while (j >= 0 && (atual->valor_hora*atual->horas_mes > vf[j]->valor_hora*vf[j]->horas_mes)){
            vf[j + 1] = vf[j];
            j--;
        }
        vf[j + 1] = atual;
    }

    for (int i = 0; i < 3; i++){
        printf("Nome: %s\n", vf[i]->nome);
        printf("Valor hora: %.2f\n", vf[i]->valor_hora);
        printf("Horas mes: %d\n", vf[i]->horas_mes);
        printf("====================================\n");
    }
}

int main(int argc, char const *argv[])
{
    Funcionario *f1 = (Funcionario *) malloc(sizeof(Funcionario));
    Funcionario *f2 = (Funcionario *) malloc(sizeof(Funcionario));
    Funcionario *f3 = (Funcionario *) malloc(sizeof(Funcionario));
    Funcionario *f4 = (Funcionario *) malloc(sizeof(Funcionario));
    Funcionario *vf = (Funcionario *) malloc(sizeof(Funcionario) * 4);

    strcpy(f1->nome, "Joao");
    f1->valor_hora = 10.0;
    f1->horas_mes = 160;

    strcpy(f2->nome, "Maria");
    f2->valor_hora = 15.0;
    f2->horas_mes = 180;

    strcpy(f3->nome, "Ana");
    f3->valor_hora = 20.0;
    f3->horas_mes = 160;

    strcpy(f4->nome, "Pedro");
    f4->valor_hora = 25.0;
    f4->horas_mes = 160;

    vf[0] = *f1;
    vf[1] = *f2;
    vf[2] = *f3;
    vf[3] = *f4;

    mostrar_funcionarios(4, vf);
    bubble_sort(4, vf);
    mostrar_funcionarios(4, vf);

    Funcionario *f = busca_func(4, vf, "Maria");
    mostra_funcionario(f);

    Funcionario *vf2[4];
    vf2[0] = f3;
    vf2[1] = f1;
    vf2[2] = f2;
    vf2[3] = f4;

    Funcionario *f5 = buscabin_func(4, vf2, "Joao");
    mostra_funcionario2(&f5);

    exibe_top3_salarios(4, vf2);

    return 0;
}
