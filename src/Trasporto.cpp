#include "Trasporto.h"

Trasporto::Trasporto() { };

Trasporto::~Trasporto() { };

int Trasporto::get_partenza()
{
    return partenza;
}

int Trasporto::get_arrivo()
{
    return arrivo;
}

string Trasporto::get_mappa()
{
    return mappa;
}

void Trasporto::set_partenza(int n)
{
    partenza = n;
}

void Trasporto::set_arrivo(int n)
{
    arrivo = n;
}

void Trasporto::set_mappa(string s)
{
    mappa = s;
}
