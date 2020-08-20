#include "Astro.h"
#include "Interfaccia.h"
#include "Museo.h"
//#include "Lista.h"
#include "Listaa.h"  //MODIFICA DELLA FOLGORE GRAZIA
#include "Insieme.h"
#include <string>  //Modifica PMF(ufficio)
#include <cstring> //Modifica PMF(ufficio)

#include <iostream> //MODIFICA D-R(Colturi):Luoghi a Pagamento
#include <fstream> //MODIFICA D-R(Colturi):Luoghi a Pagamento
#include <sstream> //MODIFICA D-R(Colturi):Luoghi a Pagamento

#include <windows.h>
#include <unistd.h>
#include <algorithm> //libreria utilizzata per trasformare il testo (TOUPPER) o (TOLOWER)
#include "Biglietto.h"
#include "Prodotto.h"


using namespace std;
int immetti = 0; //variabile che permette di verificare se immettere il nuovo oggetto nel luogo 'meccanico'


Astro::Astro()
{
    Gioco();
}

Astro::~Astro() {}

int Astro::getCabina()
{
    return cabina_aperta;
}

int Astro::getParete()
{
    return parete_stagna_aperta;
}

void Astro::setCabina(int cab)
{
    cabina_aperta=cab;
}

void Astro::setParete(int par)
{
    parete_stagna_aperta=par;
}


void Astro::init_specifiche()
{
    // dizionario

    vocabolario.inserisci("1",1);		//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("2",2);		//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("5",3);		//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("10",4);		//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("20",5);		//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("50",6);      //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito

    vocabolario.inserisci("a",5);
    vocabolario.inserisci("agenda",56); //Modifica PMF (agenda)
    vocabolario.inserisci("aggiusta", 27);
    vocabolario.inserisci("alto", 5);
    vocabolario.inserisci("antenna", 69);
    vocabolario.inserisci("annulla",72);
    vocabolario.inserisci("apri", 22);
    vocabolario.inserisci("armadietto", 67);
    vocabolario.inserisci("b", 6);
    vocabolario.inserisci("bacheca", 17);
    vocabolario.inserisci("basso", 6);
    vocabolario.inserisci("biglietto",7);  //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("bottone", 61);
    vocabolario.inserisci("cancella",18);  //Modifica PMF (agenda)
    vocabolario.inserisci("camice", 52);
    vocabolario.inserisci("carta",90);     //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("cartello", 60);
    vocabolario.inserisci("casco", 50);
    vocabolario.inserisci("chiave", 54);
    vocabolario.inserisci("cinema",77);    //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("cosa", 13);
    //Modifica PMF(ufficio)
    vocabolario.inserisci("consegna", 93);
    vocabolario.inserisci("documento", 79);
    vocabolario.inserisci("documenti", 79);
    //Modifica PMF: fin qui.
    vocabolario.inserisci("e", 3);
    vocabolario.inserisci("entra",74);     //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("est", 3);
    vocabolario.inserisci("etichetta", 70);
    vocabolario.inserisci("giallo", 63);
    vocabolario.inserisci("guarda", 10);
    vocabolario.inserisci("il", 7);
    vocabolario.inserisci("indicatore", 66);
    vocabolario.inserisci("indietro", 72); //modifica
    vocabolario.inserisci("indossa", 20);
    vocabolario.inserisci("inventario", 13);
    vocabolario.inserisci("insegna",78);   //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("l", 7);
    vocabolario.inserisci("la", 7);
    vocabolario.inserisci("lascia", 9);
    vocabolario.inserisci("leggi", 25);
    vocabolario.inserisci("letto", 68);
    vocabolario.inserisci("leva", 65);
    vocabolario.inserisci("lo", 7);
    vocabolario.inserisci("load", 12);
    vocabolario.inserisci("luminosa",7);   //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("manuale", 55);
    vocabolario.inserisci("metti", 20);
    vocabolario.inserisci("n", 1);
    //inizio modifica Petronelli Angelo
    vocabolario.inserisci("mappa", 19);
    vocabolario.inserisci("navigatore", 19);
    //fine modifica Petronelli Angelo
    vocabolario.inserisci("mostra",75); //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("nella",7);   //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("nella",7);   //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("nello",7);   //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("nel",7);     //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("nord", 1);
    vocabolario.inserisci("o", 4);
    vocabolario.inserisci("orologio",74);//modifica DIP
    vocabolario.inserisci("ovest", 4);
    vocabolario.inserisci("per", 7);    //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("premi", 26);
    vocabolario.inserisci("prendi", 8);
    vocabolario.inserisci("pulsante", 61);
    vocabolario.inserisci("ripara", 27);
    vocabolario.inserisci("ritira", 81); //Modifica PMF(ufficio)
    vocabolario.inserisci("rosso", 64);
    vocabolario.inserisci("s", 2);
    vocabolario.inserisci("sali", 5);
    vocabolario.inserisci("save", 11);
    vocabolario.inserisci("scendi", 6);
    vocabolario.inserisci("schiaccia", 26);
    vocabolario.inserisci("scrivi",19);  //Modifica PMF (agenda)
    vocabolario.inserisci("secondo", 53);
    vocabolario.inserisci("spingi", 24);
    vocabolario.inserisci("stadio",76);  //MODIFICA D-R(Colturi):Luoghi a Pagamento
    vocabolario.inserisci("storia", 75); //Modifica PMF(per storia)
    vocabolario.inserisci("sud", 2);

    //INIZIO modifiche SALVATORE VESTITA
    vocabolario.inserisci("sulla", 7);
    vocabolario.inserisci("sul", 7);
    //FINE modifiche SALVATORE VESTITA

    vocabolario.inserisci("tira", 23);
    vocabolario.inserisci("togli", 21);
    vocabolario.inserisci("torna", 72); //modifica
    vocabolario.inserisci("tuta", 51);
    vocabolario.inserisci("verde", 62);
    vocabolario.inserisci("w", 4);

    vocabolario.inserisci("parla", 30);        	//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("mercante", 31);     	//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("saluta", 32);	   	//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("compra", 33);	   	//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("portafoglio", 34 ); 	//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    vocabolario.inserisci("controlla", 35);		//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("impiegato",36);		//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("deposita",9);		//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("denaro",38);			//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("conto",39);			//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("saldo",39);			//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("preleva",40);		//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("cassetta",41);		//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("ritira",42);			//MODIFICA D-R(D'orsi):Negozio + Banca
    vocabolario.inserisci("calcolatore",78);	//Modifica PMF(ufficio)
    vocabolario.inserisci("scrivania", 85); 	//Modifica PMF(ufficio)
    vocabolario.inserisci("usa", 80);		    // modifica inserito vocabolo usa
    vocabolario.inserisci("motorino", 83);      // modifica inserito vocabolo motorino //Modifica PMF
    vocabolario.inserisci("pompa", 82);


    //Inizio modifiche Zagaria -- inserimento dei personaggi
    vocabolario.inserisci("cloud", 73);
    vocabolario.inserisci("cid", 73);
    vocabolario.inserisci("vincent", 73);
    vocabolario.inserisci("kain", 73);
    vocabolario.inserisci("cecil", 73);
    vocabolario.inserisci("garnet", 73);
    vocabolario.inserisci("dom", 73);
    vocabolario.inserisci("sam", 73);
    vocabolario.inserisci("lance", 73);
    vocabolario.inserisci("andre", 73);
    vocabolario.inserisci("george", 73);
    vocabolario.inserisci("oscar", 73);
    vocabolario.inserisci("lucas", 73);
    vocabolario.inserisci("lauren", 73);
    vocabolario.inserisci("zick", 73);
    vocabolario.inserisci("shain", 73);
    vocabolario.inserisci("samuel", 73);
    vocabolario.inserisci("martino", 73);
    vocabolario.inserisci("tom", 73);
    vocabolario.inserisci("jim", 73);
    vocabolario.inserisci("adam", 73);
    vocabolario.inserisci("paul", 73);
    vocabolario.inserisci("raoul", 73);
    vocabolario.inserisci("max", 73);
    vocabolario.inserisci("yan", 73);
    vocabolario.inserisci("arthur", 73);
    vocabolario.inserisci("cole", 73);
    vocabolario.inserisci("sam", 73);
    vocabolario.inserisci("zack", 73);
    vocabolario.inserisci("getro", 73);
    vocabolario.inserisci("leroy", 73);
    vocabolario.inserisci("tony", 73);
    vocabolario.inserisci("timmy", 73);
    vocabolario.inserisci("eric", 73);
    vocabolario.inserisci("dan", 73);
    vocabolario.inserisci("chuck", 73);
    vocabolario.inserisci("kail", 73);
    vocabolario.inserisci("joe", 73);
    vocabolario.inserisci("shaun", 73);
    vocabolario.inserisci("frank", 73);
    vocabolario.inserisci("vivi", 73);
    vocabolario.inserisci("jin", 73);
    vocabolario.inserisci("stainer", 73);
    vocabolario.inserisci("bruce", 73);
    vocabolario.inserisci("gabriel", 73);
    vocabolario.inserisci("interagisci", 39); // azioni che servono per interagire con i personaggi
    vocabolario.inserisci("comunica", 39);
    vocabolario.inserisci("parla", 39);
    vocabolario.inserisci("con", 7);
    //fine modifiche






    //Modifiche Francesco Cosma - Premi

    vocabolario.inserisci("regali",86); //modifica DAMONE EMANUELE
    vocabolario.inserisci("distintivo spazio",87);
    vocabolario.inserisci("distintivo soccorso",88);
    vocabolario.inserisci("distintivo annuncio",89);
    vocabolario.inserisci("distintivo corridoio",90);
    vocabolario.inserisci("distintivo algoritmi",91);

    //INIZIO MODIFICA DAMONE MARCO
    //modifica Francesco De Giorgio
    //vocaboli che servono per far funzionare rubrica e guida
    vocabolario.inserisci("consulta", 30);
    vocabolario.inserisci("tesserino", 31);
    vocabolario.inserisci("inserisci", 29);
    vocabolario.inserisci("rubrica", 28);
    vocabolario.inserisci("cerca", 15);
    vocabolario.inserisci("guida", 32);
    //vocaboli in eccesso per facilitare l' uso degli oggetti
    vocabolario.inserisci("usa", 29);
    vocabolario.inserisci("tessera", 31);
    //fine De Giorgio
    //FINE MODIFICA DAMONE MARCO
    //MODIFICHE MICHELE ALBANO
    //pronto soccorso
    vocabolario.inserisci("gettone", 86);
    vocabolario.inserisci("salute", 88);
    vocabolario.inserisci("tessera", 84);
    vocabolario.inserisci("terminale", 99);
    //FINE MODIFICA MICHELE ALBANO

    //MODIFICHE GIOVANNI CASTELLANA
    //chiesa
    vocabolario.inserisci("croce",120); //Modifica NARRACCI DOMENICO per conflitto id con oggetto tasca (prima era id: 43)
    vocabolario.inserisci("prega", 95);
    vocabolario.inserisci("confessati", 96);
    vocabolario.inserisci("confessionale",97);
    vocabolario.inserisci("sacerdote", 98);

    //FINE MODIFICA GIOVANNI CASTELLANA
    vocabolario.inserisci("pietra", 49);
    vocabolario.inserisci("pietra canalizzatrice", 49);
    vocabolario.inserisci("teletrasporto", 48);
    //INIZIO MODIFICA DISABATO(GALLONE)
    // Modifiche Gallone Gianmarco - Fast food e Ristorante
    vocabolario.inserisci("fame", 14);                 // termini per il controllo appetito
    vocabolario.inserisci("appetito", 14);
    vocabolario.inserisci("sazio", 14);
    vocabolario.inserisci("fast food",16);
    vocabolario.inserisci("ristorante",16);
    vocabolario.inserisci("zaino",28);
    vocabolario.inserisci("termico",28);
    vocabolario.inserisci("tesserino",45);
    vocabolario.inserisci("trancio",46);
    vocabolario.inserisci("pizza",46);
    vocabolario.inserisci("buono",59);
    vocabolario.inserisci("pasto",59);
    vocabolario.inserisci("arrosto",93);
    vocabolario.inserisci("frutti",95);
    vocabolario.inserisci("mare",95);
    vocabolario.inserisci("fettuccine",96);
    vocabolario.inserisci("paglia",96);
    vocabolario.inserisci("fieno",96);
    vocabolario.inserisci("gelato",97);
    vocabolario.inserisci("mangia",98);
    //FINE MODIFICA DISABATO(GALLONE)

    //Inizio modifiche Galeandro da progetto Bellanova
    vocabolario.inserisci("lettera",37); // da 62
    vocabolario.inserisci("pacco", 57); // da 63
    vocabolario.inserisci("sportello",99); //da 95
    vocabolario.inserisci("documento", 62); //da 61
    //Fine modifiche Galeandro da progetto Bellanova

    //INIZIO modifiche Moschetti
    vocabolario.inserisci("accendi", 86);
    vocabolario.inserisci("proiettore", 80);
    vocabolario.inserisci("computer", 78);
    vocabolario.inserisci("spegni", 72);
    vocabolario.inserisci("lezione", 71);
    vocabolario.inserisci("libri", 55);
    vocabolario.inserisci("segui", 10);
    //FINE modifiche Moschetti

    //INIZIO modifiche DAMONE EMANUELE
    vocabolario.inserisci("elimina", 18);
    vocabolario.inserisci("svuota", 18);
    vocabolario.inserisci("capacita", 26);
    vocabolario.inserisci("aprire", 22);
    vocabolario.inserisci("premere", 26);
    vocabolario.inserisci("scrivere", 19);

    //INIZIO modifiche SALVATORE VESTITA
    //commento "foglio" con codice oggetto 94 perchè mi serve il verbo "siediti"
    //vocabolario.inserisci("foglio", 94);
    vocabolario.inserisci("siediti", 94);
    //FINE modifiche SALVATORE VESTITA

    vocabolario.inserisci("elenca", 43);
    vocabolario.inserisci("elenco", 44);
    vocabolario.inserisci("piegarsi", 58);
    vocabolario.inserisci("leggere", 25);
    vocabolario.inserisci("salta", 49);
    vocabolario.inserisci("saltare", 49);
    vocabolario.inserisci ("digita", 92);
    vocabolario.inserisci("digitare", 92);
    vocabolario.inserisci("guidare", 48);
    //FINE modifiche DAMONE EMANUELE


    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    vocabolario.inserisci("file12",37);
    vocabolario.inserisci("file13",57);
    vocabolario.inserisci("file15",58);
    vocabolario.inserisci("file21",71);
    vocabolario.inserisci("computer",99);
    vocabolario.inserisci("museo",16);//definisco il vocabolo museo
    vocabolario.inserisci("entra nel",74);//duplicato di "entra"
    //FINE MODIFICHE DEL GIUDICE ANGELO

    //MODIFICHE DI BASILE ANTONIO
    vocabolario.inserisci("scuola", 16);
    vocabolario.inserisci("1A", 16);
    vocabolario.inserisci("2A", 16);
    vocabolario.inserisci("3A", 16);
    vocabolario.inserisci("cartina", 60);
    vocabolario.inserisci("banchi", 43);
    vocabolario.inserisci("sedia", 56);
    vocabolario.inserisci("registro", 88);
    vocabolario.inserisci("lavagna", 90);
    vocabolario.inserisci("cattedra", 70);
    //inserimento di personaggi
    vocabolario.inserisci("preside", 73);
    vocabolario.inserisci("maestra", 73);
    //FINE MODIFICHE DI BASILE ANTONIO

    //INIZIO MODIFICHE VACCA GIANLUCA
    vocabolario.inserisci("Auditorium", 16);
    vocabolario.inserisci("proiettore rotto", 80);
    vocabolario.inserisci("schermo", 60);
    vocabolario.inserisci("finestra", 90);
    vocabolario.inserisci("microfono", 90);
    vocabolario.inserisci("strumenti", 88);
    vocabolario.inserisci("strumento", 88);
    vocabolario.inserisci("suona", 72); //per utilizzare il verbo suonare
    vocabolario.inserisci("jukebox", 56);
    vocabolario.inserisci("pannello", 70);
    vocabolario.inserisci("scacchiera", 73);
    //vocabolario.inserisci("usa", 80);
    //FINE MODIFICHE VACCA GIANLUCA


    //INIZIO modifiche SALVATORE VESTITA
    vocabolario.inserisci("biglietteria", 80);
    vocabolario.inserisci("giornale", 78);
    vocabolario.inserisci("treno", 55);
    vocabolario.inserisci("panchina", 71);
    //FINE modifiche SALVATORE VESTITA

    //INIZIO reinserimento codice non trovato nel progetto base1906 Palagiano Marcello
    //INIZIO modifiche DAVIDE MANTELLINI
    vocabolario.inserisci("panca", 57);
    vocabolario.inserisci("tapis", 47);
    vocabolario.inserisci("roulant", 47);
    vocabolario.inserisci("scheda", 84);
    vocabolario.inserisci("schede", 84);
    vocabolario.inserisci("macchinetta", 97);
    //FINE modifiche DAVIDE MANTELLINI

    //INIZIO MODIFICHE CICALA
    vocabolario.inserisci("slotmachine", 86);
    vocabolario.inserisci("5", 90);
    vocabolario.inserisci("10", 91);
    vocabolario.inserisci("20", 92);
    vocabolario.inserisci("50", 93);
    vocabolario.inserisci("100", 94);
    vocabolario.inserisci("euro", 95);

    //FINE MODIFICHE CICALA

    //inzio modifiche biblioteca Scatigna
    vocabolario.inserisci("chiudi", 93);
    vocabolario.inserisci("libro", 95);
    vocabolario.inserisci("astronave", 90);
    vocabolario.inserisci("vetrina", 19);
    vocabolario.inserisci("equipaggio", 91);
    //fine modifiche biblioteca Scatigna
    //FINE reinserimento codice non trovato nel progetto base1906 Palagiano Marcello



    //INIZIO modifiche DELLA FOLGORE GRAZIA
    vocabolario.inserisci("ticket_bus", 114);
    vocabolario.inserisci("autobus", 115);
    vocabolario.inserisci("chiave_auto", 116);
    vocabolario.inserisci("automobile", 117);
    //FINE modifiche DELLA FOLGORE GRAZIA

    //INIZIO modifiche PALAGIANO MARCELLO
    vocabolario.inserisci("banco", 43);
    vocabolario.inserisci("ricambio", 119);
    vocabolario.inserisci("pila", 70);
    vocabolario.inserisci("batterie", 16);
    vocabolario.inserisci("chiave_inglese", 118);
    vocabolario.inserisci("diario", 57);
    vocabolario.inserisci("meccanico", 73);
    //FINE modifiche PALAGIANO MARCELLO

    // Modifiche Matteo_Luceri(ex_Sternativo)
    vocabolario.inserisci("frammento", 154);
    vocabolario.inserisci("valigia", 155);
    vocabolario.inserisci("zaino", 156);
    vocabolario.inserisci("raccogli", 258);
    vocabolario.inserisci("aiuto", 259);
    vocabolario.inserisci("help", 259);




// inizio modifiche CHIARAPPA ROSA

    /*vocabolario.inserisci("ruba", 250);
    vocabolario.inserisci("rubati", 200);

    azioni.inserisci(2000000, 11);         //azione "rubati"
    azioni.inserisci(509999, -10);        //azioni per "ruba"*/

// fine modifiche CHIARAPPA ROSA





    // azioni
    azioni.inserisci(10000, 1);
    azioni.inserisci(20000, 1);
    azioni.inserisci(30000, 1);
    azioni.inserisci(40000, 1);
    azioni.inserisci(50000, 1);
    azioni.inserisci(60000, 1);
    azioni.inserisci(89999, -2);
    azioni.inserisci(90050, -10);
    azioni.inserisci(90051, -10);

    //MODIFICA D-R(D'Orsi):Negozio + Banca
    azioni.inserisci(90055, -10); // lascia manuale
    azioni.inserisci(90052, -10); // lascia camice
    azioni.inserisci(90054, -10); // lascia chiave

    azioni.inserisci(99999, 3);
    azioni.inserisci(100051, -11);
    azioni.inserisci(100052, -14);
    azioni.inserisci(100053, -12);
    azioni.inserisci(100055, -13);
    azioni.inserisci(100060, -13);
    azioni.inserisci(109999, -4);
    azioni.inserisci(110000, 5);
    azioni.inserisci(120000, 6);
    azioni.inserisci(130000, 7);
    azioni.inserisci(170000, 40); //azione bacheca

    azioni.inserisci(1856, -46); //Modifica PMF (agenda)comando cancella agenda

    //inizio modifica Petronelli Angelo
    azioni.inserisci(1900, 8);
    //fine modifica Petronelli Angelo

    azioni.inserisci(1956, -47); // Modifica PMF (agenda) comando scrivi agenda

    azioni.inserisci(200050, -142); //Modifica ML
    azioni.inserisci(200051, -142); //Modifica ML
    azioni.inserisci(200052, -142); //Modifica ML

    azioni.inserisci(210050, -10);
    azioni.inserisci(210051, -10);
    azioni.inserisci(210052, -3);
    //azioni.inserisci(2255, -15);
    //azioni.inserisci(2555, -15);
    azioni.inserisci(250056,-48); // Modifica PMF (agenda) comando leggi agenda
    azioni.inserisci(270069, -29);
    azioni.inserisci(650050, -10);
    azioni.inserisci(650051, -10);
    azioni.inserisci(650052, -3);
    azioni.inserisci(720000, 9); //modifica

    azioni.inserisci(750000, 50);//Modifica PMF(per storia)

    azioni.inserisci(800082, 41); // azione usa pompa di benzina
    azioni.inserisci(800083, 42); //azione usa motorino////Modifica PMF
    azioni.inserisci(100100066, 16);
    azioni.inserisci(100250070, 17);
    azioni.inserisci(100260061, 18);
    azioni.inserisci(200030000, 21); //MODIFICA D-R(Colturi):Luoghi a Pagamento
    azioni.inserisci(200050000, 20);
    azioni.inserisci(220056000, 19);

    azioni.inserisci(300030000, 1);//Modifica PMF(ufficio)

    azioni.inserisci(300030000, 21);
    azioni.inserisci(400030000, 21);
    azioni.inserisci(400250060, 22);
    azioni.inserisci(500080074, 39);//modifica DP LL*VV*OO
    azioni.inserisci(500220067, 23);
    azioni.inserisci(600220067, 24);
    azioni.inserisci(700300000, 37);
    azioni.inserisci(700400000, 38);
    azioni.inserisci(700260061, 25);
    azioni.inserisci(700260062, 27);
    azioni.inserisci(700260064, 26);
    azioni.inserisci(800100066, 16);
    azioni.inserisci(800230065, 35);
    azioni.inserisci(800240065, 34);
    azioni.inserisci(800250060, 28);
    azioni.inserisci(800260061, 30);
    azioni.inserisci(800260062, 33);
    azioni.inserisci(800260063, 32);
    azioni.inserisci(800260064, 31);
    azioni.inserisci(900100069, 36);

    //MODIFICA D-R(D'Orsi):Negozio + Banca // SOSTITUZIONE LL = 12 => 14; LL = 13 => 15 //
    azioni.inserisci(1400390031,51); // parla mercante
    azioni.inserisci(1400339999,52); // compra oggetto
    azioni.inserisci(1400320031,53); // saluta mercante
    azioni.inserisci(350034,  54); // controlla portafoglio
    azioni.inserisci(1500390036,55); // parla impiegato
    azioni.inserisci(1500090038,56); // deposita denaro
    azioni.inserisci(1500320036,57); // saluta impiegato
    azioni.inserisci(1500350039,58); // controlla conto/saldo
    azioni.inserisci(1500400038,59); // preleva denaro
    azioni.inserisci(1500350041,60); // controlla cassetta
    azioni.inserisci(1500429999,61); // ritira oggetto

    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    azioni.inserisci(350090,  66);  // controlla carta

    azioni.inserisci(1800740075, 62); //MODIFICHE D-R(Colturi):Luoghi a Pagamento - LL = 18 MOSTRA D'ARTE - VV = 74 ENTRA - OO = 75 MOSTRA
    azioni.inserisci(1700740076, 63); //MODIFICHE D-R(Colturi):Luoghi a Pagamento - LL = 17 STADIO		  - VV = 74 ENTRA - OO = 76 STADIO
    azioni.inserisci(1600740077, 64); //MODIFICHE D-R(Colturi):Luoghi a Pagamento - LL = 16 CINEMA		  - VV = 74 ENTRA - OO = 77 CINEMA
    azioni.inserisci(250078,   65); //MODIFICHE D-R(Colturi):Luoghi a Pagamento - INSEGNA LUMINOSA      - VV = 25 LEGGI - OO = 78 INSEGNA
    azioni.inserisci(100078,  -13); //MODIFICHE D-R(Colturi):Luoghi a Pagamento - INSEGNA LUMINOSA	  - VV = 10       - OO = 78 INSEGNA

    //Inizio modifiche Zagaria
    azioni.inserisci(390073,43); // comando azione per parlare con il personaggio
    //fine modifiche


    //Modifica PMF(ufficio)
    azioni.inserisci(1200100085, 44); //(GUARDA SCRIVANIA)
    azioni.inserisci(1200100078, 45); //(GUARDA CALCOLATORE)
    azioni.inserisci(1200800079, 46); //(CONSEGNA DOCUMENTO)
    azioni.inserisci(1200810079, 47); //(RITIRA DOCUMENTO)
    //Modifica PMF: fin qui.

    //Modifiche Francesco Cosma - Premi

    azioni.inserisci(800060000, 68); //2600

    //INIZIO MODIFICA DAMONE MARCO
    //Modifica De Giorgio azione che permette di richiamare guida
    azioni.inserisci(309999, 49);
    //azione che permette di usare il tesserino
    azioni.inserisci(800290031, 59);

    //azione che permette di usare la rubrica
    azioni.inserisci(170028, 77);
    //azioni sinonime
    azioni.inserisci(250028, 77);
    azioni.inserisci(290028, 77);
    //azioni.inserisci(2955, -15);
    //FINE MODIFICA DAMONE MARCO
    //INIZIO MODIFICA MICHELE ALBANO
    azioni.inserisci(880000, 67); //Comando Stato Salute
    azioni.inserisci(1900299999, 69);//Azione per usare il terminale nel pronto soccorso
    azioni.inserisci(1900109999, 69);//Guarda il terminale nel pronto soccorso,sinonimo
    //FINE MODIFICA MICHELE ALBANO

    //INIZIO MODIFICA GIOVANNI CASTELLANA
    azioni.inserisci(2000960000, 70); //Azione per confessarti con comando confessati
    azioni.inserisci(2000740097, 70); //Azione per confessarti con comando entra confessionale
    azioni.inserisci(2000940000, 71);// Azione per sederti con comando siediti
    azioni.inserisci(2000020000, 72); // Azione di supporto alla 71
    azioni.inserisci(2000300098, 73);//Azione per parlare al sacerdote
    azioni.inserisci(2000950000, 74);//Azione per pregare
    //FINE MODIFICA GIOVANNI CASTELLANA

    //INIZIO MODIFICA DISABATO(GALLONE)
    // Inizio Modifica Gallone - integro le nuove azioni
    //Prendi
    azioni.inserisci(100089999,-2);
    azioni.inserisci(200089999,-2);
    azioni.inserisci(300089999,-2);
    azioni.inserisci(400089999,-2);
    //azioni.inserisci(500089999,-2);
    azioni.inserisci(600089999,-2);
    azioni.inserisci(700089999,-2);
    azioni.inserisci(80008999,-2);
    azioni.inserisci(900089999,-2);
    azioni.inserisci(1000089999,-2);
    azioni.inserisci(1100089999,-2);
    azioni.inserisci(1200089999,-2);

    azioni.inserisci(140000, 75); //mostra la sazietà
    azioni.inserisci(280000, 79); //mostra il contenuto dello zaino termico
    azioni.inserisci(2200980046, 77); //mangia i piatti che sono conservati nello zaino termico
    azioni.inserisci(2100980093, 77); //(codici dei piatti compresi tra 46 e 97)
    azioni.inserisci(2100980094, 77);
    azioni.inserisci(2100980095, 77);
    azioni.inserisci(2100980096, 77);
    azioni.inserisci(2200980097, 77);
    azioni.inserisci(2200339999, 76); //compra gli oggetti nel fast food
    azioni.inserisci(2100339999, 76); //compra gli oggetti nel ristorante
    // Fine Modifica Gallone	//FINE MODIFICHE MARGHERITA DISABATO(GALLONE)

    //Modifiche Galeandro da progetto Bellanova
    azioni.inserisci(2400109999,82);//AZIONE 82/InUfficioPostale-guarda-sportello
    azioni.inserisci(220057,83);//AZIONE 83/apri-pacco
    azioni.inserisci(250037,84);//AZIONE 84/leggi-lettera
    //Fine modifiche Galeandro da progetto Bellanova

    //INIZIO modifiche Moschetti
    azioni.inserisci(2500940000, 85);//"Siediti"
    azioni.inserisci(2500250055, 86);//"Leggi libri”
    azioni.inserisci(2500290099, 87);//"Usa computer"
    azioni.inserisci(2500100071, 88);//"Segui lezione"
    azioni.inserisci(2500860080, 89);//"Accendi proiettore"
    azioni.inserisci(2500720080, 90);//"Spegni proiettore"
    //FINE modifiche Moschetti

    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    azioni.inserisci(2600299999, 91);//uso del computer
    azioni.inserisci(2600250037, 92);//leggi file12
    azioni.inserisci(2600250057, 93);//leggi file13
    azioni.inserisci(2600250058, 94);//leggi file15
    azioni.inserisci(2600250071, 95);//leggi file21
    azioni.inserisci(2700740016, 96); //azione entrata museo
    //FINE MODIFICHE DEL GIUDICE ANGELO

    //INIZIO MODIFICHE BASILE ANTONIO
    azioni.inserisci(250088,97); //leggi registro
    azioni.inserisci(100088, 97); //guarda registro
    azioni.inserisci(3100100090, 98); //guarda lavagna
    azioni.inserisci(2800390073, 100); //parla con il preside
    azioni.inserisci(2900390073, 101); //parla con la maestra Clara
    azioni.inserisci(3000390073, 102); //parla con la maestra Mara
    azioni.inserisci(2800100060, 103); //guarda cartina galattica
    azioni.inserisci(2900100060, 104); //guarda cartina geografica
    //FINE MODIFICHE BASILE ANTONIO

    //INIZIO MODIFICHE VACCA GIANLUCA
    azioni.inserisci(3200860080, 105); //Accendi il proiettore rotto nell'Auditorium
    azioni.inserisci(3200100060, 106); //Guarda lo schermo presente nell'Auditorium
    azioni.inserisci(3200100090, 107); //Guarda dalla finestra (che è sigillata)
    azioni.inserisci(3200390090, 108); //Parla al microfono dell'Auditorium
    azioni.inserisci(3200290056, 109); //Interagisci con il Jukebox nell'auditorium
    azioni.inserisci(3200100088, 110);  //Guarda gli strumenti musicali
    azioni.inserisci(3200720088, 111);  //Usa gli strumenti musicali
    azioni.inserisci(3200290070, 112);  //Interagisci con il pannello delle luci
    azioni.inserisci(3200100073, 113); //Guarda la scacchiera
    //FINE MODIFICHE VACCA GIANLUCA

    //INIZIO modifiche SALVATORE VESTITA
    azioni.inserisci(3300940071, 114);//"Siediti sulla panchina"
    azioni.inserisci(3300290080, 115);//"usa biglietteria"
    azioni.inserisci(3300250078, 116);//"leggi giornale"
    azioni.inserisci(3300050055, 117);//"sali sul treno"
    azioni.inserisci(4900290048, 118);   //Se si usa il teletrasporto nell'astronave aliena -- Palagiano Marcello: modifica codice luogo da 40 a 48
    azioni.inserisci(1100290049, 118);   //Se si usa la pietra canalizzatrice nel luogo 11 "Poppa dell'astronave"
    azioni.inserisci(290049, 119);     //Se si usa la pietra in qualsiasi altro posto
    //FINE modifiche SALVATORE VESTITA

    azioni.inserisci(100117, 80); //Modifica DELLA FOLGORE GRAZIA - Guarda bagagliaio

    //INIZIO modifiche DAVIDE MANTELLINI -- Palagiano Marcello: modifica codice luogo da 35 a 34
    azioni.inserisci(3400290057, 120); //usa panca
    azioni.inserisci(3400290047, 121); //usa tapis
    azioni.inserisci(3400290099, 122); //usa terminale
    azioni.inserisci(3400100099, 122); //guarda terminale
    azioni.inserisci(3400290084, 123); //usa schede
    azioni.inserisci(3400290097, 124); //usa macchinetta
    //FINE modifiche DAVIDE MANTELLINI


    //INIZIO modifiche GIACOMO CICALA -- Palagiano Marcello: modifica codice luogo da 36 a 35
    azioni.inserisci(3500290086, 125); //usa slotmachine
    //FINE modifiche GIACOMO CICALA

    //inizio modifiche biblioteca Scatigna -- Palagiano Marcello: modifica codice luogo da 37 a 36 (biblioteca), da 38 a 37 (vetrina)

    azioni.inserisci(3600250070, 126); //nuova azione etichetta su biblioteca
    azioni.inserisci(3600220019, 127); //nuova azione di apertura su vetrina
    azioni.inserisci(3700930019, 128); //nuova azione di chiusura su vetrina
    azioni.inserisci(250090, 129); //leggi libro astronave
    azioni.inserisci(250091, 129); //leggi libro equipaggio
    //fine modifica biblioteca Scatigna

    //INIZIO modifiche PALAGIANO MARCELLO
    azioni.inserisci(4100100043, 130); //guarda banco da lavoro
    azioni.inserisci(4100100119, 131); //guarda ricambio astronave
    azioni.inserisci(4100100070, 132); //guarda pila batterie
    //133 definita se si scartano batterie dalla pila --- guarda batterie
    azioni.inserisci(100118, 134); //guarda la chiave_inglese
    azioni.inserisci(4100100057, 135); //guarda il diario
    azioni.inserisci(4100250057, 136); //leggi il diario
    azioni.inserisci(4100100060, 137); //guarda il cartello
    azioni.inserisci(4100100099, 138); //guarda computer
    azioni.inserisci(4100390073, 139); //parla meccanico
    //FINE modifiche PALAGIANO MARCELLO

    // Modifiche Matteo_Luceri(ex_Sternativo)

    azioni.inserisci(80155, -2); //Azione prendi valigia
    azioni.inserisci(80156, -2); //Azione prendi zaino
    azioni.inserisci(90155, 3); //Azione lascia valigia
    azioni.inserisci(90156, 3); //Azione lascia zaino
    azioni.inserisci(100155, 140); //Azione guarda valigia
    azioni.inserisci(100156, 141); //Azione guarda zaino
    azioni.inserisci(1550000, 143); //Azione inventario valigia
    azioni.inserisci(1560000, 144); //Azione inventario zaino
    azioni.inserisci(2590000, 145); //Azione aiuto/help


    //INIZIO MODIFICA DAMONE MARCO
    // oggetti: (nome, codice, luogo)
    // oggetti: (nome, codice, luogo,descrizione) --- MODIFICA MARCO DAMONE
    oggetti.svuota();
//1
    oggetti.inserisci(Oggetto("un indicatore", 66, -1,0, "Indicatore:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tL'indicatore e' situato nella cabina di pilotaggio.\n\tDescrizione:\tSegna la temperatura del reattore.\n"));
    oggetti.inserisci(Oggetto("un pulsante", 61, -1,0,"Pulsante:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl pulsante e' situato nella cabina di pilotaggio!\n\tDescrizione:\tServe per mandare l'SOS GALATTICO!\n"));
    oggetti.inserisci(Oggetto("un'etichetta", 70, -1, 0,"Etichetta:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tL'etichetta e' situata nella cabina di pilotaggio!\n\tDescrizione:\tSull'etichetta c'e' scritto: SOS GALATTICO (premere il pulsante solo\n\t\t\tin caso di emergenza. Ogni abuso verra' punito!).\n"));
    oggetti.inserisci(Oggetto("una tuta", 51, 1, 2,"Tuta:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tLa tuta e' situata nell'armadietto.\n\tDescrizione:\tDevi indossarla per poter andare all'esterno\n\t\t\tdell'astronave!\n"));
    oggetti.inserisci(Oggetto("un cartello bianco", 60, -2, 0,"Cartello Bianco:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl cartello bianco e' situato alla base di una scaletta\n\t\t\ta nord del corridoio!\n\tDescrizione:\tSul cartello c'e' scritto: Ingresso riservato al personale\n\t\t\tdi bordo!\n"));
//5-6
    oggetti.inserisci(Oggetto("un cartello giallo", 60, -4, 0,"Cartello Giallo:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl cartello giallo e' situato a sud del corridoio!\n\tDescrizione:\tSul cartello c'e' scritto: ATTENZIONE! STANZA DEPRESSURIZZATA!\n"));
    oggetti.inserisci(Oggetto("un letto", 68, -5, 0,"Letto:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl letto e' situato nella cabina del secondo pilota!\n\tDescrizione:\tQuesto e' il letto del secondo pilota!\n"));
    oggetti.inserisci(Oggetto("un armadietto", 67, -5, 0,"Armadietto:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto armadietto e' situato nella cabina del secondo\n\t\t\tpilota!\n\tDescrizione:\tHai bisogno della chiave per aprire questo\n\t\t\tarmadietto, potrebbe contenere qualcosa di utile!\n"));
    oggetti.inserisci(Oggetto("un letto", 68, -6, 0,"Letto:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl letto e' situato nella tua cabina!\n\tDescrizione:\tQuesto e' il tuo letto!\n"));
    oggetti.inserisci(Oggetto("un armadietto", 67, -6, 0,"Armadietto:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto armadietto e' situato nella tua cabina!\n\tDescrizione:\tNon hai bisogno di chiavi per aprire questo\n\t\t\tarmadietto!\n"));
//10-11
    oggetti.inserisci(Oggetto("un casco", 50, 6, 3,"Casco:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tIl casco e' situato nella tua cabina!\n\tDescrizione:\tIl casco ti serve indossarlo per poter andare\n\t\t\tall'esterno dall'astronave!\n"));
    oggetti.inserisci(Oggetto("la tua agenda",56,6, 0, "Agenda : \n\n Stato : \t\t Prendibile\n\t Luogo : \t\t L'agenda è presente nel tuo inventario non appena comincia il gioco. \n\t descrizione : \t potrai annotare degli appunti durante l'avventura")); //Modifica PMF(agenda)
    oggetti.inserisci(Oggetto("un pulsante rosso", 61, -7, 0,"Pulsante Rosso:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto pulsante e' situato nel compartimento stagno!\n\tDescrizione:\tDovresti fare attenzione al pulsante rosso, premilo\n\t\t\tal momento giusto!\n"));
    oggetti.inserisci(Oggetto("un pulsante verde", 61, -7, 0,"Pulsante Verde:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto pulsante e' situato nel compartimento stagno!\n\tDescrizione:\tIl pulsante verde serve per aprire la porta per rientrare\n\t\t\tall'interno dell'astronave!\n"));
    oggetti.inserisci(Oggetto("un indicatore", 66, -8, 0,"Indicatore:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tL'indicatore e' situato nella sala controllo del reattore!\n\tDescrizione:\tTi indica la temperatura che c'e' all'interno dell'astronave!\n"));
//15-16
    oggetti.inserisci(Oggetto("una leva", 65, -8, 0,"Leva:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tLa leva e' situata nella sala controlllo del reattore!\n\tDescrizione:\tAttenzione: devi tirare la leva nel momento giusto, altrimenti non potrai uscire dall'astronave\n"));
    oggetti.inserisci(Oggetto("un pulsante rosso", 61, -8, 0,"Pulsante Rosso:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto pulsante e' situato nella sala controllo del reattore!\n\tDescrizione:\tIl pulsante rosso ti da delle indicazioni!"));
    oggetti.inserisci(Oggetto("un pulsante verde", 61, -8, 0,"Pulsante Verde:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto pulsante e' situato nella sala controllo del reattore!\n\tDescrizione:\tIl pulsante verde ti da indicazioni sulla tua salute!"));
    oggetti.inserisci(Oggetto("un cartello rosso", 60, -8, 0,"Cartello Rosso:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tIl cartello rosso e' situato nella sala controllo del reattore!\n\tDescrizione:\tQuesto cartello ti da delle indicazioni sulla stanza successiva!\n"));
    oggetti.inserisci(Oggetto("un pulsante giallo", 61, -8, 0,"Pulsante Giallo:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tQuesto pulsante e' situato nella sala controllo del reattore!\n\tDescrizione:\tIl pulsante giallo se viene cliccato una volta non ti da nessuna indicazione, se viene cliccato 2 volte ti manda un segnale di allarme perche' la temperatura all'interno dell'astronave e' insopportabile perche' sta aumentando!"));
//20-21
    oggetti.inserisci(Oggetto("il secondo pilota", 53, 9, 0,"Secondo Pilota:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tIl secondo pilota e' situato all'esterno dell'astronave\n\t\t\tprecisamente a prua.\n\tDescrizione:\tE' il secondo pilota dell'astronave, ma con l'incidente\n\t\t\tavvenuto ha perso i sensi. Dovresti cercare di\n\t\t\trisvegliarlo perche' lui puo' darti delle\n\t\t\tinformazioni utili!\n"));
    oggetti.inserisci(Oggetto("un'antenna parabolica", 69, -9, 0,"Antenna parabolica:\n\n\tStato:\t\tNon Prendibile\n\tLuogo:\t\tL'antenna parabolica e' situata all'esterno\n\t\t\tdell'astronave, precisamente a prua!\n\tDescrizione:\tL'antenna parabolica e' utilizzata per\n\t\t\ttrasmettere comunicazioni verso la stazione base e le\n\t\t\taltre astronavi!\n"));
    oggetti.inserisci(Oggetto("un camice", 52, -9999, 3,"Camice:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tIl camice e' situato nell'armadietto che si trova nella cabina del secondo pilota!\n\tDescrizione:\tIl camice ti serve indossarlo per andare nella sala controllo del reattore!\n"));
    oggetti.inserisci(Oggetto("una chiave", 54, -9999, 0,"Chiave:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tLa chiave la possiede il seconco pilota.\n\tDescrizione:\tServe per aprire l'armadietto situato nella cabina del secondo pilota.\n"));
    oggetti.inserisci(Oggetto("un manuale", 55, -9999, 1,"Manuale:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tIl manuale e' situato nell'armadietto che si trova nella cabina del secondo pilota!\n\tDescrizione:\tTi da' indicazioni per come disattivare il reattore!\n"));
//25-26
    oggetti.inserisci(Oggetto("un portafoglio",34, 6, 0)); 	  //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("una carta di credito",90, 6, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("un biglietto per la mostra",75,4, 0)); //MODIFICHE D-R(Colturi):Luoghi a Pagamento
    oggetti.inserisci(Oggetto("un biglietto per lo stadio",76,6, 0)); //MODIFICHE D-R(Colturi):Luoghi a Pagamento
    oggetti.inserisci(Oggetto("un biglietto per il cinema",77,1, 0)); //MODIFICHE D-R(Colturi):Luoghi a Pagamento
//30-31
    oggetti.inserisci(Oggetto("Un insegna luminosa",78,-18, 0));      //MODIFICHE D-R(Colturi):Luoghi a Pagamento
    oggetti.inserisci(Oggetto("Un insegna luminosa",78,-17, 0));      //MODIFICHE D-R(Colturi):Luoghi a Pagamento
    oggetti.inserisci(Oggetto("Un insegna luminosa",78,-16, 0));      //MODIFICHE D-R(Colturi):Luoghi a Pagamento
    //MODIFICA D-R(D'Orsi) // CAMBIATO cod_luogo -12 => -14; -13 => -15 //
    oggetti.inserisci(Oggetto("un mercante", 31, -14, 0));
    oggetti.inserisci(Oggetto("un impiegato",69,-15, 0));//->35
//35-|
    //MODIFICA D-R(D'Orsi): inserire oggetti in negozio
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 52 ) ), 250.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 51 ) ), 800.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 50 ) ), 100.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 54 ) ), 1000.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 55 ) ), 1500.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 75 ) ), 10.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 76 ) ), 10.00f );
    negozio.inserisci( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 77 ) ), 10.00f );
    //banca.lascia_oggetto( oggetti.get_oggetto( oggetti.get_oggetto_indice_by_codice( 55 ) ));
