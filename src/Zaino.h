#ifndef ZAINO_H_
#define ZAINO_H_
#include "Lista.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//realizzazione di una pila dinamica utilizzando una lista dinamica monodirezionale

template<class P> class Zaino
{
public:
    //definizioni di tipo
    typedef P tipoelem;
    typedef Cella<P>* posizione;

    //costruttori
    Zaino();
    Zaino(const Zaino&);

    //distruttore di default

    //operatori di specifica
    void creaZaino();
    bool zainoVuoto() const;
    tipoelem leggiZaino() const;
    void inZaino(tipoelem);
    void fuoriZaino();
    void svuota(); //operatore ausiliare

    //sovraccarichi
    void operator =(const Zaino&);
    bool operator ==(Zaino&);

private :
    Lista<P> zaino; //la pila è di fatto una lista


    friend ostream& operator<<(ostream& os, Zaino<P>& p) //sovraccarico output
    {
        os<<p.zaino;
        return(os);
    }

};

template<class P> Zaino<P>::Zaino() //costruttore generico
{
    creaZaino();
}

template<class P> Zaino<P>::Zaino(const Zaino<P>& p) //costruttore di copia
{
    creaZaino();
    zaino=p.zaino;
}

template<class P> void Zaino<P>::creaZaino() //crea la pila
{
    zaino.crealista();
}

template<class P> bool Zaino<P>::zainoVuoto() const  //restituisce true se la pila è vuota, false altrimenti
{
    return (zaino.listavuota());
}

template<class P> P Zaino<P>::leggiZaino() const //legge l'elemento in testa alla pila
{
    if (!zainoVuoto())  //precondizione pila non vuota
        return (zaino.leggilista(zaino.primolista()));
}

template<class P> void Zaino<P>::inZaino(tipoelem a)  //inpila un elemento
{
    posizione i=zaino.primolista();
    zaino.inslista(i,a);
}

template<class P> void Zaino<P>::fuoriZaino()  //estrae l'elemento in testa
{
    posizione i=zaino.primolista();
    if (!zainoVuoto())  //precondizione pila non vuota
        zaino.canclista(i);
}


//sovrccarichi

template<class P> void Zaino<P>::operator =(const Zaino<P>& p) //assegnamento
{
    zaino=p.zaino;
}

template<class P> bool Zaino<P>::operator ==(Zaino<P>& p) //uguaglianza
{
    return (zaino==p.zaino);
}

//operatore ausiliare

template<class P> void Zaino<P>::svuota() //svuota la pila
{
    while (!zainoVuoto())
    {
        fuoriZaino();
    }
}



#endif /* ZAINO_H_ */
