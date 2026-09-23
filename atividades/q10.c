void corrigirProva(char listaGabarito[],char listaAluno[], int qtdQuestoes){
    int i, acertos = 0;

    for (i = 0; i < qtdQuestoes; i++){
        if (listaAluno[i] == listaGabarito[i]){
            acertos++;
        }
    }

    printf("\nGABARITO");
    for (i = 0; i < qtdQuestoes; i++){
        printf("\nQuestao %d: %c", i +1, listaGabarito[i]);
    }
    printf("\nRESPOSTA");
    for (i = 0; i < qtdQuestoes; i++){
        printf("\nQuestao %d: %c", i +1, listaAluno[i]);
    }
    printf("\nQuantidade de acertos: %d", acertos);


}