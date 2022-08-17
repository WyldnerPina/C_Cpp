#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string>
#define TAM 10

using namespace std;
/*********************** 01 ************************/
void bubble_sort(int vetor[TAM]);// a dele tá errado
void bubble_sort_meu(int vetor[TAM]);

/*********************** 02 ************************/
void insertion_sort(int vetor[TAM]);

/*********************** 03 ************************/
void selection_sort(int vetor[TAM]);

/*********************** 04 ************************/
void quick_sort(int vetor[TAM], int inicio, int fim);

/*********************** 05 ************************/
void shell_sort(int vetor[TAM]);

/*********************** 06 ************************/
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito);
void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito);

/************************************************/
void imprimeVetor(int vetor[]);

/****************************************************************************************************/
//================================== ESTRUTURA DE DADOS - ORDENAÇÃO ==================================
//====================================================================================================
//====================================================================================================
int main () {
    int opc;
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};

    setlocale(LC_ALL,"");

    imprimeVetor(vetor);

    do{
        //Interface de Menu
        printf("\n      Escolha uma opcao:    ");
        printf("\n ===========================");
        printf("\n |    1 - Bubble Sort      |");
        printf("\n |    2 - Insertion Sort   |");
        printf("\n |    3 - Selection Sort   |");
        printf("\n |    4 - Quick Sort       |");
        printf("\n |    5 - Shell Sort       |");
        printf("\n |    6 - Merge Sort       |");
        printf("\n |    7 - Meu Bubble Sort  |");
        printf("\n ===========================");
        printf("\n\n |  9 - Sair               |");
        printf("\n ===========================\n");
        scanf("%d", &opc);

        //Resultado de acordo com a opcao escolhida
        switch(opc){
             case 1:
                bubble_sort(vetor);//sempre q passa um vetor em C, já é passada a referência de endereço,
                // não precisando de retorno
                break;
             case 2:
                insertion_sort(vetor);
                break;
             case 3:
                selection_sort(vetor);
                break;
             case 4:
                quick_sort(vetor, 0, TAM);
                break;
             case 5:
                shell_sort(vetor);
                break;
             case 6:
                merge_sort(vetor, 0, TAM - 1);
                break;
             case 7:
                bubble_sort_meu(vetor);
                break;
            case 9:
                printf("\nDesligando\n");
                break;
            default:
                printf("\nOpcão Inválida\n");
                break;
        }
    }while(opc != 9);
    return 0;
}

/****************************************************************************************************/
//============================================ FUNÇÕES ===============================================
//====================================================================================================
//====================================================================================================

/*********************************************** 01 *************************************************/
//========================================== Bubble Sort =============================================
// algoritmo da bolha - compara em dupla até q não aja mais o q ordenar
// ex: 5 3 8 4 6 => compara os dois primeiros e vê qual é o menor => 3 5 8 4 6
// compara o segundo 5 com o teceiro 8 => 3 5 8 4 6 e vai no mesmo ritmo
// compara 8 e 4 = 3 5 4 8 6 (resultado)
// compara 8 e 6 = 3 5 4 6 8 (resultado)
// compara 3 e 5 = 3 5 4 8 6 (resultado)
// compara 5 e 4 = 3 4 5 8 6 (resultado)
// compara 5 e 8 = 3 4 5 8 6 (resultado)
// compara 8 e 6 = 3 4 5 6 8 (resultado), até finalmente estar em ordem
// qndo ordenado ja quase ordenado é bom, qndo em ordem decrescente é demorado, quase não é utilizado pela lentidão
void bubble_sort(int vetor[TAM]){

    //Auxiliares
    int x, y, aux;

    //Valor da esquerda sendo analisado
    for(x = 0; x < TAM; x++){

    //ao contrário do descrito acima, aqui ele está comparando o x com todos os outros e colocando em x o menor valor
        //Valor da direita sendo analisado
        for(y = x + 1; y < TAM; y++){

            imprimeVetor(vetor);

            //Confere se precisa fazer a troca
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }
}

/*********************************************** 01 *************************************************/
//======================================== Bubble Sort MEU ===========================================
void bubble_sort_meu(int vetor[TAM]){
    int cont, i, aux, modificacoes = 0;

    for(cont = 1; cont < TAM; cont++){//vou passar o número de vezes q tenho no vetor menor uma
    // já q o último valor não precisa ser comparado com ele mesmo
    // podia ser de 0 até TAM -1
        for(i = 0 ;i < TAM - 1; i++){// TAM - 1, é pq no último espaço se eu comparar o 10º termo com o 11º
            // vai dar erro!!!
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                modificacoes++;
            }
            imprimeVetor(vetor);
        }
        if(modificacoes == 0){//aqui é pra finalizar caso já ordenado,
            // ESSE TIPO DE IF NO MEIO VIRA UM "E" LÁ NO PRIMEIRO FOR, PORÉM É PRECISO MUDAR PRA WHILE
            // ENTÃO while(cont < TAM) && (modificacoes != 0).... deixei assim por ser mais didático pra mim
            cont = TAM;
        }
    }
}

