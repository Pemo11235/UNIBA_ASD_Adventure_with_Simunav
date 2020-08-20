/*
    Coda.h

    Created by: Mirco Sternativo 
	Edited by:  Matteo Luceri

    Date: 16-Mar-2015 // 30-Oct-2019
*/

#ifndef _CODA_H
#define _CODA_H

#include "Cella.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template<class tipoelem>
class Coda{

    public:
        

        //COSTRUTTORE E DISTRUTTORE ------------------------------------------------------------------
        Coda();                         //costruttore coda
        Coda(Coda&);                    //costruttore di copia
        ~Coda();                        //distruttore coda

        //OPERATORI ----------------------------------------------------------------------------------
        void creacoda();
        bool codavuota() const;
        tipoelem leggicoda() const;
        void incoda(tipoelem);
        void fuoricoda();
		//NUOVI METODI
        void inverti_coda();
        void svuota();

    private:
		//DEFINIZIONE DEI TIPI ----------------------------------------------------------------------- 
        typedef Cella<tipoelem>* posizione;
        //VARIABILI ----------------------------------------------------------------------------------
        posizione testa;
        posizione fondo;


};




//IMPLEMENTAZIONI COSTRUTTORE E DISTRUTTORE ----------------------------------------------------------
template<class tipoelem> 
Coda<tipoelem>::Coda(){
    creacoda();
}


template<class tipoelem> 
Coda<tipoelem>::Coda(Coda<tipoelem>& c){
    //N.B.: questo costruttore effettua una copia o clone di un oggetto
    creacoda();
    tipoelem temp;
    Coda<tipoelem> comodo;
	
    while (!c.codavuota()){
        comodo.incoda(c.leggicoda());
        //copio gli elementi di c in una coda d'appoggio
        c.fuoricoda();                          //distruzione della coda
    }

    while (!comodo.codavuota()){
        temp=comodo.leggicoda();
        comodo.fuoricoda();
        incoda(temp);
        //copia degli elementi della coda d'appoggio nella nuova coda
        c.incoda(temp);
        //e ripristino c
    }
}


template<class tipoelem> 
Coda<tipoelem>::~Coda(){
    while (!codavuota())
    {
        fuoricoda();
        //eliminazione elementi coda
    }
    delete fondo;
	//eliminazione riferimenti per inizio e fine coda
    delete testa;
}



//IMPLEMENTAZIONI OPERATORI --------------------------------------------------------------------------
template<class tipoelem> 
void Coda<tipoelem>::creacoda(){
    testa=nullptr;
    fondo=nullptr;
}


template<class tipoelem> 
bool Coda<tipoelem>::codavuota() const{
    return ((testa==nullptr));
    //controllo esistenza coda tramite verifica puntatori inizio e fine
}


template<class tipoelem> 
tipoelem Coda<tipoelem>::leggicoda() const {
    if (!codavuota())
        //precondizione coda non vuota
        return (testa->leggicella());
    //lettura elemento in testa
}


template<class tipoelem> 
void Coda<tipoelem>::incoda(tipoelem a){
    posizione temp=new Cella<tipoelem>;
    //creazione nuovo elemento temp
    temp->scrivicella(a);
    //valorizzazione di temp
    temp->scrivisucc(nullptr);

    if (!codavuota())
        fondo->scrivisucc(temp);
		fondo=temp;
        //se la coda non è vuota, l'elemento successivo è temp
    else
        testa=temp;
		fondo=temp;
        //altrimenti sta alla testa

}


template<class tipoelem> 
void Coda<tipoelem>::fuoricoda(){
    if (!codavuota()){
    //precondizione coda non vuota
        
		posizione temp=testa;
		//puntatore all'elemento da eliminare
		
		testa=testa->leggisucc();
		delete temp;
		//eliminazione elemento in testa
}

// NUOVI METODI--------------------------------------------------------------------------------------
template<class tipoelem> 
void Coda<tipoelem>::inverti_coda(){
    tipoelem Elemento;

    if (!codavuota()){
        Elemento = leggicoda();
        fuoricoda();
        inverti_coda();
        incoda(Elemento);
    }
}


template<class C> 
void Coda<C>::svuota(){
    while (!codavuota()){
        fuoricoda();
    }
};

#endif // CODA_H
