#ifndef PREMI_H_
#define PREMI_H_
#include "Lista.h"
#include "Premio.h"

#define MAX_PREMI 50

using namespace std;

class Premi
{
public:
    Premi();
    ~Premi();

    void stampaPremiRicevuti();
    float ritiraTempo(typename Lista<Premio>::posizione);
    int ritiraOggetto(typename Lista<Premio>::posizione);
    Lista<Premio>* getListaPremi();

private:

    Lista<Premio>* listapremi;
};

#endif
