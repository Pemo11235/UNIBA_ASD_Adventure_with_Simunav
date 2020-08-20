/*
 * Prioricoda.h
 *
 *  Created on: 21 gen 2017
 *      Author: Angelo
 */

#ifndef STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_CODA_PRIOR_VETTORE_HEAP_PRIORICODA_H_
#define STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_CODA_PRIOR_VETTORE_HEAP_PRIORICODA_H_

#include "Priorielem.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//realizzazione di una coda con priorità tramite una lista (dinamica monodirezionale) non ordinata
//valore di priorità minore indica priorità maggiore
const int MAX=1024;
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
    bool vuota()const;

    //operatori ereditati dell'insieme
    bool insiemevuoto() const;
    bool appartiene(tipoelem) const;


private:
    tipoelem prioricoda[MAX];
    int ultimo;
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
   ultimo=0;
}
template<class P> bool Prioricoda<P>::vuota()const //crea la coda con priorità
{
  return (ultimo==0);
}


template<class P> void Prioricoda<P>::inserisci(tipoelem a) //inserimento
{
	int i,k;
	tipoelem temp;
	if (ultimo == MAX)
	{ cout<<"Coda con priorità piena"<<endl; }
	else{
	ultimo =ultimo +1;
	prioricoda[ultimo] = a;
	i = ultimo;
	if (i>1){ k = i/2;}
	while ( i>1 && prioricoda[i]<prioricoda[k] ){
	temp = prioricoda[i];
	prioricoda[i] = prioricoda[k];
	prioricoda[k] = temp;
	i = k;
	if (i>1){ k = i/2;};
	}
}

}

template<class P> Priorielem<P> Prioricoda<P>::min() const //restituisce il minimo della coda
{
	if(vuota()){
		cout<<"Coda con priorità vuota"<<endl;
	}
	else{
		return prioricoda[1];
	}
}

template<class P> void Prioricoda<P>::cancellamin() //elimina il minimo dalla coda
{
	int i,k;
	tipoelem temp;
	bool scambio=false;


	if (vuota())
	{ cout<<"Coda con priorità vuota"<<endl; }
	else{

	prioricoda[1] = prioricoda[ultimo];
	ultimo = ultimo-1;
	i = 1;
	scambio = true;
	while ( i<=(ultimo/2) && scambio){
	k = 2*i;
	if (k < ultimo) {
	if (prioricoda[k] > prioricoda[k+1]){
		k=k+1;
	}
	}
	if (prioricoda[k] < prioricoda[i]){
	temp = prioricoda[i];
	prioricoda[i] = prioricoda[k];
	prioricoda[k] = temp;
	i = k;
	}
	else{
	scambio = false;
	}
	}
	}
}


template<class P> bool Prioricoda<P>::insiemevuoto() const //verifica se la coda è vuota
{
    return (ultimo==0);
}

template<class P> bool Prioricoda<P>::appartiene(tipoelem a) const //verifica se l'elemento appartiene alla coda
{
    bool trovato=false;
    tipoelem k;
    if (!ultimo==0)
    {
        int indice=0;
        while ((indice != ultimo) && !trovato)
        {
            k = prioricoda[indice];
            if (k==a) //se l'elemento corrente è il cercato
                trovato=true;
            else indice=indice+1;
        }
    }
    return(trovato);
}


#endif /* STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_CODA_PRIOR_VETTORE_HEAP_PRIORICODA_H_ */
