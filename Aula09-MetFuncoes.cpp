#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>

//Definindo que a fun��o existe - Se eu quiser escrever ela abaixo da chamada do c�d principal
void desenhaBorda();
int retornaDezEImprimeMensagem();
float retornaQuebrado();
char retornaLetra();
bool retornaBooleano();
//====================================================================================================
//====================================================================================================

int main(){

    //Chamando a Fun��o
    desenhaBorda();

    //Imprimindo texto na tela
    printf("hi\n");

    //Chamando a Fun��o
    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo Vari�veis
    int a;

    //Passando o retorno de uma fun��o para uma vari�vel
    a = retornaDezEImprimeMensagem();

    //Imprimindo valor de a
    printf("\n%d", a);

    //Definndo um float
    float b;

    //Passando o retorno de uma fun��o para uma vari�vel
    b = retornaQuebrado();

    //Imprimindo valor de a
    printf("\n%f", b);

    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo vari�veis
    char letra;

    //Char recebendo valor de uma fun��o
    letra = retornaLetra();

    //Imprimindo novo valor
    printf("\n%c", letra);

    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo vari�veis
    bool variavelBooleana;

    //Vari�vel recebendo booleano
    variavelBooleana = retornaBooleano();

    //Se for verdadeiro executa o primeiro bloco
    if(variavelBooleana){
        printf("Eh verdadeiro!");
    }//Sen�o, executa o segundo bloco
    else{
        printf("Eh falso!");
    }

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
//Fun��o que retorna 10
int retornaDezEImprimeMensagem(){
    printf("\nOi galera! \n");
    int numero = 10;
    return numero;// posso fazer apera��es aqui tbm: return numero * 10;
}

//====================================================================================================
//====================================================================================================
//Retorna um n�mero quebrado
float retornaQuebrado(){
    return 5.5;
}

//====================================================================================================
//====================================================================================================
char retornaLetra(){
    return 'x';// posso fazer o retorno com o n�mero asc: return 120;
}

//====================================================================================================
//====================================================================================================
bool retornaBooleano(){
    return true;
}
