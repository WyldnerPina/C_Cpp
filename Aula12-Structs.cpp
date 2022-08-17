#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <new>

// structs é uma estrutura q serve pra trabalhar parecido com POO

// exemplos 1 e 2 em C, e 3 em C++


void exDois();
void exTres();
using namespace std;
/****************************************************************************************************/
//============================================ EXEMPLO 1 =============================================
//====================================================================================================
//====================================================================================================
struct palavra{
    int ordem;
    char letra;
    char texto[255];
};
//====================================================================================================
//====================================================================================================
int main () {

    //Criar uma palavra
    struct palavra primeiraPalavra;// como instanciar uma nova palavra

    //Modificando os campos, modificando os atributos
    primeiraPalavra.ordem = 10;
    primeiraPalavra.letra = 'p';
    strcpy(primeiraPalavra.texto,"palavrinha");//strcpy = string copy

    //Mostrando valores do Struct
    printf("Ordem: %d, Primeira Letra: %c, Palavra: %s", primeiraPalavra.ordem,primeiraPalavra.letra, primeiraPalavra.texto);
    //%s é pra string

//====================================================================================================
//====================================================================================================
    //Fazendo uma lista de structs
    struct palavra listaDePalavras[3];//criou um vetor para lista

    //Modificando os campos
    listaDePalavras[0].ordem = 0;
    listaDePalavras[1].ordem = 1;
    listaDePalavras[2].ordem = 2;
    listaDePalavras[0].letra = 'd';
    listaDePalavras[1].letra = 'l';
    listaDePalavras[2].letra = 'b';
    strcpy(listaDePalavras[0].texto,"Da hora");
    strcpy(listaDePalavras[1].texto,"Legal");
    strcpy(listaDePalavras[2].texto,"Bacana");

    //Percorrendo o vetor
    int cont;
    for(cont = 0; cont < 3; cont++){
        printf("\nOrdem: %d, Primeira Letra: %c, Palavra: %s", listaDePalavras[cont].ordem,
               listaDePalavras[cont].letra, listaDePalavras[cont].texto);
    }
//====================================================================================================
//====================================================================================================
    exDois();
    exTres();
    return 0;
}



// struct dentro de struct
/****************************************************************************************************/
//============================================ EXEMPLO 2 =============================================
//====================================================================================================
//====================================================================================================

typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

struct Aluno{
    int id;
    Data nascimento;//aqui eu chamo o Data acima, e chamo nascimento... tipo data, nome nascimento
};
//====================================================================================================
//====================================================================================================
void exDois(){

    //Criando um aluno
    struct Aluno aluno1;

    //Modificando valores
    aluno1.id = 15;
    aluno1.nascimento.ano = 1996;
    aluno1.nascimento.mes = 1;
    aluno1.nascimento.dia = 17;

    //Imprimindo valores
    printf("Nascido em: %d / %d / %d",  aluno1.nascimento.dia,  aluno1.nascimento.mes,  aluno1.nascimento.ano);
 }





/****************************************************************************************************/
//============================================ EXEMPLO 3 =============================================
//====================================================================================================
//====================================================================================================
 //Struct para frutas
struct fruta{
    string cor;
    string nome;
};

void exTres(){

    //Criando um ponteiro para o struct criado
    fruta *primeiraFruta = new fruta;

    //Modificando valores
    primeiraFruta->cor = "Amarela";
    primeiraFruta->nome = "Banana";

    //Exibindo Valores
    cout << "Fruta:" << primeiraFruta->nome << ", Cor:" << primeiraFruta->cor;
//====================================================================================================
//====================================================================================================
    //Criando uma lista de frutas
    fruta *ponteiroListaDeFrutas = new fruta[2];

    //Modificando valores
    ponteiroListaDeFrutas[0].cor = "Vermelho"; // qndo é vetor usamos o ponto e não a seta
    ponteiroListaDeFrutas[0].nome = "Morango";
    ponteiroListaDeFrutas[1].cor = "Verde";
    ponteiroListaDeFrutas[1].nome = "Kiwi";

    //Percorrendo e exibingo
    int cont;
    for(cont = 0; cont < 2; cont++){
         //Exibindo Valores
        cout << "\nFruta:" << ponteiroListaDeFrutas[cont].nome << ", Cor:" << ponteiroListaDeFrutas[cont].cor;
    }
}
