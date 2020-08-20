#include "Negozio.h"

Negozio::Negozio()
{

}

Negozio::Negozio( Servizi_Lista<Oggetto> ogg )
{
    oggetti= ogg;
}
// MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
float Negozio::acquista( int codice, Interfaccia& interfaccia, float& contanti,float& conto_corrente, Oggetti& inventario, string metodo )
{
    float somma;
    if (metodo == "portafoglio")
    {

        for( int i = 0; i < oggetti.count(); i++ )
        {
            Oggetto og = oggetti.get( i );

            if( codice == og.get_codice() )
            {

                if( contanti >= og.get_prezzo() )
                {

                    sottrai(&somma,og.get_prezzo());
                    inventario.set_luogo( inventario.get_oggetto_indice_by_codice( codice ), 0 );
                    oggetti.cancLista( i );
                    interfaccia.scrivi( "\n Acquisto riuscito tramite : Denaro Contante \n" );
                    parla(interfaccia);
                }
                else
                {
                    interfaccia.scrivi( "Non hai abbastanza contante per effettuare l'acquisto" );
                    break;
                }
            }
        }
    }

    if (metodo == "carta")
    {
        for( int i = 1; i < oggetti.count(); i++ )
        {
            Oggetto og = oggetti.get( i );

            if( codice == og.get_codice() )
            {

                if( conto_corrente >= og.get_prezzo() )
                {

                    sottrai(&somma,og.get_prezzo());
                    inventario.set_luogo( inventario.get_oggetto_indice_by_codice( codice ), 0 );
                    oggetti.cancLista( i );
                    interfaccia.scrivi( "\n Acquisto riuscito tramite : Carta di Credito \n" );
                    parla(interfaccia);
                }
                else
                {
                    interfaccia.scrivi( "Non hai abbastanza credito per effettuare l'acquisto" );
                    break;
                }
            }
        }
    }
    return somma;

}

void Negozio::inserisci(Oggetto oggetto)
{
    oggetti.insListaCoda(oggetto);
}

void Negozio::inserisci( Oggetto oggetto, float prezzo )
{
    oggetto.set_prezzo( prezzo );
    inserisci( oggetto );
}

void Negozio::parla(Interfaccia& interfaccia)
{
    interfaccia.scrivi("Benvenuto nel mio negozio");
    if( oggetti.count() > 0 )
    {
        interfaccia.scrivi("Questi sono gli articoli disponibili:");
        for( int i = 0; i < oggetti.count(); i++ )
        {
            Oggetto og = oggetti.get(i);
            interfaccia.scrivi_parziale( " - " );
            interfaccia.scrivi_parziale( og.get_nome() );
            interfaccia.scrivi_parziale( ", prezzo: " );
            interfaccia.scrivi_float( og.get_prezzo() );
            interfaccia.scrivi( /*" dollari"*/ " Euro " ); //MODIFICA D-R(Pisani)
        }
    }
    else
        interfaccia.scrivi("Spiacente, ho esaurito le scorte");
}
