/*
 * Portafoglio.h
 *
 *  Created on: 15/set/2014
 *      Author: Ivano
 */

#ifndef PORTAFOGLIO_H_
#define PORTAFOGLIO_H_

#include "Oggetti.h"
#include "Negozio.h"


class Portafoglio
{
public:

    Portafoglio();
    virtual ~Portafoglio();
    void iniz_contante();
    bool hai_Portafoglio(Oggetti &oggetti);  // Controlla se è stato preso il portafoglio
    bool acquista_Portafoglio(Oggetti &oggetti, int comando_oggetto, Interfaccia &interfaccia, Negozio &negozio);
    void Prendi_Banconota(Oggetti &oggetti,int og, Interfaccia &interfaccia);
    float get_contanti() const;
    void set_contanti(float &contanti);
    float get_contocorrente() const;
    void set_contocorrente(float &conto);

private:

    float contanti;
    float conto_corrente;


};

#endif /* PORTAFOGLIO_H_ */
