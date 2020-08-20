/*
Realizzazione: 	Coda con priorità tramite una lista ordinata
Note: 		Valore di priorità minore indica priorità maggiore
Modificato da:	Matteo Luceri
Autore 	     :	Sconosciuto
*/

#ifndef CODA_CON_PRIORITA_H_
#define CODA_CON_PRIORITA_H_

#include "Lista_Ordinata_Ereditata.h"
#include <iostream>
#include <cstdlib>
#include "Elemento_Coda_Con_Priorita.h"

using namespace std;

//realizzazione di una
template<class P> class Prioricoda
{
public:

    //definizione di tipo
    typedef Priorielem<P> tipoelem;

    //costruttori
    Prioricoda();
    Prioricoda(const Prioricoda<P>&);

    //distruttore di default

    //operatori di specifica
    void creaprioricoda();
    void inserisci(tipoelem);
    tipoelem min() const;
    void cancellamin();

    //operatori ereditati dell'insieme
    bool insiemevuoto() const;
    bool appartiene(tipoelem) const;

private:
    ListaOrdinata<tipoelem> prioricoda;  //la coda con priorità di fatto è una lista

    friend ostream& operator<< (ostream& o, const Prioricoda<P>& p) //sovraccarico output
    {
        o<<p.prioricoda;
        return o;
    }

};


template<class P> Prioricoda<P>::Prioricoda() //costruttore generico
{
    creaprioricoda();
}

template <class P> Prioricoda<P>::Prioricoda(const Prioricoda<P>& p) //costruttore di copia
{
    creaprioricoda();
    prioricoda=p.prioricoda;
}

template<class P> void Prioricoda<P>::creaprioricoda() //crea la coda con priorità
{
    prioricoda.crealista();
}

template<class P> void Prioricoda<P>::inserisci(tipoelem a) //inserimento
{
    prioricoda.inslista(a);
}

template<class P> Priorielem<P> Prioricoda<P>::min() const //restituisce il minimo della coda
{
	tipoelem m;
    if (!prioricoda.listavuota())  //precondizione coda non vuota
    {
	 typename ListaOrdinata<tipoelem>::posizione indice=prioricoda.primolista();
	 m= prioricoda.leggilista(indice);
    }

    return m;
}

template<class P> void Prioricoda<P>::cancellamin() //elimina il minimo dalla coda
{
    if (!prioricoda.listavuota())  //precondizione coda non vuota
    {
	typename ListaOrdinata<tipoelem>::posizione indice=prioricoda.primolista();
   	prioricoda.canclista(indice);
    }
}

template<class P> bool Prioricoda<P>::insiemevuoto() const //verifica se la coda è vuota
{
    return (prioricoda.listavuota());
}

template<class P> bool Prioricoda<P>::appartiene(tipoelem a) const //verifica se l'elemento appartiene alla coda
{
    bool trovato=false;
    if (!prioricoda.listavuota())
    {
        typename ListaOrdinata<tipoelem>::posizione indice=prioricoda.primolista(); //ricerca
        while (!prioricoda.finelista(indice) && !trovato)
        {
            if (prioricoda.leggilista(indice)==a) //se l'elemento corrente è il cercato
                trovato=true;
            else indice=prioricoda.succlista(indice);
        }
    }
    return(trovato);
}



#endif /* CODA_CON_PRIORITA_H_ */
