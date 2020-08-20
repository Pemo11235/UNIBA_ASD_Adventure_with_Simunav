
//Modifica PMF(strutture)
//#include <Windows.h>

#include "ServizioInsieme.h"
#include <time.h>       //Modifica PMF
#include "Gioco.h"
#include "Pila.h"
#include "Bacheca.h"
#include "enigma.h"   //Modifica PMF(enigmi)
#include "risposta.h" //Modifica PMF(enigmi)
#include "Interfaccia.h" //Modifica Margherita Disabato
#include "ServizioPila.h"
#include "Oggetti.h"

#define completo true // costante per passare dalla modalità a stato completo a non completo

#include "Oggetto.h"

#include <windows.h>
#include <unistd.h> //libreria standard per sostituire Sleep(essendo prettamente di windows)
#include <cstdio> //libraria per sostituire il deletefile(essendo prettamente di windows)


string stringa_comando="";  //Modifica PMF(storia)
string stringa_risposta=""; //Modifica PMF(storia)

Gioco::Gioco()
{
    fStringa = "astro";

    //MODIFICHE D-R(D'Orsi):Negozio + Banca
    somma = 0.0f;
    k = 0;
    comando_oggetto = 0;
    caricafile();
    carica_trasporti();

    init_premi(); //Modifiche Francesco Cosma - Premi
}

void Gioco::caricafile()
{

    ifstream f("enigma.txt", ios::in);
    string buffer;
    int i;
    string estratto;
    n_enigmi = 0;

    while (!f.eof())
    {
        enigma e;
        risposta r;
        i = 0;
        getline(f, buffer);
        if (buffer.length() > 2)
        {
            estratto = estrai_f(buffer, i, ';');
            e.set_id(atoi(estratto.c_str()));

            estratto = estrai_f(buffer, i, ';');
            e.set_enigma(estratto);

            while (i < buffer.length()) //mi legge n risposte fino alla fine della riga
            {
                estratto = estrai_f(buffer, i, ';');
                r.set_risp(estratto);
                estratto = estrai_f(buffer, i, ';');
                r.set_esatto(atoi(estratto.c_str()));
                e.set_risposta(r);
            }
            n_enigmi++;
            Lista<enigma>::posizione posi = enigmi.primolista();

            while(!enigmi.finelista(posi))
            {
                posi = enigmi.succlista(posi);
            }

            enigmi.inslista(e,posi);
        }
    }
    f.close();

}
//START DAMONE
//Modifica De GIorgio
//Per la Guida
void Gioco::consulta()
{
    if(oggetti.get_oggetto(56).get_luogo() == 0)//controllo se il protagonista possiede la guida
    {
        if(abs(oggetti.get_oggetto(og).get_luogo()) == luogo_attuale || abs(oggetti.get_oggetto(og).get_luogo()) == 0)
            //controllo se l'oggetto che devo consultare si trova nel luogo attuale del protagonista oppure quest'ultimo ce l'ha addosso
        {
            interfaccia.scrivi(oggetti.get_oggetto(og).get_descrizione());
            interfaccia.scrivi("\n");
            //system("pause");
        }
        else
        {
            interfaccia.scrivi("L'oggetto da te cercato non e' presente in questo luogo!\n");
        }
    }
    else
    {
        interfaccia.scrivi("Non possiedi la guida!\n");
    }
}

//END DAMONE

bool Gioco::leggienigma()
{

    Lista<enigma>::posizione pos = enigmi.primolista();
    enigma e;
    int a;
    bool trovato = false;

    srand(time(0));
    a = (rand() % n_enigmi) + 1;

    while(!enigmi.finelista(pos) && !trovato)
    {
        algor = false; //Modifiche Francesco Cosma - Premi
        if (a == enigmi.leggilista(pos).get_id())
        {
            trovato = true;
            if(enigmi.leggilista(pos).get_id()==3)//Modifiche Francesco Cosma - Premi
                algor = true;	//Modifiche Francesco Cosma - Premi
        }
        else
            pos = enigmi.succlista(pos);
    }
    e = enigmi.leggilista(pos);
    cout << e.get_enigma() << endl;

    Lista<risposta>::posizione indice = e.get_risposta().primolista();
    int num_risp = 1; // era commentato
    cout << endl;
    cout << e.get_risposta().leggilista(e.get_risposta().primolista()).get_risp() << endl;
    /*while (!e.get_risposta().finelista(indice))
    {
        indice = e.get_risposta().succlista(indice);
        num_risp++; // era commentato

    } */
    bool trovato3 = false;
    char in_risp2[3]; //2
    int in_risp;

    while(!trovato3)
    {
        cout << "\nInserisci il numero della risposta esatta: ";
        cin >> in_risp2;

        if((in_risp2[0] >= 'a') || (in_risp2[1] >= '0'))
        {
            cout << "- Non capisco." << endl;
        }
        else
        {
            in_risp = in_risp2[0];
            in_risp -= 48;
            if (in_risp<=3)
            {
                trovato3 = true;
            }
        }

    }

    bool rsp=false;
    bool trovato2 = false;
    ris_esatta=false; //Modifiche Francesco Cosma - Premi
    num_risp = 1; //era con l'int
    while (num_risp!=in_risp)
    {
        num_risp++;
    }
    if (num_risp==1)
        rsp=e.get_risposta().leggilista(e.get_risposta().primolista()).get_esatto();
    else if (num_risp==2)
        rsp=e.get_risposta().leggilista(e.get_risposta().succlista(e.get_risposta().primolista())).get_esatto();
    else if (num_risp==3)
    {
        if (!e.get_risposta().finelista(e.get_risposta().succlista(e.get_risposta().succlista(e.get_risposta().primolista()))))
        {
            rsp=e.get_risposta().leggilista(e.get_risposta().succlista(e.get_risposta().succlista(e.get_risposta().primolista()))).get_esatto();
        }
    }
    if (rsp==true)
    {
        trovato2=true;
        ris_esatta=true;
    }
    /* while (!e.get_risposta().finelista(i) && !trovato2)
     {
         cout << e.get_risposta().leggilista(i).get_esatto();
         if ((in_risp == num_risp) && (e.get_risposta().leggilista(i).get_esatto() != false))
         {
             trovato2 = true;
             ris_esatta= true; //Modifiche Francesco Cosma - Premi
         }

         else
         {
             i = e.get_risposta().succlista(i);
             num_risp++;
         }
     } */
    return trovato2;


}


string Gioco::estrai_f(string s, int &i, char fine)
{
    string estratto = "";
    while (s[i] != fine && i < s.length())
    {
        estratto += s[i];
        i++;
    }
    i++;
    return (estratto);
}

Gioco::~Gioco() {}
/* 940 - 1080
	Init
*/
void Gioco::init_specifiche() {}

void Gioco::init()
{
    fine_partita = false;
    salito = false; // Vaira - Inizializzazione variabile
    interfaccia.scrivi("\nUn attimo di pazienza...\n");
    init_specifiche(); // caricamento dizionario, mappa, azioni, oggetti, variabili
}

/* 250 - 360
	Estrae pStringa da inStringa[in], trova codice c, salta art.
*/
int Gioco::estraipar(string inStringa, int li, int *pos_attuale, string *parola)
{
    int cod_parola; // posizione della parola nel dizionario
    int inizio_parola; // indice di inizio parola

    do
    {
        cod_parola = 0;
        while (inStringa[*pos_attuale] == ' ' || inStringa[*pos_attuale] == '\'')
            (*pos_attuale)++;
        if (*pos_attuale >= li)
            *parola = "";
        else
        {
            inizio_parola = *pos_attuale; // inizio
            while (inStringa[*pos_attuale] != ' ' && inStringa[*pos_attuale] != '\'' && (*pos_attuale) < li)
                (*pos_attuale)++;
            *parola = inStringa.substr(inizio_parola, *pos_attuale-inizio_parola);
            cod_parola = vocabolario.recupera(*parola); // cerca
        }
    }
    while (cod_parola == 7);
    return cod_parola;
}

// Fine interprete, inizio avventura

/* 1170 - 1360
	Morto
*/
void Gioco::epitaffio() {}
void Gioco::futuro() {}
void Gioco::passato() {}
bool Gioco::mappaaperta() {}
void Gioco::presente() {}

void Gioco::morto()
{
    string risposta;		 // scelta nuova partita
    string storia_completa;  //Modifica PMF(storia) RISPOSTA PER VISUALIZZARE LA STORIA COMPLETA
    interfaccia.pausa();	 // <SP>
    epitaffio();
    fine_partita = true;

    //Modifica PMF(storia)
    do
    {
        storia_completa = interfaccia.leggi_stringa("Vuoi visualizzare la storia della tua partita? (s/n)");
    }
    while  (storia_completa[0] != 's' && storia_completa[0] != 'n');
    if (storia_completa[0] == 's')
    {
        interfaccia.scrivi("\n**** PECCATO HAI PERSO...VEDIAMO DOVE HAI SBAGLIATO: ****\n");
        storia_gioco.stampaStoria();
        interfaccia.scrivi("\n\n              ...la prossima volta stai piu' attento e vedrai che non sbaglierai!");
    }
    //Modifica PMF: fin qui.

    do
    {
        risposta = interfaccia.leggi_stringa("Vuoi giocare ancora? ");
    }
    while (risposta[0] != 's' && risposta[0] != 'n');
    if (risposta[0] == 's')
        riparti = true; // run: riparte
    else
    {
        interfaccia.scrivi("\n\nArrivederci!\n");
        cin.clear();
        fflush(stdin);
        riparti = false; // end
    }
}

/* 1370 - 1500
	Tempo
*/
void Gioco::tempo_specifiche() {}

void Gioco::aggiorna_tempo()
{
    //Inizio modifica Gallone - Integrazione fatta alla funzione che mi permette di gestire il tempo anche in base alla
    // sazietà del personaggio
    srand(time(NULL));
    int x = rand()%4+1;
    if (sazio <= 120 && sazio >= 80)
    {
        tempo--;
        if (sazio <= 90 && sazio >= 80)
            interfaccia.scrivi("\nInizio a sentire un leggero languorino...");

    }
    else if (sazio <= 79 && sazio >= 50)
    {
        tempo =  tempo - 2;
        if (sazio <= 60 && sazio >= 50)
            interfaccia.scrivi("\nE' tutto il giorno che non mangio, dovrei fare una pausa...");

    }
    else if (sazio <= 49 && sazio >= 20)
    {
        tempo = tempo - 3;
        if (sazio <= 30 && sazio >= 20)
            interfaccia.scrivi("\nAccidenti, la fame aumenta. Mi servono energie, e subito!");

    }

    else if (sazio <= 19 && sazio >=0)
    {
        tempo = tempo - 4;
        if (sazio <= 10 && sazio >= 0)
            interfaccia.scrivi("\n...Non riesco a fare un altro passo... le forze mi abbandonano...");

    }
    sazio = sazio - x;

    //Fine Modifica Gallone

    if (salito == true)
    {
        tempo = tempo - 0.5;
        motorino.aggiorna_carburante();
        cout << "Tempo residuo: " << tempo << endl;
        cout << "Livello benzina: " << motorino.get_livello_benzina() << endl;
        if(motorino.get_livello_benzina() == 0)
        {
            salito = false;
            interfaccia.scrivi("Hai finito la benzina. Sei sceso dal motorino!!!");
        }
    }
    else
    {
        if(Salute.Ferito()==true) //Inizio modifica Michele Albano: se sei ferito, mostra un nuovo messaggio
        {
            cout << "Tempo residuo: " << tempo << endl;
            cout << "Tempo aggiuntivo dovuto allo Stato di Salute: " << Salute.GetPenalita();
        }
        else
            cout << "Tempo residuo: " << tempo;
        tempo = tempo - 1 - Salute.GetPenalita(); //Fine modifica Michele Albano
    }
    tempo_specifiche();
    if (tempo <= 0)
    {
        morto(); // QUI NON FUNZIONA SE SI RISPONDE NO AL RIGIOCARE!!!
        interfaccia.a_capo();
    }
    interfaccia.a_capo();

    float tempo_perso = 0; //Modifica DAVIDE MANTELLINI

    if (sazio <= 120 && sazio >= 80)
    {
        tempo_perso+= 1; //Modifica DAVIDE MANTELLINI
        if (sazio <= 90 && sazio >= 80)
            interfaccia.scrivi("\nInizio a sentire un leggero languo-rino...");
    }
    else if (sazio <= 79 && sazio >= 50)
    {
        tempo_perso+= 2; //Modifica DAVIDE MANTELLINI
        if (sazio <= 60 && sazio >= 50)
            interfaccia.scrivi("\nE' tutto il giorno che non mangio, do-vrei fare una pausa...");
    }
    if (Salute.GetStatoSalute() <= 40)
    {
        tempo -= Salute.GetPenalita();
    }
    else //La penalità non viene ridotta se la salute è troppo bassa
    {
        tempo_perso += Salute.GetPenalita();
    }
    tempo -= sFisico.riduciTempo(tempo_perso);
    //Qui la penalità di tempo totale viene ridotta in base alla costituzione attuale del personaggio
    cout << "Tempo residuo: " << tempo << endl;
}

