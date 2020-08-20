#include "rubrica.h"
Rubrica::Rubrica() {}

Rubrica::~Rubrica() {}

string Rubrica::get_nome()
{
    return nome;
}

string Rubrica::get_cognome()
{
    return cognome;
}

string Rubrica::get_interno()
{
    return interno;
}

string Rubrica::get_descrizione()
{
    return descrizione;
}

string Rubrica::get_telefono()
{
    return telefono;
}

void Rubrica::set_descrizione(string d)
{
    descrizione = d;
}

void Rubrica::set_nome(string n)
{
    nome = n;
}

void Rubrica::set_cognome(string c)
{
    cognome = c;
}

void Rubrica::set_interno(string i)
{
    interno = i;
}

void Rubrica::set_telefono(string t)
{
    telefono = t;
}


