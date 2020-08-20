#ifndef H_OGGETTI
#define H_OGGETTI

#define MAXOGGETTI 150

#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

#include "Oggetto.h"

class Oggetti
{
public:
    Oggetti();
    void inserisci(Oggetto);
    int get_n_oggetti();
    Oggetto get_oggetto(int);
    Oggetti posizionati_in(int);
    int luogo_oggetto(int, int);
    void set_luogo(int, int);    // serve perche' Oggetti.get_oggetto(o).set_luogo(l) non funziona
    int get_luogo(int);
    void svuota();
    void set_luogo_oggetti_pos_in(int, int); //Modifica DELLA FOLGORE GRAZIA

    int get_oggetto_indice_by_codice(int); //MODIFICA D-R(D'Orsi):Negozio + Banca
    bool controllo_og(int);	//MODIFICA D-R(D'Orsi):Negozio + Banca

    //inizio modifiche ROSA CHIARAPPA

    void set_rubato(int, int);

    //fine modifiche ROSA CHIARAPPA

    //Modifiche_ML
    int get_n_oggettiZ();
    void get_zaino(int);
    int get_zaino2(int);
    int get_valigia(int);
private:
    Oggetto oggetti[MAXOGGETTI];
    int fo; // fineOggetti: numero oggetti riconosciuti

};

#endif
