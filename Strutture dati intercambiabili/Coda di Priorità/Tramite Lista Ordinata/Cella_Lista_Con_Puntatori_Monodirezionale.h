/*
Realizzazione: 	Cella per Lista con Puntatori Monodirezionale
Modificato da:	Matteo Luceri
Autore 	     :	Sconosciuto
*/

#ifndef CELLA_LISTA_CON_PUNTATORI_MONODIREZIONALE_H_
#define CELLA_LISTA_CON_PUNTATORI_MONODIREZIONALE_H_

template<class T>
class Cella_LP_Mono
{
public:
	typedef T tipoelem;
    Cella_LP_Mono();
	~Cella_LP_Mono();

    void scriviCella(tipoelem);
    tipoelem leggiCella() const;
    void scriviSucc(Cella_LP_Mono<T>*);
    Cella_LP_Mono<T>* leggiSucc() const;

private:
    tipoelem elemento;
    Cella_LP_Mono<T>* succ;
};

template<class T>
Cella_LP_Mono<T>::Cella_LP_Mono()
{
	succ = nullptr;
}

template<class T>
Cella_LP_Mono<T>::~Cella_LP_Mono()
{
    //dtor
}

template<class T>
void Cella_LP_Mono<T>::scriviCella(tipoelem label)
{
    elemento = label;
}

template<class T>
T Cella_LP_Mono<T>::leggiCella() const
{
    return elemento;
}


template<class T>
void Cella_LP_Mono<T>::scriviSucc(Cella_LP_Mono<T>* c)
{
    succ = c;
}

template<class T>
Cella_LP_Mono<T>* Cella_LP_Mono<T>::leggiSucc() const
{
    return succ;
}



#endif /* CELLA_LISTA_CON_PUNTATORI_MONODIREZIONALE_H_ */
