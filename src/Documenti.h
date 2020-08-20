/*
 * File:   Documenti.h
 * Author: Alessandra
 *
 * Created on 6 giugno 2014, 15.38
 */

#ifndef DOCUMENTI_H
#define	DOCUMENTI_H

#define MAXDOCUMENTI 50

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Lista.h"
#include "servizioLista.h"
#include "Documento.h"

using namespace std;

class Documenti
{
public:
    Documenti ();
    void inserisci (string, string, int, int); //inserisce un nuovo documento all'interno della struttura dati scelta
    int get_n_documenti();					   //restituisce il numero di documenti all'interno della struttura dati scelta
    void get_documento(int);                   //restituisce un documento specifico
    void elenca_documenti(int);                //per vedere nell'archivio dell'ufficio quali documenti sono disponibili
    void stampa_nomi_documenti (int);
    string get_nome_documento(int);
    string get_descrizione_documento(int);
    int get_codice_documento(int);
    void set_luogo_documenti (int, int);
    int get_luogo_documenti (int);
private:
    //Lista <Documento> documenti; se uso la lista già implementata dovrei cambiare tutti i metodi e l'ordine degli input
    Lista<Documento> documenti;
    int n_documenti;
    Lista<Documento>::posizione pos;
};


#endif	/* DOCUMENTI_H */

