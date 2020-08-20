/*
 * CartadiCredito.h
 *
 *  Created on: 15/set/2014
 *      Author: Ivano
 */

#ifndef CARTADICREDITO_H_
#define CARTADICREDITO_H_

#include "Oggetti.h"
#include "Negozio.h"
#include "Portafoglio.h"

class Carta_di_Credito
{
public:

    Carta_di_Credito();
    virtual ~Carta_di_Credito();
    bool hai_Carta(Oggetti oggetti);
    bool acquista_Carta(Oggetti &oggetti, int comando_oggetto, Interfaccia &interfaccia, Negozio &negozio, Portafoglio &portafoglio); // Controlla se è stato preso il portafoglio e successivamente la Carta
    float get_contocorrente(Portafoglio &portafoglio) const;
    void set_contocorrente(Portafoglio &portafoglio,float &conto);

private:

};

#endif /* CARTADICREDITO_H_ */