//INIZIO MODIFICHE DEL GIUDICE ANGELO
void Gioco::Aggiorna_Tempo_bonus()       // Museo
{
    int tempo_b=40;
    interfaccia.scrivi("---------------Complimenti hai ottenuto 40 punti bonus!----------------");
    cout<<"Tempo precedente: "<<tempo<<endl;
    tempo=tempo+tempo_b;
    cout<<"Il tempo attuale e':"<<tempo<<endl;

}
bool Gioco::biglietto_museo() //funzione ausiliare per controllare la disponibilita' del portafoglio
// e aquistare biglietto museo
{
    bool acquisto=false;
    char a[1];
    int tempo_b=0;
    float saldo_p=0.0f;
    int numero;
    bool trovato = false;
    trovato = portafoglio.hai_Portafoglio(oggetti);
    if(trovato==true)
    {
        saldo_p=portafoglio.get_contanti();
        if (saldo_p>=10)
        {
            saldo_p=saldo_p-10;
            portafoglio.set_contanti(saldo_p);
            do
            {
                system("cls");
                //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                interfaccia.scrivi("Biglietto acquistato!");
                interfaccia.a_capo();
                //Calcolo bonus randomico
                numero=rand()%(10-1+1)+1;
                if(numero==3)
                {
                    Aggiorna_Tempo_bonus();
                }
                interfaccia.scrivi("Premi un tasto per continuare...");

                cin>>a;
            }
            while(a==" ");
            acquisto=true;
        }

        else
        {
            interfaccia.scrivi("Credito insufficiente!");
        }
    }
    else if(trovato==false)
    {
        interfaccia.scrivi("Non e' possibile acquistare se non indossi il portafoglio con almeno 10 euro al suo interno! ");
    }
    return acquisto;
}
//modifiche angelo del giudice commentate causa sostituzione con struttura dati grafo nel museo da ANTONIO PASTORELLI
/*
void Gioco::mostra_galleria_a()
{

int risposta_documento;
bool caso=false;
bool uscita_museo;

    do
   {

	  ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   uscita_museo=false;

   interfaccia.scrivi("|----------------------------------------------------------------------------------|");
   interfaccia.scrivi("|BENVENUTO NELLA GALLERIA A                                                        |");
   interfaccia.scrivi("|In questa galleria verrai guidato nell'esplorazione del percorso Preistorico.     |");
   interfaccia.scrivi("|Il percorso Preistorico comprende una serie di esposizioni di notevole importanza.|");
   interfaccia.scrivi("|Per maggiori descrizioni sui reperti presenti, consultare la guida elettronica :  |");
   interfaccia.scrivi("|1 - Neuropteris sp.-Felci fossili-Carbonifero-Francia                             |");
   interfaccia.scrivi("|2 - Allosaurus fragilis-Scheletro di Allosauro-Giurassico-Stati Uniti d'America   |");
   interfaccia.scrivi("|3 - Coproliti di dinosauri - Epoche varie - Stati Uniti d'America                 |");
   interfaccia.scrivi("|4 - Pterodactylus kochi-Rettile volante-Giurassico-Solnhofen (Germania)           |");
   interfaccia.scrivi("|5 - Tyrannosaurus rex-Palena (Chieti)                                             |");
   interfaccia.scrivi("|6 - PER USCIRE DALLA GUIDA ELETTRONICA                                            |");
   interfaccia.scrivi("|----------------------------------------------------------------------------------|");
       interfaccia.scrivi_parziale("Mosse rimaste: ");
       tempo--;
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
	continue;
	    }

   switch (risposta_documento) {
   case 1:
   ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Neuropteris sp.-Felci fossili-Carbonifero-Francia                           |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Queste piante raggiungevano un'altezza di cinque metri, con un tronco molto |");
   interfaccia.scrivi("|simile a quello delle attuali palme. Il fusto era formato in parte dalle    |");
   interfaccia.scrivi("|basi foliari delle vecchie foglie, e possedeva radici aeree che crescevano  |");
   interfaccia.scrivi("|in prossimitÃ  della base. Le fronde erano di diverso tipo: alcune erano     |");
   interfaccia.scrivi("|dentellate, altre erano munite di foglioline arrotondate. A molte di queste |");
   interfaccia.scrivi("|foglie sono stati assegnati nomi diversi, come Neuropteris o Alethopteris.  |");
   interfaccia.scrivi("|La prima era un tipo di foglia di grandi dimensioni, con un rachide percorso|");
   interfaccia.scrivi("|da striature longitudinali. In Alethopteris, invece, le venature erano poco |");
   interfaccia.scrivi("|visibili e quasi ad angolo retto, mentre il margine della foglia era        |");
   interfaccia.scrivi("|dentellato.                                                                 |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   tempo--;
   //system("pause");
   break;
   case 2:
       ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Allosaurus fragilis-Scheletro di Allosauro-Giurassico-Stati Uniti d'America |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Allosaurus e' un genere estinto di grande dinosauro teropode, vissuto tra i |");
   interfaccia.scrivi("|155 e i 145 milioni di anni fa, durante il periodo Giurassico. I primi      |");
   interfaccia.scrivi("|resti fossili furono ritrovati nel 1877, ad opera del paleontologo Othniel  |");
   interfaccia.scrivi("|Charles Marsh, che ribattezzÃ² i resti come Antrodemus. Essendo uno dei primi|");
   interfaccia.scrivi("|dinosauri teropodi meglio conservati e piu' completi, questo animale ha piu'|");
   interfaccia.scrivi("|volte attirato l'attenzione di paleontologi e amanti dei dinosauri.         |");
   interfaccia.scrivi("|L'Allosaurus era un predatore bipede di modeste dimensioni; il suo cranio   |");
   interfaccia.scrivi("|era incredibilmente robusto e compatto e armato di una moltitudine di denti.|");
   interfaccia.scrivi("|La lunghezza di un esemplare adulto non doveva essere inferiore agli 8,5    |");
   interfaccia.scrivi("|metri  di lunghezza, anche se alcuni resti frammentari suggeriscono         |");
   interfaccia.scrivi("|dimensioni maggiori, con esemplari che avrebbero potuto raggiungere i       |");
   interfaccia.scrivi("|12 metri di lunghezza.                                                      |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   tempo--;
   //system("pause");
   break;
   case 3:
   ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Coproliti di dinosauri - Epoche varie - Stati Uniti d'America               |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Il termine coprolite deriva dal greco kopros (sterco) e lÃ­thos (pietra) e   |");
   interfaccia.scrivi("|indica un escremento, prodotto da un animale vissuto nel passato, che si e' |");
   interfaccia.scrivi("|fossilizzato. Dallâ€™analisi di questi reperti, si possono ricavare           |");
   interfaccia.scrivi("|informazioni sulle abitudini alimentari e lâ€™habitat nel quale lâ€™animale     |");
   interfaccia.scrivi("|viveva. Per esempio, la presenza di semi, foglie, corteccia o radici indica |");
   interfaccia.scrivi("|che lâ€™escremento e' stato prodotto da un erbivoro, mentre se si individuano |");
   interfaccia.scrivi("|frammenti di ossa, artigli o tendini lâ€™animale era un carnivoro.            |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   tempo--;
   //system("pause");
   break;
   case 4:
   ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Pterodactylus kochi-Rettile volante-Giurassico-Solnhofen (Germania)         |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Pterodactylus e' un estinto genere di pterosauro, i cui membri sono         |");
   interfaccia.scrivi("|popolarmente chiamati ''pterodattili''. Attualmente, il genere contiene una |");
   interfaccia.scrivi("|singola specie, Pterodactylus antiquus, che oltre ad essere la specie tipo  |");
   interfaccia.scrivi("|e' anche il primissimo genere di pterosauro mai rinvenuto. I principali     |");
   interfaccia.scrivi("|ritrovamenti di resti fossili di questo animale sono stati rinvenuti        |");
   interfaccia.scrivi("|principalmente, nei Calcari di Solnhofen, di Baviera, in Germania, risalenti|");
   interfaccia.scrivi("|alla fine del periodo Giurassico, circa 150,8-148-500 milioni di anni fa,   |");
   interfaccia.scrivi("|anche se alcuni resti frammentari sono stati rinvenuti anche in altre aree  |");
   interfaccia.scrivi("|in Europa e in Africa. Questo animale era un predatore che probabilmente si |");
   interfaccia.scrivi("|cibava soprattutto di pesci e piccoli invertebrati marini. Come tutti gli   |");
   interfaccia.scrivi("|pterosauri, anche le ali dello Pterodactyluserano formate da una membrana   |");
   interfaccia.scrivi("|di pelle che si estendeva dalla fine del quarto dito della ''mano'' fino    |");
   interfaccia.scrivi("|agli arti posteriori. L'ala era supportata, ulteriormente, internamente da  |");
   interfaccia.scrivi("|fibre di collagene ed esternamente da strutture cheratinose.                |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   tempo--;
   //system("pause");
   break;
   case 5:
   ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Pterodactylus kochi-Rettile volante-Giurassico-Solnhofen (Germania)         |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   interfaccia.scrivi("|Il tirannosauro  era un dinosauro vissuto nel Cretaceo superiore            |");
   interfaccia.scrivi("|appartenente alla famiglia dei tirannosauridi. Visse in nordamerica, che    |");
   interfaccia.scrivi("|anticamente era un continente isolato nominato Laramidia. Il Tyrannosaurus  |");
   interfaccia.scrivi("|era molto piu' diffuso geograficamente degli altri tirannosauridi. I suoi   |");
   interfaccia.scrivi("|fossili si trovano in una varietÃ  di formazioni risalenti all' epoca        |");
   interfaccia.scrivi("|Maastrichtiana del Cretaceo superiore, circa 68-66 milioni di anni fa.      |");
   interfaccia.scrivi("|Fu una delle specie degli ultimi dinosauri non-aviani viventi quando si ebbe|");
   interfaccia.scrivi("|l' estinzione di massa del Cretaceo-Paleocene, che determino' la scomparsa  |");
   interfaccia.scrivi("|dei dinosauri propriamente detti.                                           |");
   interfaccia.scrivi("|----------------------------------------------------------------------------|");
   tempo--;
   //system("pause");
   break;
   case 6:
    uscita_museo=true;
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    break;
    default:

    interfaccia.scrivi("Comando non riconosciuto");
    //system("pause");
    break;

   }

}while(uscita_museo!=true);


}
void Gioco::mostra_galleria_b()
{bool uscita_museo;

    do
   {
    uscita_museo=false;
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    int risposta_documento;

    interfaccia.scrivi("|----------------------------------------------------------------------------------|");
    interfaccia.scrivi("|BENVENUTO NELLA GALLERIA B                                                        |");
    interfaccia.scrivi("|In questa galleria verrai guidato nell'esplorazione del percorso Romano.          |");
    interfaccia.scrivi("|Come testimonianza di questo periodo storico potrete ammirare antichi affreschi   |");
    interfaccia.scrivi("|Per ulteriri dettagli, consultare la guida elettronica:                           |");
    interfaccia.scrivi("|1 - Numa Pompilio istituisce il culto delle Vestali e dei sacerdoti               |");
    interfaccia.scrivi("|2 - Ritrovamento della Lupa con Romolo e Remo                                     |");
    interfaccia.scrivi("|3 - Combattimento degli Orazi e Curiazi                                           |");
    interfaccia.scrivi("|4 - Ratto delle Sabine                                                            |");
    interfaccia.scrivi("|5 - Battaglia di Tullo Ostilio contro i Veienti e i Fidenati                      |");
    interfaccia.scrivi("|6 - PER USCIRE DALLA GUIDA ELETTRONICA                                            |");
    interfaccia.scrivi("|----------------------------------------------------------------------------------|");
    interfaccia.scrivi_parziale("Mosse rimaste: ");
    interfaccia.scrivi_parziale(tempo);
    interfaccia.scrivi_parziale("\n");
    interfaccia.scrivi_parziale("Risposta: ");

            cin >> risposta_documento;
            switch (risposta_documento) {
        case 1:
        ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Numa Pompilio istituisce il culto delle Vestali e dei sacerdoti(1636-1638)  |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Al centro della scena, sullo sfondo di un grandioso scorcio architettonico, |");
    interfaccia.scrivi("|arde sull' altare il fuoco sacro che le Vestali dovevano custodire sempre   |");
    interfaccia.scrivi("|acceso.                                                                     |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
       case 2:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Ritrovamento della Lupa con Romolo e Remo (1596)                            |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Faustolo scopre sotto i rami di un fico, sulla riva del Tevere, la Lupa che |");
    interfaccia.scrivi("|allatta Romolo e Remo. Nella figura della lupa e' evidente il richiamo alla |");
    interfaccia.scrivi("|Lupa capitolina conservata nel palazzo e simbolo della cittÃ .               |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
    case 3:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Combattimento degli Orazi e Curiazi(1612-1613)                              |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Episodio della guerra di Roma contro la vicina citta' di Albalonga che si   |");
    interfaccia.scrivi("|concluse con un duello tra i rappresentanti di Roma, gli Orazi, e quelli di |");
    interfaccia.scrivi("|Albalonga, i Curiazi. Gli eserciti contendenti assistono alla scena finale  |");
    interfaccia.scrivi("|del duello, quando l' ultimo degli Orazi sta per colpire l' ultimo degli    |");
    interfaccia.scrivi("|avversari                                                                   |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
    case 4:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Ratto delle Sabine (1635-1636)                                              |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|In primo piano e' il gruppo delle donne Sabine rapite dai Romani per        |");
    interfaccia.scrivi("|popolare la cittÃ  da poco fondata. L'affresco, eseguito dopo circa venti    |");
    interfaccia.scrivi("|anni di interruzione, condivide con le ultime due scene una tecnica         |");
    interfaccia.scrivi("|pittorica piu' rapida e sommaria, tipica della tarda maniera del            |");
    interfaccia.scrivi("|Cavalier d' Arpino.                                                         |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
    case 5:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Battaglia di Tullo Ostilio contro i Veienti e i Fidenati(1597-1601)         |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Con vivacita' e' rappresentato un episodio della guerra di espansione       |");
    interfaccia.scrivi("|intrapresa dai Romani contro le cittÃ  vicine al tempo di Tullo Ostilio,     |");
    interfaccia.scrivi("|terzo re di Roma.                                                           |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
    case 6:
    uscita_museo=true;
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    break;
    default:
    interfaccia.scrivi("Comando non riconosciuto");
    //system("pause");

            }

}while(uscita_museo!=true);
}

void Gioco::mostra_galleria_c()
{bool uscita_museo;

    do
    {
    uscita_museo=false;
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    int risposta_documento;
    interfaccia.scrivi("|---------------------------------------------------------------------------------|");
    interfaccia.scrivi("|BENVENUTO NELLA GALLERIA C                                                       |");
    interfaccia.scrivi("|Questa galleria comprende i ritrovamenti del periodo che va dal 200-300 a.C.     |");
    interfaccia.scrivi("|Sono stati ritrovati numerosi reperti risalenti a questa epoca, alcuni dei quali |");
    interfaccia.scrivi("|sono presenti all'interno della nostra galleria.                                 |");
    interfaccia.scrivi("|Per maggiori descrizioni, consultare la guida elettronica:                       |");
    interfaccia.scrivi("|1 - Stele funeraria del tipo â€œa falsa portaâ€� a nome di Sameri                    |");
    interfaccia.scrivi("|2 - Rilievo con scena di libagione                                               |");
    interfaccia.scrivi("|3 - Rilievo dalla tomba di Horemheb con scena di lavoro nei campi dellâ€™oltretomba|");
    interfaccia.scrivi("|4 - Rilievo con la dea Renenutet                                                 |");
    interfaccia.scrivi("|5 - Sarcofago a cassa a nome di Irinimenpu                                       |");
    interfaccia.scrivi("|6 - PER USCIRE DALLA GUIDA ELETTRONICA                                           |");
    interfaccia.scrivi("|---------------------------------------------------------------------------------|");
        interfaccia.scrivi_parziale("Mosse rimaste: ");
        interfaccia.scrivi_parziale(tempo);
        interfaccia.scrivi_parziale("\n");
        interfaccia.scrivi_parziale("Risposta: ");
            cin >> risposta_documento;
            switch (risposta_documento) {
            case 1:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Stele funeraria del tipo a ''falsa porta'' a nome di Sameri                   |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|La stele a '' falsa porta ''  e'  un elemento funerario tipico delle        |");
    interfaccia.scrivi("|sepolture dell' Antico Regno ed e'  costituita da due o piu' montanti       |");
    interfaccia.scrivi("|laterali e da un architrave sotto cui e'  scolpita una stuoia arrotolata    |");
    interfaccia.scrivi("|a suggerire l' idea di una porta accessibile all' anima del defunto. Questa |");
    interfaccia.scrivi("|stele appartiene ad un funzionario di nome Sameri, membro di una famiglia di|");
    interfaccia.scrivi("|cortigiani molto vicina al faraone, e gli dedicata dal padre Urkaptah, che  |");
    interfaccia.scrivi("|include nel dono anche la moglie e gli altri figli. Sameri e' rappresentato |");
    interfaccia.scrivi("|con la tecnica del rilievo ad incavo sull' architrave della â€œfalsa portaâ€�,  |");
    interfaccia.scrivi("|mentre siede in compagnia della madre Henutes davanti a una tavola ricolma  |");
    interfaccia.scrivi("|di vasellame da mensa e di alimenti (pani, anatre giÃ  spennate, tranci di   |");
    interfaccia.scrivi("|carne bovina, etc.) utili per la sua sopravvivenza ultraterrena che         |");
    interfaccia.scrivi("|lâ€™iscrizione in caratteri geroglifici sottostante completa per forza magica |");
    interfaccia.scrivi("|Lâ€™importanza del pane, quale alimento base della dieta egiziana, appare     |");
    interfaccia.scrivi("|evidente, anche se non e'  possibile differenziare le varie tipologie di    |");
    interfaccia.scrivi("|pane elencate per qualitÃ  di ingredienti, modalitÃ  di impasto e di cottura  |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");

    tempo--;
    //system("pause");
                    break;
            case 2:
            ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Rilievo con scena di libagione                                              |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    interfaccia.scrivi("|Il rilievo, collocato in origine alle pareti di una tomba, mostra una scena |");
    interfaccia.scrivi("|di libagione. La â€œsignora della casaâ€� Nubi, proprietaria della sepoltura,   |");
    interfaccia.scrivi("|siede su una bassa sedia decorata con zampe di gatto mentre riceve l'offerta|");
    interfaccia.scrivi("|funeraria di acqua e di vino da sua figlia Kiki, in piedi davanti a lei.    |");
    interfaccia.scrivi("|Altri cibi, tra i quali un mazzetto di porri e varie cucurbitacee, sono     |");
    interfaccia.scrivi("|raccolti allâ€™interno di un profondo bacile alle spalle di Kiki allo scopo di|");
    interfaccia.scrivi("|nutrire in eterno la defunta. L'eleganza e la morbidezza delle figure, come |");
    interfaccia.scrivi("|la raffinatezza dei costumi rivelano l'agiatezza di vita della dama Nubi,   |");
    interfaccia.scrivi("|tipica dell' Egitto del Nuovo Regno. Entrambe le donne indossano lunghi abiti|");
    interfaccia.scrivi("|la cui semplicitÃ  contrasta con la resa accurata dei gioielli, visibili alle|");
    interfaccia.scrivi("|braccia, al collo e alle orecchie,e delle pesanti parrucche adorne di nastri|");
    interfaccia.scrivi("|coroncine di fiori e cono di unguento profumato.                            |");
    interfaccia.scrivi("|----------------------------------------------------------------------------|");
    tempo--;
    //system("pause");
    break;
    case 3:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Rilievo dalla tomba di Horemheb con scena di lavoro nei campi dell'oltretomba |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Il rilievo, proveniente da una delle tre cappelle di culto annesse alla tomba |");
    interfaccia.scrivi("|menfita del generale Horemheb, e' costituito da due frammenti parietali       |");
    interfaccia.scrivi("|combacianti ed e' suddiviso in quattro fasce orizzontali scolpite a           |");
    interfaccia.scrivi("|bassorilievo. E' probabile che quella in alto, di cui sopravvive solo la      |");
    interfaccia.scrivi("|parte inferiore, contenesse l'omaggio di Horemheb alle divinitÃ  funerarie.    |");
    interfaccia.scrivi("|Nei due registri centrali, meglio conservati, Horemheb e' colto in momenti    |");
    interfaccia.scrivi("|diversi: seduto in compagnia della sua â€œanimaâ€� akh dalle sembianze di uccello |");
    interfaccia.scrivi("|appollaiato su un trespolo davanti a una tavola piena di pani di varia forma, |");
    interfaccia.scrivi("|tranci di carne bovina e altri cibi destinati al pasto funebre del defunto;   |");
    interfaccia.scrivi("|in piedi mentre governa alcuni buoi che calpestano un mucchio di spighe di    |");
    interfaccia.scrivi("|cereale per separare i chicchi dalla pula; in piedi, dietro un aratro trainato|");
    interfaccia.scrivi("|da due buoi, intento a dissodare il terreno da coltivare. In basso, Horemheb  |");
    interfaccia.scrivi("|e'  nuovamente seduto davanti a una tavola stracolma di offerte e, a raccolto |");
    interfaccia.scrivi("|ultimato, riceve in dono alcuni mannelli di lino da parte di tre contadini.   |");
    interfaccia.scrivi("|Tutte queste scene, ispirate al capitolo 110 del Libro dei Morti, ci mostrano |");
    interfaccia.scrivi("|Horemheb al lavoro nei campi dellâ€™oltretomba per garantirsi la sopravvivenza  |");
    interfaccia.scrivi("|eterna. Il serpente ureo, simbolo di regalitÃ , che orna la sua fronte, fu     |");
    interfaccia.scrivi("|scalpellato in un secondo momento, solo quando Horemheb divenne faraone       |");
    interfaccia.scrivi("|dâ€™Egitto alla fine della XVIII dinastia.                                      |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
             tempo--;
                 //system("pause");

              break;
    case 4:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Rilievo con la dea Renenutet                                                  |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Il rilievo proviene dalla tomba di uno scriba di nome Amenemhat, vissuto agli |");
    interfaccia.scrivi("|inizi del Nuovo Regno, prima del faraone Akhenaton, durante il cui governo il |");
    interfaccia.scrivi("|nome del dio Amon fu spesso cancellato, come in questo caso. Sul rilievo sono |");
    interfaccia.scrivi("|raffigurate due tipiche attivitÃ  agricole: nella parte alta, alcuni contadini |");
    interfaccia.scrivi("|puliscono il grano lanciandolo in aria con sessole di legno per separare i    |");
    interfaccia.scrivi("|chicchi dalla pula, mentre un uomo offre loro da bere con profonde ciotole    |");
    interfaccia.scrivi("|emisferiche, riempite in un grande vaso panciuto alle sue spalle. Nel registro|");
    interfaccia.scrivi("|inferiore si procede alla misurazione del cereale ormai pulito e accumulato di|");
    interfaccia.scrivi("|fronte alla dea delle messi Renenutet, in forma di serpente cobra. Scene di   |");
    interfaccia.scrivi("|questo tipo, sia dipinte che a rilievo, sono piuttosto comuni nellâ€™arte       |");
    interfaccia.scrivi("|egiziana a partire dall'Antico Regno                                          |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 5:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Sarcofago a cassa a nome di Irinimenpu                                        |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|La decorazione principale di questo sarcofago destinato al corredo funerario  |");
    interfaccia.scrivi("|di un egiziano di nome Irinimenpu consiste in una serie di pannelli a         |");
    interfaccia.scrivi("|'facciata di palazzo', un motivo ripreso dall'architettura funararia          |");
    interfaccia.scrivi("|dell'Antico Regno, che rende il sarcofago simile a una dimora eterna. Su uno  |");
    interfaccia.scrivi("|dei lati lunghi della cassa, in posizione centrale, sono raffigurate numerose |");
    interfaccia.scrivi("|offerte alimentari (pani, ortaggi, frutti, tranci di carni bovine, volatili   |");
    interfaccia.scrivi("|giÃ  spennati, contenitori per liquidi, etc.), perche' il defunto possa        |");
    interfaccia.scrivi("|nutrirsene per forza magica nella vita ultraterrena. Sullo stesso lato,       |");
    interfaccia.scrivi("|a una delle estremita', e' dipinta una porta chiusa, sopra la quale sono      |");
    interfaccia.scrivi("|collocati due occhi che indicano la presenza all'interno della testa della    |");
    interfaccia.scrivi("|mummia e allo stesso tempo rappresentano una protezione magica per il corpo   |");
    interfaccia.scrivi("|del defunto. L'ottimo stato di conservazione del legno e dei vivaci colori    |");
    interfaccia.scrivi("|utilizzati per decorarlo si deve al clima caldo e asciutto dell'Egitto,       |");
    interfaccia.scrivi("|oltre che alla collocazione originaria del sarcofago nell'ambiente protetto   |");
    interfaccia.scrivi("|della sepoltura.                                                              |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 6:
    uscita_museo=true;
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    break;
            default:
                interfaccia.scrivi("Comando non riconosciuto");
                //system("pause");
            }
}while(uscita_museo!=true);
}
void Gioco::mostra_galleria_d()
{bool uscita_museo;

    do
    {

    uscita_museo=false;

    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    int risposta_documento;

    interfaccia.scrivi("|------------------------------------------------------------------------------------|");
    interfaccia.scrivi("|BENVENUTO NELLA GALLERIA D                                                          |");
    interfaccia.scrivi("|In questa galleria verrai guidato nell'esplorazione del percorso sulla Magna Grecia.|");
    interfaccia.scrivi("|La Magna Grecia e' l'area geografica della penisola italiana meridionale che fu     |");
    interfaccia.scrivi("|anticamente colonizzata dai Greci a partire dall' VIII secolo a.C..                 |");
    interfaccia.scrivi("|Di questa civilta' possediamo numerose sculture e reperti                           |");
    interfaccia.scrivi("|Per maggiori descrizioni sui reperti presenti, consultare la guida elettronica:     |");
    interfaccia.scrivi("|1 - Testa in marmo di Eracle                                                        |");
    interfaccia.scrivi("|2 - Stele figurata in marmo con defunto in nuditÃ  eroica.                           |");
    interfaccia.scrivi("|3 - Statua marmorea del II secolo d.C. di genio carpoforo (portatore di frutti).    |");
    interfaccia.scrivi("|4 - Specchio in argento, con doratura a caldo.                          |");
    interfaccia.scrivi("|5 - I Bronzi di Riace                                                               |");
    interfaccia.scrivi("|6 - PER USCIRE DALLA GUIDA ELETTRONICA                                              |");
    interfaccia.scrivi("|------------------------------------------------------------------------------------|");
        interfaccia.scrivi_parziale("Mosse rimaste: ");
        interfaccia.scrivi_parziale(tempo);
        interfaccia.scrivi_parziale("\n");
        interfaccia.scrivi_parziale("Risposta: ");
            cin >> risposta_documento;
            switch (risposta_documento) {
    case 1:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Testa in marmo di Eracle                                                      |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Probabilmente una copia del colosso bronzeo creato da Lisippo a Tara alla fine|");
    interfaccia.scrivi("|del IV secolo AC.                                                             |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 2:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Stele figurata in marmo con defunto in nuditÃ  eroica.                         |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Raffigurato nellâ€™atto di offrire una melagrana ad un serpente, simbolo        |");
    interfaccia.scrivi("|funerario delle divinitÃ  infernali.                                           |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 3:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Statua marmorea del II secolo d.C. di genio carpoforo (portatore di frutti).  |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Proveniente dall'area delle Terme e relativo alla decorazione scultorea delle |");
    interfaccia.scrivi("|stesse.                                                                       |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 4:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|Specchio in argento, con doratura a caldo.                        |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|E' raffigurata l'immagine di una Musa, o di Afrodite, circondata da Eroti.    |");
    interfaccia.scrivi("|Dalla tomba degli Ori di Canosa.                                              |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
    case 5:
    ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|I Bronzi di Riace                                                             |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    interfaccia.scrivi("|I Bronzi di Riace sono due statue di bronzo di provenienza greca o magnogreca |");
    interfaccia.scrivi("|o siceliota, databili al V secolo a.C. pervenute in eccezionale stato di      |");
    interfaccia.scrivi("|conservazione. Le due statue, rinvenute il 16 agosto 1972 nei pressi di Riace,|");
    interfaccia.scrivi("|in provincia di Reggio Calabria sono considerate tra i capolavori scultorei |");
    interfaccia.scrivi("|piu' significativi dell'arte greca, e tra le testimonianze dirette dei grandi |");
    interfaccia.scrivi("|maestri scultori dell'eta' classica. Le ipotesi sulla provenienza e sugli     |");
    interfaccia.scrivi("|autori delle statue sono diverse, ma non esistono ancora elementi che         |");
    interfaccia.scrivi("|permettano di attribuire con certezza le opere ad uno specifico scultore.     |");
    interfaccia.scrivi("|I Bronzi si trovano al Museo nazionale della Magna Grecia di Reggio Calabria, |");
    interfaccia.scrivi("|luogo in cui sono stati riportati il 12 dicembre 2015, dopo la rimozione e il |");
    interfaccia.scrivi("|soggiorno per tre anni (con annessi lavori di restauro) presso Palazzo        |");
    interfaccia.scrivi("|Campanella, sede del Consiglio Regionale della Calabria a causa dei lavori di |");
    interfaccia.scrivi("|ristrutturazione dello stesso museo. I Bronzi sono diventati uno dei simboli  |");
    interfaccia.scrivi("|della cittÃ  stessa.                                                           |");
    interfaccia.scrivi("|------------------------------------------------------------------------------|");
    tempo--;
        //system("pause");

    break;
           case 6:
                uscita_museo=true;
                ////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
                break;
            default:
                interfaccia.scrivi("Comando non riconosciuto");
                 //system("pause");
            }
//FINE MODIFICHE DEL GIUDICE ANGELO
}while(uscita_museo!=true);
            }*/   //modifiche angelo del giudice commentate causa sostituzione con struttura dati grafo nel museo da ANTONIO PASTORELLI
