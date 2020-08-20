/*
Funzioni di servizio per la struttura dati Lista
Inserite da A.Annese per rendere intercambiabili le realizzazioni della Lista
*/
#ifndef SERVIZIOLISTA_H
#define SERVIZIOLISTA_H

#include "Lista.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace check_pointers
{
	template<class T>
	struct is_pointer { static const bool value = false; };
	template<class T>
	struct is_pointer<T*> { static const bool value = true; };
}

template <class T>
typename Lista<T>::posizione posizioneInvalida(const Lista<T>& l)
{
	typename Lista<T>::posizione returnVal = l.primolista();
	if(check_pointers::is_pointer<typename Lista<T>::posizione>::value)
		returnVal = 0;
	else while(!l.finelista(returnVal))
		returnVal = l.succlista(returnVal);

	return returnVal;
}

template <class T>
bool posizioneValida(const Lista<T>& l, typename Lista<T>::posizione posizione)
{
	bool valid = false;
	if(!l.listavuota())
	{
		typename Lista<T>::posizione p = l.primolista();
		if(l.finelista(posizione))
			valid = true;
		else while(!l.finelista(p) && !valid)
		{
			if(p == posizione)
				valid = true;
			p = l.succlista(p);
		}
	}

	return valid;
}

template <class T>
int posizioneLogicaDaPosizioneFisica(const Lista<T>& l, typename Lista<T>::posizione p)
{
	if(posizioneValida(l, p))
	{
		int pos = 0;
		typename Lista<T>::posizione p1 = l.primolista();
		while(p1 != p)
		{
			++pos;
			p1 = l.succlista(p1);
		}

		return pos;
	}
	else
		return -1;
}

template <class T>
typename Lista<T>::posizione posizioneFisicaDaLogica(const Lista<T>& l, int posizione)
{
	if(posizione != -1)
	{
		typename Lista<T>::posizione p = l.primolista();
		for(int i = 0; i < posizione; i++)
			p = l.succlista(p);
		return p;
	}
	else
		return posizioneInvalida(l);

}

template <class T>
void svuotaLista(Lista<T>& l)
{
	if(!l.listavuota())
	{
		typename Lista<T>::posizione p = l.primolista();
		while(!l.finelista(p))
            l.canclista(p);
	}
}

template <class T>
void copiaLista(Lista<T> &a, const Lista<T> &b)
{
    if (&a!=&b)
    {
        svuotaLista(a);
        typename Lista<T>::posizione ind = a.primolista(),ind2 = b.primolista();
        while (!b.finelista(ind2))
        {
            a.inslista(b.leggilista(ind2),ind);
            ind = a.succlista(ind);
            ind2 = b.succlista(ind2);
        }
    }
}

template <class T>
void stampaLista(Lista<T> &l)
{
    cout << "[ ";
    typename Lista<T>::posizione riferimento;
    riferimento = l.primolista();
    while(!l.finelista(riferimento))
    {
        cout << l.leggilista(riferimento);
        if(!l.finelista(l.succlista(riferimento)))
            cout << ", ";

        riferimento = l.succlista(riferimento);
    }
    cout << "]\n";
}

#endif // SERVIZIOLISTA_H
