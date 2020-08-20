#include "Premi.h"

using namespace std;

Premi::Premi()
{
    listapremi = new Lista<Premio>;
}

Premi::~Premi() {}

void Premi::stampaPremiRicevuti()
{
    int l=1;
    int premistampa=0;
    Lista<Premio>::posizione i;
    cout << "premi ricevuti"<< endl;
    i=listapremi->primolista();
    while(not listapremi->finelista(i))
    {
        if(listapremi->leggilista(i).getRitirato() == true)
        {
            cout << l << ")";
            listapremi->leggilista(i).stampaPremio();
            l++;
            premistampa++;
        }
        i=listapremi->succlista(i);
    }
    if(premistampa==0)
    {
        cout << "non hai sbloccato nessun premio" << endl;
    }
}

float Premi::ritiraTempo(typename Lista<Premio>::posizione i)
{
    float tempo_bonus = listapremi->leggilista(i).getPremio_T();
    return(tempo_bonus);
}

int Premi::ritiraOggetto(typename Lista<Premio>::posizione i)
{
    int oggetto_bonus = listapremi->leggilista(i).getPremio_O();
    return(oggetto_bonus);
}

Lista<Premio>* Premi::getListaPremi()
{
    return listapremi;
}
