#include <stdio.h>
#include <stdlib.h>

struct No { 
    int valor;       
    struct No *proximo;
};

void inicio(struct No **ponteiro_inicio, int novo_valor);
void inserir_final(struct No **ponteiro_inicio, int novo_valor);

int main(){
    struct No *ponteiro_inicio = NULL;
    
    inicio(&ponteiro_inicio, 10);
    inicio(&ponteiro_inicio, 20);
    inicio(&ponteiro_inicio, 30);

    inserir_final(&ponteiro_inicio, 10);
    inserir_final(&ponteiro_inicio, 20);
    inserir_final(&ponteiro_inicio, 30);

    struct No *atual = ponteiro_inicio;
    struct No *primeiro = atual;

    while (atual != NULL){ 
        printf("\n%d", atual -> valor); 
        atual = atual -> proximo; 
    }

    atual = primeiro;
    struct No *auxiliar = atual; 

    while (atual != NULL){
        auxiliar = atual -> proximo; 
        free(atual); 
        atual = auxiliar;
    }
    
    return 0;
}

//Pondo em ordem inversa

void inicio(struct No **ponteiro_inicio, int novo_valor){

    struct No *novo = malloc(sizeof(struct No)); //criamos um ponteiro para o novo valor que vai ocupar aquele espaço

    novo -> valor = novo_valor;
    novo -> proximo = *ponteiro_inicio; //está dizendo que o próximo elemento depois do seu novo nó será aquele que, até agora, era o primeiro da lista
    //Cada novo elemento vira o primeiro da lista, e o antigo primeiro passa a ser o próximo dele, ou seja, esta indo da direita para a esquerda
    *ponteiro_inicio = novo;

}

//Pondo em ordem de chegada

void inserir_final(struct No **ponteiro_inicio, int novo_valor) {
    struct No *novo = malloc(sizeof(struct No));
    novo->valor = novo_valor;
    novo->proximo = NULL;

    //se a lista estiver vazia, o novo nó é o inicio
    if (*ponteiro_inicio == NULL) {
        *ponteiro_inicio = novo;
        
    //senão busca o ultimo nó
    } else {
        struct No *aux = *ponteiro_inicio;
        // Caminha até o último nó
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        // O último nó agora aponta para o novo
        aux->proximo = novo;
    }
}