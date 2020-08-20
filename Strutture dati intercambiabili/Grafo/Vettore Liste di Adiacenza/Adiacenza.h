#ifndef _ADIACENZA_H
#define _ADIACENZA_H

#include <iostream>
#include <cstdlib>

using namespace std;

//tipo dell'elemento che sarà usato nella lista di adiacenza del grafo pesato

template<class nodo,class tipoPeso> class Adiacenza
{
public:


    //costruttori (generico di default)
    Adiacenza();
    Adiacenza(nodo,tipoPeso);
    ~Adiacenza();
    //distruttore di default

    //setter e getter
    void scrivinodo(nodo);
    nodo legginodo() const;
    void scrivipeso(tipoPeso);
    tipoPeso leggipeso() const;


private:
    nodo adiacente; //riferimento al nodo adiacente
    tipoPeso peso; //peso dell'arco

};


template <class nodo,class tipoPeso> Adiacenza<nodo,tipoPeso>::Adiacenza() //costruttore generico
{
}

template <class nodo,class tipoPeso> Adiacenza<nodo,tipoPeso>::Adiacenza(nodo n,tipoPeso p) //costruttore specifico
{
    adiacente=n;
    peso=p;
}

template <class nodo,class tipoPeso> Adiacenza<nodo,tipoPeso>::~Adiacenza()
{
    //dtor
}

template <class nodo,class tipoPeso> void Adiacenza<nodo,tipoPeso>::scrivinodo(nodo n)
{
    adiacente=n;
}

template <class nodo,class tipoPeso> void Adiacenza<nodo,tipoPeso>::scrivipeso(tipoPeso p)
{
    peso=p;
}

template <class nodo,class tipoPeso> nodo Adiacenza<nodo,tipoPeso>::legginodo() const
{
    return(adiacente);
}

template <class nodo,class tipoPeso> tipoPeso Adiacenza<nodo,tipoPeso>::leggipeso() const
{
    return(peso);
}


//sovraccarico output

template<class nodo,class tipoPeso> ostream& operator<<(ostream& os, const Adiacenza<nodo,tipoPeso>& a)
{
    os<<"("<<a.legginodo()<<"|"<<a.leggipeso()<<")";
    return(os);
}

#endif