//|-36
    oggetti.inserisci(Oggetto("5 Euro",3, 6, 0));  //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("10 Euro",4, 3, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("50 Euro",6, 3, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("1  Euro",1, 1, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("2  Euro",2, 2, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
//40-41
    oggetti.inserisci(Oggetto("10 Euro",4, 7, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("20 Euro",5, 4, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("1  Euro",1, 2, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("2  Euro",2, 7, 0)); //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    oggetti.inserisci(Oggetto("un orologio", 74, -5, 0));
//45-46
    oggetti.inserisci(Oggetto("un calcolatore", 80, -12, 0));//Modifica PMF(ufficio)
    oggetti.inserisci(Oggetto("una scrivania", 81, -12, 0 ));//Modifica PMF(ufficio)
    oggetti.inserisci(Oggetto("una pompa di benzina",82, -13, 0));
    oggetti.inserisci(Oggetto("un motorino",83, 12,0)); //28////Modifica PMF
    oggetti.inserisci(Oggetto("un distintivo spazio",87, -9999, 0));//->50
//50-51
    oggetti.inserisci(Oggetto("un distintivo pronto soccorso",88, -9999, 0));
    oggetti.inserisci(Oggetto("un distintivo annuncio",89, -9999, 0));
    oggetti.inserisci(Oggetto("un distintivo corridoio",90, -9999, 0));
    oggetti.inserisci(Oggetto("un distintivo algoritmi",91, -9999, 0));
    oggetti.inserisci(Oggetto("la rubrica", 28, -9999, 0,"Rubrica:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tLa rubrica e' situata nell'armadietto che si trova\n\t\t\tnella tua cabina!\n\tDescrizione:\tPuoi consultarla per poter ottenere informazioni\n\t\t\tsu alcuni personaggi coinvolti nel gioco!\n"));
//55-56
    oggetti.inserisci(Oggetto("la guida", 32, 1, 0,"Guida:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tLa guida e' situata nella cabina di pilotaggio!\n\tDescrizione:\tPuoi consultarla per poter ottenere informazioni\n\t\t\tsu tutti gli oggetti presenti nel gioco!\n"));
    oggetti.inserisci(Oggetto("il tesserino", 31, -9999, 0,"Tesserino:\n\n\tStato:\t\tPrendibile\n\tLuogo:\t\tIl tesserino e' situato nell'armadietto che si trova nella cabina del secondo pilota!\n\tDescrizione:\tTi serve per interagire con i comandi del reattore!\n"));
    //FINE MODIFICA DAMONE MARCO
    //INIZIO MODIFICA MICHELE ALBANO
    oggetti.inserisci(Oggetto("una tessera sanitaria",84, 6, 0));  //Indice-->58
    oggetti.inserisci(Oggetto("un gettone",86, 12, 0));  //Indice-->59
    oggetti.inserisci(Oggetto("un terminale",99, -19, 0));  //Indice-->60
    //FINE MODIFICA MICHELE ALBANO
    //INIZIO MODIFICA GIOVANNI CASTELLANA
//60-61
    oggetti.inserisci(Oggetto("una croce",43, 20, 0));
    oggetti.inserisci(Oggetto("un confessionale",97, -20, 0));
    oggetti.inserisci(Oggetto("un sacerdote",98, -20, 0));
    //FINE MODIFICA GIOVANNI
    oggetti.inserisci(Oggetto("la Pietra Canalizzatrice",49,0, 0));
    oggetti.inserisci(Oggetto("un teletrasporto",48,-49, 0)); //-- Palagiano Marcello: modifica codice luogo da 41 a 49
    //INIZIO MODIFICHE MARGHERITA DISABATO
    //Inizio Modifica Gallone - aggiungo zaino e tasca nel Dizionario degli Oggetti
//65-66
    oggetti.inserisci(Oggetto("uno zaino termico",28,6, 0));
    oggetti.inserisci(Oggetto("tasca", 43,0, 0));
    //Fine Modifica Gallone
    //Inizio Modifica Gallone - inserisco i nuovi oggetti nel Dizionario degli Oggetti
    //nome,codice,luogo,valore energetico,categoria
    oggetti.inserisci(Oggetto("Trancio di pizza",46,22, 0,20,"BLU"));
    oggetti.inserisci(Oggetto("Gelato alla panna",97,22, 0,24,"GIALLO"));
    oggetti.inserisci(Oggetto("Fettuccine Paglia e Fieno",96,21, 0,46,"VERDE"));
//70-71
    oggetti.inserisci(Oggetto("Misto frutti di mare",95,21, 0,38,"VERDE"));
    oggetti.inserisci(Oggetto("un tesserino ristorante verde",45,1, 0,"VERDE"));//-_>77
    oggetti.inserisci(Oggetto("un buono pasto giallo",59,5, 0,"GIALLO"));//-->78
    //Fine Modifica Gallone
    //FINE MODIFICHE MARGHERITA DISABATO
    //Inizio modifiche Galeandro da progetto Bellanova
    oggetti.inserisci(Oggetto("un documento d'identita'",62,6, 0));//80 (doc 79 da 61)
    oggetti.inserisci(Oggetto("una lettera",37,-9999, 0));//81
//75-76
    oggetti.inserisci(Oggetto("uno sportello telematico",99,-24, 0));//Galeandro da -23 a -24
    oggetti.inserisci(Oggetto("un pacco",57,-9999, 0));//83
    //Fine modifiche Galeandro da progetto Bellanova
    //INIZIO modifiche Moschetti
    oggetti.inserisci(Oggetto("un proiettore",80, -25, 0));
    oggetti.inserisci(Oggetto("un computer",99, -25, 0));
    oggetti.inserisci(Oggetto("dei libri",55, 25, 0));
//80-81
    oggetti.inserisci(Oggetto("una lezione in corso",71, -25, 0));
    //FINE modifiche Moschetti
    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    oggetti.inserisci(Oggetto("file12",37, -26, 0));
    oggetti.inserisci(Oggetto("file13",57, -26, 0));
    oggetti.inserisci(Oggetto("file15",58, -26, 0));
    oggetti.inserisci(Oggetto("file21",71, -26, 0));
//85-86
    oggetti.inserisci(Oggetto("un computer",99, -26, 0));
    oggetti.inserisci(Oggetto("il museo",16, -16, 0));
    //FINE MODIFICHE DEL GIUDICE ANGELO
    //MODIFICHE ANTONIO BASILE
    //Oggetti inseriti nella scuola
    oggetti.inserisci(Oggetto("una cartina Galattica", 60,-28, 0));
    oggetti.inserisci(Oggetto("il Preside", 73, -28, 0));
    //1A
    oggetti.inserisci(Oggetto("la maestra Clara", 73, -29, 0));
//90-91
    oggetti.inserisci(Oggetto("una cartina geografica", 60, -29, 0));
    oggetti.inserisci(Oggetto("dei banchi", 43, -29, 0));
    oggetti.inserisci(Oggetto("delle sedie", 56, -29, 0));
    oggetti.inserisci(Oggetto("una cattedra", 70, -29, 0));
    //2A
    oggetti.inserisci(Oggetto("la maestra Mara", 73, -30, 0));
//95-96
    oggetti.inserisci(Oggetto("dei banchi", 43, -30, 0));
    oggetti.inserisci(Oggetto("delle sedie", 56, -30, 0));
    oggetti.inserisci(Oggetto("un registro", 88, 30, 0));
    oggetti.inserisci(Oggetto("una cattedra", 70, -30, 0));
    //3A
    oggetti.inserisci(Oggetto("dei banchi", 43, -31, 0));
//100-101
    oggetti.inserisci(Oggetto("delle sedie", 56, -31, 0));
    oggetti.inserisci(Oggetto("una cattedra", 70, -31, 0));
    oggetti.inserisci(Oggetto("una lavagna", 90, -31, 0));
    //FINE MODIFICHE ANTONIO BASILE
    //INIZIO MODIFICHE VACCA GIANLUCA
    oggetti.inserisci(Oggetto("un proiettore rotto", 80, -32, 0));
    oggetti.inserisci(Oggetto("uno schermo", 60, -32, 0));
//105-106
    oggetti.inserisci(Oggetto("una finestra grande", 90, -32, 0));
    oggetti.inserisci(Oggetto("un microfono", 90, -32, 0));
    oggetti.inserisci(Oggetto("dei strumenti musicali", 88, -32, 0));

    oggetti.inserisci(Oggetto("una scacchiera sulla cattedra", 73, -32, 0));
    oggetti.inserisci(Oggetto("un jukebox antico", 56, -32, 0));
//110-111
    oggetti.inserisci(Oggetto("un pannello di controllo delle luci", 70, -32, 0));
    //FINE MODIFICHE VACCA GIANLUCA
    //INIZIO modifiche SALVATORE VESTITA
    oggetti.inserisci(Oggetto("una biglietteria", 80, -33, 0));
    oggetti.inserisci(Oggetto("un frammento di giornale", 78, 33, 0));
    oggetti.inserisci(Oggetto("un treno", 55, -33, 0));
    oggetti.inserisci(Oggetto("una panchina", 71, -33, 0));
    //FINE modifiche SALVATORE VESTITA
    //INIZIO modifiche DELLA FOLGORE GRAZIA
//115-116
    oggetti.inserisci(Oggetto("un ticket_bus", 114, 5, 0));
    oggetti.inserisci(Autobus("un autobus", 115, 13, 20, false));
    oggetti.inserisci(Oggetto("una chiave_auto", 116, 5, 0));

    oggetti.inserisci(Oggetto("un'automobile", 117, 13, 0));
    //FINE modifiche DELLA FOLGORE GRAZIA
    //INIZIO modifiche DAVIDE MANTELLINI -- Palagiano Marcello: modifica codice luogo da 35 a 34
    oggetti.inserisci(Oggetto("una panca per gli addominali", 57, -34, 0));
//120-121
    oggetti.inserisci(Oggetto("un tapis roulant", 47, -34, 0));
    oggetti.inserisci(Oggetto("un terminale informativo",99, -34, 0));
    oggetti.inserisci(Oggetto("delle schede di allenamento", 84, 34, 0));

    oggetti.inserisci(Oggetto("una macchinetta",97, -34, 0));
    //FINE modifiche DAVIDE MANTELLINI
    //INIZIO modifiche GIACOMO CICALA
    oggetti.inserisci(Oggetto("una slotmachine", 86,-35, 0));
//125-126
    oggetti.inserisci(Oggetto("5 euro",90,-99, 0)); //Luogo -99 in quanto non visibili
    oggetti.inserisci(Oggetto("10 euro",91,-99, 0));
    oggetti.inserisci(Oggetto("20 euro",92,-99, 0));
    oggetti.inserisci(Oggetto("50 euro",93,-99, 0));
    oggetti.inserisci(Oggetto("100 euro",94,-99, 0));
    //Fine modifiche GIACOMO CICALA

    //inizio modifiche biblioteca Scatigna -- Palagiano Marcello: modifica codice luogo da 37 a 36 (biblioteca), da 38 a 37 (vetrina)
//130-131
    oggetti.inserisci(Oggetto("etichetta", 70, -36, 0));
    oggetti.inserisci(Oggetto("vetrina",19, -36, 0));
    oggetti.inserisci(Oggetto("astronave", 90, 37, 0));
    oggetti.inserisci(Oggetto("equipaggio", 91, 37, 0));
    //fine modifica Scatigna
    //INIZIO modifiche PALAGIANO MARCELLO
    oggetti.inserisci(Oggetto("un banco da lavoro", 43, -41, 0));
//135-136
    oggetti.inserisci(Oggetto("un pezzo di ricambio per astronave", 119, -41, 0));
    oggetti.inserisci(Oggetto("una pila di batterie", 70, -41, 0));
    oggetti.inserisci(Oggetto("una chiave_inglese", 118, 41, 0));
    oggetti.inserisci(Oggetto("un diario", 57, -41, 0));
    oggetti.inserisci(Oggetto("un cartello", 60, -41, 0));
//140-141
    oggetti.inserisci(Oggetto("un computer", 99, -41, 0));
    oggetti.inserisci(Oggetto("un meccanico", 73, -41, 0));
    //FINE modifiche PALAGIANO MARCELLO

    //_Modifiche_Matteo_Luceri
    oggetti.inserisci(Oggetto("una valigia", 155, 6, 0));
    oggetti.inserisci(Oggetto("uno zaino", 156, 6, 0));


//144-|

    for(int indiceInsieme = 1; indiceInsieme<=31; indiceInsieme++)
    {
        slotmachine.inserisci(indiceInsieme);
    }
    //FINE modifiche GIACOMO CICALA


    //INIZIO MODIFICA MICHELE ALBANO
    Ferite.inserisci(1,Ferita("un taglio al braccio","Un filo di rame sporgente ti ha tagliato il braccio e ora sanguini! ",1,1));
    Ferite.inserisci(10,Ferita("un taglio alla coscia","Un filo di rame sporgente ti ha tagliato la coscia e ora sanguini!",10,1));
    Ferite.inserisci(20,Ferita("una distorsione alla caviglia","Mentre ti muovevi sei inciampato su una mattonella sporgente e ti sei distorto la caviglia!",20,2));
    Ferite.inserisci(30,Ferita("una distorsione al braccio","Mentre ti muovevi hai colpito un tubo sporgente e ti sei distorto il braccio!",30,2));
    Ferite.inserisci(40,Ferita("una slogatura alla caviglia","Mentre ti muovevi sei inciampato su una mattonella sporgente e ti sei slogato la caviglia!",40,3));
    Ferite.inserisci(50,Ferita("una slogatura alla spalla","Mentre ti muovevi hai colpito un tubo sporgente e ti sei slogato il braccio!",50,3));
    Ferite.inserisci(60,Ferita("una bruciatura al volto","Un tubo e' scoppiato e il getto ti ha colpito in pieno volto!",60,5));
    Ferite.inserisci(70,Ferita("una bruciatura al petto","Un tubo e' scoppiato e il getto ti ha colpito in pieno petto!",70,4));
    Ferite.inserisci(80,Ferita("uno stiramento alla spalla","Mentre ti muovevi hai fatto un movimento errato e ti sei stirato la spalla! ",80,3));
    Ferite.inserisci(90,Ferita("uno stiramento al polpaccio","Mentre ti muovevi sei inciampato e ti sei stirato il polpaccio!",90,3));
    //FINE MODIFICA MICHELE ALBANO


    //INSERIMENTO DOCUMENTI
    //Modifica PMF(ufficio)
    primo_doc.inserisci("PILOTA", "Sono diventato pilota nel 1983", 1, 12);
    primo_doc.inserisci("RADIAZIONI", "L'astronave è munita di camici di piombo per proteggersi dalle radiazioni.", 2, 12);
    primo_doc.inserisci("CARTELLI", "Tutti i cartelli dell'astronave hanno un preciso significato", 3, 12);
    primo_doc.inserisci("BILANCI", "L'astronave ha speso di più di quello che ha guadagnato", 4, 12);
    primo_doc.inserisci("ANAGRAFICA", "Il secondo pilota e' nato nel 1957 nel mese di maggio e giorno 20", 5, 12);
    primo_doc.inserisci("MANUALE", "La seconda parte del manuale è in un altro documento", 6, 12);
    primo_doc.inserisci("REATTORE VOL 1", "Per spegnere il reattore devi: 1)premere il rosso 2)premere il giallo ", 7,12);
    primo_doc.inserisci("REATTORE VOL 2", "Per spegnere il reattore devi: 3)premere il verde 4)spingere la leva  ",8,12);
    primo_doc.inserisci("SECONDO PILOTA", "Il secondo pilota ha un diploma di laurea in elettronica e si e' sempre occupato dei guasti all'antenna", 9, 12);
    primo_doc.inserisci("AVVERTENZA", "Per uscire dall'astronave indossare il casco e la tuta", 10, 12);
    primo_doc.inserisci("CABINE PILOTI", "Ogni pilota ha il proprio armadietto, il secondo pilota ha voluto chiuderlo a chiave, se la porta sempre con se.", 11, 12);
    //Modifica PMF:fin qui.

    //INIZIO MODIFICA DAMONE MARCO
    //modifica Francesco De Giorgio
    // rubrica (nome, cognome, interno, descrizione, telefono): setto gli elementi da inserire nella rubrica
    //ho reso pubblico l'uso della funzione svuota
    svuotaLista(rubrica);
    //mi serve per svuotare la lista, prima la svuoto e poi la riempio con i dati che seguono

    persona = rubrica.primolista();
    persone.set_nome("Francesco");
    persone.set_cognome("De Giorgio");
    persone.set_interno("Primo Pilota");
    persone.set_descrizione("Francesco e' il Primo pilota della navicella!");
    persone.set_telefono("080-11223344");
    rubrica.inslista(persone, persona);

    persone.set_nome("Pilota");
    persone.set_cognome("Secondo");
    persone.set_interno("Secondo Pilota");
    persone.set_descrizione("Pilota e' il secondo pilota della navicella!");
    persone.set_telefono("080-55667788");
    rubrica.inslista(persone, persona);

    persone.set_nome("Giovanni");
    persone.set_cognome("Rossi");
    persone.set_interno("Sala Controllo del Reattore");
    persone.set_descrizione("Giovanni e' il tecnico del reattore, e controlla che non ci siano problemi!");
    persone.set_telefono("080-366749");
    rubrica.inslista(persone, persona);

    persone.set_nome("Luca");
    persone.set_cognome("Verdi");
    persone.set_interno("Cabina di Pilotaggio");
    persone.set_descrizione("Luca e' l'assistente pel primo pilota!");
    persone.set_telefono("080-4553268");
    rubrica.inslista(persone, persona);

    persone.set_nome("Simone");
    persone.set_cognome("Fabiani");
    persone.set_interno("Esterno dell'Astronave");
    persone.set_descrizione("Simone e' un'hostess della navicella!");
    persone.set_telefono("080-4412398");
    rubrica.inslista(persone, persona);

    persone.set_nome("Valerio");
    persone.set_cognome("Iacovone");
    persone.set_interno("Corridoio");
    persone.set_descrizione("Valerio e' un'hostess della navicella!");
    persone.set_telefono("080-4356732");
    rubrica.inslista(persone, persona);

    persone.set_nome("Nicola");
    persone.set_cognome("Cimino");
    persone.set_interno("Compartimento Stagno");
    persone.set_descrizione("Cimino e' addetto alla manutenzione della navicella!");
    persone.set_telefono("080-4159867");
    rubrica.inslista(persone, persona);


    //fine modifica De Giorgio
    //FINE MODIFICA DAMONE MARCO


    //InIZIO MODIFICA VACCA GIANLUCA PER FUNZIONAMENTO JUKEBOX
    inizializza_Jukebox(); //Inizializza il jukebox con i suoi brani.
    //FINE MODIFICA VACCA GIANLUCA


    // variabili
    //Modifiche ML
    aperto=false;
    n_oggettiZ = 0;
    peso_MaxZ = 5;
    n_oggettiZV = 0;
    peso_MaxZV = 8;
    el1 = 0;
    el2 = 0;
    el3 = 0;
    el4 = 0;
    el5 = 0;
    el6 = 0;
    //fine modifiche

    tempo = 350; //MODIFICA D-R(Colturi):Luoghi a Pagamento // Incremento ulteriore del tempo dovuto all' introduzione dei nuovi luoghi a Pagemento
    //INIZIO MODIFICHE BASILE ANTONIO
    gioco_impiccato = false;
    gioco_preside = false;
    gioco_prof_clara = false;
    gioco_prof_mara = false;
    //FINE MODIFICHE BASILE ANTONIO
    luogo_attuale = 6;
    passo_soluzione = 0;
    parete_stagna_aperta = 0;
    // modifica Gallone
    sazio = 120;  // modifica Gallone - inizializzo la variabile sazio a 120

    //INIZIO modifiche PALAGIANO MARCELLO
    batteria_cambiata=false;
    batteria.set_modello("A0001");
    batteria.set_stato(100);
    batterie.inpila(batteria);
    batteria.set_modello("A0002");
    batteria.set_stato(35);
    batterie.inpila(batteria);
    batteria.set_modello("A0003");
    batteria.set_stato(35);
    batterie.inpila(batteria);
    batteria.set_modello("A0004");
    batteria.set_stato(55);
    batterie.inpila(batteria);
    attivitaSelezionata = elenco.primolista();
    attivita.set_data("01 Gennaio 2003");
    attivita.set_autore("Capo Officina");
    attivita.set_descrizione("Eseguire collaudo su pezzo riparato nel motore");
    elenco.inslista(attivita, attivitaSelezionata);
    attivita.set_data("22 Marzo 2000");
    attivita.set_autore("Capo Officina");
    attivita.set_descrizione("Eseguita verifica impianto di raffreddamento motore");
    elenco.inslista(attivita, attivitaSelezionata);
    attivita.set_data("10 Giugno 2010");
    attivita.set_autore("Capo Officina");
    attivita.set_descrizione("Riparare ventola di aerazione");
    elenco.inslista(attivita, attivitaSelezionata);
    cliente.setNome("Frank");
    coda_attesa.incoda(cliente);
    cliente.setNome("John");
    coda_attesa.incoda(cliente);
    cliente.setNome("Kirk");
    coda_attesa.incoda(cliente);
    cliente.setNome("Michael");
    coda_attesa.incoda(cliente);
    //FINE modifiche PALAGIANO MARCELLO

}

//MODIFICA VACCA - INIZIALIZZA IL JUKEBOX. SI PUO' SOSTITUIRE CON UN SISTEMA CHE CARICHI I BRANI DA UN FILE
void Astro::inizializza_Jukebox()
{
    jukeboxAttivo = false; // Questo flag è usato per far interagire il giocatore col jukebox fin quando vorrà
    canzoneInRiproduzione = 0;
    svuotaLista(canzoni);
    canzoneScelta = canzoni.primolista(); // prima posizione della lista
    // INIZIALIZZAZIONE DELLE CANZONI NEL JUKEBOX

    canzone.set_nome("Yellow Submarine");
    canzone.set_artista("Beatles");
    canzone.set_anno(1966);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("We will rock you");
    canzone.set_artista("Queen");
    canzone.set_anno(1977);
    canzoni.inslista(canzone, canzoneScelta);


    canzone.set_nome("The man who sold the World");
    canzone.set_artista("David Bowie");
    canzone.set_anno(1970);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Hotel California");
    canzone.set_artista("The Eagles");
    canzone.set_anno(1976);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Crazy");
    canzone.set_artista("Willie Nelson");
    canzone.set_anno(1961);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Wish you were here");
    canzone.set_artista("Pink Floyd");
    canzone.set_anno(1975);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Blowin' in the wind");
    canzone.set_artista("Bob Dylan");
    canzone.set_anno(1963);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Imagine");
    canzone.set_artista("John Lennon");
    canzone.set_anno(1971);
    canzoni.inslista(canzone, canzoneScelta);

    canzone.set_nome("Generale");
    canzone.set_artista("Francesco De Gregori");
    canzone.set_anno(1978);
    canzoni.inslista(canzone, canzoneScelta);


    canzone.set_nome("Un giudice");
    canzone.set_artista("Fabrizio De Andre'");
    canzone.set_anno(1971);
    canzoni.inslista(canzone, canzoneScelta);

    canzoneScelta = canzoni.primolista(); //Verra' usata questa variabile per tenere conto di quale canzone sta suonando il jukebox
}

void Astro::introduzione()
{
    interfaccia.scrivi("\n\n\n# L'astronave condannata:un'avventura #");
    interfaccia.scrivi("# di Enrico Colombini e Chiara Tovena #\n");
    interfaccia.scrivi("(c) Dinosoft e Jackson Editrice 1985\n");
    interfaccia.scrivi("Sdraiato nella sabbia, ti godi il");
    interfaccia.scrivi("dolce calore del sole tropicale...\n");
    interfaccia.scrivi("Ora il sole picchia piu' forte,");
    interfaccia.scrivi("sei in pieno deserto e non c'e'");
    interfaccia.scrivi("traccia di oasi...\n");
    interfaccia.scrivi("Ti svegli di soprassalto nella tua");
    interfaccia.scrivi("cabina di comandante del 'Neutronia'.");
    interfaccia.scrivi("Fa molto caldo. Troppo caldo. Ci");
    interfaccia.scrivi("dev'essere qualcosa che non funziona.\n");
}

void Astro::tempo_specifiche()
{
    //Modifiche PMF(ufficio)
    /*if(tempo <=90){
            int l;
            if (primo_doc.get_luogo_documenti(l)== -99)
            {
                primo_doc.set_luogo_documenti( primo_doc.get_codice_documento() , 12);
                bacheca.NuovoMessaggioGioco("Nuovo documento inserito nell'ufficio");
            }
        }
        if(tempo <85){

            bacheca.NuovoMessaggioGioco("Nuovo documento inserito nell'ufficio");
        }
     */
    //Modifica PMF: fin qui.

    if (tempo <= 10)
    {
        interfaccia.scrivi("Sento un segnale di allarme.");
        bacheca.NuovoMessaggioGioco("*sbrigati! l'astronave sta per esplodere!!!");
    }
    if (tempo <= 5)
        interfaccia.scrivi("La temperatura e' insopportabile.");
    if (tempo <= 2)
        interfaccia.scrivi("La nave e' scossa da vibrazioni.");
    if (tempo <= 0)
    {
        interfaccia.scrivi("*** Troppo tardi! ***");
        interfaccia.scrivi("Il reattore e' fuori controllo.");
        interfaccia.scrivi("L'astronave e' disintegrata in minuscoli frammenti");
        interfaccia.scrivi("E' incredibile il silenzio delle esplosioni nel vuoto.");
    }
}

// Modifiche ML
bool Astro::indossa_specifiche()
{
    bool problemi = true;

    int codiceA = 0, codiceB = 0; // 4 23
    codiceA = oggetti.get_oggetto_indice_by_codice(50);
    codiceB = oggetti.get_oggetto_indice_by_codice(52);
    if (og == codiceA && oggetti.get_oggetto(codiceB).get_luogo() == 0)     // 4 23       //Modifica Mirco Sternativo
    {
        interfaccia.scrivi("Togli prima il camice.");
        stringa_risposta = "ti e' stato detto di togliere prima il camice."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta); //Modifica PMF(storia)
    }
    else if (og == codiceB && oggetti.get_oggetto(codiceA).get_luogo() == 0)       //Modifica Mirco Sternativo
    {
        interfaccia.scrivi("Togli prima la tuta.");
        stringa_risposta = "ti e' stato detto di togliere prima la tuta."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta); //Modifica PMF(storia)
    }
    else
        problemi = false;
    return problemi;
}

