#ifndef PALESTRA_H
#define PALESTRA_H
#include "StatoFisico.h"
#include "Scheda.h"
#include "Lista.h"
#include "Dizionario.h"
#include <Windows.h>
#include <sstream>
#include <string>
#include <iostream>

/*
*Progetto AMS
*Classe che implementa le funzionalità del luogo "Palestra"
*/
class Palestra
{
public:
    static void usaPanca(StatoFisico& stato, int ripetizioni);
    static void usaTapis(StatoFisico& stato, int ripetizioni);
    static void usaSchede(StatoFisico& stato);
    static void usaTerminale();

private:
    static Lista<string> listaSchede;
    static Dizionario<string,Scheda> schede;
    static void stampaSchede();
    static void creaScheda();
    static void cancellaSchede();
    static void eseguiScheda(StatoFisico& stato);


};

#endif // PALESTRA_H
