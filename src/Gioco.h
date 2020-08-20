#ifndef GIOCO_H
#define GIOCO_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "StatoSalute.h"
#include "ServizioTrasporti.h"
#include "Agenda.h" //Modifica PMF (agenda)
using namespace std;
#include "Dizionario.h"
#include "Mappa.h"
#include "Grafo.h"
#include "Oggetti.h"
#include "Interfaccia.h"
#include "Stato.h"
#include "Pila.h"
#include "stato_comando.h"
#include "Bacheca.h"
#include "enigma.h"		//Modifica PMF(enigma)
#include "Motorino.h"
#include "storia.h" 	//Modifica PMF(storia)
#include "Documenti.h"	//Modifica PMF(ufficio)

#include "Negozio.h"  //MODIFICA D-R(D'Orsi):Negozio + Banca
#include "Banca.h"	  //MODIFICA D-R(D'Orsi):Negozio + Banca

#include "Portafoglio.h"    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
#include "CartadiCredito.h" //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito

#include "Lista.h"
#include "Premio.h"
#include "Premi.h"

#include "Insieme.h" //MODIFICA Zagaria // aggiunta la classe Insieme
#include "Personaggi.h"  //MODIFICA Zagaria // aggiunta la classe Personaggi

#include "Canzone.h" //MODIFICA VACCA GIANLUCA, Canzoni per il Jukebox nell'auditorium
#include "Luce.h" //MODIFICA VACCA GIANLUCA
//START DAMONE
#include "rubrica.h"  // Modifica  Francesco De Giorgio
//END DAMONE

#include "UfficioPostale.h" //Modifica Galeandro - Aggiunta classe UfficioPostale

//INIZIO modifica PALAGIANO MARCELLO
#include "Batteria.h" // Batterie che si trovano nel luogo Meccanico
#include "Attivita.h" // Contenuto del diario nel luogo Meccanico
//FINE modifica PALAGIANO MARCELLO

#include "Automobile.h" //Modifica DELLA FOLGORE GRAZIA
#include "Autobus.h"    //Modifica DELLA FOLGORE GRAZIA

#include "Palestra.h" //MODIFICA DAVIDE MANTELLINI
#include "Valigia.h" //_Modifica_ML
#define MAXSTRINGA 50
#define MAXPILA 3


class Gioco
{
public:

    Gioco();
    ~Gioco();
    Storia stampaStoria(); //Modifica PMF(storia)
    void ciak(Mappa&, ifstream &f);
    bool attiva_enigmi();                                        //Modifica D-R(D-R):da la possibilit� di disattivare/attivare gli enigmi all'inizio del gioco
    void switch_enigmi(int a, Mappa &M, Pila <stato_comando>* p, Personaggi* pg); //Modifica D-R(D-R) // modifica zagaria -- aggiunto il parametro personaggi pg
    void caricafile();
    bool leggienigma();
    //Modifica Francesco Cosma - Premi
    Premi premi;
    void init_premi();
    void aggiorna_premi();
    void aggiorna_progresso();
    bool ris_esatta;
    bool algor;
    bool messaggio_b;

    Premio enigmista;
    Premio spazio;
    Premio tuta;
    Premio casco;
    Premio radiazioni;
    Premio pronto_soccorso;
    Premio annuncio;
    Premio perso;
    Premio asd;

    void carica_trasporti();
    void trasporto(int n);

protected:
    ServizioTrasporti servizio_trasporti;
    StatoSalute Salute; //MODIFICA MICHELE ALBANO
    Dizionario<int, Ferita> Ferite; //MODIFICA MICHELE ALBANO


    // variabili globali (usate dalle azioni)
    Interfaccia interfaccia;
    int k;
    // int tempo;
    float tempo;

    bool gioco_impiccato; //MODIFICA BASILE ANTONIO
    bool gioco_preside; //MODIFICIA BASILE ANTONIO
    bool gioco_prof_mara; //MODIFICA BASILE ANTONIO
    bool gioco_prof_clara; //MODIFICA BASILE ANTONIO



//MODIFICA VACCA
    Canzone canzone; //MODIFICA VACCA GIANLUCA - Inizializzazione classe canzone
    Lista<Canzone> canzoni; //MODIFICA VACCA GIANLUCA - Inizializzazione della lista di canzoni del Jukebox
    Lista<Canzone>::posizione canzoneScelta; //MODIFICA VACCA GIANLUCA
    bool jukeboxAttivo;
    int canzoneInRiproduzione; //Serve per il salvataggio del brano in riproduzione.
    Coda<Canzone> playlist; //Salva la playlist dei brani ascoltati

