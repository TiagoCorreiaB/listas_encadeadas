#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

void printar(struct No *NoPrincipal);
void inserirNoFinal(struct No **NoPrincipal, int valor);
void remover(struct No **NoPrincipal, int ValorExcluir);
int buscar(struct No *NoPrincipal, int ValorBuscar);
void adicionarDepoisDe(struct No **NoPrincipal, int ValorAdicionar, int ValorReferencia);

int main(){
    struct No *NoPrincipal = NULL;
    inserirNoFinal(&NoPrincipal, 10);
    inserirNoFinal(&NoPrincipal, 20);
    inserirNoFinal(&NoPrincipal, 30);

    printar(NoPrincipal);

    //vamos remover o 20
    remover(&NoPrincipal, 20);

    printar(NoPrincipal);

    //Verificamos se o valor existe ou não e printamos
    if(buscar(NoPrincipal, 20)){ //Passagem de parametro sem  & pos estamos apenas verificando a lista, não alterando
        printf("\nValor encontrado");
    }
    else{
        printf("\nValor nao encontrado");
    }

    adicionarDepoisDe(&NoPrincipal, 20, 10); //Adicionando o 20 novamente, depois do valor 10
    
    if(buscar(NoPrincipal, 20)){ //Passagem de parametro sem  & pos estamos apenas verificando a lista, não alterando
        printf("\nValor encontrado");
    }
    else{
        printf("\nValor nao encontrado");
    }

    printar(NoPrincipal);

    struct No *aux;
    while (NoPrincipal != NULL){
        aux = NoPrincipal;
        NoPrincipal = NoPrincipal->proximo;
        free(aux);
    }
    return 0;
}

void printar(struct No *NoPrincipal){
    struct No *print = NoPrincipal;
    printf("\n");
    while (print != NULL){
        printf("\n%d", print->valor);
        print = print->proximo;
    }
}

void inserirNoFinal(struct No **NoPrincipal, int valor){
    struct No *NoLocal = malloc(sizeof(struct No));

    if (NoLocal == NULL){
        printf("erro ao alocar");
        return;
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

void adicionarDepoisDe(struct No **NoPrincipal, int ValorAdicionar, int ValorReferencia){
    if (*NoPrincipal == NULL) return; //Tentou adicionar em lista vazia, num pode
    
    struct No *NoAtual = *NoPrincipal;

    while (NoAtual != NULL && NoAtual->valor != ValorReferencia){ //percorre a lista ate o valor anterior ao que queremos adicionar
        NoAtual = NoAtual->proximo;
    }

    if (NoAtual == NULL){ //Verificamos se o valor anterior realmente existe
        return;
    }

    struct No *NoNovo = malloc(sizeof(struct No)); //Cria o No do valor que queremos adicionar
    if (NoNovo == NULL){
        printf("erro ao alocar");
        return;
    }

    NoNovo->proximo = NoAtual->proximo; //O novo No vai apontar para onde o anterior apontava 
    NoNovo->valor = ValorAdicionar;
    NoAtual->proximo = NoNovo; //O anterior vai apontar para o novo No
}