#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    Aqui definimos o Nó, que armazena um inteiro
    Uma estrutura é como uma caixa que guarda varias variaveis de uma só vez, dando apenas 1 nome a ela
    */
    struct No { // No ou Nó é o nome de nossa estrutura
        int valor;              // O dado que queremos guardar
        struct No *proximo;     // Ponteiro para o próximo nó da lista
    };
    struct No *novo_no = malloc(sizeof(struct No)); //adiciona tamanho dinamico, é como se tivesse comprando um terreno de memoria para uma noca estrutura

    //A estrutura para atribuir valor é essa: "ponteiro -> campo = valor;"
    novo_no -> valor = 10;
    novo_no -> proximo = NULL; //Atribuimos NULL aqui para quando o proximo for vazio não pegar um endereço aleatorio

    //criamos um segundo nó
    struct No *segundo_no = malloc(sizeof(struct No));

    novo_no -> proximo = segundo_no; //pegando o endereço de memória onde o segundo nó mora e guardando dentro do primeiro

    //atribuindo valores ao segundo nó
    segundo_no -> valor = 20,
    segundo_no -> proximo = NULL;

    printf("%d",novo_no -> proximo -> valor); //acessa o valor do segundo nó a partir do primeiro e printa
    
    return 0;
}