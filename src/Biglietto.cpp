#include "Biglietto.h"
using namespace std;


Biglietto::Biglietto(string d, int c)
{
    destinazione=d;
    costo=c;
}

Biglietto::Biglietto()
{
    destinazione="";
    costo=0;
}

Biglietto::~Biglietto()
{
}

string Biglietto::getDestinazione() const
{
    return destinazione;
}

int Biglietto::getCosto() const
{
    return costo;
}
