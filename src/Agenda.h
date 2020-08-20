#include "Dizionario.h"
#include "Appunto.h"
#include "Lista.h"
#include "servizioLista.h"

//Modifica PMF(struttura)

class Agenda
{
public:
    Agenda();
    void Scrivi();
    void Leggi();
    void Cancella();

private:
    Dizionario<string,int> elementi; /*struttura che conterr� i codici univoci dei file dell' agenda */
    Lista<string> lista_codici; 	 /*conterr� i codici ai fini della cancellazione */
    void CaricaCodici(); 			 /*caricher� i codici dal file sul dizionario */
    void CancellaSingolo();          /* cancella il singolo elemento dell'agenda*/
    void CancellaTutto(); 			 /*cancella tutti gli elementi dell'agenda*/
    void SalvaCodici(); 			 /*caricher� i codici dal file sulla lista eccetto quello da cancellare e verr� cancellato dal dizionario*/
    void AggiornaFile();   			 /*aggiorner� il file contenete i codici dopo l'operazione di cancellazione di un elemento*/
    void CancellaCodice(string);     /*canceller� dalla lista dei codici il codice passato come parametro*/
    void CancellaCodici(); 			 /*canceller� tutti i codici presenti nel file e nel dizionario*/
};
