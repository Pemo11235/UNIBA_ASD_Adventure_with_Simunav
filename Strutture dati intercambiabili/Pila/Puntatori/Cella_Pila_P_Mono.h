#ifndef _CELLA_PILA_P_MONO_H_INCLUDED
#define _CELLA_PILA_P_MONO_H_INCLUDED

template<class T> class Cella_Pila_P_Mono
{
public:
    typedef T tipoelem;
    Cella_Pila_P_Mono();
    tipoelem leggiCella() const;
    void scriviCella(tipoelem);
    Cella_Pila_P_Mono<T>* leggiSucc()const;
    void scriviSucc(Cella_Pila_P_Mono<T>*);
private:
    tipoelem elemento;
    Cella_Pila_P_Mono<T>* suc;
};

template<class T>
Cella_Pila_P_Mono<T>::Cella_Pila_P_Mono()
{suc=nullptr;
}

template<class T>
T Cella_Pila_P_Mono<T>::leggiCella()const
{
    return elemento;
}
template<class T>
void Cella_Pila_P_Mono<T>::scriviCella(tipoelem e)
{
    elemento=e;
}
template<class T>
Cella_Pila_P_Mono<T>* Cella_Pila_P_Mono<T>::leggiSucc()const
{
    return suc;
}
template <class T>
void Cella_Pila_P_Mono<T>::scriviSucc(Cella_Pila_P_Mono<T>* c)
{
    suc=c;
}


#endif // _CELLA_PILA_P_MONO_H_INCLUDED
