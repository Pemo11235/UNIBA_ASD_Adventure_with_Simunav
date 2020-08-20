/*
 * Automobile.h
 *
 *  Created on: 05/set/2015
 *      Author: Luca Carlucci
 */

/* HEADER FILE DI DEFINIZIONE DELLA CLASSE AUTOMOBILE
 * IL TIPO AUTOMOBILE E' UN PARTICOLARE TIPO DI
 * VEICOLO.
 */

#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

#include "Veicolo.h"
#include "Bagagliaio.h"

class Automobile: public Veicolo{
	public:
		Automobile();
		Automobile(string, int, int, unsigned short, bool);
		~Automobile();
		Bagagliaio bagagliaio;			//Un oggetto di tipo AUTOMOBILE dispone di un BAGAGLIAIO
};

#endif /* AUTOMOBILE_H_ */

