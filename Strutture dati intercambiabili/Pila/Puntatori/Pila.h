/**
 * @file Pila.h
 * Definizione della struttura dati "Pila".
 * @note Definizione di Pila per la realizzazione tramite puntatori.
 * @author Sconosciuto, modificato da Niccolo' Petti.
 * @date Anno Accademico 2018/19.
 */
#ifndef _PILA_H_INCLUDED
#define _PILA_H_INCLUDED
#include<assert.h>
#include "Cella_Pila_P_Mono.h"


/**
 * @brief Pila
 * Questa classe contiene tutti gli operatori tipici della struttura dati "Pila".
 * @note Pila p=< e1,..., en>
 * @author Sconosciuto, modificato da Niccolo' Petti.
 */
template <class T> class Pila {

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
      * @post l'elemento @a elem e' inserito nella pila (p=<elem,e1,...,en>)
      */
    	void inpila(tipoelem elem);

private:
        typedef Cella_Pila_P_Mono<T> posizione;
    	posizione* testa;
};


template <class T> Pila<T>::Pila() {
  creapila();
}

template <class T> Pila<T>::~Pila() {
    while(!pilavuota())
    fuoripila();
        delete testa;
}

template <class T> void Pila<T>::creapila() {
	testa = nullptr;
}

template <class T> bool Pila<T>::pilavuota() const{
    return(testa == nullptr);
}

template <class T> T Pila<T>::leggipila() const{
	assert(!pilavuota());
    return testa->leggiCella();
}

template <class T> void Pila<T>::fuoripila(){
    assert(!pilavuota());
	posizione* temp = new posizione;
    temp=testa;
    testa=testa->leggiSucc();
    delete temp;
}

template <class T> void Pila<T>::inpila(tipoelem elem){
    posizione* temp = new posizione;
    temp->scriviCella(elem);
    temp->scriviSucc(testa);
    testa=temp;
}
#endif //   _PILA_H_INCLUDED