/*********************************************** 02 *************************************************/
//======================================== Insertion Sort ============================================
// sempre q se depara com um novo valor, compara o valor dele com o menor e sucessivamente até encontrar
// sua posição. onde este é colocado
// bom pra qndo já quase ordenado e ruim para matriz inversa
// como cartas q vc vai ordenando
void insertion_sort(int vetor[TAM]){

    int i, j, atual;

    for(i = 1; i < TAM; i++){// começa no segundo pq não tem pq comparar o primeiro com ele mesmo

        //Elemento atual em análise
        atual = vetor[i];

        //Elemento anterior ao analisado
        j = i - 1;

        // anda do último até o primeiro e para assim q acha o local do número, ou esse se torna o primeiro número
        // q é o >=0
        //Analisando membros anteriores
        while( (j >=0) && (atual < vetor[j])){

            //Posiciona os elmeentos uma posição para frente
            vetor[j + 1] = vetor[j];

            //Faz o j andar para trás
            j = j - 1;
        }

        //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
        vetor[j + 1] = atual;

        //Mostra a lista atualizada
        imprimeVetor(vetor);
    }
}


/********************************************** 03 *************************************************/
//======================================== Selection Sort ===========================================
// simples e ocupa pouca memória, bom para vetores pequenos
// ele percorre a lista, acha o menor valor e põe na posição atual.
void selection_sort(int vetor[TAM]){

    int posicaoDoMenorValor, aux, i, j;

    for(i = 0; i < TAM; i++){

        //Recebe a posicao inicial para o menor valor
        posicaoDoMenorValor = i;

        //Analisa os elementos na frente
        for(j = i + 1; j < TAM; j++){

            //Caso encontre um valor menor na frente dos analisados
            if(vetor[j] < vetor[posicaoDoMenorValor]){
                posicaoDoMenorValor = j;
            }
        }

        //Verifica se houve mudança e troca os valores
        if(posicaoDoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }
        imprimeVetor(vetor);
    }

}


/*********************************************** 04 *************************************************/
//========================================== Quick Sort ==============================================
// utilizado qndo vc não sabe como a lista vai estar, sendo bem rápido
// ajusta em conjuntos menores e os organiza e depois organiza tudo.
// é preciso sempre limites (inicial e final) pra definir os blocos
// É UM MÉTODO RECURSIVO, ONDE VC CHAMA ELE MESMO
void quick_sort(int vetor[TAM], int inicio, int fim){

    int pivo, esq, dir, meio, aux;

    //Limites da esquerda e direita da região analisada
    esq = inicio; // não era necessário passar inicio e fim, uma vez q TAM já nos fornece, inicio = 0, e fim = TAM -1
    dir = fim;// porém, por se tratar de uma recursividade, os valores vão ser diferentes a cada giro
    // gerando os BLOCOS

    //Ajustando auxiliares do centro
    meio =  (int) ((esq + dir) / 2);// transforma o valor do resultado em int
    pivo = vetor[meio]; // pivô é o valor q está no meio da lista


    while(dir > esq){

        while(vetor[esq] < pivo){
            esq = esq + 1;
        }

        while(vetor[dir] > pivo){
            dir = dir - 1;
        }

        if(esq <= dir){
            //Realiza uma troca
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;

            //Faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;
        }
        imprimeVetor(vetor);
    }

    //Recursão para continuar ordenando
    if(inicio < dir){
        quick_sort(vetor, inicio, dir);
    }

     //Recursão para continuar ordenando
    if(esq < fim){
         quick_sort(vetor, esq, fim);
    }
}


/*********************************************** 05 *************************************************/
//========================================== Shell Sort ==============================================
// funciona bem pra listas grandes
// compara itens mais distantes da lista e faz a troca, é tipo o bubble só q distante
// no caso abaixo usou-se de três em três. comparo o 1º número com o 4º (pulo 3 casas)
// o 2º com o 5º etc. depois diminuo o fator de 3, para dois e faço a comparação mais próxima até comparar
// com o q estiver ao lado.
// funciona como o insertion só q com pulos maiores q vão diminuindo, faz ficar mais rápido -!?-

