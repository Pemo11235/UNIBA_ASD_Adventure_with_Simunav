/*
Realizzazione: Lista con Vettore
Modificata da A.Annese
*/
#ifndef _LISTA_H
#define _LISTA_H

template <class T>
class Lista{
public:
	typedef int posizione;
	typedef T tipoelem;

	Lista ();
	~Lista ();
	void crealista ();
	bool listavuota () const;
	tipoelem leggilista (posizione)const;
	void scrivilista (tipoelem,posizione &);
	posizione primolista () const;
	bool finelista (posizione)const;
	posizione succlista (posizione)const;
	posizione preclista (posizione)const;
	void inslista (tipoelem,posizione &);
	void canclista (posizione &);

private:
	static const int max = 1024;
	T * elementi;
	int lunghezza;
};

template <class T>
Lista <T>::Lista()
{
	crealista();
}

template <class T>
Lista <T>::~Lista()
{
    lunghezza = 0;
    delete elementi;
}

template <class T>
void Lista <T>::crealista()
{
	lunghezza = 0;
    elementi = new T[max];
}

template <class T>
bool Lista <T>::listavuota() const
{
	return (lunghezza == 0);
}

template <class T>
typename Lista <T>::posizione Lista <T>::primolista() const
{
	return 0;
}

template <class T>
typename Lista <T>::posizione Lista <T>::succlista(posizione p)const
{
	if (0 <= p && p < lunghezza)
		return (p + 1);
	else
		return p;
}

template <class T>
typename Lista <T>::posizione Lista <T>::preclista(posizione p)const
{
	if (0 < p && p < lunghezza)
		return (p - 1);
	else
		return p;
}

template <class T>
bool Lista <T>::finelista(posizione p) const
{
	if (0 <= p && p <= lunghezza)
		return (p == lunghezza);
	else
		return false;
}

template <class T>
T Lista <T>::leggilista(posizione p)const
{
	return elementi[p];
}

template <class T>
void Lista <T>::scrivilista(tipoelem a, posizione & p)
{
	elementi[p] = a;
}

template <class T>
void Lista <T>::inslista(tipoelem a, posizione & p)
{
	for(int i = lunghezza; i > p; i--)
        elementi[i] = elementi[i-1];
	elementi[p] = a;
	lunghezza++;
}

template <class T>
void Lista <T>::canclista(posizione & p)
{
    for(int i=p; i < (lunghezza-1); i++)
        elementi[i] = elementi[i+1];
    lunghezza--;
}

#endif // _LISTA_H
