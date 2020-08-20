/*
 * Portafoglio.cpp
 *
 *  Created on: 15/set/2014
 *      Author: Ivano
 */

#include "Portafoglio.h"

Portafoglio::Portafoglio()
{
    iniz_contante();
}

Portafoglio::~Portafoglio() {}

void Portafoglio::iniz_contante()
{
    contanti = 300.0f;
    conto_corrente = 300.0f;
}

bool Portafoglio::hai_Portafoglio(Oggetti &oggetti)
{
    bool trovato = false;

    for(int i = 1; i <= oggetti.get_n_oggetti(); i++)
    {

        if(oggetti.posizionati_in(0).get_oggetto(i).get_codice() == 34)
        {
            trovato = true;
        }
    }
    return trovato;
}

bool Portafoglio::acquista_Portafoglio(Oggetti &oggetti, int comando_oggetto, Interfaccia &interfaccia,Negozio &negozio)
{
    bool trovato = false;
    trovato = hai_Portafoglio(oggetti);
    float somma;

    if(trovato)
    {
        string metodo ="portafoglio";
        somma = negozio.acquista( comando_oggetto, interfaccia, contanti,conto_corrente, oggetti, metodo );
        contanti += somma;
        trovato = true;
    }
    else if(!trovato)
    {
        interfaccia.scrivi(" Prima di effettuare acquisti devi prendere il portafoglio ! ");
    }

    return trovato;
}
void Portafoglio::Prendi_Banconota(Oggetti &oggetti,int og, Interfaccia &interfaccia)
{
    bool trovato = false;
    float cont = get_contanti();
    trovato = hai_Portafoglio(oggetti);

    if (trovato && (og == 39 || og == 43))
    {
        oggetti.set_luogo(og,0);
        cont += 1;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }
    else if (trovato && (og == 40 || og == 44))
    {
        oggetti.set_luogo(og,0);
        cont += 2;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }
    else if (trovato && og == 36)
    {
        oggetti.set_luogo(og,0);
        cont += 5;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }
    else if (trovato && (og == 37 || og == 41))
    {
        oggetti.set_luogo(og,0);
        cont += 10;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }
    else if (trovato && og == 42)
    {
        oggetti.set_luogo(og,0);
        cont += 20;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }
    else if (trovato && og == 38)
    {
        oggetti.set_luogo(og,0);
        cont += 50;
        set_contanti(cont);
        interfaccia.scrivi(" Fatto! ");
    }


}

float Portafoglio::get_contanti() const
{
    return contanti;
}

float Portafoglio::get_contocorrente() const
{
    return conto_corrente;
}

void Portafoglio::set_contanti(float &contant)
{
    contanti = contant;
}

void Portafoglio::set_contocorrente(float &conto)
{
    conto_corrente = conto;
}

