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
void inserir(int valor);

int main(){
    cabeca = iniCabeca();
    inserir(30);
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

void inserirFinal(T_cabeca *cabeca, int valor)
{
    // Cria um ponteiro para um novo nó.
    // Ainda não existe o nó; "novo" apenas vai guardar o endereço
    // dele quando fizermos o malloc.
    T_lista *novo;

    // Cria de fato um espaço na memória para o novo nó.
    novo = malloc(sizeof(T_lista));

    // Coloca o valor recebido dentro do campo "info" do novo nó.
    // Exemplo: se valor = 50, então novo->info = 50.
    novo->info = valor;

    // Como estamos colocando o nó no FINAL da lista,
    // ele não terá nenhum nó depois dele.
    // Por isso, seu "prox" começa apontando para NULL.
    novo->proximo = NULL;

    // O novo nó será colocado depois do atual último nó.
    // Portanto, o "ant" do novo nó deve apontar para o
    // atual último nó da lista.
    novo->anterior = cabeca->fim;


    // Agora precisamos descobrir se a lista já possui elementos.
    //
    // Se cabeca->fim NÃO for NULL:
    // significa que existe um último nó.
    //
    // Se cabeca->fim for NULL:
    // significa que a lista está vazia.
    if (cabeca->fim != NULL)
    {
        // A lista já possui pelo menos um elemento.
        //
        // cabeca->fim aponta para o último nó.
        // Então pegamos esse último nó e fazemos o "prox" dele
        // apontar para o novo nó.
        //
        // Antes:
        //
        // [10] ⇄ [20]
        //          ↑
        //         fim
        //
        // Depois:
        //
        // [10] ⇄ [20] ⇄ [30]
        //
        // Aqui estamos criando a ligação:
        // [20].prox → [30]
        cabeca->fim->proximo = novo;
    }
    else
    {
        // Se entrou aqui, o IF não foi executado.
        //
        // Isso significa que:
        // cabeca->fim == NULL
        //
        // Portanto, a lista estava VAZIA.
        //
        // Como esse é o primeiro nó da lista,
        // ele também precisa ser o primeiro.
        //
        // Então:
        // cabeca->inicio → novo
        cabeca->inicio = novo;
    }


    // Independentemente de a lista estar vazia ou não,
    // o novo nó agora é o ÚLTIMO nó.
    //
    // Por isso atualizamos o fim.
    //
    // Se era:
    // fim → [20]
    //
    // agora:
    // fim → [30]
    cabeca->fim = novo;

    // Como adicionamos um elemento, aumentamos a quantidade
    // de elementos da lista.
    cabeca->qtd++;
}