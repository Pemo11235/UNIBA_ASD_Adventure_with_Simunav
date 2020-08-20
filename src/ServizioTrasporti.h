#ifndef H_SERVIZIOTRASPORTI
#define H_SERVIZIOTRASPORTI

#include "Trasporto.h"
#include "Lista.h"
#include "servizioLista.h"

class ServizioTrasporti
{
public:
    ServizioTrasporti();                    //Costruttore di default
    ServizioTrasporti(ifstream &t);         //Costruttore da file
    ~ServizioTrasporti();                   //Distruttore

    void cerca_trasporto(int n);            //Valorizza l'indice con il Trasporto che ha partenza n
    int get_luogo();                        //Restituisce l'arrivo del Trasporto puntato da indice
    string get_map();                       //Restituisce il nome della mappa del Traporto puntato da indice
    void stampa_trasporti();                //Stampa la lista dei trasporti

    typedef Lista<Trasporto>::posizione posiz;

    /*
     * Modifica introdotta per permettere il
     * funzionamento del programma rispettando
     * le specifiche della lista.
     * @author Andrea Esposito & Alessandro Annese
     */
    void operator=(const ServizioTrasporti& s);

private:
    Lista<Trasporto> trasporti;             //Inizializzato da file
    posiz indice;                           //Valorizzato da cerca_trasporto
    string estrai_stringa(string s, int &i, char fine);
};

#endif // H_SERVIZIOTRASPORTI
