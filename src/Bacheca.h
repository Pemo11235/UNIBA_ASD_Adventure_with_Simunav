#ifndef BACHECA_H
#define	BACHECA_H

#include "Lista.h"

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>//Modifica PMF (ufficio)

#include <cctype>
//#include <windows.h>

//#include "listavtemp.h"//Modifica PMF (ufficio)

//Modifica PMF: abbiamo tolto Lista.h per utilizzare la lista con i doppi puntatori
//#include"Strutture Dati/lista_doppi_puntatori_template.h"//Modifica di PMF //MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
using namespace std;

#define MAXMESSUTENTE 15 //dimensione massima della bacheca
#define LUNG 160 //lunghezza massima di un messaggio

class Bacheca
{
public:
    Bacheca();
    ~Bacheca();
    void CreaBacheca();
    void StampaBacheca();
    void StampaMessCancellabili();
    int GetMessCancellabili();
    bool BachecaVuota();
    bool BachecaPiena();
    void SalvaBacheca(ofstream&);
    void CaricaBacheca(ifstream&);
    void CancellaBacheca();
    bool EsisteMessaggio(string);
    void NuovoMessaggio(string);
    void NuovoMessaggioGioco(string);
    void CancellaMessaggio(int);
    void CancellaMessaggioGioco(string);

private:

    //Lista_template_vettore <string,MAXMESSUTENTE> bac; //Modifica PMF (ufficio)
    //ListaDP<string> bacheca; //modificare per ciaccia e barnaba e ciccio //MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string> bacheca;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    int messCancellabili;
};

#endif /* BACHECA_H */
