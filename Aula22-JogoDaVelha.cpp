#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//�rea de defini��o de cabe�alhos de fun��o
void limpaTela(); //==================================== 01 ==========================================
void menuInicial(); //================================== 02 ==========================================
void iniciaTabuleiro(char tabuleiro[3][3]); //========== 03 ==========================================
void exibeTabuleiro (char tabuleiro[3][3]); //========== 04 ==========================================
int confereTabuleiro(char tabuleiro[3][3]); //========== 05 ==========================================
void exibeInstrucoes(); //============================== 06 ==========================================
//========================================= LOOP DO JOGO 07 ==========================================
void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois);



/****************************************************************************************************/
//========================================== JOGO DA VELHA ===========================================
//=============================================== MAIN ===============================================
//====================================================================================================
int main(){
    menuInicial(); /*************************** 02 **************************************************/
    return 0;
}

/****************************************************************************************************/
//============================================ FUN��ES ===============================================
//====================================================================================================
//=============================================== 01 =================================================
void limpaTela(){
    system("CLS");
}


//====================================================================================================
//=============================================== 02 =================================================
void menuInicial(){

    //Op��o escolhida pelo usu�rio
    int opcao = 0;

    //Nome dos jogadores
    string nomeDoJogadorUm, nomeDoJogadorDois;

    //Enquanto o jogador n�o digita uma opcao v�lida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela(); /*************************** 01 ************************************************/
        cout << "Bem vindo ao Jogo da Velha";
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
                cout << "Digite o nome do jogador 1:";
                cin >> nomeDoJogadorUm;
                cout << "Digite o nome do jogador 2:";
                cin >> nomeDoJogadorDois;
                jogo(nomeDoJogadorUm, nomeDoJogadorDois,0,0); /**** 07 ****************************/
                // os zeros no final, s�o referentes �s pontua��es dos jogadores, como aqui � o in�cio
                // as pontua��es come�am zeradas
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
void iniciaTabuleiro(char tabuleiro[3][3]){
    //Navega por cada posi��o do tabuleiro e coloca o s�mbolo de '-'
    int linha,coluna;
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}


//====================================================================================================
//=============================================== 04 =================================================
void exibeTabuleiro (char tabuleiro[3][3]){// s� printa mesmo
     //Exibe o tabuleiro com suas linhas e colunas quebrando a linha ao sair de um for
    int linha,coluna;
    cout << "\n";
    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            cout << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }

}


//====================================================================================================
//=============================================== 05 =================================================
//1 = X venceu, 2 = O venceu, 0 = Nada Aconteceu
int confereTabuleiro(char tabuleiro[3][3]){// aqui s�o todas as condi��es de vit�ria

        int linha, coluna;

        //Confere linhas
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 1;
            }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                return 2;
            }
        }

        //Confere Colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 1;
            }else if(tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                return 2;
            }
        }

        //Diagonal Principal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){

            if(tabuleiro[0][0] == 'X'){
               return 1;
            }else{
               return 2;
            }
        }

        //Diagonal Secund�ria
        if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){

            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else{
               return 2;
            }
        }

        return 0;// s� retorna zero se nada acontecer
}


//====================================================================================================
//=============================================== 06 =================================================
void exibeInstrucoes(){
    cout << "\nMapa de Posicoes:";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
}


