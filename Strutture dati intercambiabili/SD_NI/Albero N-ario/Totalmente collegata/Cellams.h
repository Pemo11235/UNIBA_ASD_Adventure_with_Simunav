#ifndef CELLA_H
#define CELLA_H

#include <ctype.h>

//Cella (atomo) base per tutte le strutture

template<class T> class cella
{
public:
    typedef T tipoelem; //definizione di tipo

    cella(); //usa costruttore e distruttore di default

    tipoelem getelem(); //------+
    void setelem(tipoelem); //  +-\ setter e
    bool getvisita(); //        +-/ getter
    void setvisita(bool); //----+

private:
    tipoelem elem; //informazione
    bool visita; //visita della cella

    bool operator>(cella);
    bool operator<(cella);
};

template<class T> cella<T>::cella()
{
    visita = false;
}

template<class T> bool cella<T>::getvisita()
{
    return visita;
}

template<class T> void cella<T>::setvisita(bool b)
{
    visita = b;
}

template<class T> T cella<T>::getelem()
{
    return elem;
}

template<class T> void cella<T>::setelem(tipoelem t)
{
    elem = t;
}

template<class T> bool cella<T>::operator>(cella<T> c)
{
    return getelem > c.getelem();
}

template<class T> bool cella<T>::operator<(cella<T> c)
{
    return getelem < c.getelem();
}

#endif // CELLA_H
