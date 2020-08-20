#ifndef ENIGMA_H_
#define ENIGMA_H_

//Modifica PMF(struttura)

#include <iostream>
#include "Lista.h"
#include "servizioLista.h"
#include "risposta.h"

using namespace std;

class enigma
{
public:
    enigma();
    ~enigma();
    void set_id(int);
    void set_enigma(string);
    void set_risposta(risposta);
    void stampa_risposte();

    int get_id();
    string get_enigma();
    Lista<risposta> get_risposta();
    void operator =(enigma);

private:
    int id;
    string eni;
    Lista<risposta> risposte;

};

#endif /* ENIGMA_H_ */
