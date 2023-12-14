typedef struct funcionario {
    char nome[50];
    float valor_hora;
    int horas_mes;
    char matricula[10];
} Funcionario;

typedef struct noarv {
  struct noarv *esq;
  struct noarv *dir;
  Funcionario dado;
} NoArv;

typedef struct arvore {
  NoArv *raiz;
} Arvore;

void criar(Arvore *a);
void exibir(NoArv *raiz, int n);
// void exibir2(NoArv *r);
int inserir(Arvore *a, Funcionario valor);
NoArv *inserir_rec(NoArv *raiz, Funcionario dado);
void insere(Arvore *a, Funcionario dado);
int busca(NoArv *raiz, char *matricula);
NoArv *sucessor(NoArv *atual);
int remover(Arvore *a, char *matricula);