#ifndef CELLA_CODA_H_INCLUDED
#define CELLA_CODA_H_INCLUDED

template<class T>
class Cella
{
public:
    typedef T tipoelem;
    Cella();
    ~Cella();
    Cella<T>* getSucc() const;
    void setSucc(Cella<T>*);
    tipoelem getElemento() const;
    void setElemento(tipoelem );
private:
    Cella<T>* succ;
    tipoelem elemento;
};
template <class T>
Cella<T>::Cella()
{
    succ = 0;
}
template <class T>
Cella<T>::~Cella()
{
    succ = 0;
}
template <class T>
Cella<T>* Cella<T>::getSucc() const
{
    return succ;
}
template <class T>
void Cella<T>::setSucc(Cella<T>* t)
{
    succ = t;
}
template <class T>
typename Cella<T>::tipoelem Cella<T>::getElemento() const
{
    return elemento;
}
template <class T>
void Cella<T>::setElemento(tipoelem e)
{
    elemento = e;
}
#endif // CELLA_CODA_H_INCLUDED
