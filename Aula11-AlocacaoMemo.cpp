#include <stdio.h>
#include <stdlib.h>
#include "Aula11-Funcoes.h" // aqui � o nome do arquivo. pode usar pastas e referenciar com pasta
#include <new> // esse new � a biblioteca q usamos para fazer o vetor din�mico em C++
#include <iostream>
#include <string>

using namespace std;

int main(){

    //Chama a fun��o
    imprimeOi();

    desenhaBorda();
//====================================== ALOCA��O DE MEMO EM C =======================================
//========================================== Para vetores ============================================
//====================================================================================================
    // Para criar um vetor "din�mico", onde vc diz o tamanho, em C, vc precisa alocar memo
    //Ponteiro que vai apontar para o vetor criado
    int *vetor , tam ,i; // para o vetor vc cria um ponteiro vazio, q armazenar� o primeiro espa�o
    // do vetor

    //Lendo o tamanho do vetor
    printf("Digite um tamanho");
    scanf ( "%d", &tam ) ;

    //Vetor vai receber um endere�o de mem�ria com o vetor que foi alocado
    //ponteiro = ENDERECO_DE_MEMORIA ou PONTEIRO
    //*ponteiro = VALOR
    vetor = alocaVetor(tam) ; // chama a fun��o e passa tamanho como par�metro

    //Colocando alguns valores no vetor
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;

    //Imprimindo o vetor na tela
    for(i=0;i<tam;i++){
        if(i>2){
            vetor[i] = vetor[i - 1] + 2;
        }
        printf("%d  ", vetor[i]);
    }

    //Libera a mem�ria ap�s usar o vetor, sempre q n�o for mais utilizar o vetor � preciso liberar memo
    free (vetor);

    desenhaBorda();
//===================================== ALOCA��O DE MEMO EM C++ ======================================
//========================================== Para vetores ============================================
//====================================================================================================
    //Tamanho a ser criado
    int tamanho;

    //Lendo o tamanho do vetor
    cout << "Digite o tamanho:";
    cin >> tamanho;

    //Mostrando o tamanho lido
    cout << "Tamanho:" << tamanho;

    //Criando um ponteiro que recebe o novo vetor vazio
    int *vet = new int[tamanho];

    //Passa valores para o vetor e os imprime na tela
    for(i = 0; i < tamanho; i++){
        vet[i] = i;
        cout << "\n" << vet[i];
    }
//====================================== ALOCA��O DE MEMO EM C =======================================
//========================================== Para matrizes ===========================================
//====================================================================================================
    //Ponteiro que vai apontar para o vetor criado
    int linhas = 3, colunas = 3, j;

    //Criando a um ponteiro
    int (*mat)[colunas];

    //Alocando mem�ria
    mat=(int (*)[colunas])malloc(sizeof(*mat)*linhas);

    //mat = alocaMatriz(mat, linhas, colunas);

    //Imprimindo a matriz
    for(i = 0; i < linhas; i++){
        for(j = 0; j< colunas; j++){
            mat[i][j] = i;
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }

    free(mat);
    /******************************************OUTRA FORMA************************************/
    int **matriz ,nl , nc;// em ponteiro para ponteiro, um ponteiro � a linha e o outro a coluna

    scanf("%d", &nl) ;
    scanf("%d", &nc);

    //Alocando mem�ria para o vetor de linhas
    matriz = (int **) malloc ( nl * sizeof (int *) ) ;

    //Alocando mem�ria para as colunas de cada linha
    for ( i =0; i < nl ; i ++)
        matriz[i] = (int*)malloc(nc * sizeof (int));

    //Preenchendo valores e imprimindo na tela
    for(i = 0; i < nl; i++){
         for(j = 0; j < nc; j++){
            matriz[i][j] = i;
            printf("%d ",matriz[i][j]);
         }
         printf("\n");
    }

    free(matriz);
//===================================== ALOCA��O DE MEMO EM C++ ======================================
//========================================== Para matrizes ===========================================
//====================================================================================================
    //Tamanho a ser criado
    int numeroLinhas, numeroColunas;

    //Lendo o tamanho do vetor
    cout << "Digite o tamanho de linhas:\n";
    cin >> numeroLinhas;
    cout << "Digite o tamanho de colunas:\n";
    cin >> numeroColunas;

    //Mostrando o tamanho lido
    cout << "Tamanho de Linhas:" << numeroLinhas << "\n";
    cout << "Tamanho de Colunas:" << numeroColunas << "\n";

    //Ponteiro de Ponteiro para Matriz
    int **mat2;

    //Matriz de ponteiro para ponteiros
    mat2 = (int **) new int[numeroLinhas];

    //Alocando mem�ria para cada coluna
    for ( i =0; i < numeroLinhas ; i ++)
        mat2[i] = (int *)  new int[numeroColunas];

    //Imprimindo a matriz
    for(i = 0; i < numeroLinhas; i++){
         for(j = 0; j < numeroColunas; j++){
            mat2[i][j] = i;
            printf("%d ",mat[i][j]);
         }
         printf("\n");
    }

    //Retorno da Fun��o
    return 0;
}
