/*
 * storia.h
 *
 *  Created on: 18/giu/2014
 *      Author: Giulia
 */

#ifndef STORIA_H_
#define STORIA_H_

#include <string>
//#include "Strutture Dati/listaVT.h" //MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
#include "Lista.h"


//const int maxlung=100;

using namespace std;

class Storia
{
public:
    Storia();
    ~Storia();
    void insStoria(string, string);       //PRENDE IL COMANDO E LA RISPOSTA E LI INSERISCE NELLA LISTA
    void stampaStoria();                  //STAMPA A VIDEO QUELLO CHE PRENDO LEGGO DALLA LISTA

private:
    //Lista_VT <string,maxlung> storia;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    //Lista_VT<string,maxlung>::posizione lung_storia;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string> storia;                 //MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    Lista<string>::posizione lung_storia; //MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    string strConcatenata;

};

#endif /* STORIA_H_ */
