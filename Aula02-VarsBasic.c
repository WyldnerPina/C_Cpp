#include <stdio.h>
#include <stdlib.h>

void main(){

    //Definindo uma vari?vel
    int a = 5, b;

    //Imprimindo a vari?vel "a"
    printf("%d", a);

    //Concatenando
    printf("\nO valor da var a eh: %d", a);

    //Mudando o valor de "a"
    a = 15;

    //Concatenando
    printf("\nO valor da var a eh: %d", a);

    //Lendo valores
    printf("\n================================================");
    printf("\nDigite um valor: ");
    scanf("%d", &b);

    //Concatenando
    printf("\nO valor da var b eh: %d", b);

    //Pula linhas
    printf("\n");
    printf("\n================================================");
    printf("\nO valor da var a eh: %d %d", a,b);
    //Imprimindo
    printf("\n Uhuu =)\n");

    //Pausando
    system("pause");

}
