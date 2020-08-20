#include "Attivita.h"

Attivita::Attivita()
{
    //ctor
}

Attivita::~Attivita()
{
    //dtor
}

string Attivita::get_data()
{
    return data;
}

string Attivita::get_descrizione()
{
    return descrizione;
}

string Attivita::get_autore()
{
    return autore;
}

void Attivita::set_data(string d)
{
    data = d;
}

void Attivita::set_descrizione(string desc)
{
    descrizione = desc;
}

void Attivita::set_autore(string a)
{
    autore = a;
}
