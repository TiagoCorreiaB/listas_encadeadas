void somaListas(T_cabeca *cabecaA, T_cabeca *cabecaB){
    T_lista *A, *B;
    T_cabeca *cabecaC = inicializarLista();
    A = cabecaA->inicio;
    B = cabecaB->fim;
    int soma;

    while (A != NULL && B != NULL){
        soma = A->valor + B->valor;
        inserir(cabecaC, soma);
        A = A->proximo;
        B = B->anterior;
    }

    T_lista *auxC = cabecaC->inicio; //C chega a NULL, como o inicio seria perdido criamos um aux pra pegar o inicio de volta 
    while(auxC != NULL){
        printf("\nvalor: %d", auxC->valor);
        auxC = auxC->proximo;
    }
}