#include <stdio.h>
#include <stdlib.h>

struct No { 
    int valor;       
    struct No *proximo;
};

void inicio(struct No **ponteiro_inicio, int novo_valor);
void inserir_final(struct No **ponteiro_inicio, int novo_valor);

int main(){
    struct No *ponteiro_inicio = NULL; //recebe valor nulo porque atribuimos eles na função
    
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

    struct No *novo = malloc(sizeof(struct No)); //criamos um novo No

    novo -> valor = novo_valor;
    novo -> proximo = *ponteiro_inicio; //"Faça com que o valor novo aponte para o antigo primeiro elemento"

    /*
    Início: NULL
    inicio(10): [10] -> NULL                         (novo elemento 10 aponta para o antigo que é NULL)
    inicio(20): [20] -> [10] -> NULL                 (novo elemento 20 aponta para o antigo que é 10 e o 10 está apontando para o NULL)
    inicio(30): [30] -> [20] -> [10] -> NULL         (idem)
    */

    //Cada novo elemento vira o primeiro da lista, e o antigo primeiro passa a ser o próximo dele, ou seja, esta "indo da direita para a esquerda"
    *ponteiro_inicio = novo; //O novo nó se torna, oficialmente, o primeiro da lista.

}

//Pondo em ordem de chegada

void inserir_final(struct No **ponteiro_inicio, int novo_valor) {

    struct No *novo = malloc(sizeof(struct No));
    novo->valor = novo_valor;
    novo->proximo = NULL; //Dessa vez, o ultimo será NULL por definição: [10] -> [20] -> [30] -> NULL (porximo valor sempre pode ser o ultimo) 
    
    //O valor já esta criado, ele só não está ligado a nenhuma posição lista (voce criou a "peça" só não encaixou no brinquedo)

    //se a lista estiver vazia, o novo nó é o inicio
    if (*ponteiro_inicio == NULL) {
        *ponteiro_inicio = novo; //Se estiver vazia não tem o que percorrer, novo se torna o primeiro
        
    //senão busca o ultimo nó
    } else {
        struct No *aux = *ponteiro_inicio; //Criamos um "auxiliar" para ir do início da lista
        // Caminha até o último nó
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo; // O último nó agora aponta para o novo valor
    }
}