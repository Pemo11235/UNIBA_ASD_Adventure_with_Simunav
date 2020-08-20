#include "Agenda.h"
using namespace std;
Agenda::Agenda()
{}


void Agenda::Scrivi()
{
    CaricaCodici();
    ofstream file_output;
    file_output.open("codici.txt",ios::app);
    string codice;
    cout<<"Inserisci codice"<<endl;
    cin>>codice;
    if(!elementi.appartiene(codice))
    {
        file_output<<codice<<endl;
        Appunto nuova_nota;
        nuova_nota.Scrivi(codice);
    }
    else
        cout<<"Elemento gia' esistente"<<endl;
}

void Agenda::CaricaCodici()
{
    ifstream file_input;
    file_input.open("codici.txt",ios::in);
    string codice;
    while(file_input >> codice)
    {
        elementi.inserisci(codice,0);
    }
}

void Agenda::Leggi()
{
    CaricaCodici();
    cout<<"Inserisci codice dell' appunto"<<endl;
    string codice;
    cin>>codice;
    if(elementi.appartiene(codice))
    {
        Appunto appunto_leggere;
        appunto_leggere.Leggi(codice);
    }
    else
    {
        cout<<"Nessun appunto esistente con quel codice"<<endl;
    }
}


void Agenda::Cancella()
{
    int azione;
    cout<<"Digita il codice corrispondente alla modalita' di cancellazione"<<endl;
    cout<<"1 Cancellazione di un elemento dell'agenda"<<endl;
    cout<<"2 Cancellazione dell' intera agenda"<<endl;
    cin>>azione;
    switch (azione)
    {
    case 1:
        CancellaSingolo();
        break;
    case 2:
        CancellaTutto();
        break;
    default:
        cout<<"codice di operazione non valido"<<endl;
    }

}

void Agenda::SalvaCodici()
{
    ifstream file_input;
    file_input.open("codici.txt",ios::in);
    string codice_letto;
    typename Lista<string>::posizione posizione_attuale = lista_codici.primolista();
    while(file_input >> codice_letto)
    {
        lista_codici.inslista(codice_letto,posizione_attuale);
        posizione_attuale = lista_codici.succlista(posizione_attuale);
    }

}

void Agenda:: CancellaCodice(string codice_da_cancellare)
{
    typename Lista<string>::posizione posizione_attuale = lista_codici.primolista();
    bool flag = false;
    string codice_letto;
    while(!lista_codici.finelista(posizione_attuale) && !flag)
    {
        codice_letto = lista_codici.leggilista(posizione_attuale).data();
        if(codice_letto.compare(codice_da_cancellare)==0)
        {
            lista_codici.canclista(posizione_attuale);
            Appunto appunto_da_cancellare;
            appunto_da_cancellare.Cancella(codice_da_cancellare);
            elementi.cancella(codice_da_cancellare);
            flag = true;
            cout<<"Appunto cancellato con successo"<<endl;
        }
        else
        {
            posizione_attuale = lista_codici.succlista(posizione_attuale);
        }
    }
}

void Agenda::AggiornaFile()
{
    remove("codici.txt");
    ofstream file_output;
    file_output.open("codici.txt",ios::app);
    string codice;
    typename Lista<string>::posizione posizione =  lista_codici.primolista();
    while(!lista_codici.finelista(posizione))
    {
        codice = (lista_codici.leggilista(posizione)).data();
        file_output<<codice<<endl;
        posizione = lista_codici.succlista(posizione);
    }
}


void Agenda::CancellaSingolo()
{
    CaricaCodici();
    string codice;
    cout<<"Inserisci codice"<<endl;
    cin>>codice;
    if(elementi.appartiene(codice))
    {
        SalvaCodici();
        CancellaCodice(codice);
        AggiornaFile();
        CaricaCodici();
    }
    else
    {
        cout<<"Operazione errata elemento non esistente in agenda"<<endl;
    }
}


void Agenda::CancellaCodici()
{
    typename Lista<string>::posizione posizione_attuale =  lista_codici.primolista();
    string codice_da_cancellare;
    Appunto appunto_da_cancellare;
    while(!lista_codici.finelista(posizione_attuale))
    {
        codice_da_cancellare = lista_codici.leggilista(posizione_attuale).data();
        appunto_da_cancellare.Cancella(codice_da_cancellare);
        posizione_attuale = lista_codici.succlista(posizione_attuale);
    }
    remove("codici.txt");
    svuotaLista(lista_codici);
    //Obrobrio
    //elementi.~Dizionario();
}

void Agenda::CancellaTutto()
{
    SalvaCodici();
    CancellaCodici();
    cout<<"Tutti gli elementi dell'agenda sono stati cancellati"<<endl;
}
