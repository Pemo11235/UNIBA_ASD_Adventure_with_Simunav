#include "StatoSalute.h"
#include <cstdlib>
StatoSalute::StatoSalute()
{
    Salute=100;
    PenalitaMosse=0;
}

bool StatoSalute::Ferito()
{
    return(Ferite.listavuota()==false);
}

void StatoSalute::Cura()
{
    if(Ferito()==true) //Precondizione: se sei Ferito, Cancella tutte le Ferite e ripristina lo stato di Salute iniziale
    {
        Lista<Ferita>::posizione pos, pos1;
        pos=Ferite.primolista(); //Posizionati sul primo elemento
        pos1=Ferite.succlista(pos); //Posizionati sull'elemento successivo
        while(Ferite.finelista(pos)!=true)
        {
            Ferite.canclista(pos); //Cancella l'elemento corrente
            pos=pos1; //Aggiorna l'elemento corrente con il suo successivo
            pos1=Ferite.succlista(pos); //Acquisisci l'elemento successivo
        }
        Salute=100; //Ripristina Salute
        PenalitaMosse=0; //Azzera Penalit‡Mosse
    }
}


void StatoSalute::SetFerita(Ferita f)
{
    if(Ferita_Contratta(f)!=true) //Precondizione: se non hai gi‡ contratto la Ferita, inseriscila
    {
        Lista<Ferita>::posizione temp = Ferite.primolista();
        Ferite.inslista(f, temp);
    }
}

int StatoSalute::GetPenalita()
{
    return(PenalitaMosse);
}

int StatoSalute::GetStatoSalute()
{
    return(Salute);
}

//INIZIO MODIFICHE GIOVANNI CASTELLANA
void StatoSalute::SetStatoSalute(int saluteattuale)
{
    Salute=saluteattuale;
}

void StatoSalute::Miracolo()
{
    if(Ferito()==true) //Precondizione: se sei Ferito, Cancella la prima Ferita e ripristina lo stato di Salute iniziale
    {

        Lista<Ferita>::posizione pos;
        pos=Ferite.primolista(); //Posizionati sul primo elemento

        Ferite.canclista(pos); //Cancella l'elemento corrente
        pos=Ferite.succlista(pos); //Posizionati sul secondo elemento

    }
    if (Ferito()==true)   //se sei ancora ferito
    {
        Salute=90 + rand()%10; //Imposta la Salute a un valore compreso tra 90 e 99
        PenalitaMosse=1;
    }
    else
    {
        Salute=100; //Ripristina Salute
        PenalitaMosse=0; //Azzera Penalit‡Mosse
    }

}
//FINE MODIFICHE GIOVANNI CASTELLANA

Lista<Ferita> StatoSalute::Get_Ferite()
{
    return(Ferite);
}

void StatoSalute::Aggiorna_Stato()
{
    if(Ferito()==true) //Precondizione: se sei stato ferito, aggiorna lo stato
    {
        int PenalitaSalute=0; //Intero di appoggio utilizzato come sommatoria dei Danni provocati dalle Ferite contratte. Ha funzione di controllore
        Lista<Ferita>::posizione pos=Ferite.primolista(); //Posizionati alla prima Ferita
        while(Ferite.finelista(pos)!=true) //FinchÈ non scandisci tutta la lista, continua
        {
            PenalitaSalute=PenalitaSalute+Ferite.leggilista(pos).GetDannoSalute();
            pos=Ferite.succlista(pos);
        }
        if(PenalitaSalute>Salute)//Se la Penalit‡ Ë maggiore dello Stato Salute, il valore sar‡ negativo ma lo StatoSalute Ë definito nell'intervallo [0,100]. Pertanto, settalo a 0;
            Salute=0;
        else
            Salute=Salute-PenalitaSalute;
        PenalitaMosse=4-(Salute/25); //Funzione definita nella Documentazione
    }
}

bool StatoSalute::Ferita_Contratta(Ferita f)
{
    bool trovato=false;
    Lista<Ferita>::posizione pos=Ferite.primolista(); //Posizionati alla prima Ferita
    while(Ferite.finelista(pos)!=true && trovato!=true && Ferite.listavuota()!=true) //FinchÈ non scandisci tutta la lista o non trovi l'elemento, continua
    {
        if(Ferite.leggilista(pos).GetCodice()==f.GetCodice()) //Se il codice della Ferita inserito corrisponde con il codice della nuova Ferita, la Ferita Ë gi‡ stata contratta e non deve essere reinserita
            trovato=true;
        else
            pos=Ferite.succlista(pos);
    }
    return(trovato);
}
