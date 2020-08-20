#include "stato_comando.h"

stato_comando::stato_comando()
{}

stato_comando::stato_comando(Stato s, string com)
{
    stato=s;
    comando=com;
}

stato_comando::~stato_comando()
{
    //dtor
}

void stato_comando::set_stato(Stato s)
{
    stato=s;
}
void stato_comando::set_comando(string c)
{
    comando=c;
}
Stato stato_comando::get_stato()
{
    return stato;
}
string stato_comando::get_comando()
{
    return comando;
}

