#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>

//Definindo que a fun��o existe
void desenhaBorda();
void mostraSucessor(int numero);
int retornaAntecessor(int numero);
void mostraSoma(int primeiroValor, int segundoValor);
int retornaSoma(int primeiroValor, int segundoValor);
int retornaComMaisDez(int numero);
void aumentaDez(int *numero);
void imprimeVetor(int *vetor, int tamanho);
void modificaVetor(int *vetor, int tamanho);
//====================================================================================================
//====================================================================================================

int main(){
    //Definindo Vari�veis
    int a;

    //Instru��o
    printf("Digite um valor:");

    //Passa um valor para 'a'
    scanf("%d", &a);

    //Chama a fun��o
    mostraSucessor(a);

    //Exibe o antecessor
    printf("\nO antecessor de %d eh %d", a, retornaAntecessor(a));

    //Chamando a Fun��o
    desenhaBorda();
//====================================================================================================
//====================================================================================================
    //Definindo Vari�veis
    int b = 7;
    a = 5;

    //Fun��o que mostra a soma
    mostraSoma(a,b);

    //Exibe o resultado da soma retornado pela fun��o
    printf("\n A soma entre %d e %d eh %d", a,b,retornaSoma(a,b));

    //Chamando a Fun��o
    desenhaBorda();
//====================================================================================================
//====================================================================================================
    a = 5;

    //Mostrando o valor
    printf("%d \n", a);

    //Aumenta 10
    a = retornaComMaisDez(a);

    //Mostrando o valor
    printf("%d \n", a);

    //Fun��o que aumenta 10 diretamente
    aumentaDez(&a);

    //Mostrando o valor
    printf("%d \n", a);

    //Chamando a Fun��o
    desenhaBorda();
//====================================================================================================
//====================================================================================================
    //Definindo Vetor
    int v[3] = {1,2,3};

    //Mostrando vetor
    imprimeVetor(v, 3);

    //Modifica o vetor
    modificaVetor(v, 3);

    //Mostrando vetor
    imprimeVetor(v, 3);

    //Chamando a Fun��o
    desenhaBorda();
//====================================================================================================
//====================================================================================================

    return 0;
}

//============================================ FUN��ES ===============================================
//====================================================================================================
//====================================================================================================
//Fun��o que desenha borda
void desenhaBorda(){
    printf("\n==================================================================\n");
    printf("==================================================================\n");
}
//====================================================================================================
//====================================================================================================
void mostraSucessor(int numero){
    printf("\nO sucessor de %d eh %d", numero, numero + 1);
}
//====================================================================================================
//====================================================================================================
int retornaAntecessor(int numero){
    return numero - 1;
}
//====================================================================================================
//====================================================================================================
void mostraSoma(int primeiroValor, int segundoValor){
    printf("\n A soma entre %d e %d eh %d", primeiroValor,segundoValor,primeiroValor + segundoValor);
}
//====================================================================================================
//====================================================================================================
int retornaSoma(int primeiroValor, int segundoValor){
    return primeiroValor + segundoValor;
}
//====================================================================================================
//====================================================================================================
int retornaComMaisDez(int numero){
    return numero + 10;
}
//====================================================================================================
//====================================================================================================
void aumentaDez(int *numero){
    *numero = *numero + 10;
}
//====================================================================================================
//====================================================================================================
void imprimeVetor(int *vetor, int tamanho){ // todo vetor � um ponteiro, vc passa os ends, no caso do 1�

    //Percorrendo o vetor
    for(int i = 0; i < tamanho;i++)
        printf("%d \n",vetor[i]);

}
//====================================================================================================
//====================================================================================================
void modificaVetor(int *vetor, int tamanho){

    //Percorrendo o vetor
    for(int i = 0; i < tamanho;i++)
        vetor[i] = vetor[i] + 1;

}
