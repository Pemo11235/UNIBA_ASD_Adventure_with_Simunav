
#ifndef DESCDATA_H_
#define DESCDATA_H_

//Modifica PMF(struttura)

#include "Lista.h"
#include "servizioLista.h"
#include <string>

typedef Lista<string>::posizione posizione;

class DescData
{
public:
    // Creazione istanza oggetti DescData tramite caricamento dati da file
    static DescData* loadDescriptions(int idLuogo, string nomeLuogo);

    DescData(); 								  // Costruttore predefinito
    virtual ~DescData();						  // Distruttore predefinito
    void initialize(); 							  // Inizializza il puntatore alla prima descrizione presente nella lista delle descrizioni
    string getDescription();					  // Restituisce una delle descrizioni per il Luogo
    DescData* addDescription(string description); // Aggiunge una descrizione alla lista delle descrizioni
    // Restituisce il puntatore allo stesso oggetto chiamante
    // (utile qualora si vogliano aggiungere aggiungere descrizioni "a catena"
    // via codice) es. descData->addDescription("d1")->addDescription("d2")->addDescription(....

    int getSize() const;  // Restituisce il numero delle descrizioni contenute nella lista delle descrizioni
    bool isEmpty() const; // Restituisce TRUE se la lista delle descrizioni è vuota, FALSE altrimenti

protected:
private:
    Lista<string>* descList; // Lista delle descrizioni
    posizione currentCell; 	 // Puntatore alla cella della descrizione attualmente utilizzata
    posizione insPtr; 		 // Puntatore per l'inserimento in coda alla lista

    int numDes; // Contatore numero descrizioni inserite
};

#endif /* DESCDATA_H_ */
