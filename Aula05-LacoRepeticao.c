#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Fun��o principal do programa
void main(){
    setlocale(LC_ALL, "");
//====================================================================================================
//====================================================================================================

    //Definindo Vari�veis
    int a = 1, b = 10;

    //Contando at� 10
    while(a <= 10){
        //Imprimindo 'a' na tela
        printf("\n%d", a);
        //Incremento
        a++;     //a = a + 1;
    }

    //Contagem Regressiva
    while(b >= 1){
        //Imprimindo 'b' na tela
        printf("\n%d", b);
        //Incremento
        b--;    //b = b - 1;
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Alterando o valor de 'a'
    a = 1;
 //Primeiro confere a condi��o, depois repete o bloco
    while(a <= 10){
        //Imprimindo 'a' na tela
        printf("\n%d", a);
        //Incremento
        a++;     //a = a + 1;
    }

    //Alterando o valor de 'a'
    a = 20;

    //Primeiro executa uma vez, depois confere a condi��o
    do{
        //Imprimindo 'a' na tela
        printf("\n%d", a);
        //Incremento
        a++;     //a = a + 1;
    }while(a <= 10);

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

//Definir Vari�veis
    int cont;

    //Tabuada do 5
    for(cont = 1; cont <= 10; cont++){
        printf("\n 5 X %d = %d",cont, 5 * cont);
    }

    //Contando de 2 em 2
    for(cont = 0; cont <= 10; cont = cont + 2){
        printf("\n%d",cont);
    }

    //Contagem regressiva
    for(cont = 10; cont > 0; cont--){
        printf("\n%d", cont);
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Definindo Vari�veis
    int opcao;

    //Confere e valida a opcao
    while(opcao < 1 || opcao > 3){

         //Interface de Menu
        printf("Escolha uma opcao:"); // tbm poderia:printf("Escolha uma opcao:\n1-Opcao 1\n2-Opcao 2...")
        printf("\n1-Opcao 1");
        printf("\n2-Opcao 2");
        printf("\n3-Opcao 3\n");

        //Lendo a opcao
        scanf("%d", &opcao);

        //Resultado de acordo com a opcao escolhida
        switch(opcao){
             case 1:
                printf("\nOpcao 1 foi escolhida");
                break;
             case 2:
                printf("\nOpcao 2 foi escolhida");
                break;
             case 3:
                printf("\nOpcao 3 foi escolhida");
                break;
            default:
                printf("\nOpcao Invalida");
                break;
        }

    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================
    int i = 10;
    while(i >= 0){
        printf("%d \n", i);
        i--;
    }

    //Do While
    i = 10;
    do{
        printf("%d \n", i);
        i--;
    }while(i >= 0);

    //For
    for(i = 10; i >= 0; i--){
        printf("%d \n", i);
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Crie um algoritmo que imprima os n�meros
    //pares de 10 a 20 (usando While, Do While ou For)

    for(i = 10; i <= 20; i++){
        if(i % 2 == 0){
            printf("%d � par \n", i);
        }else{
            printf("%d � �mpar \n", i);
        }
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

//Crie um algoritmo que informe se o valor lido � primo ou n�o
    int valor, aux = 0;

    printf("Digite um valor para saber se ele � primo:");
    scanf("%d", &valor);

    for(i = 1; i <= valor ; i++){

        //Conferindo quantas vezes houve divisibilidade
        if(valor % i == 0){
            aux++;
        }

        //Exibe o resto da divis�o na tela
        printf("%d / %d tem o resto = %d \n", valor, i, valor%i);
     }

     if(aux == 2){
        printf("O n�mero � primo!");
    }else{
        printf("O n�mero n�o � primo! Pois ele tem %d divisores", aux);
    }
}
