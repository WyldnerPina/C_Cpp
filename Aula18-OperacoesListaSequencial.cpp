#include <iostream>
#include <new> // biblioteca para poder gerar vetores em C++
#include <string>
#include <stdlib.h>
#define TAM 3 // Usado somente nos métodos alocaVet

using namespace std; //para utilizar cout
void alocaVetC();// minha função pra simplificar um processo
void alocaVetCPP();

/****************************************************************************************************/
//============================================ STRUCTS ===============================================
//====================================================================================================
//====================================================================================================
///Struct para pessoa
struct pessoa{
    string nome;
    int rg;
};


/****************************************************************************************************/
//============================================ FUNÇÕES ===============================================
//====================================================================================================
//====================================================================================================
/*********************************************** 01 *************************************************/
///Limpa a tela
void limpatela(){
    system("CLS");
}


//====================================================================================================
/*********************************************** 02 *************************************************/
///Imprime a lista Sequencial
void imprimeSequencial(pessoa *ponteiroSequencial,int tamanhoDaListaSequencial) {// ponteiroSequencial
    // do tipo pessoa e o tamanho da lista pra poder printar

   //Cabeçaalho da Lista
   cout << "\nLista: \n";

   //Imprime a lista com separacao de virgulas e indices
   int cont;
   for(cont = 0; cont < tamanhoDaListaSequencial ; cont++)
        cout << cont << " - " << ponteiroSequencial[cont].nome << "," << ponteiroSequencial[cont].rg << "\n";
}


//====================================================================================================
/*********************************************** 03 *************************************************/
///Adiciona um membro ao início da lista
void adcComecoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg){

    //Caso a lista nao possua elementos, cria uma nova
    if(*tamanhoDaListaSequencial == 0){
        //Cria uma nova lista
        pessoa *novalistaSequencial = new pessoa[1];

        //Coloca o primeiro membro
        novalistaSequencial[0].nome = nome;
        novalistaSequencial[0].rg = rg;

        //Faz o ponteiro apontar para a nova lista
        ponteiroSequencial = novalistaSequencial;
    }else{
        //Cria um vetor auxiliar com uma posicao a mais
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];

        //Posiciona o primeiro elemento
        copiaListaSequencial[0].nome = nome;
        copiaListaSequencial[0].rg = rg;

        //Passa os elementos da lista antiga para a nova uma posicao a frente
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont+1].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont+1].rg = ponteiroSequencial[cont].rg;
        }
        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;
    }
    //Atualiza o tamanho da lista
    *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;
}


//====================================================================================================
/*********************************************** 04 *************************************************/
///Adiciona um membro ao fim da lista
void adcFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg,int *posicaoNaLista){

        //Posicao na lista
        *posicaoNaLista = *tamanhoDaListaSequencial;

        //Cria um vetor com uma posicao a mais
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];

        //Posiciona o ultimo elemento no tamanhoNovo -1 , pois começamos contando do 0
        copiaListaSequencial[*tamanhoDaListaSequencial].nome = nome;
        copiaListaSequencial[*tamanhoDaListaSequencial].rg = rg;

        //Passa os elementos da lista antiga para a nova
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }

        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;

        //Atualiza o tamanho da lista
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;
}


//====================================================================================================
/*********************************************** 05 *************************************************/
///Adiciona um membro numa posicao especifica
void adcPosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,string nome,int rg,int posicao){

        //Cria um vetor com uma posicao a mais
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial + 1];

        //Passa os elementos da lista antiga para a nova ate o elemento desejado
        int cont;
        for(cont = 0; cont < posicao; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }

        //Posiciona o elemento na posicao desejada
        copiaListaSequencial[posicao].nome = nome;
        copiaListaSequencial[posicao].rg = rg;

        //Continua posicionando os outros elementos apos a posicao desejada
        for(cont = posicao + 1; cont < *tamanhoDaListaSequencial + 1; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont-1].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont-1].rg;
        }

        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;

        //Atualiza o tamanho da lista
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial + 1;
}