/* 1510 - 1670
	Introduzione
*/
void Gioco::introduzione() {}

/* 3810 - 3830
	comune
*/
void Gioco::errore()
{
    passo_soluzione = 0;
    tempo = tempo/2;
}

/* 1760 - 1800
	1: direzioni
*/
/*void Gioco::direzioni(Mappa &M)
{

    int a = mappa.luogo_adiacente(luogo_attuale,cod_parola1);
    if (a == 0)
    {
        interfaccia.scrivi("- Di li' non puoi andare");

        stringa_risposta = "di li' non sei potuto andare."; 		  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
    }
    else
    {
        luogo_attuale = a;
        if(mappa.get_nome_luogo(a) != "Luogotrasporto")
        {
            stringa_risposta = "sei andato " + mappa.get_nome_luogo(luogo_attuale) + "."; //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            //Modifica PMF(storia)
        }
    }

}
*/
bool Gioco::direzioni(Mappa &M)
{
    //INIZIO modifiche DELLA FOLGORE GRAZIA
    bool cambia_dir = true;
    int a = mappa.luogo_adiacente(luogo_attuale,cod_parola1);
    if (a == 0)
    {
        interfaccia.scrivi("- Di li' non puoi andare");
        stringa_risposta = "di li' non sei potuto andare."; 		  //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
        cambia_dir = false;  //PANNO
    }
    else
    {
        //INIZIO modifiche PALAGIANO MARCELLO
        if (((autobus.get_inUso()==true)||(automobile.get_inUso()==true)) && (a<38 && a!=13 && a!=41))
        {
            if(autobus.get_inUso()==true)
            {
                interfaccia.scrivi("- Non puoi andare li' con l'autobus");
                stringa_risposta = "hai provato ad andare con l'autobus in posti non autorizzati";
                storia_gioco.insStoria(stringa_comando, stringa_risposta);
            }
            if(automobile.get_inUso()==true)
            {
                interfaccia.scrivi("- Non puoi andare li' con l'auto");
                stringa_risposta = "hai provato ad andare con l'auto in posti non autorizzati";
                storia_gioco.insStoria(stringa_comando, stringa_risposta);
            }
            cambia_dir = false;  //Modifica Rosita Galiandro
        }
        else
        {
            if(automobile.get_inUso()==true && batteria_cambiata==false && a!=41 && a!=13)
            {
                interfaccia.scrivi("Sarebbe pericoloso andare di la' con la batteria scarica!");
                stringa_risposta = "non hai cambiato la batteria";
                storia_gioco.insStoria(stringa_comando, stringa_risposta);
            }

            else
            {
                int b = a - 9; //Aggiustamento per ricerca luogo da file DELLA FOLGORE GRAZIA
                if((a>=38) && (a<=40) && ((mappa.get_nome_luogo(b) == "Bari") || (mappa.get_nome_luogo(b) == "Roma") || (mappa.get_nome_luogo(b) == "Pisa")))
                {
                    a = b;
                    if((autobus.get_inUso()==false)&&(automobile.get_inUso()==false))
                    {
                        interfaccia.scrivi("- Impieghi piu' tempo muovendoti a piedi");
                        tempo = tempo - 3;
                    }
                }

                luogo_attuale = a;
                if(mappa.get_nome_luogo(a) != "Luogotrasporto")
                {
                    stringa_risposta = "sei andato " + mappa.get_nome_luogo(luogo_attuale) + "."; //Modifica PMF(storia)
                    storia_gioco.insStoria(stringa_comando, stringa_risposta); 				   //Modifica PMF(storia)
                }
            }
            //FINE modifiche PALAGIANO MARCELLO
        }
    }
    return cambia_dir;
    //FINE modifiche DELLA FOLGORE GRAZIA
}
/* 1810 - 1890
	2: prendi
*/
bool Gioco::prendi_specifiche()
{
    return false;
}
bool Gioco::preso_specifiche()
{
    return false;
}

//MODIFICA D-R(Pisani):Portafoglio + Carta di Credito
void Gioco::prendi()
{
    //modifica Gallone Gianmarco -  Riadattamento metodo prendi per tasca, zaino e portafoglio.
    bool fatto = false;
    bool cpz= true ;
    riferimento_tasca = tasca.primolista();
    riferimento_zaino = zaino_frigo.primolista();
    bool trovato = false;
    int check = 0;


    if(og == 11 || og == 4 || og == 23 || og == 25)
    //controllo che gli oggetti che possono andare in valigia o nello zaino siano
    // o il casco, o la tuta, o il camice o il manuale
    {
        if (oggetti.get_oggetto(og).get_luogo() == 0)
        //controllo che l'oggetto non sia stato già preso
        {
            interfaccia.scrivi("- Gia' fatto.");
            stringa_risposta = "non e' stato possibile perche' avevi gia' quell'oggetto.";
            //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            //Modifica PMF(storia)
        }
        else if(oggetti.get_oggetto(og).get_luogo() == 20)
        //controllo che l'oggetto non sia già nela valigia o nello zaino
        {
            interfaccia.scrivi("- Sta gia' nello zaino o nella valigia.");
        }
        else if (oggetti.get_oggetto(og).get_luogo() < 0)
        //controllo che l'oggetto si possa prendere del tutto
        {
            stringa_risposta = "non e' stato possibile.";
            //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            //Modifica PMF(storia)
            interfaccia.scrivi("- Non e' possibile.");
        }
        else if (!prendi_specifiche())
        {
            controllo2 = false;
            controllo1 = false;

            if(oggetti.get_oggetto(143).get_luogo() == 0)
            // controllo se la valigia si trova nell'inventario
            {
                if (og == 21 || og == 24 || og==49)
                {
                    oggetti.set_luogo(og,0);
                }
                else
                {
                    do
                    {
                        interfaccia.scrivi(
                        "Se vuoi portare l'oggetto con te, premi(y);se vuoi metterlo in valigia, premi(v)");


                        cin >> risposta1;
                        if(risposta1 == "y" || risposta1 == "Y")
                        {
                            oggetti.set_luogo(og,0);
                            interfaccia.scrivi("Ora e' nell'inventario.");
                            controllo1 = true;
                            controllo2 = true;
                        }
                        else if(risposta1 == "v" || risposta1 == "V")
                        {
                            oggetti.set_luogo(og,20);
                            controllo2 = true;
                        }
                        else
                        {
                            controllo2 = false;
                        }
                    }
                    while(controllo2 == false);
                }
            }
            else if(oggetti.get_oggetto(144).get_luogo() == 0)
            {
                if (og == 21 || og == 24 || og==49)
                {
                    oggetti.set_luogo(og,0);
                }
                else
                {
                    do
                    {
                        interfaccia.scrivi(
                        "Se vuoi portare l'oggetto con te, premi(y); se vuoi metterlo nello zaino, premi(z)");
                        cin >> risposta1;
                        if(risposta1 == "y" || risposta1 == "Y")
                        {
                            oggetti.set_luogo(og,0);
                            interfaccia.scrivi("Ora e' nell'inventario.");
                            controllo1 = true;
                            controllo2 = true;
                        }
                        else if(risposta1 == "z" || risposta1 == "Z")
                        {

                            oggetti.set_luogo(og,20);
                            controllo2 = true;
                        }
                        else
                        {
                            controllo2 = false;
                        }
                    }
                    while(controllo2 == false);
                }
            }
            else
            {
                oggetti.set_luogo(og,0);
            }

            if(!controllo1 && !preso_specifiche())
            {
                interfaccia.scrivi("Fatto.");
                stringa_risposta = "l'hai preso.";
                //Modifica PMF(storia)
                storia_gioco.insStoria(stringa_comando, stringa_risposta);
                //Modifica PMF(storia)
            }

            bacheca.CancellaMessaggioGioco(
            "*non uscire fuori dall'astronave se non hai l'equipaggiamento da astronauta");
        }
    }
    else if(!prendi_specifiche())
    {
        if (oggetti.get_oggetto(og).get_luogo() == 0)
        {
            interfaccia.scrivi("- Gia' fatto.");
            stringa_risposta = "non e' stato possibile perche' avevi gia' quell'oggetto.";
            //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
        }
        else if (oggetti.get_oggetto(og).get_luogo() < 0)
        {
            stringa_risposta = "non e' stato possibile.";
            //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            //Modifica PMF(storia)
            interfaccia.scrivi("- Non e' possibile.");
        }
        else if ((og != 27) && (og != 36) && (og != 37) && (og != 38) && (og != 39) &&
                (og != 40) && (og != 41) && (og != 42) && (og != 43) && (og != 44))
        {
            if(!preso_specifiche())
            {
                oggetti.set_luogo(og,0);
                if (og == 26)
                {
                    interfaccia.scrivi("Fatto : l'hai addosso ! ");
                    stringa_risposta = "l'hai preso.";
                        //Modifica PMF(storia)
                    storia_gioco.insStoria(stringa_comando, stringa_risposta);
                    //Modifica PMF(storia
                }
                else
                {
                    interfaccia.scrivi("Fatto.");
                    stringa_risposta = "l'hai preso.";
                    //Modifica PMF(storia)
                    storia_gioco.insStoria(stringa_comando, stringa_risposta);
                    check++;
                }
            }
        }//Gestione portafogli
        else if ( og == 27|| (og >=36 && og <= 44))
        {
            bool port = false;
            port = portafoglio.hai_Portafoglio(oggetti);
            if (port &&(og>=36 && og <=44) )
            {
                if(!fatto)
                    portafoglio.Prendi_Banconota(oggetti,og,interfaccia);
                oggetti.set_luogo(og,0);
            }
            else if(!port && (og>=36 && og <=44))
                interfaccia.scrivi(
                " Non e' Possibile prendere denaro se non hai gia' preso il portafoglio !" );
            else if (!port &&(og==27))
                interfaccia.scrivi(
                "Non e' Possibile prendere la carta di credito  se non hai gia' preso il portafoglio !") ;
            else if (port &&(og==27))
            {
                oggetti.set_luogo(og,0);
                interfaccia.scrivi("Presa! L'hai nel portafoglio");
            }
        }
        else if (og == 49 || og == 118 || og == 73)
        //non puo prendere: motorino
        {
            interfaccia.scrivi ("Quest'oggetto non e' tuo. Per averlo dovresti rubarlo!");
            //  chiave_auto
            interfaccia.a_capo();
            //  buono pasto giallo
            oggetti.set_rubato(og,false);
        }
        else if(og == 74)       // Modifica documento d'identità //
        {
            oggetti.set_luogo(og, 0);
            tasca.inslista(og, riferimento_tasca);
        }
        else if (og >=77 && og <= 79)
        {
            oggetti.set_luogo(og, 0);
            tasca.inslista(og,riferimento_tasca);
            interfaccia.scrivi("Inserito nella tasca!");
        }
        else if (og >= 67 && og <=76)
        {
            if (tasca.listavuota())
            {
                interfaccia.scrivi("Non hai buoni pasto per acquistarlo!");
                cpz=false;
            }
            else
            {
                interfaccia.scrivi("Dovresti comprare le pietanze, non prenderle...");
                cpz=false;
            }
        }
        //INIZIO modifiche PALAGIANO MARCELLO
        else if(oggetti.get_oggetto(117).get_luogo() == 0)
        {
            interfaccia.scrivi("** Per prendere oggetti devi lasciare l'autobus! **");
            cpz=false;
        }
        else if(oggetti.get_oggetto(119).get_luogo() == 0)
        {
            interfaccia.scrivi("** Per prendere oggetti devi lasciare l'automobile! **");
            cpz=false;
        }
        //FINE modifiche PALAGIANO MARCELLO
        else
            oggetti.set_luogo(og,0);
        //Fine Modifica Gallone
        // MANCA NELLE VERSIONI INTERMEDIE
        if (!preso_specifiche() && (cpz) && check == 0)
        {
            oggetti.set_rubato(og,false); // modifica CHIARAPPA ROSA
            interfaccia.scrivi("Fatto.");
            interfaccia.a_capo();
        }
    }
    while (!tasca.finelista(riferimento_tasca))
    {
        if (oggetti.get_oggetto(og).get_codice() ==
            oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_codice())
            trovato = true;
        riferimento_tasca = tasca.succlista(riferimento_tasca);
    }


    while (!zaino_frigo.finelista(riferimento_zaino))
    {
        riferimento_zaino = zaino_frigo.succlista(riferimento_zaino);
        oggetti.set_rubato(og,false);
    }
}
// inizio modifiche CHIARAPPA ROSA

