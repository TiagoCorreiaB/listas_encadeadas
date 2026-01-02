#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

void organizar(struct No **NoPrincipal, int valor);
void remover(struct No **NoPrincipal, int ValorExcluir);
int buscar(struct No *NoPrincipal, int ValorBuscar);

int main(){
    struct No *NoPrincipal = NULL;
    organizar(&NoPrincipal, 10);
    organizar(&NoPrincipal, 20);
    organizar(&NoPrincipal, 30);

    struct No *printar = NoPrincipal;
    while (printar != NULL){
        printf("\n%d", printar->valor);
        printar = printar->proximo;
    }

    //vamos remover o 20
    remover(&NoPrincipal, 20);

    printf("\n");
    printar = NoPrincipal;
    while (printar != NULL){
        printf("\n%d", printar->valor);
        printar = printar->proximo;
    }

    //Verificamos se o valor existe ou não e printamos
    if(buscar(NoPrincipal, 20)){ //Passagem de parametro sem  & pos estamos apenas verificando a lista, não alterando
        printf("\nValor encontrado");
    }
    else{
        printf("\nValor nao encontrado");
    }

    struct No *aux;
    while (NoPrincipal != NULL){
        aux = NoPrincipal;
        NoPrincipal = NoPrincipal->proximo;
        free(aux);
    }
}

void organizar(struct No **NoPrincipal, int valor){
    struct No *NoLocal = malloc(sizeof(struct No));

    if (NoLocal == NULL){
        printf("erro ao alocar");
    }
    NoLocal->valor = valor;
    NoLocal->proximo = NULL;
    
    if (*NoPrincipal == NULL){
        *NoPrincipal = NoLocal;
    }

    else{
        struct No *NoAux = *NoPrincipal;
        while (NoAux->proximo != NULL){
            NoAux = NoAux->proximo;
        }
        NoAux->proximo = NoLocal;
    }
}

void remover(struct No **NoPrincipal, int ValorExcluir){
    struct No *NoAtual = *NoPrincipal;
    struct No *NoAnterior = NULL;

    //Verifica se o valor (que queremos excluir) existe na lista com o NULL e anda o encadeamento até ele
    while (NoAtual != NULL && NoAtual->valor != ValorExcluir){
        NoAnterior = NoAtual; //guarda o valor anteior
        NoAtual = NoAtual->proximo; //vai guardando ate chegar no ultimo
    }

    //se perceber que o valor não exite na lista, retorna
    if (NoAtual == NULL){
        return;
    }
    
    //Caso o valor seja o primeiro da lista: (ex: 10-> 20.. O atual é 10 e anterior continua NULL) ele diz pro NoPrincipal andar 1 casa pra frente
    if (NoAnterior == NULL){
        *NoPrincipal = NoAtual->proximo;
    }

    /*"Costura" a lista fazendo com que o valor anterior aponte para o valor que atual esta apontando:

    é como se basicamente fizéssemos um backup do próximo valor. 
    Temos o 10, 20 e 30, anterior esta no 10 apontando pro 20, o atual esta no 20 apontando pro 30, 
    aí falamos pra anterior fazer "backup" do que o atual esta apontando e apontar pro 30 também. 
    quando excluímos o atual, sabemos para quem temos que apontar.*/
    else{
        NoAnterior->proximo = NoAtual->proximo;
    }
    
    free(NoAtual);
}

int buscar(struct No *NoPrincipal, int ValorBuscar){ //Apenas 1 asterisco
    struct No *BuscarNo = NoPrincipal; //Usando NoPrincipal sem * pos estamos apenas verificando a lista, não alterando

    while (BuscarNo != NULL){
        if (BuscarNo->valor == ValorBuscar){
            return 1;
        }
        BuscarNo = BuscarNo->proximo;
    }
    return 0;
}