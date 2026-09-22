// Escreva uma função que receba duas estruturas estáticas como parâmetro contendo informações de alunos, ou
// seja, uma tabela com informações dos alunos da Turma de Estrutura de Dados e da Turma de Linguagem de
// Programação I, de acordo com a estrutura apresentada abaixo. Após identifique e mostre os alunos que
// cursam as duas disciplinas.

typedef struct aluno
{ int matricula;
char nome[50];
float media;
}T_aluno;

void q1(T_aluno turmaA[], T_aluno turmaB[], int tamA, int tamB){

    int i = 0, x;
    while (i < tamA){
        x = 0;
        while (x < tamB && turmaA[i].matricula != turmaB[x].matricula){
            x++;
        }
        if (x < tamB){
            printf("o aluno %s esta nas duas materias", turmaB[x].nome);
        }
        i++;
    }

}