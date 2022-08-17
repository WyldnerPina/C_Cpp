//======================================== FUNÇÕES AULA 11 ===========================================
//====================================================================================================
//====================================================================================================
//Função que diz oi
void imprimeOi(){
    printf("Oi\n");
}
//====================================================================================================
//====================================================================================================
//Aloca um vetor do tamanho pedido
int* alocaVetor (int tam ){ // vai retornar um ponteiro, já q a var lá no principal é ponteiro

    //É criado um ponteiro para auxiliar no retorno, já q recebi um ponteiro
    int *v;

    //A memória é alocada e o ponteiro recebe o endereço de memória dele
    v = (int*) malloc (tam * sizeof(int));
    // malloc é a função q aloca espaço na memo
    // tam * sizeof(int) = é o tamanho digitado pelo usuário vezes o tamanho básico de um int. com isso
    // sabemor qnto de memo alocar para o vetor
    // (int*) força q a alocação de memória feita passe um endereço de memória do tipo int para o ponteiro


    //Esse ponteiro é retornado
    return v;
}
//====================================================================================================
//====================================================================================================
//Função que desenha borda
void desenhaBorda(){
    printf("\n==================================================================\n");
    printf("==================================================================\n");
}
//====================================================================================================
//====================================================================================================
//Aloca um vetor do tamanho pedido
int* alocaMatriz (int *matriz, int linhas, int colunas ){

    //É criado um ponteiro
    int *novaMatriz;

    //A memória é alocada e o ponteiro recebe o endereço de memória dele
    novaMatriz = (int *)malloc(linhas * colunas * sizeof(int));

    //Esse ponteiro é retornado
    return novaMatriz;
}