//====================================================================================================
/*********************************************** 06 *************************************************/
///Remove o elemento inicial
void removeInicioSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial){

        //Cria um vetor com uma posicao a menos
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];

        //Passa os elementos da lista antiga ignorando o primeiro para a nova ate o elemento desejado
        int cont;
        for(cont = 1; cont < *tamanhoDaListaSequencial; cont++){
            copiaListaSequencial[cont-1].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont-1].rg = ponteiroSequencial[cont].rg;
        }

        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;

        //Atualiza o tamanho da lista
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;
}


//====================================================================================================
/*********************************************** 07 *************************************************/
///Remove o elemento final
void removeFimSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int *posicaoNaLista){

        //Posiçao na lista
        *posicaoNaLista = *tamanhoDaListaSequencial - 1;

        //Cria um vetor com uma posicao a menos
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];

        //Passa os elementos da lista antiga ignorando o primeiro para a nova ate o elemento desejado
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial - 1; cont++){
            copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
            copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        }

        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;

        //Atualiza o tamanho da lista
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;
}


//====================================================================================================
/*********************************************** 08 *************************************************/
///Remove um elemento por posição
void removePosicaoSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int posicao){

        //Cria um vetor com uma posicao a mais
        pessoa *copiaListaSequencial = new pessoa[*tamanhoDaListaSequencial - 1];

        //Passa os elementos da lista antiga para a nova ate o elemento desejado
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial - 1; cont++){
            if(cont < posicao){
                //Faz uma copia dos elementos ate a posicao
                copiaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
                copiaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
            }else{
                //Faz uma copia dos elementos ate a posicao
                copiaListaSequencial[cont].nome = ponteiroSequencial[cont+1].nome;
                copiaListaSequencial[cont].rg = ponteiroSequencial[cont+1].rg;
            }
        }

        //Faz o ponteiroSequencial apontar para a nova lista com um elemento extra
        ponteiroSequencial = copiaListaSequencial;

        //Atualiza o tamanho da lista
        *tamanhoDaListaSequencial = *tamanhoDaListaSequencial - 1;
}


//====================================================================================================
/*********************************************** 09 *************************************************/
///Retorna o nome pelo RG
string retornaNomeSequencial(pessoa *&ponteiroSequencial,int *tamanhoDaListaSequencial,int rg,int *posicao){

        //Nome a ser retornado
        string nome = "Nao Encontrado";

        //Passa os elementos da lista antiga para a nova ate o elemento desejado
        int cont;
        for(cont = 0; cont < *tamanhoDaListaSequencial; cont++){

            //Se encontrar alguem com o RG procurado
            if(ponteiroSequencial[cont].rg == rg){

                //Faz uma copia dos elementos ate a posicao
                nome = ponteiroSequencial[cont].nome;

                cout << "Encontrado na Posicao:" << cont <<"\n";
            }
        }
        return nome;
}


