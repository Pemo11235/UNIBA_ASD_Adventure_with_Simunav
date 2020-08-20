/*
Realizzazione: Lista con Puntatori Circolare (Simmetrica)
Modificata da A.Annese
Nota Bene: Il costruttore di copia e' stato implementato in quanto
           NECESSARIO per via di alcuni file del progetto in cui
           vengono passate liste come parametri di funzioni e
           restituite (dalle stesse) non per riferimento.
*/
#ifndef LISTA_H_
#define LISTA_H_
#include "Cella_Lista_Circolare.h"

template<class T>
class Lista
{
public:
	typedef Cella_L_Circ<T>* posizione;
    typedef T tipoelem;
    
	Lista();
	Lista(const Lista&);
    ~Lista();

    void crealista();
    bool listavuota() const;
    tipoelem leggilista(posizione) const;
    void scrivilista(tipoelem, posizione);
    posizione primolista() const;
    bool finelista(posizione) const;
    posizione succlista(posizione) const;
    posizione preclista(posizione) const;
    void inslista(tipoelem, posizione &);
    void canclista(posizione &);

private:
    posizione lista;
};

template<class T>
Lista<T>::Lista()
{
    crealista();
}

template <class T>
Lista<T>::Lista(const Lista& b)
{
    crealista();
    typename Lista<T>::posizione ind = primolista(),ind2 = b.primolista();
    while (!b.finelista(ind2))
    {
        inslista(b.leggilista(ind2),ind);
        ind = succlista(ind);
        ind2 = b.succlista(ind2);
    }
}

template<class T>
Lista<T>::~Lista()
{
    typename Lista<T>::posizione temp;
    temp = primolista();
    while(!finelista(temp))
        canclista(temp);
}

template<class T>
void Lista<T>::crealista()
{
    lista = new Cella_L_Circ<T>;
    lista->scrivicella(T());
    lista->scrivisucc(lista);
}

template<class T>
bool Lista<T>::listavuota() const
{
    return (lista->leggisucc() == lista);
}

template<class T>
typename Lista<T>::posizione Lista<T>::primolista() const
{
    return lista->leggisucc();
}

template<class T>
typename Lista<T>::posizione Lista<T>::succlista(posizione p) const
{
    return p->leggisucc();
}

template<class T>
typename Lista<T>::posizione Lista<T>::preclista(posizione p) const
{
    typename Lista<T>::posizione temp;
    temp = primolista();
    if(temp != p)
    {
        while(succlista(temp) != p || succlista(temp) == nullptr)
            temp = succlista(temp);
        return temp;
    }
    else
        temp = lista;

    return temp;
}

template<class T>
bool Lista<T>::finelista(posizione p) const
{
    return (p == lista);
}

template<class T>
T Lista<T>::leggilista(posizione p) const
{
    return p->leggicella();
}

template<class T>
void Lista<T>::scrivilista(tipoelem a, posizione p)
{
    p->scrivicella(a);
}

template<class T>
void Lista<T>::inslista(tipoelem a,posizione & p)
{
    typename Lista<T>::posizione temp;
    temp = new Cella_L_Circ<T>;
    temp->scrivicella(a);
    temp->scrivisucc(p);
    preclista(p)->scrivisucc(temp);
    p = temp;
}

template<class T>
void Lista<T>::canclista(posizione & p)
{
    typename Lista<T>::posizione temp;
    temp = p;
    preclista(p)->scrivisucc(p->leggisucc());
    p = p->leggisucc();
    delete (temp);
}

#endif // LISTA_H_
