#include "lib/agenda.h"
#include <algorithm>

using namespace std;

Agenda::Agenda(int tempoMaxVisitacao){
    this->tempoMaxVisitacao = tempoMaxVisitacao;
    mesVisitacao = 1;
    vector<int> trocaMesVisitacao;
    vector<Visita*> todasAsVisitas;
}

void Agenda::adicionaVisita(int tempoVisitacao, string nomePlaneta){
    todasAsVisitas.push_back(new Visita(tempoVisitacao, nomePlaneta));
}

void Agenda::ordenaVisitas(){
    msort(todasAsVisitas);
}

void Agenda::msort(vector<Visita*> & vetorOrdena){
    if (vetorOrdena.size() <=  1){
        return;
    }

    int meio = vetorOrdena.size() / 2;
    vector<Visita*> esquerda;
    vector<Visita*> direita;

    for(int i = 0; i < meio; ++i){
        esquerda.push_back(vetorOrdena[i]);
    }
    for(int i = 0; i < (vetorOrdena.size() - meio); ++i){
        direita.push_back(vetorOrdena[meio + i]);
    }


    msort(esquerda);
    msort(direita);
    Agenda::mergeSort(esquerda, direita, vetorOrdena);
}

void Agenda::mergeSort(vector<Visita*> & esquerda, vector<Visita*> & direita, \
                        vector<Visita*> & vetorOrdena){

    int tamEsquerda = esquerda.size();
    int tamDireita = direita.size();

    int i = 0, j = 0, k = 0;

    while(j < tamEsquerda && k < tamDireita){

        if(esquerda[j]->tempoVisitacao <= direita[k]->tempoVisitacao){
            vetorOrdena[i] = esquerda[j];
            j++;
        } else{
            vetorOrdena[i] = direita[k];
            k++;
        }
        i++;
    }

    while(j < tamEsquerda){
        vetorOrdena[i] = esquerda[j];
        j++;
        i++;
    }
    
    while(k < tamDireita){
        vetorOrdena[i] = direita[k];
        k++;
        i++;
    }
}


void Agenda::calculaMes(){
    int somaTempoVisitas = 0;

    for(auto iter = todasAsVisitas.begin(); iter != todasAsVisitas.end(); ++iter){
        // verifica se pode adicionar mais um evento antes do proximo mes
        if((somaTempoVisitas + (*iter)->tempoVisitacao) > tempoMaxVisitacao){
            mesVisitacao++;
            somaTempoVisitas = 0;
        }

        (*iter)->mesDeVisita = mesVisitacao;
        somaTempoVisitas += (*iter)->tempoVisitacao;
    }
}

void Agenda::imprimeAgenda(){
    for(auto iter = todasAsVisitas.begin(); iter != todasAsVisitas.end(); ++iter){
        cout << (*iter)->mesDeVisita << " " << (*iter)->nomePlaneta << " " << (*iter)->tempoVisitacao << endl;
    }
}

/* 

    void Agenda::ordenaAgenda(){
    rsort(todasAsVisitas);
}

void Agenda::rsort(vector<Visita*> & vetorOrdena){
    if (vetorOrdena.empty()){
        return;
    }

    vector<Visita*> bucket;
    bucket.resize(10);

    int maior = 0;
    for(auto iter = todasAsVisitas.begin(); iter != todasAsVisitas.end(); ++iter){
        if( ((*iter)->tempoVisitacao) > maior ){
            maior = (*iter)->tempoVisitacao;
        }
    } // a partir daqui, temos o maior elemento na variavel maior

    int i = 1;
    while(maior != 0){
        for(auto aux : todasAsVisitas){
            if(todasAsVisitas)
        }
    }


}

*/