/*
 * Premio.cpp
 *
 *  Created on: 21/ott/2014
 *      Author: FRANCESCO COSMA
 */

#include "Premio.h"
#include <iostream>
using namespace std;

Premio::Premio() {}

Premio::Premio(string t,string d,int o,int pt,int po)
{
    Titolo=t;
    Descrizione=d;
    Progresso=0;
    Obbiettivo=o;
    Premio_T=pt;
    Premio_O=po;
    Ritirato=false;
}

Premio::~Premio()
{
    // TODO Auto-generated destructor stub
}

void Premio::creaPremio(string t,string d,int o,int pt,int po)
{
    Titolo=t;
    Descrizione=d;
    Progresso=0;
    Obbiettivo=o;
    Premio_T=pt;
    Premio_O=po;
    Ritirato=false;
}

void Premio::setTitolo(string tit)
{
    Titolo=tit;
}

void Premio::setDescrizione(string des)
{
    Descrizione=des;
}

void Premio::setProgresso(int pr)
{
    Progresso=pr;
}

void Premio::setObbiettivo(int ob)
{
    Obbiettivo=ob;
}

void Premio::setPremio_T(int pt)
{
    Premio_T=pt;
}

void Premio::setPremio_O(int po)
{
    Premio_O=po;
}

void Premio::setRitirato(bool flag)
{
    Ritirato=flag;
}

string Premio::getTitolo() const
{
    return(Titolo);
}

string Premio::getDescrizione() const
{
    return(Descrizione);
}

int Premio::getProgresso() const
{
    return(Progresso);
}

int Premio::getObbiettivo() const
{
    return(Obbiettivo);
}

float Premio::getPremio_T() const
{
    return(Premio_T);
}

int Premio::getPremio_O() const
{
    return(Premio_O);
}

bool Premio::getRitirato() const
{
    return(Ritirato);
}

void Premio::stampaPremio()
{
    cout<< Titolo << endl;
    cout<< Descrizione << endl;
}

bool Premio::confronta()
{
    return(Progresso >= Obbiettivo);
}

void Premio::incrementaProgresso()
{
    Progresso++;
}

bool Premio::operator ==(const Premio& oggetto)
{
    return (Titolo == oggetto.getTitolo());
}
