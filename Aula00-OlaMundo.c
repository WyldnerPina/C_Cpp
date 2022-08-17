#include <stdio.h> // biblioteca p/ ler valores
#include <stdlib.h> // biblioteca p/ fazer algumas operações
#include <locale.h> // biblioteca p/ poder usar acentos em pt

void main(){ // função principal main = no java, função vazia sem parâmetros
    setlocale(LC_ALL,""); // cód p/ pegar a língua padrão do sistema

    printf("Olá Mundo!"); // pra imprimir na tela

    int var;
    float a = 1.1;
    printf("\n digite o valor de var: ");
    scanf("\n %d", &var); // o & é pra indicar local na memória
    printf("\n var = %d", var);
    printf("\n var + a = %f \n", var + a);

    char letra = 'w'; // apenas 1 letra
    printf("\n letra é = %c \n", letra);

    fflush(stdin); // sempre q usar char, fazer a limpeza do buffer antes da leitura
    // dar descarga na entrada de buffer principal (standard in)
    printf("\n digite letra: ");
    scanf("%c", &letra);
    printf(" letra é = %c", letra);
}
// não pode salvar na área de trabalho. essa IDE não compila lá.
//>>> NO C++, A PRINCIPAL É INT E NÃO VOID, E SEMPRE VAI RETORNAR UM VALOR Q GERALMENTE É ZERO

/*
===============================================================================================================
================================================== ESCREVER ===================================================
===============================================================================================================
    printf(“Oi Galera!”);
    printf(“%d”, var);
    printf(“O valor de var = %d”, var);
    printf(“Oi Galera! \n Aqui estou em outra linha”);

===============================================================================================================
================================================= VARIÁVEIS ===================================================
===============================================================================================================
 int a = 5; --------> Para escrever: printf(“%d”, nomeDaVariavel); ---> Para ler: scanf(“%d”, &nomeDaVariavel);
 float b = 5.5;  ---> Para escrever: printf(“%f”, nomeDaVariavel); ---> Para ler: scanf(“%f”, &nomeDaVariavel);
 char c = ‘p’;  ----> Para escrever: printf(“%c”, nomeDaVariavel); ---> Para ler: scanf(“%c”, &nomeDaVariavel);
    ATENÇÃO: é preciso limpar o buffer nas leituras, com fflush(stdin);

*/


