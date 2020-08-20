/*
 * Premio.h
 *
 *  Created on: 21/ott/2014
 *      Author: FRANK
 */

#ifndef PREMIO_H_
#define PREMIO_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Premio
{
public:
    Premio(); //costruttore
    Premio(string t,string d,int o,int pt,int po);
    virtual ~Premio(); //distruttore

    void creaPremio(string t,string d,int o,int pt,int po);

    //set

    void setTitolo(string tit);
    void setDescrizione(string des);
    void setProgresso(int pr);
    void setObbiettivo(int ob);
    void setPremio_T(int pt);
    void setPremio_O(int po);
    void setRitirato(bool flag);
    //get

    string getTitolo() const;
    string getDescrizione() const;
    int getProgresso() const;
    int getObbiettivo() const;
    float getPremio_T() const;
    int getPremio_O() const;
    bool getRitirato() const;

    bool confronta();
    void incrementaProgresso();
    void stampaPremio(); //stampa a video tutti i campi Premio.
    bool operator == (const Premio&);
private:
    string Titolo; //titolo del premio
    string Descrizione; //descrizione del premio
    int Progresso; //progresso del completamento del premio
    int Obbiettivo; //obbiettivo finale per ricevere il premio
    float Premio_T; //indica l'incremento del tempo
    int Premio_O; //indica l'oggetto da inserire nell'inventario
    bool Ritirato;//booleano che indica se il premio è stato ritirato
};

#endif /* PREMIO_H_ */
