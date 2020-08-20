#ifndef VALIGIA_H_
#define VALIGIA_H_
#include <iostream>
using namespace std;
#include "Lista.h"

template <class tipoelem>
class Valigia{
public:
	Valigia();											// Costruttore
	~Valigia();											// Distruttore
	void CreaInsieme();									// Crea un insieme vuoto
	bool InsiemeVuoto();								// Verifica se l'insieme è vuoto
	bool Appartiene(tipoelem);							// Verifica se l'elemento appartiene all'insieme
	void Inserisci(tipoelem);							// Inserisce un nuovo elemento nell'insieme
	void Cancella(tipoelem);							// Cancella l'elemento dall'insieme
	void StampaInsieme();
	Valigia<tipoelem> operator = (const Valigia<tipoelem>&);
private:
	Lista<tipoelem> insieme;
};

template <class tipoelem> Valigia<tipoelem>::Valigia(){
	CreaInsieme();
}

template <class tipoelem> Valigia<tipoelem>::~Valigia(){

}

template <class tipoelem> void Valigia<tipoelem>::CreaInsieme(){
	insieme.crealista();
}

template <class tipoelem> bool Valigia<tipoelem>::InsiemeVuoto(){
	return insieme.listavuota();
}

template <class tipoelem> bool Valigia<tipoelem>::Appartiene(tipoelem e){
	Cella<tipoelem>* indice = insieme.primolista();
	bool trovato = false;

	/* Scandice la lista e restituisce true se l'elemento è presente e false altrimenti */
	while(!trovato && !insieme.finelista(indice)){
		if(insieme.leggilista(indice) == e)
			trovato = true;
		else
			indice = insieme.succlista(indice);
	}
	return trovato;
}

template <class tipoelem> void Valigia<tipoelem>::Inserisci(tipoelem e){
	Cella<tipoelem>* indice = insieme.primolista();
	bool inserito = false;

	/* Se l'elemento non è già presente nell insieme lo inserisco */
	if(!Appartiene(e)){
		/* Scandisce la lista fino a trovare la posizione corretta in cui inserirlo*/
		while(!inserito && !insieme.finelista(indice)){
			if(e < insieme.leggilista(indice)){
				insieme.inslista(indice,e);
				inserito = true;
			}
			else
				indice = insieme.succlista(indice);
		}
		/* Se la lista è finita e il valore non è stato inserito allora lo inserisco come ultimo elemento */
		if(insieme.finelista(indice))
			insieme.inslista(indice,e);
	}
}

template <class tipoelem> void Valigia<tipoelem>::Cancella(tipoelem e){
	Cella<tipoelem>* indice = insieme.primolista();
	bool trovato = false;

	/* Scandisce la lista e se trova l'elemento lo cancella */
	while(!trovato && !insieme.finelista(indice)){
		if(insieme.leggilista(indice) == e){
			insieme.canclista(indice);
			trovato = true;
		}
		else
			indice = insieme.succlista(indice);
	}
}

template <class tipoelem> void Valigia<tipoelem>::StampaInsieme(){
	Cella<tipoelem>* indice;

	for(indice = insieme.primolista(); !insieme.finelista(indice); indice = insieme.succlista(indice))
		std::cout << insieme.leggilista(indice) << " ";
}

template <class tipoelem> Valigia<tipoelem> Valigia<tipoelem>::operator=(const Valigia<tipoelem> &i2){
	Cella<tipoelem>* indice=i2.insieme.primolista();

	if(!i2.insieme.listavuota())
	{
		do{
			indice=i2.insieme.succlista(indice);
			Inserisci(i2.insieme.leggilista(indice));
		}while(!i2.insieme.finelista(indice));
	}
	return *this;
}

#endif /* VALIGIA_H_ */
