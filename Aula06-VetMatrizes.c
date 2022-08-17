#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3
//#include <string>
//#include <iostream>

//Função principal do programa
void main(){
    setlocale(LC_ALL, "");
//====================================================================================================
//====================================================================================================

    //Imprime na tela
    int vetor[TAM],cont;

    //Passando valores para o vetor
    vetor[0] = 5;
    vetor[1] = 10;
    vetor[2] = 15;

    //Adicionando 1 para cada posição
    for(cont = 0; cont < TAM; cont++){
        vetor[cont] =  vetor[cont] + 1;
    }

    //Exeibindo os valores do vetor
    printf("\nPosicao 0: %d", vetor[0] );
    printf("\nPosicao 1: %d", vetor[1] );
    printf("\nPosicao 2: %d", vetor[2] );

    //Imprimindo vetor em um laço de repetição
    for(cont = 0; cont < TAM; cont++){
        printf("\nPosicao %d : %d", cont, vetor[cont] );
    }

    //Lendo 3 valores para o vetor
    for(cont = 0; cont < TAM; cont++){
        scanf("%d", &vetor[cont]);
    }

    //Imprimindo vetor em um laço de repetição
    for(cont = 0; cont < TAM; cont++){
        printf("\nPosicao %d : %d", cont, vetor[cont] );
    }

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Crie um algoritmo que leia 3 valores para um vetor de 3 posições
    //e depois calcule a média dos valores acessando o vetor.
    float vetorA[3], aux, media;

    //Forma mais simples
    printf("Digite um valor:");
    scanf("%.2f", &vetorA[0]);
    printf("Digite um valor:");
    scanf("%.2f", &vetorA[1]);
    printf("Digite um valor:");
    scanf("%.2f", &vetorA[2]);
    printf("\nvetorA[0] -> %.2f ", vetorA[0]);
    printf("\nvetorA[1] -> %.2f ", vetorA[1]);
    printf("\nvetorA[2] -> %.2f ", vetorA[2]);
    media = (vetorA[0] + vetorA[1] + vetorA[2]) / 3;
    printf("\n Média: %.2f", media);

    //Outra Forma
    int i;
    for(i = 0; i < 3; i++){
        printf("\nDigite um valor para a posição vetor[%d]", i);
        scanf("%.2f",&vetorA[i]);
        media = media + vetorA[i];
    }
    printf("\n Média: %.2f", media/3);


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================
    // VERSÃO 2
    //Crie um algoritmo que leia um tamanho um vetor e preencha cada posição com um valor
    //depois calcule a média dos valores acessando o vetor.
    int tamanho;
    printf("Qual será o tamanho do vetor?");
    scanf("%d", &tamanho);

    float vet[tamanho], soma;

    for(i = 0; i < tamanho; i++){
        printf("Digite um valor:");
        scanf("%f", &vet[i]);
        soma = soma + vet[i];
    }
    for(i = 0; i < tamanho; i++){
        printf("\nvetor[%d] = %.2f",i, vet[i]);
    }

    printf("\nA média dos valores é: %.2f", soma/tamanho);


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Variáveis
    char palavra[10];//define um tamanho, 10 letras

    //Instrução
    printf("Digite uma palavra");

    //Limpa o Buffer
    setbuf(stdin, 0);// como é char tem q limpar o buffer

    //Lê a String
    fgets(palavra, 255, stdin); //lê palavras, 255 é o tamanho (255 letras), o certo é deixar igual.
    // e depois o meio q vai entrar = stdin, meio padrão

    //Limpa as casas não utilizadas
    palavra[strlen(palavra)-1] = '\0'; //strlen é o tamanho da palavra lida q está na var palavra
    // se palavra uhu a contagem é 3 e menos 1 é pra ajeitar com vetor
    // qndo é guardado na memó = [u][h][u][][][][][][][]\0 = 10 posições, após as posições tem um \0 pra indicar o fim
    // pegamos então o \0 e trazemos pra após a palavra q são 3 letras nas posições 0, 1 e 2, então tiramos o 3 (-1)
    // e após colocamos o \o

    //Imprime na tela
    printf("%s", palavra);


    printf("\n==================================================================\n");
    printf("\n==================================================================\n");

//====================================================================================================
//====================================================================================================


    //Preencha uma matriz 2x2 lendo valores do usuário e
    //depois troque os valores entre a primeira e a segunda linha.
    int minhaMatriz[2][2], aux1,aux2;

    //Lendo valores para matriz
    printf("Digite um valor para [0][0]");
    scanf("%d", &minhaMatriz[0][0]);
    printf("Digite um valor para [0][1]");
    scanf("%d", &minhaMatriz[0][1]);
    printf("Digite um valor para [1][0]");
    scanf("%d", &minhaMatriz[1][0]);
    printf("Digite um valor para [1][1]");
    scanf("%d", &minhaMatriz[1][1]);

    //Auxiliares
    aux1 = minhaMatriz[0][0];
    aux2 = minhaMatriz[0][1];

    //Invertendo valores usando auxiliares
    minhaMatriz[0][0] = minhaMatriz[1][0];
    minhaMatriz[0][1] = minhaMatriz[1][1];
    minhaMatriz[1][0] = aux1;
    minhaMatriz[1][1] = aux2;

    //Imprimindo nova matriz
    printf("\n%d %d",minhaMatriz[0][0],minhaMatriz[0][1]);
    printf("\n%d %d\n",minhaMatriz[1][0],minhaMatriz[1][1]);

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================
    // VERSÃO 2
    //Preencha uma matriz 2x2 lendo valores do usuário e
    //depois troque os valores entre a primeira e a segunda linha.
    int j;

    //Lendo valores para matriz
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2 ; j++){
            printf("Digite um valor para [%d][%d]:", i, j);
            scanf("%d", &minhaMatriz[i][j]);
        }
    }

    //Auxiliares
    aux1 = minhaMatriz[0][0];
    aux2 = minhaMatriz[0][1];

    //Invertendo valores usando auxiliares
    minhaMatriz[0][0] = minhaMatriz[1][0];
    minhaMatriz[0][1] = minhaMatriz[1][1];
    minhaMatriz[1][0] = aux1;
    minhaMatriz[1][1] = aux2;

    //Imprimindo nova matriz
    for(i = 0; i < 2 ; i++){
        for(j = 0; j < 2 ; j++){
            printf("%d ", minhaMatriz[i][j]);
        }
        printf("\n");
    }

}
