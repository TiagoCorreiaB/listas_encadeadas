// Escreva um programa que leia o nome e a nota de n alunos,
// armazene os alunos em uma lista duplamente encadeada.
//
// Mostre o nome e a nota do melhor aluno,
// varrendo a lista da direita para a esquerda.
//
// Mostre o nome e a nota do pior aluno,
// varrendo a lista da esquerda para a direita.
//
// Mostre também a média geral de todos os alunos.
//
// Obs: Pegue sempre o primeiro nome encontrado
// no caso de duas ou mais notas serem iguais.


void q5(T_cabeca *cabeca){
    T_lista *alunos;
    alunos = cabeca->fim;
    float maiorNota = alunos -> nota;
    float menorNota = alunos-> nota;
    char nomeMaior[50];
    char nomeMenor[50];
    strcpy(nomeMaior, alunos->nome);
    strcpy(nomeMenor, alunos->nome);
    float soma = 0.0;
    int qtd = 0;

    while(alunos != NULL){
        if (alunos->nota > maiorNota){
            maiorNota = alunos->nota;
            strcpy(nomeMaior, alunos->nome);
        }
        if(alunos->nota < menorNota){
            menorNota = alunos->nota;
            strcpy(nomeMenor, alunos->nome);
        }
        soma = alunos->nota + soma;
        qtd++;
        alunos = alunos->anterior;
    }
    soma = soma/qtd;
    printf("O melhor aluno é %s, com nota %f", nomeMaior, maiorNota);
    printf("O pior aluno é %s, com nota %f", nomeMenor, menorNota);
    printf("A media geral foi: %f", soma);
}