/*
 * File:   luogoufficio.h
 * Author: Alessandra
 *
 * Created on 4 giugno 2014, 11.17
 */

#ifndef LUOGOUFFICIO_H
#define	LUOGOUFFICIO_H

#include "Luogo.h"
#include "Oggetti.h"
#include "Documenti.h"
#include "Documento.h"
//#include "Documenti.cpp"
using namespace std;

class luogoufficio:public Luogo
{
public:
    luogoufficio (string,string);
    luogoufficio ();
    ~luogoufficio ();
    //void consegna_documento(Documenti ,int);
    //void ritira_documento(Documenti ,int, string);
    //void crea_documento();

};




#endif	/* LUOGOUFFICIO_H */

