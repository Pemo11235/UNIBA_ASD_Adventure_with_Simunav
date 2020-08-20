#include "Domanda.h"

Domanda::Domanda() {}

//costruttore di copia
Domanda::Domanda(const Domanda& d){
        domanda = d.domanda;
        codicedomanda = d.codicedomanda;
    }

Domanda::~Domanda() {}

Domanda::Domanda(int codice, string stringa){
    this->codicedomanda=codice;
    this->domanda=stringa;
}

int Domanda::leggicodice(){
    return this->codicedomanda;
}

string Domanda::leggidomanda(){
    return this->domanda;
}