/****************************************************************************************************/
//========================= ESTRUTURA DE DADOS - BUSCA E OPERAÇÕES COM LISTA =========================
//============================================= MAIN =================================================
//====================================================================================================
int main(){

    //Variáveis
    int funcaoDesejada = 1;// pra entrar no menu
    /*
    //Lista Sequencial Inicial com tamanho 1 e vazia
    //pessoa *copiaListaSequencial = new pessoa[1];

    //Dois registros de exemplo

    copiaListaSequencial[0].nome = "John";
    copiaListaSequencial[0].rg = 123;

    copiaListaSequencial[1].nome = "Maicon";
    copiaListaSequencial[1].rg = 123;
    */

    //Lista Sequencial Inicial
    pessoa *ponteiroSequencial;// instancia ponteiroSequencial
      /*
    //Aponta para a lista inicial vazia
    //ponteiroSequencial = copiaListaSequencial;*/

    //Tamanho inicial da lista
    int tamanhoDaListaSequencial = 0; // define tamanho da lista

//============================================= MENU =================================================
//====================================================================================================
     ///Manipula as listas
    while(funcaoDesejada <= 10 && funcaoDesejada > 0){// aqui podia ser diferente de 9 e somente o 9 sairia

        cout << "Tamanho Atual[" << tamanhoDaListaSequencial << "]\n";
        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista \n";
        cout << "2 - Insercao de um node no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "10 - Vetores dinâmicos em C e C++ \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";

        //Lê a opção
        cin >> funcaoDesejada;

        //Limpa as opções
        limpatela();

        //Variáveis para valores novos
        string nome;
        int rg, posicao,posicaoNaLista;

//====================================== INSERIR NODE NO INÍCIO ======================================
//====================================================================================================
        switch(funcaoDesejada){
            case 1:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Inserir um node no comeco da lista";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

 /*********************************************** 03 *************************************************/
                //Adiciona ao inicio da Lista ou cria uma nova
                adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);

                //Exibe o usuario inserido
                cout << "\nUsuario: " << nome << ",RG: " << rg << " adicionado ao inicio da lista.\n";
                break;


//====================================== INSERIR NODE NO FINAL =======================================
//====================================================================================================
            case 2:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Inserir um node no fim da lista";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(tamanhoDaListaSequencial == 0){
/*********************************************** 03 *************************************************/
                    //Se for o primeiro da lista cria uma nova lista
                    adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);
                }else{
/*********************************************** 04 *************************************************/
                    //Adiciona ao fim da Lista
                    adcFimSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg, &posicaoNaLista);
                }

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado ao fim da lista(" << posicaoNaLista << ")";
                break;


//==================================== INSERIR NODE NA POSIÇÃO N =====================================
//====================================================================================================
             case 3:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Inserir um node na posicao N da lista";

                 //Lendo valores do usuario
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                //Se pedir a primeira posição
                if(posicao == 0){
/*********************************************** 03 *************************************************/
                    //Se for o primeiro da lista cria uma nova lista
                    adcComecoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg);
                }else if(posicao == tamanhoDaListaSequencial + 1){
/*********************************************** 04 *************************************************/
                    //Adiciona ao fim da Lista
                    adcFimSequencial(ponteiroSequencial,&tamanhoDaListaSequencial, nome, rg, &posicaoNaLista);
                }else{
 /*********************************************** 05 *************************************************/
                    //Adiciona numa posicao específica
                    adcPosicaoSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, nome, rg, posicao);
                }

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado na posicao" << posicao<< "da lista.";
                break;


//======================================= RETIRAR NODE DO INÍCIO =====================================
//====================================================================================================
            case 4:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Retirar um node do inicio da lista\n";

                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{
/*********************************************** 06 *************************************************/
                    //Remove do inicio da lista
                    removeInicioSequencial(ponteiroSequencial, &tamanhoDaListaSequencial);
                    //Exibe o usuario removido
                    cout << "Usuario: " << nome <<",RG: "<<rg<< "foi removido do inicio da lista";
                }
                break;


//======================================= RETIRAR NODE DO FINAL ======================================
//====================================================================================================
            case 5:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Retirar um node do fim da lista\n";

                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{
/*********************************************** 07 *************************************************/
                    //Remove do final da lista
                    removeFimSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, &posicaoNaLista);
                    //Exibe o usuario removido
                    cout << "Usuario: "<<nome<<",RG: "<<rg<<" foi removido da posicao " << posicaoNaLista <<" da lista.";
                }
                break;


//====================================== RETIRAR NODE DE QQ LUGAR ====================================
//====================================================================================================
            case 6:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Retirar um node de uma posicao da lista\n";

                 //Lendo valores do usuario
                cout << "Digite a Posicao: ";
                cin >> posicao;

                if(tamanhoDaListaSequencial == 0){
                    cout << "Lista Vazia\n";
                }else{

                    if(posicao == 0){
/*********************************************** 06 *************************************************/
                        //Remove do inicio da lista
                        removeInicioSequencial(ponteiroSequencial, &tamanhoDaListaSequencial);
                    }else if(posicao == tamanhoDaListaSequencial - 1){
/*********************************************** 07 *************************************************/
                        //Remove do final da lista
                        removeFimSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, &posicaoNaLista);
                    }else{
/*********************************************** 08 *************************************************/
                        //Remove do posicao desejada da lista
                        removePosicaoSequencial(ponteiroSequencial,&tamanhoDaListaSequencial,posicao);
                    }
                }

                //Exibe o usuario removido
                cout << "Usuario: "<<nome<<",RG: "<<rg<<" foi removido da posicao "<< posicao <<" da lista.";
                break;


