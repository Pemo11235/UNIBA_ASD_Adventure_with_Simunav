#ifndef _NODOPREC_H
#define _NODOPREC_H

#include <iostream>
#include <cstdlib>

using namespace std;

//Classe contenente la coppia nodo-predecessore (che userò nella classe navigatore, è il tipo dei dati dell'array risultato di Dijkstra)

template<class X> class Nodo_predecessore
{
public:
    //definizione di tipo
    typedef X tiponodo;

    //usa costruttore e distruttore di default

    //setter e getter
    void scrivinodo(tiponodo);
    tiponodo legginodo() const;
    void scrivipredecessore(int);
    int leggipredecessore() const;

    //sovraccarichi
    void operator =(Nodo_predecessore);

private:
    tiponodo nodo;
    int prec;
};


template <class X> void Nodo_predecessore<X>::scrivinodo(tiponodo n)
{
    nodo=n;
}

template <class X> void Nodo_predecessore<X>::scrivipredecessore(int p)
{
    prec=p;
}

template <class X> X Nodo_predecessore<X>::legginodo() const
{
    return(nodo);
}

template <class X> int Nodo_predecessore<X>::leggipredecessore() const
{
    return(prec);
}

//sovraccarichi

template <class X> void Nodo_predecessore<X>::operator =(Nodo_predecessore<X> x)
{
    scrivinodo(x.legginodo());
    scrivipredecessore(x.leggipredecessore());
}

template<class X> ostream& operator<<(ostream& os, const Nodo_predecessore<X>& x) //sovraccarico output
{
    os<<x.legginodo()<<"|"<<x.leggipredecessore();
    return(os);
}

#endif
