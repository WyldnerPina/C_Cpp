#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Função principal do programa
void main(){

    //Definindo Variáveis
    int a = 6, b = 4;

    //Soma
    printf("\n A soma de %d e %d = %d",a , b, a + b);//toda vez q ele tem um "%d" ele vai procurar depois qual
    // a var q está após a frase, ou seja, o "%d" é como se fosse a var ali, participando da frase

    //Subtração
    printf("\n A subtracao de %d e %d = %d",a , b, a - b);

    //Divisão
    printf("\n A divisao de %d e %d = %d",a , b, a / b);

    //Multiplicação
    printf("\n A multiplicacao de %d e %d = %d",a , b, a * b);

    //Resto da Divisão
    printf("\n O resto da divisao entre %d e %d = %d",a , b, a % b);

    //Valor Absoluto
    printf("\n O valor absoluto de -3 = %d", abs(-3));

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

    //Para usar acentos
    setlocale(LC_ALL, ""); // além da pontuação em pt, tbm habilita poder usar vírgula em vez de ponto para nºs decimais

//====================================================================================================
    //Crie um algoritmo que leia 2 notas e mostre a média entre elas.

    //Definindo Variáveis
    float nota1, nota2, resultado;

    //Lendo primeiro valor
    printf("\nDigite a primeira nota:");
    scanf("%f", &nota1);

    //Lendo segundo valor
    printf("\nDigite a segunda nota:");
    scanf("%f", &nota2);

    //Calculando e mostrando resultado final
    resultado = (nota1 + nota2) / 2;
    printf("\nA média é: %.1f \n", resultado);// o %.1f mostra uma var tipo float com apenas 1 casa após vigula
    // com duas %.2f
    // poderia fazer a conta direto na apresentação do resultado, com isso a var resultado não seria necessária

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
    //Crie um algoritmo que leia 2 notas e mostre o valor absoluto da diferença entre elas
    int n1, n2;

    printf("Digite a primeira nota:");
    scanf("%d", &n1);
    printf("Digite a segunda nota:");
    scanf("%d", &n2);
    printf("A diferença entre os dois é: %d \n", abs(nota1 - nota2) );

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================

    /*Crie um algoritmo que leia 3 números inteiros de uma só vez e coloque os resultado da multiplicação
     entre os 3 em uma variável própria, depois exiba essa variável.*/

    //Definindo Variáveis
    int val, val2, val3, result;

    //Lendo os 3 valores
    printf("Digite as 3 notas:");
    scanf("%d %d %d", &val, &val2, &val3);
    result = val * val2 * val3;

    //Exibindo resultado
    printf("O resultado é: %d", result);


    //Pausa o programa após executar
    system("pause");//o programa nem sempre para dependendo a IDE etc. aí pra testes usamos pause
}
