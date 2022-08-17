#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10
/* LIFO - last in,first out - � o modo como a pilha � feita
a opera��o de empilhar chamamos PUSH. a de desempilhar POP
*/
using namespace std;
void imprime_vetor(int vetor[TAM], int topo);
bool pilha_vazia(int topo);
bool pilha_cheia(int topo);
int pilha_tamanho(int topo);
int pilha_get(int pilha[TAM], int *topo);
void pilha_push(int pilha[TAM],int valor, int *topo);
void pilha_pop(int pilha[TAM], int *topo);
void pilha_construtor(int pilha[TAM], int *topo);

/****************************************************************************************************/
//==================================== ESTRUTURA DE DADOS - PILHA ====================================
//====================================================================================================
//====================================================================================================
int main(){

    int pilha[TAM];// TAM = 10, definido l� em cima com constante
    // tamanho 10 n�o significa 10 elementos na pilha. a estrutura comporta 10.
    int topo, valorRetirado ;                                 //Topo da pilha
    // para dizer onde � o topo e q a partir dali n�o t�m mais elementos no vetor, criamos uma var topo


    /********************** 01 **********************/
    pilha_construtor(pilha, &topo);// chamamos essa fun��o, para definirmos como nossa pilha vai ser
    // e o q est� nela


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);// na 1x aqui o vetor vai estar zerado, pq o zeramos acima.


    /********************** 03 **********************/
    pilha_push(pilha, 5, &topo); //1� valor inserido


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);


    /********************** 04 **********************/
    cout << " Ultimo valor da pilha " << pilha_get(pilha, &topo);


    /********************** 05 **********************/
    cout << " Tamanho da Pilha: " << pilha_tamanho(topo);


    /********************** 03 **********************/
    //pilha envio o vetor, 7 � o n�mero q quero no vetor naquela posi��o, como � pra mudar o �ltimo
    // valor, envio o endere�o de topo.
    // como estou inserindo valores a opera��o � PUSH
    pilha_push(pilha, 7, &topo);//2� valor inserido
    pilha_push(pilha, 7, &topo);//3� valor inserido
    pilha_push(pilha, 7, &topo);//4� valor inserido
    pilha_push(pilha, 7, &topo);//5� valor inserido
    pilha_push(pilha, 7, &topo);//6� valor inserido
    pilha_push(pilha, 7, &topo);//7� valor inserido
    pilha_push(pilha, 7, &topo);//8� valor inserido
    pilha_push(pilha, 7, &topo);//9� valor inserido
    pilha_push(pilha, 7, &topo);//10� valor inserido


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);


    /********************** 06 **********************/
    pilha_pop(pilha, &topo);


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);
}


/****************************************************************************************************/
//============================================ FUN��ES ===============================================
//====================================================================================================
//====================================================================================================
/********************** 01 **********************/
//Cria uma pilha e limpa ela
void pilha_construtor(int pilha[TAM], int *topo){
    //Coloca o topo negativo para indicar uma pilha vazia
    *topo = -1;// primeiro endere�o � o 0, vai de 0 at� 9
    // se dissermos q o topo � 0 vamos inserir o pr�ximo valor em 1 pq o topo j� est� cheio.
    // por isso usamos -1 pra q qndo estiver vazia os valores sejam inseridos em 0

    //Auxiliar contador
    int cont;

     //deixa todas as posi��es zero no vetor
    for(cont = 0; cont < TAM; cont++){
       pilha[cont] = 0;
    }
    // em C, aparentemente qndo se passa um vetor, n�o � necess�rio voltar ele. vemos q vetor � modificado
    // e n�o � retornado. enquanto q vari�veis normais precisam retornar, e pra n�o fazer isso passamos
    // s� o ponteiro
}


/********************** 02 **********************/
void imprime_vetor(int vetor[TAM], int topo){
    int cont;

    cout << "\n";

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

    cout << "Topo: " << topo;

}


/********************** 03 **********************/
//Adiciona um valor na pilha
void pilha_push(int pilha[TAM],int valor, int *topo){

    //Caso n�o possa colocar mais valores
    if(pilha_cheia(*topo)){
        cout << " Pilha cheia! ";
    }else{//se a pilha estiver lugar
        *topo = *topo + 1;// 1�lugar = -1 + 1 =0, 2� = 0 + 1 = 1... 10� = 8 + 1 = 9
        pilha[*topo] = valor;// ap�s ajeitar o valor ent�o inserimos na posi��o
        // outra fun��o q modifica o vetor e n�o tem retorno do mesmo, mas as modifica��es aparecem na main
    }

}


/********************** 04 **********************/
//Retorna o ultimo valor da pilha
int pilha_get(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo)){// chama outra fun��o abaixo, q se true executa
        cout << " A pilha esta vazia ";
        return 0;// se n�o tiver nada retorna zero
    }else{// se falso retorna o �ltimo espa�o da pilha
        return pilha[*topo];// se tiver algo vai retornar o valor do �ltimo endere�o armazenado como topo,
        // no caso da primeira parte o valor � 5 no endere�o 0 = *topo
    }
}


/********************** 05 **********************/
int pilha_tamanho(int topo){//Saber se t� no m�ximo. topo + 1 = 9(�ltimo local no vetor) + 1 = TAM
    return topo + 1;// sempre mais um pra ajustar a posi��o, se posi��o 0 ent�o � o 1�
}


/********************** 06 **********************/
//Remove um valor da pilha
void pilha_pop(int pilha[TAM], int *topo){

    if(pilha_vazia(*topo)){
        cout << " A Pilha ja esta vazia ";
    }else{
        cout << " Valor Removido: " << pilha[*topo];
        pilha[*topo] = 0;
        *topo = *topo -1;
    }
}

/****************************************************************************************************/
//======================================= FUN��ES DAS FUN��ES ========================================
//====================================================================================================
//====================================================================================================
/************************************************/
//Caso a pilha esteja vazia
bool pilha_vazia(int topo){
    if(topo == -1){// confere o valor de topo e retorna vdd se ainda n�o somou nada, indicando vazia
        return true;
    }else{
        return false;
    }
}


/************************************************/
//Confere se a pilha est� cheia
bool pilha_cheia(int topo){
     if(topo == TAM - 1){// verifica se topo est� em 9, �ltimo espa�o do vetor, se tiver = cheia
        return true;
    }else{
        return false;
    }
}



