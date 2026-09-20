#include <stdio.h>
#include <stdlib.h>

struct No { 
    int valor;       
    struct No *proximo;
};


int main(){

    struct No *novo_no = malloc(sizeof(struct No));
    novo_no -> valor = 10;
    novo_no -> proximo = NULL;

    struct No *segundo_no = malloc(sizeof(struct No));
    segundo_no -> valor = 20;
    segundo_no -> proximo = NULL;
    novo_no -> proximo = segundo_no;

    struct No *terceiro_no = malloc(sizeof(struct No));
    terceiro_no -> valor = 30;
    terceiro_no -> proximo = NULL;
    segundo_no -> proximo = terceiro_no;

    struct No *atual = novo_no; //ponteiro "atual" apontando para o inicio da lista
    
    while (atual != NULL){ //enquanto não indetificar null (fim) faz o while
        printf("\n%d", atual -> valor); //amostra o valor do atual 
        atual = atual -> proximo; // atual precisa dar um pulo para o proximo valor
    }

    // Vamos limpar a memória agora
    atual = novo_no; //começa resentando o ponteiro atual para a primeira posição
    struct No *auxiliar; //auxiliar não precisa de valor atribuido porque sera sobrescrito no while

    while (atual != NULL){
        auxiliar = atual -> proximo; //Guarda o valor(ponteiro) do proximo com uma variavel auxiliar
        free(atual); //Destroi ou elimina o valor atual
        atual = auxiliar;  //Vai para o proximo
    }
    
    return 0;
}