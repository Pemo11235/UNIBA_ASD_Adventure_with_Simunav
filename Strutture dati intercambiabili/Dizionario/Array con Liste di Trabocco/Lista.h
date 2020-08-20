#ifndef _LISTA_V_H
#define _LISTA_V_H

#include <iostream>
using namespace std;

template <class T>
class Lista
{
private:
	static const int max = 1024;
public:
	typedef int posizione;
	typedef T tipoelem;

	Lista(); //costruttore
	Lista(const Lista<T>&); //costruttore di copia
	~Lista(); //distruttore
	//operatori
	void crealista ();
	bool listavuota () const;
	tipoelem leggilista (posizione)const;
	void scrivilista (tipoelem,posizione);
	posizione primolista () const;
	bool finelista (posizione)const;
	posizione succlista (posizione)const;
	posizione preclista (posizione)const;
	void inslista (tipoelem,posizione);
	void canclista (posizione);

private:
	T elementi [max];
	int lunghezza;
};

	//costruttore
template <class T> Lista<T>::Lista()
{
		crealista ();
}

	//costruttore di copia:effettua una copia o clone di un oggetto
template <class T> Lista<T>::Lista(const Lista<T>&L)
{
		lunghezza=L.lunghezza;
		for (int i=0;i<lunghezza;i++)
			elementi [i]=L.elementi[i];
}

	//distruttore
template <class T> Lista<T>::~Lista() {}

	//operatori
	template <class T> void Lista<T>::crealista () {
		lunghezza=0;
	}

	template <class T> bool Lista<T>::listavuota () const {
		return (lunghezza==0);
	}

	template <class T> int Lista<T>::primolista () const {
		return (1);
	}

	template <class T> int Lista<T>::succlista (posizione p)const {
		if ((p >0) && (p<lunghezza+1))
			return (p+1);
		else return (p);
	}

	template <class T> int Lista<T>::preclista (posizione p)const {
		if ((p>0) && (p<lunghezza+1))
			return (p-1);
		else return (p);
	}

	template <class T> bool Lista<T>::finelista (posizione p) const {
		if ((p>0)&&(p<=lunghezza+1))
			return (p==lunghezza+1);
		else return (false);
	}

	template <class T> T Lista<T>::leggilista (posizione p)const {
		if ((p>0)&& (p<lunghezza+1))
			return (elementi [p-1]);
	}

	template <class T> void Lista<T>::scrivilista (tipoelem a, posizione p){
		if ((p>0)&& (p<lunghezza +1))
			elementi [p-1]=a;
	}

	template <class T> void Lista<T>::inslista (tipoelem a, posizione p){
		if ((p>0)&& (p<=lunghezza+1))
			for (int i=lunghezza;i>=p;i--)
				elementi [i]=elementi [i-1];
		elementi [p-1]=a;
		lunghezza++;
	}

	template <class T> void Lista<T>::canclista (posizione p){
		if ((p>0)&&(p<lunghezza+1))
			if (!listavuota()){
				for (int i=p-1;i<(lunghezza+1);i++)
					elementi [i]=elementi [i+1];
				lunghezza--;
			}
	}






#endif // _LISTA_V_H

