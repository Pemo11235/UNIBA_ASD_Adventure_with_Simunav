/* IMPLEMENTAZIONE DEI METODI
 * DELLA CLASSE AUTOBUS
*/

#include "Autobus.h"
//#include "Veicolo.h"

using namespace std;

//INIZIO MODIFICHE Luca Carlucci
Autobus::Autobus():Veicolo(){
	postiLiberi = false;
}

Autobus::Autobus(string n, int c, int l, unsigned short numP, bool inU):Veicolo(n, c, l, numP, inU){
	//Veicolo::set_indice_di_consumo(10);
	//Veicolo::set_livello_benzina(100);
	postiLiberi = false;
}


Autobus::~Autobus(){

}

bool Autobus::autobusPieno(){
	return(postiLiberi);
}
//FINE MODIFICHE Luca Carlucci

