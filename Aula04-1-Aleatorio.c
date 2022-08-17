#include <stdio.h>
#include <stdlib.h>
#include <time.h> // biblioteca para aleatório
#define TAM 10.5 // TAM é o nome da constante. e ela vale 10. geralmente constante se declara tudo maiúsculo

//Função principal do programa
void main(){
    printf("\n%f", TAM);//APRESENTANDO CONSTANTE

   //Responsável por alimentar o rand de forma diferente
   srand((unsigned)time(NULL));// usa como base o tempo do pc pra mudar o randow
   int aleat = rand();// qq número

   //Variável que recebe o resto da divisão do número por 3 (aleatorio entre 0 e 2)
   int aleatorio = rand() % 3;

   //Variável que recebe o resto da divisão do número por 5 (aleatorio entre 1 e 5)
   int aleatorioSegundo = (rand() % 5) + 1;

   //Imprime o valor
   printf("\n%d\n", aleatorioSegundo);

   //Pausa o programa após executar
   system("pause");

}
