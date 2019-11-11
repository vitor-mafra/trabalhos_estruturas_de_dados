#ifndef AGENDA_H
#define AGENDA_H

#include "visita.h"
#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Agenda{
    public:
        int tempoMaxVisitacao;
        int mesVisitacao;
        vector<Visita*> todasAsVisitas;

        Agenda(int tempoMaxVisitacao);

        void adicionaVisita(int tempoVisitacao, string nomePlaneta);

        void ordenaVisitas(); // ordena as visitas da agenda de acordo com o tempo
        void msort(vector<Visita*> & vetorOrdena);
        void mergeSort(vector<Visita*> & esquerda, vector<Visita*> & direita,\
                         vector<Visita*> & vetorOrdena);


        //void ordenaAgenda(); // ordena agenda (ja ordenada por tempo de visita) por ordem alfabetica
        //void rsort(vector<Visita*> & vetorOrdena);
        //void radixSort(vector<Visita*> & esquerda, vector<Visita*> & direita,\
                         vector<Visita*> & vetorOrdena);
        

        void calculaMes();
        void imprimeAgenda();

};

#endif // AGENDA_H