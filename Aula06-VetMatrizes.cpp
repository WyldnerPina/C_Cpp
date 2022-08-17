#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <iostream> // praticamente substitui a stdio.h - a 1ª

using namespace std; // pra não ter q ficar usando std toda hora.

int main(){ // no c++ uso int e não void para a função principal, e sempre dou um retorno 0
    setlocale(LC_ALL, "");

    std::string palavra; //(sem std)

    printf("Digite uma palavra");
    std::cin >> palavra; // lê palavra (sem std)
    std::cout << "\nA palavra é: " << palavra; // imprime palavra (sem std)

    printf("\n==================================================================\n");
    printf("\n==================================================================\n");
//====================================================================================================
//====================================================================================================

    //Criando uma matriz
    int matriz[2][2], i, j;

    //Passando valores
    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[1][0] = 3;
    matriz[1][1] = 4;

    //Imprimindo valores na tela
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            //cout << "\ni = " << i << " , j = " << j; //aqui é só pra mostrar passando os índices
            cout << matriz[i][j] * 2 << " "; // o x2 multiplica o número por 2
        }
        cout << "\n";
    }

    //Lendo valores para a matriz
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
           //scanf("%d", &matriz[i][j]); // código em c q funfa aqui tbm
           cin >> matriz[i][j];
        }
    }

    //Imprimindo valores na tela
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            //cout << "\ni = " << i << " , j = " << j;
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
//====================================================================================================
//====================================================================================================
    return 0;
}