//====================================================================================================
//=============================================== 07 =================================================
void jogo(string nomeDoJogadorUm, string nomeDoJogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){

    ///Vari�veis Gerais
    string nomeDoJogadorAtual;//Nomes dos jogadores
    char tabuleiro[3][3];                                       //Tabuleiro do Jogo
    int linha,coluna;                                           //Auxiliares para tabuleiro
    int linhaJogada,colunaJogada,posicaoJogada;                 //Posi��o em que o jogador posiciona sua marca
    int estadoDeJogo = 1;                                       //0 = Sem jogo,1 = Em Jogo
    int turnoDoJogador = 1;                                     //1 = X, 2 = O
    int rodada = 0;                                             //Quantas vezes os jogadores jogaram no total
    int opcao;                                                  //Op��o de rein�cio
    bool posicionouJogada;                                      //Verifica se o jogador colocou um marcador no tabuleiro

    //Coloca os '-' no tabuleiro para indicar o vazio
    iniciaTabuleiro(tabuleiro); /*************************** 03 *************************************/

//====================================================================================================
    while(rodada < 9 && estadoDeJogo == 1){

        limpaTela(); /*************************** 01 ************************************************/

        cout << "\nRodada:" << rodada << "\n";
        cout << "Pontuacao:" << nomeDoJogadorUm << " " << pontuacaoJogadorUm << " x " << pontuacaoJogadorDois << " " << nomeDoJogadorDois;

        //Exibe o tabuleiro na tela
        exibeTabuleiro(tabuleiro); /************* 04 ************************************************/

        //Exibe qual numero corresponde a qual posicao
        exibeInstrucoes(); /*************************** 06 *****************************************/


        //Atualiza o nome do jogador atual
        if(turnoDoJogador == 1){

            nomeDoJogadorAtual = nomeDoJogadorUm;

        }else{

            nomeDoJogadorAtual = nomeDoJogadorDois;

        }

        posicionouJogada = false;

        //Matriz de posicoes poss�veis - usada para poder jogar apenas digitando um n�mero
        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};


//====================================================================================================
        while(posicionouJogada == false){// tudo q � preciso pra uma rodada

            //L� a jogada
            cout << "\n" << nomeDoJogadorAtual << "Digite uma posicao conforme o mapa acima:";
            cin >> posicaoJogada;

            //Passa a linha e coluna de acordo com a matriz de posi��es exibida no mapa
            linhaJogada = posicoes[posicaoJogada-1][0];// o menos um � pra ajeitar, digitamos de 1 at� 9
            colunaJogada = posicoes[posicaoJogada-1][1]; // e nas linhas temos o zero, assim como na coluna
            // repare q se digitar 7, 7 - 1 = 6, sendo o 6� n�mero da matriz (0, 0) linha 6, a coluna � definida
            // pelo segundo n�mero zero para o primeiro (linha 6 coluna 0 = 0) e no outro (linha 6 coluna 2 = 0)
            // passando dois n�meros de coordenadas, ent�o 7 = coord 0, 0

            //Verifica se a posi��o � vazia
            if(tabuleiro[linhaJogada][colunaJogada] == '-'){// se a posi��o estiver vazia ent�o vai verificar
                // se X ou O para poder jogar

                //Conseguiu posicionar um marcador
                posicionouJogada = true;

                //Verifica de quem � a vez para posicionar o marcador
                if(turnoDoJogador == 1){

                    tabuleiro[linhaJogada][colunaJogada] = 'X';

                    turnoDoJogador = 2;

                }else{

                    tabuleiro[linhaJogada][colunaJogada] = 'O';

                    turnoDoJogador = 1;
                }
            }
        }// final da rodada


//====================================================================================================
        //Confere se o jogo acabou
        if(confereTabuleiro(tabuleiro) == 1){ /*********** 05 ***************************************/
            cout << "O jogador X venceu";// v� quem venceu de acordo com a fun��o
            pontuacaoJogadorUm++;
            estadoDeJogo = 0;
        }else if(confereTabuleiro(tabuleiro) == 2){ /***** 05 ***************************************/
            cout << "O jogador O venceu";
            pontuacaoJogadorDois++;
            estadoDeJogo = 0;
        }
        //Aumenta uma rodada
        rodada++;
    }// FIM DO LOOP DO GAME


//====================================================================================================
    exibeTabuleiro(tabuleiro); /************************** 04 ***************************************/
    cout << "Fim de jogo";
    cout << "\nO que deseja fazer?";
    cout << "\n1-Continuar Jogando";
    cout << "\n2-Menu Inicial";
    cout << "\n3-Sair";
    cin >> opcao;
    if(opcao == 1){
        // Se continuar jogando volta pro jogo - com os mesmos nomes de jogadores
        // envia tbm as pontua��es da rodada anterior
        jogo(nomeDoJogadorUm, nomeDoJogadorDois,pontuacaoJogadorUm,pontuacaoJogadorDois); /** 07 ***/
    }else if(opcao == 2){
        menuInicial(); // se n�o quiser mais jogar volta para menu inicial e insere novos nomes
    }

}