//====================================== RETORNA NOME E POSIÇÃO ======================================
//====================================================================================================
            case 7:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Retorna o nome e posicao pelo RG \n";

                //Lendo valores do usuario
                cout << "Digite um RG: ";
                cin >> rg;

/*********************************************** 09 *************************************************/
                //Retorna o nome pelo RG
                cout << "Nome:" << retornaNomeSequencial(ponteiroSequencial, &tamanhoDaListaSequencial, rg, &posicao);
                break;


//=========================================== IMPRIMIR ===============================================
//====================================================================================================
            case 8:
                //Cabeçalho da acao
                cout << "Funcao Escolhida: Imprime a lista\n";

/*********************************************** 02 *************************************************/
                imprimeSequencial(ponteiroSequencial, tamanhoDaListaSequencial);// só aqui imprime a lista
                // após fazer todas as mudanças anteriores e vc digitar 8.
                break;


//=========================================== IMPRIMIR ===============================================
//====================================================================================================
            case 9:
                //Cabeçalho da acao
                cout << "Flwwwwwwwwwwwwwwwwww\n";
                exit(0);
                break;


//================================== VETS DINÂMICOS - C & C++ ========================================
//====================================================================================================
            case 10:
                int escolhaC;
                cout << "Escolha C(1) ou CPP(2)\n";
                cin >> escolhaC;

                if(escolhaC == 1){
/*********************************************** 10 *************************************************/
                    alocaVetC();
                }else{
/*********************************************** 11 *************************************************/
                    alocaVetCPP();
                }
                break;
        }
    }
    return 0;
}



//====================================================================================================
/*********************************************** 10 *************************************************/
// aloca um vetor do tamanho pedido
void alocaVetC(){
//====================================================================================================
    //Vetor normal aqui
    printf("FAZENDO VETOR EM C\n");

    // Variáveis
    int vetor[TAM] = {1, 2, 3}, w;

    for(w = 0; w < TAM; w++){
        printf("valor %d = %d\n", w, vetor[w]);
    }
//====================================================================================================
    int tamanhoDaLista; // para vetores dinâmicos

    printf("digite o tamanho do vetor\n");
    scanf("%d", &tamanhoDaLista);

    int *v;
    // em C é preciso alocar memória pra fazer um vetor dinâmico
    // aloca memo para o novo vetor
    v = (int*) malloc(tamanhoDaLista * sizeof(int)); // malloc é a função para alocar memória e fazer o vetor dinâmico, dentro dele especificamos
    // o tamanho 'tam' multiplicado pelo tamanho do tipo da variável 'int'. O 'int*' antes é pra receber o valor como ponteiro


    for(w = 0; w < tamanhoDaLista; w++){
        printf("digite um valor\n");
        scanf("%d", &v[w]);
    }

    for(w = 0; w < tamanhoDaLista; w++){
        printf("valor %d = %d\n", w, v[w]);
    }
}



//====================================================================================================
/*********************************************** 11 *************************************************/
void alocaVetCPP(){
//====================================================================================================
    //Vetor normal aqui
    cout << "FAZENDO VETOR EM C++\n";

    // Variáveis
    int vetor[TAM] = {1, 2, 3}, w;

    for(w = 0; w < TAM; w++){
        cout << "valor "<< w <<" = " << vetor[w] << "\n";
    }
//====================================================================================================
    int tamanhoDaLista; // para vetores dinâmicos

    cout << "digite o tamanho do vetor\n";
    cin >> tamanhoDaLista;

    int *vetCPP = new int[tamanhoDaLista];

    for(w = 0; w < tamanhoDaLista; w++){
        cout << "digite um valor\n";
        cin >> vetCPP[w];
    }

    for(w = 0; w < tamanhoDaLista; w++){
        cout << "valor "<< w <<" = " << vetCPP[w] << "\n";
    }
}
