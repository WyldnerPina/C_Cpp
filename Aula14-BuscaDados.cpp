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
    // Vars s�o usadas nos dois exemplos
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
        cout << "O valor foi encontrado na posicao:" << posicaoEncontrada + 1;// +1 j� q a posi��o � vetor, p/ ajustar
    }else{
        cout << "Valor nao encontrado";
    }

    desenhaBorda();
//========================================== BUSCA BIN�RIA ===========================================
//============================================== EX 2 ================================================
//====================================================================================================

    /* s� funciona em listas j� ordenadas (em ordem crescente), na sequencial n�o � necess�rio
    qndo fazemos uma busca bin�ria, n�o fazemos do come�o ao fim, mas do meio (atrav�s de um piv� - cursor -
    q escolhemos). Ap�s apontado o programa pergunta se o n�mero procurado � maior ou menor q o meio.
    sendo maior ele vai novamente achar o meio e refazer a pergunta, segue essa sequ�ncia at� achar o
    n�mero desejado
    */

    //Imprime o vetor na tela
    imprime_vetor(vetor);

    //Lendo o n�mero buscado
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
    bool valorFoiEncontrado;// por pad�o bool � false

    //Percorre a lista em busca do valor
    for(cont = 0; cont < TAM; cont++){
        if(vetor[cont] == valorProcurado){
            valorFoiEncontrado = true;
            *posicaoEncontrada = cont;// pra passar a posi��o encontrada (n�o � poss�vel passar para dentro da chamada
            // da fun��o, j� q essa j� retorna o valor encontrado), ent�o passamos o end da mem�ria para a fun��o e
            // modificamos o valor l�, com isso n�o � preciso retornar um valor
        }
    }

    if(valorFoiEncontrado){// no if a pergunta � sempre se vdd
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

    // estabelece os limites pra ir achando o meio. no come�o o limite � o espa�o 0 e o 9, j� q o vetor
    // tem tamanho 10

    while(esquerda <= direita){// a condi��o para parar o c�d � justamente qndo a esq e a dir se encontrarem

        //Encontra o meio da an�lise
        meio = (esquerda + direita)/2;

        //Quando o valor do meio � encontrado
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


//Fun��o que desenha borda
void desenhaBorda(){
    printf("\n==================================================================\n");
    printf("==================================================================\n");
}

