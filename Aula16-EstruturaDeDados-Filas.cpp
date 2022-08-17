#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10
/* FIFO - firt in,first out - é o modo como a pilha é feita - agora como uma fila mesmo
o primeiro a chegar é o primeiro a sair
*/
using namespace std;
void imprime_vetor(int vetor[TAM], int tamanho);
void fila_construtor(int *frente, int *tras);
bool fila_vazia(int frente, int tras);
bool fila_cheia(int tras);
void fila_enfileirar(int fila[TAM], int valor, int *tras);
void fila_desenfileirar(int fila[TAM], int *frente, int tras);
int fila_tamanho(int tras, int frente);

/****************************************************************************************************/
//==================================== ESTRUTURA DE DADOS - FILAS ====================================
//====================================================================================================
//====================================================================================================
int main(){

    int fila[TAM] = {0,0,0,0,0,0,0,0,0,0};
    int frente,tras;
    int valor;

    /********************** 01 **********************/
    fila_construtor(&frente, &tras);

    /********************** 02 **********************/
    fila_enfileirar(fila, 5, &tras);
    fila_enfileirar(fila, 7, &tras);

    /********************** 03 **********************/
    fila_desenfileirar(fila,&frente, tras);
    fila_desenfileirar(fila,&frente, tras);
    fila_desenfileirar(fila,&frente, tras);

    /********************** 02 **********************/
    fila_enfileirar(fila, 8, &tras);

    /********************** 04 **********************/
    imprime_vetor(fila, fila_tamanho(tras,frente)); /********************** 05 **********************/
    // fila tamanho sendo passada como parâmetro

    return 0;
}


/****************************************************************************************************/
//============================================ FUNÇÕES ===============================================
//====================================================================================================
//====================================================================================================
/********************** 01 **********************/
void fila_construtor(int *frente, int *tras){
    *frente = 0;
    *tras = -1;
}

/********************** 02 **********************/
void fila_enfileirar(int fila[TAM], int valor, int *tras){

    if(fila_cheia(*tras)){
        cout << "Fila cheia!";
    }else{
        *tras = *tras + 1;
        fila[*tras] = valor;
    }
}

/********************** 03 **********************/
void fila_desenfileirar(int fila[TAM], int *frente, int tras){

    if(fila_vazia(*frente, tras)){
        cout << "Impossivel desenfileirar uma lista vazia";
    }else{
        cout << "O valor " << fila[*frente] << " foi removido";
        fila[*frente] = 0;
        *frente = *frente + 1;
    }

}

/********************** 04 **********************/
void imprime_vetor(int vetor[TAM], int tamanho){

    //Auxiliar contador
    int cont;

    cout << "\n";

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }
}

/********************** 05 **********************/
int fila_tamanho(int tras, int frente){
    return (tras - frente) + 1;
}


/****************************************************************************************************/
//======================================= FUNÇÕES DAS FUNÇÕES ========================================
//====================================================================================================
//====================================================================================================
/************************************************/
bool fila_vazia(int frente, int tras){
    if(frente > tras){
        return true;
    }else{
        return false;
    }
}

/************************************************/
bool fila_cheia(int tras){

    if(tras == TAM -1){
        return true;
    }else{
        return false;
    }
}


