#ifndef H_BANCA
#define H_BANCA

using namespace std;

#include "Oggetto.h"
#include "Interfaccia.h"
#include "Oggetti.h"
#include "Servizi_Lista.h"
#include "Transazioni.h"

class Banca : public Transazioni
{
public:
    Banca();
    Banca(Servizi_Lista<Oggetto> ogg);

    void parla(Interfaccia&);
    void deposita(float&,float&,Interfaccia&);
    void preleva( float&,float&,Interfaccia&);

    void lascia_oggetto(Oggetto);
    void mostra_oggetto(Interfaccia&);
    void ritira_oggetto(int, Interfaccia&, Oggetti&);

protected:
    Servizi_Lista<Oggetto> oggetti;


};

#endif
