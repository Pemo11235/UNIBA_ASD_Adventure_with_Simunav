#include "Prodotto.h"
using namespace std;

Prodotto::Prodotto()
{
    nome = "";
    costo = 0;
    quantita = 0;
}

Prodotto::Prodotto(string nomea, float costoa,int codicea, int quantitaa)
{

    nome = nomea;
    costo = costoa;
    quantita = quantitaa;
    codice = codicea;

}

float Prodotto::getCosto()
{
    return costo;
}


string Prodotto::getNome()
{
    return nome;
}
int Prodotto::getQuantita()
{
    return quantita;
}

int Prodotto::getCodice()
{
    return codice;
}

void Prodotto::setQuantita(int q)
{
    quantita=q;
}

Prodotto::~Prodotto()
{
}