    Luce luce;
    Insieme<Luce> luciAuditoriumAccese; //MODIFICA VACCA GIANLUCA - permette di vedere quali sono le luci accese dell'auditorium
    string nome_luci_auditorium[6] = {"fittizio","sulla destra, avanti","sulla sinistra, avanti","sulla destra, dietro","sulla sinistra, dietro","sul palco"}; //MODIFICA VACCA - array di stringhe dei nomi delle luci
//FINE MODIFICA VACCA

    Pila<string> Luogo_p;                   //MODIFICA POLIMENA
    Pila<int> Codice_luogo;                 //MODIFICA POLIMENA

    string parola2; // MODIFICA Zagaria -- aggiunta inizializzaizone della nuova parola parola2
    int luogo_attuale;
    int og;              // oggetto
    int passo_soluzione; // contatore soluzione
    int cod_parola1;     // codice prima parola comando

    // variabili necessarie per la strutturazione
    bool fine_partita;
    bool riparti;        // per rigiocare alla fine della partita
    bool salito;
    string fStringa;     // file situazione
    Dizionario<string, int> vocabolario;
    Mappa mappa;
    Dizionario<int, int> azioni;
    Oggetti oggetti;
    Bacheca bacheca;
    bool v_passato; //modifica Gallone - servir� per la risoluzione del bug
    // Inizio modifica Gallone
    int sazio; //dichiaro il parametro vitale
    Lista<int> zaino_frigo; //inizializzazione lista cibi
    Lista<int> tasca; //inizializzazione buoni pasto
    typename Lista<int>::posizione riferimento_tasca;
    typename Lista<int>::posizione riferimento_zaino;
    // Fine modifica Gallone

    //Modifica PMF(ufficio)
    Documenti primo_doc;
    bool ritirato; //per consegna e ritira documento
    //Modifica PMF: fin qui.


    //Modifica PMF(storia)
    Storia storia_gioco;
    string stringa_comando;
    string stringa_risposta;
    //Modifica PMF: fin qui.

    //istanzio il motorino
    Motorino motorino ;

    //INIZIO modifiche DELLA FOLGORE GRAZIA
    Autobus autobus;
    Automobile automobile;
    //FINE modifiche DELLA FOLGORE GRAZIA



    //inizio modifiche zagaria --inserimento dell' insieme personaggi
    Dizionario<int, Personaggi> insPersonaggi;
    Personaggi pg;
    int luogo_precedente;
    bool presente2;
    int index;
    //fine modifiche

    //STAT DAMONE
// Modifica Francesco De Giorgio
    // dichiarazioni che permettono il funzionamento della rubrica

    Rubrica persone;
    Lista<Rubrica> rubrica;
    Lista<Rubrica>::posizione persona;
    // fine modifica Francesco De Giorgio
    //START DAMONE


    //MODIFICA D-R(D'Orsi):Negozio + Banca
    Negozio negozio;
    Banca banca;
    float somma;		  //appoggio per le transazioni
    int comando_oggetto;

    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    Portafoglio portafoglio;
    Carta_di_Credito carta;

    //Modifica Galeandro - Creazione dell'oggetto ufficiopostale
    UfficioPostale ufficiopostale;

    //MODIFICA Davide Mantellini -Creazione dell'oggetto Statofisico che implementa le caratteristiche fisiche del personaggio
    StatoFisico sFisico;

    //MODIFICA Cicala
    Insieme<int> slotmachine;
    int numEuro;

    //INIZIO modifiche PALAGIANO MARCELLO
    Batteria batteria;
    Pila<Batteria> batterie;
    Pila<Batteria> batterie_scariche;
    Pila<Batteria> batterie_appoggio;
    Attivita attivita;
    Lista<Attivita> elenco;
    Lista<Attivita>::posizione attivitaSelezionata;
    Personaggi cliente;
    Coda<Personaggi> coda_attesa;
    Coda<Personaggi> codaa_appoggio;
    bool batteria_cambiata;
    //FINE modifiche PALAGIANO MARCELLO



    // Modifiche ML
    Pila<int> p;
    Pila<int> z;
    int n_oggettiZ;     //Numero di oggetti nello zaino
    int peso_MaxZ;      //Peso massimo trasportabile nello zaino
    Insieme<int> ins;
    int n_oggettiZV;    //Numero di oggetti nella valigia
    int peso_MaxZV;     //Peso massimo trasportabile nella valigia
    //el1=primo elemento zaino; el2=secondo elemento zaino;
    //el3 [..] el6 elementi valigia
    int el1;
    int el2;
    int el3;
    int el4;
    int el5;
    int el6;
    bool salva;         //Boooleano usato nella save e nella load
    string risposta1;   //risposta al frammento
    bool controllo1;
    bool controllo2;
    Lista<int> L;
    //Fine_Modifiche_ML

