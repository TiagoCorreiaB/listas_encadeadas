
void contarGratuitos(T_cabeca *cabeca){
    
    T_lista *listaFilmes = cabeca->inicio;
    T_cabeca *filmesGratuitos = inicializarLista();
    int qtdLocacoes;

    while (listaFilmes != NULL){
    qtdLocacoes = 0;
        
        if(listaFilmes->filmesLocados >= 15){
            qtdLocacoes = listaFilmes->filmesLocados / 15; 
            inserir(filmesGratuitos, qtdLocacoes, listaFilmes->codigoCliente);
        }
        listaFilmes = listaFilmes->proximo;
    }

    T_lista *auxFilmes = filmesGratuitos->inicio;
    while(auxFilmes != NULL){
        printf("\nO cliente %d tem direito a %d filmes gratuitos", auxFilmes->codigoCliente, auxFilmes->qtdGratuitos);
        auxFilmes = auxFilmes->proximo;
    }
} 
