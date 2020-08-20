/*
 * Bagagliaio.cpp
 *
 *  Created on: 07/set/2015
 *      Author: Luca Carlucci
 */

#include "Bagagliaio.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Bagagliaio::Bagagliaio(){
	for(int indice =0; indice<DIMMAX; indice=indice+1)
		bagagli[indice].presente = false;
	num_bagagli = 0;
}

Bagagliaio::~Bagagliaio(){

}

bool Bagagliaio::bagagliaioVuoto(){
	return(num_bagagli==0);
}

bool Bagagliaio::bagagliaioPieno(){
	return(num_bagagli==DIMMAX);
}

void Bagagliaio::depositaBagaglio(Oggetto ogg){
	int posizione = cercaScompartoLibero();
	if(posizione != -DIMMAX){
		bagagli[posizione].oggetto = ogg;
		bagagli[posizione].presente = true;
		num_bagagli++;
	}
}

void Bagagliaio::rimuoviBagaglio(Oggetto ogg){
	if(!bagagliaioVuoto()){
		int posizione = cercaBagaglio(ogg);
		if(posizione != -DIMMAX){
			bagagli[posizione].presente = false;
			num_bagagli--;
		}
	}
}

Oggetto Bagagliaio::vediBagaglio(Oggetto ogg){
	if(!bagagliaioVuoto()){
		int posizione = cercaBagaglio(ogg);
		if(posizione != -DIMMAX)
			return bagagli[posizione].oggetto;
	}
}

Oggetto Bagagliaio::estraiBagaglio(){
	if(!bagagliaioVuoto()){
		bool estratto = false;
		for(int indice = 0; ((indice<DIMMAX)&&(!estratto)); indice=indice+1){
			if(bagagli[indice].presente){
				estratto = true;
				bagagli[indice].presente = false;
				num_bagagli--;
				return bagagli[indice].oggetto;
			}
		}
	}
}

int Bagagliaio::cercaBagaglio(Oggetto ogg){
	bool trovato = false;
	int indice;
	for(indice = 0; ((indice<DIMMAX) && (!trovato)); indice=indice+1){
		if(bagagli[indice].presente){
			if(bagagli[indice].oggetto.get_codice()==ogg.get_codice())
				trovato = true;
		}
	}
	if(trovato)
		return indice-1;
	else
		return -DIMMAX;
}

void Bagagliaio::vediBagagli(){
	if(!bagagliaioVuoto()){
		cout << num_bagagli << " scomparto/i occupato/i su " << DIMMAX << endl;
		for(int indice = 0; indice<DIMMAX; indice=indice+1){
			if(bagagli[indice].presente)
				cout << "Lo scomparto " << indice+1 << " contiene: " << bagagli[indice].oggetto.get_nome() << endl;
		}
	}
	else
		cout << "Il bagagliaio e' vuoto" << endl;
}

int Bagagliaio::cercaScompartoLibero(){
	if(!bagagliaioPieno()){
		bool trovato = false;
		int indice;
		for(indice = 0; ((indice<DIMMAX) && (!trovato)); indice=indice+1){
			if(!bagagli[indice].presente)
				trovato = true;
		}
		return indice-1;
	}
	else
		return -DIMMAX;
}

