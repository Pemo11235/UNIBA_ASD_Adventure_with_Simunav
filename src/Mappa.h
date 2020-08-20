#ifndef MAPPA_H
#define MAPPA_H

//#include <conio.h>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>
#include <ctype.h>
#include <fstream>
#include "Luogo.h"
#include "Via.h"
#include "Pila.h"
#include "Coda.h"
#include "Prioricoda.h"
#include "Grafo.h"
#include "Nalbero.h"
#include "Interfaccia.h"
#include "Nodo_etichetta.h"
#include "Nodo_predecessore.h"
#include "Nodo_cursore.h"
#include "Zaino.h" // Modifica_ML

class Mappa
{
public:

    //definizioni di tipo
    typedef Luogo etichetta;
    typedef Via peso;

    //costruttore
    Mappa();
    Mappa(ifstream&,fstream&);

    //distruttore
    ~Mappa();

    //metodi
    void scrivipartenza(); //setta il nodo di partenza
    void scriviarrivo(); //setta il nodo di arrivo
    string legginomepartenza(); //restituisce il nome del nodo di partenza
    string legginomearrivo(); //restituisce il nome del nodo di arrivo
    typename Grafo<etichetta,peso>::nodo nodo_da_input(string); //cerca se esiste un nodo con nome, o situato nella via, passato in input
    typename Grafo<etichetta,peso>::nodo nodo_da_input(string,int); //cerca se esiste un nodo situato nella via, con numero civico, passato in input
    void cammino_ottimo(); //calcola cammino migliore (secondo le opzioni impostate)
    void cambia_opzioni(); //cambia le opzioni per il calcolo del cammino migliore
    void salvacronologia(fstream&); //salva la cronologia delle partenze e degli arrivi su file
    void cronologia(); //setta il nodo di partenza o arrivo a partire dalla cronologia
    void canccronologia(); //cancella la cronologia delle partenze o degli arrivi

    // Inizio modifica Angelo Petronelli
    int luogo_adiacente(int,int);
    Luogo get_luogo(int);       // dato l'id del luogo restituisce il luogo
    string get_nome_luogo(int);    // restituisce il nome del luogo
    void set_partenza_gioco(int);        // setta il luogo di partenza passandogli luogo_attuale - 1
    void set_destinazione_gioco(); //setta la destinazione al luogo fittizzio
    // fine modifica
    int inizio_mappa;

private:

    // Inizio modifica Angelo Petronelli
    Interfaccia interfaccia;
    // fine modifica

    //definizioni di tipo
    typedef Nodo_etichetta< Grafo<etichetta,peso>::nodo,etichetta > riferimento; //coppia etichetta-nodo
    typedef Nodo_predecessore< Grafo<etichetta,peso>::nodo > nodo_prec; //tipoelem del vettore di predecessori T restituito da Dijkstra
    typedef Nodo_cursore< Grafo<etichetta,peso>::nodo > nodo_cur; //tipoelem della coda con priorità S in Dijkstra

    //attributi
    Grafo<etichetta,peso>* mappa; //la mappa del navigatore che sarà popolata con i dati da file
    Grafo<etichetta,peso>::nodo* fittizio; //nodo fittizio che si usa nel caso di ricerche con esito negativo o annullamenti
    riferimento* riferimenti; //vettore che contiene le coppie nodo-etichetta
    unsigned int numnodi; //dimensione del vettore riferimenti (ovvero numero di nodi della mappa)
    Grafo<etichetta,peso>::nodo partenza; //luogo di partenza per il calcolo del camminominimo
    Grafo<etichetta,peso>::nodo arrivo; //luogo di arrivo per il calcolo del camminominimo
    bool distanza_tempo; //true=distanza,false=tempo --+
    bool evita_sterrato,evita_pedaggi; //     ---------+----- attributi per il criterio su cui è applicato dijkstra
    nalbero<char> na; //albero ennario che contiene tutti i luoghi e le vie della mappa volto alla ricerca dei suggerimenti
    nalbero<char>::nodo n; //nodo che si usa per la ricerca dei suggerimenti all'interno dell'albero
    Pila<string> partenze; //pila contenente la cronologia dei luoghi e vie di partenza
    Pila<string> arrivi; //pila contenente la cronologia dei luoghi e vie di arrivo
    Lista<char*>* ins;

    //metodi
    string estrai(string,int&,char); //metodo per l'estrazione di tutte le parole di una linea di testo separati da un carattere a scelta
    string minuscolo(string); //rende tutta la stringa con caratteri minuscoli
    bool multi_string_matching(string,string); //string matching "multiplo"
    Grafo<etichetta,peso>::nodo nodo_da_id(etichetta::ID); //dato il campo ID dell'etichetta di un nodo, ne restituisce il nodo
    nodo_prec* Dijkstra(Grafo<etichetta,peso>::nodo); //applica l'algoritmo di Dijkstra restituendo il vettore (albero )di predecessori radicato nel nodo passato
    Pila< Grafo<etichetta,peso>::nodo > cammino_da_dijkstra(nodo_prec*,Grafo<etichetta,peso>::nodo); //dato il vettore di predecessori, resituisce il cammino dalla radice al nodo passato
    void indicazioni(Coda< Grafo<etichetta,peso>::nodo >); //stampa il cammino su video (che era memorizzato su file)
    void indicazioni_file(ofstream&,Pila< Grafo<etichetta,peso>::nodo >,Grafo<etichetta,peso>::nodo,Grafo<etichetta,peso>::nodo); //stampa il cammino su video e su file (perchè su file non esiste)

    void setsuggerimenti(ifstream&); //costruisce l'albero dei suggerimenti da file
    string getsuggerimenti(string,string); //ritorna la stringa presa in input o scelta tra i suggerimenti messi a disposizione e ne stampa a video i risultati in tempo reale
    void setcronologia(fstream&); //carica la cronologia salvata in un file
    void aggiungiacrono(string); //aggiungi partenza o destinazione appena digitata nella cronologia
    int stampacrono(string); //stampa la cronologia delle partenze o delle destinazioni ritornando il numero degli elementi
    void settapartenzacrono(); //setta la partenza da quelle disponibili nella cronologia delle partenze
    void settaarrivocrono(); //setta la destinazione da quelle disponibili nella cronologia delle destinazioni
    bool ritornafrase(char*,nalbero<char>::nodo); //ritorna true se è stata trovato un percorso non visitato dal nodo dato in input a una foglia, false altrimenti
    bool ritornaparola(char*,nalbero<char>::nodo); //ritorna true se è stata trovato un percorso non visitato dal nodo dato in input a una foglia o ad un nodo che contiene uno spazio, false altrimenti
    void ricercanodo(int&,nalbero<char>::nodo*,char,nalbero<char>::nodo); //cerca all'interno dell'albero se è presente un nodo avente l'elemento passato in input
    void epurazione(); //elimina eventuali parole presenti più di una volta all'interno della lista di quelle trovate nell'albero durante la ricerca dei suggerimenti
    void inssottoalbero(char,nalbero<char>::nodo&,nalbero<char>::nodo&); //inserisce il nodo la cui posizione sarà identificata da due nodi
    bool controllo(char,nalbero<char>::nodo&); //ritorna true se tra i fratelli del nodo passato in input c'è lo stesso elemento passato anch'esso in input, false altrimenti
};



#endif
