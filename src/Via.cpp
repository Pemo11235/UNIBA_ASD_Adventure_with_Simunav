#include "Via.h"

Via::Via() //costruttore generico
{
    nome="";
    direzione="";
    lunghezza=0;
    tempo=0;
    asfalto=true;
    pedaggio=false;
}

string Via::legginome() const
{
    return(nome);
}

float Via::leggilunghezza() const
{
    return(lunghezza);
}

float Via::leggitempo() const
{
    return(tempo);
}

string Via::leggidirezione() const
{
    return(direzione);
}

bool Via::leggiasfalto() const
{
    return(asfalto);
}

bool Via::leggipedaggio() const
{
    return(pedaggio);
}

void Via::scrivinome(string n)
{
    nome=n;
}

void Via::scrivilunghezza(float l)
{
    lunghezza=l;
}

void Via::scrividirezione(string d)
{
    direzione=d;
}

void Via::scrivitempo(float t)
{
    tempo=t;
}

void Via::scriviasfalto(bool a)
{
    asfalto=a;
}

void Via::scrivipedaggio(bool p)
{
    pedaggio=p;
}

//sovraccarichi

void Via::operator =(Via v) //assegnamento
{
    scrivinome(v.legginome());
    scrivilunghezza(v.leggilunghezza());
    scrividirezione(v.leggidirezione());
    scrivitempo(v.leggitempo());
    scriviasfalto(v.leggiasfalto());
    scrivipedaggio(v.leggipedaggio());
}

bool Via::operator ==(Via v) //uguaglianza
{
    return (legginome()==v.legginome() && leggilunghezza()==v.leggilunghezza() && leggidirezione()==v.leggidirezione() && leggitempo()==v.leggitempo() && leggiasfalto()==v.leggiasfalto() && leggipedaggio()==v.leggipedaggio() );
}

ostream& operator<<(ostream& os, const Via& v) //output
{
    os<<v.legginome()<<"|"<<v.leggilunghezza()<<"|"<<v.leggitempo()<<"|"<<v.leggidirezione()<<"|"<<v.leggiasfalto()<<"|"<<v.leggipedaggio();
    return(os);
}
