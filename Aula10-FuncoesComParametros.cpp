#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>

//Definindo que a função existe
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
    //Definindo Variáveis
    int a;

    //Instrução
    printf("Digite um valor:");

    //Passa um valor para 'a'
    scanf("%d", &a);

    //Chama a função
    mostraSucessor(a);

    //Exibe o antecessor
    printf("\nO antecessor de %d eh %d", a, retornaAntecessor(a));

    //Chamando a Função
    desenhaBorda();
//====================================================================================================
//====================================================================================================
    //Definindo Variáveis
    int b = 7;
    a = 5;

    //Função que mostra a soma
    mostraSoma(a,b);

    //Exibe o resultado da soma retornado pela função
    printf("\n A soma entre %d e %d eh %d", a,b,retornaSoma(a,b));

    //Chamando a Função
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

    //Função que aumenta 10 diretamente
    aumentaDez(&a);

    //Mostrando o valor
    printf("%d \n", a);

    //Chamando a Função
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

    //Chamando a Função
    desenhaBorda();
//====================================================================================================
//====================================================================================================

    return 0;
}

//============================================ FUNÇÕES ===============================================
//====================================================================================================
//====================================================================================================
//Função que desenha borda
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
void imprimeVetor(int *vetor, int tamanho){ // todo vetor é um ponteiro, vc passa os ends, no caso do 1º

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
