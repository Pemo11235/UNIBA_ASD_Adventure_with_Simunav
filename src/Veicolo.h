#ifndef H_VEICOLO
#define H_VEICOLO

#include "Oggetto.h"
/* DEFINIZIONE DELLA CLASSE VEICOLO*/

using namespace std;

class Veicolo: public Oggetto {

public:

	//INIZIO MODIFICHE PANNO
	Veicolo();
	Veicolo(string, int, int, unsigned short, bool);
	~Veicolo();
	void set_numPosti(unsigned short);
	void set_inUso(bool);
	unsigned short get_numPosti();
	bool get_inUso();
	//FINE MODIFICHE PANNO

	void pieno_benzina();
	void aggiorna_carburante();
	void set_indice_di_consumo(int);
	int get_livello_benzina();
	void set_livello_benzina(int);

private:

	int indice_di_consumo;
	unsigned short livello_benzina;
	unsigned short numPosti;	//Numero posti - MODIFICA PANNO
	bool inUso;					//Indica se il veicolo è in uso - MODIFICA PANNO



};

#endif