void Gioco::ruba()    //azione RUBA
{

    if (oggetti.get_oggetto(og).get_luogo() == 0 && oggetti.get_oggetto(og).get_rubato() == true)
    {

        interfaccia.scrivi(" L'hai gia' rubato.");
    }
    else if (oggetti.get_oggetto(og).get_luogo() < 0)
    {
        interfaccia.scrivi(" Non puoi rubarlo.");
    }
    else
    {
        if (og == 49 || og == 118 || og == 73)       //puo rubare: motorino, chiave_auto e buono pasto
        {
            int l = 0;
            oggetti.set_luogo(og, l);
            oggetti.set_rubato(og,true);
            interfaccia.scrivi("Rubato.");
        }
        else
        {
            interfaccia.scrivi ( "Quest'oggetto non puo essere rubato. Per averlo devi prenderlo.");
        }
    }
    interfaccia.a_capo();
}





void Gioco::rubati()     //Inventario oggetti rubati
{
    interfaccia.elenca_rubati(oggetti.posizionati_in(0),"Hai rubato:\n");

}






void Gioco::aggiorna_luogo_carabiniere(int contatore)
{

    int codice = 94;
    Personaggi carabiniere = insPersonaggi.recupera(codice);  //recupera il personaggio dal dizionario inspersonaggio
    if (contatore >= 10)        //fino a 10 azioni il carabiniere resta nella stanza settata inizialmente, dopo le 10 azioni nella stanza dettata dal numero random calcolato
    {
        srand (time(NULL));
        carabiniere.setLuogo(rand() % 48 + 1);
        insPersonaggi.aggiorna(codice, carabiniere);
    }
//	std::cout <<"Il carabiniere e' nella stanza: "<< carabiniere.getLuogo() << std::endl;
}






bool Gioco::verifica_presenza_carabiniere(int luogo_attuale)
{

    int codice = 94;
    Personaggi carabiniere = insPersonaggi.recupera(codice);
    if (carabiniere.getLuogo()==luogo_attuale)
    {
        return true;
    }
    else
    {
        return false;
    }
}







void Gioco::perquisizione_giocatore(int &luogo_attuale)
{

    if (oggetti.get_oggetto(118).get_rubato() == true || oggetti.get_oggetto(73).get_rubato() == true || oggetti.get_oggetto(49).get_rubato() == true) //controllo se l'oggetto
    {
        interfaccia.scrivi("Il carabiniere ti ha perquisito e ha trovato in tuo possesso un oggetto rubato, sei in arresto!");
        interfaccia.a_capo();
        luogo_attuale = 53-9;
        interfaccia.scrivi("Puoi uscire dalla caserma fra 30 secondi.");
        //sleep (30);
        interfaccia.scrivi("Ora sei libero.");
        oggetti.set_rubato(118, false);
        oggetti.set_rubato(73, false);
        oggetti.set_rubato(49, false);

    }
    else
    {
        interfaccia.scrivi("Il carabiniere ti ha perquisito e non ha trovato nessun oggetto rubato in tuo possesso.");
    }
    interfaccia.a_capo();
}



// fine modifiche CHIARAPPA ROSA





void Gioco::cosa()
{
    interfaccia.elenca_oggetti(oggetti.posizionati_in(0),"Possiedi:");

    stringa_risposta = "hai consultato l'inventario degli oggetti che portavi con te."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);       					//Modifica PMF(storia)

//Modifica PMF(ufficio)
    if (ritirato == true)
    {
        // interfaccia.scrivi("Possiedi come documento: "); //Modifica PMF(ufficio) (INSERIMENTO DEL DOCUMENTO RITIRATO NELL'INVENTARIO DEL GIOCATORE)
        primo_doc.elenca_documenti(0);
    }
    //Modiifca PMF: fin qui.
}

/* 1900 - 1940
	3: lascia
*/
bool Gioco::lascia_specifiche()
{
    return false;
}


