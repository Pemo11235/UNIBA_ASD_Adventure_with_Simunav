#include "Scheda.h"

Scheda::Scheda()
{
    this->nome = "";
    this->esercizi = Coda<Esercizio>();
}

Scheda::Scheda(string nome)
{
    this->nome = nome;
    this->esercizi = Coda<Esercizio>();
}

Scheda::~Scheda()
{
    //dtor
}

string Scheda::getNome()
{
    return this->nome;
}

void Scheda::addEsercizio(string tipo, int ripetizioni)
{
    Esercizio ese = {.tipo = tipo, .ripetizioni = ripetizioni};
    this->esercizi.incoda(ese);
}

Coda<Scheda::Esercizio> Scheda::getEsercizi() //Crea e restituisce una copia della coda di esercizi
{
    Coda<Esercizio> codaRitorno = *new Coda<Esercizio>(this->esercizi);
    return codaRitorno;
}
