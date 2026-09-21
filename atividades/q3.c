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


T_cabeca *iniCabeca();
void inserirDepois(int valor);
void inserirAntes(int valor);

int main(){
    int valor, escolha;

    do{
        printf("Escolha onde irá inserir (1 - Antes | 2 - Depois | 3 - Parar): ");
        scanf("%d", &escolha);
        printf("Escolha o valor: ");
        scanf("%d", &valor);

        if (escolha == 1){
            inserirAntes(valor);
        }
        else if (escolha == 2){
            inserirDepois(valor);
        }

    } while (escolha != 3);

    cabeca = iniCabeca();
    inserirDepois(valor);
    inserirAntes(valor);

    return 0;
}

T_cabeca *iniCabeca(){
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

void inserirDepois(int valor){
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

void inserirAntes(int valor){
    T_lista *novo;

    novo = malloc(sizeof(T_lista));

    novo->info = valor;
    novo->anterior = NULL;
    novo->proximo = cabeca->inicio;

    if(cabeca->inicio != NULL){
        cabeca->inicio->anterior = novo;
    }
    else{
        cabeca->fim = novo;
    }

    cabeca->inicio = novo;
    cabeca->qtd++;
}

void excluir(int valor){
    int verifi = 0;
    T_lista *atual = cabeca->inicio;
    T_lista *aux;
    
    while (atual != NULL){
        if(atual->info == valor){
            verifi = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (verifi == 1){
        
        if (atual->proximo == NULL && atual->anterior == NULL){
            cabeca->inicio = NULL;
            cabeca->fim = NULL;
        }
        else{
            if (atual == cabeca->inicio){
            cabeca->inicio = atual->proximo;
            cabeca->inicio->anterior = atual->anterior;
            }
            else if (atual == cabeca->fim){
                cabeca->fim = atual->anterior;
                cabeca->fim->proximo = atual->proximo;
            }
            else{
                aux = atual->anterior;
                aux->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;

            }
        }
        
        free(atual);
    }
}