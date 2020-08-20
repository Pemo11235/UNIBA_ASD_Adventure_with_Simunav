/*
Realizzazione: Lista con Puntatori Doppi
Autore: A. Annese
Nota Bene: Il costruttore di copia e' stato implementato in quanto
           NECESSARIO per via di alcuni file del progetto in cui
           vengono passate liste come parametri di funzioni e
           restituite (dalle stesse) non per riferimento.
*/
#ifndef LISTA_H_
#define LISTA_H_

#include "Cella_L_DP.h"

template <class tipoelem>
class Lista{
public:
    typedef Cella_L_DP<tipoelem>* posizione;

    Lista();
    Lista(const Lista&);
    ~Lista();

    void crealista();

    bool listavuota() const;
    posizione primolista() const;
    posizione succlista(posizione) const;
    posizione preclista(posizione) const;
    bool finelista(posizione) const;

    tipoelem leggilista(posizione) const;

    void inslista(tipoelem, posizione&);
    void scrivilista(tipoelem, posizione);
    void canclista(posizione&);

private:
    posizione lista;
};

template <class tipoelem>
Lista<tipoelem>::Lista()
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

template <class tipoelem>
Lista<tipoelem>::~Lista()
{
    posizione p = primolista();
    posizione temp;
    while(p->getSucc() != nullptr)
    {
        temp = p;
        p=p->getSucc();
        delete temp;
    }
}

template <class tipoelem>
void Lista<tipoelem>::crealista()
{
    lista = new Cella_L_DP<tipoelem>;
    lista->setSucc(nullptr);
    lista->setPrec(nullptr);
}

template <class tipoelem>
bool Lista<tipoelem>::listavuota() const
{
    return (lista->getSucc() == nullptr && lista->getPrec() == nullptr);
}

template <class tipoelem>
typename Lista<tipoelem>::posizione Lista<tipoelem>::primolista() const
{
    return lista;
}

template <class tipoelem>
typename Lista<tipoelem>::posizione Lista<tipoelem>::succlista(posizione p) const
{
    if(lista->getSucc() == nullptr)
        return p;
    else
        return p->getSucc();
}

template <class tipoelem>
typename Lista<tipoelem>::posizione Lista<tipoelem>::preclista(posizione p) const
{
    return p->getPrec();
}

template <class tipoelem>
bool Lista<tipoelem>::finelista(posizione p) const
{
    return (p->getSucc() == nullptr);
}


template <class tipoelem>
tipoelem Lista<tipoelem>::leggilista(posizione p) const
{
    return p->getElem();
}

template <class tipoelem>
void Lista<tipoelem>::scrivilista(tipoelem e, posizione p)
{
    p->setElem(e);
}

template <class tipoelem>
void Lista<tipoelem>::inslista(tipoelem e, posizione& p)
{
    typename Lista<tipoelem>::posizione temp;

    temp = new Cella_L_DP<tipoelem>;
    temp->setElem(e);
    temp->setSucc(p);
    temp->setPrec(p->getPrec());

    if(p == primolista())
        lista = temp;
    else
        p->getPrec()->setSucc(temp);

    p->setPrec(temp);

    p = temp;
}


template <class tipoelem>
void Lista<tipoelem>::canclista(posizione& p)
{
    posizione temp;
    temp = p;
    if(p == primolista())
    {
        if(p->getSucc() != nullptr)
        {
            lista = p->getSucc();
            lista->setPrec(nullptr);
        }
    }
    else
    {
        preclista(p)->setSucc(p->getSucc());
        succlista(p)->setPrec(preclista(p));
    }

    p = p->getSucc();
    delete temp;
}


#endif //LISTA_H_
