#include "Vialuogo.h"

Vialuogo::Vialuogo() //costruttore generico
{
    nome="";
    min=0;
    max=0;
}

void Vialuogo::scrivinome(string n)
{
    nome=n;
}

string Vialuogo::legginome() const
{
    return(nome);
}

void Vialuogo::scrivimin(unsigned int m)
{
    min=m;
}

unsigned int Vialuogo::leggimin() const
{
    return(min);
}

void Vialuogo::scrivimax(unsigned int m)
{
    max=m;
}

unsigned int Vialuogo::leggimax() const
{
    return(max);
}

//sovraccarichi

void Vialuogo::operator =(Vialuogo v) //assegnamento
{
    scrivinome(v.legginome());
    scrivimin(v.leggimin());
    scrivimax(v.leggimax());
}

bool Vialuogo::operator ==(Vialuogo v) //uguaglianza
{
    return (legginome()==v.legginome() && leggimin()==v.leggimin() && leggimax()==v.leggimax());
}

ostream& operator<<(ostream& os, const Vialuogo& v) //output
{
    os<<v.legginome()<<"-"<<v.leggimin()<<"-"<<v.leggimax();
    return(os);
}
