#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

//Cabeçalhos de funções
void limpaTela(); //==================================== 01 ==========================================
void menuInicial(); //================================== 02 ==========================================
void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]); //===== 03 =======================
void exibeMapa(); //==================================== 04 ==========================================
void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito); //== 05 ======
void posicionaBarcos(char tabuleiro[10][10]); //======== 06 ==========================================
//====================================================== 07 ==========================================
void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem);
void jogo(string nomeDoJogador); //======== LOOP DO JOGO 08 ==========================================


/****************************************************************************************************/
//========================================== BATALHA NAVAL ===========================================
//=============================================== MAIN ===============================================
//====================================================================================================
int main(){
    //Para gerar números realmente aleatórios
    srand((unsigned)time(NULL));

    menuInicial(); /*************************** 02 **************************************************/
    return 0;
}


/****************************************************************************************************/
//============================================ FUNÇÕES ===============================================
//====================================================================================================
//=============================================== 01 =================================================
void limpaTela(){
    system("CLS");
}

//====================================================================================================
//=============================================== 02 =================================================
void menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Nome do usuário
    string nomeDoJogador;

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela(); /*************************** 01 ************************************************/
        cout << "Bem vindo ao Jogo de Batalha Naval";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        //Faz a leitura da opcao
        cin >> opcao;

        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                //cout << "Jogo iniciado";
                cout << "Qual seu nome?";
                cin >> nomeDoJogador;
                jogo(nomeDoJogador); /********** 08 ************************************************/
                break;
            case 2:
                //Mostra informacoes do Jogo
                cout << "Informacoes do jogo";
                break;
            case 3:
                cout << "Ate mais!";
                break;
        }
    }
}


//====================================================================================================
//=============================================== 03 =================================================
void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){

     //Popula o tabuleiro com Água
    int linha,coluna;
    for(linha = 0; linha < 10; linha++){
         for(coluna = 0; coluna < 10; coluna++){ // são duas matrizes, uma com ~ para água
            tabuleiro[linha][coluna] = '~'; // põe todas as posições em Agua
            mascara[linha][coluna] = '*'; // e tudo como asterisco pra partes ocultas
         }
    }
}


//====================================================================================================
//=============================================== 04 =================================================
void exibeMapa(){// serve apenas para indicar a numeração de cada coluna
    //Mapa indicador de colunas
    int cont;
    for(cont = 0; cont < 10; cont++){// são dez colunas
        if(cont == 0){// na primeira, o espaço é maior pra ajeitar com o tabuleiro
            cout << "     ";
        }
        cout << cont << " ";// nas outras só um espacinho
    }
    cout << "\n";// pula a linha

    for(cont = 0; cont < 10; cont++){// agora é uma linha, abaixo do número, pra indicar a coluna
        if(cont == 0){// segue os mesmos espaços já q a linha está abaixo dos números
            cout << "     ";
        }
        cout << "| ";
    }
    cout << "\n";
}


//====================================================================================================
//=============================================== 05 =================================================
void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito){
    // ele pegou o cód na net, a fileira antes do "m" é a correspondente à cor
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };// branco

    //Exibe o tabuleiro
    int linha,coluna;
    for(linha = 0; linha < 10; linha++){
         cout << linha << " - "; // aparece antes de cada linha pra indicar a numeração da linha
         for(coluna = 0; coluna < 10; coluna++){

            switch(mascara[linha][coluna]){
                case '~':
                    cout << blue << " " <<mascara[linha][coluna] << normal;// blue chama a var q carrega a cor
                    break;
                case '^':
                    cout << green << " " <<mascara[linha][coluna] << normal;
                    break;
                default:
                    cout << " " <<mascara[linha][coluna];
                    break;
            }
         }
         cout << "\n";
    }

    if(mostraGabarito == true){
        for(linha = 0; linha < 10; linha++){
             for(coluna = 0; coluna < 10; coluna++){
                 cout << " " <<tabuleiro[linha][coluna];
             }
             cout << "\n";
        }
    }
}


//====================================================================================================
//=============================================== 06 =================================================
void posicionaBarcos(char tabuleiro[10][10]){

    //Coloca 10 barcos no tabuleiro
    int cont, quantidade = 10, quantidadePosicionada = 0;

    //Verifica se já posicionou todos os barcos
    while(quantidadePosicionada < quantidade){

        int linhaAleatoria = rand() % 10;  //Gera número aleatório de 0 a 9
        int colunaAleatoria = rand() % 10; //Gera número aleatório de 0 a 9

        if(tabuleiro[linhaAleatoria][colunaAleatoria] == '~'){

            //Posiciona 10 barcos aleatoriamente
            tabuleiro[linhaAleatoria][colunaAleatoria] = '^';

            //Aumenta o contador de barcos posicionados
            quantidadePosicionada++;
         }
    }
}


