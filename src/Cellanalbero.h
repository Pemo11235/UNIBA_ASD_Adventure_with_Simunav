#ifndef CELLANALBERO_H
#define CELLANALBERO_H

#include "Cellams.h"

//Cella (atomo) base per l'albero ennario dinamico

template<class T> class cellanalbero:public cella<T> //ereditarietà della classe cella
{
public:
    cellanalbero(); //usa costruttore e distruttore di default

    cellanalbero<T>* getprec();
    void setprec(cellanalbero<T>*);
    cellanalbero<T>* getsucc();
    void setsucc(cellanalbero<T>*);
    cellanalbero<T>* getpadre();
    void setpadre(cellanalbero<T>*);
    cellanalbero<T>* getfiglio();
    void setfiglio(cellanalbero<T>*);

private:
    cellanalbero<T>* padre; //riferimento al nodo padre
    cellanalbero<T>* figlio; //riferimento al nodo figlio
    cellanalbero<T>* prec; //riferimento al nodo fratello precedente
    cellanalbero<T>* succ; //riferimento al nodo fratello successivo
};

template<class T> cellanalbero<T>::cellanalbero()
{

}

template<class T> cellanalbero<T>* cellanalbero<T>::getprec()
{
    return prec;
}

template<class T> void cellanalbero<T>::setprec(cellanalbero<T>* c)
{
    prec = c;
}

template<class T> cellanalbero<T>* cellanalbero<T>::getsucc()
{
    return succ;
}

template<class T> void cellanalbero<T>::setsucc(cellanalbero<T>* c)
{
    succ = c;
}

template<class T> cellanalbero<T>* cellanalbero<T>::getpadre()
{
    return padre;
}

template<class T> void cellanalbero<T>::setpadre(cellanalbero<T>* c)
{
    padre = c;
}

template<class T> cellanalbero<T>* cellanalbero<T>::getfiglio()
{
    return figlio;
}

template<class T> void cellanalbero<T>::setfiglio(cellanalbero<T>* c)
{
    figlio = c;
}

#endif // CELLANALBERO_H
