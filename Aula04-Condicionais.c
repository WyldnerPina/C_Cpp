#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h> // biblioteca para usar booleano
//Fun��o principal do programa
void main(){
    setlocale(LC_ALL, "");
//====================================================================================================
//====================================================================================================
    //Definindo Vari�veis
    int a = 4,opcao = 3;
    float b = 2.5;
    char c = 'x';

    //Condicional Simples
    if(a == 5){
        printf("\n A variavel a = 5");
    }
    if(b == 2.5){
        printf("\n A variavel b = 2.5");
    }
    if(c == 'x'){
        printf("\n A variavel c = letra x");
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
    //N�mero par ou impar
    if(a % 2 == 1){
        printf("\n A variavel a eh impar");
    }else{
        printf("\n A variavel a eh par");
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
    //Condicional Composta
    if(opcao == 1){
        printf("\nA opcao = 1");
    }else if(opcao == 2){
         printf("\nA opcao = 2");
    }else{
        printf("\nA opcao nao eh igual a 1 e nem 2");
    }

//====================================================================================================
//====================================================================================================
    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
    //Definindo Vari�veis
    int d = 5, e = 10, f = 15;
    char g = 'x';

    //Maior
    if(d > 2){
        printf("\n %d eh maior que 2", d);
    }

    //Maior ou Igual
    if(f >= e){
        printf("\n %d eh maior ou igual que %d", f, e);
    }

    //Menor
    if(d < 10){
        printf("\n %d eh menor que 10", d);
    }

    //Menor ou igual
    if(d <= 10){
        printf("\n %d eh menor ou igual a 10", d);
    }

    //Diferente
    if(f != 10){
        printf("\n %d nao eh 10", f);
    }
    if(g != 'g'){
        printf("\n %c nao eh a", g);
    }
    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================
    bool h = true, i = false;

   //Se H for verdadeiro
    if(h){ // por default sempre q fazemos com var bool o if j� � "h == true", ent�o s� colocamos H
        printf("\n H eh verdadeiro");
    }

   //Comparando o B
    if(i){
        printf("\nI eh verdadeiro");
    }else{
        printf("\nI eh falso");
    }

    //Comparando uma falsidade
    if(!i){ //aqui � pra ver se � falto, t� negando I
        printf("\nI eh falso");
    }


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================



//Definindo Vari�veis
    char letra = 'x';

    //Condicional Simples
    if(letra == 'x'){
        printf("\nA letra eh x.");
    }

    //C�digo em ASCII
    printf("\nCodigo da letra = %d", letra);

    //Comparando C�digo ASCII
    if(letra == 120){
         printf("\n A letra eh x.");
    }


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================


    //Crie um algoritmo que leia 3 notas e calcule a m�dia entre elas.
    //Se o valor for maior que 7 informe que o aluno foi aprovado,
    //sen�o foi reprovado.
    float nota1, nota2, nota3, media;
    printf("Digite a nota 1:");
    scanf("%f", &nota1);

    printf("\nDigite a nota 2:");
    scanf("%f", &nota2);

    printf("\nDigite a nota 3:");
    scanf("%f", &nota3);

    media = (nota1+nota2+nota3)/3;
    printf("\nA m�dia do aluno foi: %.2f", media);

    if(media > 7 ){ // podia fezer: if((nota1+nota2+nota3)/3 >7){...}, sem usar var m�dia
        printf("\n\nO aluno foi aprovado! Parab�ns campe�o!");
    }else{
        printf("\n\nO aluno foi reprovado! Sinto muito, na pr�xima voc� vai conseguir!");
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================

    //Condicionais m�ltiplas
    //Definindo Vari�veis
    int z = 18;

    //Conectivo L�gico E (AND) , Se UMA COMPARACAO for FALSA, N�o entra no bloco
    if(z > 5 && z > 15){
        printf("\n A variavel 'a' esta entre 5 e 15 ");
    }

    //Conectivo L�gico OU (OR) , Se UMA COMPARACAO for VERDADEIRA, j� entra no bloco
    if(z > 5 || z > 15){
        printf("\n A variavel 'a' eh maior que 5 ou 15 ");
    }

    //Misturando Conectivos
    if( (z > 5 && z < 15) || a == 20 ){
        printf("\n A variavel 'a' esta entre 5 e 15 ou ela vale 20 ");
    }


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================


    //Crie um algoritmo que leia 3 valores e informe se eles s�o
    //iguais entre si para formarem os lados de um tri�ngulo equil�tero.
    int ladoA, ladoB, ladoC;
    printf("Digite os 3 valores:");
    scanf("%d %d %d", &ladoA, &ladoB, &ladoC);

    //Analisa se � equil�tero
    if( (ladoA == ladoB) && (ladoB == ladoC) ){
        printf("\nO tri�ngulo � equil�tero");
    }else{
        //Analisa se existem pelo menos dois lados iguais
        if( (ladoA == ladoB) || (ladoB == ladoC) || (ladoC == ladoA)){
            printf("\nO tri�ngulo � is�sceles!");
        }else{
            printf("\nO tri�ngulo � escaleno!");
        }
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================

    //case
    //Definindo Vari�veis
    int w = 2;
    char y = 'y';

    //C�digo de exemplo com if
    if(w == 1){
        printf("\n Opcao escolhida: 1");
    }else if(w == 2){
        printf("\n Opcao escolhida: 2");
    }else if(w == 3){
        printf("\n Opcao escolhida: 3");
    }else{
        printf("\n Opcao invalida");
    }

    //O mesmo c�digo de cima, adaptado ao Switch
    switch(w){
        case 1:
            printf("\n Opcao escolhida: 1");
            break;
        case 2:
            printf("\n Opcao escolhida: 2");
            break;
        case 3:
            printf("\n Opcao escolhida: 2");
            break;
        default:
            printf("\n Opcao invalida");
            break;
    }

    //Switch com Char
    switch(y){
        case 'x':
            printf("\n A letra eh x");
            break;
        default:
            printf("\n Opcao invalida");
            break;
    }


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================

     /*Crie um algoritmo que leia dois valores e depois crie um menu (Usando Switch Case)
    de 4 op��es:1-Somar, 2-Subtrair,3-Dividir,4-Multiplicar.
    Depois que o usu�rio escolher uma op��o, mostre o resultado da opera��o escolhida
    com os dois valores lidos.*/
    float valor1, valor2;
    int opc;

    printf("Digite o primeiro valor:");
    scanf("%f", &valor1);
    printf("Digite o segundo valor:");
    scanf("%f", &valor2);

    printf("\nBoa tarde coleguinha, escolha uma op��o:");
    printf("\n1-Somar");
    printf("\n2-Subtrair");
    printf("\n3-Dividir");
    printf("\n4-Multiplicar");
    scanf("%d", &opc);
    switch(opc){
        case 1:
            printf("Resultado da soma: %.2f", valor1 + valor2);
            break;
        case 2:
            printf("Resultado da subtra��o: %.2f", valor1 - valor2);
            break;
        case 3:
            printf("Resultado da divis�o: %.2f", valor1 / valor2);
            break;
        case 4:
            printf("Resultado da multiplica��o: %.2f", valor1 * valor2);
            break;
        default:
            printf("Op��o inv�lida!");
            break;
    }

    //Pausa o programa ap�s executar
    system("pause");

}
