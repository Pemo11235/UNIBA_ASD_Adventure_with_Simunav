#ifndef CELLA_H
#define CELLA_H
#include <iostream>
using namespace std;
template <class T>

class Cella
{
public:
    typedef T tipoelem;
    Cella();
    Cella(tipoelem);
    virtual ~Cella();
    void setetichetta(tipoelem);
    tipoelem getetichetta();
    void setprimofiglio(Cella*);
    Cella* getprimofiglio();
    void setfratellosucc(Cella*);
    Cella* getfratellosucc();
    void setpadre(Cella*);
    Cella* getpadre();
    bool operator==(Cella);
private:
    tipoelem etichetta;
    Cella* primofiglio;
    Cella* fratellosucc;
    Cella* padre;
};

template <class T> Cella<T>::Cella()
{
    T elemento;
    this->etichetta=elemento;
    this->primofiglio=NULL;
    this->fratellosucc=NULL;
    this->padre=NULL;
}

template <class T> Cella<T>::~Cella() {}

template <class T> Cella<T>::Cella(tipoelem a)
{
    this->etichetta=a;
    this->primofiglio=NULL;
    this->fratellosucc=NULL;
    this->padre=NULL;
}

template <class T> void Cella<T>::setetichetta(tipoelem a)
{
    this->etichetta=a;
}

template <class T> T Cella<T>::getetichetta()
{
    return etichetta;
}

template <class T> void Cella<T>::setprimofiglio(Cella* a)
{
    this->primofiglio=a;
}

template <class T> Cella<T>* Cella<T>::getprimofiglio()
{
    return primofiglio;
}

template <class T> void Cella<T>::setfratellosucc(Cella* a)
{
    this->fratellosucc=a;
}

template <class T> Cella<T>* Cella<T>::getfratellosucc()
{
    return fratellosucc;
}

template <class T> void Cella<T>::setpadre(Cella* a)
{
    this->padre=a;
}

template <class T> Cella<T>* Cella<T>::getpadre()
{
    return padre;
}

template <class T> bool Cella<T>::operator==(Cella a)
{
    return (this->etichetta==a.getetichetta());
}

#endif // CELLA_H
