#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; //para utilizar cout
void desenhaBorda();
void imprime_vetor(int vetor[TAM]);
int busca_simples(int vetor[TAM], int valorProcurado, int *posicaoEncontrada);
int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada);

int main(){
    // Vars são usadas nos dois exemplos
    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valorProcurado;
    int posicao, posicaoEncontrada;
    //Auxiliar contador
    int cont;

//========================================== BUSCA SIMPLES ===========================================
//============================================== EX 1 ================================================
//====================================================================================================
    //Imprime o vetor na tela
    imprime_vetor(vetor);


    printf("Qual numero deseja encontrar?");
    scanf("%d", &valorProcurado);

    if(busca_simples(vetor, valorProcurado, &posicaoEncontrada) == 1){
        cout << "O valor foi encontrado na posicao:" << posicaoEncontrada + 1;// +1 já q a posição é vetor, p/ ajustar
    }else{
        cout << "Valor nao encontrado";
    }

    desenhaBorda();
//========================================== BUSCA BINÁRIA ===========================================
//============================================== EX 2 ================================================
//====================================================================================================

    /* só funciona em listas já ordenadas (em ordem crescente), na sequencial não é necessário
    qndo fazemos uma busca binária, não fazemos do começo ao fim, mas do meio (através de um pivô - cursor -
    q escolhemos). Após apontado o programa pergunta se o número procurado é maior ou menor q o meio.
    sendo maior ele vai novamente achar o meio e refazer a pergunta, segue essa sequência até achar o
    número desejado
    */

    //Imprime o vetor na tela
    imprime_vetor(vetor);

    //Lendo o número buscado
    printf("Qual numero deseja encontrar?");
    scanf("%d", &valorProcurado);


    if(busca_binaria(vetor, valorProcurado, &posicaoEncontrada) == 1){
        cout << "O valor foi encontrado na posicao:" << posicaoEncontrada + 1;
    }else{
        cout << "Valor nao encontrado";
    }


    return 0;

}


//============================================== EX 1 ================================================
//====================================================================================================
//====================================================================================================
void imprime_vetor(int vetor[TAM]){
    //Auxiliar contador
    int cont;

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

}

int busca_simples(int vetor[TAM], int valorProcurado, int *posicaoEncontrada){

    //Auxiliar contador
    int cont;

    //Verifica se o valor foi encontrado
    bool valorFoiEncontrado;// por padão bool é false

    //Percorre a lista em busca do valor
    for(cont = 0; cont < TAM; cont++){
        if(vetor[cont] == valorProcurado){
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont;// pra passar a posição encontrada (não é possível passar para dentro da chamada
            // da função, já q essa já retorna o valor encontrado), então passamos o end da memória para a função e
            // modificamos o valor lá, com isso não é preciso retornar um valor
        }
    }

    if(valorFoiEncontrado){// no if a pergunta é sempre se vdd
        return 1;
    }else{
        return -1;
    }
}


//============================================== EX 2 ================================================
//====================================================================================================
//====================================================================================================
int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada){

    int esquerda = 0;           //Limite da esquerda
    int direita = TAM - 1;      //Limite da direita
    int meio;                   //O meio onde fica o cursor

    // estabelece os limites pra ir achando o meio. no começo o limite é o espaço 0 e o 9, já q o vetor
    // tem tamanho 10

    while(esquerda <= direita){// a condição para parar o cód é justamente qndo a esq e a dir se encontrarem

        //Encontra o meio da análise
        meio = (esquerda + direita)/2;

        //Quando o valor do meio é encontrado
        if(valorProcurado == vetor[meio]){
            *posicaoEncontrada = meio;
            return 1;
        }

        //Ajustando os limites laterais
        if(vetor[meio] < valorProcurado){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }

    }

    return -1;

}


//Função que desenha borda
void desenhaBorda(){
    printf("\n==================================================================\n");
    printf("==================================================================\n");
}

