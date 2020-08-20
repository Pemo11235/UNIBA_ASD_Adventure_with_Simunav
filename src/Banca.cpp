
#include "Banca.h"


Banca::Banca()
{

}

Banca::Banca(Servizi_Lista<Oggetto> ogg )
{
    oggetti= ogg;
}

void Banca::parla(Interfaccia& interfaccia)
{
    interfaccia.scrivi("Benvenuto nella banca dell'astronave");
    interfaccia.scrivi("");
    interfaccia.scrivi("Scegli l'operazione da fare:");
    interfaccia.scrivi("- Deposita denaro sul tuo conto");
    interfaccia.scrivi("- Preleva denaro dal tuo conto");
    interfaccia.scrivi("- Controlla il saldo prelevabile presente sul tuo conto");
    interfaccia.scrivi("- Controlla la tua cassetta di sicurezza");
    interfaccia.scrivi("- Deposita un oggetto nella cassetta di sicurezza");
    interfaccia.scrivi("- Ritira un oggetto dalla cassetta di sicurezza");
}

void Banca::deposita(float& contanti,float& conto_corrente,Interfaccia& interfaccia)
{
    float somma;


    somma = interfaccia.leggi_float("Quanto vuoi depositare? ");
    if(somma<=contanti)
    {

        sottrai(&contanti,somma);
        aggiungi(&conto_corrente,somma);
        interfaccia.scrivi( "Operazione riuscita correttamente " );
        interfaccia.scrivi_parziale("Hai depositato ");
        interfaccia.scrivi_float(somma);
        interfaccia.scrivi(/*" dollari"*/ " Euro "); // MODIFICA D-R(Pisani)

    }
    else
    {
        interfaccia.scrivi( "Non hai abbastanza contante per effettuare l'operazione" );
    }



}

void Banca::preleva(float& contanti,float& conto_corrente,Interfaccia& interfaccia)
{
    float somma;


    somma = interfaccia.leggi_float("Quanto vuoi prelevare? ");
    if(somma<=conto_corrente)
    {

        sottrai(&conto_corrente,somma);
        aggiungi(&contanti,somma);

        interfaccia.scrivi( "Operazione  riuscita correttamente" );
        interfaccia.scrivi_parziale("Hai prelevato ");
        interfaccia.scrivi_float(somma);
        interfaccia.scrivi(/*" dollari"*/ " Euro ");  // MODIFICA D-R(Pisani)

    }
    else
    {
        interfaccia.scrivi( "Non hai abbastanza denaro sul conto per effettuare l'operazione" );
    }


}

void Banca::lascia_oggetto( Oggetto oggetto)
{


    oggetti.insListaTesta(oggetto);
}

void Banca::mostra_oggetto(Interfaccia& interfaccia)
{

    if( oggetti.count() > 0 )
    {
        interfaccia.scrivi("All'interno della cassetta vedo:");
        for( int i = 0; i < oggetti.count(); i++ )
        {
            Oggetto og = oggetti.get(i);
            interfaccia.scrivi_parziale( " - " );
            interfaccia.scrivi( og.get_nome() );

        }
    }
    else
        interfaccia.scrivi("La sua cassetta di sicurezza e' vuota");

}

void Banca::ritira_oggetto( int codice, Interfaccia& interfaccia, Oggetti& inventario )
{
    bool trovato = false;

    for( int i = 0; i < oggetti.count(); i++ )
    {
        Oggetto og = oggetti.get( i );

        if( codice == og.get_codice() )
        {
            trovato = true;


            inventario.set_luogo( inventario.get_oggetto_indice_by_codice( codice ), 0 );

            oggetti.cancLista( i );
            interfaccia.scrivi( "Fatto\n" );
            parla(interfaccia);


            break;
        }
    }
    if( !trovato )
        interfaccia.scrivi( "L' oggetto richiesto non e' disponibile" );
}
