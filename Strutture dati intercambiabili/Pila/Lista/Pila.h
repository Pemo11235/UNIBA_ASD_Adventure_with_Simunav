/**
 * @file Pila.h
 * Definizione della struttura dati "Pila".
 * @note Definizione di Pila per la realizzazione tramite lista.
 * @author Niccolo' Petti.
 * @date Anno Accademico 2018/19.
 */

#ifndef _PILA_H_INCLUDED
#define _PILA_H_INCLUDED
#include<assert.h>
#include "Lista.h"

/**
 * @brief Pila
 * Questa classe contiene tutti gli operatori tipici della struttura dati "Pila".
 * @note Pila p=< e1,..., en>
 * @author Niccolo' Petti.
 */
template <class T>
class Pila
{
public:
    typedef T tipoelem;

	Pila();
	~Pila();

	/**
      * @brief Crea una pila vuota.
      * @post la nuova pila p e' la pila vuota (p=<>).
      */
    	void creapila();

    /**
      * @brief Controlla se la pila e' vuota.
      * @return true se la pila e' vuota (p=<>), false altrimenti.
      */
    	bool pilavuota() const;

    /**
      * @brief Restituisce il valore dell'ultimo elemento inserito,
      * senza estrarlo dalla pila
      * @pre la pila non deve essere vuota (p!=<>)
      * @return l'ultimo elemento inserito (e1)
      */
    	tipoelem leggipila() const;

    /**
      * @brief Estrae dalla pila l'ultimo elemento inserito
      * @pre la pila non deve essere vuota (p!=<>)
      * @post L'ultimo elemento inserito e' rimosso dalla pila (p=<e2,...,en>)
      */
    	void fuoripila();

    /**
      * @brief Inserisce un nuovo elemento nella pila
      * @param[in] elem L'elemento da inserire
      * @pre la pila non deve aver raggiunto la sua dimensione massima @a SIZE_VETT
      * @post l'elemento @a elem e' inserito nella pila (p=<elem,e1,...,en>)
      */
    	void inpila(tipoelem elem);
private:
	Lista<tipoelem> pila;
};


template <class T>
Pila<T>::Pila()
{
	creapila();
}

template <class T>
Pila<T>::~Pila()
{
    //Viene richiamato automaticamente il distruttore della lista
}

template <class T>
void Pila<T>::creapila()
{
pila.crealista();
}

template <class T>
bool Pila<T>::pilavuota() const
{
	return pila.listavuota();
}

template <class T>
T Pila<T>::leggipila() const
{   assert(!pilavuota());
	return pila.leggilista(pila.primolista());
}

template <class T>
void Pila<T>::fuoripila()
{   assert(!pilavuota());
    typename Lista<T>::posizione first = pila.primolista();
	pila.canclista(first);
}

template <class T>
void Pila<T>::inpila(tipoelem el)
{
    typename Lista<T>::posizione first = pila.primolista();
	pila.inslista(el,first);
}
#endif //   _PILA_H_INCLUDED
