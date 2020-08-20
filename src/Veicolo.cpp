/* METODI DELLA CLASSE VEICOLO */
#include "Veicolo.h"
#include "Oggetto.h"

void Veicolo::pieno_benzina() {
    set_livello_benzina(20);
}

int Veicolo::get_livello_benzina()
{       return livello_benzina;}

void Veicolo::set_indice_di_consumo(int i)
{
    indice_di_consumo = i;
}

void Veicolo::aggiorna_carburante()
{
    // m*indice di consumo Ã¨ il consumo per ogni metro percorso
    // la distanza complessima percorsa Ã¨ data dal navigatore

    livello_benzina=livello_benzina-indice_di_consumo;
}

void Veicolo::set_livello_benzina(int l)
{
    livello_benzina=l;
}

//INIZIO MODIFICHE PANNO
Veicolo::Veicolo():Oggetto(){
	numPosti = 0;
	inUso = false;
	indice_di_consumo = 0;
	livello_benzina = 0;
	set_isVeicolo(true);
}

Veicolo::Veicolo(string n, int c, int l, unsigned short numP, bool inU):Oggetto(n, c, l,numP, inU){
	numPosti = numP;
	inUso = inU;
	indice_di_consumo = 0;
	livello_benzina = 0;
	set_isVeicolo(true);
}

Veicolo::~Veicolo(){

}

void Veicolo::set_numPosti(unsigned short numP){
	numPosti = numP;
}

void Veicolo::set_inUso(bool inU){
	inUso = inU;
}

unsigned short Veicolo::get_numPosti(){
	return numPosti;
}

bool Veicolo::get_inUso(){
	return inUso;
}
//FINE MODIFICHE PANNO
