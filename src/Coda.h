#ifndef CODA_H_
#define CODA_H_

#include "Lista.h"
template <class T> class Coda
{
    public:
        typedef T tipoelem;
        Coda(); //Costruttore di default
        ~Coda(); //Distruttore
        void creacoda(); //Crea la cosa
        bool codavuota(); //Restituisce true se la coda e' vuota, false altrimenti
        void incoda(tipoelem); //Incoda elemento di tipo tipoelem
        tipoelem leggicoda(); //Leggi elemento di tipo tipoelem
        void fuoricoda(); //Estrai elemento di tipo tipoelem dalla coda

    private:
        Lista<T> coda_lista;

};
template<class T>Coda<T>::Coda() { 
	creacoda();
};

template<class T>Coda<T>::~Coda()
{
    coda_lista.~Lista(); //Chiama il distruttore della lista
};

template<class T> void Coda<T>::creacoda() //Crea la lista
{
	coda_lista.crealista();
};

template<class T>bool Coda<T>::codavuota()
{
    return (coda_lista.listavuota()); //Controlla se la lista e' vuota
};

template<class T>void Coda<T>::incoda(tipoelem x)
{
    typename Lista<T>::posizione pos = coda_lista.primolista(); //Posizionati sul primo elemento
    while(!coda_lista.finelista(pos)) //Finche' non raggiungi l'ultimo elemento, aggiorna la posizione
        {
            pos = coda_lista.succlista(pos);
        }
    coda_lista.inslista(x,pos); //Inserisci l'elemento in coda alla lista
};

template<class T> T Coda<T>::leggicoda()
{
    if(!codavuota()) //Precondizione: se la coda non e' vuota
        return(coda_lista.leggilista(coda_lista.primolista()));
};

template<class T>void Coda<T>::fuoricoda()
{
    typename Lista<T>::posizione pos = coda_lista.primolista(); //Posizionati sul primo elemento
    if(!codavuota()) //Precondizione: se la coda non e' vuota
        coda_lista.canclista(pos); //Cancella il primo elemento della coda
};

#endif
