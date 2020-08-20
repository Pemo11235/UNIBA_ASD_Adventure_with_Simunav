#include "Azione.h"

Azione::Azione()
{
    comando = 0;
    codice = 0;
}

void Azione::set(int com, int cod)
{
    comando = com;
    codice = cod;
}

int Azione::get_codice()
{
    return codice;
}

int Azione::get_comando()
{
    return comando;
}
