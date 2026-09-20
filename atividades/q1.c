// Escreva uma função que receba duas estrutura estática como parâmetro contendo informações de alunos, ou
// seja, uma tabela com informações dos alunos da Turma de Estrutura de Dados e da Turma de Linguagem de
// Programação I, de acordo com a estrutura apresentada abaixo. Após identifique e mostre os alunos que
// cursam as duas disciplinas.

typedef struct aluno
{ int matricula;
char nome[50];
float media;
}T_aluno;

void q1(T_aluno sala_estrutura_dados, T_aluno sala_programacao, int qtdEstrutura, int qtdProgramacao){
    int i = 0, x;

    while(i < qtdEstrutura){
        x = 0;
        while(x < qtdProgramacao && sala_programacao[x].matricula != sala_estrutura_dados[i].matricula){
            x++;            
        }
        if(x < qtdProgramacao){
            printf("O aluno %s esta em duas turmas", sala_programacao[x].nome);
        }
        i++;
    }
}