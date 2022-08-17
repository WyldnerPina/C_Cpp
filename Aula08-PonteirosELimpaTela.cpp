#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>

using namespace std;

//Limpa a tela
void limpaTela(){
    system("CLS");//biblioteca da <stdlib.h>, clean scream
}
//====================================================================================================
//====================================================================================================
int main(){

    //Vari�vel
    int a = 20;

    //Imprimindo o valor de uma vari�vel
    printf("Valor de a: %d \n", a);

     //Imprimindo o endere�o de uma vari�vel
    printf("Endere�o de a: %d \n", &a);// o & sempre busca endere�o de memo,
    // pra receber um n�mero, por exemplo usamos o scanf("%d", &a); com o &a para jogar no endere�o
    // de a

    //VARI�VEIS ARMAZENAM VALORES
    int b = 10;

    //PONTEIROS ARMAZENAM POSI��ES DA MEM�RIA
    int *ponteiro;

    //PONTEIRO RECEBENDO A POSI��O NA MEM�RIA DA VARI�VEL b
    ponteiro = &b;

    //Imprimindo o valor de uma vari�vel
    printf("Valor de b: %d \n", b);

    //* pode ser lido como "CONTE�DO APONTADO POR"
    *ponteiro = 40;// se eu mudo o valor do ponteiro q aponta o valor de b, ent�o eu mudo o valor de b
    //acesso mais direto � memo do programa


    //Imprimindo o valor de uma vari�vel
    printf("Valor de b: %d \n", b);


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Imprimindo alguma coisa
    printf("Digite um valor para 'a':");

    //Lendo o valor
    scanf("%d", &a);

    //Chama a fun��o que limpa a tela
    limpaTela();//fun��o abaixo d� erro aqui, ela precisa ser declarada antes de chamar, ent�o acima.

    printf("O valor digitado foi %d \nFim do Programa!", a);


    return 0;
}
