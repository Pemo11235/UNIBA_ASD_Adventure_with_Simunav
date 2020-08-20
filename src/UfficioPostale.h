/*
 * ufficiopostale.h
 *
 *  Created on: 21/giu/2016
 *      Author: Germano G
 */

#ifndef UFFICIOPOSTALE_H_
#define UFFICIOPOSTALE_H_

#include "luogoufficio.h"
#include <cstdlib> //funzione random

using namespace std;

class UfficioPostale:public luogoufficio
{
public:
    UfficioPostale();
    virtual ~UfficioPostale();

    int randomFila(); // genera un numero casuale da 0 a 10 compresi.
    bool get_Suggerimento();
    bool get_Pacco();
    void set_Suggerimento(bool);
    void set_Pacco(bool);

    bool get_ritiratoPacco();
    bool get_ritiratoSuggerimento();
    void set_ritiratoPacco(bool);
    void set_ritiratoSuggerimento(bool);
private:
    bool invia_Richiesta_Suggerimento;
    bool invia_Richiesta_Pacco;
    bool ritirato_Suggerimento;
    bool ritirato_Pacco;

};


#endif /* UFFICIOPOSTALE_H_ */
