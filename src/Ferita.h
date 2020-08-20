#ifndef FERITA_H
#define FERITA_H

#include <string>
using namespace std;

class Ferita
{
public:
    Ferita(); //Costruttore di default
    Ferita(string, string, int, int); //Costruttore
    string GetNome(); //Restituisce il Nome della Ferita
    string GetDescrizione(); //Restituisce la Descrizione della Ferita
    int GetCodice(); //Restituisce il Codice della Ferita
    int GetDannoSalute(); //Restituisce il Danno_Salute della Ferita
private:
    string Nome;
    string Descrizione;
    int Codice;
    int Danno_Salute;
};

#endif // FERITA_H
