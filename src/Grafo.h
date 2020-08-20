/**
 * @file Grafo.h
 * Definizione struttura dati Grafo realizzata mediante Matrice di Adiacenza
 * @author Graziano Montanaro.
 * @date Anno Accademico 2018/19.
 */

#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "CellaGrafo.h"
#include "CellaNodo.h"
#include <iostream>
#include "Lista.h"
#define maxNodi 50


template <class tipoElem, class tipoPeso>
class Grafo
{
public:
    class nodo;
    Grafo();
    ~Grafo();
    void creagrafo();
    bool grafovuoto();
    void insarco(nodo&,nodo&);
    void cancarco(nodo&,nodo&);
    void insnodo(nodo &);
    void cancnodo(nodo&);
    Lista<nodo> adiacenti(nodo&);
    bool esistenodo(nodo&);
    bool esistearco(nodo&,nodo&);
    void scrivinodo(tipoElem,nodo);
    void scriviarco(tipoPeso,nodo&,nodo&);
    tipoElem legginodo(nodo&);
    tipoPeso leggiarco(nodo&,nodo&);


private:

        unsigned int nodiUsati;
        unsigned int primoLibero();
        CellaGrafo<tipoPeso> matrice[maxNodi][maxNodi];
        CellaNodo<tipoElem> nodi[maxNodi];
};


// Definizione del tipo nodo

template <class tipoElem, class tipoPeso>
class Grafo<tipoElem,tipoPeso>::nodo
{
public:
    nodo();
    nodo(const nodo&);
    ~nodo();
    int legginodo();
    void scrivinodo(int n);
    bool  operator == ( const nodo& );
    bool  operator != ( const nodo& );


private:
    int valore;
};



template <class tipoElem, class tipoPeso>
Grafo<tipoElem , tipoPeso>::Grafo()
{
    nodiUsati = 0;
    for(int i=0;i<maxNodi;i++)
    {
        nodi[i].setPresente(false);
        for(int j=0;i<maxNodi;i++)
            matrice[i][j].setUsato(false);
    }
}

template <class tipoElem, class tipoPeso>
Grafo<tipoElem , tipoPeso>::~Grafo()
{

}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem , tipoPeso>::grafovuoto()
{
    return nodiUsati == 0;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem, tipoPeso>::esistenodo(nodo &n)
{
    if(n.legginodo()>=0 && n.legginodo()<nodiUsati)
        return nodi[n.legginodo()].getPresente();
    else
        return false;
}

template <class tipoElem, class tipoPeso>
tipoPeso Grafo<tipoElem , tipoPeso>::leggiarco(nodo& n1, nodo& n2)
{
    if(esistearco(n1,n2))
        return matrice[n1.legginodo()][n2.legginodo()].getPeso();


}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::insnodo(nodo & n)
{
    if(!esistenodo(n))
    {
        if(nodiUsati<maxNodi)
        {
            unsigned int  i = primoLibero();
            nodi[i].setPresente(true);
            nodi[i].setArchi(0);
            n.scrivinodo(i);
            nodiUsati++;
        }
    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::cancnodo(nodo& n)
{
    if(esistenodo(n))
    {
        nodo* temp = new nodo;
        for(int i=0;i<nodiUsati;i++)
        {
            temp->scrivinodo(i);
            if(esistearco(*temp,n))
                cancarco(*temp,n);
            if(esistearco(n,*temp))
                cancarco(n,*temp);
        }
        nodi[n.legginodo()].setPresente(false);
        nodiUsati--;


    }

}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::insarco(nodo &n1, nodo &n2)
{
    if(!esistearco(n1,n2))
    {
        matrice[n1.legginodo()][n2.legginodo()].setUsato(true);
        nodi[n1.legginodo()].setArchi(nodi[n1.legginodo()].getArchi()+1);
        nodi[n2.legginodo()].setArchi(nodi[n2.legginodo()].getArchi()+1);
    }


}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::cancarco(nodo& n1, nodo& n2)
{
    if(esistearco(n1,n2))
    {
        matrice[n1.legginodo()][n2.legginodo()].setUsato(false);
        nodi[n1.legginodo()].setArchi(nodi[n2.legginodo()].getArchi() -1);
        nodi[n2.legginodo()].setArchi(nodi[n2.legginodo()].getArchi() -1);

    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::scrivinodo(tipoElem e, nodo n)
{
    if(esistenodo(n))
    {
        nodi[n.legginodo()].setEtichetta(e);
    }

}

template <class tipoElem, class tipoPeso>
tipoElem Grafo<tipoElem , tipoPeso>::legginodo(nodo& n)
{
    if(esistenodo(n))
    {
        return nodi[n.legginodo()].getEtichetta();
    }
}

template <class tipoElem, class tipoPeso>
void Grafo<tipoElem , tipoPeso>::scriviarco(tipoPeso p,nodo& n1, nodo& n2)
{
    if(!esistearco(n1,n2))
    {
        matrice[n1.legginodo()][n2.legginodo()].setPeso(p);
    }

}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem , tipoPeso>::esistearco(nodo& n1, nodo& n2)
{
    if(esistenodo(n1))
        if(esistenodo(n2))
            return matrice[n1.legginodo()][n2.legginodo()].getUsato();

}


template <class tipoElem, class tipoPeso>
Lista<typename Grafo<tipoElem,tipoPeso>::nodo> Grafo<tipoElem , tipoPeso>::adiacenti(nodo& n)
{
    Lista<nodo> l;
    typename Lista<nodo>::posizione p = l.primolista();
    for(int i=0;i<nodiUsati;i++)
    {
        if(matrice[n.legginodo()][i].getUsato())
        {
            nodo* temp = new nodo();
            temp->scrivinodo(i);
            l.inslista(*temp,p);
        }
    }
    // Nodi di cui n è coda
    /*for(int i=0;i<nodiUsati;i++)
    {
        if(matrice[i][n].getUsato())
            if(!matrice[n][i].getUsato())
            l.inslista(i,p);
    }*/
    return l;
}

template <class tipoElem, class tipoPeso>
unsigned int Grafo<tipoElem,tipoPeso>::primoLibero()
{
     nodo i;
     i.scrivinodo(-1);
    bool libero=false;
    while(!libero)
    {
        i.scrivinodo(i.legginodo()+1);
        if(nodi[i.legginodo()].getPresente()==false)
            libero = true;
    }
    return i.legginodo();
}

//Operatori NODO

template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::nodo()
{
   valore = -1;
}



template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::nodo(const nodo& n)
{
   valore = n.valore;
}



template <class tipoElem, class tipoPeso>
Grafo<tipoElem,tipoPeso>::nodo::~nodo()
{

}


template <class tipoElem, class tipoPeso>
int Grafo<tipoElem,tipoPeso>::nodo::legginodo()
{
    return valore;
}


template <class tipoElem, class tipoPeso>
void Grafo<tipoElem,tipoPeso>::nodo::scrivinodo(int n)
{
    valore = n;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::nodo:: operator == ( const nodo& n)
{
    return valore == n.valore;
}

template <class tipoElem, class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::nodo:: operator != ( const nodo& n)
{
    return valore != n.valore;
}


#endif // GRAFO_H_INCLUDED
