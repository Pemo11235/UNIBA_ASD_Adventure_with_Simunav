#ifndef _LUOGO_H
#define _LUOGO_H

//Modifica PMF(struttura)

#include <iostream>
#include <cstdlib>
#include "Vialuogo.h"
#include "Lista.h"
#include "servizioLista.h"
#include "DescData.h"

#include <iostream>      //MODIFICA D-R(Colturi):Luoghi a Pagamento
#include <fstream>       //MODIFICA D-R(Colturi):Luoghi a Pagamento
#include <sstream>       //MODIFICA D-R(Colturi):Luoghi a Pagamento
#include "Oggetti.h"	 //MODIFICA D-R(Colturi):Luoghi a Pagamento


using namespace std;

class Luogo
{
    friend ostream& operator<<(ostream& os, const Luogo& l); //overload output
public:

    //definizione di tipo
    typedef unsigned int ID;

    //costruttore
    Luogo();

    //distruttore di default

    //setter e getter
    void scriviID(unsigned int);
    unsigned int leggiID() const;
    void scriviluogo(string);
    string leggiluogo() const;
    void insvia(Vialuogo);
    Lista<Vialuogo> leggivie() const;

    // Vaira [Donati] - Dichiarazione metodi codice Donati e rimozione dei metodi superflui
    string getDescrizione(); // dichiaro una funzione che restituisce la descrizione
    void setDescData(DescData* descData);
    DescData* getDescData() const;

    // Modifica Angelo Petronelli
    void scrividirezioni(string);
    string leggidirezioni() const;
    // Fine Modifica

    bool leggi_predefinito(); //Modifica DELLA FOLGORE GRAZIA

    // MODIFICA D-R(Colturi):Luoghi a Pagemento
    Lista<string> Carica_descLuoghiPag();
    void Leggi_descLuoghiPag(Lista<string> desc, int luogo_attuale);
    void leggi_str(string stampa, int luogo_attuale);

    //sovraccarichi
    void operator =(Luogo);
    bool operator ==(Luogo);
    bool operator!= (const Luogo&);


private:
    ID id;
    string nome;
    //Modifica Angelo Petronelli
    string direzioni;               // contiene la stringa delle direzioni consentite
    //fine modifica
    Lista<Vialuogo> vie;


    // Vaira - Sostituita lista circolare con classe custom
    DescData* descrizioni;
};

#endif
