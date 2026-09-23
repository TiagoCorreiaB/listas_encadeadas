void encontrarPalavra(T_cabeca *cabeca){
    T_lista *palavras;
    palavras = cabeca->inicio;
    int qtd = 0;

    while(palavras != NULL){
        if(strcmp(palavras->palavra,"PAZ") == 0){
            qtd++;
        }
        palavras = palavras -> proximo;
    }
    printf("A palavra paz foi encontrada %d vezes", qtd);
}