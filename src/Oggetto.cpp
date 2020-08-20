#include "Oggetto.h"

Oggetto::Oggetto()
{
    luogo = -1;
    rubato = false;           //modifica ROSA CHIARAPPA

}

Oggetto::Oggetto(string n, int c, int l, int w)
{
    nome = n;
    codice = c;
    luogo = l;
    peso = w;
    rubato = false;           //modifica ROSA CHIARAPPA

}

//Inizio Modifica Gallone - Inserimento del nuovo costruttore dedicato ai cibi
Oggetto::Oggetto(string n, int c, int l,int w, int v, string cat)
{
    nome = n;
    codice = c;
    luogo = l;
    peso = w;
    valore_e = v;
    category = cat;
    rubato = false;         //modifica ROSA CHIARAPPA

}

//modifica Gallone - Inserimento del nuovo costruttore dedicato agli oggetti 'Buoni Pasto'
Oggetto::Oggetto(string n, int c, int l,int w, string cat)
{
    nome = n;
    codice = c;
    luogo = l;
    peso = w;
    category = cat;
    rubato = false;      //modifica ROSA CHIARAPPA

}
//modifica Gallone
//Realizzazione della metodo usato per prelevare il valore energetico del cibo e renderlo disponibile ad altri utilizzi
int Oggetto::get_valore_e()
{
    return valore_e;
}

//modifica Gallone
//Realizzazione del metodo get_categoria utilizzato per confrontare le categorie di oggetti durante l’azione compra
string Oggetto::get_categoria()
{
    return category;

}

//Fine Modifica Gallone

//MODIFICA D-R(D'Orsi):Negozio + Banca// oggetto vendibile con un certo prezzo
Oggetto::Oggetto(string n, int c, int l,int w, float p)
{
    nome = n;
    codice = c;
    luogo = l;
    peso = w;
    prezzo = p;
    rubato = false;   //modifica ROSA CHIARAPPA

}
//START DAMONE
/*Oggetto::Oggetto(string n, int c, int l, string d) {
	nome = n;
	codice = c;
	luogo = l;
	descrizione = d;
}*/





//inizio modifiche ROSA CHIARAPPA

void Oggetto::set_rubato(bool r)
{
    rubato = r;
}
bool Oggetto::get_rubato()
{
    return rubato;
}

//fine modifiche ROSA CHIARAPPA






string Oggetto::get_nome()
{
    return nome;
}

int Oggetto::get_codice()
{
    return codice;
}

int Oggetto::get_luogo()
{
    return luogo;
}
string Oggetto::get_descrizione()
{
    return descrizione;
}

void Oggetto::set_luogo(int &l)
{
    luogo = l;
}

void Oggetto::set_luogo_n(int lg) 	//Modifica DELLA FOLGORE GRAZIA
{
    luogo = lg;
}
void Oggetto::set_isVeicolo(bool b) 	//Modifica DELLA FOLGORE GRAZIA
{
    veicolo = b;
}
bool Oggetto::is_Veicolo() 		//Modifica DELLA FOLGORE GRAZIA
{
    return veicolo;
}

//MODIFICA D-R(D'Orsi):Negozio + Banca
float Oggetto::get_prezzo()
{
    return prezzo;
}

void Oggetto::set_prezzo( float p )
{
    prezzo = p;
}

//Modifica ML
int Oggetto::get_peso()
{
    return peso;
}
