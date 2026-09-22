#include <stdio.h>

typedef struct no{
    int info;
    struct no *proximo;
} T_lista;

typedef struct cab_lista{
    struct no *inicio;
    struct no *fim;
} T_cabeca;

void q4(T_cabeca *cabeca){
    T_lista *aux;
    aux = cabeca->inicio;
    int ant, atu, r;
    while (aux != NULL){
        ant = 1;
        atu = 1;
        r = 1;
        while(r < aux->info ){
            ant = atu;
            atu = r;
            r = ant + atu;
        }
        if (r == aux->info){
            remove(cabeca, r);
        }
        aux = aux->proximo;
    }
    aux = cabeca->inicio;
    printf("\nElementos da lista:");
    while(aux != NULL){
        printf("\n %d", aux->info);
        aux = aux->proximo;
    }
}