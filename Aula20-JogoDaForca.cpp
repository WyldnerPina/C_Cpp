#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h> // para aleatoriedade

using namespace std;

void limpaTela(); //==================================== 01 ==========================================
void menuInicial(); //================================== 02 ==========================================
string retornaPalavraAleatoria(); //==================== 03 ==========================================
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra); //====== 04 ===================
void exibeStatus(string palavraComMascara, int tamanhoDaPalavra,
                 int tentativasRestantes, string letrasJaArriscadas, string mensagem); //== 05 =======
int jogar(int numeroDeJogadores);//===================== 06 ==========================================

/****************************************************************************************************/
//========================================== JOGO DA FORCA ===========================================
//=============================================== MAIN ===============================================
//====================================================================================================
int main(){

    // PARA GERAR NÚMEROS ALEATÓRIOS é preciso desse cód
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

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela(); /*************************** 01 ************************************************/
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar Sozinho";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER:";

        //Faz a leitura da opcao
        cin >> opcao;


//====================================================================================================
        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo: 1 = jogador
                if(jogar(1) == 1){ /************* 06 ************************************************/
                    menuInicial(); /************* 01 ************************************************/
                }
                break;
            case 2:
                //Inicia o jogo: 2 = jogadores
                if(jogar(2) == 1){ /************* 06 ************************************************/
                    menuInicial(); /************* 01 ************************************************/
                }
                break;
            case 3:
                //Mostra informacoes do Jogo
                cout << "Informacoes do jogo";
                limpaTela(); /******************** 01 ***********************************************/
                cout << "Jogo desenvolvido por Joao em 2017";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial(); /************* 01 ************************************************/
                }

                break;
            case 4:
                cout << "Ate mais!";
                break;
        }
    }

}


//====================================================================================================
//=============================================== 03 =================================================
string retornaPalavraAleatoria(){

     //Vetor com palavras disponíveis
    string palavras[3] = {"abacaxi", "manga", "morango"};

    //Indice gerado no intervalo {0,1,2} → qndo vc divide por três só irá haver apenas três resultados
    int indiceAleatorio = rand() % 3;

    //Exibe a palavra aleatória
    //cout << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];// aqui é retornado a palavra no índice aleatório resultante do
    // processo anterior
}


//====================================================================================================
//=============================================== 04 =================================================
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){// dá pra ver q a palavra em si
    // não tem utilidade nessa função
    int cont = 0;
    string palavraComMascara;

    //Coloca uma máscara
    while(cont < tamanhoDaPalavra){// tamanho da palavra é o nº de letras
        palavraComMascara += "_"; // gera os underlines
        cont++;
    }
    return palavraComMascara;// retorna os underlines como palavra
}


//====================================================================================================
//=============================================== 05 =================================================
void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

    //=============================== MENU DE STATUS ENQUANTO JOGAMOS ================================
    //cout << "A palavra secreta eh: " << palavra << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << mensagem; // var de msgs,
    cout << "\nPalavra:" << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
    cout << "\nTentativas Restantes:" << tentativasRestantes;

    //Exibe as letras arriscadas
    int cont;
    cout << "\nLetras arriscadas:";
    for(cont = 0; cont < letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont] << ", ";
    }

}


//====================================================================================================
//=============================================== 06 =================================================
int jogar(int numeroDeJogadores){

    //Palavra a ser adivinhada
    string palavra;

    //Confere o número de jogadores
    if(numeroDeJogadores == 1){
        // Qndo apenas 1 jogador é gerada uma palavra aleatória na função, q retorna em palavra
        //Palavra a ser adivinhada
        palavra = retornaPalavraAleatoria(); /*** 03 ************************************************/

    }else{
        // caso mais de um jogadores, então a palavra será digitada
        cout << "\nDigite uma palavra:";
        cin >> palavra;
    }

    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();// aqui o tamanho da palavra passa para a var

    //Palavra mascarada → var contém underlines com o número de letras da palavra
    // pra isso envia para função a palavra e seu tamanho
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra); /*** 04 *********/

