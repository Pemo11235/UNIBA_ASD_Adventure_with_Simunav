#include <cstdlib>
#include <iostream>
//#include <windows.h>
#include "Mappa.h"
#include "Astro.h"

using namespace std;

int main(int argc, char *argv[])
{
// chiamate a sistema da commentare per evitare incompatibilità su sistemi non windows
    system("title Adventure with Simunav");   //imposto header della finestra dos
    system("mode con cols=100");    		  //imposto la larghezza della finestra dos

    fstream crono("Cronologia.odb",fstream::in); //apro il file su cui è presente la cronologia

    ifstream f("Mappa.nav",ios::in);	 //apro il file su cui ho rappresentato la mappa
    bool aperto=f.good();				 //esito dell'apertura del file
    if (aperto) 						 //se il file di input è stato aperto correttamente
    {

        Mappa M(f,crono); //istanzio la mappa
        Astro partita = Astro();
        partita.ciak(M,f);

    }
    else cout<<"Errore apertura file \"Mappa.nav\""<<endl; //altrimenti stampa messaggio di errore

	f.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}

