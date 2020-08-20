#ifndef _PRIORICODA_H
#define _PRIORICODA_H

#include "Lista.h"
#include "Priorielem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//realizzazione di una coda con priorità tramite una lista non ordinata
//valore di priorità minore indica priorità maggiore

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
    Lista<tipoelem> prioricoda;  //la coda con priorità di fatto è una lista

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
    //in una lista non ordinata (in testa)
    typename Lista<tipoelem>::posizione indice=prioricoda.primolista();
    prioricoda.inslista(indice,a);
}

template<class P> Priorielem<P> Prioricoda<P>::min() const //restituisce il minimo della coda
{
    tipoelem m,temp;
    if (!prioricoda.listavuota())  //precondizione coda non vuota
    {
        Cella<tipoelem>* indice=prioricoda.primolista(); //ricerca del minimo
        m=prioricoda.leggilista(indice); //impongo come minimo il primo elemento
        indice=prioricoda.succlista(indice); //inizio la scansione dal secondo elemento
        while (!prioricoda.finelista(indice))
        {
            temp=prioricoda.leggilista(indice);
            if (temp<m) //se l'elemento è minore del minimo corrente (minore nel senso che la priorità è più alta)
            {
                m=temp;
            }
            indice=prioricoda.succlista(indice);
        }
    }
    return m;
}

template<class P> void Prioricoda<P>::cancellamin() //elimina il minimo dalla coda
{
    tipoelem m,temp;
    if (!prioricoda.listavuota())  //precondizione coda non vuota
    {
        Cella<tipoelem>* indice=prioricoda.primolista(); //ricerca del minimo
        m=prioricoda.leggilista(indice); //impongo come minimo il primo elemento
        indice=prioricoda.succlista(indice); //inizio la scansione dal secondo elemento
        while (!prioricoda.finelista(indice))
        {
            temp=prioricoda.leggilista(indice);
            if (temp<m) //se l'elemento è minore del minimo corrente (minore nel senso che la priorità è più alta)
            {
                m=temp;
            }
            indice=prioricoda.succlista(indice);
        } //fine della ricerca del minimo
        indice=prioricoda.primolista(); //seconda scansione per eliminare il minimo
        bool trovato=false;
        while (!prioricoda.finelista(indice) && !trovato)
        {
            temp=prioricoda.leggilista(indice);
            if (temp==m) //se l'elemento corrente è il minimo
            {
                trovato=true;
                prioricoda.canclista(indice); //eliminalo
            }
            else indice=prioricoda.succlista(indice);
        }
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
        Cella<tipoelem>* indice=prioricoda.primolista();  //ricerca con sentinella
        while (!prioricoda.finelista(indice) && !trovato)
        {
            if (prioricoda.leggilista(indice)==a) //se l'elemento corrente è il cercato
                trovato=true;
            else indice=prioricoda.succlista(indice);
        }
    }
    return(trovato);
}

#endif