void shell_sort(int vetor[TAM]){
    int i, j, atual;
    int h = 1;// h representa o espaço entre as casas avaliadas

    //De quantos em quantos será o pulo entre análises
    while(h < TAM){
        h = 3*h+1;// no 1º giro = 3*1+1=4, vai para o segundo giro 3*4+1=13
    }

    while(h > 1){

        //Reduz a distância entre as análises
        h = h / 3;// 13/3= 4,? ..... como h é int fica só 4

        for(i = h; i < TAM; i++){

            //Elemento atual em análise
            atual = vetor[i];//1º volta i=4

            //Elemento anterior ao analisado
            j = i - h;//1º volta 4-4=0

            //Analisando membros anteriores
            while( (j >=0) && (atual < vetor[j])){//1º volta j=0 → (vetor[4] < vetor[0]) → se o valor for menor

                //Posiciona os elmeentos uma posição para frente
                vetor[j + h] = vetor[j];//vetor[0 + 4] = vetor[0] → a primeira parte é pra ficar dinâmico, por isso
                // não foi direto o vetor[i], tem q somar mais 4 sempre

                //Faz o j andar para trás
                j = j - h;// j=0 - h=4 = -4, vai sair do loop, geralmente qndo é assim poderia ser colocado como
                // condição no while
            }

            //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
            vetor[j + h] = atual;// o j=-4 + h=4 = 0, fica redundante pq a condição do while foi mal feita

            imprimeVetor(vetor);
        }
    }
}


/*********************************************** 06 *************************************************/
//========================================== Merge Sort ==============================================

void merge_sort(int vetor[TAM], int indiceEsquerdo, int indiceDireito){// primeiro índice = 0 e último TAM - 1

    if(indiceEsquerdo < indiceDireito){

        //Encontra o meio
        int meio = indiceEsquerdo + (indiceDireito - indiceEsquerdo) / 2;

        //Da metade para trás
        merge_sort(vetor, indiceEsquerdo, meio);

        //Da metade para frente
        merge_sort(vetor, meio + 1, indiceDireito);

        //Une os dois subarrays que foram criados
        merge(vetor, indiceEsquerdo, meio, indiceDireito);
    }
}

//Juta os dois subarrays criados ao dividir o vetor principal
void merge(int vetor[TAM], int indiceEsquerdo,int meio, int indiceDireito){

    int i, j, k ;                       //Auxiliares
    int n1 = meio - indiceEsquerdo + 1; //Tamaho do primeiro vetor auxiliar
    int n2 = indiceDireito - meio;      //Tamaho do segundo vetor auxiliar

    //Cria dois Arrays temporários
    int vetorEsquerdo[n1], vetorDireito[n2];

    //Passa os elementos do vetor principal para o primeiro vetor auxiliar (Esquerda)
    for(i = 0; i < n1; i++){
        vetorEsquerdo[i] = vetor[indiceEsquerdo + i];
    }

    //Passa os elementos do vetor principal para o segundo vetor auxiliar (Direita)
    for(j = 0; j < n2; j++){
        vetorDireito[j] = vetor[meio + 1 + j];
    }

    //Reseta as variáveis
    i = 0;
    j = 0;
    k = indiceEsquerdo;

    while(i < n1 && j < n2){

        //Caso o valor na esquerda seja menor
        if(vetorEsquerdo[i] <= vetorDireito[j]){

            //Passa para o meu vetor principal o valor menor
            vetor[k] = vetorEsquerdo[i];

            //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
            i++;
        } else{

            //Passa para o meu vetor principal o valor menor
            vetor[k] = vetorDireito[j];

            //Incrementa o auxiliar para passar a análise para os próximos valores do vetor auxiliar
            j++;
        }

        //Aumenta o índice de posicionamento do vetor
        k++;
    }

    //Se faltarem alguns elemntos do array ESQUERDO passa eles para o array principal
    while(i < n1){
        vetor[k] = vetorEsquerdo[i];
        i++;
        k++;
    }

    //Se faltarem alguns elemntos do array DIREITO passa eles para o array principal
    while(j < n2){
        vetor[k] = vetorDireito[j];
        i++;
        k++;
    }
}


/****************************************************************************************************/
//======================================== FUNÇÕES GENÉRICAS =========================================
//====================================================================================================
//====================================================================================================
/***********************************************/
void imprimeVetor(int vetor[]){
    int i;
    printf("\n");
    //cout << "\n";
    for(i = 0; i < TAM; i++){
        printf(" | %d| ", vetor[i]);
        //cout << " |" << vetor[i] << "| ";
    }
}


