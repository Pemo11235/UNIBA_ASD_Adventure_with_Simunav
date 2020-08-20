/*
Realizzazione: Lista con Puntatori Monodirezionale
Modificata da A.Annese
Nota Bene: Il costruttore di copia e' stato implementato in quanto
           NECESSARIO per via di alcuni file del progetto in cui
           vengono passate liste come parametri di funzioni e
           restituite (dalle stesse) non per riferimento.
*/
#ifndef LISTA_H_
#define LISTA_H_
#include "Cella_Lista_P_Mono.h"

template<class L>
class Lista
{
public:
    typedef Cella_LP_Mono<L>* posizione;
    typedef L tipoelem;

    Lista();
	Lista(const Lista&);
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
    void canclista(posizione &);

private:
    posizione lista;
};


template <class L>
Lista<L>::Lista()
{
    crealista();
}

template <class L>
Lista<L>::Lista(const Lista& b)
{
    crealista();
    typename Lista<L>::posizione ind = primolista(),ind2 = b.primolista();
    while (!b.finelista(ind2))
    {
        inslista(b.leggilista(ind2),ind);
        ind = succlista(ind);
        ind2 = b.succlista(ind2);
    }
}

template <class L>
Lista<L>::~Lista()
{
    posizione p = primolista();
    while(p->leggiSucc() != nullptr)
    {
        posizione temp = p;
        p=p->leggiSucc();
        delete temp;
    }
}

template <class L>
void Lista<L>::crealista()
{
    lista = new Cella_LP_Mono<L>;
    lista->scriviSucc(nullptr);
}

template <class L>
bool Lista<L>::listavuota() const
{
    return (lista->leggiSucc() == nullptr);
}

template <class L>
bool Lista<L>::finelista(posizione pos) const
{
    return (pos->leggiSucc() == nullptr);
}

template <class L>
typename Lista<L>::posizione Lista<L>::primolista() const
{
    return lista;
}

template <class L>
typename Lista<L>::posizione Lista<L>::succlista(posizione pos) const
{
    if (lista->leggiSucc() != nullptr)
        return (pos->leggiSucc());
    else
        return pos;
}

template <class L>
typename Lista<L>::posizione Lista<L>::preclista(posizione pos) const
{
    typename Lista<L>::posizione temp = primolista();
    if(pos == temp)
        temp = nullptr;
    else
    {
        while(succlista(temp) != pos)
            temp = succlista(temp);
    }
    return temp;
}

template <class L>
L Lista<L>::leggilista(posizione pos) const
{
    return (pos->leggiCella());
}

template <class L>
void Lista<L>::scrivilista(tipoelem elem, posizione pos)
{
    pos->scriviCella(elem);
}

template <class L>
void Lista<L>::inslista(tipoelem elem, posizione &pos)
{
    typename Lista<L>::posizione temp;
    temp = new Cella_LP_Mono<L>;
    temp->scriviCella(elem);
    temp->scriviSucc(pos);

    if (pos == primolista())
        lista = temp;
    else
        preclista(pos)->scriviSucc(temp);
    pos = temp;
}

template <class L>
void Lista<L>::canclista(posizione & pos)
{
    typename Lista<L>::posizione temp = pos;

    if(pos != lista)
        preclista(pos)->scriviSucc(pos->leggiSucc());
    else
        lista = pos->leggiSucc();

    pos = pos->leggiSucc();
    delete temp;
}

#endif // LISTA_H_
