#include "Stato.h"


Stato::Stato() {}

Stato::~Stato() {}

void Stato::set_luogo(int l)
{
    luogo_attuale=l;
}

void Stato::set_passo(int p)
{
    passo_soluzione=p;
}

void Stato::set_tempo(int t)
{
    tempo=t;
}

void Stato::set_ogg(int og[])  //get_ogg deve restituire il vettore della classe Stato
{
    for (int i = 0; i <MAX; i++)
    {
        oggetti[i]=og[i];
    }

}

void Stato::set_parete_stagna(int ps)
{
    parete_stagna=ps;
}

void Stato::set_cabina(int cb)
{
    cabina=cb;
}

int Stato::get_luogo()
{
    return luogo_attuale;
}

int Stato::get_passo()
{
    return passo_soluzione;
}

int Stato::get_tempo()
{
    return tempo;
}

int* Stato::get_ogg()
{
    /*La get prenderà il vettore dalla classe Stato e lo
                            passerà alla funzione associata a indietro per ripristinare la posizione degli oggetti*/
    return oggetti;
}

int Stato::get_parete_stagna()
{
    return parete_stagna;
}

int Stato::get_cabina()
{
    return cabina;
}

bool Stato::stato_completo()
{
    bool valore = true;
    if (is_null(parete_stagna))
        valore = false; // controlla lo stato della parete stagna; se è NULL, cioè il valore = 0,lo stato sarà incompleto;
    if (is_null(luogo_attuale))
        valore = false;
    if (is_null(tempo))
        valore = false;
    if (is_null(passo_soluzione))
        valore = false;
    if (is_null(cabina))
        valore = false;
    if (is_null(oggetti, MAX))
        valore = false;
    return valore;
}



bool Stato::is_null(int a)
{
    return a == NULLV; // se a è nullo, mi da true, false altrimenti
}


bool Stato::is_null(int a[], int dim)
{
    return controllo_array(a, dim);     // la utilizzo per l array di oggetti
}


void Stato::unisci(Stato s2)              // s2 è lo stato con cui unirò quello attuale
{
    if (is_null(parete_stagna))
    {
        set_parete_stagna (s2.get_parete_stagna());
    }

    if (is_null(luogo_attuale))
    {
        set_luogo (s2.get_luogo());
    }

    if (is_null(tempo))
    {
        set_tempo (s2.get_tempo());
    }

    if (is_null(passo_soluzione))
    {
        set_passo (s2.get_passo());
    }

    if (is_null(cabina))
    {
        set_cabina (s2.get_cabina());
    }

    if (is_null(oggetti, MAX))
    {
        set_ogg (s2.get_ogg());
    }

}

void Stato::differenza(Stato s2, int num)    // int num è il numero degli oggetti memorizzati nel vettore
{
    bool elem = true; // supponiamo che gli elementi dell' array oggetti di s2 (stato più recente) e s(stato appena creato) siano gli stessi
    if(parete_stagna == s2.get_parete_stagna())
        parete_stagna = NULLV;
    if(luogo_attuale == s2.get_luogo())
        luogo_attuale = NULLV;  // se  luogo attuale = al luogo dell ultimo stato della pila, luogo_attuale = null, cioè non è cambiato
    if(tempo == s2.get_tempo())
        tempo = NULLV;
    if(passo_soluzione == s2.get_passo())
        passo_soluzione = NULLV;
    if(cabina == s2.get_cabina())
        cabina = NULLV;

    for (int i=0; i<= num && elem == true; i++)
    {
        if(oggetti[i] != s2.get_ogg()[i])
        {
            elem = false; //almeno uno è diverso
        }
    }
    if (elem)
        svuota_array(oggetti, MAX); // non è cambiato lo stato; svuota array rende nulli tutti gli elementi dell array
}
