#ifndef SCHEDA_H
#define SCHEDA_H
#include "Coda.h"
#include <iostream>
#include <string>
using namespace std;
/*
*Progetto AMS
*Classe che implementa le schede di allenamento
*/
class Scheda
{
public:
    Scheda();
    Scheda(string);
    ~Scheda();
    struct Esercizio
    {
        string tipo;
        int ripetizioni;
    };
    string getNome();
    void setNome(string);
    void addEsercizio(string tipo, int ripetizioni);
    Coda<Esercizio> getEsercizi();
private:
    string nome;
    Coda<Esercizio> esercizi;


};

#endif // SCHEDA_H