    // metodi
    void init();
    int estraipar(string, int, int *, string *);
    void morto();
    void aggiorna_tempo();
    void errore();
    void prendi();
    void lascia();
    void guarda();
    void save();
    void load();
    void cosa();
    void indietro(Pila<stato_comando>*); //*
    void memorizza_comandi(string, Pila<stato_comando>*,Stato); //*
    void correggi_Pila (Pila<stato_comando>*);
    void visualizza_bacheca();
    void cancella_mess_bacheca_specifiche();
    void inserisci_mess_bacheca_specifiche();
    // Inizio modifica Angelo Petronelli
    void interpreta(string, Mappa&,Pila<stato_comando>*, Stato,bool si);
    bool esegui_azione(int, int, Mappa&,Pila<stato_comando>*, bool si);
    bool esegui_azione(int, int, Mappa&,Pila<stato_comando>*, bool si, Personaggi*);  // MODIFICA Zagaria -- aggiunto paramentro personaggi
    void esegui(int a, Mappa &M, Pila<stato_comando>*,bool si, Personaggi*); // MODIFICA Zagaria -- aggiunta personaggi parametro pg personaggi
    void navigatore(Mappa&);
    void macchinadeltempo();
    bool direzioni(Mappa&);
    void benzina();		 // inserimento metodo benzina
    void usa_motorino(); // inserimento metodo motorino
    void Aggiorna_Ferite(); //GESTORE DELLE FERITE(MICHELE ALBANO)
    //Modifica PMF(agenda)
    void azione_46(); // azione che richiama il sottoprogramma CancellaAgenda dell classe Agenda
    void azione_47(); // azione che richiama il sottoprogramma ScriviAgenda  della classe Agenda
    void azione_48(); // azione che richiama il sottoprogramma LeggiAgenda  della classe Agenda
    void azione_118();
    //Modifica PMF: fin qui.

//inizio modifiche ROSA CHIARAPPA

    void ruba();
    void rubati();
    void aggiorna_luogo_carabiniere(int);
    bool verifica_presenza_carabiniere(int);
    void perquisizione_giocatore(int&);

//fine modifiche ROSA CHIARAPPA

    // VIRTUAL
    virtual void setCabina(int); //*
    virtual void setParete(int); //*
    virtual int getCabina(); //*
    virtual int getParete(); //*
    virtual void aggiorna_specifiche(); //biblioteca
    virtual bool esegui_specifiche(int,Mappa&);
    // Fine modifica

    //inizio modifiche zagaria -- aggiunte le dichiarazioni di funzioni relative ai personaggi
    void parla(Personaggi);
    void az_parla(Personaggi);
    int controlla();
    void initPers(Dizionario<int, Personaggi>*);
    void personaggio_entra();
    void personaggio_esce();
    //fine modifiche



    //inizio modifiche D'Andria Dresda al progetto di Federica Forte
    Dialogo caricaDialoghiDaFile(string);
    void convertiRiga(Dialogo*,string,string);
    int caricastatodialogo(string);
    int leggistato(int*,string, string);
    void scrivistatosufile(string, int);
    bool verificanome(string,string);
    void salvaStatiDialoghi();
    void caricaStatiDialoghi();
    //fine modifiche

    //MODIFICA VACCA GIANLUCA
    void salvaJukeBoxLuci(); //metodo per salvare lo stato del Jukebox e delle luci
    void caricaJukeBoxLuci(); //metodo per caricare lo tato del Jukebox e delle luci

    // VIRTUAL
    virtual void init_specifiche();
    virtual void introduzione();
    virtual void tempo_specifiche();
    virtual bool prendi_specifiche();
    virtual bool preso_specifiche();
    virtual bool lascia_specifiche();
    virtual void save_specifiche(ofstream &);
    virtual void load_specifiche(ifstream &);
    virtual void epitaffio();
    virtual void futuro();
    virtual void passato();
    virtual void presente();
    virtual bool mappaaperta();
    //void encomio();

    //Modifica PMF(enigmi)
    Lista <enigma> enigmi;
    int n_enigmi;
    string estrai_f(string, int&, char);

    //START DAMONE
    //modifica Francesco De Giorgio : RUBRICA
    void consulta();
    void inserisci();
    void cerca();
    // Modifica De Giorgio : fin qui.

    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    void Aggiorna_Tempo_bonus();//bonus tempo
    bool biglietto_museo();//acquisto biglietto
    void mostra_galleria_a();//esplorazione galleria a
    void mostra_galleria_b();//esplorazione galleria b
    void mostra_galleria_c();//esplorazione galleria c
    void mostra_galleria_d();//esplorazione galleria d
    //FINE MODIFICHE DEL GIUDICE ANGELO



};


#endif
