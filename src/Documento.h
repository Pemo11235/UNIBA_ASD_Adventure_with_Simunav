/*
 * File:   Documento.h
 * Author: Alessandra
 *
 * Created on 6 giugno 2014, 14.55
 */

#ifndef DOCUMENTO_H
#define	DOCUMENTO_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Oggetto.h"


using namespace std;

class Documento: public Oggetto
{
public:
    Documento();
    Documento(string,string,int,int);
    ~Documento();
    string get_descrizione () const;
    void set_descrizione (string);
    string get_nome() const;
    void set_nome(string);
    void stampa_documento();
    int get_codice();
    int get_luogo ();
    void set_luogo_documento (int);
    int luogo_documento;
private:
    int codice;
    string descrizione;
    string nome;

};


#endif	/* DOCUMENTO_H */

