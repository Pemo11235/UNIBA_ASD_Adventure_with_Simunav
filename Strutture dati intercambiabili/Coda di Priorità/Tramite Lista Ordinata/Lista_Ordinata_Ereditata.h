/*
 Definizione della struttura dati "Lista Ordinata".
 Definizione di Lista Ordinata per la realizzazione tramite ereditarietà da Lista.
 Autore: 	Andrea Esposito.
 Modificata da: Matteo Luceri
*/

#ifndef LISTA_ORDINATA_EREDITATA_H_
#define LISTA_ORDINATA_EREDITATA_H_

#include "Lista_Con_Puntatori_Monodirezionale.h"

template <class T>
class ListaOrdinata : private Lista<T>
{
public:
    typedef typename Lista<T>::posizione posizione;

    ListaOrdinata();
    ListaOrdinata(const ListaOrdinata&);
    ~ListaOrdinata();

    void crealista();
    bool listavuota() const;
    bool finelista(posizione) const;
    posizione primolista() const;
    posizione succlista(posizione) const;
    posizione preclista(posizione) const;
    T leggilista(posizione) const;
    void inslista(T);
    void canclista(posizione&);
};

template <class T>
ListaOrdinata<T>::ListaOrdinata() :
    Lista<T>() // call parent constructor
{

}

template <class T>
ListaOrdinata<T>::ListaOrdinata(const ListaOrdinata<T>& l):
    Lista<T>(l) // call parent constructor
{

}

template <class T>
ListaOrdinata<T>::~ListaOrdinata()
{
    Lista<T>::~Lista();
}

template <class T>
void ListaOrdinata<T>::crealista()
{
    Lista<T>::crealista();
}

template <class T>
bool ListaOrdinata<T>::listavuota() const
{
    return Lista<T>::listavuota();
}

template <class T>
typename ListaOrdinata<T>::posizione ListaOrdinata<T>::primolista() const
{
    return Lista<T>::primolista();
}

template <class T>
bool ListaOrdinata<T>::finelista(posizione p) const
{
    return Lista<T>::finelista(p);
}

template <class T>
typename ListaOrdinata<T>::posizione ListaOrdinata<T>::succlista(posizione p) const
{
    return Lista<T>::succlista(p);
}

template <class T>
typename ListaOrdinata<T>::posizione ListaOrdinata<T>::preclista(posizione p) const
{
    return Lista<T>::preclista(p);
}

template <class T>
void ListaOrdinata<T>::inslista(T el)
{
    posizione p = primolista();
    if(!listavuota())
        while(leggilista(p) < el && !finelista(p))
            p = succlista(p);

    Lista<T>::inslista(el, p);
}

template <class T>
void ListaOrdinata<T>::canclista(posizione &p)
{
    Lista<T>::canclista(p);
}

template <class T>
T ListaOrdinata<T>::leggilista(posizione p) const
{
    return Lista<T>::leggilista(p);
}

#endif /* LISTA_ORDINATA_EREDITATA_H_ */
