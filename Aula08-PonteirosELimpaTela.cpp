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

    //Variável
    int a = 20;

    //Imprimindo o valor de uma variável
    printf("Valor de a: %d \n", a);

     //Imprimindo o endereço de uma variável
    printf("Endereço de a: %d \n", &a);// o & sempre busca endereço de memo,
    // pra receber um número, por exemplo usamos o scanf("%d", &a); com o &a para jogar no endereço
    // de a

    //VARIÁVEIS ARMAZENAM VALORES
    int b = 10;

    //PONTEIROS ARMAZENAM POSIÇÕES DA MEMÓRIA
    int *ponteiro;

    //PONTEIRO RECEBENDO A POSIÇÃO NA MEMÓRIA DA VARIÁVEL b
    ponteiro = &b;

    //Imprimindo o valor de uma variável
    printf("Valor de b: %d \n", b);

    //* pode ser lido como "CONTEÚDO APONTADO POR"
    *ponteiro = 40;// se eu mudo o valor do ponteiro q aponta o valor de b, então eu mudo o valor de b
    //acesso mais direto à memo do programa


    //Imprimindo o valor de uma variável
    printf("Valor de b: %d \n", b);


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Imprimindo alguma coisa
    printf("Digite um valor para 'a':");

    //Lendo o valor
    scanf("%d", &a);

    //Chama a função que limpa a tela
    limpaTela();//função abaixo dá erro aqui, ela precisa ser declarada antes de chamar, então acima.

    printf("O valor digitado foi %d \nFim do Programa!", a);


    return 0;
}
