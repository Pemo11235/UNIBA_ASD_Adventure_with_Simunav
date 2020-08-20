/*
 * Bagagliaio.h
 *
 *  Created on: 07/set/2015
 *      Author: Luca Carlucci
 */

/* HEADER FILE CONTENENTE LA DEFINIZIONE DELLA
 * CLASSE BAGAGLIAIO IN USO ALL'AUTOMOBILE
 * I dettagli relativi alla specifica del tipo BAGAGLIAIO
 * sono riportati nella documentazione corrispondente.
 */

#ifndef BAGAGLIAIO_H_
#define BAGAGLIAIO_H_

#include "Oggetto.h"

//Dimensione massima
const unsigned short DIMMAX = 10;

//Definizione del tipo "bagaglio"
struct bagaglio{
	Oggetto oggetto;
	bool presente;
};

class Bagagliaio{
	public:
		Bagagliaio();
		~Bagagliaio();
		bool bagagliaioVuoto();
		bool bagagliaioPieno();
		void depositaBagaglio(Oggetto);
		void rimuoviBagaglio(Oggetto);
		Oggetto vediBagaglio(Oggetto);
		Oggetto estraiBagaglio();
		int cercaBagaglio(Oggetto);
		void vediBagagli();
	private:
		int cercaScompartoLibero();
		bagaglio bagagli[DIMMAX];
		unsigned short num_bagagli;
};



#endif /* BAGAGLIAIO_H_ */