//Modifiche ML
bool Astro::indosso_specifiche()
{
    bool avvisato = true;

    if (og == 23)   //Modifica Mirco Sternativo
    {
        stringa_risposta = "l'hai preso.";     						//Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }

    if(og == 23)
        bacheca.CancellaMessaggioGioco("*stai assorbendo troppe radiazioni! non hai la giusta protezione!");
    else
        avvisato = false;
    return avvisato;
}

bool Astro::prendi_specifiche()
{
    bool problemi = true;


    if(og == 143 && oggetti.get_oggetto(144).get_luogo() == 0)
    {
        // controllo che l'oggetto sia la valigia e che nell'inventario ci sia lo zaino
        interfaccia.scrivi("Lascia prima lo zaino.");
    }
    else if(og == 144 && oggetti.get_oggetto(143).get_luogo() == 0)
    {
        // controllo che l'oggetto sia lo zaino e che nell'inventario ci sia la valigia
        interfaccia.scrivi("Lascia prima la valigia.");
    }
//INIZIO modifiche DELLA FOLGORE GRAZIA
    else if (og == 117 && oggetti.get_oggetto(116).get_luogo() != 0)  //se non possiedi il ticket_bus (autobus->117)
    {
        interfaccia.scrivi("Devi prendere un ticket_bus.");
        stringa_risposta = "ti e' stato detto di prendere un ticket_bus.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else if (og == 117 && oggetti.get_oggetto(116).get_luogo() == 0)  //se possiedi il ticket_bus
    {
        if (automobile.get_inUso()==false)
        {
            interfaccia.scrivi("Sei salito sull'autobus.");
            oggetti.set_luogo(117, 0);	//sei sull'autobus
            autobus.set_inUso(true);
            problemi = false;
            stringa_risposta = "sei salito sull'autobus.";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
        else
        {
            interfaccia.scrivi("Devi prima lasciare l'automobile");
            stringa_risposta = "Ti e' stato detto di lasciare prima l'automobile.";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
    }
    else if (og == 119 && oggetti.get_oggetto(118).get_luogo() != 0) // se non possiedi le chiavi dell' auto (auto-> 119)
    {
        interfaccia.scrivi("Devi prendere la chiave.");
        stringa_risposta = "ti e' stato detto di prendere la chiave.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else if (og == 119 && oggetti.get_oggetto(118).get_luogo() == 0) // se possiedi le chiavi dell' auto
    {
        if (autobus.get_inUso()==false)
        {
            interfaccia.scrivi("Sei salito sull'automobile.");
            //INIZIO modifiche PALAGIANO MARCELLO
            if(batteria_cambiata==false)
            {
                interfaccia.scrivi("Accidenti! La batteria e' quasi scarica! Meglio andare da un meccanico.");
            }
            //FINE modifiche PALAGIANO MARCELLO
            oggetti.set_luogo(119, 0);
            automobile.set_inUso(true);
            problemi = false;
            stringa_risposta = "Sei salito sull'automobile.";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
        else
        {
            interfaccia.scrivi("Devi prima lasciare l'autobus");
            stringa_risposta = "Ti e' stato detto di lasciare prima l'autobus.";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
    }

    else if (luogo_attuale == 37 || luogo_attuale == 38)
    {
        Lista<int>::posizione p = libriInPrestito.primolista();
        for (int j = 0; ((!libriInPrestito.finelista(p)) &&
                         (j < MAX_LIBRI)); p = libriInPrestito.succlista(p))
        {
            j++;
        }

        Oggetto oggettoPreso = oggetti.get_oggetto(og);
        int codOggetto = oggettoPreso.get_codice();
        if (codOggetto >= 90)
        {
            libriInPrestito.inslista(codOggetto, p);
        }

        system("cls");
        cout << "Hai preso in prestito " << oggettoPreso.get_nome() << ".\n";


        oggetti.set_luogo(og, 0);
    }

    //FINE modifiche DELLA FOLGORE GRAZIA
    else
        problemi = false;
    return problemi;
}


bool Astro::preso_specifiche()
{
    //Modifiche Mirco Sternativo
    bool avvisato = true;

    if ((og == 11 || og == 4 || og == 23 || og == 25) && (oggetti.get_oggetto(143).get_luogo() == 0))
    {
        if(oggetti.get_oggetto(og).get_peso() > peso_MaxZV && og != 25)
        {
            // controllo che il peso dell'oggetto sia maggiore allo spazio disponibile
            // nella valigia e che l'oggetto sia diverso dal manuale
            oggetti.set_luogo(og,luogo_attuale);
            interfaccia.scrivi("La valigia e' troppo piena...");
            interfaccia.scrivi("(Suggerimento: togli qualcosa dalla valigia.)");
        }
        else if(oggetti.get_oggetto(og).get_peso() > peso_MaxZV && og == 25)
        {
            oggetti.set_luogo(og,0);
            interfaccia.scrivi("La valigia e' troppo piena...");
            interfaccia.scrivi("Lo tengo in mano, e' troppo importante.");
            interfaccia.scrivi("(Suggerimento: controlla nell'inventario)");
        }
        else
        {
            interfaccia.scrivi("Ora e' in valigia.");
            ins.inserisci(oggetti.get_oggetto(og).get_codice());
            n_oggettiZV++;
            peso_MaxZV -= oggetti.get_oggetto(og).get_peso();
        }
    }
    else if((og == 11 || og == 4 || og == 23 || og == 25) &&
            (oggetti.get_oggetto(144).get_luogo() == 0))
    {
        if(oggetti.get_oggetto(og).get_peso() > peso_MaxZ && og != 25)
        {
            // controllo che il peso dell'oggetto sia maggiore allo spazio
            // disponibile nella valigia e che l'oggetto sia diverso dal manuale
            oggetti.set_luogo(og,luogo_attuale);
            interfaccia.scrivi("Lo zaino e' troppo pieno...");
            interfaccia.scrivi("(Suggerimento: togli qualcosa dallo zaino.)");
        }
        else if(oggetti.get_oggetto(og).get_peso() > peso_MaxZ && og == 25)
        {
            oggetti.set_luogo(og,0);
            interfaccia.scrivi("Lo zaino e' troppo pieno...");
            interfaccia.scrivi("Lo tengo in mano, e' troppo importante.");
            interfaccia.scrivi("(Suggerimento: controlla nell'inventario)");
        }
        else
        {
            interfaccia.scrivi("Ora e' nello zaino.");
            z.inpila(oggetti.get_oggetto(og).get_codice()); //*
            n_oggettiZ++;
            peso_MaxZ -= oggetti.get_oggetto(og).get_peso();
        }
    }
    else
        avvisato = false;
    if(og == 23)
    {
        stringa_risposta = "l'hai preso.";     //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
        bacheca.CancellaMessaggioGioco
        ("*stai assorbendo troppe radiazioni! non hai la giusta protezione!");
    }
    else
    {
        avvisato = false;
    }

    return avvisato;
    //Fine Modifiche
}

bool Astro::lascia_specifiche()
{
    /*bool lasciato = true;

    if (luogo_attuale >= 9) {
    	oggetti.set_luogo(og, -99);
    	interfaccia.scrivi("Si e' perso nello spazio.");
    	stringa_risposta = "si e' perso nello spazio!!";    //Modifica PMF(storia)
    	storia_gioco.insStoria(stringa_comando , stringa_risposta); //Modifica PMF(storia)
    } else
    	lasciato = false;
    return lasciato;*/
    //modifica Gallone

    bool lasciato = true;
    //INIZIO modifiche DELLA FOLGORE GRAZIA
    //INIZIO modifiche PALAGIANO MARCELLO
    if (luogo_attuale == 13 || (mappa.get_nome_luogo(luogo_attuale) == "Bari")  || (mappa.get_nome_luogo(luogo_attuale) == "Roma") || (mappa.get_nome_luogo(luogo_attuale) == "Pisa") || luogo_attuale==41)
    {
        //FINE modifiche PALAGIANO MARCELLO
        if (og == 117) //autobus
        {
            oggetti.set_luogo(og, luogo_attuale);
            autobus.set_inUso(false);
            interfaccia.scrivi("Hai lasciato l'autobus");
            stringa_risposta = "hai lasciato l'autobus";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
        else if(og == 119)  //automobile
        {
            oggetti.set_luogo(og, luogo_attuale);
            automobile.set_inUso(false);
            interfaccia.scrivi("Hai lasciato l'automobile");
            stringa_risposta = "hai lasciato l'automobile";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
    }
    else
    {
        lasciato = false;
        if(og == 117)
        {
            interfaccia.scrivi("Non puoi scendere dall'autobus qui");
            stringa_risposta = "hai tentato di scendere dall'autobus dove non potevi";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
        if(og == 119)
        {
            interfaccia.scrivi("Non puoi scendere dall'auto qui");
            stringa_risposta = "hai tentato di scendere dall'auto dove non potevi";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
    }
    //FINE modifiche DELLA FOLGORE GRAZIA

    //Inizio Modifica Gallone - aggiorno il metodo per integrare le nuove funzionalità
    riferimento_tasca = tasca.primolista();
    riferimento_zaino = zaino_frigo.primolista();

    if (luogo_attuale == 9 || luogo_attuale == 10 || luogo_attuale == 11 || (luogo_attuale == 7 && parete_stagna_aperta == 1))
    {
        if (og >= 35 && og <=37)
        {
            while (!tasca.finelista(riferimento_tasca))
            {
                if (oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_codice() == oggetti.get_oggetto(og).get_codice())
                    tasca.canclista(riferimento_tasca);
                else
                    riferimento_tasca=tasca.succlista(riferimento_tasca);
            }
        }
        else if (og >= 25 && og <= 34)
        {
            while (!zaino_frigo.finelista(riferimento_zaino))
            {
                if (oggetti.get_oggetto(zaino_frigo.leggilista(riferimento_zaino)).get_codice() == oggetti.get_oggetto(og).get_codice())
                    zaino_frigo.canclista(riferimento_zaino);
                else
                    riferimento_zaino=zaino_frigo.succlista(riferimento_zaino);
            }
        }
        //Fine modifica Gallone
        oggetti.set_luogo(og, -99);
        interfaccia.scrivi("Si e' perso nello spazio.");
    }
    else
        lasciato = false;
    return lasciato;
    // fine modifica gallone
}

void Astro::save_specifiche(ofstream &file)
{
    file << parete_stagna_aperta << '\n';
    file << cabina_aperta<< '\n';
}

void Astro::load_specifiche(ifstream &file)
{
    file >> parete_stagna_aperta;
    file >> cabina_aperta;
}

//Inizio modifiche Biblioteca Scatigna
void Astro::libro()
{
    switch (oggetti.get_oggetto(og).get_codice())
    {
    case 90:
        cout
                << "\n|------------------------------------------|-----------------------------------|";
        cout
                << "\n|               ASTRONAVE                  |                                   |";
        cout
                << "\n| Un'astronave (detta anche nave           | L'umanita' non ha mai costruito   |";
        cout
                << "\n| stellare) e' un veicolo spaziale         | un'autentica astronave, molti     |";
        cout
                << "\n| progettato per il viaggio interstellare  | scienziati (Freeman Dyson e il    |";
        cout
                << "\n| cioe' in grado di raggiungere sistemi    | Progetto Orione) hanno discusso   |";
        cout
                << "\n| stellari diversi da quello di partenza.  | diverse ipotesi ingegneristiche   |";
        cout
                << "\n| La fantascienza (in particolare il filone| riguardanti la possibilita' di    |";
        cout
                << "\n| della space opera) abbonda di storie che | intraprendere in futuro dei viaggi|";
        cout
                << "\n| descrivono questo genere di veicoli      | interstellari.                    |";
        cout
                << "\n| degli anni molti autori hanno descritt   |                                   |";
        cout
                << "\n| e nel corso astronavi di varie forme:    |                                   |";
        cout
                << "\n| in alcuni anime l'astronave principale   |                                   |";
        cout
                << "\n| corazzata giapponese della seconda guerra|                                   |";
        cout
                << "\n| aveva la forma di una mondiale, nella    |                                   |";
        cout
                << "\n| Guida galattica per gli autostoppisti ci |                                   |";
        cout
                << "\n| sono astronavi a forma di mattoni        |                                   |";
        cout
                << "\n| giallim mentre le classiche astronavi    |                                   |";
        cout
                << "\n| alien degli anni cinquanta sono i celebri|                                   |";
        cout
                << "\n|dischi volanti.                           |                                   |";
        cout
                << "\n| -----------------------------------------|-----------------------------------|";
        system("pause");
        break;
    case 91:
        cout
                << "\n| -----------------------------------------|-----------------------------------|";
        cout
                << "\n|                EQUIPAGGIO                                                    |";
        cout
                << "\n| Questa e' una lista delle persone che    | scritti in corsivo.Essi non hanno |";
        cout
                << "\n| hanno partecipato come equipaggi         | specifico ruolo ma sono inseriti  |";
        cout
                << "\n| divisi in ordine                         | specialisti di carico per ragioni |";
        cout
                << "\n| cronologico rispetto alla missione.      | di spazio.                        |";
        cout
                << "\n| Abbreviazioni usate:                     | STS-61-A e' l'unico volo, lanciato|";
        cout
                << "\n| PC = Comandante del carico utile         | nel 1985, che ha portato a bordo  |";
        cout
                << "\n| MSE = Ingegnere di volo dell'USAF        | equipaggio maggiore di sette      |";
        cout
                << "\n| Mir = Lanciato come equipaggio della     | astronauti.                       |";
        cout
                << "\n| stazione spaziale Mir                    |                                   |";
        cout
                << "\n| ISS = Lanciato come equipaggio della     |                                   |";
        cout
                << "\n| Stazione Spaziale Internazionale (ISS).  |                                   |";
        cout
                << "\n| I nomi degli astronauti di ritorno dalla |                                   |";
        cout
                << "\n| Mir o dall'ISS sullo Space Shuttle sono  |                                   |";
        cout
                << "\n| -----------------------------------------|-----------------------------------|";
        system("pause");
        break;
    }


}
//Fine modifiche Biblioteca Scatigna


//Inizio modifiche Biblioteca Scatigna -- Palagiano Marcello: modifica codice luogo da 37 a 36 (biblioteca), da 38 a 37 (vetrina)
void Astro::scadenza()
{
    Lista<int>::posizione p = libriInPrestito.primolista();

    //DECREMENTO AUTOMATICO
    for (int j = 0; ((!libriInPrestito.finelista(p)) && (j < MAX_LIBRI)); p =libriInPrestito.succlista(p))
    {
        int oggetto = libriInPrestito.leggilista(p);
        //cout << "oggetto: " << oggetto << " \n";

        int libro = oggetto - 90;

        //cout << "libro : " << libro << " \n";

        int scadenza = --scadenze[libro];
        //cout << scadenza << " \n";;

        if (scadenza == 10)
        {
            for (i = 1; i <= oggetti.get_n_oggetti(); i++)
            {
                if (oggetti.get_oggetto(i).get_codice() == oggetto)
                {
                    cout << "AVVISO: Mancano 10min per la restituzione del libro "
                         << "\n        Corri in Biblioteca!\n";
                    break;
                }
            }
        }
        else if (scadenza == 0)
        {
            scadenze[libro] = 100;
            for (i = 1; i <= oggetti.get_n_oggetti(); i++)
            {
                if (oggetti.get_oggetto(i).get_codice() == oggetto)
                {
                    oggetti.set_luogo(i, 37);

                    cout << "\nIl " << oggetti.get_oggetto(i).get_nome() << " e' tornato in Biblioteca. \n\n";
                    cout << "\nA causa della mancata restituzione hai perso 10 minuti del tuo tempo.";
                    break;
                }
            }
            libriInPrestito.canclista(p);
            tempo = tempo - 10; //PENALITA
        }
        j++;
    }
}
//Fine modifiche Biblioteca Scatigna


//Inizio modifiche Biblioteca Scatigna
void Astro::aggiorna_specifiche()
{
    scadenza();
}
//Fine modifiche Biblioteca Scatigna

void Astro::epitaffio()
{
    interfaccia.scrivi("### IL GAZZETTINO DELLA GALASSIA ###");
    interfaccia.scrivi("");
    interfaccia.scrivi("- Tragedia al largo di Vega -");
    interfaccia.scrivi("");
    interfaccia.scrivi("L'astronave 'Neutronia', in servizio");
    interfaccia.scrivi("passeggeri con 250 persone a bordo,");
    interfaccia.scrivi("e' stata distrutta da una violenta");
    interfaccia.scrivi("esplosione, causata probabilmente");
    interfaccia.scrivi("da imperizia del comandante (un");
    interfaccia.scrivi("novellino, stando a indiscrezioni");
    interfaccia.scrivi("raccolte dal nostro corrispondente)");
    interfaccia.scrivi("Il responsabile del peggior disastro");
    interfaccia.scrivi("della storia galattica sara' di certo");
    interfaccia.scrivi("degradato alla memoria.");
    interfaccia.scrivi("");
}
void Astro::futuro()
{
    interfaccia.scrivi("### IL GAZZETTINO DELLA GALASSIA ###\n");
    interfaccia.scrivi("- MIRACOLO NELLO SPAZIO -\n");
    interfaccia.scrivi("L'astronave 'Neutronia', in servizio");
    interfaccia.scrivi("passeggeri con 250 persone a bordo,");
    interfaccia.scrivi("e' stata salvata da sicura distruzione");
    interfaccia.scrivi("grazie al coraggio e al sangue freddo");
    interfaccia.scrivi("del secondo pilota, che,dopo essersi ripreso a seguito di un brutto colpo, ");
    interfaccia.scrivi("e' riuscito a disattivare il reattore impazzito.");
    interfaccia.scrivi("Il suo nome verra' ricordato per");
    interfaccia.scrivi("sempre tra gli eroi della nostra");
    interfaccia.scrivi("flotta galattica\n");
    interfaccia.scrivi("a differenza del comandante che sembra essersi dissolto nel nulla\n");
    interfaccia.pausa(); // <SP>

    stringa_risposta = "hai viaggiato avanti nel tempo, scoprendo di aver salvato l'astronave"; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta); //Modifica PMF(storia)

    fine_partita = true;
    riparti = false; // end
    //Modifica PMF(storia)
    string storia_completa;
    do
    {
        storia_completa = interfaccia.leggi_stringa("Vuoi visualizzare la storia della tua partita? (s/n)");
    }
    while  (storia_completa[0] != 's' && storia_completa[0] != 'n');
    if (storia_completa[0] == 's')
    {
        interfaccia.scrivi("\n**** COMPLIMENTI HAI VINTO!!! VEDIAMO LE MOSSE CHE TI HANNO PORTATO ALLA VITTORIA: ****\n");
        storia_gioco.stampaStoria();
        interfaccia.scrivi("\n\n                                ...sei stato bravo e te la sei cavata davvero bene!\n\n");
    }
    //Modifica PMF: fin qui.


}
void Astro::setmappapassato(bool b)
{
    aperto=true;
}
bool Astro::mappaaperta()
{
    return aperto;
}
void Astro::passato()
{
    fstream crono("Cronologia.odb",fstream::in);

    ifstream f("Mappapassato.nav",ios::in); //apro il file su cui ho rappresentato la mappa del passato
    bool aperto=f.good(); //esito dell'apertura del file
    if (aperto) //se il file di input è stato aperto correttamente
    {
        //salito_temp = salito; //salvo lo stato di salito in salito temporaneo
        salito = false;
        motorino.set_livello_benzina(0);
        Mappa M(f,crono);
        interfaccia.scrivi("Sei tornato a dieci anni fa,");
        interfaccia.scrivi("quando eri un semplice pilota...");
        interfaccia.scrivi("prima di diventare il comandate che sei adesso!");
        interfaccia.scrivi("Vai in giro per l'astronave ");
        interfaccia.scrivi("per vedere se vi sono dei cambiamenti.");

        stringa_risposta = "hai scelto di viaggiare indietro nel tempo di 10 anni.";  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

        mappa=M;
        setmappapassato(true);
    }
    else
        cout<<"Errore apertura file \"Mappapassato.nav\""<<endl; //altrimenti stampa messaggio di errore

}
void Astro::presente(){
    	fstream crono("Cronologia.odb",fstream::in);
        ifstream f("Mappa.nav",ios::in); //apro il file su cui ho rappresentato la mappa del passato
	    bool aperto=f.good(); //esito dell'apertura del file
        if (aperto) //se il file di input è stato aperto correttamente
		  {
		    Mappa M(f,crono);
	        interfaccia.scrivi("Ok, siamo nel presente.");

	        stringa_risposta = "sei tornato al presente.";     //Modifica PMF(storia)
	        storia_gioco.insStoria(stringa_comando , stringa_risposta); //Modifica PMF(storia)

	        mappa=M;

	        Storia sto=storia_gioco; //Modifica PMF(storia)

	         Astro partita = Astro();

	        partita.storia_gioco=sto;//Modifica PMF(storia)

            partita.ciak(M,f);
             //modifica salito per viaggio nel tempo

           }
		     else cout<<"Errore apertura file \"Mappa.nav\""<<endl; //altrimenti stampa messaggio di errore
}
void Astro::encomio()
{
    interfaccia.scrivi("### IL GAZZETTINO DELLA GALASSIA ###\n");
    interfaccia.scrivi("- Comandante salva astronave -\n");
    interfaccia.scrivi("L'astronave 'Neutronia', in servizio");
    interfaccia.scrivi("passeggeri con 250 persone a bordo,");
    interfaccia.scrivi("e' stata salvata da sicura distruzione");
    interfaccia.scrivi("grazie al coraggio e al sangue freddo");
    interfaccia.scrivi("del comandante, che e' riuscito a");
    interfaccia.scrivi("disattivare il reattore impazzito.");
    interfaccia.scrivi("Il suo nome verra' ricordato per");
    interfaccia.scrivi("sempre tra gli eroi della nostra");
    interfaccia.scrivi("flotta galattica\n");
    interfaccia.scrivi("\n- Congratulazioni! -\n");
    //Modifica PMF(storia)
    string storia_completa;
    do
    {
        storia_completa = interfaccia.leggi_stringa("Vuoi visualizzare la storia della tua partita? (s/n)");
    }
    while  (storia_completa[0] != 's' && storia_completa[0] != 'n');
    if (storia_completa[0] == 's')
    {
        interfaccia.scrivi("\n**** COMPLIMENTI HAI VINTO!!! VEDIAMO LE MOSSE CHE TI HANNO PORTATO ALLA VITTORIA: ****\n");
        storia_gioco.stampaStoria();
        interfaccia.scrivi("\n\n                                ...sei stato bravo e te la sei cavata davvero bene!\n\n");
    }
    //Modifica PMF: fin qui
}

/* 10:
 */
void Astro::azione_10()
{
    if (oggetti.get_oggetto(og).get_luogo() != 0 && oggetti.get_oggetto(og).get_luogo() != 20) //Modifiche_ML
    {
        interfaccia.scrivi("Non ce l'hai.");
        stringa_risposta = "non e' stato possibile perche' non ce l'avevi.";  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else if (!(luogo_attuale == 9) || (luogo_attuale == 7
                                       && parete_stagna_aperta == 1))
        lascia();
    else
    {
        interfaccia.scrivi("L'aria! L'aria! Aaaagh!!!");
        morto();
    }
}

/* 11:
 */
void Astro::azione_11()
{
    interfaccia.scrivi("E' la tuta per la tua attivita' extraveicolare.");
    stringa_risposta = "hai notato che era la tuta per uscire dall'astronave.";//Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 12:
 */
void Astro::azione_12()
{
    interfaccia.scrivi("E' privo di conoscenza ed ha");
    interfaccia.scrivi("un'ammaccatura nel casco.");
    interfaccia.scrivi("Probabilmente e' stato colpito");
    interfaccia.scrivi("da un piccolo meteorite");
    interfaccia.scrivi("mentre riparava l'antenna.");
    interfaccia.scrivi("Per fortuna, e' ancora vivo.");

    stringa_risposta = "hai notato che il secondo pilota era in pericolo e andava portato in salvo!"; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 13:
 */
void Astro::azione_13()
{
    interfaccia.scrivi("Non e' meglio leggerlo?");

    stringa_risposta = "forse dovevi leggere, non guardare.";  //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 14:
 */
void Astro::azione_14()
{
    interfaccia.scrivi("E' piuttosto pesante.");
    interfaccia.scrivi("Probabilmente, e' trattato al piombo.");

    stringa_risposta = "hai notato che il camice era abbastanza pesante."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 15:
 */
void Astro::azione_15()
{
    if (oggetti.get_oggetto(og).get_luogo() == luogo_attuale)
    {
        interfaccia.scrivi("Prendilo in mano, prima.");

        stringa_risposta = "prima dovevi prenderlo.";   //Modifics PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else if(oggetti.get_oggetto(og).get_luogo() == 20)
    {
        if(ins.appartiene(55))
        {
            interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -");
            interfaccia.scrivi("-   REATTORE POSITRONICO    -");
            interfaccia.scrivi("-       Codice: yt8421     -");
            interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
            interfaccia.scrivi("- Per attivare il reattore,");
            interfaccia.scrivi("tirare la leva e poi premere");
            interfaccia.scrivi("in sequenza i pulsanti verde,");
            interfaccia.scrivi("giallo e rosso.");
            interfaccia.scrivi("- Per disattivare il reattore...\n");
            interfaccia.scrivi("Dannazione! La pagina e' strappata.");

            stringa_risposta = "hai letto il MANUALE DEL REATTORE, ma hai notato che la pagina era strappata!";  //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
        }
        else if(z.leggipila() == 55)
        {
            interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -");
            interfaccia.scrivi("-   REATTORE POSITRONICO    -");
            interfaccia.scrivi("-       Codice: yt8421     -");
            interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
            interfaccia.scrivi("- Per attivare il reattore,");
            interfaccia.scrivi("tirare la leva e poi premere");
            interfaccia.scrivi("in sequenza i pulsanti verde,");
            interfaccia.scrivi("giallo e rosso.");
            interfaccia.scrivi("- Per disattivare il reattore...\n");
            interfaccia.scrivi("Dannazione! La pagina e' strappata.");

            stringa_risposta = "hai letto il MANUALE DEL REATTORE, ma hai notato che la pagina era strappata!";  //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
        }
        else
        {
            interfaccia.scrivi("Devi prima lasciare: ");
            oggetti.get_zaino(z.leggipila());
        }
    }
    else
    {
        interfaccia.scrivi("- MANUALE DI ISTRUZIONI DEL -");
        interfaccia.scrivi("-   REATTORE POSITRONICO    -");
        interfaccia.scrivi("-       Codice: yt8421     -");
        interfaccia.scrivi("-     Mod. YTREWQ 8421      -\n");
        interfaccia.scrivi("- Per attivare il reattore,");
        interfaccia.scrivi("tirare la leva e poi premere");
        interfaccia.scrivi("in sequenza i pulsanti verde,");
        interfaccia.scrivi("giallo e rosso.");
        interfaccia.scrivi("- Per disattivare il reattore...\n");
        interfaccia.scrivi("Dannazione! La pagina e' strappata.");

        stringa_risposta = "hai letto il MANUALE DEL REATTORE, ma hai notato che la pagina era strappata!";  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
}

/* 16:
 */
void Astro::azione_16()
{
    interfaccia.scrivi("- TEMPERATURA REATTORE -\n");
    interfaccia.scrivi_parziale("Segna ");
    interfaccia.scrivi_parziale(840 - tempo * 4);
    interfaccia.scrivi(" gradi e sta salendo velocemente.");
    interfaccia.scrivi(" C'e' un segno rosso a 800 gradi.");

    stringa_risposta = "hai guardato l'indicatore della TEMPERATURA DEL REATTORE."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 17:
 */
void Astro::azione_17()
{
    interfaccia.scrivi("- S.O.S. GALATTICO -\n");
    interfaccia.scrivi("Premere il pulsante solo in caso di emergenza.");
    interfaccia.scrivi("Ogni abuso verra' punito.");

    stringa_risposta = "hai letto l'etichetta sotto il pulsante per l' S.O.S. GALATTICO."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 18:
 */
void Astro::azione_18()
{
    interfaccia.scrivi("Una scritta lampeggia brevemente:");
    interfaccia.scrivi("- ANTENNA ESTERNA DIFETTOSA -");

    stringa_risposta = "hai appreso un dettaglio dell'ANTENNA ESTERNA."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 19:
 */
void Astro::azione_19()
{
    interfaccia.scrivi("E' alla base di una scaletta e dice:\n");
    interfaccia.scrivi("INGRESSO RISERVATO AL");
    interfaccia.scrivi("PERSONALE DI BORDO.");

    stringa_risposta = "hai letto il cartello davanti alla cabina di pilotaggio."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 20:
 */
void Astro::azione_20()
{
    luogo_attuale = 1;
    if (oggetti.get_oggetto(20).get_luogo() == 9)
    {
        interfaccia.scrivi("Se solo ci fosse qui il secondo");
        interfaccia.scrivi("pilota, il solo che se ne intende");
        interfaccia.scrivi("di problemi tecnici!");

        stringa_risposta = "sei andato nella cabina di pilotaggio."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
}

/* 21:
 */
void Astro::azione_21()
{
    interfaccia.scrivi("Meglio non svegliare i passeggeri,");
    interfaccia.scrivi("potrebbero farsi prendere dal panico.");

    stringa_risposta = "era meglio non disturbare i passeggeri...";   //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 22:
 */
void Astro::azione_22()
{
    interfaccia.scrivi("E' posto ad ovest e dice:\n");
    interfaccia.scrivi("- ATTENZIONE: -\n");
    interfaccia.scrivi("STANZA DEPRESSURIZZATA");

    stringa_risposta = "hai letto un avviso davanti al compartimento stagno."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 23:
 */
void Astro::azione_23()
{
    if (oggetti.get_oggetto(23).get_luogo() != -9999)  //24
    {
        interfaccia.scrivi("Gia' fatto.");
        stringa_risposta = "e' stato inutile perche' avevi gia' aperto l'armadietto.";   //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else if (oggetti.get_oggetto(24).get_luogo() != 0) //23
    {
        interfaccia.scrivi("E' chiuso a chiave.");
        bacheca.NuovoMessaggioGioco("*per aprire l'armadietto serve la chiave..");
        stringa_risposta = "hai notato che l'armadietto era chiuso a chiave."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifiche PMF(storia)
    }
    else
    {
        interfaccia.scrivi("Fatto.");

        stringa_risposta = "l'hai aperto.";        //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

        oggetti.set_luogo(25, luogo_attuale); //24
        oggetti.set_luogo(23, luogo_attuale); //22
        //MODIFICA DAMONE MARCO
        // modifica De Giorgio
        //ho inserito il tesserino nell'armadietto situato nella cabina del secondo pilota
        oggetti.set_luogo(57, luogo_attuale);
        //FINE MODIFICA DAMONE MARCO
    }
}

/* 24:
 */
//MODIFICA DAMONE MARCO
//Modifica De Giorio inserisco la rubrica
void Astro::azione_24()
{
    if (oggetti.get_oggetto(55).get_luogo() != -9999)
    {
        interfaccia.scrivi("E' vuoto.");
        stringa_risposta = "hai notato che l'armadietto era vuoto."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else
    {
        interfaccia.scrivi("Fatto.");
        //ho inserito la rubrica nell'armadietto situato nella cabina del protagonista
        oggetti.set_luogo(55, luogo_attuale);
    }
}
//FINE MODIFICA DAMONE MARCO
/* 25:
 */
void Astro::azione_25()
{
    interfaccia.scrivi("Dimmi: 'Premi il rosso'");
    interfaccia.scrivi("o 'Premi il verde'.");
    stringa_risposta = "forse dovevi digitare meglio il comando...";   //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 26:
 */
void Astro::azione_26()
{
    int i;

    if (parete_stagna_aperta == 1)
    {
        interfaccia.scrivi("Click.");
        stringa_risposta = "hai sentito uno strano rumore...";   //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else
    {
        interfaccia.scrivi("La parete ad est si chiude.");
        interfaccia.scrivi("La parete ad ovest si apre");
        interfaccia.scrivi("verso lo spazio esterno.");
        interfaccia.scrivi("L'aria esce sibilando.");
        stringa_risposta = "si e' aperta una parete ad ovest, verso la poppa dell'astronave."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

        if (oggetti.get_oggetto(4).get_luogo() != 0
                || oggetti.get_oggetto(11).get_luogo() != 0)
        {
            interfaccia.scrivi("\nAaaagh!");
            morto(); // goto 1200
        }
        else
        {
            for (i = 1; i <= oggetti.get_n_oggetti(); i++)
            {
                if (oggetti.get_oggetto(i).get_luogo() == luogo_attuale)
                {
                    interfaccia.scrivi(oggetti.get_oggetto(i).get_nome()
                                       + " si perde nello spazio");
                    oggetti.set_luogo(i, -9999);
                }
            }
            parete_stagna_aperta = 1;
        }
    }
}

/* 27:
 */
void Astro::azione_27()
{
    if (parete_stagna_aperta == 0)
    {
        interfaccia.scrivi("Click.");
        stringa_risposta = "hai sentito uno strano rumore...";     //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else
    {
        interfaccia.scrivi("La parete ad ovest si chiude.");
        interfaccia.scrivi("La parete ad est si apre");
        interfaccia.scrivi("verso il corridoio.");
        interfaccia.scrivi("L'aria rientra sibilando.");

        stringa_risposta = "si e' chiusa la parete ad ovest: la stanza si e' ripressurizzata.";  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

        parete_stagna_aperta = 0;
        if (!(oggetti.get_oggetto(21).get_luogo() != 0 //20
                || oggetti.get_oggetto(24).get_luogo() != -9999))    //23
        {
            interfaccia.scrivi("\nIl secondo pilota rinviene, si rende");
            interfaccia.scrivi("subito conto della situazione e dice:\n");
            interfaccia.scrivi("- Presto, ferma il reattore!");
            interfaccia.scrivi("Ecco la chiave e il pass per...");
            interfaccia.scrivi("Poi perde nuovamente i sensi");
            bacheca.CancellaMessaggioGioco("*per aprire l'armadietto serve la chiave..");
            oggetti.set_luogo(21, luogo_attuale); //23
            oggetti.set_luogo(24, luogo_attuale); //28
        }
    }
}

/* 28:
 */
void Astro::azione_28()
{
    interfaccia.scrivi("- L'EMERGENZA E' IN AGGUATO! -");
    interfaccia.scrivi("-    Porta sempre con te     -");
    interfaccia.scrivi("-  il manuale del reattore.  -");
    stringa_risposta = "ti ha consigliato di portare sempre con te il manuale del reattore!"; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 29:
 */
void Astro::azione_29()
{
    interfaccia.scrivi("Il tecnico e' il secondo pilota.");

    stringa_risposta = "non hai potuto ripararla perche' non sei il secondo pilota."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 30:
 */
void Astro::azione_30()
{
    interfaccia.scrivi("Dimmi: 'Premi il rosso', 'Premi");
    interfaccia.scrivi("il verde' o 'Premi il giallo'.");

    stringa_risposta = "forse dovevi digitare meglio il comando..."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

/* 31:
 */
//START DAMONE MARCO
// Modifica De Giorgio
// inserisco tesserino nelle prossime 4 azioni
void Astro::azione_31()
{
    interfaccia.scrivi("Click.");

    stringa_risposta = "hai sentito uno strano rumore...e la tubatura ha perso leggermente acqua!"; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

    if (passo_soluzione != 0 && passo_soluzione != 5)
        errore(); // goto 3830
    else if (passo_soluzione == 5)
        interfaccia.scrivi("Appare una scritta lampeggiante sullo schermo:\n\t\t  \"Inserire tesserino!\"");
    //ho aggiunto l'inserimento del tesserino prima di sbloccare i comandi per disattivare il reattore
    else
    {
        interfaccia.scrivi("Una tubatura perde leggermente");
        interfaccia.scrivi("da un raccordo (probabilmente per");
        interfaccia.scrivi("sovrapressione). Le gocce cadono sul");
        interfaccia.scrivi("quadro di controllo, vicino a te.");
        passo_soluzione = 1;
    }
}

/* 32:
 */
void Astro::azione_32()
{
    interfaccia.scrivi("Click.");

    stringa_risposta = "hai sentito uno strano rumore...";    //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

    if (passo_soluzione != 1 && passo_soluzione != 5)
        errore(); // goto 3830
    else if (passo_soluzione == 5)
        interfaccia.scrivi("Appare una scritta lampeggiante sullo schermo:\n\n\t  \"Inserire tesserino!\"");
    //ho aggiunto l'inserimento del tesserino prima di sbloccare i comandi per disattivare il reattore
    else
    {
        passo_soluzione = 2;
        if (oggetti.get_oggetto(22).get_luogo() != 0)
        {
            interfaccia.scrivi("Non ti senti troppo bene.");

            stringa_risposta = "hai cominciato a non sentirti bene...";   //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
            bacheca.NuovoMessaggioGioco("*stai assorbendo troppe radiazioni! non hai la giusta protezione!");
        }
    }
}

/* 33:
 */
void Astro::azione_33()
{
    interfaccia.scrivi("Click.");

    stringa_risposta = "hai sentito uno strano rumore...";   //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

    if (passo_soluzione != 2 && passo_soluzione != 5)
        errore();
    else if (passo_soluzione == 5)
        interfaccia.scrivi("Appare una scritta lampeggiante sullo schermo:\n\n\t  \"Inserire tesserino!\"");
    //ho aggiunto l'inserimento del tesserino prima di sbloccare i comandi per disattivare il reattore
    else
    {
        passo_soluzione = 3;
        if (oggetti.get_oggetto(22).get_luogo() != 0)
        {
            interfaccia.scrivi("Temo che tu abbia assorbito troppe");
            interfaccia.scrivi("radiazioni. Ora stai decisamente");
            interfaccia.scrivi("male. Perdi conoscenza...");
            morto();
        }
    }
}

/* 34:
 */
void Astro::azione_34()
{


    stringa_risposta = "hai sentito uno strano rumore...";            //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
    if (passo_soluzione == 5)
        interfaccia.scrivi("Appare una scritta lampeggiante sullo schermo:\n\n\t \"Inserire tesserino!\"");
    //ho aggiunto l'inserimento del tesserino prima di sbloccare i comandi per disattivare il reattore
    else if (passo_soluzione != 3 && passo_soluzione != 5)
    {
        errore();
        interfaccia.scrivi("Clanck.");
    }
    else
    {
        interfaccia.pausa(); //<SP>
        encomio();
        fine_partita = true;
        riparti = false;
    }
}

/* 35:
 */
void Astro::azione_35()
{
    if (passo_soluzione == 5)
        interfaccia.scrivi("Appare una scritta lampeggiante sullo schermo:\n\n\t \"Inserire tesserino!\"");
    //ho aggiunto l'inserimento del tesserino prima di sbloccare i pulsanti per disattivare il reattore
    else
        interfaccia.scrivi("Clunck.");
    errore();
    stringa_risposta = "hai sentito uno strano rumore...";      //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    // Fine De GIorgio
    // goto 3830
}
//end DAMONE MARCO

/* comune
 SPOSTATA PRIMA (dopo lo switch) PER VISIBILITA'
 */

/* 36:
 */
void Astro::azione_36()
{
    interfaccia.scrivi("Sembra danneggiata, forse");
    interfaccia.scrivi("da un grosso meteorite.");

    stringa_risposta = "hai notato che l'antenna era danneggiata.";   //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
}

/* 37:
 */
void Astro::azione_37(Mappa &M)
{
    if (parete_stagna_aperta == 0)
        luogo_attuale = 4;
    else
        direzioni(M);
}

/* 38:
 */
void Astro::azione_38(Mappa &M)
{
    if (parete_stagna_aperta == 1)
        luogo_attuale = 11;
    else
        direzioni(M); // goto 1780;
}
//Modifica PMF (ufficio)
//AZIONE GUARDA SCRIVANIA
void Astro::azione_44()
{
    interfaccia.scrivi("C'e' una lucetta con una lampadina che");
    interfaccia.scrivi("si accende e si spegne ad intermittenza");
    interfaccia.scrivi("ma non noto nulla di particolare");
}
//AZIONE GUARDA CALCOLATORE
void Astro::azione_45()
{
    //l=luogo_attuale;
    interfaccia.scrivi("---Calcolatore ufficio---\n");
    interfaccia.scrivi("Qui e' possibile ritirare o consegnare");
    interfaccia.scrivi("i documenti necessari per raggiungere");
    interfaccia.scrivi("alcune zone della nave e anche la fine del gioco");
    interfaccia.scrivi("digita quindi (ritira documento) oppure (consegna documento),");
    interfaccia.scrivi("per visualizzare il documento che hai ritirato");
    interfaccia.scrivi(" ti basta digitare 'cosa' oppure 'inventario'");


    //interfaccia.scrivi("preceduto dalla parola \'codice\'");
    //(M.get_luogo(luogo_attuale).leggiluogo);

    // interfaccia.scrivi("Quale vuoi prendere? \n");
    // interfaccia.scrivi("ATTENZIONE: Puoi prenderne solo uno per volta \n");
}

//AZIONE CONSEGNA DOCUMENTO
void Astro::azione_46()
{
    int doc;
    int doc1;
    int i;
    bool trovato;
    if (luogo_attuale==12)
    {
        interfaccia.scrivi("Hai questo documento: ");
        primo_doc.elenca_documenti(0);
        interfaccia.scrivi ("Digita il codice del documento se vuoi lasciarlo\n");
        cin >> doc;
        for (i=1 ; i < primo_doc.get_n_documenti() ; i++)
        {
            if (doc == primo_doc.get_codice_documento(i))
            {
                if(primo_doc.get_luogo_documenti(i)== 0)
                {
                    primo_doc.set_luogo_documenti(i, 12);
                    interfaccia.scrivi ("Documento lasciato!\n");
                    trovato = true;
                    ritirato = false;
                    break;
                }
            }
            else
                trovato=false;
        }
        if (trovato == false)
        {
            interfaccia.scrivi ("Non eri in possesso del documento");
        }
        if (doc > 20)
        {
            interfaccia.scrivi ("Il codice del documento che hai digitato non esiste");
        }
    }

}

//AZIONE RITIRA DOCUMENTO
void Astro::azione_47()
{
    int k;
    int doc;

    primo_doc.stampa_nomi_documenti(12);

    interfaccia.scrivi("Digita il codice del documento che vuoi ritirare ");
    cin >> doc;

    if (ritirato == false)
    {
        for (k=1; k<primo_doc.get_n_documenti(); k++)
        {
            if (doc == primo_doc.get_codice_documento(k))
            {
                if (primo_doc.get_luogo_documenti(k) == 12)
                {
                    primo_doc.set_luogo_documenti(k, 0);
                    interfaccia.scrivi("Hai preso il documento scelto.");
                    ritirato = true;
                    break;
                }
                else
                    interfaccia.scrivi("Questo documento ce l'hai gia'! ");
                break;
            }

        }
    }
    else
        interfaccia.scrivi("Hai gia' un documento nell'inventario!");

}
//Modifica PMF: fin qui.
//START DAMONE
void Astro::cerca()
{
    //se l'oggetto rubrica lo possiedo allora posso proseguire per la ricerca del personaggio
    if (oggetti.get_oggetto(55).get_luogo() == 0)
    {
        string risp = interfaccia.leggi_stringa("Inserisci il nome per la ricerca:");
        persona = rubrica.primolista();
        bool trovato = false;
        do //cerco il nome inserito all'interno della rubrica, se lo trovo stampo tutte le informazioni
        {
            if(risp == rubrica.leggilista(persona).get_nome())
            {
                interfaccia.scrivi("La persona da te ricercata e': ");
                interfaccia.scrivi_parziale("NOME: ");
                interfaccia.scrivi(rubrica.leggilista(persona).get_nome());
                interfaccia.scrivi_parziale("COGNOME: ");
                interfaccia.scrivi(rubrica.leggilista(persona).get_cognome());
                interfaccia.scrivi_parziale("INTERNO: ");
                interfaccia.scrivi(rubrica.leggilista(persona).get_interno());
                interfaccia.scrivi_parziale("DESCRIZIONE: ");
                interfaccia.scrivi(rubrica.leggilista(persona).get_descrizione());
                interfaccia.scrivi_parziale("TELEFONO: ");
                interfaccia.scrivi(rubrica.leggilista(persona).get_telefono());
                trovato = true;
            }
            persona = rubrica.succlista(persona);
        }
        while (!rubrica.finelista(persona));
        if(!trovato)//se il nome non lo trovo stampo il seguente messaggio
        {
            interfaccia.scrivi("Il nome da te inserito non e' presente nella rubrica!");
        }
    }
    else
    {
        interfaccia.scrivi("Non ce l'hai!\n");// se non sono in possesso della rubrica e faccio la ricerca di un personaggio mi appare il seguente messaggio
    }
}
//END DAMONE
//Modifica PMF(storia)
void Astro::azione_50()
{
    interfaccia.scrivi("\n +----- MOSSE EFFETTUATE FIN'ORA: -----+ \n ");
    storia_gioco.stampaStoria();
    interfaccia.scrivi("\n +-------------------------------------+ \n ");
}//Modifica PMF: fin qui.

//MODIFICA D-R(D'Orsi):Negozio + Banca// nuove azioni negozio
void Astro::azione_51() // PARLA MERCANTE
{
    negozio.parla(interfaccia);

}
//MODIFICA D-R(Pisani):Portafoglio +  Carta di Credito
void Astro::azione_52() // COMPRA OGGETTO
{
    int r;
    interfaccia.scrivi( " Seleziona il metodo di pagamento : ");
    interfaccia.scrivi( " 1 - per  Denaro Contante  ");
    interfaccia.scrivi( " 2 - per  Carta di Credito ");
    cin >> r;

    switch(r)
    {

    case  1 :

        if(portafoglio.acquista_Portafoglio(oggetti,comando_oggetto,interfaccia,negozio))
        {
            interfaccia.scrivi( "\n GRAZIE ! \n");
            interfaccia.a_capo();
        }
        break;

    case 2:

        if(carta.acquista_Carta(oggetti,comando_oggetto,interfaccia,negozio,portafoglio))
        {
            interfaccia.scrivi( "\n GRAZIE ! \n");
            interfaccia.a_capo();
        }
        break;


    default :
        interfaccia.scrivi(" Metodo di Pagamento Errato !");
    }

}
//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_53() // SALUTA MERCANTE
{
    interfaccia.scrivi("Mercante: Arrivederci");
}

//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
void Astro::azione_54() // CONTROLLA PORTAFOGLIO
{
    bool trovato = false;
    trovato = portafoglio.hai_Portafoglio(oggetti);

    if(trovato)

    {
        interfaccia.scrivi_parziale("Al momento possiedi ");
        interfaccia.scrivi_float( portafoglio.get_contanti() );
        interfaccia.scrivi( " Euro " );

    }

    else if(!trovato )
    {
        interfaccia.scrivi("Non è possibile controllare il portafoglio se prima non lo prendi! ");
    }
}
//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_55() // PARLA IMPIEGATO
{
    banca.parla(interfaccia);
}
//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
void Astro::azione_56() // DEPOSITA DENARO
{
    bool trovato = false;
    trovato = portafoglio.hai_Portafoglio(oggetti);
    float cont = portafoglio.get_contanti();
    float contcorr = portafoglio.get_contocorrente();

    if(trovato)

    {
        banca.deposita(cont,contcorr,interfaccia);
        portafoglio.set_contanti(cont);
        portafoglio.set_contocorrente(contcorr);
        trovato = true;
    }

    else if(!trovato)
    {
        interfaccia.scrivi("Non è possibile depositare se non indossi il portafoglio ! ");
    }


}
//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_57() // SALUTA IMPIEGATO
{
    interfaccia.saluto();
    luogo_attuale = 14; //MODIFICA D-R(D-R): 12 => 14 (adattandolo alla nuova mappa)
}
//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_58() //CONTROLLA SALDO
{
    interfaccia.scrivi_parziale("Sul conto sono attualmente presenti ");
    interfaccia.scrivi_float( portafoglio.get_contocorrente() );
    interfaccia.scrivi( " Euro" );
}

//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
void Astro::azione_59() // PRELEVA DENARO
{
    bool trovato = false;
    trovato = portafoglio.hai_Portafoglio(oggetti);
    float cont = portafoglio.get_contanti();
    float contcorr = portafoglio.get_contocorrente();


    if(trovato)
    {
        if(!gia_prelevato)
        {

            banca.preleva(cont,contcorr,interfaccia);
            portafoglio.set_contanti(cont);
            portafoglio.set_contocorrente(contcorr);
            tempo=tempo/2;
            gia_prelevato=true;
        }
        else
        {
            banca.preleva(cont,contcorr,interfaccia);

        }

    }
    else if(!trovato)
    {
        interfaccia.scrivi("Non è possibile prelevare se non indossi il portafoglio ! ");
    }


}
//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_60() // CONTROLLA CASSETTA
{


    banca.mostra_oggetto(interfaccia);
}

//MODIFICA D-R(D'Orsi):Negozio + Banca
void Astro::azione_61() // RITIRA OGGETTO
{
    banca.ritira_oggetto(comando_oggetto, interfaccia, oggetti);
}

//MODIFICA D-R(Colturi):Luoghi a Pagamento
void Astro::azione_62(Mappa& M, int bigl) // ENTRA MOSTRA D'ARTE - STADIO - CINEMA
{

    if(luogo_attuale <16)
    {
        interfaccia.scrivi("Comando non valido in questo luogo");
    }

    else if (luogo_attuale >15 && oggetti.get_oggetto(og).get_luogo() !=0 )
    {
        interfaccia.scrivi("Non hai il biglietto per entrare ");
        interfaccia.scrivi("Prendi il biglietto prima");
    }
    else
    {
        Luogo lu = M.get_luogo(luogo_attuale);
        Lista<string> desc;
        copiaLista(desc, lu.Carica_descLuoghiPag());
        lu.Leggi_descLuoghiPag(desc,luogo_attuale);
        srand(time(0));
        int k = (rand()%6)+1;
        oggetti.set_luogo(og,k); //elimino il biglietto dallo zaino perchè¨ appena utilizzato e lo genero casualmente in un luogo
    }

}
//MODIFICA D-R(Colturi):Luoghi a Pagamento
void Astro::azione_63(Mappa& M) // LEGGI INSEGNA LUMINOSA
{
    if(luogo_attuale<16)
    {
        interfaccia.scrivi("Non e' possibile utilizzare qui questo comando");
    }
    else if(luogo_attuale==18)
    {
        interfaccia.scrivi("Entra nella Mostra d'arte e vieni a visitare le nostre opere");
    }
    else  if(luogo_attuale==17)
    {
        interfaccia.scrivi("Entra nello Stadio,ti aspettano avvincenti partite!");
    }
    else  if(luogo_attuale==16)
    {
        interfaccia.scrivi("Entra nel Cinema,vieni a vedere i film in programma");
    }
}

//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
void Astro::azione_66() // CONTROLLA CARTA
{
    bool trovato = false;

    for(int i = 1; i <= oggetti.get_n_oggetti(); i++)
    {

        if(oggetti.posizionati_in(0).get_oggetto(i).get_nome() == "una carta di credito")

        {
            interfaccia.scrivi_parziale("Al momento possiedi ");
            interfaccia.scrivi_float(portafoglio.get_contocorrente());
            interfaccia.scrivi( " Euro " );
            trovato = true;
        }

        else if( i == oggetti.get_n_oggetti() && !trovato )
        {
            interfaccia.scrivi("Non è possibile controllare il carta di credito se prima non la prendi! ");
        }

    }


}
//INIZIO MODIFICHE ALBANO MICHELE
void Astro::azione_67() //Azione Salute
{
    Lista<Ferita> f; //Ferite contratte dal Giocatore
    Lista<Ferita>::posizione pos; //Posizione
    if(Salute.Ferito()==false) //Se non sei ferito...
        interfaccia.scrivi("Il tuo Stato di Salute e' ottimo!");
    else
    {
        f=Salute.Get_Ferite(); //Aggiorna le Ferite contratte dal Giocatore
        if(Salute.GetStatoSalute()<=50)
            interfaccia.scrivi_parziale("Sei gravemente ferito. ");
        else
            interfaccia.scrivi_parziale("Sei ferito. ");
        interfaccia.a_capo();
        interfaccia.scrivi_parziale("Controllandoti, scorgi ");
        pos=f.primolista(); //Posizionati sul primo elemento
        while(f.finelista(pos)!=true) //Finchè non scandisci tutte le ferite, continua
        {
            interfaccia.scrivi_parziale(f.leggilista(pos).GetNome()); //Stampa il nome della Ferita
            pos=f.succlista(pos); //Aggiorna posizione
            if(f.finelista(pos)!=true) //Se ci sono altre Ferite, aggiorna l'impaginamento
                interfaccia.scrivi_parziale(", ");
        }
        interfaccia.scrivi(".");
        if(Salute.GetStatoSalute()<=50)
            interfaccia.scrivi("Dovresti recarti al Pronto Soccorso il prima possibile!");
        else
            interfaccia.scrivi("Forse sarebbe il caso di visitare il Pronto Soccorso!");
    }
    interfaccia.a_capo();
    storia_gioco.insStoria(stringa_comando, "hai controllato il tuo Stato di Salute");  //Aggiorna storia gioco
}
//FINE MODIFICHE MICHELE ALBANO
//Modifiche Francesco Cosma - Premi

void Astro::azione_68()
{
    premi.stampaPremiRicevuti();
}
//INIZIO MODIFICHE MICHELE ALBANO
void Astro::azione_69() //Azione usa terminale nel pronto soccorso
{
    //Aggiunta coda random
    int selezione, generatore_coda; //Variabile di selezione e di generatore coda
    string input_utente; //Strina di appoggio. Contiene l'input dell'utente
    bool uscita=false; //Uscita dal menu
    bool conferma=false; //Conferma utente
    bool controllo=false; //Variabile di controllo
    bool gettone=false; //Variabile di controllo
    generatore_coda=rand()%11; //Genera una variabile casuale compresa tra 0 e 10
    if(generatore_coda>0) //Se ci sono persone in coda, chiedi al Giocatore cosa desidera fare
    {
        interfaccia.scrivi_parziale(generatore_coda);
        interfaccia.scrivi_parziale(" persone attendono di poter usare il terminale. Desideri aspettare? [si/no] ");
        while(controllo!=true)
        {
            cin>>input_utente;
            if(input_utente=="S" || input_utente=="s" || input_utente=="Si" || input_utente== "SI" || input_utente=="si") //Se l'utente digita si, aggiorna conferma
            {
                conferma=true; //L'utente ha confermato di voler utilizzare il terminale
                controllo=true; //Aggiorna il controllo
                tempo-=generatore_coda; //Aggiorna le mosse del giocatore
            }
            else if(input_utente=="N" || input_utente=="n" || input_utente=="No" || input_utente== "NO" || input_utente=="no") //Se l'utente digita no, aggiorna conferma
            {
                conferma=false; //L'utente ha confermato di non voler utilizzare il terminale
                controllo=true; //Aggiorna il controllo
            }
            else
            {
                interfaccia.scrivi("Non capisco.");
                aggiorna_tempo();
                interfaccia.a_capo();
                interfaccia.scrivi_parziale(generatore_coda);
                interfaccia.scrivi_parziale(" persone attendono di poter usare il terminale. Desideri aspettare? [si/no] ");
                interfaccia.a_capo();
            }
        }
    }
    else
        conferma=true; //Se non ci sono persone, usa terminale senza bisogno di conferma
    if(conferma==true) //Se l'utente ha confermato l'utilizzo, mostra le opzioni del terminale
    {
        storia_gioco.insStoria(stringa_comando, "hai deciso di usare il terminale nel Pronto Soccorso");  //Aggiorna storia gioco
        system("cls");
        //		//system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI //Pulisci la schermata
        interfaccia.scrivi("+---- ACCENSIONE TERMINALE IN CORSO...                      ----+");

        Sleep(850); //Attendi alcuni istanti
        interfaccia.scrivi("+---- CARICAMENTO APPLICAZIONE IN CORSO...                  ----+");
        Sleep(850); //Attendi alcuni istanti
        interfaccia.scrivi("+---- BENVENUTO NEL TERMINALE DI CURA DI SIMUNAV!           ----+");
        if(oggetti.get_oggetto(58).get_luogo() == 0) //Se hai la tessera nell'inventario
        {
            interfaccia.scrivi("+---- TESSERA SANITARIA RICONOSCIUTA!                       ----+");
            interfaccia.scrivi("+---- DIGITA 0 PER CURARTI!                                 ----+");
            interfaccia.scrivi("+---- DIGITA 1 PER SPEGNERE IL TERMINALE!                   ----+");
        }
        else if(oggetti.get_oggetto(59).get_luogo() == 0) //Se hai il gettone
        {
            interfaccia.scrivi("+---- GETTONE RICONOSCIUTO!                                 ----+");
            interfaccia.scrivi("+---- DIGITA 0 PER CURARTI!                                 ----+");
            interfaccia.scrivi("+---- DIGITA 1 PER SPEGNERE IL TERMINALE!                   ----+");
            gettone=true;
        }
        else
        {
            interfaccia.scrivi("+---- ERRORE 457!                                           ----+");
            interfaccia.scrivi("+---- TESSERA SANITARIA E GETTONE NON RIVELATI!             ----+");
            interfaccia.scrivi("+---- IMPOSSIBILE CURARE IL PAZIENTE!                       ----+");
            interfaccia.scrivi("+---- SPEGNIMENTO TERMINALE IN CORSO...!                    ----+");
            interfaccia.a_capo();
            interfaccia.a_capo();
            Sleep(850); //Attendi  alcuni istanti
            uscita=true;
        }
        while(uscita!=true)
        {
            interfaccia.scrivi_parziale("+---- Digita il valore: ");
            cin>>selezione; //Inserisci il valore
            switch(selezione)
            {
            case 0:
                storia_gioco.insStoria(stringa_comando, "hai deciso di curare le tue ferite nel Pronto Soccorso");  //Aggiorna storia gioco
                Salute.Cura();
                if(gettone==true) //Se hai il gettone e ti sei curato, togli il gettone dall'inventario
                {
                    oggetti.set_luogo(59,-9999); //Setta il Gettone nel limbo
                    interfaccia.scrivi("+---- GETTONE ACCETTATO!                                   ----+");
                }
                interfaccia.scrivi("+---- CURE RICHIESTE SOMMINISTRATE!                          ----+");
                Sleep(850); //Attendi  alcuni istanti
                interfaccia.scrivi("+---- SPEGNIMENTO TERMINALE IN CORSO...!                     ----+");
                Sleep(850); //Attendi  alcuni istanti
                interfaccia.a_capo();
                interfaccia.a_capo();
                uscita=true;
                break;
            case 1:
                storia_gioco.insStoria(stringa_comando, "hai lasciato il terminale nel Pronto Soccorso");  //Aggiorna storia gioco
                interfaccia.scrivi("+---- SPEGNIMENTO TERMINALE IN CORSO...!                   ----+");
                Sleep(850); //Attendi  alcuni istanti
                interfaccia.a_capo();
                interfaccia.a_capo();
                uscita=true;
                break;
            default:
                system("cls");
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI //Pulisci la schermata
                interfaccia.scrivi("Non capisco.");
                aggiorna_tempo();
                interfaccia.a_capo();
                interfaccia.scrivi("+---- DIGITA 0 PER CURARTI!                                  ----+");
                interfaccia.scrivi("+---- DIGITA 1 PER SPEGNERE IL TERMINALE!                    ----+");
                break;
            }
        }
    }
}
//FINE MODIFICHE MICHELE ALBANO

//INIZIO MODIFICHE GIOVANNI CASTELLANA
void Astro::azione_70()  // azione confessati, entra confessionale
{
    //Aggiunta coda casuale
    int n_persone_coda; //Variabile di generatore coda
    string input_utente; //Strina di appoggio. Contiene l'input dell'utente
    bool conferma=false; //Conferma utente
    bool controllo=false; //Variabile di controllo
    n_persone_coda=rand()%11; //Genera una variabile casuale compresa tra 0 e 10

    if(n_persone_coda>0) //Se ci sono persone in coda, chiedi al Giocatore cosa desidera fare
    {
        interfaccia.scrivi_parziale(n_persone_coda);
        interfaccia.scrivi_parziale(" persone attendono per potersi confessare. Desideri aspettare? [si/no] ");
        while(controllo!=true)
        {
            cin>>input_utente;
            if(input_utente=="S" || input_utente=="s" || input_utente=="Si" || input_utente== "SI" || input_utente=="si") //Se l'utente digita si, aggiorna conferma
            {
                conferma=true; //L'utente ha confermato di volersi confessare
                controllo=true; //Aggiorna il controllo
                tempo=tempo-n_persone_coda; //Aggiorna le mosse del giocatore

                interfaccia.a_capo();
                interfaccia.scrivi("+---- Attendi alcuni istanti...!   ----+");
                Sleep(850); //Attendi  alcuni istanti
                interfaccia.a_capo();
                interfaccia.scrivi("+---- OTTIMO, TI SEI CONFESSATO!   ----+");
                interfaccia.scrivi("Hai impiegato");
                interfaccia.scrivi_parziale(n_persone_coda);
                interfaccia.scrivi(" unita' di tempo aggiuntive!");
                storia_gioco.insStoria(stringa_comando, "ti sei confessato");  //Aggiorna storia gioco
            }
            else if(input_utente=="N" || input_utente=="n" || input_utente=="No" || input_utente== "NO" || input_utente=="no") //Se l'utente digita no, aggiorna conferma
            {
                conferma=false; //L'utente ha confermato di non volersi confessare
                controllo=true; //Aggiorna il controllo
                storia_gioco.insStoria(stringa_comando, "non ti sei confessato");  //Aggiorna storia gioco
            }
            else
            {
                interfaccia.scrivi("Non capisco.");
                aggiorna_tempo();
                interfaccia.a_capo();
                interfaccia.scrivi_parziale(n_persone_coda);
                interfaccia.scrivi_parziale(" persone attendono per potersi confessare. Desideri aspettare? [si/no] ");
                interfaccia.a_capo();
            }
        }
    }
    else
    {
        conferma=true; //Se non ci sono persone, confessati senza bisogno di conferma
        interfaccia.scrivi("+---- OTTIMO, TI SEI CONFESSATO!   ----+");
        storia_gioco.insStoria(stringa_comando, "ti sei confessato");  //Aggiorna storia gioco
    }

}

bool controllo=false; //variabile di controllo per fare in modo che la salute aumenti solo la prima volta che ci si sieda

void Astro::azione_71()  // azione siediti,siediti panchina
{

    if (controllo==false)   // se non ti sei mai seduto
    {

        if (Salute.GetStatoSalute()<100)    // se il tuo stato di salute non è ottimale
        {
            int salute_attuale;
            int salute_aggiornata;
            salute_attuale=Salute.GetStatoSalute(); //salvo lo stato di salute corrente in una variabile
            salute_aggiornata=salute_attuale+10; // aggiorno lo stato di saluto
            Salute.SetStatoSalute(salute_aggiornata); // salvo il nuovo stato di salue

            if(salute_aggiornata>100)   // se la salute aggiornata supera 100
            {
                salute_aggiornata=100; // imposto la salute aggiornata a 100
                Salute.SetStatoSalute(salute_aggiornata); // salvo il nuovo stato di salute
            }

            interfaccia.scrivi("+---- TI SEI SEDUTO E HAI RECUPERATO UN PO' DI SALUTE   ----+");
            interfaccia.scrivi("Salute precedente: ");
            interfaccia.scrivi_parziale(salute_attuale); //stampa la salute precedente
            interfaccia.a_capo();
            interfaccia.scrivi("Salute attuale: ");
            interfaccia.scrivi_parziale(salute_aggiornata); // stampa la salute attuale
            controllo=true;

        }
        else   // se il tuo stato di salute è già ottimale
        {
            interfaccia.scrivi("+---- TI SEI SEDUTO E IL TUO STATO DI SALUTE E' OTTIMO   ----+");
            controllo=true;
        }
    }
    else   // se già ti sei seduto, non ti permette di recuperare salute
    {

        interfaccia.scrivi("+---- TI SEI SEDUTO MA NON HAI RECUPERATO SALUTE   ----+");
    }

    storia_gioco.insStoria(stringa_comando, "ti sei seduto");  //Aggiorna storia gioco

}

void Astro::azione_72()  // azione che serve a impostare la variabile controllo utile
{
    //nell'azione 71, quando si esce dalla chiesa e si va a sud (unica direzione consentita)

    luogo_attuale=2;
    controllo=false;
    storia_gioco.insStoria(stringa_comando, "sei andato all'estremita' nord del corridoio");  //Aggiorna storia gioco
}

void Astro::azione_73()  //azione parla sacerdote
{
    interfaccia.scrivi("+---- Hai parlato con il sacerdote e ti ha suggerito di pregare, potrebbe accadere un miracolo!  ----+");

    storia_gioco.insStoria(stringa_comando, "hai parlato con il sacerdote");  //Aggiorna storia gioco
}

void Astro::azione_74()  //azione PREGA
{

    Lista<Ferita> ferite; //Ferite contratte dal Giocatore

    if(Salute.Ferito()==false) //Se non sei ferito
        interfaccia.scrivi("Il tuo Stato di Salute e' ottimo!");
    else
    {
        ferite=Salute.Get_Ferite(); // aggiorna le ferite contratte dal giocatore
        Lista<Ferita>::posizione pos;
        pos=ferite.primolista(); //Posizionati sul primo elemento

        int casuale=rand()%10; //genera un numero casuale da 0 a 9

        if (casuale<5)   // se il numero casuale è minore di 5
        {

            interfaccia.scrivi("+---- HAI PREGATO ED E' AVVENUTO UN MIRACOLO:   ----+");
            interfaccia.a_capo();
            interfaccia.scrivi("Sei stato curato da");
            interfaccia.scrivi_parziale(ferite.leggilista(pos).GetNome()); //Stampa il nome della Ferita
            Salute.Miracolo(); //invoca la procedura Miracolo di StatoSalute
            pos=ferite.succlista(pos); // Posizionati sull'elemento successivo
        }
        else   // se il numero casuale è maggiore di 5
        {
            interfaccia.scrivi("+---- OTTIMO, HAI PREGATO!  ----+");
        }

    }
    storia_gioco.insStoria(stringa_comando, "hai pregato");  //Aggiorna storia gioco
}

//FINE MODIFICHE GIOVANNI CASTELLANA

//Inizio Modifica Gallone - Aggiungo le Procedure (dalla 69 alla 73) necessarie all'integrazione della nuova funzionalità------------------------------

//Azione fame: monitora l'appetito del comandante, funzione richiamabile in qualsiasi luogo
void Astro::azione_75() //
{
    string messaggio;
    string stato;
    if (sazio <= 120 && sazio >= 80)
    {
        stato = "OTTIMALE";
        messaggio = "Inizio a sentire un leggero languorino...";
    }
    else if (sazio <= 79 && sazio >= 50)
    {
        messaggio = "E' tutto il giorno che non mangio, dovrei fare una pausa...";
        stato = "BUONO";
    }
    else if (sazio <= 49 && sazio >= 30)
    {
        messaggio = "Accidenti, la fame aumenta. Mi servono energie, e subito!";
        stato = "CRITICO";
    }
    else if (sazio <= 29 && sazio >=0)
    {
        messaggio = "...Non riesco a fare un altro passo... le forze mi abbandonano...";
        stato = "MOLTO CRITICO";
    }
    cout << "\nlivello sazieta': " << stato << " (" << sazio << ")" << endl;
    interfaccia.scrivi(messaggio);

}

//Azione Compra: permette di acquistare le vivande dai luoghi preposti, a patto che si abbiano i buoni pasto richiesti
//e si trasporti lo zaino_frigo, dove le cibarie verranno conservate prima di essere mangiate
void Astro::azione_76() // ex azione 40
{
    riferimento_zaino=zaino_frigo.primolista();
    while(!zaino_frigo.finelista(riferimento_zaino))
    {
        riferimento_zaino=zaino_frigo.succlista(riferimento_zaino);
    }
    if(oggetti.get_oggetto(66).get_luogo()==0)//Codice da modificare in base alla posizione dell'oggetto Zaino Termico
    {
        riferimento_tasca=tasca.primolista();
        bool trovato=false;
        if(tasca.listavuota())
            interfaccia.scrivi("Non hai Buoni Mensa! Procurateli per poterli scambiare con deliziose pietanze!");
        else
        {
            while(!tasca.finelista(riferimento_tasca) && !trovato)
            {
                if(oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_categoria()==oggetti.get_oggetto(og).get_categoria())
                {
                    oggetti.set_luogo(tasca.leggilista(riferimento_tasca),-9999);
                    tasca.canclista(riferimento_tasca);
                    oggetti.set_luogo(og,0);
                    interfaccia.scrivi("Piatto acquistato ed inserito nello zaino termico!");
                    zaino_frigo.inslista(og, riferimento_zaino);
                    trovato=true;
                }
                else
                    riferimento_tasca=tasca.succlista(riferimento_tasca);
            }
            if(!trovato)
            {
                interfaccia.scrivi("Non possiedi un Buono Mensa della stessa categoria del piatto scelto.");
            }
        }
    }
    else
        interfaccia.scrivi("Non hai nessuno zaino termico! Dovresti prima prenderlo.");

}


//Azione mangia:  Mangia i piatti che ha comprato
void Astro::azione_77() // ex azione 41
{
    string messaggio;
    int y;
    srand(time(NULL));
    y= rand()%3+1;
    switch (y)
    {
    case 1:
        messaggio = "Che bonta'! Ci voleva proprio!";
        break;
    case 2:
        messaggio = "Mai assaggiato un piatto cosi' buono!";
        break;
    case 3:
        messaggio = "Era ora di mettere qualcosa sotto i denti!";
        break;
    }
    bool trovato = false;
    riferimento_zaino = zaino_frigo.primolista();

    while(!zaino_frigo.finelista(riferimento_zaino) && trovato == false)
    {
        if (oggetti.get_oggetto(zaino_frigo.leggilista(riferimento_zaino)).get_codice() == oggetti.get_oggetto(og).get_codice())
        {
            sazio = sazio + oggetti.get_oggetto(og).get_valore_e();
            oggetti.set_luogo(og, -9999);
            zaino_frigo.canclista(riferimento_zaino);
            trovato = true;
            cout << "\n" << messaggio << "\n";
        }
        else
            riferimento_zaino = zaino_frigo.succlista(riferimento_zaino);
    }
    if (trovato == false)
        interfaccia.scrivi("Non hai a disposizione quel piatto!");

}

//Azione Tasca: mostra il contenuto della tasca del capitano
void Astro::azione_78() // ex azione 42
{
    riferimento_tasca=tasca.primolista();
    if(tasca.listavuota())
        interfaccia.scrivi("Non hai nulla in tasca.");
    else
    {
        interfaccia.scrivi("In tasca hai:");
        do
        {
            cout << "\n- " << oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_nome();
            if (tasca.finelista(riferimento_tasca))
                cout << "\n- " << oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_nome() << ".";
            else
                cout << "\n- " << oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_nome() << ";";
            riferimento_tasca=tasca.succlista(riferimento_tasca);
        }
        while(!tasca.finelista(riferimento_tasca));
        cout<<endl;
    }
}

//Azione Zaino Termico: mostra il contenuto dello Zaino Termico
void Astro::azione_79() // ex azione 43
{

    if(oggetti.get_oggetto(65).get_luogo()==0)//Codice da modificare in base alla posizione dell'oggetto Zaino Termico
    {
        riferimento_zaino=zaino_frigo.primolista();
        if(zaino_frigo.listavuota())
            interfaccia.scrivi("Non c'e' nulla nello zaino termico. Qui puoi conservare il cibo!");
        else
        {
            interfaccia.scrivi("Nello zaino termico hai messo:");
            do
            {
                if (zaino_frigo.finelista(riferimento_zaino))
                    cout << "\n- " << oggetti.get_oggetto(zaino_frigo.leggilista(riferimento_zaino)).get_nome() << ".";
                else
                    cout << "\n- " << oggetti.get_oggetto(zaino_frigo.leggilista(riferimento_zaino)).get_nome() << ";";
                riferimento_zaino=zaino_frigo.succlista(riferimento_zaino);
            }
            while(!zaino_frigo.finelista(riferimento_zaino));
            cout<<endl;
        }
    }
    else
        interfaccia.scrivi("Non hai nessuno zaino termico! Dovresti prima prenderlo.");

}


//Fine Modifica Gallone-----------------------------------------------------------------------------------------------------

//INIZIO modifiche DELLA FOLGORE GRAZIA
void Astro::azione_80()
{
    if(luogo_attuale==oggetti.get_oggetto(119).get_luogo() || oggetti.get_oggetto(119).get_luogo()==0)
    {
        if((automobile.get_inUso()==false)&&(autobus.get_inUso()==false))
        {
            bool controllo = false;
            bool conferma = false;
            bool uscita = false;
            string input_utente;
            int selezione;
            interfaccia.scrivi("L'automobile dispone di un bagagliaio");
            stringa_risposta = "hai notato che l'auto dispone di un bagagliaio";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            interfaccia.scrivi_parziale("Vuoi utilizzarlo per riporvi/prelevare oggetti? [si/no]");
            while(controllo!=true)
            {
                interfaccia.a_capo();
                cin >> input_utente;
                if(input_utente=="S" || input_utente=="s" || input_utente=="Si" || input_utente== "SI" || input_utente=="si")
                {
                    conferma=true;		//Il giocatore conferma di voler usare il bagagliaio
                    controllo=true;
                }
                else if(input_utente=="N" || input_utente=="n" || input_utente=="No" || input_utente== "NO" || input_utente=="no")
                {
                    conferma=false; 	//Il giocatore conferma di non voler usare il bagagliaio
                    controllo=true;
                }
                else
                {
                    interfaccia.scrivi("Non capisco.");
                    aggiorna_tempo();
                    interfaccia.a_capo();
                    interfaccia.scrivi("L'automobile dispone di un bagagliaio");
                    interfaccia.scrivi_parziale("Vuoi utilizzarlo per riporvi/prelevare oggetti? [si/no]");
                    interfaccia.a_capo();
                }
            }
            if(conferma)
            {
                storia_gioco.insStoria(stringa_comando, "hai deciso di usare il bagagliaio dell'auto");
                system("cls");
                if(oggetti.get_oggetto(118).get_luogo() == 0)
                {
                    interfaccia.scrivi("Puoi utilizzare il bagagliaio perche' possiedi la chiave");
                    interfaccia.scrivi("Seleziona:");
                    interfaccia.scrivi(" 0: per depositare gli oggetti");
                    interfaccia.scrivi(" 1: per prelevare gli oggetti");
                    interfaccia.scrivi(" 2: per vedere il contenuto del bagagliaio");
                    interfaccia.scrivi(" 3: per vedere gli oggetti che possiedi");
                    interfaccia.scrivi(" 4: chiudere il bagagliaio");
                    interfaccia.a_capo();
                }
                else
                {
                    interfaccia.scrivi("Devi prendere la chiave dell'auto");
                    uscita=true;
                }
                while(uscita!=true)
                {
                    int num_ogg_inventario = oggetti.posizionati_in(0).get_n_oggetti();
                    interfaccia.scrivi_parziale("Cosa vuoi fare:");
                    cin >> selezione;
                    switch(selezione)
                    {
                    case 0:
                        storia_gioco.insStoria("0", "hai deciso di depositare i tuoi oggetti nel bagagliaio");
                        if(num_ogg_inventario>0)
                        {
                            for(int i=1; i<=num_ogg_inventario; i++)
                            {
                                //L'oggetto viene depositato se non è una chiave
                                if((oggetti.posizionati_in(0).get_oggetto(i).get_codice())!=116)        //116 -> Chiave Automobile
                                {
                                    automobile.bagagliaio.depositaBagaglio(oggetti.posizionati_in(0).get_oggetto(i));	//L'oggetto è depositato nel bagagliaio
                                    //cout<<"\n oggetto "<<oggetti.posizionati_in(0).get_oggetto(i).get_codice();
                                }
                            }
                            oggetti.set_luogo_oggetti_pos_in(0, -99);
                        }
                        interfaccia.a_capo();
                        interfaccia.scrivi("Oggetti depositati nel bagagliaio");
                        interfaccia.a_capo();
                        uscita = true;
                        break;
                    case 1:
                        storia_gioco.insStoria("1", "hai deciso di prelevare i tuoi oggetti dal bagagliaio");
                        if(!automobile.bagagliaio.bagagliaioVuoto())
                        {
                            interfaccia.a_capo();
                            interfaccia.scrivi("Oggetti prelevati dal bagagliaio");
                        }
                        else
                        {
                            interfaccia.a_capo();
                            interfaccia.scrivi("Non hai prelevato nulla: il bagagliaio e' vuoto");
                        }
                        while(!automobile.bagagliaio.bagagliaioVuoto())
                        {
                            Oggetto oggetto = automobile.bagagliaio.estraiBagaglio();
                            int indice = oggetti.get_oggetto_indice_by_codice(oggetto.get_codice());
                            oggetti.set_luogo(indice, 0);
                        }
                        uscita = true;
                        break;
                    case 2:
                        storia_gioco.insStoria("2", "hai deciso di vedere il contenuto del bagagliaio");
                        interfaccia.a_capo();
                        automobile.bagagliaio.vediBagagli();
                        interfaccia.a_capo();
                        uscita = true;
                        break;
                    case 3:
                        storia_gioco.insStoria("3", "hai deciso di vedere gli oggetti che possiedi");
                        interfaccia.a_capo();
                        interfaccia.elenca_oggetti(oggetti.posizionati_in(0),"Possiedi:");
                        if (ritirato == true)
                        {
                            interfaccia.scrivi("Possiedi come documento: ");
                            primo_doc.elenca_documenti(0);
                        }
                        uscita = true;
                        break;
                    case 4:
                        storia_gioco.insStoria("4", "hai deciso di chiudere il bagagliaio dell'auto");
                        uscita = true;
                        break;
                    default:
                        system("cls");
                        interfaccia.scrivi("Non capisco.");
                        aggiorna_tempo();
                        interfaccia.a_capo();
                        interfaccia.scrivi("Seleziona:");
                        interfaccia.scrivi(" 0: per depositare gli oggetti");
                        interfaccia.scrivi(" 1: per prelevare gli oggetti");
                        interfaccia.scrivi(" 2: per vedere il contenuto del bagagliaio");
                        interfaccia.scrivi(" 3: per vedere gli oggetti che possiedi");
                        interfaccia.scrivi(" 4: chiudere il bagagliaio");
                        interfaccia.a_capo();
                        break;
                    }
                }
            }
        }
        else
        {
            if(automobile.get_inUso())
            {
                interfaccia.scrivi("Non noti nulla dall'interno dell'auto");
                storia_gioco.insStoria(stringa_comando, "non hai notato nulla dall'interno");
            }
            if(autobus.get_inUso())
            {
                interfaccia.scrivi("Non noti nulla dall'autobus");
                storia_gioco.insStoria(stringa_comando, " non hai notato nulla dall'autobus");
            }
        }
    }
    else
    {
        interfaccia.scrivi("L'automobile non e' qui!");
    }
}
//FINE modifiche DELLA FOLGORE GRAZIA

//Inizio modifiche Galeandro da Progetto Bellanova
void Astro :: azione_82 ( )
{
    std::string risp;

    int p,spedizione,luogo;
    Oggetti inventario;
    p=ufficiopostale.randomFila();

    system("cls");
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI

    interfaccia.scrivi(" --------  ATTENZIONE  --------  !");
    cout<<" Ci sono "<<p<<" persone in fila, vuoi attendere? [s/n]";
    cin>>risp;
    if(strcmp(risp.c_str(),"s") == 0)
    {
        tempo=tempo-p;
        int scelta,sceltainvia;
        bool uscita,uscitainvia;
        uscita=false;
        uscitainvia=false;
        system("cls");
        ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi("Caricamento del sistema in corso......");
        Sleep(920);
        system("cls");
        ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi("\n+--------------------------------------------------------------+");
        interfaccia.scrivi("+ Benvenuto nel sistema postale Adventure                      +");
        interfaccia.scrivi("+ Potrai usufruire dei seguenti servizi                        +");
        interfaccia.scrivi("+ Digita:                                                      +");
        interfaccia.scrivi("+ 1 per accedere ai servizi di invio                           +");
        interfaccia.scrivi("+ 2 per accedere ai servizi di ricezione                       +");
        interfaccia.scrivi("+ 0 per uscire                                                 +");
        interfaccia.scrivi("+--------------------------------------------------------------+");
        while(uscita != true)
        {
            cout<<(" \n Opzione: ");
            cin>>scelta;
            switch (scelta)
            {
            case 1:
                system("cls");
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                interfaccia.scrivi(" Caricamento in corso . . .");
                Sleep(820);
                system("cls");
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                interfaccia.scrivi("\n+--------------------------------------------------------------+");
                interfaccia.scrivi("+ Sei nella sezione di invio                                  +");
                interfaccia.scrivi("+ Digita:                                                     +");
                interfaccia.scrivi("+ 1 per richiedere un suggerimento                            +");
                interfaccia.scrivi("+ 2 per richiedere un pacco misterioso                        +");
                interfaccia.scrivi("+ 3 per inviare un pacco in un luogo della nave               +");
                interfaccia.scrivi("+ 4 per depositare del denaro in banca                        +");
                interfaccia.scrivi("+ 0 per uscire                                                +");
                interfaccia.scrivi("+-------------------------------------------------------------+");

                while(uscitainvia != true)
                {
                    cout<<(" \n Opzione: ");
                    cin>>sceltainvia;
                    switch(sceltainvia)
                    {
                    case 1:
                        if(ufficiopostale.get_Suggerimento() == true)
                        {
                            system("cls");
                            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Attendere prego . . .");
                            Sleep(820);
                            system("cls");
                            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+-------------------------------------------------------------+");
                            interfaccia.scrivi("+ Attenzione! Hai gia' richiesto il suggerimento!             +");
                            interfaccia.scrivi("+ Non puoi utilizzare nuovamente questa funzione              +");
                            interfaccia.scrivi("+-------------------------------------------------------------+");
                        }
                        else
                        {
                            ufficiopostale.set_Suggerimento(true);
                            system("cls");
                            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Invio in corso . . .");
                            Sleep(820);
                            system("cls");
                            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+--------------------------------------------------------------+");
                            interfaccia.scrivi("+ Richiesta inviata correttamente!                             +");
                            interfaccia.scrivi("+ Riceverai a breve la lettera.                                +");
                            interfaccia.scrivi("+ Controlla nella sezione di ricezione.                        +");
                            interfaccia.scrivi("+--------------------------------------------------------------+");
                        }
                        uscitainvia=true;
                        break;

                    case 2:
                        if(ufficiopostale.get_Pacco() == true)
                        {
                            system("cls");
                            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Attendere prego . . .");
                            Sleep(820);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+-------------------------------------------------------------+");
                            interfaccia.scrivi("+ Attenzione! Hai gia' richiesto il pacco!                    +");
                            interfaccia.scrivi("+ Non puoi utilizzare nuovamente questa funzione              +");
                            interfaccia.scrivi("+-------------------------------------------------------------+");
                        }
                        else
                        {
                            ufficiopostale.set_Pacco(true);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Invio in corso . . .");
                            Sleep(820);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+--------------------------------------------------------------+");
                            interfaccia.scrivi("+ Richiesta inviata correttamente!                             +");
                            interfaccia.scrivi("+ Riceverai a breve il pacco.                                  +");
                            interfaccia.scrivi("+ Controlla nella sezione di ricezione.                        +");
                            interfaccia.scrivi("+--------------------------------------------------------------+");
                        }
                        uscitainvia=true;
                        break;

                    case 3:
                        system("cls");
                        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                        interfaccia.scrivi("Caricamento in corso . . .");
                        Sleep(820);
                        system("cls");
                        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                        interfaccia.scrivi("\n+-------------------------------------------------------------+");
                        interfaccia.scrivi("+ Scegli dall'inventario l'oggetto da inviare.                +");
                        interfaccia.scrivi("+ Inserendo il relativo codice spedizione.                    +");
                        for (int i=1; i<= oggetti.get_n_oggetti(); i++)
                        {
                            if(oggetti.get_oggetto(i).get_luogo() == 0)
                            {
                                cout<<"\n - "<<oggetti.get_oggetto(i).get_nome()<<".  codice spedizione: --> "<<i;
                            }
                        }
                        cout<<"\n Codice spedizione: ";
                        cin>>spedizione;
                        interfaccia.scrivi("+ Inserisci il codice del luogo di destinazione.              +");
                        cout<<"\n - Sala controllo del reattore codice luogo             --> 8 +";
                        cout<<"\n - Nella cabina del secondo pilota                      --> 5 +";
                        cout<<"\n Codice luogo: ";
                        cin>>luogo;
                        interfaccia.scrivi("+-------------------------------------------------------------+");
                        if (luogo == 8 || luogo == 5)
                        {
                            oggetti.set_luogo(spedizione,luogo);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Invio in corso . . .");
                            Sleep(820);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+--------------------------------------------------------------+");
                            interfaccia.scrivi("+ Operazione completata!                                       +");
                            interfaccia.scrivi("+--------------------------------------------------------------+");
                        }
                        else
                        {
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("Invio in corso . . .");
                            Sleep(820);
                            system("cls");
                            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                            interfaccia.scrivi("\n+--------------------------------------------------------------+");
                            interfaccia.scrivi("+ Operazione annullata!                                        +");
                            interfaccia.scrivi("+ Codice luogo non valido                                      +");
                            interfaccia.scrivi("+--------------------------------------------------------------+");
                        }
                        uscitainvia=true;
                        break;

                    case 4:
                        system("cls");
                        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                        interfaccia.scrivi("Caricamento in corso . . .");
                        Sleep(820);
                        system("cls");
                        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                        azione_56();
                        uscitainvia=true;
                        break;

                    case 0:
                        uscitainvia=true;
                        break;

                    default:
                        tempo=tempo-1;
                        interfaccia.scrivi("Non ho capito");
                    }
                }
                uscita=true;
                break;

            case 2:
                if(oggetti.get_oggetto(81).get_luogo() == 0) //get_oggetto(x,y) x da 80 a 81 Galeandro
                {
                    system("cls");
                    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                    interfaccia.scrivi(" Caricamento in corso . . .");
                    Sleep(820);
                    system("cls");
                    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                    interfaccia.scrivi("\n+--------------------------------------------------------------+");
                    interfaccia.scrivi("+ Sei nella sezione di ricezione.                              +");
                    if(ufficiopostale.get_Pacco()== false && ufficiopostale.get_Suggerimento()==false)
                    {
                        interfaccia.scrivi("+ Nessun ogetto da ritirare.                                   +");
                        interfaccia.scrivi("\n+--------------------------------------------------------------+");
                    }

                    if(ufficiopostale.get_Pacco() == true && ufficiopostale.get_ritiratoPacco() == false)
                    {
                        interfaccia.scrivi("+ E' arrivato un pacco per te.                                 +");
                        interfaccia.scrivi("+ Controlla il tuo inventario.                                 +");
                        interfaccia.scrivi("+--------------------------------------------------------------+");
                        ufficiopostale.set_ritiratoPacco(true);
                        oggetti.set_luogo(84,0);//set_luogo(x,y) x da 83 a 84 Galeandro
                    }
                    else if(ufficiopostale.get_ritiratoPacco() == true)
                    {
                        interfaccia.scrivi("+ Hai gia' ritirato il pacco                                   +");
                    }

                    if(ufficiopostale.get_Suggerimento()== true && ufficiopostale.get_ritiratoSuggerimento() ==false)
                    {
                        interfaccia.scrivi("+E' arrivata una lettera per te.                               +");
                        interfaccia.scrivi("+ Controlla il tuo inventario.                                 +");
                        interfaccia.scrivi("+--------------------------------------------------------------+");
                        ufficiopostale.set_ritiratoSuggerimento(true);
                        oggetti.set_luogo(82,0);//set_luogo(x,y) x da 81 a 82 Galeandro
                    }
                    else if(ufficiopostale.get_ritiratoSuggerimento()== true)
                    {
                        interfaccia.scrivi("+ Hai gia' ritirato la lettera                                 +");
                    }
                }
                else
                {
                    system("cls");
                    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                    interfaccia.scrivi("\n+--------------------------------------------------------------+");
                    interfaccia.scrivi("+                  Attenzione!                                 +");
                    interfaccia.scrivi("+ Recupera prima il tuo documento d'identita'                  +");
                    interfaccia.scrivi("+ e avrai accesso alla sezione desiderata.                     +");
                    interfaccia.scrivi("+--------------------------------------------------------------+");
                }
                uscita=true;
                break;

            case 0:
                system("cls");
                //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                interfaccia.scrivi("\n+-------------------------------------------------------------+");
                interfaccia.scrivi("+ Grazie e Arrivederci!                                       +");
                interfaccia.scrivi("+-------------------------------------------------------------+");
                uscita=true;
                break;

            default:
                tempo=tempo-1;
                cout<<"\n non capisco";
            }
        }
    }
}

void Astro :: azione_83 ( )
{
    if(oggetti.get_oggetto(84).get_luogo() == 0)//get_oggetto(x) x da 83 a 84 Galeandro
    {
        interfaccia.scrivi("Hai aperto il pacco misterioso.");
        interfaccia.scrivi("Messaggio:");
        interfaccia.scrivi("Ecco a te il doppione della chiave dell'armadietto del secondo pilota!. . .");
        interfaccia.scrivi("Cerca di non perderla! ");
        interfaccia.scrivi("Controlla il tuo inventario. ");
        oggetti.set_luogo(24,0);//set_luogo(x,y) x da 23 a 24 Galeandro
        oggetti.set_luogo(84,-9999);//set_luogo(x,y) x da 83 a 84 Galeandro
    }
    else
    {
        interfaccia.scrivi("Non capisco.");
    }
}

void Astro :: azione_84 ( )
{
    if(oggetti.get_oggetto(82).get_luogo() == 0)//get_oggetto(x) x da 81 a 82 Galeandro
    {
        interfaccia.scrivi("Hai aperto la lettera.");
        interfaccia.scrivi("Messaggio:");
        interfaccia.scrivi("La chiave dell'armadietto del secondo pilota potrebbe essere andata perduta!. . .");
        interfaccia.scrivi("Per fortuna che alla base hanno sempre i pezzi di ricambio! ");
    }
    else
    {
        interfaccia.scrivi("Non capisco.");
    }
}

//Fine modifiche Galeandro



//INIZIO modifiche Moschetti
void Astro::azione_85()
{
    interfaccia.scrivi("Ti sei seduto");
    storia_gioco.insStoria(stringa_comando, "Hai deciso di sederti");  //Aggiorna storia gioco
}






void Astro::azione_86()
{
    bool controllo1=false;
    bool controllo2=false;
    bool controllo3=false;
    Lista <int> l;
    Lista <int>::posizione p;
    p=l.primolista();
    int lib=(rand() % 3) + 1;// creo una variabile che mi randomizzera un numero da 1 a 3 che servirà per decidere quale libro leggere
    if (lib==1 && controllo1==true) // se il libro e' stato gia' letto
    {
        while(l.finelista(p)!=true) //fino a quando non raggiungiamo finelista
        {
            if(l.leggilista(p)==1)
            {
                interfaccia.scrivi("E' UN LIBRO DI MANZONI");
                interfaccia.scrivi("L'HAI GIA' LETTO!!");
            }
            p=l.succlista(p);
        }
    }

    else if (lib==1 && controllo1==false)  //se il libro non è stato ancora letto
    {
        interfaccia.scrivi("E' UN LIBRO DI ALLESSANDRO MANZONI");
        interfaccia.scrivi("");
        interfaccia.scrivi("Ei fu. Sicome immobile,");
        interfaccia.scrivi("dato il mortal sospiro,");
        interfaccia.scrivi("stette la spoglia immemore ");
        interfaccia.scrivi("orba di tanto spiro,...");

        l.inslista(1,p);// inserisce nella lista il numero 1
        p=l.succlista(p);
        controllo1=true;//metto a true il controllo della lettura del libro

        int salute=Salute.GetStatoSalute();// creo una variabile salute in cui metterò il valore della salute del giocatore
        if(salute>=95 ) // se la salute è maggiore o uguale di 95 e non mai stato utilizzato il kit medico
        {
            interfaccia.scrivi("");
            interfaccia.scrivi("HAI TROVATO UN KIT MEDICO MA LA TUA SALUTE E' ANCORA OTTIMA ");
            interfaccia.scrivi("LO USI MA NON HA NESSUN EFFETTO");
        }
        else  // se la salute non è piu maggiore di 95 e non è mai stato utilizzato il kit medico
        {
            interfaccia.scrivi("");
            Salute.SetStatoSalute(salute+5);// agiorno la salute aggiungendo 5 unità
            interfaccia.scrivi("INCREDIBILE!!");
            interfaccia.scrivi("HAI RECUPERATO CINQUE UNITA DI SALUTE!!");
            interfaccia.scrivi("ORA LA TUA SALUTE E' DI:");
            cout << Salute.GetStatoSalute() << endl;// stampa a video della salute aggiornata del giocatore
        }
    }
    else if (lib==2 && controllo2==true) // se il libro e' stato gia' letto
    {

        while(l.finelista(p)!=true) //fino a quando non raggiungiamo finelista
        {
            if(l.leggilista(p)==2)
            {
                interfaccia.scrivi("E' UN LIBRO DI UNGARETTI");
                interfaccia.scrivi("L'HAI GIA' LETTO!!");
            }
            p=l.succlista(p);
        }
    }
    else if (lib==2 && controllo2==false)  //se il libro non è stato ancora letto
    {
        interfaccia.scrivi("E' UN LIBRO DI GIUSEPPE UNGARETTI");
        interfaccia.scrivi("");
        interfaccia.scrivi("M'illumino d'immenso");

        l.inslista(2,p);// inserisce nella lista il numero 2
        p=l.succlista(p);
        controllo2=true;//metto a true il controllo della lettura del libro
    }
    else if(lib==3 && controllo3==true) // se il libro e' stato gia' letto
    {

        while(l.finelista(p)!=true) //fino a quando non raggiungiamo finelista
        {
            if(l.leggilista(p)==3)
            {
                interfaccia.scrivi("E' UN LIBRO DI LEOPARDI");
                interfaccia.scrivi("L'HAI GIA' LETTO!!");
            }
            p=l.succlista(p);
        }
    }
    else if (lib==3 && controllo3==false)  //se il libro non è stato ancora letto
    {
        interfaccia.scrivi("E' UN LIBRO DI GIACOMO LEOPARDI");
        interfaccia.scrivi("");
        interfaccia.scrivi("Silvia, rimembri ancora");
        interfaccia.scrivi("quel tempo della tua vita mortale,");
        interfaccia.scrivi("quando belta' splendea...");

        l.inslista(3,p);// inserisce nella lista il numero 3
        p=l.succlista(p);
        controllo3=true;//metto a true il controllo della lettura del libro
    }
    storia_gioco.insStoria(stringa_comando, "hai deciso di leggere dei libri");  //Aggiorna storia gioco
}



void Astro::azione_87()
{
    int num=(rand() % 4) + 1;// creo una variabile che mi randomizzera un numero da 1 a 4 che servirà per decidere quale ricerca effettuare
    if  (num==1)
    {
        interfaccia.scrivi("Ricerca di matematica:");
        interfaccia.scrivi("I numeri interi (o numeri interi relativi, o semplicemnte, numeri relativi)  ");
        interfaccia.scrivi("sono formati dall'unione dei numeri naturali (0,1,2,..) e dei numeri interi negativi (-1,-2,-3,..) ");
        interfaccia.scrivi("costruiti ponendo un segno - davanti ai numeri naturali");
    }
    else if(num==2)
    {
        interfaccia.scrivi("Ricerca di geografia:");
        interfaccia.scrivi("Taranto e' un comune italiano di 202.063 abitanti capoluogo dell'omonima provincia, in Puglia");
        interfaccia.scrivi("Il clima e' dolce e mite.");
        interfaccia.scrivi("Taranto inoltre e' la casa della marina militare italiana.");
    }
    else if(num==3)
    {
        interfaccia.scrivi("Ricerca di storia:");
        interfaccia.scrivi("La prima guerra mondiale fu un conflitto armato");
        interfaccia.scrivi("che coinvolse le principali potenze mondiali e molte di quelle minori. ");
        interfaccia.scrivi("Il conflitto duro' dal 28 luglio 1914 e l'11 novembre 1918.");
    }
    else if(num==4)
    {
        interfaccia.scrivi("Ricerca di informatica:");
        interfaccia.scrivi("Un bit e' l'unita di misura dell'informazione(binary digit),");
        interfaccia.scrivi("definita come la quantita' minima di informazione");
        interfaccia.scrivi("che serve a discernere tra due possibili ");
        interfaccia.scrivi("eventi equiprobabili.");
    }
    storia_gioco.insStoria(stringa_comando, "hai deciso di usare il computer");  //Aggiorna storia gioco
}



void Astro::azione_88()
{
    int tipo;// creo una variabile in cui mettero il numero della lezione che sceglierò
    interfaccia.scrivi("Ci sono vari tipi di lezioni che puoi sentire");
    interfaccia.scrivi("1) Sicurezza a lavoro");
    interfaccia.scrivi("2) Medicina");
    interfaccia.scrivi("3) Astronomia ");
    interfaccia.scrivi("4) Meccanica ");
    interfaccia.scrivi("");
    interfaccia.scrivi("Quale scegli?");
    cin >> tipo;// scelgo che lezione seguire

    switch(tipo)
    {

    case 1:
        if(tipo==1) // nel caso in cui dovessi scegliere la prima lezione
        {
            interfaccia.scrivi("LEZIONE SULLA SICUREZZA SUL LAVORO!!");
            interfaccia.scrivi("");
            interfaccia.scrivi("La sicurezza sul lavoro e' l'obbiettivo di una attivita' lavorativa");
            interfaccia.scrivi("senza l'esposizione per i lavoratori al rischio di infortuni/incidenti");
            interfaccia.scrivi("e senza il richio di contrarre una malattia professionale. ");
            interfaccia.scrivi("Ecco perche noi raccomandiamo sempre di usare TUTA e CASCO per uscire fuori nello spazio.");
        }
        break;



    case 2:
        if(tipo==2) // nel caso in cui dovessi scegliere la seconda lezione
        {
            interfaccia.scrivi("COME USARE IL PRONTO SOCCORSO!!");
            interfaccia.scrivi("");
            interfaccia.scrivi("Siamo felici di annunciarvi che la nostra nave presenta un pronto soccorso,");
            interfaccia.scrivi("in cui i nostri operai si possono curare dopo aver subito gravi incidenti.");
            interfaccia.scrivi("Pero' per potersi curare  pero' devono essere in posseso di una TESSERA SANITARIA.");
            interfaccia.scrivi("In mancanza di quest'ultima pero' l'operaio potra curarsi anche usando dei GETTONI monouso.");
        }
        break;

    case 3:
        if(tipo==3) // nel caso in cui dovessi scegliere la terza lezione
        {
            interfaccia.scrivi("LEZIONE DI ASTRONOMIA!!");
            interfaccia.scrivi("");
            interfaccia.scrivi("In questo momento ci troviamo vicino ad una stella che forma la costellazione di Andromeda");
            interfaccia.scrivi("Andromeda e' una costellazione che si trova nell'emisfero nord vicino a Pegaso.");
            interfaccia.scrivi("La costellazione ha la forma approssimata  di una lettera A");
            interfaccia.scrivi("E' famosa sopratutto per la presenza della galassia di Andromeda nei suoi confini.");
        }
        break;

    case 4:
        if(tipo==4)  // nel caso in cui dovessi scegliere la quarta lezione
        {
            interfaccia.scrivi("LEZIONE DI MECCANICA ");
            interfaccia.scrivi("");
            interfaccia.scrivi("Nel compartimento stagno della nave sulla pulsantiera ci sono due pulsanti di colori differenti");
            interfaccia.scrivi("Il pulsante Rosso chiude la parete Est e apre la parete Ovest verso lo spazio esterno;");
            interfaccia.scrivi("Il pulsante Verde chiude la parete Ovest e apre la parete Est verso il corridoio;");
            interfaccia.scrivi("Attenti a cosa premete");
        }
        break;

    default:// nel caso in cui dovessi immettere un valore che non corrisponde a nessuna lezione
        interfaccia.scrivi("Lezione non esistente");

    }
    tempo=tempo-5;// ogni qual volta che seguirò una lezione verranno sottratte 5 unità di vita(unità di tempo)
    storia_gioco.insStoria(stringa_comando, "hai deciso di seguire una lezione");  //Aggiorna storia gioco
}



int pr=0;// creo una variabile che mi permetterà di capire se il proiettore è acceso o no
void Astro::azione_89()
{
    if(pr==0)
    {
        interfaccia.scrivi("Hai acceso il proiettore");
        interfaccia.scrivi("MESSAGGIO PROMOZIONALE");
        interfaccia.scrivi("Leggere fa bene alla mente e al corpo");
        interfaccia.scrivi("leggi di piu'");
        interfaccia.a_capo();
        pr=1;//proiettore acceso
    }
    else
    {
        interfaccia.scrivi("Hai già acceso il proiettore"); //MODIFICA ROSA FAGO
    }
    storia_gioco.insStoria(stringa_comando, "hai acceso il proiettore");  //Aggiorna storia gioco
}



void Astro::azione_90()
{
    if (pr==0)//se il  proiettore è spento fai la seguente azione
    {
        interfaccia.scrivi("Il proiettore e' gia' spento");
    }
    else // se il proiettore è acceso stampa messaggio di spegnimento MODIFICA ROSA FAGO
    {
        interfaccia.scrivi("hai spento il proiettore");
        pr=0;
    }
    storia_gioco.insStoria(stringa_comando, "Hai spento il proiettore");  //Aggiorna storia gioco
}
//FINE modifiche Moschetti

//INIZIO MODIFICHE DEL GIUDICE ANGELO
void Astro :: azione_91 ( )
{
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    int num_persone=rand()%11;
    bool uscita_computer=false;
    bool uscita_coda=false;
    string risposta_attesa; //input per la risposta
    int risposta_documento; //input per la risposta al documento

    while (!uscita_coda)
    {
        if (num_persone==0)
        {
            uscita_coda=true;
        }
        else
        {
            interfaccia.scrivi_parziale("Ci sono ");
            interfaccia.scrivi_parziale(num_persone);
            interfaccia.scrivi(" in coda che vogliono utilizzare il computer");
            interfaccia.scrivi("Desideri aspettare (s/n):");
            cin >> risposta_attesa;
            if (risposta_attesa=="s" || risposta_attesa=="sÃ¬" || risposta_attesa=="si")
            {
                tempo=tempo-num_persone;
                uscita_coda=true;
            }
            else if (risposta_attesa=="n" || risposta_attesa=="no")
            {
                uscita_computer=true;
                uscita_coda=true;
            }
            else
            {
                interfaccia.scrivi("Input non compreso. Digitare correttamente le risposte!");
            }
        }
    }


    while (!uscita_computer)
    {
        // Menu di scelta 0,1,...
        ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI

        interfaccia.scrivi(" -------------------------------------------------------------------------------");
        interfaccia.scrivi("|Sistema Archivio 2.0                                                           |");
        interfaccia.scrivi("|Benvenuto Comandante nel sistema di archivio dell'astronave.                   |");
        interfaccia.scrivi("|A causa dei gravi danni subiti, l'integrita' dell'archivio e' compromessa.     |");
        interfaccia.scrivi("|Il sistema e' stato in grado di ripristinare solo alcuni file.                 |");
        interfaccia.scrivi("|Inoltre vi e' un problema nella visualizzazione a schermo dei file.            |");
        interfaccia.scrivi("|I file possono pero' essere stampati senza problemi                            |");
        interfaccia.scrivi("|Per ritirare il documento digitare il numero corrispondente.                   |");
        interfaccia.scrivi("|Attenzione: problemi tecnici rallenteranno il processo di stampa.              |");
        interfaccia.scrivi("|Per uscire digitare il numero corrispondente.                                  |");
        interfaccia.scrivi("|1 <- File12                                                                    |");
        interfaccia.scrivi("|2 <- File13                                                                    |");
        interfaccia.scrivi("|3 <- File15                                                                    |");
        interfaccia.scrivi("|4 <- File21                                                                    |");
        interfaccia.scrivi("|5 <- Uscire dal computer                                                       |");
        interfaccia.scrivi(" -------------------------------------------------------------------------------\n");
        interfaccia.scrivi_parziale("Mosse rimaste: ");
        interfaccia.scrivi_parziale(tempo);
        interfaccia.scrivi_parziale("\n");
        interfaccia.scrivi_parziale("Risposta: ");


        cin >>risposta_documento;
        if(cin.good()==0)
        {
            interfaccia.scrivi("Comando non riconosciuto... stai per uscire!");
            //system("pause");
            cin.clear();
            fflush(stdin);
            return;
        }
        switch (risposta_documento)
        {
        case 1:
            //file12
            if (oggetti.get_oggetto(37).get_luogo() != 0)
            {
                oggetti.set_luogo(37,0);
                interfaccia.scrivi("File12 ritirato!");

                tempo=tempo-(rand()%6+2);
                //system("pause");
            }
            else
            {
                interfaccia.scrivi("File gia' ritirato e disponibile per la lettura!");
                tempo=tempo-1;
                //system("pause");
            }
            break;
        case 2:
            //file13
            if (oggetti.get_oggetto(57).get_luogo() != 0)
            {
                oggetti.set_luogo(57,0);
                interfaccia.scrivi("File13 ritirato!");
                tempo=tempo-(rand()%6+2);
                //system("pause");
            }
            else
            {
                interfaccia.scrivi("File gia' ritirato e disponibile per la lettura!");
                tempo=tempo-1;
                //system("pause");

            }
            break;
        case 3:
            //file15
            if (oggetti.get_oggetto(58).get_luogo() != 0)
            {
                oggetti.set_luogo(58,0);
                interfaccia.scrivi("File15 ritirato!");
                tempo=tempo-(rand()%6+2);
                //system("pause");
            }
            else
            {
                interfaccia.scrivi("File gia' ritirato e disponibile per la lettura!");
                tempo=tempo-1;
                //system("pause");
            }
            break;
        case 4:
            //file21
            if (oggetti.get_oggetto(71).get_luogo() != 0)
            {
                oggetti.set_luogo(71,0);
                interfaccia.scrivi("File21 ritirato!");
                tempo=tempo-(rand()%6+2);
                //system("pause");
            }
            else
            {
                interfaccia.scrivi("File gia' ritirato e disponibile per la lettura!");
                tempo=tempo-1;
                //system("pause");
            }
            break;
        case 5:
            uscita_computer=true;
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            break;
        default:
            interfaccia.scrivi("Comando non riconosciuto... stai per uscire!");
            uscita_computer=true;
            //system("pause");
        }
    }
}
void Astro :: azione_92 ( )
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    if(oggetti.get_oggetto(37).get_luogo() != 0)
    {
        interfaccia.scrivi("Puoi leggere i file solo dopo averli scaricati dal terminale dell'archivio");
    }
    else
    {
        interfaccia.scrivi("File12");
        interfaccia.scrivi("Le simulazioni di volo hanno evidenziato diversi problemi.");
        interfaccia.scrivi("L'equipaggio non e' a conoscenza di particolari rischi derivanti dallo scorretto utilizzo dei sistemi di bordo.");
        interfaccia.scrivi("Per aprire il compartimento stagno e' necessario premere il pulsante rosso.");
        interfaccia.scrivi("Per richiudere il compartimento stagno bisogna premere il verde.");
        interfaccia.scrivi("Pare che i cadetti abbiano fatto l'esatto opposto.");
    }
}
void Astro::azione_93()
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    if(oggetti.get_oggetto(57).get_luogo() != 0)
    {
        interfaccia.scrivi("Puoi leggere i file solo dopo averli scaricati dal terminale dell'archivio");
    }
    else
    {
        interfaccia.scrivi("File13");
        interfaccia.scrivi("La forza di gravita' e' spesso sottovalutata.");
        interfaccia.scrivi("Un cadetto ha effettuato l'altro giorno delle riparazioni fuori dall'astronave");
        interfaccia.scrivi("Aveva, non so come, portato con se' la foto di sua moglie.");
        interfaccia.scrivi("Con suo grande dispiacere l'ha vista roteare nello spazio.");
        interfaccia.scrivi("Persa per sempre.");
    }
}
void Astro::azione_94()
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    if(oggetti.get_oggetto(58).get_luogo() != 0)
    {
        interfaccia.scrivi("Puoi leggere i file solo dopo averli scaricati dal terminale dell'archivio");
    }
    else
    {
        interfaccia.scrivi("File15");
        interfaccia.scrivi("Ieri nella sala mensa e' scoppiata una rissa.");
        interfaccia.scrivi("A quanto pare uno dei cadetti aveva prodotto delle osservazioni poco lusinghiere su un collega.");
        interfaccia.scrivi("L'armonia dell'equipaggio e' fondamentale per portare a termine la missione.");
        interfaccia.scrivi("Sono stati presi severi provvedimenti nei confronti dei fautori della rissa.");
        interfaccia.scrivi("Simili accadimenti non dovranno ripetersi.");
    }
}
void Astro::azione_95()
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    if(oggetti.get_oggetto(71).get_luogo() != 0)
    {
        interfaccia.scrivi("Puoi leggere i file solo dopo averli scaricati dal terminale dell'archivio");
    }
    else
    {
        interfaccia.scrivi("File21");
        interfaccia.scrivi("Il reattore dell'astronave ha fatto registrare dei valori anomali negli ultimi giorni.");
        interfaccia.scrivi("Ne ho parlato con il comandante e sembra d'accordo nell'avviare un'indagine approfondita.");
        interfaccia.scrivi("Dobbiamo essere operativi al cento per cento per proseguire.");
        interfaccia.scrivi("Stilero' un manuale da consultare in caso di emergenza.");
        interfaccia.scrivi("Mi sembra la cosa piu' giusta da fare.");
    }
}
void Astro::azione_96()
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI windows os

    int num_persone=(rand()+1)%11;
    bool uscita_museo=false;
    bool uscita_coda=false;
    string risposta_attesa; //input per la risposta
    int risposta_documento; //input per la risposta al documento

    while (!uscita_coda)
    {
        if (num_persone==0)
        {
            uscita_coda=true;
        }
        else
        {
            interfaccia.scrivi_parziale("Ci sono ");
            interfaccia.scrivi_parziale(num_persone);
            interfaccia.scrivi("  persone in coda per pagare il biglietto /n");
            interfaccia.scrivi("Il costo del biglietto e' 10 euro");
            interfaccia.scrivi("Desideri aspettare e pagare? (s/n):");
            cin >> risposta_attesa;

            if (risposta_attesa=="s" || risposta_attesa=="sÃ¬" || risposta_attesa=="si")
            {
                bool controlla=false;
                tempo=tempo-num_persone;
                uscita_coda=true;
                controlla=biglietto_museo();
                if(controlla==false)
                    uscita_museo=true;
            }
            else if (risposta_attesa=="n" || risposta_attesa=="no")
            {
                uscita_museo=true;
                uscita_coda=true;
            }
            else
            {
                interfaccia.scrivi("Input non compreso. Digitare correttamente le risposte!");
            }
        }
    }

    //INIZIO MODIFICHE ANTONIO PASTORELLI
    Museo museo;
    Lista<typename Grafo<StanzaMuseo,unsigned char>::nodo> listastanze;


    while (!uscita_museo)
    {
        copiaLista(listastanze,museo.getstanzeadiacenti());
        interfaccia.scrivi(" -----------------------------------------------------------------------------");
        cout<<endl<<museo.leggiStanza(museo.getstanzacorrente()).gettitolo()<<endl<<endl;
        cout<<museo.leggiStanza(museo.getstanzacorrente()).getdescrizione()<<endl<<endl;
        interfaccia.scrivi(" -----------------------------------------------------------------------------");

        int risposta;

        cout<<"Scegliere la stanza nella quale spostarsi:"<<endl;
        typename Lista<Grafo<StanzaMuseo, unsigned char>::nodo>::posizione indice = listastanze.primolista();
        int i = 0;
        while(!listastanze.finelista(indice))
        {
            cout<< i<<" - "<<museo.leggiStanza(listastanze.leggilista(indice)).gettitolo()<<endl;
            i++;
            indice = listastanze.succlista(indice);
        }
        cout<<i<<" - Uscita dal Museo"<<endl;

        i--;

        cin>>risposta;


        if (!cin)
        {
            cin.clear();
            cin.ignore(256,'\n');
            system("cls");
            //system("clear"); //linux os
            interfaccia.scrivi("Input errato");
            fflush(stdin);

        }
        else
        {

            if((risposta>=0)&&(risposta<=i))
            {
                int j = 0;
                indice = listastanze.primolista();
                while(!(listastanze.finelista(indice)))
                {
                    if(j == risposta)
                    {
                        museo.setstanzacorrente(listastanze.leggilista(indice));
                        indice = listastanze.succlista(indice);
                        j++;
                    }
                    else
                    {
                        indice = listastanze.succlista(indice);
                        j++;
                    }

                }
                fflush(stdin);
                system("cls");
                //system("clear"); //linux os
            }
            else if(risposta == i+1)
            {
                museo.setstanzacorrente(museo.getiniziale());
                uscita_museo = true;
                system("cls");
                //system("clear"); //linux os
                fflush(stdin);
            }
            else
            {
                system("cls");
                //system("clear"); //linux os
                cout<<"Input errato"<<endl;
                fflush(stdin);
            }
            fflush(stdin);
        }
        //FINE MODIFICHE ANTONIO PASTORELLI
        // Modifiche di ANGELO DE GIUDICE sostituite dal codice precedente
        /*interfaccia.scrivi(" -----------------------------------------------------------------------------------");
        interfaccia.scrivi("|Benvenuto nel museo delle scienze                                                 |");
        interfaccia.scrivi("|Hai a disposizione una serie di gallerie visitabili, ognuna delle quali           |");
        interfaccia.scrivi("|Presenta diversi percorsi con varie tipologie di esposizioni.                     |");
        interfaccia.scrivi("|Scegli il percorso che vuoi visitare, altrimenti premi 5 per uscire:              |");
        interfaccia.scrivi("|1 <- Galleria A                                                                   |");
        interfaccia.scrivi("|2 <- Galleria B                                                                   |");
        interfaccia.scrivi("|3 <- Galleria C                                                                   |");
        interfaccia.scrivi("|4 <- Galleria D                                                                   |");
        interfaccia.scrivi("|5 <- Uscire dal museo                                                             |");
        interfaccia.scrivi(" ---------------------------------------------------------------------------------\n");
        interfaccia.scrivi_parziale("Mosse rimaste: ");
        interfaccia.scrivi_parziale(tempo);
        interfaccia.scrivi_parziale("\n");
        interfaccia.scrivi_parziale("Risposta: ");
            cin >> risposta_documento;
            if(cin.good()==0)
                   {
                interfaccia.scrivi("Comando non riconosciuto");
                //system("pause");
                cin.clear();
                fflush(stdin);
                return;
                    }
            switch (risposta_documento) {
            case 1:
             ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
             mostra_galleria_a();

             break;
            case 2:
              ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                mostra_galleria_b();
                break;
            case 3:
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                mostra_galleria_c();
                break;
            case 4:
                 ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                mostra_galleria_d();
                break;
           case 5:
                uscita_museo=true;
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                break;
            default:
                interfaccia.scrivi("Comando non riconosciuto");
                uscita_museo=true;
                //system("pause");

            }*/

    }
}

//FINE MODIFICHE DEL GIUDICE ANGELO

//INIZIO MODIFICHE BASILE ANTONIO
//guarda registro
void Astro::azione_97()
{
    interfaccia.scrivi("|---------------------------------------------------------------|");
    interfaccia.scrivi("|-------------- Registro degli Alunni 2A -----------------------|");
    interfaccia.scrivi("|- Data: 16/02/2017.............................................|");
    interfaccia.scrivi("|- Albano Giuseppe.......................................ASSENTE|");
    interfaccia.scrivi("|- Albino Gianni.........................................ASSENTE|");
    interfaccia.scrivi("|- Franco Walter........................................PRESENTE|");
    interfaccia.scrivi("|- D'angelo Giuseppe.....................................ASSENTE|");
    interfaccia.scrivi("|- Zagaria Marcello.....................................PRESENTE|");
    interfaccia.scrivi("|---------------------------------------------------------------|");
}
//gioco dell'impiccato
void Astro::azione_98()
{
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    string risp;

    if(!gioco_impiccato)
    {
        do
        {
            interfaccia.scrivi("c'e' scritto qualcosa.....");
            interfaccia.scrivi("sembra che sia un gioco...");
            interfaccia.scrivi("e' il gioco dell'impiccato!!!");
            risp = interfaccia.leggi_stringa("Vuoi giocare al gioco dell'impiccato? [Si/No]");
        }
        while(risp != "SI" && risp != "NO" && risp != "si" && risp != "no" && risp != "n" && risp != "s");
        if(risp == "si" || risp == "SI" || risp == "s")
        {
            gioco_impiccato = true;
            string parola = "giocattolo";
            string parola_nascosta = "g****t****";
            string parola_indovinata;
            int num_tentativi = 3;
            int lunghezza = parola.length();
            bool indovina = false;
            bool controllo;
            bool trovato;
            char carattere;

            do
            {
                interfaccia.scrivi_parziale("Hai ");
                interfaccia.scrivi_parziale(num_tentativi);
                interfaccia.scrivi_parziale(" tentativi");
                interfaccia.a_capo();
                do
                {
                    interfaccia.scrivi(parola_nascosta);
                    risp = interfaccia.leggi_stringa("Vuoi indovinare la parola?");
                }
                while(risp != "SI" && risp != "NO" && risp != "si" && risp != "no" && risp != "n" && risp != "s");
                if(risp == "si" || risp == "s" || risp == "Si")
                {
                    indovina = true;
                    parola_indovinata = interfaccia.leggi_stringa("Scrivi parola: ");
                    if(parola == parola_indovinata)
                    {
                        interfaccia.scrivi("La parola e': giocattolo");
                        interfaccia.scrivi("Hai Vinto!!!");
                        interfaccia.scrivi("Ti verra' incrementato il tempo di 40 punti!");
                        tempo = tempo + 40;
                    }
                    else
                    {
                        interfaccia.scrivi("La parola da indovinare era: giocattolo");
                        interfaccia.scrivi("Hai Perso!!!");
                        interfaccia.scrivi("Hai perso tempo ti verra' decrementato il tempo di 40 punti!");
                        tempo = tempo - 40;
                    }
                }
                else
                {
                    trovato = false;
                    carattere = interfaccia.leggi_carattere("Inserisci carattere: ");
                    for(int i = 1; i <= lunghezza; i++)
                    {
                        if(parola_nascosta[i] == '*')
                        {
                            if(parola[i] == carattere)
                            {
                                parola_nascosta[i] = carattere;
                                trovato = true;
                            }
                        }
                    }

                    if(!trovato)
                    {
                        interfaccia.scrivi("Non hai indovinato nessun carattere");
                        num_tentativi--;
                    }
                    else
                    {
                        controllo = false;
                        for(int i = 0; i <= lunghezza && !controllo; i++)
                        {
                            if(parola_nascosta[i] == '*')
                                controllo = true;
                        }
                        if(!controllo)
                        {
                            interfaccia.scrivi("La parola e': giocattolo");
                            interfaccia.scrivi("Hai Vinto!!!");
                            interfaccia.scrivi("Ti verra' incrementato il tempo di 40 punti!");
                            tempo = tempo + 40;
                            indovina = true;
                        }
                    }
                }
            }
            while(num_tentativi > 0 && !indovina);
            if(num_tentativi == 0)
            {
                interfaccia.scrivi("La parola da indovinare era: giocattolo");
                interfaccia.scrivi("Hai Perso!!!");
                interfaccia.scrivi("Hai perso tempo ti verra' decrementato il tempo di 40 punti!");
                tempo = tempo - 40;
            }
        }
        else
            interfaccia.scrivi("Hai cose piu importanti da fare... salva l'astronave Neutronia!!!");
    }
    else
        interfaccia.scrivi("Hai gia' giocato... salva l'astronave Neutronia!!!");
}
//parla con il preside
void Astro::azione_100()
{

    string nome;
    string accetta;
    string risposta;

    if(!gioco_preside)
    {
        interfaccia.scrivi("Salve, benvenuto nella Scuola Elementare della Neutronia");
        nome = interfaccia.leggi_stringa("Con chi ho il piacere di parlare?");
        interfaccia.scrivi_parziale("Quindi lei e' ");
        interfaccia.scrivi_parziale(nome);
        interfaccia.a_capo();

        do
        {
            accetta = interfaccia.leggi_stringa("Ho un problema da risolvere... Mi puo' aiutare??? [Si/No]");
        }
        while(accetta != "si" && accetta != "s" && accetta != "Si" &&
                accetta != "no" && accetta != "n" && accetta != "No");

        if(accetta == "si" || accetta == "s" || accetta == "Si")
        {
            gioco_preside = true;
            interfaccia.scrivi("Benissimo!\n");
            interfaccia.scrivi("Sto cercando di risolvere un cruciverba...");
            risposta = interfaccia.leggi_stringa("9 orizzontale.... un arma simile ad un arco...");
            if(risposta == "balestra")
            {
                interfaccia.scrivi("Grazie mille!!!");
                interfaccia.scrivi("Il tuo tempo e' stato incrementato di 10 punti!!!");
                tempo = tempo + 10;
            }
            else
            {
                interfaccia.scrivi("Hai Sbagliato!!!");
                interfaccia.scrivi("La parola era BALESTRA");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti!!!");
                tempo = tempo - 10;
            }

            interfaccia.scrivi("Seconda domanda...");
            risposta = interfaccia.leggi_stringa("1 orizzontale... L'ultima fa traboccare il vaso: ");

            if(risposta == "goccia")
            {
                interfaccia.scrivi("Grazie mille!!!");
                interfaccia.scrivi("Il tuo tempo e' stato incrementato di 10 punti!!!");
                tempo = tempo + 10;
            }
            else
            {
                interfaccia.scrivi("Hai Sbagliato!!!");
                interfaccia.scrivi("La parola era Goccia");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti!!!");
                tempo = tempo - 10;
            }

            interfaccia.scrivi("Un'altra domanda...");
            risposta = interfaccia.leggi_stringa("10 verticale.... Interruttore per... liquidi: ");
            if(risposta == "rubinetto")
            {
                interfaccia.scrivi("Grazie mille!!!");
                interfaccia.scrivi("Il tuo tempo e' stato incrementato di 10 punti!!!");
                tempo = tempo + 10;
            }
            else
            {
                interfaccia.scrivi("Hai Sbagliato!!!");
                interfaccia.scrivi("La parola era Rubinetto");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti!!!");
                tempo = tempo - 10;
            }

        }
        else
        {
            interfaccia.scrivi_parziale("Ciao ");
            interfaccia.scrivi_parziale(nome);
            interfaccia.a_capo();
        }
    }
    else
        interfaccia.scrivi("Hai gia' parlato con il preside");
}
//parla con la maestra Clara
void Astro::azione_101()
{
    if(!gioco_prof_clara)
    {
        string risp;
        do
        {
            interfaccia.scrivi("Salve sono la maestra Clara");
            risp = interfaccia.leggi_stringa("Insegno storia, vuoi fare un test? [Si/No]");

        }
        while(risp != "Si" && risp != "No" && risp != "s" && risp != "n" &&
                risp != "si" && risp != "no");

        if(risp == "Si" || risp == "s" || risp == "si")
        {
            string risposta;
            gioco_prof_clara = true;

            interfaccia.scrivi("Rispondi alle seguenti domande:");
            risposta = interfaccia.leggi_stringa("Prima domanda: Quando cadde l'Impero Romano d'Occidente?");
            if(risposta == "476 d.C." || risposta == "476 d.c.")
            {
                tempo = tempo + 5;
                interfaccia.scrivi("Risposta Esatta");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti");
            }
            else
            {
                tempo = tempo - 10;
                interfaccia.scrivi("Risposta sbagliata");
                interfaccia.scrivi("il tuo tempo e' stato decrementato di 10 punti");
            }
            interfaccia.a_capo();
            risposta = interfaccia.leggi_stringa("Seconda domanda: Quando venne scoperta l'America?");
            if(risposta == "1492")
            {
                tempo = tempo + 5;
                interfaccia.scrivi("Risposta Esatta");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti");
            }
            else
            {
                tempo = tempo - 10;
                interfaccia.scrivi("Risposta sbagliata");
                interfaccia.scrivi("il tuo tempo e' stato decrementato di 10 punti");
            }
            interfaccia.a_capo();
            risposta = interfaccia.leggi_stringa("Terza Domanda: Quando esplose la prima Guerra Mondiale?");
            if(risposta == "1914")
            {
                tempo = tempo + 5;
                interfaccia.scrivi("Risposta Esatta");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti");
            }
            else
            {
                tempo = tempo - 10;
                interfaccia.scrivi("Risposta sbagliata");
                interfaccia.scrivi("il tuo tempo e' stato decrementato di 10 punti");
            }
        }
        else
            interfaccia.scrivi("Ok ci vediamo!");

    }
    else
        interfaccia.scrivi("Hai gia' parlato con la maestra Clara");
}
//parla con la maestra mara
void Astro::azione_102()
{
    if(!gioco_prof_mara)
    {
        string risp;
        do
        {
            interfaccia.scrivi("Salve sono la maestra Mara");
            risp = interfaccia.leggi_stringa("Insegno matematica, Vuoi fare un test? [Si/No]");
        }
        while(risp != "Si" && risp != "No" && risp != "s" && risp != "n" &&
                risp != "si" && risp != "no");

        if(risp == "Si" || risp == "s" || risp == "si")
        {
            gioco_prof_mara = true;
            int num_esatte;
            string risp1, risp2, risp3;
            interfaccia.scrivi("Risolvi le seguenti espressioni: ");
            interfaccia.scrivi("1. [(3*4)/2+5*6-(10/5)*6]");
            interfaccia.scrivi("2. [6*7-18*(5-12)]");
            interfaccia.scrivi("3. [(4^2/8)*7+(2^3)*4]");
            interfaccia.a_capo();

            risp1 = interfaccia.leggi_stringa("Risultato della prima espressione:   ");

            if(risp1 == "24")
            {
                interfaccia.scrivi("Risposta Corretta! Bravo!!!");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti.");
                tempo = tempo + 5;
            }
            else
            {
                interfaccia.scrivi("Risposta Sbagliata!");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti");
                tempo = tempo - 10;
            }

            risp2 = interfaccia.leggi_stringa("Risultato della seconda espressione: ");

            if(risp2 == "168")
            {
                interfaccia.scrivi("Risposta Corretta! Bravo!!!");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti.");
                tempo = tempo + 5;
            }
            else
            {
                interfaccia.scrivi("Risposta Sbagliata!");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti");
                tempo = tempo - 10;
            }

            risp3 = interfaccia.leggi_stringa("Risultato della terza esprezzione:   ");

            if(risp3 == "46")
            {
                interfaccia.scrivi("Risposta Corretta! Bravo!!!");
                interfaccia.scrivi("il tuo tempo e' stato incrementato di 5 punti.");
                tempo = tempo + 5;
            }
            else
            {
                interfaccia.scrivi("Risposta Sbagliata!");
                interfaccia.scrivi("Il tuo tempo e' stato decrementato di 10 punti");
                tempo = tempo - 10;
            }
        }
        else
        {
            interfaccia.scrivi("Ok ci vediamo");
        }
    }
    else
        interfaccia.scrivi("Hai gia' parlato con la maestra Mara");
}
//guarda cartina galattica
void Astro::azione_103()
{
    interfaccia.scrivi("e' una cartina che rappresenta il Sistema Solare");
}
//guarda cartina geografica
void Astro::azione_104()
{
    interfaccia.scrivi("cartina che rappresenta la penisola Italiana");
}
//FINE MODIFICHE BASILE ANTONIO



//INIZIO MODIFICHE VACCA GIANLUCA

//Accendi il proiettore rotto
void Astro::azione_105()
{
    interfaccia.scrivi("e' un proiettore non funzionante, la lente e' rotta");
}

//Guarda lo schermo nell'auditorium
void Astro::azione_106()
{
    interfaccia.scrivi("Lo schermo non mostra nulla poiche' il proiettore non e' acceso.");
}

//Guarda la finestra chiusa
void Astro::azione_107()
{
    interfaccia.scrivi("Lo spettacolo deve essere mozzafiato... peccato che il sistema di sicurezza abbia attivato la chiusura di tutte le finestre della Neutronia...");
}

//Parla al microfono
void Astro::azione_108()
{
    interfaccia.scrivi("La mia voce rieccheggia in tutto l'Auditorium! Meglio smetterla prima di ricevere una lavata di capo...");
}


//Interagisci con il Jukebox Antico

void Astro::azione_109()
{

    string decisione; //per contenere la decisione dell'utente
    interfaccia.scrivi("E' un antico Jukebox! L'acustica qua e' perfetta!");
    jukeboxAttivo = true;
    while(jukeboxAttivo)
    {
        canzone = canzoni.leggilista(canzoneScelta);
        playlist.incoda(canzone); //inserisce nella coda la canzone in riproduzione.
        cout << "\n";
        cout << canzone;  //possibile grazie all'overload dell'operatore
        interfaccia.scrivi("Posso andare alla prima canzone, a quella precedente o a quella successiva. Cosa faccio?");

        cin >> decisione;

        if ( (decisione.compare("prima") == 0) || (decisione.compare("Prima") == 0) || (decisione.compare("PRIMA") == 0) )
        {
            canzoneScelta = canzoni.primolista();
            canzoneInRiproduzione = 0;
        }
        else if( (decisione.compare("successiva") == 0) || (decisione.compare("Successiva") == 0) || (decisione.compare("SUCCESSIVA") == 0) )
        {
            if ( canzoni.finelista(canzoni.succlista(canzoneScelta)) )
            {
                interfaccia.scrivi("Poiche' e' l'ultima canzone, il Jukebox e' tornato alla prima canzone.");
                canzoneScelta = canzoni.primolista();
                canzoneInRiproduzione = 0;
            }
            else
            {
                canzoneScelta = canzoni.succlista(canzoneScelta);
                canzoneInRiproduzione++;
            }
        }
        else if ( (decisione.compare("precedente") == 0) || (decisione.compare("Precedente") == 0) || (decisione.compare("PRECEDENTE") == 0) )
        {

            if (canzoneScelta == canzoni.primolista() )
            {
                canzoneScelta = canzoni.primolista();
                canzoneInRiproduzione = 0;
                interfaccia.scrivi("Questo jukebox non puo' tornare dalla prima canzone all'ultima!");
            }
            else
            {
                canzoneScelta = canzoni.preclista(canzoneScelta);
                canzoneInRiproduzione--;
            }
        }
        else
        {
            jukeboxAttivo = false;
        }
    }
    cout <<"\n" << "\n" << "\n";
    interfaccia.scrivi("Meglio che vada a salvare la Neutronia...");
    interfaccia.scrivi("Ho ascoltato, nel seguente ordine, queste canzoni: ");
    cout << "\n";
    int cnt = 0; //Per far stampare il numero affianco alla canzone
    //Stampa tutta la playlist.
    while(!playlist.codavuota())
    {
        cnt++;
        canzone = playlist.leggicoda();
        playlist.fuoricoda();
        cout << cnt <<") " << canzone.get_nome() << "\n"; //Evito di stampare tutti i brano con il COUT della Classe Canzone
    }
}

//Guarda gli strumenti Musicali
void Astro::azione_110()
{
    interfaccia.scrivi("Sul palco dell'Auditorium sono presenti una chitarra, un violino e un pianoforte");
}


//Suona uno strumento musicale. L'IF permette di scegliere quale strumento suonare
void Astro::azione_111()
{
    string strumentoDaSuonare;
    interfaccia.scrivi("Potrei provare a suonare il violino, il pianoforte o la chitarra... ");
    interfaccia.scrivi("Quale scelgo?");
    cin >> strumentoDaSuonare;

    if (strumentoDaSuonare.compare("violino") ==0)
    {
        interfaccia.scrivi("Provo a sfregare l'archetto sulle corde del violino... ma i risultati sono disastrosi...");
    }
    else if (strumentoDaSuonare.compare("pianoforte") ==0)
    {
        interfaccia.scrivi("Nell'auditorium rieccheggiano le poche note che conosco della Sinfonia numero 9.");
    }
    else if (strumentoDaSuonare.compare("chitarra")==0)
    {
        interfaccia.scrivi("Forse in un'altra vita ero capace di suonarla... ma non in questa.");
    }
    else
    {
        interfaccia.scrivi("Forse e' meglio lasciar stare...");
    }
}


//Interagisci con le luci dell'auditorium VACCA
void Astro::azione_112()
{

    string nome_luce;
    int bottonePremuto;
    bool inputValido = true;

    interfaccia.scrivi("E' un pannello di controllo delle luci dell'Auditorium");
    interfaccia.scrivi("Vedo dei bottoni che si illuminano numerati, con un'etichetta affianco");
    cout << "\n";
    if (luciAuditoriumAccese.insiemevuoto() )
    {
        interfaccia.scrivi("Tutte le luci dell'Auditorium sono spente");
    }
    else
    {
        for(int i= 1; i  <sizeof(nome_luci_auditorium)/sizeof(nome_luci_auditorium[0]); i++)
        {
            luce.setNome(nome_luci_auditorium[i]);
            if (luciAuditoriumAccese.appartiene(luce))
            {
                cout << "La luce " << luce << " e' accesa \n";
            }
        }
    }
    //Si potrebbero usare direttamente i nomi delle luci per scrivere le etichette affianco ai bottoni,
    cout << "\n";
    interfaccia.scrivi("1. Destra Avanti");
    interfaccia.scrivi("2. Sinistra Avanti");
    interfaccia.scrivi("3. Destra Dietro");
    interfaccia.scrivi("4. Sinistra Dietro");
    interfaccia.scrivi("5. Palco");

    cout << "\n";
    interfaccia.scrivi("Quale bottone premo?");

    cin >> bottonePremuto;

    if ( (cin.fail() ) || (bottonePremuto >5) || (bottonePremuto<1))
    {
        interfaccia.scrivi("Meglio che vada a salvare la Neutronia...");
        inputValido = false;
    }

    else
        nome_luce=nome_luci_auditorium[bottonePremuto];

    if (inputValido)
    {
        luce.setNome(nome_luce);

        if (!luciAuditoriumAccese.appartiene(luce))
        {
            luciAuditoriumAccese.inserisci(luce);
            cout << "La luce che si trova " << luce << " e' ora accesa. \n" ;
        }
        else
        {
            luciAuditoriumAccese.cancella(luce);
            cout << "La luce che si trova " << luce << " e' ora spenta. \n" ;

        }
    }

}

//Guarda la scacchiera
void Astro::azione_113()
{
    interfaccia.scrivi("La scacchiera, per qualche motivo, ha 8 regine schierate.");
    interfaccia.scrivi("Sono disposte in maniera tale che nessuna possa mangiare l'altra.");
    interfaccia.scrivi("Mi chiedo il motivo di questa curiosa disposizione...");
}

//FINE MODIFICHE VACCA GIANLUCA


//INIZIO modifiche SALVATORE VESTITA


void Astro::azione_114()
{

    interfaccia.scrivi("Ti sei seduto.");

    storia_gioco.insStoria(stringa_comando, "Hai deciso di sederti");  //Aggiorna storia gioco"
    cout << "Ecco il tuo tempo a disposizione: " << tempo;
    interfaccia.a_capo();
    tempo--;

    interfaccia.scrivi("Non sprecare il tuo tempo restando seduto!!!");
    interfaccia.a_capo();

    string risp;
    cout << "Vuoi alzarti? ";
    cin >> risp;


    while(risp!="si" && risp!="SI" && risp!="Si" && risp!="sI")
    {
        cout << "E ora ti vuoi alzare? ";
        cin >> risp;
    }

    cout << "Ti sei alzato";
    storia_gioco.insStoria(stringa_comando, "Hai deciso di alzarti");  //Aggiorna storia gioco
}

//void Astro::azione_118(){
//    if(seduto){
//        interfaccia.scrivi("Ti sei alzato");
//        seduto=false;
//        storia_gioco.insStoria(stringa_comando , "Hai deciso di alzarti"); //Aggiorna storia gioco
//    }
//    else{
//        interfaccia.scrivi("Non puoi alzarti se non sei seduto!");
//    }
//}

bool biglietto=false;


void Astro::azione_115()
{


    /*
     CREO UN DIZIONARIO CHIAMATO "BIGLIETTI", FORMATO DALLA COPPIA <CHIAVE, VALORE>:
     - CHIAVE: CODICE (UNIVOCO) DEL LUOGO
     - VALORE: BIGLIETTO (HO CREATO LA CLASSE BIGLIETTO, IL QUALE E' FORMATO DALLA COPPIA:
                          *NOME DELLA DESTINAZIONE
                          *COSTO DEL BIGLIETTO)
    */

    Biglietto b1("aula",100);
    Biglietto b2("ristorante",80);
    Biglietto b3("stadio",50);
    Biglietto b4("banca",49);

    Dizionario<int, Biglietto> Biglietti;
    Biglietti.inserisci(25,b1);
    Biglietti.inserisci(21,b2);
    Biglietti.inserisci(17,b3);
    Biglietti.inserisci(15,b4);

    //CREO UNA CODA PER SIMULARE IL NUMERO DI PERSONE IN CODA ALLA BIGLIETTERIA
    Coda<int> c;
    int casuale, numpersincoda, i;
    casuale=rand()%10;
    numpersincoda=0;
    i=0;

    while(i<=casuale)
    {
        i++;
        c.incoda(i);
    }

    numpersincoda=i; //variabile che conterrà il numero di persone in coda

    string input;//variabile che conterrà l'input dato dall'utente
    //string selezione;//variabile in cui inserire il luogo di destinazione scelto
    float denaro;//variabile che conterrà il denaro disponibile

    if(portafoglio.hai_Portafoglio(oggetti))
    {
        while(input!="si" && input!="s" && input!="Si" && input!="SI" && input!="no" && input!="NO" && input !="No" && input!="n" && input!="N")
        {
            if(numpersincoda>1)
            {

                interfaccia.scrivi_parziale(numpersincoda);
                interfaccia.scrivi(" persone sono in coda ad attendere il proprio turno, desidera attendere? [si/no]");
            }
            else if(numpersincoda==0)
            {
                interfaccia.scrivi("E' il tuo turno vuoi prenotare un biglietto? [si/no]");
            }
            else if(numpersincoda==1)
            {
                interfaccia.scrivi("C'e' una sola persona in coda, desidera attendere? [si/no]");
            }
            cin>>input;
            if(input=="si" || input=="s" ||input=="S" || input=="Si"||input=="SI" || input=="sI")
            {
                tempo-=numpersincoda;
                i=0;
                while(i<=casuale)
                {
                    i++;
                    c.fuoricoda();
                }
                cout << "\n\n\n";
                interfaccia.scrivi("########################################################");//messaggio di output per la biglietteria
                interfaccia.scrivi("########################################################");
                interfaccia.scrivi("####       BENVENUTO IN FERROVIE PER LO SPAZIO      ####");
                interfaccia.scrivi("####             DOVE DESIDERA ANDARE?              ####");
                interfaccia.scrivi("####     SCEGLIERE TRA LE SEGUENTI DESTINAZIONI:    ####");
                interfaccia.scrivi("####       -25: AULA         (costo=100)            ####");
                interfaccia.scrivi("####       -21: RISTORANTE   (costo=80)             ####");
                interfaccia.scrivi("####       -17: STADIO       (costo=55)             ####");
                interfaccia.scrivi("####       -15: BANCA        (costo=49)             ####");
                interfaccia.scrivi("####       -0: (PER USCIRE)                         ####");
                interfaccia.scrivi("########################################################");
                interfaccia.scrivi("########################################################");
                interfaccia.scrivi("########################################################");
                interfaccia.scrivi("####       N.B I BIGLIETTI ACQUISTATI NON SONO      ####");
                interfaccia.scrivi("####         RIMBORSABILI PER ALCUN MOTIVO          ####");
                interfaccia.scrivi("########################################################");
                interfaccia.scrivi("########################################################");

                interfaccia.a_capo();


                int codiceinserito;
                int costo;
                interfaccia.a_capo();
                cout << "INSERISCI CODICE LUOGO: ";
                cin >> codiceinserito;

                if(codiceinserito==0)
                {
                    interfaccia.scrivi("###       HAI DECISO DI ANNULLARE L'OPERAZIONE!      ###");
                }

                while(!Biglietti.appartiene(codiceinserito) && codiceinserito!=0)
                {
                    interfaccia.scrivi("####           DESTINAZIONE NON VALIDA!             ####");
                    cout << "INSERISCI NUOVAMENTE IL CODICE LUOGO: ";
                    cin >> codiceinserito;
                }

                if(Biglietti.appartiene(codiceinserito))
                {
                    Biglietto b;
                    b = Biglietti.recupera(codiceinserito);
                    costo=b.getCosto();
                    string destinazione=b.getDestinazione();
                    std::transform(destinazione.begin(), destinazione.end(), destinazione.begin(), ::toupper);

                    if(portafoglio.get_contanti()>=costo)
                    {
                        cout <<"\n\nHAI ACQUISTATO UN BIGLIETTO PER: " << destinazione << "!";
                        denaro=portafoglio.get_contanti();
                        biglietto=true;
                        denaro-=costo;
                        portafoglio.set_contanti(denaro); //aggiornamento denaro
                    }
                    else
                    {
                        interfaccia.a_capo();
                        interfaccia.scrivi("ATTENZIONE! Non hai abbastanza soldi.");
                    }
                }

                /*
                BIGLIETTERIA VECCHIA SENZA L'UTILIZZO DI UN DIZIONARIO
                    cin>>selezione;//luogo di destinazione scelto dall'utente
                    while(selezione!="AULA" && selezione!="Aula" && selezione!="aula"&& selezione!="RISTORANTE" && selezione!="Ristorante" && selezione!="ristorante"&&
                          selezione!= "STADIO" && selezione!= "Stadio" && selezione != "stadio" && selezione!="BANCA"&&
                          selezione!="Banca"&& selezione!="banca"&& selezione!="ANNULLA" && selezione!="Annulla"&&selezione!="annulla"){

                            interfaccia.scrivi("#### SELEZIONE NON VALIDA REIMMETTERE DESTINAZIONE ####");
                            cin>>selezione;}

                            if(selezione=="AULA" || selezione=="Aula" || selezione=="aula"){
                                if(portafoglio.get_contanti()>=100){
                                    interfaccia.scrivi("####            HAI ACQUISTATO UN BIGLIETTO PER AULA             ####");
                                    denaro=portafoglio.get_contanti();
                                    biglietto=true;
                                    denaro-=100;
                                    portafoglio.set_contanti(denaro);//aggiornamento denaro

                                }
                                else{
                                    interfaccia.scrivi("non hai abbastanza soldi ");
                                }

                            }

                           else if(selezione=="RISTORANTE" || selezione=="Ristorante" || selezione=="ristorante"){
                                if(portafoglio.get_contanti()>=80){
                                    interfaccia.scrivi("####            HAI ACQUISTATO UN BIGLIETTO PER RISTORANTE             ####");
                                    denaro=portafoglio.get_contanti();
                                    biglietto=true;
                                    denaro-=80;
                                    portafoglio.set_contanti(denaro);//aggiornamento denaro

                                }

                                else{
                                    interfaccia.scrivi("non hai abbastanza soldi ");
                                }
                            }

                           else if(selezione=="STADIO"|| selezione=="Stadio" || selezione =="stadio"){
                                if(portafoglio.get_contanti()>=55){
                                    interfaccia.scrivi("####            HAI ACQUISTATO UN BIGLIETTO PER STADIO             ####");
                                    denaro=portafoglio.get_contanti();
                                    biglietto=true;
                                    denaro-=55;
                                    portafoglio.set_contanti(denaro);//aggiornamento denaro

                            }

                            else{
                                    interfaccia.scrivi("non hai abbastanza soldi ");
                                }

                          }

                         else if(selezione=="BANCA" || selezione=="Banca" || selezione=="banca"){
                                if(portafoglio.get_contanti()>=49){
                                    interfaccia.scrivi("####            HAI ACQUISTATO UN BIGLIETTO PER BANCA             ####");
                                    denaro=portafoglio.get_contanti();
                                    biglietto=true;
                                    denaro-=49;
                                    portafoglio.set_contanti(denaro);//aggiornamento denaro

                            }

                            else{
                                    interfaccia.scrivi("non hai abbastanza soldi ");
                                }

                          }
                          else if(selezione=="ANNULLA" || selezione=="Annulla"||selezione=="annulla"){
                               interfaccia.scrivi("####            HAI DECISO DI ANNULLARE L'OPERAZIONE             ####");

                          }

                        FINE BIGLIETTERIA VECCHIA SENZA DIZIONARIO
                          */
            }

            else if(input=="no"||input=="NO"||input=="No"||input=="n"||input=="N" ||input=="nO")
            {
                interfaccia.scrivi("Hai deciso di non prenotare alcun biglietto");
                interfaccia.a_capo();

                //FACCIO UN FUORI CODA PER "SVUOTARE" LA CODA
                i=0;
                while(i<=casuale)
                {
                    i++;
                    c.fuoricoda();
                }
            }
            else
            {
                interfaccia.scrivi("non capisco.");
                interfaccia.a_capo();
            }
        }

    }

    else
    {
        interfaccia.scrivi("#################################################################################");
        interfaccia.scrivi("#################################################################################");
        interfaccia.scrivi("#### non puoi accedere alla biglietteria perche' non hai soldi con cui pagare ###");
        interfaccia.scrivi("#### per accedere alla biglietteria serve avere: -un portafoglio              ###");
        interfaccia.scrivi("####                    grazie e arrivederci                                  ###");
        interfaccia.scrivi("#################################################################################");
        interfaccia.scrivi("#################################################################################");

    }
}

void Astro::azione_116()
{
    interfaccia.scrivi("####   Il giornale e' troppo frammentato, non riesco a leggere    ####");
}

void Astro::azione_117()
{
    if(biglietto==true)
    {
        interfaccia.scrivi("Din, don, siamo spiacenti di informare la clientela che a seguito di un guasto il treno per");
        interfaccia.scrivi("Aula, Ristorante, Stadio, Banca, non potra' partire, ci scusiamo per il disagio, grazie e arrivederci.");
        interfaccia.a_capo();
    }
    else if(biglietto==false)
    {
        interfaccia.scrivi("Per salire sul treno e' necessario acquistare un biglietto");
        interfaccia.a_capo();

    };
}
//FINE modifiche SALVATORE VESTITA -- Palagiano Marcello: modifica codice luogo da 41 a 49
void Astro::azione_118()   // Azione relativa al teletrasporto verso e dall'astronave aliena, gestita rispetto al luogo_attuale
{
    if (luogo_attuale == 11)    //se si è sulla poppa e si utilizza la pietra canalizzatrice, si arriva all'astronave aliena
    {
        interfaccia.scrivi("Ti senti leggero...");
        interfaccia.scrivi("E, senza che neanche tu te ne accorga, stai fluttuando verso un oggetto non identificato.");
        interfaccia.scrivi("Utilizzando la pietra canalizzatrice, sei stato teletrasportato verso un'astronave aliena.");
        storia_gioco.insStoria(stringa_comando, "utilizzando la pietra canalizzatrice, sei stato teletrasportato verso un'astronave aliena.");
        //luogo_attuale = 41;
    }
    else if (luogo_attuale == 49)   //se si utilizza il teletrasporto nell'astronave aliena, si torna sull'astronave
    {
        interfaccia.scrivi("Stai tornando sull'astronave, pronto a riprendere la tua avventura.");
        storia_gioco.insStoria(stringa_comando, "sei tornato sulla Neutronia azionando il teletrasporto della nave aliena.");
        //luogo_attuale = 11;
    }
    trasporto(luogo_attuale);
}

void Astro::azione_119()     //Azione puramente descrittiva, che spinge il giocatore ad uscire all'esterno per utilizzare la pietra canalizzatrice.
{
    interfaccia.scrivi("Senti un richiamo lontano, proveniente dall'esterno dell'astronave...");
}

void Astro::azione_120() //usa panca
{
    interfaccia.scrivi("Quante ripetizioni vuoi fare ?");
    int rip;
    string risp;
    getline(cin, risp);
    stringstream(risp) >> rip;
    Palestra::usaPanca(sFisico, rip);
}

void Astro::azione_121() // usa tapis
{
    interfaccia.scrivi("Per quanti minuti vuoi correre ?");
    int rip;
    string risp;
    getline(cin, risp);
    stringstream(risp) >> rip;
    Palestra::usaTapis(sFisico, rip);
}

void Astro::azione_122() //usa/guarda terminale
{
    Palestra::usaTerminale();
}

void Astro::azione_123()
{
    Palestra::usaSchede(sFisico);
}

void Astro::azione_124()
{
    int codiceinserito;
    float soldi = 0;
    Prodotto p1("Barretta Proteica", 2, 10,rand()%10);
    Prodotto p2("Acqua", 1, 11,rand()%10);
    Prodotto p3("Powerade", 2, 12, rand()%10);
    Prodotto p4("Succo di frutta",1, 13, rand()%10);

    Dizionario<int, Prodotto> Macchinetta;
    Macchinetta.inserisci(p1.getCodice(),p1);
    Macchinetta.inserisci(p2.getCodice(),p2);
    Macchinetta.inserisci(p3.getCodice(),p3);
    Macchinetta.inserisci(p4.getCodice(),p4);
    cout << "\n\n\n";
    interfaccia.scrivi("########################################################");//messaggio di output per la macchinetta
    interfaccia.scrivi("########################################################");
    interfaccia.scrivi("####                 Food&Drink                     ####");
    interfaccia.scrivi("####             Cosa desidera acquistare?          ####");
    interfaccia.scrivi("####         Inserisci il codice del prodotto:      ####");
    interfaccia.scrivi("####       - 10: Barretta Proteica        (costo=2) ####");
    interfaccia.scrivi("####       - 11:  Acqua                   (costo=1) ####");
    interfaccia.scrivi("####       - 12: Powerade                 (costo=2) ####");
    interfaccia.scrivi("####       - 13: Succo di Frutta          (costo=1) ####");
    interfaccia.scrivi("####       - 0: (PER USCIRE)                        ####");
    interfaccia.scrivi("########################################################");
    interfaccia.scrivi("########################################################");
    interfaccia.a_capo();
    cin >> codiceinserito;
    if (codiceinserito == 0 )
    {
        interfaccia.scrivi("Nessun prodotto acquistato arrivederci \n");
    }
    else
    {
        if(Macchinetta.appartiene(codiceinserito))
        {
            cout << "Codice valido \n";
            if (Macchinetta.recupera(codiceinserito).getQuantita() > 0)
            {
                cout << "Prodotto disponibile!";
                if (portafoglio.get_contanti() >= Macchinetta.recupera(codiceinserito).getCosto())
                {
                    cout << "Hai acquistato il prodotto:" << Macchinetta.recupera(codiceinserito).getNome() << "\n";
                    soldi = portafoglio.get_contanti();
                    soldi -= Macchinetta.recupera(codiceinserito).getCosto();
                    portafoglio.set_contanti(soldi);
                }
                else
                {
                    interfaccia.a_capo();
                    interfaccia.scrivi("Non hai abbastanza soldi per comprare il prodotto selezionato");
                }

            }
            else
            {
                interfaccia.a_capo();
                interfaccia.scrivi("Prodotto esaurito, il gestore sta provvedendo a caricare il prodotto \n");

            }


        }
        else
        {
            interfaccia.scrivi("Codice non valido \n");
        }

    }
}

void Astro::azione_125()
{
    string risposta;
    string continua;
    int numeroEstratto;
    bool sentinella = true;
    int indiceDisponibilita;
    bool disponibilita5 = false;
    bool disponibilita10 = false;
    bool disponibilita20 = false;
    bool disponibilita50 = false;
    bool disponibilita100 = false;
    string giocare;
    interfaccia.scrivi("Benvenuto alla slotmachine!");
    interfaccia.scrivi("Puoi vincere questi premi:");
    indiceDisponibilita = 1;
    while(indiceDisponibilita<=16 && !disponibilita5)
    {
        if(slotmachine.appartiene(indiceDisponibilita))
            disponibilita5 = true;
        indiceDisponibilita++;
    }
    indiceDisponibilita = 17;
    while(indiceDisponibilita<=24 && !disponibilita10)
    {
        if(slotmachine.appartiene(indiceDisponibilita))
            disponibilita10 = true;
        indiceDisponibilita++;
    }
    indiceDisponibilita = 25;
    while(indiceDisponibilita<=28 && !disponibilita20)
    {
        if(slotmachine.appartiene(indiceDisponibilita))
            disponibilita20 = true;
        indiceDisponibilita++;
    }
    indiceDisponibilita = 29;
    while(indiceDisponibilita<=30 && !disponibilita50)
    {
        if(slotmachine.appartiene(indiceDisponibilita))
            disponibilita50 = true;
        indiceDisponibilita++;
    }
    indiceDisponibilita = 31;
    while(indiceDisponibilita<=31 && !disponibilita100)
    {
        if(slotmachine.appartiene(indiceDisponibilita))
            disponibilita100 = true;
        indiceDisponibilita++;
    }
    cout<<" 5 euro: ";
    disponibilita5 ? cout<<"DISPONIBILE"<<endl : cout<<"ESAURITO"<<endl;
    cout<<" 10 euro: ";
    disponibilita10 ? cout<<"DISPONIBILE"<<endl : cout<<"ESAURITO"<<endl;
    cout<<" 20 euro: ";
    disponibilita20 ? cout<<"DISPONIBILE"<<endl : cout<<"ESAURITO"<<endl;
    cout<<" 50 euro: ";
    disponibilita50 ? cout<<"DISPONIBILE"<<endl : cout<<"ESAURITO"<<endl;
    cout<<"100 euro: ";
    disponibilita100 ? cout<<"DISPONIBILE"<<endl : cout<<"ESAURITO"<<endl;
    interfaccia.scrivi("Cosa desideri fare?");
    interfaccia.scrivi("");
    interfaccia.scrivi("1. Gioca (spenderai 1 Euro)");
    interfaccia.scrivi("2. Esci");
    cin>>risposta;
    bool nonvalido=false;
    while(sentinella && nonvalido==false)
    {
        fflush(stdin);
        if(risposta == "gioca" || risposta == "Gioca" || risposta == "g" || risposta == "G" || risposta == "1")
        {
            //moneta
            //cout<<"soldi"<<portafoglio.get_contanti();
            if(portafoglio.get_contanti()>0)
            {
                float soldi=portafoglio.get_contanti()-1.00;
                portafoglio.set_contanti(soldi);

                cout<<"soldi attuali= "<<portafoglio.get_contanti();
                srand((unsigned)time(NULL));
                numeroEstratto = (rand() % 100) +1;
                if(numeroEstratto>=1 && numeroEstratto<=31)
                {
                    interfaccia.scrivi("");
                    if(numeroEstratto>=1 && numeroEstratto<=16 && disponibilita5)
                    {
                        interfaccia.scrivi("Congratulazioni! Hai vinto 5 euro!");
                        soldi=portafoglio.get_contanti()+5.00;
                        portafoglio.set_contanti(soldi);
                        oggetti.set_luogo(31+numeroEstratto,0);
                        slotmachine.cancella(numeroEstratto);
                    }
                    else if(numeroEstratto>=17 && numeroEstratto<=24 && disponibilita10)
                    {
                        interfaccia.scrivi("Congratulazioni! Hai vinto 10 euro!");
                        soldi=portafoglio.get_contanti()+10.00;
                        portafoglio.set_contanti(soldi);
                        oggetti.set_luogo(31+numeroEstratto,0);
                        slotmachine.cancella(numeroEstratto);
                    }
                    else if(numeroEstratto>=25 && numeroEstratto<=28 && disponibilita20)
                    {
                        interfaccia.scrivi("Congratulazioni! Hai vinto 20 euro!");
                        soldi=portafoglio.get_contanti()+20.00;
                        portafoglio.set_contanti(soldi);
                        oggetti.set_luogo(31+numeroEstratto,0);
                        slotmachine.cancella(numeroEstratto);
                    }
                    else if(numeroEstratto>=29 && numeroEstratto<=30 && disponibilita50)
                    {
                        interfaccia.scrivi("Congratulazioni! Hai vinto 50 euro!");
                        soldi=portafoglio.get_contanti()+50.00;
                        portafoglio.set_contanti(soldi);
                        oggetti.set_luogo(31+numeroEstratto,0);
                        slotmachine.cancella(numeroEstratto);
                    }
                    else if(numeroEstratto>=31 && numeroEstratto<=31 && disponibilita100)
                    {
                        interfaccia.scrivi("Congratulazioni! Hai vinto 100 euro!");
                        soldi=portafoglio.get_contanti()+100.00;
                        portafoglio.set_contanti(soldi);
                        oggetti.set_luogo(31+numeroEstratto,0);
                        slotmachine.cancella(numeroEstratto);
                    }
                    else //nel caso in cui il numero 􀳦 buono ma non c'􀳦 pi􀳦 disponibilita'
                    {
                        interfaccia.scrivi("Non hai vinto.");
                        interfaccia.scrivi("Ritenta, sarai piu' fortunato!");
                    }
                }
                else
                {
                    interfaccia.scrivi("");
                    interfaccia.scrivi("Non hai vinto.");
                    interfaccia.scrivi("Andra' meglio la prossima volta!");
                }
                interfaccia.scrivi("");
                interfaccia.scrivi("Vuoi giocare ancora?");
                interfaccia.scrivi("1. Si");
                interfaccia.scrivi("2. No");
                cin >> continua;
                if (continua == "1" || continua == "Si" || continua == "si" || continua == "SI" || continua == "s" || continua == "S")
                {
                    risposta="gioca";
                }
                else
                {
                    if (continua == "2" || continua == "No" || continua == "no" || continua == "NO" || continua == "n" || continua == "N")
                    {
                        risposta="esci";
                    }
                    else
                    {
                        nonvalido=true;
                        interfaccia.scrivi("Comando non valido!");
                    }
                }
            }
            else
            {
                cout<<"Mi dispiace, non hai soldi sufficienti. Soldi = 0.";
                sentinella=false;
            }
        }
        else if(risposta == "esci" || risposta == "Esci" || risposta == "e" || risposta == "E" || risposta == "2")
        {
            interfaccia.scrivi("");
            interfaccia.scrivi("Arrivederci!");
            sentinella = false;
        }
        else
            nonvalido=true;
        interfaccia.scrivi("Comando non valido!");
    }

}

//inizio modifiche biblioteca Scatigna -- Palagiano Marcello: modifica codice luogo da 37 a 36 (biblioteca), da 38 a 37 (vetrina)

void Astro::azione_126()
{
    interfaccia.scrivi("\n  ---- REGOLAMENTO ------");
    interfaccia.scrivi("\n\n1) E' possibile prendere un libro in "
                       "\nprestito e restituirlo entro e non oltre 3 ore");
    interfaccia.scrivi("\n2) La restituzione e' valida solo se i libri "
                       "\nvengono lasciati al posto originario.");
    interfaccia.scrivi("\n3) Si consiglia di non  lasciare i libri sparsi"
                       "\nin biblioteca");
    interfaccia.scrivi("\n4) Si prega infine di fare silenzio!");
    interfaccia.scrivi("\n\nSaluti dal Bibliotecario... \n");
}
void Astro::azione_127()
{
    interfaccia.scrivi("la vetrina e' aperta!\n");
    luogo_attuale = 37;

}

void Astro::azione_128()
{
    interfaccia.scrivi("la vetrina e' chiusa!\n");
    luogo_attuale = 36;
}

void Astro::azione_129()
{
    if (oggetti.get_oggetto(og).get_luogo() == 0)   //SE E' TRASPORTATO
    {
        cout << "leggo: " << og;
        libro();

    }
    else
        interfaccia.scrivi("- Non ce l'hai.\n");
}

//fine modifica biblioteca Scatigna

//INIZIO modifiche PALAGIANO MARCELLO
void Astro::azione_130() //guarda banco da lavoro
{
    interfaccia.scrivi("vedo un banco da lavoro con alcuni appunti e progetti");
}

void Astro::azione_131() //esamina ricambio astronave
{
    interfaccia.scrivi("Vedo un pezzo di ricambio per l'astronave... Purtroppo e' rotto!");
}

void Astro::azione_132() //guarda pila di batterie
{
    if (oggetti.get_oggetto(117).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'autobus");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'autobus.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else if(oggetti.get_oggetto(119).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'automobile");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'automobile.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }

    else
    {
        string risposta;
        while(!batterie.pilavuota())
        {
            batteria = batterie.leggipila();
            cout<<"La batteria " <<batteria.get_modello() <<" ha una carica del " <<batteria.get_stato() <<"%" <<"\n\n";
            if(batteria.get_stato() < 50)
            {
                cout<<"La carica della batteria " <<batteria.get_modello() <<" non e' sufficiente." <<" Vuoi scartare la batteria? ";
                cin>>risposta;
                cout<<"\n";
                if((risposta=="s") || (risposta=="si"))
                {
                    batterie_scariche.inpila(batteria);
                    batterie.fuoripila();
                    immetti += 1;
                    if (immetti == 1)
                    {
                        oggetti.inserisci(Oggetto("delle batterie scariche", 16, -41, 0));
                        azioni.inserisci(4100100016, 133); //guarda batterie scariche
                    }
                }
                else
                {
                    batterie_appoggio.inpila(batteria);
                    batterie.fuoripila();
                }
            }
            else
            {
                batterie_appoggio.inpila(batteria);
                batterie.fuoripila();
            }
        }
        //Ripristina la pila originaria, con le batterie che non sono state scartate
        while(!batterie_appoggio.pilavuota())
        {
            batteria = batterie_appoggio.leggipila();
            batterie.inpila(batteria);
            batterie_appoggio.fuoripila();
        }
    }
}

void Astro::azione_133() //guarda batterie scariche
{
    cout << "Qui ci sono le batterie scariche che hai scartato dalla pila!\n";
    while(!batterie_scariche.pilavuota())
    {
        cout << "\n- Modello: " << batterie_scariche.leggipila().get_modello() << " - Carica: " << batterie_scariche.leggipila().get_stato() << "%";
        batterie_appoggio.inpila(batterie_scariche.leggipila());
        batterie_scariche.fuoripila();
    }
    cout << "\n\n";
    while(!batterie_appoggio.pilavuota()) //ripristino pila batterie originale
    {
        batterie_scariche.inpila(batterie_appoggio.leggipila());
        batterie_appoggio.fuoripila();
    }
}



void Astro::azione_134() //guarda chiave_inglese
{
    interfaccia.scrivi("Questa chiave ha una forma molto particolare.\nAprira' qualcosa? O sara' solo un attrezzo meccanico?\n");
}
void Astro::azione_135() //guarda diario
{
    interfaccia.scrivi("Sembra un diario delle attivita'. Magari potrebbe essere utile leggerlo!");
}
void Astro::azione_136() //leggi diario
{
    if (oggetti.get_oggetto(117).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'autobus");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'autobus.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else if(oggetti.get_oggetto(119).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'automobile");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'automobile.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else
    {

        bool continua = true;
        string ris;
        attivitaSelezionata = elenco.primolista();
        while( (!elenco.finelista(attivitaSelezionata)) && (continua))
        {
            cout<<"Autore: " <<elenco.leggilista(attivitaSelezionata).get_autore() <<"\n";
            cout<<"\t" <<elenco.leggilista(attivitaSelezionata).get_descrizione() <<"\n";
            cout<<"Data: " <<elenco.leggilista(attivitaSelezionata).get_data() <<"\n\n";
            cout<<"Vuoi andare AVANTI o INDIETRO? ";
            cin>>ris;
            cout<<"\n\n";
            if((ris=="avanti") || (ris =="avant") || (ris=="avan") || (ris == "ava") || (ris == "av") || (ris == "a"))
            {
                attivitaSelezionata = elenco.succlista(attivitaSelezionata);
                if(elenco.finelista(attivitaSelezionata))
                {
                    cout << "Diario Finito!\n";
                }
            }
            else if ((ris=="indietro") || (ris =="indietr") || (ris=="indiet") || (ris == "indie") || (ris == "indi") || (ris ==
                     "ind") || (ris == "in") || (ris == "i"))
            {
                if(attivitaSelezionata != elenco.primolista())
                {
                    attivitaSelezionata = elenco.preclista(attivitaSelezionata);
                }
                else
                {
                    continua = false;
                    cout<<"Ho chiuso il diario\n\n";
                }
            }
            else
            {
                cout<<"Ho chiuso il diario\n\n";
                continua = false;
            }
        }
    }
}
void Astro::azione_137() //guarda cartello
{
    cout<<"**************************************************************************\n";
    cout<<"* OFFICINA. Per qualsiasi richiesta rivolgersi al personale autorizzato! *\n";
    cout<<"**************************************************************************\n";
}
void Astro::azione_138() //guarda computer
{

    if (oggetti.get_oggetto(117).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'autobus");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'autobus.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else if(oggetti.get_oggetto(119).get_luogo() == 0)
    {
        interfaccia.scrivi("Devi prima lasciare l'automobile");
        stringa_risposta = "Ti e' stato detto di lasciare prima l'automobile.";
        storia_gioco.insStoria(stringa_comando, stringa_risposta);
    }
    else
    {
        int r, i = 5, num=0;
        string nome;
        do
        {
            cout<<"\nIl computer e' acceso. Cosa vuoi fare?\n";
            cout<<"(1) Gestisci prenotazioni\n";
            cout<<"(2) Visualizza persone in attesa\n";
            cout<<"(3) Prenotati\n";
            cout<<"(4) Spegni PC\n\n";
            cin>>r;
            cout<<"\n";

            if (!cin)
            {
                cin.clear();
                cin.ignore(256,'\n');
                //system("clear"); //linux os
                interfaccia.scrivi("Input errato");
                fflush(stdin);
            }
            else
            {
                switch(r)
                {
                case 1:
                    cout<<"Non puoi accedere a questa sezione! Le prenotazioni possono essere gestite solo dal capo officina.\n";
                    break;
                case 2:
                    cout<<"In ordine di arrivo, ci sono le seguenti persone in attesa:\n";
                    i = 1;
                    while(!coda_attesa.codavuota())
                    {
                        cout<<i <<". " <<coda_attesa.leggicoda().getNome() <<"\n";
                        codaa_appoggio.incoda(coda_attesa.leggicoda());
                        coda_attesa.fuoricoda();
                        i++;
                    }
                    while(!codaa_appoggio.codavuota())
                    {
                        coda_attesa.incoda(codaa_appoggio.leggicoda());
                        codaa_appoggio.fuoricoda();
                    };
                    break;
                case 3:
                    cout<<"Inserisci il tuo nome: ";
                    cin>>nome;
                    cliente.setNome(nome);
                    coda_attesa.incoda(cliente);
                    num=0;
                    while(!coda_attesa.codavuota())
                    {
                        codaa_appoggio.incoda(coda_attesa.leggicoda());
                        coda_attesa.fuoricoda();
                        num++;
                    }
                    while(!codaa_appoggio.codavuota())
                    {
                        coda_attesa.incoda(codaa_appoggio.leggicoda());
                        codaa_appoggio.fuoricoda();
                    };
                    cout<<"\nPrenotazione effettuata.\nSei il numero " <<num <<"\n";
                    break;
                case 4:
                    cout<<"Spengo il PC.\n\n";
                    break;
                }
            }
        }
        while(r != 4);
    }
}

void Astro::azione_139() //parla meccanico
{
    if(!batteria_cambiata)
    {
        interfaccia.scrivi("Salve! Sono il meccanico");

        if (oggetti.get_oggetto(119).get_luogo() != 41 && oggetti.get_oggetto(119).get_luogo() != 0)  //se non c'è l'automobile
        {
            interfaccia.scrivi("Per cambiare la batteria dell'automobile devi portarla qui.");
            stringa_risposta = "ti e' stato detto di venire con l'automobile.";
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }

        else
        {

            string risp;
            do
            {

                risp = interfaccia.leggi_stringa("Vuoi cambiare la batteria dell'automobile? Ci vorra' del tempo pero' [Si/No]");

            }
            while(risp != "Si" && risp != "No" && risp != "s" && risp != "n" &&
                    risp != "si" && risp != "no");

            if(risp == "Si" || risp == "s" || risp == "si")
            {
                string risposta;
                batteria_cambiata = true; //La batteria è stata cambiata

                interfaccia.scrivi("Batteria cambiata! Ci vediamo!");
                tempo = tempo - 20;
                interfaccia.scrivi("*** Il tuo tempo e' stato decrementato di 20 punti ***");

            }
            else
                interfaccia.scrivi("Ok, sono qui se hai bisogno!");
        }
    }
    else
        interfaccia.scrivi("Hai gia' cambiato la batteria dell'automobile!");

}
//FINE integrazione PALAGIANO MARCELLO




//_Modifiche_Matteo_Luceri
void Astro::azione_140()         //Azione guarda valigia
{
    interfaccia.scrivi("E' la valigia del secondo pilota.");
    interfaccia.scrivi("Sembra molto capiente.");
}

void Astro::azione_141()         //Azione guarda zaino
{
    interfaccia.scrivi("E' il tuo zaino.");
    interfaccia.scrivi("Puo' esserti utile per trasportare oggetti.");
}

void Astro::azione_142()         //Azione indossa/metti
{
    int codiceA = 0,codiceB = 0,codiceC = 0,codiceD = 0,codiceE = 0, codiceF = 0;
    codiceA = oggetti.get_oggetto_indice_by_codice(50); // 4 casco
    codiceB = oggetti.get_oggetto_indice_by_codice(51); // 11 tuta
    codiceC = oggetti.get_oggetto_indice_by_codice(52); // 23 camice
    codiceD = oggetti.get_oggetto_indice_by_codice(55); // 25 manuale
    codiceE = oggetti.get_oggetto_indice_by_codice(155); // 55 valigia
    codiceF = oggetti.get_oggetto_indice_by_codice(156); // 56 zaino

    if (oggetti.get_oggetto(og).get_luogo() == 0) // controllo che l'oggetto si trovi nell'inventario
        interfaccia.scrivi("- Gia' fatto.");
    else if (oggetti.get_oggetto(og).get_luogo() < 0) // controllo che l'oggetto non sia indossabile
        interfaccia.scrivi("- Non e' possibile.");
    else if (!indossa_specifiche())
    {
        if(oggetti.get_oggetto(codiceF).get_luogo() == 0)
        {
            if (oggetti.get_oggetto(codiceA).get_luogo() == 20 ||
                    oggetti.get_oggetto(codiceB).get_luogo() == 20 ||
                    oggetti.get_oggetto(codiceC).get_luogo() == 20)
            {
                if(og == codiceA || og == codiceB || og == codiceC)
                {
                    int c;
                    c=z.leggipila();
                    if(og == oggetti.get_zaino2(c))
                    {
                        // controllo che l'oggetto sia proprio il primo oggetto nello zaino
                        oggetti.set_luogo(og,0);
                        z.fuoripila();
                        n_oggettiZ--;
                        peso_MaxZ += oggetti.get_oggetto(og).get_peso();
                    }
                    else if(oggetti.get_oggetto(og).get_luogo() == luogo_attuale)
                    {
                        // controllo che l'oggetto si trovi nel luogo attuale
                        oggetti.set_luogo(og,0);
                    }
                    else
                    {
                        interfaccia.scrivi("Devi prima lasciare: ");
                        oggetti.get_zaino(c);
                    }
                }
                else
                {
                    oggetti.set_luogo(og,0);
                    interfaccia.scrivi("Fatto.");
                }
            }
            else
            {
                oggetti.set_luogo(og,0);
            }
        }
        else if(oggetti.get_oggetto(codiceE).get_luogo() == 0)
        {
            if (oggetti.get_oggetto(codiceA).get_luogo() == 20 || oggetti.get_oggetto(codiceB).get_luogo() == 20 || oggetti.get_oggetto(codiceC).get_luogo() == 20)
            {
                if(og == codiceA || og == codiceB || og == codiceC)
                {
                    int c;
                    c=og;
                    if(ins.appartiene(oggetti.get_valigia(c)))
                    {
                        // controllo che l'oggetto sia presente nella valigia
                        oggetti.set_luogo(og,0);
                        ins.cancella(oggetti.get_valigia(c));
                        n_oggettiZV--;
                        peso_MaxZV += oggetti.get_oggetto(og).get_peso();
                    }
                    else if(!ins.appartiene(oggetti.get_valigia(c)))
                        //controllo che l'oggetto non sia presente nella valigia
                        interfaccia.scrivi("- Non ce l'hai in valigia.");
                    else if(oggetti.get_oggetto(og).get_luogo() == luogo_attuale)
                    {
                        //controllo che l'oggetto si trovi nel luogo attuale
                        oggetti.set_luogo(og,0);
                    }
                }
                else
                {
                    oggetti.set_luogo(og,0);
                    interfaccia.scrivi("Fatto.");
                }
            }
            else
            {
                oggetti.set_luogo(og,0); // linea 35 oggetti.cpp
            }
        }
        else
        {
            if(og != 0 && oggetti.get_oggetto(og).get_luogo() != 20)
            {
                // controllo che l'oggetto non si trovi in un altro luogo e
                // che l'oggetto non si trovi nello zaino o nella valigia
                oggetti.set_luogo(og,0);
            }
            else
                interfaccia.scrivi("- Sta nello zaino o nella valigia, e non li hai.");
        }
        if (!indosso_specifiche())  // faccio alcuni controlli in indosso_specifiche
        {
            if(oggetti.get_oggetto(og).get_luogo() == 0)
                //controllo che l'oggetto si trovi nell'inventario
                interfaccia.scrivi("Fatto.");
        }
    }
}


void Astro::azione_143()         //Azione inventario valigia
{

    if(oggetti.get_oggetto(143).get_luogo() == 0)
    {
        if(oggetti.get_oggetto(143).get_luogo() == 0)
        {
            if (!ins.insiemevuoto())
            {
                interfaccia.scrivi("Inventario Valigia");
                interfaccia.scrivi("\nVedo: ");
                if(ins.appartiene(50)) // controllo che il casco sia presente nella valigia
                    oggetti.get_zaino(50);
                if(ins.appartiene(51)) // controllo che la tua sia presente nella valigia
                    oggetti.get_zaino(51);
                if(ins.appartiene(52)) // controllo che il camice sia presente nella valigia
                    oggetti.get_zaino(52);
                if(ins.appartiene(55)) // controllo che il manuale sia presente nella valigia
                    oggetti.get_zaino(55);
                cout << "\nTotale Oggetti nella Valigia: " << n_oggettiZV << endl;
                cout << "Spazio disponibile: "<< peso_MaxZV << " su 8 kg."<< endl;
            }
            else
                interfaccia.scrivi("E' vuota.");
        }
        else
            interfaccia.scrivi("Non ce l'hai.");
    }
}

void Astro::azione_144()         //Azione inventario zaino
{

    if(oggetti.get_oggetto(144).get_luogo() == 0)
    {
        // controllo che l'oggetto zaino si trovi nell'inventario
        if (!z.pilavuota())   // controllo che l'oggetto zaino non sia vuoto //*
        {
            interfaccia.scrivi("Inventario Zaino");
            interfaccia.scrivi("\nVedo in cima: ");
            int c;
            c=z.leggipila(); //*
            oggetti.get_zaino(c);
            cout << "\nTotale Oggetti nello Zaino: " << n_oggettiZ << endl;
            cout << "Spazio disponibile: "<< peso_MaxZ << " su 5 kg."<< endl;
        }
        else
            interfaccia.scrivi("E' vuoto.");
    }
    else
        interfaccia.scrivi("Non lo hai.");
}


void Astro::azione_145()         //Azione aiuto/help
{
    interfaccia.scrivi("\nCOMANDI DI GIOCO:");
    interfaccia.scrivi("\nDirezioni: ");
    interfaccia.scrivi("- n/nord: per muoverti in avanti;");
    interfaccia.scrivi("- s/sud: per muoverti indietro;");
    interfaccia.scrivi("- e/est: per muoverti a destra;");
    interfaccia.scrivi("- w/o/ovest: per muoverti a sinistra;");
    interfaccia.scrivi("- a/alto/sali: per salire ad un piano superiore;");
    interfaccia.scrivi("- b/basso/scendi: per scendere ad un piano inferiore;");
    interfaccia.scrivi("\nAzioni: ");
    interfaccia.scrivi("- prendi/raccogli: per trasportare un oggetto in mano o con se(zaino/valigia);");
    interfaccia.scrivi("- indossa/metti: per indossare un oggetto(es. casco);");
    interfaccia.scrivi("- guarda: per guardare ed ottenere informazioni su un oggetto (es.tuta);");
    interfaccia.scrivi("- lascia/togli/leva: per lasciare o togliersi gli oggetti trasportati;");
    interfaccia.scrivi("- apri: per aprire un oggetto fisso(es. armadietto);");
    interfaccia.scrivi("- leggi: per leggere una scritta(es.cartello);");
    interfaccia.scrivi("- spingi/tira: per spingere o tirare un oggetto fisso(es.leva);");
    interfaccia.scrivi("- premi/schiaccia: per premere un oggetto fisso(es.pulsante);");
    interfaccia.scrivi("- inventario/cosa: per accedere all'inventario degli oggetti trasportati;");
    interfaccia.scrivi("- zaino: per accedere agli oggetti trasportati nello zaino;");
    interfaccia.scrivi("- valigia: per accedere agli oggetti trasportati nella valigia;");
    interfaccia.scrivi("- save/load: per salvare o caricare la partita;");
    interfaccia.scrivi("- mappa/navigatore: per avviare il navigatore SIMUNAV;\n\n");
}



//Fine_modifiche_ML


/* Esegue azione a
 SPOSTATO DOPO AZIONI PER VISIBILITA'
 */
bool Astro::esegui_specifiche(int a, Mappa &M)
{
    bool eseguito = true;
    switch (a)
    {
    case 10:
        azione_10();
        break;
    case 11:
        azione_11();
        break;
    case 12:
        azione_12();
        break;
    case 13:
        azione_13();
        break;
    case 14:
        azione_14();
        break;
    case 15:
        azione_15();
        break;
    case 16:
        azione_16();
        break;
    case 17:
        azione_17();
        break;
    case 18:
        azione_18();
        break;
    case 19:
        azione_19();
        break;
    case 20:
        azione_20();
        break;
    case 21:
        azione_21();
        break;
    case 22:
        azione_22();
        break;
    case 23:
        azione_23();
        break;
    case 24:
        azione_24();
        break;
    case 25:
        azione_25();
        break;
    case 26:
        azione_26();
        break;
    case 27:
        azione_27();
        break;
    case 28:
        azione_28();
        break;
    case 29:
        azione_29();
        break;
    case 30:
        azione_30();
        break;
    case 31:
        azione_31();
        break;
    case 32:
        azione_32();
        break;
    case 33:
        azione_33();
        break;
    case 34:
        azione_34();
        break;
    case 35:
        azione_35();
        break;
    case 36:
        azione_36();
        break;
    case 37:
        azione_37(M);
        break;
    case 38:
        azione_38(M);
        break;
    //START DAMONE
    // Modifica De Giorgio , richiama la rubrica
    /*case 77:
            cerca();
            break;*/
    //Fine Modifica De Giorgio
    //END MARCO DAMONE


    //Modifica PMF(ufficio)
    case 44:
        azione_44();
        break;
    case 45:
        azione_45();
        break;
    case 46:
        azione_46();
        break;
    case 47:
        azione_47();
        break;
    //Modifica PMF: fin qui.

    case 50:
        azione_50();
        break;
    //MODIFICHE D-R(D'orsi):Negozio + Banca
    case 51:
        azione_51();
        break;
    case 52:
        azione_52();
        break;
    case 53:
        azione_53();
        break;
    case 54:
        azione_54();
        break;
    case 55:
        azione_55();
        break;
    case 56:
        azione_56();
        break;
    case 57:
        azione_57();
        break;
    case 58:
        azione_58();
        break;
    case 59:
        azione_59();
        break;
    case 60:
        azione_60();
        break;
    case 61:
        azione_61();
        break;

    // MODIFICA D-R(Colturi):Luoghi a Pagamento
    case 62:
        azione_62(M, 26);
        break;

    case 63:
        azione_62(M, 27);
        break;

    case 64:
        azione_62(M, 28);
        break;

    case 65:
        azione_63(M);
        break;
    //MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
    case 66:
        azione_66();
        break;
    //INIZIO MODIFICHE MICHELE ALBANO
    case 67:
        azione_67();
        break;
    //FINE MODIFICHE MICHELE ALBANO

    //modifiche Francesco Cosma - Premi

    case 68:
        azione_68();
        break;
    //INIZIO MODIFICHE MICHELE ALBANO
    case 69:
        azione_69();
        break;
    //FINE MODIFICHE MICHELE ALBANO

    //INIZIO MODIFICHE GIOVANNI CASTELLANA
    case 70:
        azione_70();
        break;

    case 71:
        azione_71();
        break;

    case 72:
        azione_72();
        break;

    case 73:
        azione_73();
        break;

    case 74:
        azione_74();
        break;
    //FINE MODIFICHE GIOVANNI CASTELLANA

    //MODIFICHE GIANMARCO GALLONE, NUOVI METODI

    case 75:
        azione_75();
        break;
    case 76:
        azione_76();
        break;

    case 77:
        azione_77();
        break;
    case 78:
        azione_78();
        break;

    case 79:
        azione_79();
        break;
    // FINE MODIFICHE GALLONE

    case 80:
        azione_80(); //Modifica DELLA FOLGORE GRAZIA - Guarda bagagliaio
        break;

    //Inizio modifiche Galeandro da progetto Bellanova
    case 82 :
        azione_82 ( ) ;
        break;
    case 83 :
        azione_83 ( ) ;
        break;
    case 84 :
        azione_84 ( ) ;
        break;
    //Fine modifiche Galeandro da progetto Bellanova

    //INIZIO modifiche Moschetti
    case 85 :
        azione_85 ( ) ;
        break ;
    case 86 :
        azione_86 ( ) ;
        break ;
    case 87 :
        azione_87 ( ) ;
        break ;
    case 88 :
        azione_88 ( ) ;
        break ;
    case 89 :
        azione_89 ( ) ;
        break ;
    case 90 :
        azione_90 ( ) ;
        break ;
    //FINE modifiche Moschetti

    //INIZIO MODIFICHE DEL GIUDICE ANGELO
    case 91:
        azione_91();
        break;
    case 92:
        azione_92();
        break;
    case 93:
        azione_93();
        break;
    case 94:
        azione_94();
        break;
    case 95:
        azione_95();
        break;
    case 96:
        azione_96();
        break;
    //FINE MODIFICHE DEL GIUDICE ANGELO

    //INIZIO MODIFICHE BASILE ANTONIO
    case 97:
        azione_97();
        break;
    case 98:
        azione_98();
        break;
    case 100:
        azione_100();
        break;
    case 101:
        azione_101();
        break;
    case 102:
        azione_102();
        break;
    case 103:
        azione_103();
        break;
    case 104:
        azione_104();
        break;
    //FINE MODIFICHE BASILE ANTONIO

    //INIZIO MODIFICHE VACCA GIANLUCA
    //Accendi proiettore Auditorium
    case 105:
        azione_105();
        break;

    //Guarda lo schermo nell'Auditorium
    case 106:
        azione_106();
        break;

    //Guarda la finestra nell'Auditorium
    case 107:
        azione_107();
        break;

    //Parla col microfono dell'Auditorium
    case 108:
        azione_108();
        break;


    //Utilizza il Jukebox presente nell'auditorium
    case 109:
        azione_109();
        break;

    //Osserva gli strumenti musicali presenti nell'auditorium
    case 110:
        azione_110();
        break;

    //Suona uno strumento musicale
    case 111:
        azione_111();
        break;

    //Interagisci col pannello delle luci nell'auditorium
    case 112:
        azione_112();
        break;

    //Guarda scacchiera
    case 113:
        azione_113();
        break;
    //FINE MODIFICHE VACCA GIANLUCA


    //INIZIO modifiche SALVATORE VESTITA
    case 114:
        azione_114();
        break;
    case 115:
        azione_115();
        break;
    case 116:
        azione_116();
        break;
    case 117:
        azione_117();
        break;
    case 118:
        azione_118();
        break;
    case 119:
        azione_119();
        break;
    //FINE modifiche SALVATORE VESTITA
    //INIZIO modifiche DAVIDE MANTELLINI
    case 120:
        azione_120();
        break;
    case 121:
        azione_121();
        break;
    case 122:
        azione_122();
        break;
    case 123:
        azione_123();
    case 124:
        azione_124();
        break;
    case 125:
        azione_125();
        break;
    //FINE modifiche DAVIDE MANTELLINI
    //INIZIO modifiche Gianluca Scatigna

    case 126:
        azione_126();
        break;
    case 127:
        azione_127();//CHIAMA AZIONE DI APERTURA VETRINA
        break;
    case 128:
        azione_128();//CHIAMA AZIONE DI CHIUSURA VETRINA
        break;
    case 129:
        azione_129();
        break;
    //FINE modifiche Gianluca Scatigna

    //INIZIO modifiche PALAGIANO MARCELLO
    case 130:
        azione_130();
        break;
    case 131:
        azione_131();
        break;
    case 132:
        azione_132();
        break;
    case 133:
        azione_133();
        break;
    case 134:
        azione_134();
        break;
    case 135:
        azione_135();
        break;
    case 136:
        azione_136();
        break;
    case 137:
        azione_137();
        break;
    case 138:
        azione_138();
        break;
    case 139:
        azione_139();
        break;
    //FINE modifiche PALAGIANO MARCELLO
    //Modifiche ML
    case 140:
        azione_140();
        break;

    case 141:
        azione_141();
        break;

    case 142:
        azione_142();
        break;

    case 143:
        azione_143();
        break;

    case 144:
        azione_144();
        break;

    case 145:
        azione_145();
        break;

    //fine modifiche
    default:
        eseguito = false;
    }
    return eseguito;
}
