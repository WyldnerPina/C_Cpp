#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <string>

//Definindo que a função existe - Se eu quiser escrever ela abaixo da chamada do cód principal
void desenhaBorda();
int retornaDezEImprimeMensagem();
float retornaQuebrado();
char retornaLetra();
bool retornaBooleano();
//====================================================================================================
//====================================================================================================

int main(){

    //Chamando a Função
    desenhaBorda();

    //Imprimindo texto na tela
    printf("hi\n");

    //Chamando a Função
    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo Variáveis
    int a;

    //Passando o retorno de uma função para uma variável
    a = retornaDezEImprimeMensagem();

    //Imprimindo valor de a
    printf("\n%d", a);

    //Definndo um float
    float b;

    //Passando o retorno de uma função para uma variável
    b = retornaQuebrado();

    //Imprimindo valor de a
    printf("\n%f", b);

    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo variáveis
    char letra;

    //Char recebendo valor de uma função
    letra = retornaLetra();

    //Imprimindo novo valor
    printf("\n%c", letra);

    desenhaBorda();

//====================================================================================================
//====================================================================================================
    //Definindo variáveis
    bool variavelBooleana;

    //Variável recebendo booleano
    variavelBooleana = retornaBooleano();

    //Se for verdadeiro executa o primeiro bloco
    if(variavelBooleana){
        printf("Eh verdadeiro!");
    }//Senão, executa o segundo bloco
    else{
        printf("Eh falso!");
    }

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
//Função que retorna 10
int retornaDezEImprimeMensagem(){
    printf("\nOi galera! \n");
    int numero = 10;
    return numero;// posso fazer aperações aqui tbm: return numero * 10;
}

//====================================================================================================
//====================================================================================================
//Retorna um número quebrado
float retornaQuebrado(){
    return 5.5;
}

//====================================================================================================
//====================================================================================================
char retornaLetra(){
    return 'x';// posso fazer o retorno com o número asc: return 120;
}

//====================================================================================================
//====================================================================================================
bool retornaBooleano(){
    return true;
}
