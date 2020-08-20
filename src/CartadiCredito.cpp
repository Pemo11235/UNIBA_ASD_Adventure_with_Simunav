/*
 * CartadiCredito.cpp
 *
 *  Created on: 15/set/2014
 *      Author: Ivano
 */

#include "CartadiCredito.h"

Carta_di_Credito::Carta_di_Credito() {}

Carta_di_Credito::~Carta_di_Credito() {}

bool Carta_di_Credito::hai_Carta(Oggetti oggetti)
{
    bool trovato = false;

    for(int i = 1; i <= oggetti.get_n_oggetti(); i++)
    {

        if(oggetti.posizionati_in(0).get_oggetto(i).get_nome() == "una carta di credito" )
        {
            trovato = true;
        }
    }
    return trovato;
}

bool Carta_di_Credito::acquista_Carta(Oggetti &oggetti, int comando_oggetto, Interfaccia &interfaccia, Negozio &negozio, Portafoglio &portafoglio)
{
    bool trovatoP = false;
    trovatoP = portafoglio.hai_Portafoglio(oggetti);
    bool trovatoC = false;
    trovatoC = hai_Carta(oggetti);
    float conto = portafoglio.get_contanti();
    float contcorr = portafoglio.get_contocorrente();
    float somma;

    if(trovatoP)
    {
        if(trovatoC)
        {
            string metodo = "carta";
            somma = negozio.acquista( comando_oggetto, interfaccia, conto,contcorr, oggetti, metodo );
            contcorr += somma;
            portafoglio.set_contocorrente(contcorr);
            trovatoC = true;
        }
        else
        {
            interfaccia.scrivi(" Prima di effettuare acquisti devi prendere la Carta di Credito ! ");
        }

    }
    else if(!trovatoP)
    {
        interfaccia.scrivi(" Prima di effettuare acquisti devi prendere il Portafoglio ! ");
    }

    return trovatoC;
}

float Carta_di_Credito::get_contocorrente(Portafoglio &portafoglio) const
{
    return portafoglio.get_contocorrente();
}

void Carta_di_Credito::set_contocorrente(Portafoglio &portafoglio,float &conto)
{
    portafoglio.set_contocorrente(conto);
}
