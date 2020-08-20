#include "Luce.h"

Luce::Luce()
{
    nomeLuce = "default";
}

Luce::~Luce()
{
    //dtor
}

string Luce::getNome()
{
    return nomeLuce;
}

void Luce::setNome(string nuovoNome)
{
    nomeLuce = nuovoNome;
}

bool Luce::operator==(const Luce& l) const
{
    return nomeLuce == l.nomeLuce;
}

bool Luce::operator!=(const Luce& l) const
{
    return nomeLuce != l.nomeLuce;
}

bool Luce::operator<(const Luce& l) const
{
    return nomeLuce < l.nomeLuce;
}

bool Luce::operator<=(const Luce& l) const
{
    return nomeLuce <= l.nomeLuce;
}

ostream& operator<<(ostream& os, const Luce& luc)
{
    os << luc.nomeLuce;
    return os;
}
