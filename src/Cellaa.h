#ifndef CELLAA_H_INCLUDED
#define CELLAA_H_INCLUDED

template<class T> class Cellaa{
	public:
    typedef T tipoelem;
    typedef Cellaa<T>* posizione;
	Cellaa();
	tipoelem leggiCella() const;
	void scriviCella(tipoelem);
	posizione getsucc()const;
	void setsucc(posizione);
	bool operator == (Cellaa);
private:
	tipoelem etichetta;
	posizione suc;
};

template<class T> Cellaa<T>::Cellaa(){}

template<class T> typename Cellaa<T>::tipoelem Cellaa<T>::leggiCella()const{
	return etichetta;
}
template<class T> void Cellaa<T>::scriviCella(tipoelem e){
	etichetta=e;
}
template<class T> typename Cellaa<T>::posizione Cellaa<T>::getsucc()const{
	return suc;
}
template <class T> void Cellaa<T>::setsucc(posizione c){
	suc=c;
}

template <class T> bool Cellaa<T>::operator ==(Cellaa cella){
	return(leggiCella()==cella.leggiCella());
}


#endif // CELLAA_H_INCLUDED
