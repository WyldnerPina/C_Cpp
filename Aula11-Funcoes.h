//======================================== FUN��ES AULA 11 ===========================================
//====================================================================================================
//====================================================================================================
//Fun��o que diz oi
void imprimeOi(){
    printf("Oi\n");
}
//====================================================================================================
//====================================================================================================
//Aloca um vetor do tamanho pedido
int* alocaVetor (int tam ){ // vai retornar um ponteiro, j� q a var l� no principal � ponteiro

    //� criado um ponteiro para auxiliar no retorno, j� q recebi um ponteiro
    int *v;

    //A mem�ria � alocada e o ponteiro recebe o endere�o de mem�ria dele
    v = (int*) malloc (tam * sizeof(int));
    // malloc � a fun��o q aloca espa�o na memo
    // tam * sizeof(int) = � o tamanho digitado pelo usu�rio vezes o tamanho b�sico de um int. com isso
    // sabemor qnto de memo alocar para o vetor
    // (int*) for�a q a aloca��o de mem�ria feita passe um endere�o de mem�ria do tipo int para o ponteiro


    //Esse ponteiro � retornado
    return v;
}
//====================================================================================================
//====================================================================================================
//Fun��o que desenha borda
void desenhaBorda(){
    printf("\n==================================================================\n");
    printf("==================================================================\n");
}
//====================================================================================================
//====================================================================================================
//Aloca um vetor do tamanho pedido
int* alocaMatriz (int *matriz, int linhas, int colunas ){

    //� criado um ponteiro
    int *novaMatriz;

    //A mem�ria � alocada e o ponteiro recebe o endere�o de mem�ria dele
    novaMatriz = (int *)malloc(linhas * colunas * sizeof(int));

    //Esse ponteiro � retornado
    return novaMatriz;
}
