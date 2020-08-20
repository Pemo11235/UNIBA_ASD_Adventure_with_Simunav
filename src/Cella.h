#ifndef CELLALISTA_H
#define CELLALISTA_H

#include "Cellams.h"

//Cella (atomo) base per pila dinamica

template<class T> class Cella:public cella<T> //ereditarietà dell'oggetto cella
{
public:
    typedef T tipoelem;
    Cella();  //usa costruttore e distruttore di default
    void scrivicella(tipoelem);
    tipoelem leggicella() const;
    Cella<T>* leggiprec();
    void scriviprec(Cella<T>*);
    Cella<T>* leggisucc();
    void scrivisucc(Cella<T>*);

private:
    tipoelem elemento;
    Cella<T>* prec; //riferimento al nodo precedente
    Cella<T>* succ; //riferimento al nodo successivo
};

template<class T> Cella<T>::Cella()
{

}

template<class T> void Cella<T>::scrivicella(tipoelem label)
{
    elemento = label;
}

template<class T> T Cella<T>::leggicella() const
{
    return elemento;
}

template<class T> Cella<T>* Cella<T>::leggiprec()
{
    return prec;
}

template<class T> void Cella<T>::scriviprec(Cella<T>* c)
{
    prec = c;
}

template<class T> Cella<T>* Cella<T>::leggisucc()
{
    return succ;
}

template<class T> void Cella<T>::scrivisucc(Cella<T>* c)
{
    succ = c;
}

#endif // CELLALISTA_H
