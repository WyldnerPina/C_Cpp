#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Fun��o principal do programa
void main(){

    //Definindo Vari�veis
    int a = 6, b = 4;

    //Soma
    printf("\n A soma de %d e %d = %d",a , b, a + b);//toda vez q ele tem um "%d" ele vai procurar depois qual
    // a var q est� ap�s a frase, ou seja, o "%d" � como se fosse a var ali, participando da frase

    //Subtra��o
    printf("\n A subtracao de %d e %d = %d",a , b, a - b);

    //Divis�o
    printf("\n A divisao de %d e %d = %d",a , b, a / b);

    //Multiplica��o
    printf("\n A multiplicacao de %d e %d = %d",a , b, a * b);

    //Resto da Divis�o
    printf("\n O resto da divisao entre %d e %d = %d",a , b, a % b);

    //Valor Absoluto
    printf("\n O valor absoluto de -3 = %d", abs(-3));

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

    //Para usar acentos
    setlocale(LC_ALL, ""); // al�m da pontua��o em pt, tbm habilita poder usar v�rgula em vez de ponto para n�s decimais

//====================================================================================================
    //Crie um algoritmo que leia 2 notas e mostre a m�dia entre elas.

    //Definindo Vari�veis
    float nota1, nota2, resultado;

    //Lendo primeiro valor
    printf("\nDigite a primeira nota:");
    scanf("%f", &nota1);

    //Lendo segundo valor
    printf("\nDigite a segunda nota:");
    scanf("%f", &nota2);

    //Calculando e mostrando resultado final
    resultado = (nota1 + nota2) / 2;
    printf("\nA m�dia �: %.1f \n", resultado);// o %.1f mostra uma var tipo float com apenas 1 casa ap�s vigula
    // com duas %.2f
    // poderia fazer a conta direto na apresenta��o do resultado, com isso a var resultado n�o seria necess�ria

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
    //Crie um algoritmo que leia 2 notas e mostre o valor absoluto da diferen�a entre elas
    int n1, n2;

    printf("Digite a primeira nota:");
    scanf("%d", &n1);
    printf("Digite a segunda nota:");
    scanf("%d", &n2);
    printf("A diferen�a entre os dois �: %d \n", abs(nota1 - nota2) );

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================

    /*Crie um algoritmo que leia 3 n�meros inteiros de uma s� vez e coloque os resultado da multiplica��o
     entre os 3 em uma vari�vel pr�pria, depois exiba essa vari�vel.*/

    //Definindo Vari�veis
    int val, val2, val3, result;

    //Lendo os 3 valores
    printf("Digite as 3 notas:");
    scanf("%d %d %d", &val, &val2, &val3);
    result = val * val2 * val3;

    //Exibindo resultado
    printf("O resultado �: %d", result);


    //Pausa o programa ap�s executar
    system("pause");//o programa nem sempre para dependendo a IDE etc. a� pra testes usamos pause
}
