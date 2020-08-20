/**
 * @file Pila.h
 * Definizione della struttura dati "Pila".
 * @note Definizione di Pila per la realizzazione tramite vettore.
 * @author "Frast", modificato da Niccolo' Petti.
 * @date creato il 23/11/2017, modificato durante l'Anno Accademico 2018/19.
 */
#ifndef _PILA_H_INCLUDED
#define _PILA_H_INCLUDED
#include <assert.h>

/**
 * @brief Pila
 * Questa classe contiene tutti gli operatori tipici della struttura dati "Pila".
 * @note Pila p=< e1,..., en>
 * @author Sconosciuto, modificato da Niccolo' Petti.
 */
template <class T> class Pila{

public:
    typedef T tipoelem;
    Pila();

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
    static const int  SIZE_VETT=100;
    tipoelem vett[SIZE_VETT];
    int testa;

};


template <class tipoelem> Pila<tipoelem>::Pila(){
creapila();
}


template <class tipoelem> void Pila<tipoelem>::creapila(){
    testa=0;
}

template <class tipoelem> bool Pila<tipoelem>::pilavuota() const{
    return (testa == 0);
}

template <class tipoelem> void Pila<tipoelem>::inpila(tipoelem a){
    testa++;
    assert(testa<=SIZE_VETT);
    vett[testa-1]=a;
}

template <class tipoelem> tipoelem Pila<tipoelem>::leggipila() const {
    assert(!pilavuota());
    return vett[testa-1];
}

template <class tipoelem> void Pila<tipoelem>::fuoripila() {
    assert(!pilavuota());
    testa--;
}
#endif //   _PILA_H_INCLUDED

