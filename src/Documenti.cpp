#include "Documenti.h"

Documenti::Documenti()
{
    n_documenti= 1;
}

void Documenti::inserisci(string n, string d, int c, int l)
{
    if(n_documenti<MAXDOCUMENTI)
    {
        pos = posizioneFisicaDaLogica(documenti, n_documenti - 1);
        documenti.inslista(Documento(n,d,c,l),pos);
        n_documenti++;
    }
}

int Documenti::get_n_documenti()
{
    return n_documenti;
}

void Documenti::get_documento(int i)
{
    pos = posizioneFisicaDaLogica(documenti, i);
    documenti.leggilista(pos).stampa_documento();
}

string Documenti::get_nome_documento(int i)
{
    pos = posizioneFisicaDaLogica(documenti, i);
    return documenti.leggilista(pos).get_nome();
}

string Documenti::get_descrizione_documento(int i)
{
    pos = posizioneFisicaDaLogica(documenti, i);
    return documenti.leggilista(pos).get_descrizione();
}

int Documenti::get_codice_documento(int i)
{
    pos = posizioneFisicaDaLogica(documenti, i);
    return documenti.leggilista(pos).get_codice();
}

void Documenti::elenca_documenti(int k)
{
    int i;

    for (i = 1 ; i < get_n_documenti() ; i++)
    {
        pos = posizioneFisicaDaLogica(documenti, i);
        if (documenti.leggilista(pos).get_luogo() == k)
            get_documento(i);
    }
}

void Documenti::stampa_nomi_documenti (int k)
{
    int i;

    for (i = 1 ; i < get_n_documenti() ; i++)
    {
        pos = posizioneFisicaDaLogica(documenti, i);
        if (documenti.leggilista(pos).get_luogo() == k)

            cout << "Documento " << get_codice_documento(i) << " : " << get_nome_documento(i) <<endl;
    }
}

void Documenti::set_luogo_documenti(int i,int luogo)
{
    Documento doc (get_nome_documento(i),get_descrizione_documento(i),get_codice_documento(i),luogo);
    pos = posizioneFisicaDaLogica(documenti, i);
    documenti.scrivilista(doc,pos);
}

int Documenti::get_luogo_documenti(int i)
{
    pos = posizioneFisicaDaLogica(documenti, i);
    return documenti.leggilista(pos).get_luogo();
}
