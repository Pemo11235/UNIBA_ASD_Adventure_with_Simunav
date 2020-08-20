#include "Documento.h"
#include <iostream>

Documento::Documento()
{
    codice= 0;
}

Documento::Documento(string n, string d, int c, int l)
{
    nome = n;
    descrizione = d;
    codice = c;
    luogo_documento=l;
}

Documento::~Documento() {}

string Documento::get_descrizione() const
{
    return descrizione;
}

void Documento::set_descrizione(string d)
{
    descrizione = d;
}

string Documento::get_nome() const
{
    return nome;
}

void Documento::set_nome(string n)
{
    nome = n;
}

void Documento::stampa_documento()
{
    cout << "Documento " << get_codice() << " : " << get_nome()  << " - " << get_descrizione()  << endl;
}

int Documento::get_codice()
{
    return codice;
}

int Documento::get_luogo()
{
    return luogo_documento;
}

void Documento::set_luogo_documento(int l)
{
    luogo_documento = l;
}
