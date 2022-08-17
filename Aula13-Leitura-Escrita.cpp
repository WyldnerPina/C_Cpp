#include <stdio.h>
#include <string.h>// biblioteca para saber as casas usadas na string char em c
#include <stdlib.h>
#include <fstream>// biblioteca para abrir e mexer em arqvos
#include <string>
#include <iostream>

using namespace std;
void escreverC();
void lerC();
void lerCpp();
void arqvz();

int main () {
    int opc;
    do{
        //Interface de Menu
        printf("Escolha uma opcao:");
        printf("\n 1 - Escrever 1");
        printf("\n 2 - Ler C");
        printf("\n 3 - Ler Cpp");
        printf("\n 4 - Esvaziar");
        printf("\n 9 - Desliga\n");
        scanf("%d", &opc);

        //Resultado de acordo com a opcao escolhida
        switch(opc){
             case 1:
                escreverC();
                break;
             case 2:
                lerC();
                break;
             case 3:
                lerCpp();
                break;
             case 4:
                arqvz();
                break;
            case 9:
                printf("\nDesligando");
                break;
            case 7:
                printf("\n case 9:\n printf('Desligando');\n break;");
                break;
            default:
                printf("\nOpcao Invalida");
                break;
        }
    }while(opc != 9);
    return 0;
}

//============================================  ESCREVER =============================================
//====================================================================================================
//====================================================================================================
void escreverC(){

    //Cria o objeto de arquivo
    ofstream arquivoDeSaida;

    //Abre o arquivo ou cria caso n�o exista
    arquivoDeSaida.open("Texto.txt", std::ios_base::app);//pode ser outras exten��es
    // ios_base::app � o modo de abrir o arqv

    //Escreve algo
    arquivoDeSaida << "\nMam�ezinha";//escreve seguidamente se executado seguidamente, � preciso limpar
    // Ex: Mam�ezinhaMam�ezinhaMam�ezinhaMam�ezinha. se pular linha ent�o a� � seguido em coluna

    //Fecha o arquivo
    arquivoDeSaida.close();
};

//============================================  LER ==================================================
//====================================================================================================
//====================================================================================================
void lerC(){
    //Cursor que ir� percorrer cada letra
    int c;
    char conteudoTexto[255];
    //Contador
    int cont = 0;

    //Arquivo a ser lido
    FILE *file;

    //Abre o arquivo no diret�rio escolhido
    file = fopen("Texto.txt", "r");//fopen = file open, r = read
    // se n�o tiver na mesma pasta, tem q digitar caminho


    //Se o arquivo foi encontrado
    if(file){// se for vdd ele executa

        //Encontra encontra letras(at� o fim do arquivo)
        while((c = getc(file)) != EOF){//getc = pega caracter enquanto diferente de End Of File = fim do arquivo

            // se imprimir c, vem o c�d asc
            //Imprime na tela
            printf("%c", c);// mas na impress�o j� sai as letras

            //Vetor de char recebe a letra atual
            conteudoTexto[cont] = c;//aqui � pra receber, em C, as letras dentro de um char

            //Aumenta a contagem de letras
            cont++;

        }

        //Fecha o arquivo
        fclose(file);

    }

    //Imprimindo conte�do lido
    for(cont = 0; cont < strlen(conteudoTexto) - 2; cont++){//aqui entra a biblioteca string.h
        printf("%c",conteudoTexto[cont] );
    }
};

//============================================  LER C++ ==============================================
//====================================================================================================
//====================================================================================================
void lerCpp(){
    //Dizer qual arquivo ser� lido
    ifstream input("Texto.txt");

    //String que receber� o texto lido
    string textoLido;

    //Passa o texto do arquivo para a string
    for(string line; getline(input, line);){//string para cada linha q � tranformada na String line
        textoLido += line;// adiciona linhas � string
    }

    //Mostrar o conte�do
    cout << textoLido;

};

//========================================= ARQUIVO VAZIO ============================================
//====================================================================================================
//====================================================================================================
void arqvz(){
     //Cria o objeto do arquivo
    ofstream meuArquivo;

    //Abre o arquivo
    meuArquivo.open("Texto.txt");// d� pra usar qq tipo de arqv de texto at� html

    //Esvazia o arquivo
    meuArquivo << "";// s� mando um vazio pra dentro do arqv

    //Fecha o arquivo
    meuArquivo.close();
};