//====================================================================================================
//=============================================== 07 =================================================
void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){

    //Verifica quantos pontos adicionar - usou case para colocar mais barcos se quiser
    switch(tabuleiro[linhaJogada][colunaJogada]){
        case '^':
            *pontos = *pontos + 10;
            *mensagem = "Voce acertou um barco pequeno! (10 pts)";
            break;
        case '~':
            *mensagem = "Voce acertou a agua";
            break;
    }

}


//====================================================================================================
//=============================================== 08 =================================================
void jogo(string nomeDoJogador){

    ///Variáveis Gerais
    char tabuleiro[10][10],mascara[10][10];             //Tabuleiro do Jogo → mostrado em caracteres
    int linha,coluna;                                   //Auxiliares de navegação
    int linhaJogada, colunaJogada;                      //Posicao escolhida pelo jogador
    int estadoDeJogo = 1;                               //1 = Jogo Acontecendo, 0 = Fim de Jogo
    int pontos = 0;                                     //Pontuação do Jogador
    int tentativas = 0, maximoDeTentativas = 5;         //Tentativas do jogador
    int opcao;                                          //Opções de fim de jogo
    string mensagem = "Bem vindo ao jogo!";             //Mensagem de feedback para o jogador

    //Inicia o tabuleiro com água
    iniciaTabuleiro(tabuleiro,mascara); /******* 03 ************************************************/

    //Posiciona barcos aleatoriamente
    posicionaBarcos(tabuleiro); /*************** 06 ************************************************/


//========================================  LOOP DO JOGO ============================================
    while(tentativas < maximoDeTentativas){

        limpaTela(); /************************** 01 ************************************************/

        //Exibe o mapa de indicações
        exibeMapa(); /************************** 04 ************************************************/

        //Exibe tabuleiro
        exibeTabuleiro(tabuleiro,mascara, false); /************ 05 *********************************/

        cout << "\nPontos:" << pontos << ", Tentativas Restantes:" << maximoDeTentativas - tentativas;
        cout << "\n" << mensagem;


//====================================================================================================
// aqui é o bloco onde será digitado linha e coluna, começa em negativo para q entre no while
// (podia usar o do while), uma vez digitado um valor fora do esperado (<0 ou >9 tanto para linha ou coluna)
// é repetida a pergunta e o jogador não perde a tentativa
        //Verificação de dados
        linhaJogada = -1;
        colunaJogada = -1;

        // aqui é onde, após inicializar tudo é perguntado ao jogador qual linha e qual coluna ele quer jogar
        while( (linhaJogada < 0 || colunaJogada < 0) ||  (linhaJogada > 9 || colunaJogada > 9)) {

            cout << "\n" << nomeDoJogador << ", digite uma linha:";
            cin >> linhaJogada;
            cout <<  "\n" << nomeDoJogador << ", digite uma coluna:";
            cin >> colunaJogada;
        }
//====================================================================================================

        //Verifica o que aconteceu para pontuar
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem); /********** 07 *****/

        //Revela o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada]; // aqui revela o q tem no espaço desejado

        tentativas++; // jogo será encerrado se tentativas chegar ao máx
        //(ou vc acertar todos os barcos, mas com 5 tentativas em 100 é tão difícil q nem precisou colocar a condição

    }// ENCERRA LOOP DO JOGO


//====================================================================================================
    // qndo encerra ele não exibe o mapa com a última jogada se não repetir esses códigos

        limpaTela(); /************************** 01 ************************************************/

        //Exibe o mapa de indicações
        exibeMapa(); /************************** 04 ************************************************/

        //Exibe tabuleiro
        exibeTabuleiro(tabuleiro,mascara, false); /************ 05 *********************************/


//====================================================================================================
    cout << "Fim de jogo, o que deseja fazer?";
    cout << "\n1-Jogar Novamente";
    cout << "\n2-Ir para o Menu";
    cout << "\n3-Sair"; // sai automaticamente se digitar qq coisa diferente de 1 e 2
    cin >> opcao;
    switch(opcao){
        case 1:
            jogo(nomeDoJogador); /***************** 08 **********************************************/
            break;
        case 2:
            menuInicial(); /*********************** 02 **********************************************/
            break;
           }
}