//====================================================================================================

    ///Variáveis Gerais
    int tentativas = 0, maximoDeTentativas = 10;            //Número de tentativas e erros
    int cont = 0;                                           //Auxiliar para laços de repetição
    char letra;                                             //Letra arriscada pelo usuário
    int opcao;                                              //Opções finais
    string letrasJaArriscadas;                              //Acumula as tentativas do jogador
    string mensagem = "Bem vindo ao jogo!";                 //Feedback do jogador
    string palavraArriscada;                                //Tentativa de arriscar a palavra completa
    bool jaDigitouLetra = false, acertouLetra = false;      //Auxiliar para saber se a letra já foi digitada
                                                            // por padrão bool já começa false, mas colocou-se


    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){// loop do jogo,
            // enquanto a palavra for diferente da escolhida e jogador ainda tiver tentativas
        limpaTela(); /******************** 01 ***********************************************/



        //Exibe o status atual do jogo
        /******************** 05 ***********************************************/
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas,mensagem);
        // após receber sua resposta e fazer as verificações de tentativas e erros, volta pro início do loop
        // e sempre exibe o menu de status
        // OBS:| maximoDeTentativas - tentativas |→ passado o valor já da conta aqui, sem fazer conta antes



        //Lê um palpite
        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra):";
        cin >> letra;


        //====================================== ARRISCAR PALAVRA ====================================
        //Se digitar 1 deixa o usuário arriscar a palavra inteira
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                 palavraComMascara = palavraArriscada;
            }else{
                 tentativas = maximoDeTentativas;
            }
        }


        //================================= VERIFICA LETRA JÁ DIGITADA ==============================
        //Percorre as letras já arriscadas
        for(cont = 0; cont < tentativas; cont++){

            //Se encontrar a letra
            if(letrasJaArriscadas[cont] == letra){

                mensagem = "Essa letra ja foi digitada!"; // há uma var para controlar msgs, q é enviada
                // para status q a exibe

                //Indica com a variável booleana
                jaDigitouLetra = true;

            }
        }// se já foi digitado vai voltar o loop lá em cima

        //===================================== NÃO FOI DIGITADA ====================================
        //Se for uma letra nova
        if(jaDigitouLetra == false){

            //Incrementa as letras já arriscadas
            letrasJaArriscadas += tolower(letra);

            //============ SE TIVER UMA LETRA IGUAL, NO LUGAR DO UNDERLINE APARECE LETRA =====
            //Percorre a palavra real e
            for(cont = 0; cont < tamanhoDaPalavra; cont++){

                //Se a letra existir na palavra escondida
                if(palavra[cont] == tolower(letra)){
                // tolower transforma em letra minúscula qq letra digitada, com isso se digitar maiúscula
                // ainda assim o programa vai entender

                    //Faço aquela letra aparecer na palavraComMascara
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;
                }//**************** AQUI
            }


            // todo esse cód podia estar em qndo ele acerta acima (no AQUI), porém pra cada letra
            // apareceria uma msg, então sinalizou só se aconteceu e exibiu a msg de acordo
            if(acertouLetra == false){
                mensagem = "Voce errou uma letra!";
            }else{
                mensagem = "Voce acertou uma letra!";
            }
            //Aumenta uma tentativa realizada
            tentativas++;
        }
        //Reinicia auxiliares
        jaDigitouLetra = false;
        acertouLetra = false;



    }// VOLTA O LOOP DO JOGO
    // se palavra for igual a oculta ou não houverem tentativas o jogo acaba (finaliza loop)
    // vai para resultados


    //====================================== FIM DO JOGO ====================================
    if(palavra == palavraComMascara){

        limpaTela(); /******************** 01 ***********************************************/
        cout << "Parabens, você venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao; /********** VOLTA PARA → menuInicial **********************************/
        // Contém valor 1 para voltar ao loop do menu inicial
    }else{

        limpaTela(); /******************** 01 ***********************************************/
        cout << "Bleh, você perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1-Sim";
        cout << "\n2-Nao";
        cin >> opcao;
        return opcao; /********** VOLTA PARA → menuInicial **********************************/
        // Contém valor 1 para voltar ao loop do menu inicial
    }

}




