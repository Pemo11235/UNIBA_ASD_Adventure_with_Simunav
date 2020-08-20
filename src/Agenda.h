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
    Dizionario<string,int> elementi; /*struttura che conterrà i codici univoci dei file dell' agenda */
    Lista<string> lista_codici; 	 /*conterrà i codici ai fini della cancellazione */
    void CaricaCodici(); 			 /*caricherà i codici dal file sul dizionario */
    void CancellaSingolo();          /* cancella il singolo elemento dell'agenda*/
    void CancellaTutto(); 			 /*cancella tutti gli elementi dell'agenda*/
    void SalvaCodici(); 			 /*caricherà i codici dal file sulla lista eccetto quello da cancellare e verrà cancellato dal dizionario*/
    void AggiornaFile();   			 /*aggiornerà il file contenete i codici dopo l'operazione di cancellazione di un elemento*/
    void CancellaCodice(string);     /*cancellerà dalla lista dei codici il codice passato come parametro*/
    void CancellaCodici(); 			 /*cancellerà tutti i codici presenti nel file e nel dizionario*/
};
