#include "Canzone.h"
Canzone::Canzone()
{
    nome = "default";
    artista = "default";
    anno = 1991;
}

Canzone::~Canzone() {}

string Canzone::get_nome()
{
    return nome;
}

string Canzone::get_artista()
{
    return artista;
}

int Canzone::get_anno()
{
    return anno;
}

void Canzone::set_nome(string nuovoNome)
{
    nome = nuovoNome;
}

void Canzone::set_artista(string nuovoArtista)
{
    artista = nuovoArtista;
}

void Canzone::set_anno(int nuovoAnno)
{
    if ( (anno > 0) &&(anno < 3000) )
        anno = nuovoAnno;
    else
        anno = 1970;
}

ostream& operator<<(ostream& os, const Canzone& canz)
{
    os<<  "La canzone riprodotta e' '" << canz.nome << "' ed e' suonata da '" << canz.artista << "' e fu registrata nel " << canz.anno << "\n" ;
    return os;
}
