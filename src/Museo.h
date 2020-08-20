#ifndef MUSEO_H
#define MUSEO_H

#include "Grafo.h"
#include "StanzaMuseo.h"
#include "servizioLista.h"

class Museo
{
public:
    Museo();
    void creamuseo();
    typename Grafo<StanzaMuseo,unsigned char>::nodo getstanzacorrente();
    void setstanzacorrente(typename Grafo<StanzaMuseo,unsigned char>::nodo);
    Lista<typename Grafo<StanzaMuseo,unsigned char>::nodo> getstanzeadiacenti();
    typename Grafo<StanzaMuseo,unsigned char>::nodo getiniziale();
    StanzaMuseo leggiStanza(typename Grafo<StanzaMuseo, unsigned char>::nodo);
    void scriviStanza(typename Grafo<StanzaMuseo, unsigned char>::nodo , const StanzaMuseo& );

private:
    typename Grafo<StanzaMuseo,unsigned char>::nodo stanzainiziale;
    typename Grafo<StanzaMuseo,unsigned char>::nodo stanzacorrente;
    Grafo<StanzaMuseo,unsigned char> grafomuseo;
    string titoli[25];
    string descrizioni[25];
};

//HEADER aggiunto da ANTONIO PASTORELLI

#endif // MUSEO_H
