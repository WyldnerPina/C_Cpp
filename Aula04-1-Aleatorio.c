#include <stdio.h>
#include <stdlib.h>
#include <time.h> // biblioteca para aleat�rio
#define TAM 10.5 // TAM � o nome da constante. e ela vale 10. geralmente constante se declara tudo mai�sculo

//Fun��o principal do programa
void main(){
    printf("\n%f", TAM);//APRESENTANDO CONSTANTE

   //Respons�vel por alimentar o rand de forma diferente
   srand((unsigned)time(NULL));// usa como base o tempo do pc pra mudar o randow
   int aleat = rand();// qq n�mero

   //Vari�vel que recebe o resto da divis�o do n�mero por 3 (aleatorio entre 0 e 2)
   int aleatorio = rand() % 3;

   //Vari�vel que recebe o resto da divis�o do n�mero por 5 (aleatorio entre 1 e 5)
   int aleatorioSegundo = (rand() % 5) + 1;

   //Imprime o valor
   printf("\n%d\n", aleatorioSegundo);

   //Pausa o programa ap�s executar
   system("pause");

}
