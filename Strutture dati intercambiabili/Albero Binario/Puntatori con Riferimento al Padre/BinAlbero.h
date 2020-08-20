/** \file AlberoBin.h
 *
 * \brief Albero binario TOP DOWN. Implementazione tramite puntatori
 * \author Andrea Esposito
 */


#ifndef ALBEROBIN_H
#define ALBEROBIN_H

template <class T>
class BinAlbero
{
private:
	typedef struct Cella
	{
		Cella* genitore;
		Cella* sinistro;
		Cella* destro;
		T valore;
	} Cella;

public:
	typedef Cella* Nodo;
	static constexpr Nodo NODO_NULLO = nullptr;

	BinAlbero();
	~BinAlbero();

	void creabinalbero();
	bool binalberovuoto()const;
	Nodo binradice()const;
	Nodo padre(Nodo)const;
	Nodo figliosinistro(Nodo)const;
	Nodo figliodestro(Nodo)const;
	bool sinistrovuoto(Nodo)const;
	bool destrovuoto(Nodo)const;
	void cancsottobinalbero(Nodo);
	void insbinradice();
	void insfigliosinistro(Nodo);
	void insfigliodestro(Nodo);

	T legginodo(Nodo)const;
	void scrivinodo(Nodo, T);

private:
	Nodo inizio;
};

template <class T>
BinAlbero<T>::BinAlbero()
{
	creabinalbero();
}

template <class T>
BinAlbero<T>::~BinAlbero()
{
	if(inizio != nullptr)
		cancsottobinalbero(inizio);
}

template <class T>
void BinAlbero<T>::creabinalbero()
{
	inizio = nullptr;
}

template <class T>
bool BinAlbero<T>::binalberovuoto()const
{
    return inizio == nullptr;
}

template <class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binradice()const
{
    if(!binalberovuoto())
        return inizio;
    else
        return nullptr;
}

template <class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::padre(Nodo n)const
{
    return n->genitore;
}

template <class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figliosinistro(Nodo n)const
{
    return n->sinistro;
}

template <class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figliodestro(Nodo n)const
{
    return n->destro;
}

template <class T>
bool BinAlbero<T>::sinistrovuoto(Nodo n)const
{
    return n->sinistro == nullptr;
}

template <class T>
bool BinAlbero<T>::destrovuoto(Nodo n)const
{
    return n->destro == nullptr;
}

template <class T>
void BinAlbero<T>::insbinradice()
{
    if(inizio == nullptr)
    {
        inizio = new Cella;
        inizio->sinistro = nullptr;
        inizio->destro = nullptr;
        inizio->genitore = nullptr;
    }
}

template <class T>
void BinAlbero<T>::insfigliosinistro(BinAlbero<T>::Nodo n)
{
    Nodo q = new Cella;
    n->sinistro = q;
    q->genitore = n;
    q->sinistro = nullptr;
    q->destro = nullptr;
}

template <class T>
void BinAlbero<T>::insfigliodestro(Nodo n)
{
    Nodo q = new Cella;
    n->destro = q;
    q->genitore = n;
    q->sinistro = nullptr;
    q->destro = nullptr;
}


template <class T>
void BinAlbero<T>::cancsottobinalbero(BinAlbero<T>::Nodo n)
{
    if(!sinistrovuoto(n))
        cancsottobinalbero(n->sinistro);
    if(!destrovuoto(n))
        cancsottobinalbero(n->destro);
    if(n != inizio)
    {
        Nodo p = padre(n);
        if(p->sinistro == n)
            p->sinistro = nullptr;
        else
            p->destro = nullptr;
    }
    else
	{
        inizio = nullptr;
	}

    delete n;
}

template <class T>
T BinAlbero<T>::legginodo(Nodo n)const
{
    return n->valore;
}

template <class T>
void BinAlbero<T>::scrivinodo(Nodo n,T a)
{
    n->valore = a;
}

#endif
