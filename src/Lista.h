#ifndef _LISTAMONO_H
#define _LISTAMONO_H
#include <iostream>
#include <cstdlib>
#include "Cella.h"
using namespace std;

template<class tipoelem> class Lista
{
public:
    typedef Cella<tipoelem>* posizione;

    Lista();
    Lista(const Lista<tipoelem>&);
    ~Lista();

    void crealista();
    bool listavuota() const;
    bool finelista(posizione) const;
    posizione primolista() const;
    posizione succlista(posizione) const;
    posizione preclista(posizione) const;
    tipoelem leggilista(posizione) const;

    void scrivilista(tipoelem, posizione);
    void inslista(tipoelem, posizione&);
    void canclista(posizione&);

    //Operatori ausiliari
    void svuota();

    void stampaLista (); //Modifica Zagaria -- aggiunta funzione stampalista

    Cella<tipoelem>* get_posizione()const; // MODIFICA D-R(D-R)

    //sovraccarichi
    void operator =(const Lista&);
    bool operator ==(Lista&);



private:
    posizione lista;
    unsigned int lungh;
    unsigned int lunghezza(); //Operatore ausiliario che restituisce la lunghezza della lista
};


template <class tipoelem> Lista<tipoelem>::Lista()
{
    crealista();
}

template <class tipoelem>
Lista<tipoelem>::Lista(const Lista& b)
{
    crealista();
    typename Lista<tipoelem>::posizione ind = primolista(),ind2 = b.primolista();
    while (!b.finelista(ind2))
    {
        inslista(b.leggilista(ind2),ind);
        ind = succlista(ind);
        ind2 = b.succlista(ind2);
    }
}

template <class tipoelem> Lista<tipoelem>::~Lista() //distruttore
{
    posizione ind=primolista();
    while (!finelista(ind))
    {
        canclista(ind);
    }
    delete lista;
}

template <class tipoelem> void Lista<tipoelem>::crealista()
{
    lista=new Cella<tipoelem>;
    lista->scrivisucc(nullptr);
    lungh=0;
}

template <class tipoelem> bool Lista<tipoelem>::listavuota() const
{
    return (lista->leggisucc()==nullptr);
}

template <class tipoelem> bool Lista<tipoelem>::finelista(posizione p) const
{
    return (p->leggisucc()==nullptr);
}

template <class tipoelem> Cella<tipoelem>* Lista<tipoelem>::primolista() const
{
    return (lista);
}
template <class tipoelem> Cella<tipoelem>* Lista<tipoelem>::succlista(posizione p) const
{
    if (!finelista(p))
        return (p->leggisucc());
    else
        return (p);
}

template <class tipoelem> Cella<tipoelem>* Lista<tipoelem>::preclista(posizione p) const
{
    if (p!=primolista() && !finelista(p))
    {
        posizione ind=primolista();
        while (ind->leggisucc()!=p)
        {
            ind=ind->leggisucc();
        }
        return(ind);
    }
    else
        return (p);

}

template <class tipoelem> tipoelem Lista<tipoelem>::leggilista(posizione p) const
{
    if (!finelista(p))
        return (p->leggicella());
}

template <class tipoelem> void Lista<tipoelem>::scrivilista(tipoelem e, posizione p)
{
    if (!finelista(p))
        p->scrivicella(e);
}

template <class tipoelem> void Lista<tipoelem>::inslista(tipoelem e, posizione& p)
{
    typename Lista<tipoelem>::posizione temp;

    temp = new Cella<tipoelem>;
    temp->scrivicella(e);
    temp->scrivisucc(p);
    temp->scriviprec(p->leggiprec());

    if(p == primolista())
        lista = temp;
    else
        p->leggiprec()->scrivisucc(temp);

    p->scriviprec(temp);

    p = temp;
}

template <class tipoelem> void Lista<tipoelem>::canclista(posizione &p)
{
    if (!finelista(p))
    {
        posizione temp=p;
        if (p==lista)
        {
            lista=p->leggisucc();
            p=lista;
        }
        else
        {
            p=p->leggisucc();
            (preclista(temp))->scrivisucc(p);

        }
        delete(temp);
        lungh--;
    }
}

//MODIFICA D-R(D-R) //
template <class tipoelem> Cella<tipoelem>* Lista<tipoelem>::get_posizione()const
{
    return lista;
}

// sovraccarico

template <class tipoelem> void Lista<tipoelem>::operator =(const Lista<tipoelem>& l)   //sovraccarico operatore di assegnamento
{
    if (this!=&l) //non posso assegnare per esempio A=A;
    {
        svuota();  //svuoto
        posizione ind=primolista();
        posizione ind2=l.primolista();
        while (!l.finelista(ind2))
        {
//            inslista(ind,l.leggilista(ind2)); //e inserisco in essa tutti gli elementi di l
            ind=succlista(ind);
            ind2=l.succlista(ind2);
        }
    }
}

template <class tipoelem> bool Lista<tipoelem>::operator ==(Lista<tipoelem>& l)  //sovraccarico operatore di uguaglianza
{
    bool uguali=lunghezza()==l.lunghezza();  //vedo le lunghezze delle liste
    if (uguali) //se le liste hanno la stessa lunghezza
    {
        posizione ind=primolista();      //---+
        //   +-------- mi posiziono all'inizio di entrambe le liste
        posizione ind2=l.primolista();     //-+
        while (!finelista(ind) && uguali)  // mentre non ho finito le liste e tutti i rispettivi caratteri delle lista sono uguali
        {
            uguali=(uguali && (leggilista(ind)==l.leggilista(ind2)));  //uguali sarà dato dal valore precedente di uguali AND il risultato del confronto dei simboli correnti
            ind=succlista(ind);                                        //se almeno uno dei caratteri è diverso avrà valore false
            ind2=l.succlista(ind2);
        }
    }
    return (uguali);
}

template<class tipoelem> ostream& operator<<(ostream& os, const Lista<tipoelem>& l) //sovraccarico output
{
    Cella<tipoelem>* ind=l.primolista();
    while (!l.finelista(ind))
    {
        os<< l.leggilista(ind);
        ind=l.succlista(ind);
        if (!l.finelista(ind))
            os<<",";
    }
    return(os);
}

// operatori ausiliari

template <class tipoelem> void Lista<tipoelem>::svuota() //svuota la lista
{
    posizione indice=primolista();
    while (!listavuota())
    {
        canclista(indice);  //mentre la lista non è vuota cancella il primo elemento
    }
}

template <class tipoelem> unsigned int Lista<tipoelem>::lunghezza() //restituisce la lunghezza della lista
{
    return(lungh);
}

// inizio modifica Zagaria -- aggiunto corpo funzione stampalista

template <class tipoelem> void Lista<tipoelem>::stampaLista ()
{
    posizione p;

    p = primolista();
    while (!finelista(p))
    {
        cout<<leggilista(p);
        p = succlista(p);
    }
}

// fine modifiche zagaria

#endif

