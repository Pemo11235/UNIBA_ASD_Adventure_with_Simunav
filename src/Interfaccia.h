#ifndef INTERFACCIA_H
#define INTERFACCIA_H

#include <string>
#include "Luogo.h"
#include "Oggetti.h"
#include "Oggetto.h"

class Interfaccia
{
public:

    Interfaccia();
    int menuPrincipale();
    void saluto();
    void scrivi(string);
    void scrivi_parziale(string);
    void scrivi_parziale(int);
    // modifica Angelo Petronelli
    void scrivi_carattere(char);
    // fine modifica

    void scrivi_float( float ); //MODIFICA D-R(D'Orsi):Negozio + Banca
    float leggi_float(string);  //MODIFICA D-R(D'Orsi):Negozio + Banca

    void a_capo();
    int leggi_intero(string);
    string leggi_stringa(string);
    char leggi_carattere(string); //MODIFICA ANTONIO BASILE
    string leggi_comando();
    void disegna_scena(Luogo);
    void elenca_oggetti(Oggetti, string);
    void pausa();
    
    
    void elenca_rubati(Oggetti, string); //modifiche CHIARAPPA ROSA
    
    
private:
    Luogo ultimoLuogo;
};

#endif

