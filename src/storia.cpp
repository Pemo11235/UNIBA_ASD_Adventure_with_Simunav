
#include "storia.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;



Storia::Storia()
{
    storia.crealista();
    lung_storia = storia.primolista();
}

Storia::~Storia() {}

void Storia::insStoria(string com, string risp)
{
    ostringstream ls_intero;               //VARIABILE D'APPOGGIO CHE CONTERRA' IL VALORE DI lung_storia
    ls_intero << lung_storia;
    string ls_stringa = ls_intero.str();   //CONVERSIONE DEL VALORE CONTENUTO IN ls_intero DA INTERO A STRINGA, UTILE PER CONTARE LE MOSSE A VIDEO

    if (storia.finelista(lung_storia))
    {
        string strConcatenata = ls_stringa + " - Hai digitato '" + com + "' e " + risp ;  //CONCATENO IN UNA STRINGA IL CODICE DEL COMANDO DIGITATO E LA DESCRIZIONE DELLA RISPOSTA
        storia.inslista(strConcatenata, lung_storia);
        lung_storia = storia.succlista(lung_storia);
    }
}
void Storia::stampaStoria()
{
    Lista<string>::posizione p=storia.primolista();
    //int i;
    while(!storia.finelista(p))
    {
        cout << storia.leggilista(p) <<endl;
        p=storia.succlista(p);
    }
}



