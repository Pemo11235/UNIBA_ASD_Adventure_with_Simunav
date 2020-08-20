#ifndef H_NEGOZIO
#define H_NEGOZIO


#include "Oggetto.h"
#include "Interfaccia.h"
#include "Oggetti.h"
#include "Servizi_Lista.h"
#include "Transazioni.h"
using namespace std;



class Negozio : public Transazioni
{
public:
    Negozio();
    Negozio( Servizi_Lista<Oggetto> ogg );
    float acquista( int, Interfaccia&, float&,float&, Oggetti&,string metodo);  // MODIFICA D-R(Pisani)
    void parla(Interfaccia&);
    void inserisci(Oggetto);
    void inserisci( Oggetto, float );

protected:
    Servizi_Lista<Oggetto> oggetti;
};

#endif
