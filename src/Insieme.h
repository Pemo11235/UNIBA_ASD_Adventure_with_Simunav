/*
 * Insieme.h
 *
 *  Created on: 19 gen 2017
 *      Author: Angelo
 */

#ifndef STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_INSIEMI_LISTA_PUNT_INSIEME_H_
#define STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_INSIEMI_LISTA_PUNT_INSIEME_H_

#include "Lista.h"


template <class I> class Insieme {
public:
	typedef I tipoelem; //definisco il tipo tipoelem
	Insieme();
	Insieme(const Insieme&);
	~Insieme();

	//operatori
	void creainsieme();
	bool insiemevuoto() const;
	bool appartiene(const tipoelem&) const;
	void inserisci(const tipoelem&);
	void cancella(const tipoelem&);
	void unione(const Insieme<I> &);
	void intersezione(const Insieme<I> &);
	void differenza(const Insieme<I> &);

private:
	Lista<I> lista;
};

template <class I> Insieme<I>::Insieme()
{
	creainsieme();
}


template <class I>
Insieme<I>::Insieme(const Insieme<I>& i)
{
	/*
	 * La seguente istruzione suppone che sia presente
	 * un costruttore di copia per le liste. Tale 
	 * supposizione non è casuale: il C++ ne richiede
	 * uno, per cui in sua assenza ne definisce uno
	 * di default.
	 */
	lista = Lista<I>(i.lista);
}

template <class I> Insieme<I>::~Insieme() {}

template <class I> void Insieme<I>::creainsieme() {
	lista.crealista();
}

template <class I> bool Insieme<I>::insiemevuoto() const
{
	return (lista.listavuota());
}

template <class I> bool Insieme<I>::appartiene(const tipoelem& elemento) const
{
	bool trovato = false;  //creo un flag per il controllo e un indice di tipo puntatore a cella
	typename Lista<I>::posizione indice = lista.primolista();

	while (!(lista.finelista(indice)) && !trovato)
	{
		if (elemento == lista.leggilista(indice))
		{
			trovato = true;
		}
		else
			indice = lista.succlista(indice);
	}
	return(trovato);
}

template <class I> void Insieme<I>::inserisci(const tipoelem& elemento)
{
	typename Lista<I>::posizione indice = lista.primolista();

	if (!appartiene(elemento))
		lista.inslista(elemento, indice);
}

template<class I> void Insieme<I>::cancella(const tipoelem& elemento)
{
	typename Lista<I>::posizione p = lista.primolista();
    while (!lista.finelista(p) && lista.leggilista(p) != elemento)
        p = lista.succlista(p);
    if (lista.leggilista(p) == elemento)
        lista.canclista(p);
	
}




template <class I> void Insieme<I>::unione(const Insieme<I>& i)
{
    typename Lista<I>::posizione p = i.lista.primolista();
    while (!i.lista.finelista(p))
    {
		inserisci(i.lista.leggilista(p));
        p = i.lista.succlista(p);
    }
}




template <class I> void Insieme<I>::intersezione(const Insieme<I>& i)
{
    typename Lista<I>::posizione p = lista.primolista();

	while(!lista.finelista(p))
	{
		if(!i.appartiene(lista.leggilista(p)))
			cancella(lista.leggilista(p));
		else
			p = lista.succlista(p);
	}
}


template <class I> void Insieme<I>::differenza(const Insieme<I>& i)
{
    typename Lista<I>::posizione p = i.lista.primolista();
    
	while(!lista.finelista(p))
	{
		if(i.appartiene(lista.leggilista(p)))
			cancella(lista.leggilista(p));
		else
			p = lista.succlista(p);
	}
}


#endif /* STRUTTURE_INTERCAMBIABILI_STRUTTURE_INTERCAMBIABILI_DEL_GIUDICE_INSIEMI_LISTA_PUNT_INSIEME_H_ */
