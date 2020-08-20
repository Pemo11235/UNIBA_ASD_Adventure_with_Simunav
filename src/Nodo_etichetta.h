#ifndef _NODOETI_H
#define _NODOETI_H

#include "Luogo.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Classe contenente la coppia nodo-etichetta (che uso nella classe navigatore in modo da sapere subito l'associazione etichetta-nodo)

template<class X,class Y> class Nodo_etichetta
{
public:
    //definizioni di tipo
    typedef X tiponodo;
    typedef Y tipoetichetta;

    //usa costruttore e distruttore di default

    //setter e getter
    void scrivinodo(tiponodo);
    tiponodo legginodo() const;
    void scrivietichetta(tipoetichetta);
    tipoetichetta leggietichetta() const;

    //sovraccarichi
    void operator =(Nodo_etichetta);

private:
    tiponodo nodo;
    tipoetichetta etichetta;
};


template <class X,class Y> void Nodo_etichetta<X,Y>::scrivinodo(tiponodo n)
{
    nodo=n;
}

template <class X,class Y> void Nodo_etichetta<X,Y>::scrivietichetta(tipoetichetta e)
{
    etichetta=e;
}

template <class X,class Y> X Nodo_etichetta<X,Y>::legginodo() const
{
    return(nodo);
}

template <class X,class Y> Y Nodo_etichetta<X,Y>::leggietichetta() const
{
    return(etichetta);
}

//sovraccarichi

template <class X,class Y> void Nodo_etichetta<X,Y>::operator =(Nodo_etichetta<X,Y> x)
{
    scrivinodo(x.legginodo());
    scrivietichetta(x.leggietichetta());
}

template<class X,class Y> ostream& operator<<(ostream& os, const Nodo_etichetta<X,Y>& x) //sovraccarico output
{
    os<<x.legginodo()<<"|"<<x.leggietichetta();
    return(os);
}

#endif
