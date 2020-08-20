#include "DescData.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

DescData::DescData()
{
    descList = new Lista<string>();
    currentCell = NULL;
    insPtr = descList->primolista();
    numDes = 0;
}

DescData::~DescData()
{
    delete descList;
}

void DescData::initialize()
{
    currentCell = descList->primolista();
}

string DescData::getDescription()
{
    string description = "";
    if (!descList->listavuota())   								// La lista non è vuota --> puntatore al primo elemento NOT NULL
    {
        description = descList->leggilista(currentCell); 				// Lettura descrizione corrente
        currentCell = descList->succlista(currentCell);		    // Salto alla descrizione successiva (se esiste)
        if (descList->finelista(currentCell))
            initialize();	    // Simulazione lista circolare con controllo su "finelista"
    }
    return description;
}

DescData* DescData::addDescription(string description)
{
    descList->inslista(description, insPtr);
    insPtr = descList->succlista(insPtr);
    numDes++;
    return this;
}

int DescData::getSize() const
{
    return numDes;
}

bool DescData::isEmpty() const
{
    return !numDes;
}

DescData* DescData::loadDescriptions(int id, string nome)
{
    DescData* ddata = NULL;

    ostringstream filename; 			// dichiaro una variabile "filename" di tipo ostringstream che mi servirà ad accodare due stringhe
    filename << id << ".txt";	    //Inserisco l'id nella stringa del filename e l'estensione
    ifstream file(("./descrizioni/" + filename.str()).data(), ios::in); // apro il file passando come parametro la "path" che è una stringa sommata all'id del luogo preventivamente convertito in stringa

    //Controllo l'esistenza del file di descrizioni per il relativo luogo
    if( !file )
    {
        //Informo l'utente in caso non ci sia il file
        cout << "Nessun file di descrizioni trovato per il luogo id:" << id << " nome:" << nome << endl;
        return ddata;
    }

    string descr;
    // int descrPresenti = 0; Vaira - Rimosso contatore: l'oggetto DescData contiene in sé il numero di descrizioni inserite
    ddata = new DescData(); // Vaira - Istanziamento oggetto DescData da assegnare al Luogo
    while( std::getline( file, descr) )  // mentre c'è qualcosa da leggere nel file
    {
        ddata->addDescription(descr); // Vaira - Aggiunge una descrizione all'oggetto DescData istanziato
        //descrPresenti++;
    }

    //Verifico che ci sia almeno una descrizione, in caso contrario avverto l'utente del problema
    // Vaira - Sostituito contatore con metodo specifico dell'oggetto DescData
    if( ddata->isEmpty() )
    {
        cout << "Nessuna descrizione trovata per il luogo id:" << id << " nome:" << nome << endl;
    }
    else     // Vaira - Se esistono delle descrizioni viene inizializzato il puntatore alla prima descrizione
    {
        ddata->initialize();
    }

    return ddata;
}
