#include <stdio.h> // biblioteca p/ ler valores
#include <stdlib.h> // biblioteca p/ fazer algumas opera��es
#include <locale.h> // biblioteca p/ poder usar acentos em pt

void main(){ // fun��o principal main = no java, fun��o vazia sem par�metros
    setlocale(LC_ALL,""); // c�d p/ pegar a l�ngua padr�o do sistema

    printf("Ol� Mundo!"); // pra imprimir na tela

    int var;
    float a = 1.1;
    printf("\n digite o valor de var: ");
    scanf("\n %d", &var); // o & � pra indicar local na mem�ria
    printf("\n var = %d", var);
    printf("\n var + a = %f \n", var + a);

    char letra = 'w'; // apenas 1 letra
    printf("\n letra � = %c \n", letra);

    fflush(stdin); // sempre q usar char, fazer a limpeza do buffer antes da leitura
    // dar descarga na entrada de buffer principal (standard in)
    printf("\n digite letra: ");
    scanf("%c", &letra);
    printf(" letra � = %c", letra);
}
// n�o pode salvar na �rea de trabalho. essa IDE n�o compila l�.
//>>> NO C++, A PRINCIPAL � INT E N�O VOID, E SEMPRE VAI RETORNAR UM VALOR Q GERALMENTE � ZERO

/*
===============================================================================================================
================================================== ESCREVER ===================================================
===============================================================================================================
    printf(�Oi Galera!�);
    printf(�%d�, var);
    printf(�O valor de var = %d�, var);
    printf(�Oi Galera! \n Aqui estou em outra linha�);

===============================================================================================================
================================================= VARI�VEIS ===================================================
===============================================================================================================
 int a = 5; --------> Para escrever: printf(�%d�, nomeDaVariavel); ---> Para ler: scanf(�%d�, &nomeDaVariavel);
 float b = 5.5;  ---> Para escrever: printf(�%f�, nomeDaVariavel); ---> Para ler: scanf(�%f�, &nomeDaVariavel);
 char c = �p�;  ----> Para escrever: printf(�%c�, nomeDaVariavel); ---> Para ler: scanf(�%c�, &nomeDaVariavel);
    ATEN��O: � preciso limpar o buffer nas leituras, com fflush(stdin);

*/


