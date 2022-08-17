#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10
/* LIFO - last in,first out - é o modo como a pilha é feita
a operação de empilhar chamamos PUSH. a de desempilhar POP
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

    int pilha[TAM];// TAM = 10, definido lá em cima com constante
    // tamanho 10 não significa 10 elementos na pilha. a estrutura comporta 10.
    int topo, valorRetirado ;                                 //Topo da pilha
    // para dizer onde é o topo e q a partir dali não têm mais elementos no vetor, criamos uma var topo


    /********************** 01 **********************/
    pilha_construtor(pilha, &topo);// chamamos essa função, para definirmos como nossa pilha vai ser
    // e o q está nela


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);// na 1x aqui o vetor vai estar zerado, pq o zeramos acima.


    /********************** 03 **********************/
    pilha_push(pilha, 5, &topo); //1º valor inserido


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);


    /********************** 04 **********************/
    cout << " Ultimo valor da pilha " << pilha_get(pilha, &topo);


    /********************** 05 **********************/
    cout << " Tamanho da Pilha: " << pilha_tamanho(topo);


    /********************** 03 **********************/
    //pilha envio o vetor, 7 é o número q quero no vetor naquela posição, como é pra mudar o último
    // valor, envio o endereço de topo.
    // como estou inserindo valores a operação é PUSH
    pilha_push(pilha, 7, &topo);//2º valor inserido
    pilha_push(pilha, 7, &topo);//3º valor inserido
    pilha_push(pilha, 7, &topo);//4º valor inserido
    pilha_push(pilha, 7, &topo);//5º valor inserido
    pilha_push(pilha, 7, &topo);//6º valor inserido
    pilha_push(pilha, 7, &topo);//7º valor inserido
    pilha_push(pilha, 7, &topo);//8º valor inserido
    pilha_push(pilha, 7, &topo);//9º valor inserido
    pilha_push(pilha, 7, &topo);//10º valor inserido


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);


    /********************** 06 **********************/
    pilha_pop(pilha, &topo);


    /********************** 02 **********************/
    imprime_vetor(pilha, topo);
}


/****************************************************************************************************/
//============================================ FUNÇÕES ===============================================
//====================================================================================================
//====================================================================================================
/********************** 01 **********************/
//Cria uma pilha e limpa ela
void pilha_construtor(int pilha[TAM], int *topo){
    //Coloca o topo negativo para indicar uma pilha vazia
    *topo = -1;// primeiro endereço é o 0, vai de 0 até 9
    // se dissermos q o topo é 0 vamos inserir o próximo valor em 1 pq o topo já está cheio.
    // por isso usamos -1 pra q qndo estiver vazia os valores sejam inseridos em 0

    //Auxiliar contador
    int cont;

     //deixa todas as posições zero no vetor
    for(cont = 0; cont < TAM; cont++){
       pilha[cont] = 0;
    }
    // em C, aparentemente qndo se passa um vetor, não é necessário voltar ele. vemos q vetor é modificado
    // e não é retornado. enquanto q variáveis normais precisam retornar, e pra não fazer isso passamos
    // só o ponteiro
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

    //Caso não possa colocar mais valores
    if(pilha_cheia(*topo)){
        cout << " Pilha cheia! ";
    }else{//se a pilha estiver lugar
        *topo = *topo + 1;// 1ºlugar = -1 + 1 =0, 2º = 0 + 1 = 1... 10º = 8 + 1 = 9
        pilha[*topo] = valor;// após ajeitar o valor então inserimos na posição
        // outra função q modifica o vetor e não tem retorno do mesmo, mas as modificações aparecem na main
    }

}


/********************** 04 **********************/
//Retorna o ultimo valor da pilha
int pilha_get(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo)){// chama outra função abaixo, q se true executa
        cout << " A pilha esta vazia ";
        return 0;// se não tiver nada retorna zero
    }else{// se falso retorna o último espaço da pilha
        return pilha[*topo];// se tiver algo vai retornar o valor do último endereço armazenado como topo,
        // no caso da primeira parte o valor é 5 no endereço 0 = *topo
    }
}


/********************** 05 **********************/
int pilha_tamanho(int topo){//Saber se tá no máximo. topo + 1 = 9(último local no vetor) + 1 = TAM
    return topo + 1;// sempre mais um pra ajustar a posição, se posição 0 então é o 1º
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
//======================================= FUNÇÕES DAS FUNÇÕES ========================================
//====================================================================================================
//====================================================================================================
/************************************************/
//Caso a pilha esteja vazia
bool pilha_vazia(int topo){
    if(topo == -1){// confere o valor de topo e retorna vdd se ainda não somou nada, indicando vazia
        return true;
    }else{
        return false;
    }
}


/************************************************/
//Confere se a pilha está cheia
bool pilha_cheia(int topo){
     if(topo == TAM - 1){// verifica se topo está em 9, último espaço do vetor, se tiver = cheia
        return true;
    }else{
        return false;
    }
}



