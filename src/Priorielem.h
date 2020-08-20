#ifndef _PRIORIELEM_H
#define _PRIORIELEM_H

#include <iostream>
#include <cstdlib>

using namespace std;

//tipo di elemento della coda con priorità

template<class X> class Priorielem
{
public:

    //dichiarazione di tipo
    typedef float priorita; //la priorità è di tipo numerico (valore minore=priorità più alta)
    typedef X tipoelem;

    //costruttori
    Priorielem();
    Priorielem(const Priorielem&);
    Priorielem(priorita,tipoelem);

    //distruttore di default

    //setter e getter
    void scrivipriorita(priorita);
    priorita leggipriorita() const;
    void scrivielem(tipoelem);
    tipoelem leggielem() const;

    //sovraccarichi
    void operator=(Priorielem);
    bool operator==(Priorielem);
    bool operator<(Priorielem);
    bool operator>(Priorielem);

private:
    priorita prior; //priorità
    tipoelem elem; //informazione

};

template <class X> Priorielem<X>::Priorielem() //costruttore generico
{
    prior=9999;
}

template <class X> Priorielem<X>::Priorielem(const Priorielem& p) //costruttore di copia
{
    prior=p.leggipriorita();
    elem=p.leggielem();
}

template <class X> Priorielem<X>::Priorielem(priorita p,tipoelem e) //costruttore specifico
{
    prior=p;
    elem=e;
}

template <class X> void Priorielem<X>::scrivipriorita(priorita p)
{
    prior=p;
}

template <class X> void Priorielem<X>::scrivielem(tipoelem e)
{
    elem=e;
}

template <class X> float Priorielem<X>::leggipriorita() const
{
    return(prior);
}

template <class X> X Priorielem<X>::leggielem() const
{
    return(elem);
}


//sovraccarichi

template <class X> void Priorielem<X>::operator=(Priorielem<X> p) //assegnamento
{
    prior=p.leggipriorita();
    elem=p.leggielem();
}

template <class X> bool Priorielem<X>::operator==(Priorielem<X> p) //uguaglianza
{
    return (elem==p.leggielem());
}

template <class X> bool Priorielem<X>::operator<(Priorielem<X> p) //maggioranza (solo sulla priorità)
{
    return (prior<p.leggipriorita());
}

template <class X> bool Priorielem<X>::operator>(Priorielem<X> p) //minoranza (solo sulla priorità)
{
    return (prior>p.leggipriorita());
}

//sovraccarico output

template<class X> ostream& operator<<(ostream& os, const Priorielem<X>& p)
{
    os<<"("<<p.leggipriorita()<<"|"<<p.leggielem()<<")";
    return(os);
}


#endif
