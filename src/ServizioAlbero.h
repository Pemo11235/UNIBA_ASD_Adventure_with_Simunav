#ifndef SERVIZIOALBERO_H_INCLUDED
#define SERVIZIOALBERO_H_INCLUDED
#include "AlberoNario.h"
#include "Pila.h"

template <class tipoelem>
void Postvisita(Albero<tipoelem> & na, Albero<tipoelem>::nodo& n){
    Pila<Albero<tipoelem>::nodo> pila;
    Albero<tipoelem>:: nodo temp;
    pila.inpila(na.radice());
    while(!pila.pilavuota()){
            if(!na.foglia(n)){
        temp=pila.leggipila();
        pila.fuoripila();
        par[cont++] = na.legginodo(temp);
        temp=na.primofiglio(n);
        while(!na.ultimofratello(temp)){
            pila.inpila(temp);
            temp=na.succfratello(temp);
        }
        pila.inpila(na.primofiglio(temp));

    }
    }
}


#endif // SERVIZIOALBERO_H_INCLUDED
