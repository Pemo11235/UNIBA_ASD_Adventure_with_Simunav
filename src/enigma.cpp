#include "enigma.h"

//Modifica PMF(struttura)

enigma::enigma()
{
    id = 0;
    eni = "non selezionato";
    Lista<risposta> risposte;
}

enigma::~enigma()
{
}

void enigma::set_id(int codice)
{
    id = codice;
}

void enigma::set_enigma(string e)
{
    eni = e;
}

void enigma::set_risposta(risposta r)
{
    Lista<risposta>::posizione pol = risposte.primolista();

    while(!risposte.finelista(pol))
    {
        pol = risposte.succlista(pol);
    }
    risposte.inslista(r,pol);


}

int enigma::get_id()
{
    return id;
}

string enigma::get_enigma()
{
    return eni;
}

Lista<risposta> enigma::get_risposta()
{
    return risposte;
}

void enigma::operator =(enigma e)
{
    set_id(e.get_id());
    set_enigma(e.get_enigma());

    copiaLista(risposte,e.get_risposta());
}

void enigma::stampa_risposte()
{
    Lista<risposta>::posizione pos;
    pos = risposte.primolista();

    int i = 0;

    while (!risposte.finelista(pos))
    {
        pos = risposte.succlista(pos);
        i++;
    }
    pos = risposte.preclista(pos);

    int j = 0;
    while (j < i)
    {
        cout << risposte.leggilista(pos).get_risp() << ";";
        cout << risposte.leggilista(pos).get_esatto() << ";";
        pos = risposte.preclista(pos);
        j++;
    }
}
