/*  
    Trabalho pratico 2 - Estruturas de Dados

    Vitor de Oliveira Mafra - 2018046831
    UFMG, Novembro de 2019
*/
#include <iostream>
#include <string>
#include "lib/agenda.h"

using namespace std;

void interpretaEntrada(string entradaRickInicial, int& tempoVisitacaoTotal,\
                        int& numPlanetas, int& qtdCaracteres){


    int posicaoPrimeiroEspaco = entradaRickInicial.find(" ");
    // a funcao rfind() encontra a ULTIMA recorrencia de um valor na string
    int posicaoSegundoEspaco = entradaRickInicial.rfind(" ");


    // agora que temos a posicao do primeiro espaco na string, comecamos a 
    // colocar os valores ANTES e DEPOIS desse espaco em suas variaveis
    int tempoVisitacaoTotalAux = stoi(entradaRickInicial.substr(0, posicaoPrimeiroEspaco));
    int numPlanetasAux = stoi(entradaRickInicial.substr(posicaoPrimeiroEspaco + 1));
    // e agora fazemos o mesmo com o valor DEPOIS do segundo espaco
    int qtdCaracteresAux = stoi(entradaRickInicial.substr(posicaoSegundoEspaco + 1));


    tempoVisitacaoTotal = tempoVisitacaoTotalAux;
    numPlanetas = numPlanetasAux;
    qtdCaracteres = qtdCaracteresAux;
}

int main(){
    string entradaRickInicial;
    int tempoVisitacaoTotal, numPlanetas, qtdCaracteres;

    int tempoVisitacao;
    string nomePlaneta;

    getline(cin,  entradaRickInicial);
    interpretaEntrada(entradaRickInicial, tempoVisitacaoTotal, numPlanetas, qtdCaracteres);

    Agenda *agendaRick = new Agenda(tempoVisitacaoTotal);

    for (int i = 0; i < numPlanetas; i++){
        
        cin >> tempoVisitacao;
        cin >> nomePlaneta;

        agendaRick->adicionaVisita(tempoVisitacao, nomePlaneta);

        tempoVisitacao = 0;// "reseta" as variaveis so pra garantir
        nomePlaneta = "";

    }


    agendaRick->ordenaVisitas();
    agendaRick->calculaMes();
    agendaRick->imprimeAgenda();

    return 0;
}
















/*
    int numPlanetas;
    cin >> numPlanetas;

    int *array = new int[numPlanetas];

    for(int i = 0; i < numPlanetas; i++){
        cin >> entradaPlanetas;
    }

    /*
    int tempoVisitacaoMes = 0, numPlanetas = 0, qtdLetrasPlanetas = 0;

    cin >> entradaPlanejamentoInicial; // tempo maximo de visitacao por mes + num planetas + qtde letras de cada planeta
    trataEntrada(entradaPlanejamentoInicial);



    */

    //cout << "agenda criada!" << endl;

    //delete[] array;