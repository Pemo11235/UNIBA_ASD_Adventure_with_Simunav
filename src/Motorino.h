#ifndef H_MOTORINO
#define H_MOTORINO
#include "Veicolo.h"

/* DEFINIZIONE DELLA CLASSE MOTORINO */

using namespace std;

class Motorino: public Veicolo
{

public:

    //Motorino(string n, int c, int l);
    Motorino();
    //int get_luogo();
    void pieno_benzina();

};


#endif
