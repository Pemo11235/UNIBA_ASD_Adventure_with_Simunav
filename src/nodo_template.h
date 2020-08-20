#ifndef _NODOTEMPLATE_H
#define _NODOTEMPLATE_H
#include <iostream>

template<class T> class Nodo
{
public:
    typedef T tipoelem;
    Nodo(); //costruttore di default
    ~Nodo(); //distruttore di default
    Nodo(tipoelem x, Nodo* p, Nodo* s); //costruttore specifico
    Nodo* getPrec() const; //ritorna il puntatore al nodo precedente
    tipoelem getElem() const; //ritorna il dato di un nodo
    Nodo* getSucc() const; //ritorna il puntatore al nodo successivo
    void setPrec(Nodo* p); //imposta il puntatore al nodo precedente
    void setElem(tipoelem x); //scrive il dato x in un nodo
    void setSucc(Nodo* s); //imposta il puntatore al successivo nodo
    bool operator == (Nodo n); //ridefinisco l'operatore ==
private:
    Nodo* prec;
    tipoelem dato;
    Nodo* succ;
};

template<class T> Nodo<T> :: Nodo(tipoelem x, Nodo* p, Nodo* s)
{
    prec = p;
    dato = x;
    succ = s;
}

template<class T> Nodo<T> :: ~Nodo() {}

template<class T> Nodo<T>* Nodo<T> :: getPrec() const
{
    return prec;
}

template<class T> T Nodo<T> :: getElem() const
{
    return dato;
}

template<class T> Nodo<T>* Nodo<T> :: getSucc() const
{
    return succ;
}

template<class T> void Nodo<T> :: setPrec(Nodo* p)
{
    prec = p;
}

template<class T> void Nodo<T> :: setElem(tipoelem x)
{
    dato = x;
}

template<class T> void Nodo<T> :: setSucc(Nodo* s)
{
    succ = s;
}

template<class T> bool Nodo<T> :: operator == (Nodo n)
{
    return (getElem() == n.getElem());
}



#endif /* NODO_TEMPLATE_H */
