#ifndef _NODOCUR_H
#define _NODOCUR_H

#include <iostream>
#include <cstdlib>

using namespace std;

//Classe contenente la coppia nodo-cursore (che userò nella classe navigatore, è il tipo dei dati della coda con priorità usata in Dijkstra)

template<class X> class Nodo_cursore
{
public:
    //definizione di tipo
    typedef X tiponodo;

    //usa costruttore e distruttore di default

    //setter e getter
    void scrivinodo(tiponodo);
    tiponodo legginodo() const;
    void scrivicursore(int);
    int leggicursore() const;

    //sovraccarichi
    void operator =(Nodo_cursore);
    bool operator ==(Nodo_cursore);

private:
    tiponodo nodo;
    int cur;
};


template <class X> void Nodo_cursore<X>::scrivinodo(tiponodo n)
{
    nodo=n;
}

template <class X> void Nodo_cursore<X>::scrivicursore(int c)
{
    cur=c;
}

template <class X> X Nodo_cursore<X>::legginodo() const
{
    return(nodo);
}

template <class X> int Nodo_cursore<X>::leggicursore() const
{
    return(cur);
}

//sovraccarichi

template <class X> void Nodo_cursore<X>::operator =(Nodo_cursore<X> x)
{
    scrivinodo(x.legginodo());
    scrivicursore(x.leggicursore());
}

template <class X> bool Nodo_cursore<X>::operator ==(Nodo_cursore<X> x)
{
    return( legginodo()==x.legginodo() && leggicursore()==x.leggicursore() );
}

template<class X> ostream& operator<<(ostream& os, const Nodo_cursore<X>& x) //sovraccarico output
{
    os<<x.legginodo()<<"|"<<x.leggicursore();
    return(os);
}

#endif
