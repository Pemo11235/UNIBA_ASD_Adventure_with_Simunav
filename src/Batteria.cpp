#include "Batteria.h"

Batteria::Batteria(){}

Batteria::~Batteria(){}

int Batteria::get_stato()
{
    return stato;
}

string Batteria::get_modello()
{
    return modello;
}

void Batteria::set_stato(int stat)
{
    stato = stat;
}

void Batteria::set_modello(string mod)
{
    modello = mod;
}
