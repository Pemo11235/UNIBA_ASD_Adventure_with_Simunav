/**
 * @file Insieme.h
 * Definizione della struttura dati "Insieme".
 * @note Definizione di Insieme per la realizzazione tramite lista.
 * @author Sconosciuto, modificato da Andrea Esposito.
 * @date Anno Accademico 2018/19.
 */
#ifndef INSIEME_H_
#define INSIEME_H_

#include "Lista.h"

/**
 * @brief Insieme
 * Questa classe contiene tutti gli operatori tipici della struttura
 * dati "Insieme".
 * @author Sconosciuto, modificato da Andrea Esposito.
 */
template <class TipoElem>
class Insieme
{
public:
	Insieme();
	Insieme(const Insieme&);
	~Insieme();

    /**
     * @brief Crea un insieme vuoto.
     * @post Il nuovo insieme i è l'insieme vuoto (i={}).
     */
	void creainsieme();

	/**
	 * @brief Controlla se l'insieme è vuoto.
	 * @return true se l'insieme è vuoto, false altrimenti.
	 */
	bool insiemevuoto() const;

	/**
	 * @brief controlla se un elemento appartiene all'insieme.
	 * @param[in] L'elemento da controllare
	 * @return true se l'elemento appartiene all'insieme, false altrimenti.
	 */
	bool appartiene(const TipoElem& e) const;

	/**
	 * @brief Inserisce un elemento nell'insieme.
	 * @param[in] e L'elemento da aggiungere
	 * @post L'elemento e è aggiunto all'insieme.
	 */
	void inserisci(const TipoElem& e);

	/**
	 * @brief Rimuove un elemento dall'insieme.
	 * @param[in] e L'elemento da rimuovere.
	 * @post L'elemento e è rimosso dall'insieme.
	 */
	void cancella(const TipoElem& e);

	/**
	 * @brief Unione (matematica) di due insiemi.
	 * @param[in] i Insieme da unire.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * iniziali e gli elementi dell'insieme i.
	 */
	void unione(const Insieme& i);

	/**
	 * @brief Intersezione (matematica) di due insiemi.
	 * @param[in] i Insieme da intersecare.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * presenti sia nell'insieme iniziale che in i.
	 */
	void intersezione(const Insieme& i);

	/**
	 * @brief Differenza (matematica) di due insiemi.
	 * @param[in] i Insieme da sottrarre.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * iniziali che non appartengono anche a i.
	 */
	void differenza(const Insieme& i);

private:
	Lista<TipoElem> setlist;
};

template <class TipoElem>
Insieme<TipoElem>::Insieme()
{
    creainsieme();
}

template <class TipoElem>
Insieme<TipoElem>::Insieme(const Insieme<TipoElem>& i)
{
	/*
	 * La seguente istruzione suppone che sia presente
	 * un costruttore di copia per le liste. Tale 
	 * supposizione non è casuale: il C++ ne richiede
	 * uno, per cui in sua assenza ne definisce uno
	 * di default.
	 */
	setlist = Lista<TipoElem>(i.setlist);
}

template <class TipoElem>
Insieme<TipoElem>::~Insieme()
{
	typename Lista<TipoElem>::posizione p = setlist.primolista();
	while (!setlist.finelista(p))
        setlist.canclista(p);
}

template <class TipoElem>
void Insieme<TipoElem>::creainsieme()
{
    setlist.crealista();
}

template <class TipoElem>
bool Insieme<TipoElem>::insiemevuoto() const
{
    return setlist.listavuota();
}

template <class TipoElem>
bool Insieme<TipoElem>::appartiene(const TipoElem& e) const
{
    bool trovato = false;
    typename Lista<TipoElem>::posizione p = setlist.primolista();
    while (!setlist.finelista(p) && !trovato)
    {
        if(setlist.leggilista(p) == e)
            trovato = true;
        else
            p = setlist.succlista(p);
    }
    return trovato;
}

template <class TipoElem>
void Insieme<TipoElem>::inserisci(const TipoElem& e)
{
    if (!appartiene(e))
    {
        typename Lista<TipoElem>::posizione p = setlist.primolista();
        setlist.inslista(e, p);
    }
}

template <class TipoElem>
void Insieme<TipoElem>::cancella(const TipoElem& e)
{
    typename Lista<TipoElem>::posizione p = setlist.primolista();
    while (!setlist.finelista(p) && setlist.leggilista(p) != e)
        p = setlist.succlista(p);
    if (setlist.leggilista(p) == e)
        setlist.canclista(p);
}

template <class TipoElem>
void Insieme<TipoElem>::unione(const Insieme<TipoElem>& i)
{
    typename Lista<TipoElem>::posizione p = i.setlist.primolista();
    while (!i.setlist.finelista(p))
    {
		inserisci(i.setlist.leggilista(p));
        p = i.setlist.succlista(p);
    }
}

template <class TipoElem>
void Insieme<TipoElem>::intersezione(const Insieme<TipoElem>& i)
{
    typename Lista<TipoElem>::posizione p = setlist.primolista();

	while(!setlist.finelista(p))
	{
		if(!i.appartiene(setlist.leggilista(p)))
			cancella(setlist.leggilista(p));
		else
			p = setlist.succlista(p);
	}
}

template <class TipoElem>
void Insieme<TipoElem>::differenza(const Insieme<TipoElem>& i)
{
    typename Lista<TipoElem>::posizione p = i.setlist.primolista();
    
	while(!setlist.finelista(p))
	{
		if(i.appartiene(setlist.leggilista(p)))
			cancella(setlist.leggilista(p));
		else
			p = setlist.succlista(p);
	}
}

#endif /* INSIEME_H_ */

