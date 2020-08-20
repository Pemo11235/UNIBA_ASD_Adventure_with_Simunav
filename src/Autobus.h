#ifndef AUTOBUS_H
#define	AUTOBUS_H

#include "Veicolo.h"

/* DEFINIZIONE DELLA CLASSE AUTOBUS
 * RISTRUTTURAZIONE DI Luca Carlucci
*/

using namespace std;

class Autobus: public Veicolo {

	public:
		Autobus();
		//INIZIO MODIFICHE Luca Carlucci
    	Autobus(string, int, int, unsigned short, bool);
    	~Autobus();
    	bool autobusPieno();
	private:
    	bool postiLiberi;
    	//FINE MODIFICHE Luca Carlucci
};



#endif	/* AUTOBUS_H */


