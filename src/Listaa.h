#ifndef LISTAA_H_INCLUDED
#define LISTAA_H_INCLUDED

#include <assert.h>
#include "Cellaa.h"


template<class T> class Listaa {
	public:
		typedef typename Cellaa<T>::posizione posizione;
		typedef typename Cellaa<T>::tipoelem tipoelem;
		Listaa();
		void crealista();
		bool listavuota()const;
		bool finelista(posizione)const;
		posizione primolista()const;
		posizione succlista(posizione)const;
		posizione predlista(posizione)const;
		void canclista(posizione&);
		void inslista(tipoelem, posizione&);
		void scrivilista(tipoelem,posizione);
		tipoelem leggilista(posizione)const;
	private:
		posizione pos;

};

template<class T> Listaa<T>::Listaa() {
	Listaa::crealista();
}

template<class T> void Listaa<T>::crealista(){
	tipoelem e;
	pos = new Cellaa<T>;
	pos->scriviCella(e);
	pos->setsucc(pos);
}

template<class T> bool Listaa<T>::listavuota()const{
	return(pos->getsucc()==pos);
}

template<class T> bool Listaa<T>::finelista(posizione p)const{
	return(p==pos);
}

template<class T> typename Listaa<T>::posizione Listaa<T>::primolista()const{
	return pos->getsucc();
}

template<class T> typename Listaa<T>::posizione Listaa<T>::succlista(posizione p)const{
	assert(!listavuota());{
		return(p->getsucc());
	}
}

template<class T> typename Listaa<T>::posizione Listaa<T>::predlista(posizione p)const{
	assert(!(primolista()==p) && !listavuota());{
		posizione i=primolista();
		while(!(i->getsucc()==p)){
			i= succlista(i);
		}
		return i;
	}
}

template<class T> void Listaa<T>::canclista(posizione &p){
	assert(!listavuota());{
		posizione i=primolista();
		while(!(i->getsucc()==p)){
			i= succlista(i);
		}
		posizione temp = new Cellaa<T>;
		temp = p;
		i->setsucc(p->getsucc());
		p=temp->getsucc();
		delete temp;
	}
}

template<class T> void Listaa<T>::inslista(tipoelem e, posizione &p){
	posizione temp = new Cellaa<T>;
	posizione i = primolista();
	temp->scriviCella(e);
	while(!(i->getsucc()==p)){
		i= succlista(i);
	}
	i->setsucc(temp);
	temp->setsucc(p);
	p=temp;
}

template<class T> void Listaa<T>::scrivilista(tipoelem e, posizione p){
	assert(!listavuota());{
		p->scriviCella(e);
	}
}

template<class T> typename Listaa<T>::tipoelem Listaa<T>::leggilista(posizione p)const{
	assert(!listavuota());{
		return(p->leggiCella());
	}
}


#endif // LISTAA_H_INCLUDED