void Gioco::lascia()
{
    riferimento_tasca = tasca.primolista();
    riferimento_zaino = zaino_frigo.primolista();
    bool trovato = false;
    if (og != 44 && (luogo_attuale != 21 && luogo_attuale != 22))
    {
        if (og == 0 || oggetti.get_oggetto(og).get_luogo() != 0)
            interfaccia.scrivi("- Non ce l'hai.");
        else if (!lascia_specifiche())
        {
            if (og >= 77 && og <= 79)
                while (!tasca.finelista(riferimento_tasca) && trovato == false)
                {
                    if(oggetti.get_oggetto(tasca.leggilista(riferimento_tasca)).get_codice() ==
                        oggetti.get_oggetto(og).get_codice())
                    {
                        tasca.canclista(riferimento_tasca);
                        trovato = true;
                    }
                    else
                        riferimento_tasca = tasca.succlista(riferimento_tasca);
                }
            if (og >= 67 && og <= 76)
                while (!zaino_frigo.finelista(riferimento_zaino) && trovato == false)
                {
                    if(oggetti.get_oggetto(zaino_frigo.leggilista(riferimento_zaino)).get_codice() ==
                        oggetti.get_oggetto(og).get_codice())
                    {
                        zaino_frigo.canclista(riferimento_zaino);
                        trovato = true;
                    }
                    else
                        riferimento_zaino = zaino_frigo.succlista(riferimento_zaino);
                }


            if (oggetti.get_oggetto(og).get_rubato()==true)  //modifica ROSA CHIARAPPA (setto a folse
                                                            // gli oggetti rubati lasciati)
            {
                oggetti.set_rubato(og,false);
            }



            oggetti.set_luogo(og,luogo_attuale);
            interfaccia.scrivi("Fatto.");
        }
    }
    else if (luogo_attuale != 12)   //Modifica PMF(ufficio)
    {

        if(og == 0 && oggetti.get_oggetto(og).get_luogo() != 0 && oggetti.get_oggetto(og).get_luogo() != 20)
        // controllo che l'oggetto si trovi in un altro luogo e che l'oggetto non si trovi nè nell'inventario,
        // nè nella valigia, nè nello zaino
        {
            interfaccia.scrivi("- Non ce l'hai e qui non c'e'.");
            stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";//Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
        }

        else if (!lascia_specifiche())
        {
            // faccio alcuni controlli in lascia_specifiche
            if(oggetti.get_oggetto(144).get_luogo() == 0)
            {
                // controllo che lo zaino si trovi nell'inventario
                if(og==49) //se lascio il motorino
                    salito=false;

                if (oggetti.get_oggetto(4).get_luogo() == 20 || oggetti.get_oggetto(11).get_luogo() == 20 ||
                     oggetti.get_oggetto(23).get_luogo() == 20 || oggetti.get_oggetto(25).get_luogo() == 20)
                {
                    // controllo che uno tra:tuta, casco, camice e manuale si trovi nello zaino
                    if(og == 4 || og == 11 || og == 23 || og == 25)
                    {
                        // controllo che l'oggetto sia proprio uno tra: tuta, casco, camice e manuale
                        if(oggetti.get_oggetto(og).get_luogo()== 0)
                        {
                            // controllo che l'oggetto si trovi nell'inventario
                            oggetti.set_luogo(og,luogo_attuale);
                            if(og==49) 		//se lascio il motorino
                                salito=false;
                            interfaccia.scrivi("Fatto.");
                            stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                            storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                        }
                        else
                        {
                            // controllo che l'oggetto si trovi nello zaino
                            int c,d;
                            c=z.leggipila(); //*
                            d=og;
                            if(og == oggetti.get_zaino2(c))
                            // controllo che l'oggetto sia il primo visibile nello zaino
                            {
                                oggetti.set_luogo(og,luogo_attuale);
                                z.fuoripila(); //*
                                n_oggettiZ--;
                                peso_MaxZ += oggetti.get_oggetto(og).get_peso();
                                interfaccia.scrivi("Fatto.");
                            }
                            else if(ins.appartiene(oggetti.get_valigia(d)))
                            // controllo che l'oggetto si trovi nella valigia
                            {
                                interfaccia.scrivi("- Non ce l'hai addosso e non sta nello zaino..");
                                interfaccia.scrivi(" (Suggerimento: controlla nella valigia)");
                                stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                                //Modifica PMF(storia)
                                storia_gioco.insStoria(stringa_comando, stringa_risposta);
                                //Modifica PMF(storia)
                            }
                            else if (!z.pilavuota())
                            // controllo che lo zaino non sia vuoto
                            {
                                interfaccia.scrivi("Devi prima lasciare: ");
                                oggetti.get_zaino(c);
                            }
                        }
                    }
                    else
                    {

                        oggetti.set_luogo(og,luogo_attuale);
                        interfaccia.scrivi("Fatto.");
                        stringa_risposta = "hai lasciato l'oggetto.";              	//Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                    }
                }
                else
                {

                    if(oggetti.get_oggetto(og).get_luogo() != 0)
                    // controllo che l'oggetto non si trovi nell'inventario
                    {
                        interfaccia.scrivi("- Non ce l'hai.");
                        stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                        //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);
                        //Modifica PMF(storia)
                    }
                    else
                    // controllo che l'oggetto si trovi nell'inventario
                    {

                        oggetti.set_luogo(og,luogo_attuale);
                        interfaccia.scrivi("Fatto.");
                        stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                    }
                }
            }
            else if(oggetti.get_oggetto(143).get_luogo() == 0)
            // controllo che la valigia si trovi nell'inventario
            {
                if(og==39) 										//se lascio il motorino
                    salito=false;
                if (oggetti.get_oggetto(4).get_luogo() == 20 || oggetti.get_oggetto(11).get_luogo() == 20 ||
                    oggetti.get_oggetto(23).get_luogo() == 20 || oggetti.get_oggetto(25).get_luogo() == 20)
                    // controllo che uno tra: tuta, casco, camice e manuale si trovi nella valigia
                {
                    if(og == 4 || og == 11 || og == 23 || og == 25)
                    // controllo che l'oggetto sia proprio uno tra: tuta, casco, camice e manuale
                    {
                        int c;
                        c=og;
                        if(oggetti.get_oggetto(og).get_luogo()== 0)
                        //controllo che l'oggetto si trovi nell'inventario
                        {
                            oggetti.set_luogo(og,luogo_attuale);
                            if(og==49) 				//se lascio il motorino
                                salito=false;
                            interfaccia.scrivi("Fatto.");
                            stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                            storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                        }
                        else if(!ins.appartiene(oggetti.get_valigia(c)))
                        // controllo che l'oggetto non si trovi nella valigia
                        {
                            if((oggetti.get_valigia(c))==(z.leggipila()))
                            // controllo che l'oggetto sia il primo visibile dello zaino
                            {
                                interfaccia.scrivi("- Non ce l'hai in valigia.");
                                stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                                //Modifica PMF(storia)
                                storia_gioco.insStoria(stringa_comando, stringa_risposta);
                                //Modifica PMF(storia)
                                interfaccia.scrivi(" (Suggerimento: controlla nello zaino)");
                            }
                            else if((oggetti.get_valigia(c))!=(z.leggipila()))
                            // controllo che l'oggetto non sia il primo visibile nello zaino
                                interfaccia.scrivi("- Non ce l'hai in valigia.");
                                stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                                //Modifica PMF(storia)
                                storia_gioco.insStoria(stringa_comando, stringa_risposta);
                                //Modifica PMF(storia)
                        }
                        else if(ins.appartiene(oggetti.get_valigia(c)))
                        // controllo che l'oggetto si trovi nella valigia
                        {
                            oggetti.set_luogo(og,luogo_attuale);
                            ins.cancella(oggetti.get_valigia(c));
                            n_oggettiZV--;
                            peso_MaxZV += oggetti.get_oggetto(og).get_peso();
                            interfaccia.scrivi("Fatto.");
                            stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                            storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                        }
                        else
                            interfaccia.scrivi("- Non ce l'hai in valigia.");
                        stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                        //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                    }
                    else
                    // dovrebbe riferirsi a chiave e secondo se stanno nell'inventario.
                    {
                        oggetti.set_luogo(og,luogo_attuale);
                        interfaccia.scrivi("Fatto.");
                        stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                    }
                }
                else
                {
                    if(oggetti.get_oggetto(og).get_luogo() != 0)
                    // controllo che l'oggetto non si trovi nell'inventario
                    {
                        interfaccia.scrivi("- Non ce l'hai.");
                        stringa_risposta = "non e' stato possibile perche' non avevi quell'oggetto.";
                        //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);
                        //Modifica PMF(storia)
                    }
                    else
                    {
                        oggetti.set_luogo(og,luogo_attuale);
                        interfaccia.scrivi("Fatto.");
                        stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                        storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                    }
                }
            }
            else
            {
                if(oggetti.get_oggetto(og).get_luogo() == 0)
                // controllo che l'oggetto si trovi nell'inventario
                {
                    oggetti.set_luogo(og,luogo_attuale);
                    if(og==39) 									//se lascio il motorino
                        salito=false;
                    interfaccia.scrivi("Fatto.");
                    stringa_risposta = "hai lasciato l'oggetto.";              //Modifica PMF(storia)
                    storia_gioco.insStoria(stringa_comando, stringa_risposta);	//Modifica PMF(storia)
                }
                /*else
                	interfaccia.scrivi("- Non ce l'hai.");*/
            }
        }
        else if ((luogo_attuale == 7 || luogo_attuale >= 9) && (oggetti.get_oggetto(4).get_luogo() != 0 ||
                oggetti.get_oggetto(11).get_luogo() != 0))
        {
            // controllo che il luogo attuale sia o 7 o qualsiasi luogo pari o superiore a 9 e che la tuta o
            // il casco non si trovino nell'inventario
            interfaccia.scrivi("\nAaaagh!!!");
            morto();
        }
        if (og == 67)
        {
            interfaccia.scrivi("Non puoi compiere questa azione!");
        }

    } //Fine modifica
    //Modifica PMF(ufficio)
    else
    {
        interfaccia.scrivi("Non puoi lasciarlo nell' ufficio.");
    }
    //Modifica PMF: fin qui.

}

/* 1950 - 1970
	4: guarda
*/
void Gioco::guarda()
{
    //if(luogo_attuale==6) luogo_attuale++; // Vaira - Rimosso: l'azione "guarda" eseguita su qualunque
    // oggetto della stanza iniziale
    // modifica la locazione attuale nel quale si trova il giocatore (portandolo nel "Compartimento stagno")
    interfaccia.scrivi("- Non noto nulla di particolare.");

    stringa_risposta = "non hai notato nulla di particolare.";    //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);   //Modifica PMF(storia)
}

/* 1980 - 2030
	5: save
*/
void Gioco::save_specifiche(ofstream &f) {}

void Gioco::save()
{
    int i;

    interfaccia.scrivi("Salvataggio partita...");
    ofstream file(fStringa.c_str(), ios::out);
    for (i = 1; i <= oggetti.get_n_oggettiZ(); i++)
    {
        file << oggetti.get_oggetto(i).get_luogo() << '\n';
    }
    file << luogo_attuale << '\n';
    file << tempo << '\n';
    file << passo_soluzione << '\n';

    //Modifiche_ML
    file << n_oggettiZ << '\n';
    file << peso_MaxZ << '\n';

    if(!(z.pilavuota()))  			 // controllo che lo zaino non sia vuoto
    {
        el1 = z.leggipila();
        z.fuoripila();
        if(!(z.pilavuota()))  		// controllo che lo zaino non sia vuoto
        {
            el2 = z.leggipila();
            z.fuoripila();
            z.inpila(el2);
        }
        z.inpila(el1);
    }
    file << el1 << '\n';
    file << el2 << '\n';

    file << n_oggettiZV << '\n';
    file << peso_MaxZV << '\n';
    if(!(ins.insiemevuoto()))  		//controllo che la valigia non sia vuota
    {
        if(ins.appartiene(50))  	// controllo che il casco sia presente nella valigia
        {
            el3 = 50;
        }
        file << el3 << '\n';
        if(ins.appartiene(51))  	// controllo che la tuta sia presente nella valigia
        {
            el4 = 51;
        }
        file << el4 << '\n';
        if(ins.appartiene(52))  	// controllo che il camice sia presente nella valigia
        {
            el5 = 52;
        }
        file << el5 << '\n';
        if(ins.appartiene(55))  	// controllo che il manuale sia presente nella valigia
        {
            el6 = 55;
        }
        file << el6 << '\n';
    }
    //Fine modifiche
    save_specifiche(file);
    salvaStatiDialoghi(); //modifiche D'Andria Dresda, metodo per salvare gli stati su file
    bacheca.SalvaBacheca(file);
    salvaJukeBoxLuci(); //modifiche VAcca - Salva lo stato del Jukebox e delle luci
    file.close();
    //INIZIO MODIFICHE CICALA GIACOMO
    for(int k=1; k<=31; k++)
        if(slotmachine.appartiene(k))
            numEuro++;

    file << numEuro << '\n';

    for(int j=1; j<=31; j++)
        if(slotmachine.appartiene(j))
            file << j << '\n';
    //FINE MODIFICHE CICALA GIACOMO
}

//MOIFICA VACCA GIANLUCA SALVA STATO LUCI E DEL JUKEBOX
//Salva lo stato del Jukebox e delle luci.
//Per il jukebox usa un intero per tenere traccia della “”posizione”” a cui l'utente si è fermato,
// mentre per le luci salverà sul file tutte le luci che, nel momento del salvataggio, appartengono all'insieme delle luci accesse
void Gioco::salvaJukeBoxLuci()
{
    ofstream nuovofile("JukeLuci.txt");
    nuovofile << canzoneInRiproduzione << '\n';


    for (int i = 0; i < sizeof(nome_luci_auditorium)/sizeof(nome_luci_auditorium[0]); i++)
    {

        luce.setNome(nome_luci_auditorium[i]);
        if (luciAuditoriumAccese.appartiene(luce))
        {
            nuovofile << '-' << nome_luci_auditorium[i] << '\n';
        }
    }
    nuovofile << '?';
    nuovofile.close();
}


//Modifica Vacca Gianluca
void Gioco::caricaJukeBoxLuci()
{
//RIPRISTINA LO STATO DEL JUKEBOX E DELLE LUCI ACCESE.
//COL PRIMO NUMERO SCRITTO NEL FILE SI VEDE QUANTE VOLTE BISOGNA ESEGUIRE L'OPERATORE SUCCLISTA (PARTENDO DAL PRIMO ELEMENTO)
//EVENTUALI STRINGHE SCRITTE INDICANO, INVECE, QUALI SONO LE LUCI CHE SONO STATE ACCESE, QUINDI VERRANNO INSERITE IMMEDIATAMENTE
//NELL'INSIEME DELLE LUCI ACCESE.
    ifstream file("JukeLuci.txt");
    string rigafile;
    getline(file,rigafile);

    canzoneScelta = canzoni.primolista();
    int puntoRipresaJuke =  atoi(rigafile.c_str() );
    for (int i = 0; i< puntoRipresaJuke; i++)
    {
        canzoneScelta = canzoni.succlista(canzoneScelta);
    }

    while(file.get()!='?')
    {
        getline(file,rigafile);
        luce.setNome(rigafile);
        if ( !luciAuditoriumAccese.appartiene(luce) )
        {
            luciAuditoriumAccese.inserisci(luce);

        }
    }
    file.close();
}

//FINE MODIFICHE VACCA

/* 2040 - 2090
	6: load
*/
void Gioco::load_specifiche(ifstream &f) {}


//aggiunta D'Andria Dresda al progetto di Federica Forte
void Gioco::salvaStatiDialoghi()
{
    ofstream nuovofile("Astrostatidialoghi.txt");
    ifstream file("Statidialoghi.txt");
    string rigafile;
    while(file.get()!='?')
    {
        getline(file,rigafile);
        nuovofile << '-' << rigafile << '\n';
    }
    nuovofile << '?';
    file.close();
    nuovofile.close();
}
//fine aggiunta





void Gioco::load()
{
    int i;
    int valore;
    int slot; //CICALA GIACOMO
    svuotaInsieme(slotmachine); //CICALA GIACOMO

    ifstream file(fStringa.c_str(), ios::in);
    //modifiche effettuate da D'Andria Dresda sul controllo del caricamento da file
    ifstream astrostatidialoghi("Astrostatidialoghi.txt");
    bool astrostatidialoghiaperto=astrostatidialoghi.good();
    bool fileaperto=file.good();
    if(fileaperto || astrostatidialoghiaperto)
    {

        interfaccia.scrivi("Ripristino partita...");
        if(fileaperto)
        {
            for (i = 1; i <= oggetti.get_n_oggetti(); i++)
            {
                file >> valore;
                oggetti.set_luogo(i,valore);
            }
            file >> luogo_attuale;
            file >> tempo;
            file >> passo_soluzione;

            while(!(z.pilavuota())) 							//controllo che lo zaino non sia vuoto
                z.fuoripila();
            file >> n_oggettiZ;
            file >> peso_MaxZ;
            file >> el1;
            file >> el2;
            if(el2 !=0)
                z.inpila(el2);
            if(el1 !=0)
                z.inpila(el1);

            file >> n_oggettiZV;
            file >> peso_MaxZV;
            file >> el3;
            file >> el4;
            file >> el5;
            file >> el6;
            if((!(ins.appartiene(el3))) && el3 != 0)
                ins.inserisci(el3);
            if((!(ins.appartiene(el4))) && el4 != 0)
                ins.inserisci(el4);
            if((!(ins.appartiene(el5))) && el5 != 0)
                ins.inserisci(el5);
            if((!(ins.appartiene(el6))) && el6 != 0)
                ins.inserisci(el6);
            //Fine ML

            load_specifiche(file);
            bacheca.CaricaBacheca(file);
            file.close();
        }
        if(astrostatidialoghiaperto)
        {
            caricaStatiDialoghi(); //modifiche D'Andria Dresda
        }
        ifstream jukeLuci("JukeLuci.txt");
        if (jukeLuci.good() )
        {
            caricaJukeBoxLuci();
        }

    }
    else
    {
        interfaccia.scrivi("Non ci sono partite salvate!");
    }
    //INIZIO MODIFICHE CICALA GIACOMO
    file >> numEuro;

    for(int j=1; j<=numEuro; j++)
    {
        file >> slot;
        slotmachine.inserisci(slot);
    }
    //fine modifiche CICALA GIACOMO
}
/* 2100 - 2120
	7: cosa
*/


//aggiunta D'Andria Dresda al progetto di Federica Forte
void Gioco::caricaStatiDialoghi()
{
    ifstream file("Astrostatidialoghi.txt");
    ofstream nuovofile("Statidialoghi.txt");
    string rigafile;
    while(file.get()!='?')
    {
        getline(file,rigafile);
        nuovofile << '-' << rigafile << '\n';
    }
    nuovofile << '?';
    file.close();
    nuovofile.close();
}
//fine aggiunta



/* 2130 - 2150 ; 2160 - 2180
	8: ; 9: vuota
*/
void Gioco::indietro(Pila<stato_comando>* p)
{
    int j=0;

    if (!p->pilavuota())  //*
    {
        interfaccia.scrivi("Hai scelto di annullare il comando:");
        string s = p->leggipila().get_comando();
        interfaccia.scrivi(/*p->leggipila().get_comando()*/ s);
        Stato s2 = p->leggipila().get_stato();
        p->fuoripila();
        while (!s2.stato_completo() && !p->pilavuota())
        {
            s2.unisci(p->leggipila().get_stato());
            p->fuoripila();
            k--;
        }



        //p->fuoripila();
        //c->inverti_coda();
        luogo_attuale=s2.get_luogo();
        passo_soluzione=s2.get_passo();
        tempo= s2.get_tempo();

        for (int i = 1; i <= oggetti.get_n_oggetti(); i++)
        {
            //cicla per i che va 1 a 24(la funzione che ti restituisce il numero totale di oggetti)
            oggetti.set_luogo(i,s2.get_ogg()[j]);
            j++;
        }

        setCabina(s2.get_cabina());
        setParete(s2.get_parete_stagna());
        //p->fuoripila();
        k--;
        //c->inverti_coda();
    }
    else
    {
        interfaccia.scrivi("Non puoi tornare indietro, digita un nuovo comando");
    }

    stringa_risposta = "hai annullato l'ultimo comando digitato.";  //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);	     //Modifica PMF(storia)

}

/* 1680 - 1750
	Esegue azione a
*/
bool Gioco::esegui_specifiche(int, Mappa &)
{
    return true;
}

//MODIFICA D-R(D-R): Metodo usato in sostituzione di esegui nel caso si voglia procedere in assenza di Enigmi
void Gioco::switch_enigmi(int a, Mappa &M, Pila<stato_comando>* p, Personaggi* pg)  // modifica zagaria -- aggiunto il paramentro per la gestione dei personaggi
{
    bool parlato; //modifica D'Andria Dresda al progetto di Federica Forte
    if(leggienigma())
    {
        cout<<"\nComplimenti hai indovinato l'enigma puoi proseguire" << endl;
        cout<<"\n";
        //Modifica Pmf: fin qui.
        //INIZIO MODIFICA MICHELE ALBANO
        if(!sFisico.feritaEvitata(rand()))//Modifica DAVIDE MANTELLINI
        {
            Aggiorna_Ferite(); //Generatore Ferite
        }
        if(Salute.GetStatoSalute()==0) //Se lo Stato della Salute è a 0, fine dell'avventura
            morto();
        interfaccia.a_capo();
        //FINE MODIFICA MICHELE ALBANO

        switch (a)
        {
        case 1:
            parlato=false; //aggiunta D'Andria Dresda dal progetto di Gallo in quello di Federica Forte
            direzioni(M);
            break;

        case 2:
            prendi();
            break;
        case 3:
            lascia();
            break;
        case 4:
            guarda();
            break;
        case 5:
            save();
            break;
        case 6:
            load();
            break;
        case 7:
            cosa();
            break;
        case 8:
            navigatore(M);
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            break;
        case 9:
            indietro(p);
            break;
        case 39:
            macchinadeltempo();
            break;
        //aggiunta D'Andria Dresda dal progetto di Federica Forte
        case 99:
            if(parlato==true)
            {
                cout<<"Ci hai gia' parlato"<<endl;
            }
            else
            {
                az_parla(*pg);
                if(pg->getNome()!="Cid" && pg->getNome()!="Vincent" && pg->getNome()!="Kail") //modifica D'Andria Dresda
                {
                    parlato=true;
                }
            }
            break;
        //fine aggiunta D'Andria Dresda

        case 40:
            visualizza_bacheca();
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            break;
        case 41:
            benzina();
            break;
        case 42:
            usa_motorino();
            break;

        // inizio modifiche zagaria
        case 43:
            stringa_risposta = "Hai parlato con il personaggio presente nella stanza."; //aggiungo alla storia
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            az_parla(*pg);
            break;                          //fine modifiche

        //Modifica PMF(agenda)
        case 46:
            azione_46();
            break;
        case 47:
            azione_47();
            break;
        case 48:
            azione_48();
            break;
        //Modifica PMF: fin qui.

        //START DAMONE
        //Modifica Francesco De Giorgio
        case 49:
            consulta();//inserita la consultazione della guida
            //Modifica De Giorgio : fin qui.
            break;
        //END DAMONE


        default: // AZIONI SPECIFICHE
            if (!esegui_specifiche(a,M))
                interfaccia.scrivi("AZIONE " + a); // test
        }
    }
    //Modifica PMF(enigmi)
    else
    {
        cout << "\nHai sbagliato la risposta stai perdendo tempo," << endl;
        cout <<"ridigita il comando per avere un altro enigma" << endl;
        tempo--;
    }
}


void Gioco::esegui(int a, Mappa &M, Pila<stato_comando>* p, bool si, Personaggi* pg) // MODIFICA zagaria -- modifica della funzione esegui con l' aggiunta del parametro personaggi
{

    if(si)
    {
        switch_enigmi(a,M,p,pg); // modifica zagaria -- aggiunto il parametro pg
    }
    else
    {
        bool parlato; //Aggiunta D'Andria Dresda
        //INIZIO MODIFICA MICHELE ALBANO
        Aggiorna_Ferite(); //Generatore Ferite
        if(Salute.GetStatoSalute()==0) //Se lo Stato della Salute è a 0, fine dell'avventura
            morto();
        interfaccia.a_capo();
        //FINE MODIFICA MICHELE ALBANO
        switch (a)
        {
        case 1:
            parlato = false; //Aggiunta D'Andria Dresda
            direzioni(M);
            break;
        case 2:
            prendi();
            break;
        case 3:
            //modifiche CHIARAPPA ROSA
            //ruba();
            lascia();
            break;
        case 4:
            guarda();
            break;
        case 5:
            save();
            break;
        case 6:
            load();
            break;
        case 7:
            cosa();
            break;
        case 8:
            navigatore(M);
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            break;
        case 9:
            indietro(p);
            break;
        case 10:
            lascia();
            break;
        case 11:     //modifiche CHIARAPPA ROSA
            rubati();
            break;
        case 39:
            macchinadeltempo();
            break;
        //aggiunta D'Andria Dresda
        case 99:
            if(parlato==true)
                cout<<"Ci hai gia' parlato"<<endl;
            else
            {
                az_parla(*pg);
                if(pg->getNome()!="Cid" && pg->getNome()!="Vincent" && pg->getNome()!="Kail") //modifica D'Andria Dresda
                {
                    parlato=true;
                }
            }
            break;
        //fine aggiunta D'Andria Dresda
        case 40:
            visualizza_bacheca();
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            break;
        case 41:
            benzina();
            break;
        case 42:
            usa_motorino();
            break;

        // inizio modifiche zagaria -- definisce la comunicazione con il personaggio nella storia
        case 43:
            stringa_risposta = "Hai parlato con il personaggio presente nella stanza."; //aggiungo alla storia
            storia_gioco.insStoria(stringa_comando, stringa_risposta);
            az_parla(*pg);
            break;                  //fine modifiche

        //Modifica PMF(agenda)
        case 46:
            azione_46();
            break;
        case 47:
            azione_47();
            break;
        case 48:
            azione_48();
            break;
        //Modifica PMF: fin qui.
//START DAMONE
        //Modifica Francesco De Giorgio
        case 49:
            consulta();//inserita la consultazione della guida
            //Modifica De Giorgio : fin qui.
            break;
        //END DAMONE

        default: // AZIONI SPECIFICHE
            if (!esegui_specifiche(a,M))
            {
                interfaccia.scrivi("AZIONE " + a); // test
            }
        }
    }
}


/* 470 - 550
	Esegue azione a, a=0 se non trovata
*/
bool Gioco::esegui_azione(int azione,int c2, Mappa &M,Pila<stato_comando>* p, bool si, Personaggi* pg) // MODIFICA Zagaria -- aggiunta alla funzione esegui azione il parametro personaggi pg
{
    int cod_azione = 0; // codice azione

    if (azioni.appartiene(azione))
    {
        cod_azione = azioni.recupera(azione);
        if (cod_azione != 0)
        {
            if (c2 == 0 || cod_azione > 0) // solo verbo o no test
            {
                esegui(cod_azione, M,p,si,pg); // esegue // MODIFICA Zagaria -- aggiunto il parametro pg
            }

            else
            {
                if (og == 0)
                {
                    interfaccia.scrivi("- Qui non c'e'.");

                    stringa_risposta = "non hai trovato l'oggetto.";            //Modifica PMF(storia)
                    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

                }
                else
                    esegui(-cod_azione, M,p,si,pg); // esegue // modifica zagaria
            }
            cod_azione = 1;
        }
        return true;
    }
    else
        return false;
}

//

/* 680 - 730
	Main (parser)
	Main (parser)
*/
void Gioco::interpreta(string comando, Mappa &M,Pila<stato_comando>* p, Stato s, bool si)
{
    int lungh_comando;  // lunghezza comando
    int in; 			// posizione iniziale di scansione del comando alla ricerca di una parola
    string parola1;     // prima parola comando

    //string parola2;  // seconda parola comando // MODIFICA Zagaria aggiunto commento della parola 2 che prima non era commentata
    int cod_parola2;    // codice seconda parola comando
    int n1, n2;         // variabili temporanee per costruire il codice comando
    bool eseguito;      // indica se azione eseguita

    stringa_comando = comando; //Modifica PMF(storia)

    lungh_comando = comando.length();
    in = 0;
    cod_parola1 = estraipar(comando, lungh_comando, &in, &parola1);
    if(cod_parola1!=72&&cod_parola1!=19&&cod_parola1!=11&&cod_parola1!=12&&cod_parola1!=13)
        memorizza_comandi(comando,p,s); //*
    if (parola1[0] == '\0')
    {
        interfaccia.scrivi("- Beh?");
    }
    else if (lungh_comando > 2 && (( parola1.substr(in-3, 3) == "are") ||  parola1.substr(in-3, 3) == "ere"))
    {
        interfaccia.scrivi("- Dammi del tu, per favore.");

        stringa_risposta = "il sistema ti ha chiesto gentilmente di dargli del tu."; //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

    }
    else if (cod_parola1 == 0 && parola1[0] != '\0')
    {

        interfaccia.scrivi("- Non conosco il verbo '" + parola1 + "'.");

        stringa_risposta = "il sistema non ha riconosciuto il verbo '" + parola1 + "'.";//Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)

    }
    else
    {

        cod_parola2 = estraipar(comando, lungh_comando, &in, &parola2);
        // MODIFICA D-R(D'Orsi):Negozio + Banca
        // IN OGNI CASO OTTENGO IL COCICE DELL' OGGETTO INSERITO
        comando_oggetto = cod_parola2;
        //                      //


        if (cod_parola2 == 0 && parola2[0] != '\0' && parola1 != "codice")
        {
            interfaccia.scrivi("- Non conosco la parola '" + parola2 + "'.");

            stringa_risposta = "il sistema non ha riconosciuto la parola '" + parola2 + "'.";  //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);                         //Modifica PMF(storia)

        }
        else     // comando valido
        {
            if (cod_parola2 != 0)
                og = oggetti.luogo_oggetto(cod_parola2, luogo_attuale);                   // og = indice: gosub 650
            n1 = luogo_attuale * 100000000;                                                       // MODIFICA POLIMENA
            n2 = cod_parola1 * 10000;                                                           // MODIFICA POLIMENA
            eseguito = esegui_azione(n1 + n2 + cod_parola2, cod_parola2, M,p,si, &pg);      // verbo + nome in lu // gosub 500 // MODIFICA Zagaria -- aggiunto il parametro pg alla funzione esegui azione
            if (!eseguito && cod_parola2 != 0)
                eseguito = esegui_azione(n1 + n2 + 9999, cod_parola2, M,p,si, &pg);          // verbo + x in lu // gosub 500  MODIFICA Zagaria -- aggiunto il parametro pg alla funzione esegui azione
            if (!eseguito)
                eseguito = esegui_azione(n2 + cod_parola2, cod_parola2, M,p,si, &pg);       // verbo + nome generico // gosub 500  MODIFICA Zagaria -- aggiunto il parametro pg alla funzione esegui azione
            if (!eseguito && cod_parola2 != 0)
                eseguito = esegui_azione(n2 + 9999, cod_parola2, M,p,si, &pg);           // verbo + x generico // gosub 500  MODIFICA Zagaria -- aggiunto il parametro pg alla funzione esegui azione
            if(parola1 == "codice" && cod_parola2 == 0)
                eseguito = esegui_azione(n1+n2+9999,cod_parola2, M,p,si, &pg);  	    //Riconosce qualunque codice errato  MODIFICA Zagaria -- aggiunto il parametro pg alla funzione esegui azione
            if (!eseguito)
            {
                interfaccia.scrivi("- Non capisco.");
                stringa_risposta = "il sistema non ha capito.";          //Modifica PMF(storia)
                storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
            }
        }
    }
}

//Modifica PMF(storia)
Storia Gioco::stampaStoria()
{
    return storia_gioco;
} //Modifica PMF: fin qui.

void Gioco::ciak(Mappa &M, ifstream&)
{

    string comando;
    Luogo l;
    Stato s; //*
    mappa = M;
    bool si;
    int countComandi;  //modifiche ROSA CHIARAPPA


    //Pila <string>* p = new Pila <string>();
    Pila <stato_comando>* p = new Pila <stato_comando>();


    do
    {
        countComandi = 0; //modifiche ROSA CHIARAPPA
        svuotaPila(*p);
        init();
        introduzione();

        initPers(&insPersonaggi);

        interfaccia.pausa(); // <SP>
        si = attiva_enigmi(); // MODIFICA D-R(D-R)

        do   // ciclo di gioco
        {



            //INIZIO MODIFICA MARCO DAMONE
            //RIMOZIONE DELLE SOTTOSTANTI LINEE DI CODICE
            //if(luogo_attuale==6 && mappaaperta())
            //luogo_attuale++;
            //FINE MODIFICA MARCO DAMONE
            if(mappa.get_nome_luogo(luogo_attuale) == "Luogotrasporto")
            {
                trasporto(luogo_attuale);
                stringa_risposta = "sei andato " + mappa.get_nome_luogo(luogo_attuale) + ".";  //Modifica PMF(storia)
                storia_gioco.insStoria(stringa_comando, stringa_risposta);
            }
            l=mappa.get_luogo(luogo_attuale);
            if((!Luogo_p.pilavuota()) && (Codice_luogo.leggipila()!=luogo_attuale))                                                                                     //MODIFICA POLIMENA
            {
                cout<<"Provieni dal luogo: "<< Codice_luogo.leggipila() << ": "<< Luogo_p.leggipila();                    // MODIFICA POLIMENA
            }
            Luogo_p.inpila(mappa.get_nome_luogo(luogo_attuale));                                                            //MODIFICA POLIMENA
            Codice_luogo.inpila(luogo_attuale);                                                                             //MODIFICA POLIMENA

            if(luogo_attuale == 7)
            {
                if(oggetti.get_oggetto(4).get_luogo() != 0 || oggetti.get_oggetto(11).get_luogo()!= 0)
                    bacheca.NuovoMessaggioGioco("*non uscire fuori dall'astronave se non hai l'equipaggiamento da astronauta");
                //else
                //bacheca.CancellaMessaggioGioco("*non uscire fuori dall'astronave se non hai l'equipaggiamento da astronauta");
            }
            // MODIFICA D-R(Colturi):Luoghi a Pagamento----------
            if(luogo_attuale > 15)                             //|
            {
                //|
                //Luogo l = M.get_luogo(luogo_attuale);         //|
                //|
            }                                                  //|
            // FINE MODIFICA D-R---------------------------------
            interfaccia.disegna_scena(l);

            personaggio_entra(); //  modifica zagaria

            //if ()
            interfaccia.elenca_oggetti(oggetti.posizionati_in(luogo_attuale), "Vedo:");
            //else
            aggiorna_premi();//modifiche Francesco Cosma - Premi
            aggiorna_specifiche();//biblioteca
            aggiorna_tempo();



            //inizio modifiche ROSA CHIARAPPA
            aggiorna_luogo_carabiniere(countComandi);
            if (verifica_presenza_carabiniere(luogo_attuale))
            {
                perquisizione_giocatore(luogo_attuale);
            }
            //fine modifiche ROSA CHIARAPPA




            comando = interfaccia.leggi_comando();
            interpreta(comando,M,p,s,si);
            aggiorna_progresso();//modifiche Francesco Cosma - Premi

            countComandi++; //modifiche ROSA CHIARAPPA
        }
        while(!fine_partita);
    }
    while (riparti);
}

//MODIFICA D-R(D-R): Attiva/Disattiva Enigmi
bool Gioco::attiva_enigmi()
{
    bool si = false;
    string sn ="";
    interfaccia.scrivi("Benvenuto : Vuoi che durante il gioco gli Enigmi siano attivi? ");
    interfaccia.scrivi("[S/N] ?? : ");
    cin >> sn;

    if ((sn == "S")||(sn == "s"))
    {
        interfaccia.scrivi("Hai scelto di proseguire CON gli Enigmi");
        system("cls");
        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        si = true;
    }
    else if((sn == "N")||(sn == "n"))
    {
        interfaccia.scrivi("Hai scelto di proseguire SENZA gli Enigmi ");
        //////system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        si = false;
    }
    else
    {
        interfaccia.scrivi(" ... Non capisco!");
        interfaccia.scrivi(" digita una risposta valida ...");
        interfaccia.a_capo();
        attiva_enigmi();
    }


    return si;
}

void Gioco::navigatore(Mappa& M)
{
    char orizz=205,vert=186,as=201,bs=200,ad=187,bd=188; //caratteri per la stampa delle cornici
    int scelta;

    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi("Connessione al server dell'astronave in corso ...");
    Sleep(850);
    interfaccia.scrivi("Connessione avvenuta");
    Sleep(450);
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI

    M.set_partenza_gioco(luogo_attuale);
    M.set_destinazione_gioco();             // setta la destinazione al luogo fittizio nel caso il navigatore fosse richiamato più volte

    do
    {
        system("cls");
        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        fflush(stdin);
        interfaccia.scrivi("Menu' del navigatore");
        interfaccia.scrivi_carattere(as);
        for (int i=0; i<98; i++)
            interfaccia.scrivi_carattere(orizz);
        interfaccia.scrivi_carattere(ad);
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_parziale(" 1) Seleziona il luogo che si desidera raggiungere                                                ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_parziale(" 2) Calcola il percorso da effettuare                                                             ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_parziale(" 0) Per disconnetterti dal Navigatore                                                             ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        for (int i=0; i<98; i++)
            interfaccia.scrivi_parziale("_");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        for (int i=0; i<98; i++)
            interfaccia.scrivi_parziale(" ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_parziale(" Luogo in cui ti trovi : \t");
        interfaccia.scrivi_parziale(M.get_nome_luogo(luogo_attuale));
        for (unsigned int i=0; i<98-(31+M.get_nome_luogo(luogo_attuale).length()); i++)
            interfaccia.scrivi_parziale(" ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_parziale(" Luogo che vuoi raggiungere : \t");
        interfaccia.scrivi_parziale(M.legginomearrivo());
        for (unsigned int i=0; i<98-(31+M.legginomearrivo().length()); i++)
            interfaccia.scrivi_parziale(" ");
        interfaccia.scrivi_carattere(vert);
        interfaccia.scrivi_carattere(bs);
        for (int i=0; i<98; i++)
            interfaccia.scrivi_carattere(orizz);
        interfaccia.scrivi_carattere(bd);
        interfaccia.a_capo();
        interfaccia.scrivi_parziale(" Seleziona l'operazione :");
        cin>>scelta;
        if (cin.fail())
        {
            scelta=2;
            cin.clear();
        }
        switch (scelta)
        {
        case 0:
            interfaccia.scrivi(" Disconnessione in corso ...");
            Sleep(850);
            break;
        case 1:
            M.scriviarrivo();
            break;
        case 2:
            M.cammino_ottimo();
            //system("pause");
            break;
        default:
            interfaccia.scrivi(" Input non valido, inserire un input corretto");
            interfaccia.scrivi(" ");
            //system("pause");
            break;
        }
    }
    while (scelta!=0);
    system("cls");
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI

    stringa_risposta = "hai utilizzato il navigatore di bordo per orientarti meglio nell'astronave."; //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

void Gioco::aggiorna_specifiche()
{
}

void Gioco::setCabina(int) {} //*
void Gioco::setParete(int) {} //*
int Gioco::getCabina() {} //*
int Gioco::getParete() {} //*

void Gioco::macchinadeltempo()
{
    int scelta;
    do
    {
        interfaccia.scrivi("Questo orologio ti permette di muoverti nel tempo!");
        interfaccia.scrivi("Decidi dove andare:");
        interfaccia.scrivi(" 1) Passato");
        interfaccia.scrivi(" 2) Futuro");
        interfaccia.scrivi(" 0) Presente");
        interfaccia.scrivi(" Seleziona l'operazione :");
        cin>>scelta;
        switch (scelta)
        {
        case 0:
            presente();
            Sleep(850);
            break;
        case 1:
            passato();
            break;
        case 2:
            interfaccia.pausa();
            futuro();
            break;
        default:
            interfaccia.scrivi("SCELTA NON VALIDA!");
            scelta = -1;
            break;
        }

    }
    while (scelta == -1);
}

void Gioco::memorizza_comandi(string comando, Pila<stato_comando>* p, Stato s)   //*
{
    //INIZIO MODIFICA DAMONE MARCO
    //VARIAZIONE DIMENSIONE VETTORE ELEM IN QUANTO MAL DIMENSIONATO GENERANDO BUG INERENTI ALLA GESTIONE DEGLI ITEMS DI GIOCO
    int elem[oggetti.get_n_oggetti()];
    //FINE MODIFICA DAMONE MARCO
    int j=0;
    stato_comando sc;
    k++;
    //p->inpila(comando);

    sc.set_comando(comando);

    s.set_luogo(luogo_attuale);
    s.set_cabina(getCabina());
    s.set_parete_stagna(getParete());
    s.set_passo(passo_soluzione);
    s.set_tempo(tempo);

    for (int i=1; i<=oggetti.get_n_oggetti(); i++)
    {
        elem[j]=oggetti.get_oggetto(i).get_luogo();
        j++;
    }

    s.set_ogg(elem);



    if (!completo && !p->pilavuota())
    {
        s.differenza(p->leggipila().get_stato(), oggetti.get_n_oggetti());
    }

    sc.set_stato(s);

    if (k<=MAXPILA) //  se k è minore di un certo parametro inpila altrimenti cancella e poi inpila
        p->inpila(sc);    //
    else
    {
        //p->fuoripila();
        correggi_Pila(p);
        p->inpila(sc);    //
    }


}

void Gioco::correggi_Pila (Pila <stato_comando>* pi)
{
    stato_comando s1;    //Sc più recente nella pila
    stato_comando s2;    //Sc centrale nella pila
    s1 = pi->leggipila();  //Estraggo lo sc più recente e lo salvo
    pi->fuoripila();  //Lo elimino dalla pila per accedere ai successivi
    s2 = pi->leggipila(); //Salvo lo sc centrale
    pi->fuoripila();  //Elimino lo sc centrale per accedere al meno recente


    if (!completo)
        s2.get_stato().unisci(pi->leggipila().get_stato()); //Solo nel caso degli stati non completi devo assicurarmi che s2 (futuro stato meno recente) sia uno stato completo. Lo unisco quindi con l'ultimo della pila che è sicuramente completo
    pi->fuoripila(); //Elimino definitivamente lo sc meno recente
    pi->inpila(s2); //Inpilo s2 che ora è diventato completo
    pi->inpila(s1); //Inpilo s1,ex stato più recente. quindi c'è spazio ora per il nuovo sc


}




//Inizio modifiche zagaria  <Personaggi> *insPersonaggi) -- aggiunte le funzioni per la gestione dei personaggi
void Gioco::initPers(Dizionario<int, Personaggi> *insPersonaggi)
{

    Personaggi p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23/*,p24,p25,p26,p27,p28,p29,p30*/,
               p31,p32,p33,/*p34,p35,p36,p37,p38,p39,p40,*/p41,p42,p43,/*p44,p45,p46,p47,p48,p49,p50,*/p51,p52,p53,/*p54,p55,p56,p57,p58,p59,p60,*/
               p61,p62,p63,/*p64,p65,p66,p67,p68,p69,p70,*/p71,p72,p73,/*p74,p75,p76,p77,p78,p79,p80,*/p81,p82,p83,/*p84,p85,p86,p87,p88,p89,p90,*/
               p91,p92,p93/*,p94,p95,p96,p97,p98,p99,p100*/, p101;

    //AGGIUNTA DEI PERSONAGGI PER I DIALOGHI BASILE ANTONIO
    Personaggi prof_Mara, prof_Clara, alunno_Davide;

    //Luogo 1 1-10

    p1.setNome("Kain");
    p1.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p1.setLuogo(1);
    insPersonaggi->inserisci(1, p1);
    p2.setNome("Tom");
    p2.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p2.setOgg(true,51);
    p2.setFrasiconOgg1("Visto che hai la tuta puoi andare, qui non c'e' altro di importante","Controla tutti gli indicatori e i pulsanti, potrebbero mostrarti qualcosa di utile");
    p2.setLuogo(1);
    insPersonaggi->inserisci(2, p2);
    p3.setNome("Jim");
    p3.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p3.setLuogo(1);
    insPersonaggi->inserisci(3, p3);
    p4.setNome("Adam");
    p4.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p4.setOgg(true,51);
    p4.setFrasiconOgg1("Visto che hai la tuta puoi andare, qui non c'e' altro di importante","Controlla tutti gli indicatori e i pulsanti, potrebbero mostrarti qualcosa di utile");
    p4.setLuogo(1);
    insPersonaggi->inserisci(4, p4);
    p5.setNome("Paul");
    p5.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p5.setLuogo(1);
    insPersonaggi->inserisci(5, p5);
    p6.setNome("Raoul");
    p6.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p6.setOgg(true,51);
    p6.setFrasiconOgg1("Visto che hai la tuta puoi andare, qui non c'e' altro di importante","Controlla tutti gli indicatori e i pulsanti, potrebbero mostrarti qualcosa di utile");
    p6.setLuogo(1);
    insPersonaggi->inserisci(6, p6);
    p7.setNome("Max");
    p7.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p7.setLuogo(1);
    insPersonaggi->inserisci(7, p7);
    p8.setNome("Sam");
    p8.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p8.setOgg(true,51);
    p8.setFrasiconOgg1("Visto che hai la tuta puoi andare, qui non c'e altro di importante","Controlla tutti gli indicatori e i pulsanti, potrebbero mostrarti qualcosa di utile");
    p8.setLuogo(1);
    insPersonaggi->inserisci(8, p8);
    p9.setNome("Yan");
    p9.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p9.setLuogo(1);
    insPersonaggi->inserisci(9, p9);
    p10.setNome("Arthur");
    p10.setFrasi("Prendi la 'Tuta' potrebbe servirti","La 'Tuta' e' inutile, lasciala li");
    p10.setOgg(true,51);
    p10.setFrasiconOgg1("Visto che hai la tuta puoi andare, qui non c'e altro di importante","Controlla tutti gli indicatori e i pulsanti, potrebbero mostrarti qualcosa di utile");
    p10.setLuogo(1);
    insPersonaggi->inserisci(10, p10);

    //Luogo 2 11-20
    p11.setNome("Cloud");
    p11.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p11.setLuogo(2);
    insPersonaggi->inserisci(11, p11);
    p12.setNome("Cole");
    p12.setFrasi("Controlla la 'Cabina del secondo pilota', potresti trovare qualcosa di utile","La 'Cabina del secondo pilota' e vuota, e inutile entrarci");
    p12.setLuogo(2);
    insPersonaggi->inserisci(12, p12);
    p13.setNome("Zack");
    p13.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p13.setOgg(true,55);
    p13.setFrasiconOgg1("Hai il 'manuale',il reattore deve essere spento, svelto","Il 'manuale' non ti servira' a nulla, lascialo e cerca una soluzione al problema");
    p13.setLuogo(2);
    insPersonaggi->inserisci(13, p13);
    p14.setNome("Getro");
    p14.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p14.setLuogo(2);
    insPersonaggi->inserisci(14, p14);
    p15.setNome("Leroy");
    p15.setFrasi("Controlla la 'Cabina del secondo pilota', potresti trovare qualcosa di utile","La 'Cabina del secondo pilota' e' vuota, e inutile entrarci");
    p15.setLuogo(2);
    insPersonaggi->inserisci(15, p15);
    p16.setNome("Tony");
    p16.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p16.setOgg(true,55);
    p16.setFrasiconOgg1("Hai il 'manuale',il reattore deve essere spento, svelto","Il 'manuale' non ti servira' a nulla, lascialo e cerca una soluzione al problema");
    p16.setLuogo(2);
    insPersonaggi->inserisci(16, p16);
    p17.setNome("Timmy");
    p17.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p17.setLuogo(2);
    insPersonaggi->inserisci(17, p17);
    p18.setNome("Eric");
    p18.setFrasi("Controlla la 'Cabina del secondo pilota', potresti trovare qualcosa di utile","La 'Cabina del secondo pilota' e vuota, e inutile entrarci");
    p18.setLuogo(2);
    insPersonaggi->inserisci(18, p18);
    p19.setNome("Dan");
    p19.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p19.setOgg(true,55);
    p19.setFrasiconOgg1("Hai il 'manuale',il reattore deve essere spento, svelto","Il 'manuale' non ti servira' a nulla, lascialo e cerca una soluzione al problema");
    p19.setLuogo(2);
    insPersonaggi->inserisci(19, p19);
    p20.setNome("Chuck");
    p20.setFrasi("La 'tuta' dovrebbe trovarsi nella 'Cabina di pilotaggio'","La 'tuta' si trova nella 'sala di controllo del reattore'");
    p20.setLuogo(2);
    insPersonaggi->inserisci(20, p20);

    //luogo 3 21-30
    p21.setNome("Vincent");
    p21.setFrasi("A nord trovi la 'Cabina di pilotaggio'","A sud trovi la 'Cabina di pilotaggio'");
    p21.setLuogo(3);

    //modifiche D'Andria Dresda aggiunta dialogo a Vincent
    Dialogo dialogovincent=Dialogo("Vincent");
    dialogovincent=caricaDialoghiDaFile("Vincent");
    p21.setDialogo(&dialogovincent);

    //fine modifiche
    insPersonaggi->inserisci(21, p21);
    p22.setNome("Kail");
    p22.setFrasi("A sud trovi 'il compartimento stagno' e la 'sala del reattore'","A sud trovi la 'Cabina di pilotaggio'");
    p22.setLuogo(3);
    //modifiche D'Andria Dresda aggiunta dialogo a Vincent
    Dialogo dialogokail=Dialogo("Kail");
    dialogokail=caricaDialoghiDaFile("Kail");
    p22.setDialogo(&dialogokail);
    //fine modifiche

    insPersonaggi->inserisci(22, p22);

    p23.setNome("Joe");
    p23.setFrasi("Cerca il 'casco'","Il 'casco' e inutile");
    p23.setOgg(true,50,51);
    p23.setFrasiconOgg1("Cerca la 'tuta'","la 'tuta' non ti serve");
    p23.setFrasiconOgg2("Cerca il 'secondo pilota'","Il 'secondo pilota' e nella sua cabina");
    p23.setLuogo(3);
    insPersonaggi->inserisci(23, p23);

    //luogo 4 31-40
    p31.setNome("Garnet");
    p31.setFrasi("Ho visto il 'secondo pilota' andare verso il 'compartimento stagno' a est","Il secondo pilota non e' passato di qui");
    p31.setLuogo(4);
    insPersonaggi->inserisci(31, p31);
    p32.setNome("Shaun");
    p32.setFrasi("Ho visto il 'secondo pilota' andare verso il 'compartimento stagno' a est","Il secondo pilota non e' passato di qui");
    p32.setOgg(true,50,51);
    p32.setFrasiconOgg1("Cerca la 'tuta' prima di uscire dall'astronave","Corri nel 'compartimento stagno' e cerca il 'secondo pilota'");
    p32.setFrasiconOgg2("Corri nel 'compartimento stagno' e cerca il 'secondo pilota'","Lascia la 'tuta' prima di andare");
    p32.setLuogo(4);
    insPersonaggi->inserisci(32, p32);
    p33.setNome("Frank");
    p33.setFrasi("Ho visto il 'secondo pilota' andare verso il 'compartmento stagno' a est","Il secondo pilota non e' passato di qui");
    p33.setOgg(true,54);
    p33.setFrasiconOgg1("Vai nella 'cabina del secondo pilota'","La 'Chiave' che hai preso non va bene, cercane un altra");
    p33.setLuogo(5);
    insPersonaggi->inserisci(33, p33);

    //luogo 5 41-50
    p41.setNome("Cecil");
    p41.setFrasi("La 'Chiave' la possiede il 'secondo pilota', cercalo","Nell''Armadietto' non c'e nulla");
    p41.setLuogo(5);
    insPersonaggi->inserisci(49, p41);
    p42.setNome("Vivi");
    p42.setFrasi("La 'Chiave' la possiede il 'secondo pilota', cercalo","Nell''Armadietto' non c'e nulla");
    p42.setOgg(true,54);
    p42.setFrasiconOgg1("Apri l''Armadietto', potresti trovare qualcosa di utile","La 'Chiave' che hai preso non va bene per questo armadietto, cercane un altra");
    p42.setLuogo(5);
    insPersonaggi->inserisci(42, p42);
    p43.setNome("Jin");
    p43.setFrasi("La 'Chiave' la possiede il 'secondo pilota', cercalo","Nell''Armadietto' non c'e nulla");
    p43.setOgg(true,54);
    p43.setFrasiconOgg1("Togli la 'tata' prima di prendere il camice","Il 'camice' non serve a nulla, lascialo nell''armadietto'");
    p43.setLuogo(5);
    insPersonaggi->inserisci(43, p43);

    //luogo 6 51-60
    p51.setNome("Cid");
    p51.setFrasi("Prendi il 'casco' Potrebbe tornarti utile","Non Vedo nulla di utile qui");
    p51.setOgg(true,50,51);
    p51.setFrasiconOgg1("Prendi la tuta dalla cabina di pilotaggio","La tuta non ti serve, vai direttametne all'esterno dell'astronave");
    p51.setFrasiconOgg2("Visto che hai la tuta, puoi uscire all'esterno dell'astronave","lascia il casco prima di uscire dall'astronave");
    p51.setLuogo(6);
    //modifiche D'Andria Dresda aggiunta dialogo a Cid
    Dialogo dialogocid=Dialogo("Cid");
    dialogocid=caricaDialoghiDaFile("Cid");
    p51.setDialogo(&dialogocid);
    //fine modifiche
    insPersonaggi->inserisci(51, p51);
    p52.setNome("Stainer");
    p52.setFrasi("Dopo aver preso il 'casco' cerca la 'tuta'","Ripostati un po sul letto, potrebbe servirti a schiarire le idee");
    p52.setLuogo(6);
    insPersonaggi->inserisci(52, p52);
    p53.setNome("Bruce");
    p53.setFrasi("Non uscire all'esterno della nave senza 'casco' e 'tuta'","la 'tuta' e il 'casco' non servo per uscire all'esterno dell'astronave");
    p53.setLuogo(6);
    insPersonaggi->inserisci(53, p53);

    //luogo 7 61-70
    p61.setNome("Dom");
    p61.setFrasi("non 'premere il rosso' senza avere il 'casco'","'premi il rosso' senza 'casco' altrimenti morirai");
    p61.setLuogo(7);
    insPersonaggi->inserisci(61, p61);
    p62.setNome("Gabriel");
    p62.setFrasi("non 'premere il rosso' senza avere il 'casco'","'premi il rosso' senza 'casco' altrimenti morirai");
    p62.setOgg(true,50);
    p62.setFrasiconOgg1("Hai il il 'casco', ma ti manca la 'tuta' per poter uscire dal'astronave","hai il 'casco', premi rosso così potrai uscire dall'astonave");
    p62.setLuogo(7);
    insPersonaggi->inserisci(62, p62);
    p63.setNome("Martino");
    p63.setFrasi("non 'premere il rosso' senza avere il 'casco'","'premi il rosso' senza 'casco' altrimenti morirai");
    p63.setOgg(true,50,51);
    p63.setFrasiconOgg1("Hai il il 'casco', ma ti manca la 'tuta' per poter uscire dal'astronave","hai il 'casco', premi rosso così potrai uscire dall'astonave");
    p63.setFrasiconOgg2("Hai sia il 'casco' che la 'tuta' ora puoi uscire dal'astronave","lascia il 'casco', poi premi rosso così potrai uscire dall'astonave");
    p63.setLuogo(7);
    insPersonaggi->inserisci(63, p63);

    //luogo 8 71-80
    p71.setNome("Samuel");
    p71.setFrasi("Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare il contrario?","Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare la stessa procedura?");
    p71.setLuogo(8);
    insPersonaggi->inserisci(71, p71);
    p72.setNome("Shain");
    p72.setFrasi("Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare il contrario?","Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare la stessa procedura?");
    p72.setLuogo(8);
    insPersonaggi->inserisci(72, p72);
    p73.setNome("Zick");
    p73.setFrasi("Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare il contrario?","Il 'manuale' descrive come attivare il reattore, e se per spegnerlo bastasse fare la stessa procedura?");
    p73.setLuogo(8);
    insPersonaggi->inserisci(73, p73);

    //luogo 9 81-90
    p81.setNome("Lance");
    p81.setFrasi("Il 'secondo pilota' e' a nord","si tolga il 'casco' e' sicuro qui");
    p81.setLuogo(9);
    insPersonaggi->inserisci(81, p81);
    p82.setNome("Lauren");
    p82.setFrasi("Il 'secondo pilota' e' a nord","si tolga il 'casco' e' sicuro qui");
    p82.setLuogo(9);
    insPersonaggi->inserisci(82, p82);
    p83.setNome("Lucas");
    p83.setFrasi("Il 'secondo pilota' e' a nord","si tolga il 'casco' e' sicuro qui");
    p83.setLuogo(9);
    insPersonaggi->inserisci(83, p83);

    //luogo 10 91-100
    p91.setNome("Andre'");
    p91.setFrasi("Soccorra il 'secondo pilota', e nei guai","il 'secondo pilota' e' andato perso nello spazio, e' inutile cercarlo");
    p91.setLuogo(10);
    insPersonaggi->inserisci(91, p91);
    p91.setNome("George");
    p91.setFrasi("Soccorra il 'secondo pilota', e nei guai","il 'secondo pilota' e' andato perso nello spazio, e' inutile cercarlo");
    p91.setLuogo(10);
    insPersonaggi->inserisci(92, p91);
    p91.setNome("Oscar");
    p91.setFrasi("Soccorra il 'secondo pilota', e nei guai","il 'secondo pilota' e' andato perso nello spazio, e' inutile cercarlo");
    p91.setLuogo(10);
    insPersonaggi->inserisci(93, p91);

    //inizio modifiche ROSA CHIARAPPA
    p101.setNome("carabiniere");
    p101.setFrasi("Il carabiniere ti ha perquisito e ha trovato in tuo possesso un oggetto rubato, sei in arresto!","Il carabiniere ti ha perquisito e non ha trovato nessun oggetto rubato in tuo possesso.");
    p101.setLuogo(2);
    insPersonaggi->inserisci(94, p101);
    //fine modifiche ROSA CHIARAPPA
    //aggiunta modifiche D'Andria Dresda al progetto di Federica Forte caricamento dialoghi da file
    scrivistatosufile("Cid",1);
    scrivistatosufile("Vincent",1);
    scrivistatosufile("Kail",1);
    //fine modifiche
}

void Gioco::parla(Personaggi p)
{
    p.stampa();
}
//inizio modifiche D'Andria Dresda al progetto di Federica Forte
Dialogo Gioco::caricaDialoghiDaFile(string nome)
{

    Dialogo dialogo= Dialogo(nome);

    string rigafile;

    ifstream filedialoghi("Dialoghi.txt", ios::in);
    while (filedialoghi.get()!='?')
    {
        getline(filedialoghi,rigafile);

        convertiRiga(&dialogo,nome,rigafile);

    }
    filedialoghi.close();

    return dialogo;
}

void Gioco::convertiRiga(Dialogo *dialogo,string nome,string rigafile)
{

    string nomepersonaggio="";
    char statodialogostr[20];
    for(int j=0; j<20; j++)
    {
        statodialogostr[j]='\0';
    }

    int statodialogo;
    string frasedialogo="";
    int indice=0;
    while(rigafile[indice]!='|')
    {
        nomepersonaggio=nomepersonaggio+rigafile[indice]; //leggo il nome del personaggio
        indice++;
    }
    indice++;
    int i=0;
    while(rigafile[indice]!='*')
    {
        statodialogostr[i]=rigafile[indice]; // leggo lo stato del dialogo
        indice++;
        i++;
    }
    statodialogo=atoi(statodialogostr);
    indice++;
    while(rigafile[indice]!='#')
    {
        if(rigafile[indice]=='$')
        {
            frasedialogo=frasedialogo+'\n';
        }
        else
        {
            frasedialogo=frasedialogo+rigafile[indice]; // leggo la frase da inserire nel nodo Domanda
        }
        indice++;
    }
    if (nome==nomepersonaggio)
    {

        dialogo->inseriscidomanda(statodialogo,frasedialogo); //inserisce la Domanda nel Dialogo

    }
}
//fine modifiche


int Gioco::controlla()
{
    int i=1;
    int lung=oggetti.get_n_oggetti();
    int oggettoPg1 = pg.get_ogg1();
    int oggettoPg2 = pg.get_ogg2();
    bool trovato = false;
    if (pg.get_ogg2()!=0)
    {
        while (i <= lung && !trovato)
        {
            if (oggetti.get_oggetto(i).get_codice() == oggettoPg1)
                trovato = true;
            else
                i++;
        }
        if(oggetti.get_oggetto(i).get_luogo()==0)
        {
            i=1;
            trovato=false;
            while (i <= lung && !trovato)
            {
                if (oggetti.get_oggetto(i).get_codice() == oggettoPg2)
                    trovato = true;
                else
                    i++;
            }
            if(oggetti.get_oggetto(i).get_luogo()==0)
            {
                return 0;
            }
            else
            {
                while (i <= lung && !trovato)
                {
                    if (oggetti.get_oggetto(i).get_codice() == pg.get_ogg1())
                        trovato = true;
                    else
                        i++;
                }
                if(oggetti.get_oggetto(i).get_luogo()==0)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        while (i <= lung && !trovato)
        {
            if (oggetti.get_oggetto(i).get_codice() == pg.get_ogg1())
                trovato = true;
            else
                i++;
        }
        if(oggetti.get_oggetto(i).get_luogo()==0)
        {
            return 1;
        }
    }
}
void Gioco::personaggio_entra()
{
    if(luogo_attuale!=luogo_precedente && insPersonaggi.appartiene(luogo_attuale))
    {
        pg=insPersonaggi.recupera(luogo_attuale);
        cout<<"Vedo "<<pg.getNome()<<endl;
        presente2=true;
        luogo_precedente=luogo_attuale;
    }

//inizio modifiche ROSA CHIARAPPA
    int codice = 94;
    Personaggi carabiniere = insPersonaggi.recupera(codice);
    if (carabiniere.getLuogo() == luogo_attuale)
    {
        interfaccia.scrivi("Un carabiniere e' entrato nella stanza per ricercare degli oggetti rubati.");
    }

}



void Gioco::personaggio_esce()
{
    if(presente2==true)
    {
        cout<<endl<< pg.getNome()<<" lascia la stanza"<<endl;
        pg.setNome("");
        presente2=false;
    }



}

void Gioco::az_parla(Personaggi pg)
{
    int ris_controllo = 0;

    parola2[0]=toupper(parola2[0]);

    if(parola2==pg.getNome())
    {
        //modifiche effettuate da D'Andria Dresda per far dialogare i personaggi
        if(pg.getNome()=="Cid" || pg.getNome()=="Vincent" || pg.getNome()=="Kail")
        {
            int risposta;
            int statodialogo=caricastatodialogo(pg.getNome()); //leggo da file l'ultimo stato del dialogo
            pg.getDialogo()->setstato(statodialogo);
            pg.getDialogo()->visualizzadomande();

            bool dialogofinito=false;
            do
            {
                cout << endl<< "Digita numero risposta -----> ";
                cin >>risposta;
                cout << endl;
                dialogofinito=pg.getDialogo()->rispondi(risposta);
                if(risposta==0)
                {
                    scrivistatosufile(pg.getNome(),pg.getDialogo()->getstato()); //in caso di risposta 0 si salva lo stato del dialogo, per riprenderlo dallo stesso punto la volta successiva che si incrontrerà lo stesso personaggio
                }
                if (pg.getDialogo()->isFoglia())
                {
                    dialogofinito=true;
                    scrivistatosufile(pg.getNome(),1);//nel caso si raggiunga una foglia del dialogo si reimposta lo stato a 1
                }
            }
            while(!dialogofinito);
        }
        else
        {
            //fine modifiche D'Andria Dresda

            if(pg.getIfNec())
            {
                ris_controllo=controlla();
                if(ris_controllo==0)
                    pg.SelezionaFrase2();
                else if(ris_controllo==1)
                    pg.SelezionaFrase1();
                else
                    parla(pg);
            }
            else
            {
                parla(pg);
            }
        }
    }
    else
        cout << parola2 << " non e' in questa stanza"<<endl;
}

//aggiunta D'Andria Dresda al progetto di Federica Forte
int Gioco::caricastatodialogo(string nome)
{
    int stato=1;
    string rigafile;
    ifstream filestati("Statidialoghi.txt", ios::in);
    //if (!filestati == NULL) {
    if(!filestati.is_open())
    {
        cout << "File Statidialoghi.txt non trovato";
    }
    else
    {
        while (filestati.get()!='?')
        {
            getline(filestati,rigafile);
            leggistato(&stato,nome,rigafile); //legge lo stato all'interno della riga del file
        }
    }
    filestati.close();
    return stato;
}

int Gioco::leggistato(int *stato,string nome, string rigafile)
{
    string nomepersonaggio;
    char statodialogostr[20];
    for(int j=0; j<20; j++)
    {
        statodialogostr[j]=' ';
    }
    int statodialogo;
    int indice=0;
    while(rigafile[indice]!='|')
    {
        nomepersonaggio=nomepersonaggio+rigafile[indice];
        indice++;
    }
    indice++;
    int i=0;
    while(rigafile[indice]!='#')
    {
        statodialogostr[i]=rigafile[indice];
        indice++;
        i++;
    }
    statodialogo=atoi(statodialogostr);
    if (nome==nomepersonaggio)
    {
        *stato=statodialogo;
    }
}

void Gioco::scrivistatosufile(string nome, int stato)
{

    ifstream file("Statidialoghi.txt");
    ofstream nuovofile("Nuovofile.txt");
    string rigafile;
    string nuovariga;
    bool riganome=false;
    if(!file)
    {
        cout << "File Statidialoghi.txt non trovato";
    }
    else
    {
        while(file.get()!='?')
        {
            getline(file,rigafile);
            riganome=verificanome(nome,rigafile);
            if(riganome)
            {
                stringstream statostream;
                statostream<<stato;
                string statostring=statostream.str();
                nuovariga='-'+nome+'|'+statostring+'#';
                nuovofile << nuovariga << '\n';
            }
            else
            {
                nuovofile << '-' << rigafile << '\n';
            }

        }

    }

    nuovofile << '?';
    file.close();
    nuovofile.close();
    std::remove("Statidialoghi.txt");
    int result=rename("Nuovofile.txt","Statidialoghi.txt");
}
bool Gioco::verificanome(string nome, string rigafile)
{
    string nomepersonaggio;
    int indice=0;
    while(rigafile[indice]!='|')
    {
        nomepersonaggio=nomepersonaggio+rigafile[indice];
        indice++;
    }
    return(nome==nomepersonaggio);
}
//fine modifiche

void Gioco :: visualizza_bacheca()
{
    int scelta;

    do
    {
        system("cls");
        //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
        fflush(stdin);
        interfaccia.scrivi_parziale("\n\n\n");
        interfaccia.scrivi_parziale("                                        BACHECA ADVENTURE\n\n\n");
        bacheca.StampaBacheca();
        interfaccia.scrivi_parziale("Seleziona l'operazione da eseguire: \n\n");
        interfaccia.scrivi_parziale("1) Inserisci un nuovo avviso in bacheca\n");
        interfaccia.scrivi_parziale("2) Cancella un avviso che hai precedentemente inserito\n");
        interfaccia.scrivi_parziale("0) Torna al gioco\n\n");
        interfaccia.scrivi_parziale("Operazione: ");
        cin >> scelta;
        if(cin.fail())
        {
            cin.clear();
            scelta=3;
        }
        switch (scelta)
        {
        case 0:
            break;
        case 1:
            inserisci_mess_bacheca_specifiche();
            break;
        case 2:
            cancella_mess_bacheca_specifiche();
            break;
        default:
            interfaccia.scrivi("\n\nINPUT NON VALIDO!");
            Sleep(850);
            break;
        }
    }
    while(scelta!=0);

    stringa_risposta = "l'hai consultata.";                     //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

void Gioco :: inserisci_mess_bacheca_specifiche()
{
    string avviso;

    if(!bacheca.BachecaPiena())
    {
        interfaccia.scrivi_parziale("\n\nInserisci l'avviso [MASSIMO 160 CARATTERI]\n\n");
        fflush(stdin);
        getline(cin,avviso);
        bacheca.NuovoMessaggio(avviso);
    }
    else
        interfaccia.scrivi_parziale("\nNON PUOI INSERIRE ALTRI AVVISI\n");
    Sleep(850);

}



//MODIFICHE MICHELE ALBANO
void Gioco::Aggiorna_Ferite() //Gestore sistema ferite
{
    int Generatore_Casuale; //Generatore casuale valori.
    srand(time(NULL)); //Inizializza il generatore di valori
    Generatore_Casuale=rand()%100+1; //Genera una variabile casuale compresa tra 1 e 101
    if(Ferite.appartiene(Generatore_Casuale)==true) //Se la chiave non appartiene, aggiungi la Ferita
    {
        if(Salute.Ferita_Contratta(Ferite.recupera(Generatore_Casuale))!=true) //Se non hai già contratto la Ferita, aggiungila e stampa un messaggio al Giocatore
        {
            Salute.SetFerita(Ferite.recupera(Generatore_Casuale)); //Aggiungi la ferita allo Stato di Salute
            interfaccia.scrivi(Ferite.recupera(Generatore_Casuale).GetDescrizione()); //Stampa la descrizione della Ferita
        }
    }
    Salute.Aggiorna_Stato(); //Aggiorna Stato Salute
}


//FINE MODIFICHE MICHELE ALBANO
void Gioco :: cancella_mess_bacheca_specifiche()
{
    int i;

    if(bacheca.GetMessCancellabili() > 0)
    {
        do
        {
            system("cls");
            //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI
            fflush(stdin);
            interfaccia.scrivi_parziale("ELENCO AVVISI CHE PUOI CANCELLARE\n\n");
            bacheca.StampaMessCancellabili();
            interfaccia.scrivi_parziale("Inserisci il numero dell'avviso che vuoi cancellare: ");
            cin >> i;
            if(cin.fail())
            {
                i=0;
                cin.clear();
            }
        }
        while(i < 1 || i > bacheca.GetMessCancellabili());
        bacheca.CancellaMessaggio(i);
    }
    else
    {
        cout << "\n\nNON CI SONO MESSAGGI CHE PUOI CANCELLARE\n";
#ifdef _WIN32
        system("pause");
#else
        system("read");
#endif // _WIN32
    }
    Sleep(850);
}



void Gioco::benzina()
{
    if (oggetti.get_oggetto(27).get_luogo() == 0)
    {
        interfaccia.scrivi("stai facendo benzina");
        motorino.pieno_benzina();

        stringa_risposta = "hai fatto benzina.";                       //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else
        interfaccia.scrivi("Non hai il motorino, non puoi fare benzina.");
    stringa_risposta = "non avevi il motorino.";                           //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);          //Modifica PMF(storia)
}





void Gioco::usa_motorino()
{
    // interfaccia.scrivi("focaccia"); // Vaira - Non credo che questa informazione sia utile nel gioco: rimossa :)
    if (oggetti.get_oggetto(og).get_luogo() != 0)
    {
        interfaccia.scrivi("Non hai il motorino.");

        stringa_risposta = "non avevi il motorino.";                   //Modifica PMF(storia)
        storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
    }
    else
    {
        if(motorino.get_livello_benzina() == 0)
        {
            interfaccia.scrivi("Non hai carburante, vai a fare benzina");
            stringa_risposta = "non avevi carburante.";                    //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
        }
        else
        {
            interfaccia.scrivi("Sei sul motorino! ora ti sposti più velocemente.");
            salito = true;

            stringa_risposta = "eri sul motorino.";                        //Modifica PMF(storia)
            storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
        }

    }
}

//Modifica PMF(agenda)
//Inserimento azioni relative ad agenda


//cancella agenda
void Gioco::azione_46()
{
    Agenda agenda;
    if(oggetti.get_oggetto(12).get_luogo() != 0)
        interfaccia.scrivi("Non ce l'hai.");
    else
        agenda.Cancella();

    stringa_risposta = "hai cancellato l'agenda.";                 //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

//scrivi agenda
void Gioco::azione_47()
{
    Agenda agenda;
    if(oggetti.get_oggetto(12).get_luogo() != 0)
        interfaccia.scrivi("Non ce l'hai.");
    else
        agenda.Scrivi();

    stringa_risposta = "hai scritto l'agenda.";                    //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}

//leggi agenda
void Gioco::azione_48()
{
    Agenda agenda;
    if(oggetti.get_oggetto(12).get_luogo() != 0)
        interfaccia.scrivi("Non ce l'hai.");
    else
        agenda.Leggi();

    stringa_risposta = "hai letto l'agenda.";                      //Modifica PMF(storia)
    storia_gioco.insStoria(stringa_comando, stringa_risposta);  //Modifica PMF(storia)
}
//Modifica PMF: fin qui.

// GLI INDICI DI ARRAY VANNO DA 1 a N PER TRACCIABILITA'! (quindi posizione 0 inutilizzata)

//Modifica Francesco Cosma - Premi
void Gioco::init_premi()
{
    Lista<Premio>::posizione posiz=premi.getListaPremi()->primolista();

    enigmista.creaPremio("enigmista","risolvi 10 enigmi",10,10,0);
    premi.getListaPremi()->inslista(enigmista,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    spazio.creaPremio("giro nello spazio","visita poppa,esterno e prua",3,5,87);
    premi.getListaPremi()->inslista(spazio,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    tuta.creaPremio("metti tuta","metti la tuta per la prima volta",1,5,0);
    premi.getListaPremi()->inslista(tuta,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    casco.creaPremio("metti casco","metti il casco per la prima volta",1,5,0);
    premi.getListaPremi()->inslista(casco,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    radiazioni.creaPremio("radiazioni zero","metti il camice per la prima volta",1,5,0);
    premi.getListaPremi()->inslista(radiazioni,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    pronto_soccorso.creaPremio("pronto soccorso","salva il secondo pilota",1,5,88);
    premi.getListaPremi()->inslista(pronto_soccorso,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    annuncio.creaPremio("annuncio!","metti un annuncio in bacheca",1,5,89);
    premi.getListaPremi()->inslista(annuncio,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    perso.creaPremio("ti sei perso?","visita il corridoio 10 volte",10,5,90);
    premi.getListaPremi()->inslista(perso,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

    asd.creaPremio("quanti crediti?","rispondi correttamente all'enigma su Algoritmi e Strutture Dati",1,5,91);
    premi.getListaPremi()->inslista(asd,posiz);
    posiz = premi.getListaPremi()->succlista(posiz);

}

void Gioco::aggiorna_premi()
{
    Lista<Premio>::posizione i=premi.getListaPremi()->primolista();
    Premio appoggioconf;
    float tempoapp;
    int oggettoapp;
    int p;
    while(not premi.getListaPremi()->finelista(i))
    {
        if((premi.getListaPremi()->leggilista(i).confronta() == true) && (premi.getListaPremi()->leggilista(i).getRitirato()==false))
        {
            appoggioconf = premi.getListaPremi()->leggilista(i);
            cout <<""<<endl<<"*******************"<<endl<< "hai sbloccato un premio!:"<<appoggioconf.getTitolo() << endl<<"*******************"<<endl<<""<<endl;
            appoggioconf.setRitirato(true);
            tempoapp=premi.ritiraTempo(i);
            tempo = tempoapp + tempo;
            oggettoapp=premi.ritiraOggetto(i);
            p=0;
            while((p<= oggetti.get_n_oggetti())&&(not oggettoapp == 0))
            {
                if(oggetti.get_oggetto(p).get_codice()== oggettoapp)
                {

                    oggetti.set_luogo(p,0);
                    cout <<"hai sbloccato un distintivo" <<endl<< "apri l'inventario per visionarlo" <<endl<<""<<endl;
                }
                p++;
            }

            premi.getListaPremi()->scrivilista(appoggioconf,i);
        }
        i = premi.getListaPremi()->succlista(i);
    }
}

void Gioco::aggiorna_progresso()
{
    string cerca;
    bool trovato=false;
    bool flag=false;
    bool fine=false;
    bool controllo1=false;
    bool controllo2=false;
    bool controllo3=false;
    bool controllo4=false;
    bool controllo5=false;
    bool controllo6=false;
    bool controllo7=false;
    bool controllo8=false;
    bool controllo9=false;
    Lista<Premio>::posizione i=premi.getListaPremi()->primolista();
    Premio appoggioconf;
    int p;
    string giro= "giro nello spazio";


    //controlli

    //controllo corridoio
    while(fine == false)
    {
        if((luogo_attuale == 3) && (flag==false) && (controllo1==false))
        {
            cerca="ti sei perso?";
            flag=true;
            controllo1=true;
        }

        //controllo casco
        p=0;
        while((p< oggetti.get_n_oggetti())&&(flag == false)&&(controllo2==false))
        {
            if((oggetti.get_oggetto(p).get_codice()== 50) && (oggetti.get_oggetto(p).get_luogo()== 0))
            {
                cerca="metti casco";
                flag=true;
                controllo2=true;
            }
            p++;
        }

        //controllo tuta
        p=0;
        while((p< oggetti.get_n_oggetti())&&(flag == false)&&(controllo3==false))
        {
            if((oggetti.get_oggetto(p).get_codice()== 51) && (oggetti.get_oggetto(p).get_luogo()== 0))
            {
                cerca="metti tuta";
                flag=true;
                controllo3=true;
            }
            p++;
        }
        //controllo camice
        p=0;
        while((p< oggetti.get_n_oggetti())&&(flag == false)&&(controllo4==false))
        {
            if((oggetti.get_oggetto(p).get_codice()== 52) && (oggetti.get_oggetto(p).get_luogo()== 0))
            {
                cerca="radiazioni zero";
                flag=true;
                controllo4=true;
            }
            p++;
        }

        //controllo secondo
        p=0;
        while((p< oggetti.get_n_oggetti())&&(flag == false)&&(controllo5==false))
        {
            if((oggetti.get_oggetto(p).get_codice()== 53) && (oggetti.get_oggetto(p).get_luogo()== 0))
            {
                cerca="pronto soccorso";
                flag=true;
                controllo5=true;
            }
            p++;
        }


        //controllo giro

        i=premi.getListaPremi()->primolista();
        {
            if((giro == premi.getListaPremi()->leggilista(i).getTitolo())&&(trovato == false))
            {
                trovato = true;
            }
            i = premi.getListaPremi()->succlista(i);
        }
        if((luogo_attuale == 11) && (premi.getListaPremi()->leggilista(i).getProgresso()==0))
        {
            cerca="giro nello spazio";
            flag= true;
            controllo6=true;
        }
        if((luogo_attuale == 10) && (premi.getListaPremi()->leggilista(i).getProgresso()==1))
        {
            cerca="giro nello spazio";
            flag= true;
            controllo6=true;
        }
        if((luogo_attuale == 9) && (premi.getListaPremi()->leggilista(i).getProgresso()==2))
        {
            cerca="giro nello spazio";
            flag= true;
            controllo6=true;
        }

        //controllo enigmi
        if((ris_esatta == true) && (flag==false) && (controllo7==false))
        {
            cerca="enigmista";
            flag= true;
            controllo7=true;
        }

        //controllo asd
        if((ris_esatta==true)&& (flag==false) && (controllo8==false) && (algor==true))
        {
            cerca="quanti crediti?";
            flag= true;
            controllo8=true;
        }

        //controllo annuncio
        if((messaggio_b==true)&&(flag==false)&&(controllo9==false))
        {
            cerca="annuncio!";
            flag=true;
            controllo9=true;
        }

        //ciclo di incremento

        if(flag == true)
        {
            i=premi.getListaPremi()->primolista();
            while(not premi.getListaPremi()->finelista(i))
            {
                if(cerca == premi.getListaPremi()->leggilista(i).getTitolo())
                {
                    appoggioconf = premi.getListaPremi()->leggilista(i);
                    appoggioconf.incrementaProgresso();
                    premi.getListaPremi()->scrivilista(appoggioconf,i);
                }
                i = premi.getListaPremi()->succlista(i);
            }
            flag=false;
        }
        else
        {
            fine = true;
        }
    }
}

void Gioco::carica_trasporti()
{
    ifstream t("Trasporti.nav",ios::in);
    bool aperto=t.good();
    if (aperto)
    {
        ServizioTrasporti s(t);
        servizio_trasporti = s;
    }
}

void Gioco::trasporto(int n)
{
    servizio_trasporti.cerca_trasporto(n);
    fstream crono("Cronologia.odb",fstream::in);
    ifstream f(servizio_trasporti.get_map().c_str(),ios::in);
    bool aperto=f.good();
    if (aperto)
    {
        Mappa T(f,crono);
        mappa = T;
        luogo_attuale = servizio_trasporti.get_luogo();
    }
}




