#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct geral{
    float nota;
    char nome [50];
    struct geral *proximo;
};

void cadastro(struct geral **aluno);
void adicionar(struct geral **aluno, float nota, char nome[]);
void printar(struct geral *aluno);
void infGerais(struct geral *aluno);
void excluir(struct geral **aluno);

int main(){
    struct geral *aluno = NULL;
    int escolha;

    cadastro(&aluno);

    printf("\n\n-- Cadastro concluido --");
    printf("\nAlunos Cadastrados: ");

    printar(aluno);

    do{
        printf("\n\n-- O que deseja fazer agora? --");
        printf("\n1- Consultar informacoes de alunos\n2- Cadastrar novos alunos\n3- Consultar informacoes gerais\n4- Excluir dados de aluno\n0- Encerrar\nresposta: ");
        scanf("%d", &escolha);
        switch (escolha){
            case 0: break;
            case 1: printar(aluno);
            break;
            case 2: cadastro(&aluno);
            printf("\nNovos alunos cadastrados!");
            break;
            case 3: infGerais(aluno);
            break;
            case 4: excluir(&aluno);
            break;
            default: printf("\nNumero solicitado nao disponivel");
            break;
        }
    }while(escolha != 0);

    struct geral *limpar;
    while(aluno != NULL){
        limpar = aluno;
        aluno = aluno->proximo;
        free(limpar);
    }
    return 0;
}

void cadastro(struct geral **aluno){
    int verif;
    float nota;
    char nome[50];

    printf("\n-- Entrada de dados --");
    do{
        printf("\nDigite o nome do aluno: ");
        scanf(" %49[^\n]", nome);

        printf("\nDigite a nota do aluno: ");
        scanf(" %f", &nota);
        while (nota > 10.0 || nota < 0.0){
            printf("\n! A nota deve ser maior que 0 e menor que 10 !");
            printf("\nDigite novamente a nota do aluno: ");
            scanf(" %f", &nota);
        }

        adicionar(aluno, nota, nome);
        printf("\nDeseja continuar adicionando alunos? 1-sim | 0-nao: ");
        scanf("%d", &verif);
    }while(verif != 0);

}

void adicionar(struct geral **aluno, float nota, char nome[]){
    struct geral *NoLocal = malloc(sizeof(struct geral));

    if (NoLocal == NULL){
        printf("erro ao alocar memoria");
        return;
    }

    NoLocal->nota = nota;
    strcpy(NoLocal->nome, nome);
    NoLocal->proximo = NULL;

    if (*aluno == NULL){
        *aluno = NoLocal;
    }
    else{
        struct geral *NoAux = *aluno;
        while (NoAux->proximo != NULL){
            NoAux = NoAux->proximo;
        }
        NoAux->proximo = NoLocal;
    }
}

void printar(struct geral *aluno){
    struct geral *print = aluno;
    printf("\n-- ALUNOS CADASTRADOS --");
    while (print != NULL){
        printf("\nAluno: %s | Nota: %.2f", print->nome, print->nota);
        print = print->proximo;
    }
    printf("\n");
}

void infGerais(struct geral *aluno){
    if (aluno == NULL) {
        printf("\nNenhum aluno cadastrado no sistema.");
        return;
    }

    struct geral *aux = aluno;
    int reprovados = 0, aprovados = 0;

    float maior = aux->nota, menor = aux->nota;
    char alunoMaior[50], alunoMenor[50];
    strcpy(alunoMaior, aux->nome);
    strcpy(alunoMenor, aux->nome);

    printf("\nA maior nota foi: ");
    while(aux != NULL){
        if(maior < aux->nota){
            maior = aux->nota;
            strcpy(alunoMaior, aux->nome);
        }
        if(menor > aux->nota){
            menor = aux->nota;
            strcpy(alunoMenor, aux->nome);
        }
        aux = aux->proximo;
    }
    printf("\n");
    printf("\n- MAIOR E MENOR NOTA --\n");
    printf("\nMaior Nota: %.2f, pertencente a: %s", maior, alunoMaior);
    printf("\nMenor Nota: %.2f, pertencente a: %s", menor, alunoMenor);

    aux = aluno;
    printf("\n");
    printf("\n- APROVACOES E REPROVACOES --\n");
    while (aux != NULL){
        if(aux->nota >= 7.0){
            printf("\n%s (APROVADO)", aux->nome);
            aprovados++;
        }
        else{
            printf("\n%s (REPROVADO)", aux->nome);
            reprovados++;
        }
        aux = aux->proximo;
    }
    printf("\nTotal: Aprovados: %d | Reprovados: %d", aprovados, reprovados);
}

void excluir(struct geral **aluno){
    if (*aluno == NULL){
        printf("Lista de alunos vazia");
        return;
    }

    struct geral *NoExcluir = *aluno;
    struct geral *NoAnterior = NULL;

    char nomeEscolha[50];
    printf("Digite o nome do aluno que quer excluir, se deseja cancelar a acao, digite 'cancelar'\nresposta: ");
    scanf(" %49[^\n]", nomeEscolha);
    if (strcmp(nomeEscolha, "cancelar") == 0){
        printf("\nOperacao cancelada.\n");
        return;
    }


    //Verifica se o nome existe
    while (1) { //While 1 é o mesmo que while true
        NoExcluir = *aluno; // sempre começa do início
        NoAnterior = NULL;

        while (NoExcluir != NULL && strcmp(nomeEscolha, NoExcluir->nome) != 0) {
            NoAnterior = NoExcluir;
            NoExcluir = NoExcluir->proximo;                                       // Faz a varredura que para o ponteiro onde o nome existir
        }

        if (NoExcluir != NULL) {
            break;                 // Se o nome foi encontrado, para
        }

        printf("\nDigite um nome que existe em sua lista\n(Se desejar verificar os nomes, digite 'verificar') | Se deseja cancelar a acao, digite 'cancelar')\nresposta: ");      //Se não foi encontrado, mostra a mensagem
        scanf(" %[^\n]", nomeEscolha);
        if(strcmp(nomeEscolha, "verificar") == 0){
            printar(*aluno);
        }
        if(strcmp(nomeEscolha, "cancelar") == 0){
            NoExcluir = NULL;
            break;
        }
    }
    if (NoExcluir == NULL) {
        printf("\nOperacao cancelada.\n");
        return;
    }


    NoExcluir = *aluno;

    while (NoExcluir != NULL && strcmp(NoExcluir->nome, nomeEscolha)){
        NoAnterior = NoExcluir;
        NoExcluir = NoExcluir->proximo;
    }

    if (NoAnterior == NULL){
        *aluno = NoExcluir->proximo;
    }
    else{
        NoAnterior->proximo = NoExcluir->proximo;
    }
    free(NoExcluir);
}