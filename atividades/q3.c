#include <stdio.h>

typedef struct no{
    int info;
    struct no *proximo;
    struct no *anterior;
} T_lista;

typedef struct cab_lista{
    struct no *inicio;
    struct no *fim;
    int qtd;
} T_cabeca;

T_cabeca *cabeca;


T_cabeca *iniCabeca(int valor);
void inserir(int valor);

int main(){
    cabeca = iniCabeca(10);
    inserir(30);
    return 0;
}

T_cabeca *iniCabeca(int valor){
    cabeca = (T_cabeca *) malloc(sizeof(struct cab_lista));
    if (cabeca == NULL){ 
        printf("\n Memória insuficiente para alocar estrutura");
        exit(1);
    }
    cabeca->inicio=NULL;
    cabeca->fim=NULL;
    cabeca->qtd=0;
    return cabeca;
}

void inserir(int valor){
    T_lista *novo;

    novo = malloc(sizeof(T_lista));

    novo->info = valor;

    novo->proximo == NULL;

    if (cabeca->fim != NULL){
        cabeca->fim->proximo = novo;
    }
    else{
        cabeca->inicio = novo;
    }

    cabeca->fim = novo;

    cabeca->qtd++;
}