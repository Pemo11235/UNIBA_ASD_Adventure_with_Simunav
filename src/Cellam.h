#ifndef _CELLAMONO_H
#define _CELLAMONO_H

#include <iostream>
#include <cstdlib>

using namespace std;

//Cella (atomo) per lista monodirezionale dinamica e per Coda dinamica

template<class X> class Cellam
{
public:
    typedef X tipoelem; //definizione di tipo

    //usa costruttore e distruttore di default

    //setter e getter
    void scrivicella(tipoelem);
    tipoelem leggicella() const;
    void scrivisucc(Cellam<X>*);
    void scriviprec(Cellam<X>*); //Modifica PMF (agenda)
    Cellam<X>* leggisucc() const;
    Cellam<X>* leggiprec() const ;//Modifica PMF (agenda)


    //sovraccarichi
    void operator =(Cellam);
    bool operator ==(Cellam);
    bool operator !=(Cellam);
    bool operator >(Cellam);
    bool operator <(Cellam);
    bool operator >=(Cellam);
    bool operator <=(Cellam);


private:
    tipoelem elemento; //informazione
    Cellam<X>* succ; //riferimento al nodo successivo
    Cellam<X>* prec; //Modifica PMF (agenda)
};


template <class X> void Cellam<X>::scrivicella(tipoelem elem)
{
    elemento=elem;
}

template <class X> X Cellam<X>::leggicella() const
{
    return (elemento);
}

template <class X> void Cellam<X>::scrivisucc(Cellam<X>* pos)
{
    succ=pos;
}

//Modifica PMF(agenda)
template<class X> void Cellam<X>::scriviprec(Cellam<X>* prec) {
		this->prec = prec;
	}
//Modifica PMF: fin qui.

template <class X> Cellam<X>* Cellam<X>::leggisucc() const
{
    return (succ);
}

//Modifica PMF(agenda)
template<class X> Cellam<X>* Cellam<X>::leggiprec() const {
		return prec;
	}
//Modifica PMF: fin qui.


//sovraccarichi (gli operatori agiscono solo sull'informazione e non sui riferimenti)

template <class X> void Cellam<X>::operator =(Cellam<X> c)
{
    scrivicella(c.leggicella());
}

template <class X> bool Cellam<X>::operator ==(Cellam<X> c)
{
    return(leggicella==c.leggicella());
}

template <class X> bool Cellam<X>::operator !=(Cellam<X> c)
{
    return(leggicella!=c.leggicella());
}

template <class X> bool Cellam<X>::operator >(Cellam<X> c)
{
    return(leggicella>c.leggicella());
}

template <class X> bool Cellam<X>::operator <(Cellam<X> c)
{
    return(leggicella<c.leggicella());
}

template <class X> bool Cellam<X>::operator >=(Cellam<X> c)
{
    return(leggicella>=c.leggicella());
}

template <class X> bool Cellam<X>::operator <=(Cellam<X> c)
{
    return(leggicella<=c.leggicella());
}

template<class X> ostream& operator<<(ostream& os, const Cellam<X>& c) //sovraccarico output
{
    os<<c.leggicella();
    return(os);
}

#endif

