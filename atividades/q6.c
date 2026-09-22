typedef struct aluno{
    int matricula;
    char nome[50];
    float media;
} T_aluno;

void calcularMedia(T_aluno alunos[], int qtdAlunos){
    int i = 0;
    while (i < qtdAlunos){
        if(alunos[i].media >= 7){
            printf("\nO aluno %s tirou %f", alunos[i].nome, alunos[i].media);
        }
        i++;
    }
}