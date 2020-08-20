#include <iostream>
#include <cstdlib>

#include "Mappa.h"
#include "Luogo.h"
#include "Coda.h"
#include "ServizioPila.h"
Mappa::Mappa() {};

Mappa::Mappa(ifstream &f,fstream &crono)
{

    //non controllo l'esito dell'apertura del file, perchè istanzio l'oggetto soltanto se dal main il file è stato aperto correttamente
    int n=0;
    string buffer;
    getline(f,buffer);                    //carico le informazioni sul numero di nodi della mappa
    n=atoi(buffer.c_str());
    mappa=new Grafo<etichetta,peso>; //istanzio la mappa (un grafo con n nodi reali + 1 fittizio)
    riferimenti=new riferimento[n];       //alloco il vettore con le coppie nodo-etichetta
    numnodi=n;                            //numero di nodi reali nel grafo
    getline(f,buffer);
    inizio_mappa = atoi(buffer.c_str());
    Grafo<etichetta,peso>::nodo* node; //----+
    int i=0; //                              +-- variabili ausiliarie
    int inizio; //                           |
    string estratto; //----------------------+

    while (i<n) //inserimento degli n nodi nella mappa
    {
        etichetta e;
        inizio=0;
        getline(f,buffer);                    //leggo una riga dal file
        node=new Grafo<etichetta,peso>::nodo; //istanzio il nuovo nodo da inserire
        mappa->insnodo(*node);                //lo inserisco nella mappa
        estratto=estrai(buffer,inizio,',');   //prendo il campo ID dell'etichetta del nodo dalla riga di testo
        e.scriviID(atoi(estratto.c_str()));   //inserisco l'ID nell'etichetta
        estratto=estrai(buffer,inizio,',');   //prendo il campo nome dell'etichetta del nodo dalla riga di testo
        e.scriviluogo(estratto);              //inserisco il nome nell'etichetta
        e.setDescData(DescData::loadDescriptions(e.leggiID(), e.leggiluogo())); // Vaira [Donati] caricamento descrizioni alternative-dinamiche per il luogo
        // Modifica Angelo Petronelli
        estratto=estrai(buffer,inizio,','); //prendo il campo direzioni dell'etichetta del nodo dalla riga di testo
        e.scrividirezioni(estratto);        // inserisco le direzioni dell'etichetta

        // fine modifica

        while (inizio<buffer.length()) //prendo tutte le vie associate al luogo
        {
            Vialuogo temp;
            estratto=estrai(buffer,inizio,',');      //prendo il campo nome della via associata
            temp.scrivinome(estratto);               //lo inserisco nella variabile temporanea
            estratto=estrai(buffer,inizio,',');      //prendo il campo min della via associata
            temp.scrivimin(atoi(estratto.c_str()));  //lo inserisco nella variabile temporanea
            estratto=estrai(buffer,inizio,',');      //prendo il campo max della via associata
            temp.scrivimax(atoi(estratto.c_str()));  //lo inserisco nella variabile temporanea
            e.insvia(temp);                          //inserisco la via nell'etichetta
        }
        //MODIFICA D-R(Colturi):Luoghi a Pagamento //  controllo quando l' ID è maggiore di 15, devo caricare le descrizioni
        if(e.leggiID()>15)
        {
            e.getDescrizione();
        }
        mappa->scrivinodo(e,*node);         //associo l'etichetta al nodo nel grafo
        //e.inizioDescrizioni();            // Vaira - Considerata la nuova classe per la gestione delle descrizioni non c'è più la necessità di utilizzare questo operatore
        riferimenti[i].scrivinodo(*node);
        riferimenti[i].scrivietichetta(e);  //aggiornamento del vettore con le coppie nodo-etichetta
        i++;
        delete node;
    }
    etichetta eti; //-----------------------------------+
    eti.scriviID(n);                              //    |
    fittizio=new Grafo<etichetta,peso>::nodo;     //    +-- creazione e inserimento del nodo fittizio
    mappa->insnodo(*fittizio);                    //    |
    mappa->scrivinodo(eti,*fittizio); // ---------------+
    partenza=*fittizio; //setto luogo di partenza (fittizio)
    arrivo=*fittizio;   //setto luogo di arrivo (fittizio)

    while (!f.eof()) //inserimento degli archi nella mappa
    {
        peso temp;
        Grafo<etichetta,peso>::nodo sorgente,destinazione; //variabili ausiliarie
        inizio=0;
        getline(f,buffer); //leggo una riga dal file
        estratto=estrai(buffer,inizio,','); //prendo l'ID del nodo da cui esce l'arco
        sorgente=nodo_da_id(atoi(estratto.c_str())); //ricavo il nodo associato a tale ID nell'etichetta
        estratto=estrai(buffer,inizio,','); //prendo l'ID del nodo in cui entra l'arco
        destinazione=nodo_da_id(atoi(estratto.c_str())); //ricavo il nodo associato a tale ID nell'etichetta
        mappa->insarco(sorgente,destinazione); //inserisco l'arco nella mappa
        estratto=estrai(buffer,inizio,','); //estraggo il campo nome del peso dell'arco dalla riga di testo
        temp.scrivinome(estratto); //inserisco nome nel peso
        estratto=estrai(buffer,inizio,','); //estraggo il campo direzione del peso dell'arco dalla riga di testo
        temp.scrividirezione(estratto); //inserisco direzione nel peso
        estratto=estrai(buffer,inizio,','); //estraggo il campo lunghezza del peso dell'arco dalla riga di testo
        temp.scrivilunghezza(atof(estratto.c_str())); //inserisco lunghezza nel peso
        estratto=estrai(buffer,inizio,','); //estraggo il campo tempo del peso dell'arco dalla riga di testo
        temp.scrivitempo(atof(estratto.c_str())); //inserisco tempo nel peso
        estratto=estrai(buffer,inizio,','); //estraggo il campo asfalto del peso dell'arco dalla riga di testo
        temp.scriviasfalto(atoi(estratto.c_str())); //inserisco asfalto nel peso
        estratto=estrai(buffer,inizio,','); //estraggo il campo pedaggio del peso dell'arco dalla riga di testo
        temp.scrivipedaggio(atoi(estratto.c_str())); //inserisco pedaggio nel peso
        mappa->scriviarco(temp,sorgente,destinazione); //valorizzo l'arco con il peso
        i++;
    }
    f.close();
    f.clear();
    f.open("Mappa.nav",ios::in);
    setsuggerimenti(f); //costruisco l'albero dei suggerimenti
    f.close();
    f.clear();
    if(crono.good())
    {
        setcronologia(crono); //carico la cronologia da file
    }
    crono.close();
    crono.clear();
    distanza_tempo=true;  //---+
    evita_sterrato=false; //   +--- impostazioni di default per il calcolo del cammino migliore tra partenza e arrivo
    evita_pedaggi=false; //----+
}

Mappa::~Mappa() {}

void Mappa::scrivipartenza() //setta il luogo di partenza
{
    string input;
    input = getsuggerimenti(input,"partenza"); //salvo in "input" la stringa presa in input o scelta tra i suggerimenti messi a disposizione
    if(input != "&") //se input == "&" allora la partenza è stata settata dalla cronologia e quindi è inutile rifare tutto il procedimento
    {
        //Fine modifica
        int civ;
        Grafo<etichetta,peso>::nodo temp;
        temp=nodo_da_input(input);
        if (temp!=*fittizio)
        {
            partenza=temp; //se ho avuto un occorrenza setto partenza...
            aggiungiacrono("partenza"); //... e aggiungo la stringa alla cronologia
        }
    }
    //Fine modifica
}

void Mappa::scriviarrivo() //analogo a scrivipartenza()
{
    string input;
    input = getsuggerimenti(input,"arrivo"); //salvo in "input" la stringa presa in input o scelta tra i suggerimenti messi a disposizione
    if(input != "&") //se input == "&" allora la destinazioe è stata settata dalla cronologia e quindi è inutile rifare tutto il procedimento
    {
        int civ;
        Grafo<etichetta,peso>::nodo temp;
        temp=nodo_da_input(input);
        if (temp!=*fittizio)
        {
            arrivo=temp; //se ho avuto un occorrenza setto arrivo...
            aggiungiacrono("arrivo"); //... e aggiungo la stringa alla cronologia
        }
    }
}

string Mappa::legginomepartenza()
{
    return(mappa->legginodo(partenza).leggiluogo());
}

string Mappa::legginomearrivo()
{
    return(mappa->legginodo(arrivo).leggiluogo());
}

Grafo<Mappa::etichetta,Mappa::peso>::nodo Mappa::nodo_da_input(string pattern) //restituisce un nodo ricevendo in input (parte del) l'etichetta
{
    Grafo<etichetta,peso>::nodo rif=*fittizio;
    int i=0; //----------+
    string testo; //     +-- comodo
    int num=0; //--------+
    Lista<riferimento> risultati; //lista che conterrà i risultati
    Lista<riferimento>::posizione pos=risultati.primolista();
    bool trovato;
    string testo_low,pattern_low; //conterranno testo e pattern ma con tutti i caratteri minuscoli
    pattern_low=minuscolo(pattern); //conversione in minuscolo del pattern
    while (i<numnodi) //ricerca (CASE INSENSITIVE) in tutti i nodi
    {
        testo=riferimenti[i].leggietichetta().leggiluogo(); //ricerca nel pattern nei nomi dei luoghi
        testo_low=minuscolo(testo); //conversione in minuscolo del testo
        trovato=multi_string_matching(testo_low,pattern_low); //string matching
        if (trovato) //se ci sono corrispondenze
        {
            risultati.inslista(riferimenti[i],pos); //aggiungo elemento in testa alla lista dei risultati
            num++;
        }
        else //se non ho trovato in nome
        {
            Lista<Vialuogo> vie=riferimenti[i].leggietichetta().leggivie(); //ricerca nel pattern in via1 dei luoghi (analoga alla ricerca sopra)
            Lista<Vialuogo>::posizione ind=vie.primolista();
            while (!vie.finelista(ind) && !trovato)
            {
                testo=vie.leggilista(ind).legginome();
                testo_low=minuscolo(testo);
                trovato=multi_string_matching(testo_low,pattern_low);
                ind=vie.succlista(ind);
            }
            if (trovato)
            {
                risultati.inslista(riferimenti[i],pos);
                num++;
            }
        }
        i++;
    }
    int scelta=num+1;
    if (num>0) //se ho almeno un risultato
    {
        while (scelta!=0)
        {
            //system("cls"); windows
            system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
            fflush(stdin);
            pos=risultati.primolista();
            interfaccia.scrivi("Luoghi trovati :");    //stampa dei risultati
            for (i=0; i<100; i++)
                interfaccia.scrivi_parziale("_");
            interfaccia.a_capo();
            for (i=0; i<num; i++) //stampo la lista di tutti gli elementi che hanno corrispondenza con l'input
            {
                interfaccia.scrivi_parziale(i+1);
                interfaccia.scrivi_parziale(")");
                interfaccia.scrivi(risultati.leggilista(pos).leggietichetta().leggiluogo());
                pos=risultati.succlista(pos);
            }
            for (i=0; i<100; i++)
                interfaccia.scrivi_parziale("_");
            interfaccia.a_capo();
            interfaccia.scrivi_parziale("Selezionare il risultato cercato, digitare 0 per annullare :");
            cin>>scelta; //scelta di quello cercato tramite un menu
            if (cin.fail())
            {
                scelta=num+1;
                cin.clear();
            }
            if (scelta==0)
            {
                rif=*fittizio;
                interfaccia.scrivi("Annullamento...");
            }
            else if (scelta>0 && scelta<=num)
            {
                pos=risultati.primolista();
                for (i=0; i<scelta-1; i++)
                {
                    pos=risultati.succlista(pos);
                }
                return(risultati.leggilista(pos).legginodo());
            }
            else
            {
                interfaccia.scrivi("Scelta non valida, inserire un input valido");
                system("pause");
            }
        }
    }
    else
    {
        interfaccia.scrivi_parziale("Nessun risultato trovato per \"");
        interfaccia.scrivi_parziale(pattern);
        interfaccia.scrivi("\"");
        system("pause");
    }
    return(rif);
}

Grafo<Mappa::etichetta,Mappa::peso>::nodo Mappa::nodo_da_input(string pattern,int civico) //avendo dato anche il numero civico,si tratta di una via
{
    //per cui non si cerca nel nome dei luoghi (analoga a nodo_da_input(string)
    Grafo<etichetta,peso>::nodo rif=*fittizio;
    int i=0;
    string testo;
    int num=0;
    Lista<riferimento> risultati;
    Lista<riferimento>::posizione pos=risultati.primolista();
    bool trovato;
    int minimo,massimo;
    string testo_low,pattern_low;
    pattern_low=minuscolo(pattern);
    while (i<numnodi)
    {
        Lista<Vialuogo> vie=riferimenti[i].leggietichetta().leggivie();
        Lista<Vialuogo>::posizione ind=vie.primolista();
        trovato=false;
        while (!vie.finelista(ind) && !trovato)
        {
            testo=vie.leggilista(ind).legginome();
            minimo=vie.leggilista(ind).leggimin();
            massimo=vie.leggilista(ind).leggimax();
            testo_low=minuscolo(testo);
            trovato=multi_string_matching(testo_low,pattern_low);
            trovato=(trovato && (civico>=minimo && civico<=massimo));
            ind=vie.succlista(ind);
        }
        if (trovato)
        {
            risultati.inslista(riferimenti[i],pos);
            num++;
        }
        i++;
    }
    int scelta=num+1;
    if (num>0)
    {
        while (scelta!=0)
        {
            //system("cls"); windows
            system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
            fflush(stdin);
            pos=risultati.primolista();
            cout<<"RISULTATI PER \""<<pattern<<"\""<<endl;
            cout<<"(i risultati contengono tutti i luoghi nelle immediate vicinanze della via che contiene la stringa in input)"<<endl;
            for (i=0; i<100; i++)
                cout<<"_";
            cout<<endl;
            for (i=0; i<num; i++)
            {
                cout<<i+1<<")"<<risultati.leggilista(pos).leggietichetta().leggiluogo()<<endl;
                pos=risultati.succlista(pos);
            }
            for (i=0; i<100; i++)
                cout<<"_";
            cout<<endl<<"Selezionare il risultato cercato, digitare 0 per annullare :";
            cin>>scelta;
            if (cin.fail())
            {
                scelta=num+1;
                cin.clear();
            }
            if (scelta==0)
            {
                cout<<"Annullamento..."<<endl;
                ////system("pause");
            }
            else if (scelta>0 && scelta<=num)
            {
                pos=risultati.primolista();
                for (i=0; i<scelta-1; i++)
                {
                    pos=risultati.succlista(pos);
                }
                return(risultati.leggilista(pos).legginodo());
            }
            else
            {
                cout<<"Scelta non valida, inserire un input valido"<<endl;
                //system("pause");
            }
        }
    }
    else
    {
        cout<<"Nessun risultato trovato per \""<<pattern<<" "<<civico<<"\""<<endl;
        //system("pause");
    }
    return(rif);
}

void Mappa::cammino_ottimo() //calcola il cammino ottimo tra partenza e arrivo secondo le opzioni salvate
{
    if (!(arrivo==*fittizio))
    {
        char orizz=205; //carattere per la stampa delle cornici
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi("Tragitto :");
        for (int i=0; i<100; i++)
            interfaccia.scrivi_carattere(orizz);
        if (arrivo==*fittizio)
            interfaccia.scrivi("Non hai definito il luogo di arrivo, impossibile calcolare il percorso ...");     // controlli vari
        interfaccia.a_capo();
        if (arrivo==partenza)
            interfaccia.scrivi("Il luogo di partenza coincide con quello di arrivo, non e' necessario continuare !");
        interfaccia.a_capo();
        bool problemi=(partenza==*fittizio || arrivo==*fittizio || arrivo==partenza);
        if (!problemi) //se non si è verificata una delle condizioni precedenti
        {
            //controllo prima se ho il cammino sul file
            ifstream f("Cammini.nav",ios::in);
            if (f.good())
            {
                Coda< Grafo<etichetta,peso>::nodo > cammino; //coda che conterrà la sequenza del cammino
                string buffer; //conterrà le righe del file
                int inizio; //per l'estrazione
                etichetta::ID id_s,id_d,id_nodo,scelta_file,evita_sterrato_file,evita_pedaggi_file; //dati da leggere dal file
                Grafo<etichetta,peso>::nodo sorg,dest,node; //nodi sorgente e destinazione
                while (!f.eof())
                {
                    inizio=0;
                    getline(f,buffer);//leggo una riga dal file
                    scelta_file=atoi(estrai(buffer,inizio,',').c_str()); //prendo il campo scelta dal file
                    evita_sterrato_file=atoi(estrai(buffer,inizio,',').c_str()); //prendo il campo evita_sterrato dal file
                    evita_pedaggi_file=atoi(estrai(buffer,inizio,',').c_str()); //prendo il campo evita_pedaggi dal file
                    id_s=atoi(estrai(buffer,inizio,',').c_str()); //prendo l'id della sorgente
                    id_d=atoi(estrai(buffer,inizio,',').c_str()); //prendo l'id della destinazione
                    sorg=nodo_da_id(id_s); //prendo il nodo il cui id nell'etichetta è id_s
                    dest=nodo_da_id(id_d); //prendo il nodo il cui id nell'etichetta è id_d
                    if (distanza_tempo==scelta_file && evita_sterrato==evita_sterrato_file && evita_pedaggi==evita_pedaggi_file && sorg==partenza && dest==arrivo)
                        //se le opzioni, sorgente e destinazione letti da file solo gli stessi inseriti in input
                    {
                        //ho già il cammino calcolato, quindi lo inserisco nella coda
                        while (inizio<buffer.length())
                        {
                            id_nodo=atoi(estrai(buffer,inizio,',').c_str()); //prendo l'id del nodo
                            node=nodo_da_id(id_nodo); //prendo il nodo il cui id nell'etichetta è id_node
                            cammino.incoda(node); //incodo quel nodo
                        }
                    }
                }
                if (cammino.codavuota()) //se non ho nel file il cammino che cerco
                {
                    ofstream f("Cammini.nav",ios::app); //apro il file in modalità scrittura (salverò il cammino che calcolerò)
                    Pila< Grafo<etichetta,peso>::nodo > cammino; //pila che conterrà la sequenza del cammino che sarà calcolato
                    nodo_prec* T;
                    T=Dijkstra(partenza); //calcolo dijkstra radicato nel nodo di partenza (ottengo il vettore di predecessori)
                    cammino=cammino_da_dijkstra(T,arrivo); //(ricavo il cammino da partenza ad arrivo)
                    if (!cammino.pilavuota())
                        indicazioni_file(f,cammino,partenza,arrivo); //se il cammino esiste lo salvo su file
                    else
                        interfaccia.scrivi("Non esiste cammino, secondo le opzioni scelte");
                }
                else //altrimenti ho il cammino e ne stampo le indicazioni
                {
                    indicazioni(cammino);
                }
                f.close();
                f.clear();
            }
            else //se il file non esiste (situazione identica al caso in cui non ho il cammino nel file)
            {
                ofstream f("Cammini.nav",ios::app);
                Pila< Grafo<etichetta,peso>::nodo > cammino;
                nodo_prec* T;
                T=Dijkstra(partenza);
                cammino=cammino_da_dijkstra(T,arrivo);
                if (!cammino.pilavuota())
                    indicazioni_file(f,cammino,partenza,arrivo);
                else
                    interfaccia.scrivi("Non esiste cammino, secondo le opzioni scelte");
            }
        }
    }
    else
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi("Non hai definito il luogo di destinazione");
    }
}

string Mappa::estrai(string s,int& inizio,char sep) //estrae la parte di stringa che va dal carattere in posizione inizio fino al separatore
{
    string estratto="";
    while(s[inizio]!=sep && inizio<s.length())
    {
        estratto+=s[inizio];
        inizio++;
    }
    inizio++;
    return(estratto);
}

string Mappa::minuscolo(string s)// rende "minuscola" la stringa passata in input
{
    string s_low=s;
    for (int i=0; i<s_low.length(); i++)
    {
        s_low[i]=tolower(s[i]);
    }
    return (s_low);
}

bool Mappa::multi_string_matching(string testo,string pattern)
{
    Lista<string> patterns; //parti che contengono il pattern
    Lista<string>::posizione ind=patterns.primolista();
    string estratto;
    int inizio=0,pos;
    bool trovato=true;
    while (inizio<pattern.length())
    {
        estratto=estrai(pattern,inizio,' ');
        if (estratto!="")
            patterns.inslista(estratto,ind);    //estraggo tutte le stringhe del pattern separate dallo spazio
    }
    ind=patterns.primolista();
    while (!patterns.finelista(ind) && trovato) //eseguo il tradizionale string matching tra testo e tutte le parti del pattern
    {
        pos=testo.find(patterns.leggilista(ind));
        trovato=(trovato && pos!=-1);
        ind=patterns.succlista(ind);
    } // l'esito è positivo se e sole se ogni parte del pattern ha corrispondenza nel testo
    return (trovato);
}

Mappa::nodo_prec* Mappa::Dijkstra(Grafo<etichetta,peso>::nodo r) //Dijkstra radicato in r
{
    nodo_prec* T=new nodo_prec[numnodi]; //vettore di predecessori che sarà restituito
    float costi[numnodi]; //vettore dei costi del cammino da r al nodo i-esimo
    float costo; //costo che sarà tempo o lunghezza
    nodo_prec temp; //variabile di comodo
    Grafo<etichetta,peso>::nodo i,j; //nodi di comodo
    unsigned int cursore_i,cursore_j; //cursori di comodo
    Prioricoda<nodo_cur> S; //prioricoda di nodi con le relative distanza da r
    Priorielem<nodo_cur> e; //comodo
    nodo_cur comodo; //comodo
    int k,l; //indici per i cicli
    Lista< Grafo<etichetta,peso>::nodo > adiac; //avrà gli adiacenti di ogni nodo ad ogni passo
    temp.scrivinodo(r); //        ------+
    temp.scrivipredecessore(-1);//      |
    T[0]=temp;//                        + ---- inizializzazione delle info di r
    costi[0]=0;//              ---------+
    k=1;
    l=0;
    bool pedaggio,asfalto; //parte dei pesi degli archi letti passo per passo
    bool problemi;
    while (k<numnodi)//-------------------------------------------------------------+
    {
        //                                                                             |
        //                                                                          |
        i=riferimenti[l].legginodo(); //prendo tutti i nodi del grafo               |
        if (i!=r)         // se il nodo corrente non è r                            |
        {
            //                                                                         |
            //                                                                      |
            temp.scrivinodo(i);  // lo inserisco in T                               +---- inizializzazione info degli altri nodi
            temp.scrivipredecessore(-1); // il suo predecessore fittizio non esiste |
            T[k]=temp;    //                                                        |
            costi[k]=999999; // la distanza da r è infinito (non sono collegati)    |
            k++; //                                                                 |
            l++;   //                                                               |
        }   //                                                                      |
        else
            l++; //altrimenti lo salto --------------------------------------------+
    }
    comodo.scrivinodo(r);
    comodo.scrivicursore(0);
    e.scrivielem(comodo);
    e.scrivipriorita(0);
    S.inserisci(e); //inserisco r nella coda per l'elaborazione
    bool trovato;
    while (!S.insiemevuoto()) //mentre non ho esaminato tutti i nodi del grafo
    {
        e=S.min();
        i=e.leggielem().legginodo();//prendo l'elemento il con costo da r minore
        cursore_i=e.leggielem().leggicursore();//prendo il cursore di tale elemento (per poi effettuare eventuali aggiornamenti)
        S.cancellamin(); //elimino il minimo dalla coda con priorità
        adiac=mappa->adiacenti(i); //ricavo gli adiacenti del nodo "migliore"
        Lista< Grafo<etichetta,peso>::nodo >::posizione p=adiac.primolista();
        while(!adiac.finelista(p)) //per tutti gli adiacenti del nodo
        {
            j=adiac.leggilista(p);
            trovato=false;
            k=1;
            while (k<numnodi && !trovato) //ricavo il cursore
            {
                if (T[k].legginodo()==j)
                {
                    trovato=true;
                    cursore_j=k;
                }
                k++;
            }
            if (distanza_tempo)
                costo=mappa->leggiarco(i,j).leggilunghezza(); //se distanza_tempo=true considero distanza
            else
                costo=mappa->leggiarco(i,j).leggitempo(); //altrimenti considero tempo
            pedaggio=mappa->leggiarco(i,j).leggipedaggio(); //leggo pedaggio
            asfalto=mappa->leggiarco(i,j).leggiasfalto(); //leggo asfalto
            problemi=false; //suppongo di non avere problemi con pedaggi o strade sterrate
            problemi=problemi || !(!evita_sterrato || (evita_sterrato && asfalto));
            problemi=problemi || !(!evita_pedaggi || (evita_pedaggi && !pedaggio));
            if (!problemi) //se l'arco letto rispetta le opzioni desiderate
            {
                if (costi[cursore_i]+costo<costi[cursore_j]) //controllo se conservo la sottostruttura ottima
                {
                    T[cursore_j].scrivipredecessore(cursore_i);// --+
                    costi[cursore_j]=costi[cursore_i]+costo;//      |
                    comodo.scrivinodo(j);//                         |
                    comodo.scrivicursore(cursore_j);//              +--- aggiornamenti dei predecessori e dei costi
                    e.scrivielem(comodo);//                         |
                    e.scrivipriorita(costi[cursore_j]);//-----------+
                    if (!S.appartiene(e)) //se il nodo (adiacente a quello che sto esaminando) non è già in coda
                    {
                        S.inserisci(e); //lo aggiungo
                    }
                }
            }
            p=adiac.succlista(p);
        }
    }
    return (T); //restituisce il vettore di predecessori
}

Grafo<Mappa::etichetta,Mappa::peso>::nodo Mappa::nodo_da_id(etichetta::ID e) //restituisce il nodo che ha l'ID passato in input
{
    Grafo<etichetta,peso>::nodo rif=*fittizio; //in caso di esito negativo
    int i=0;
    bool trovato=false;
    while (i<numnodi && !trovato) //ricerca con sentinella nel vettore con gli elementi (nodo-etichetta)
    {
        if (e==riferimenti[i].leggietichetta().leggiID())
        {
            rif=riferimenti[i].legginodo();
            trovato=true;
        }
        i++;
    }
    return(rif);
}

Pila< Grafo<Mappa::etichetta,Mappa::peso>::nodo > Mappa::cammino_da_dijkstra(nodo_prec* T,Grafo<etichetta,peso>::nodo d)
{
    //restituisce il cammino dalla radice del vettore risultato di Dijkstra al nodo d
    Pila< Grafo<etichetta,peso>::nodo > P; //uso la pila perchè il cammino lo memorizzo dalla destinazione alla sorgente usando l'accesso LIFO viene "ordinato")
    int k=0;
    bool trovato=false;
    while (k<numnodi && !trovato) //ricerco d nel vettore
    {
        if (T[k].legginodo()==d)
            trovato=true;
        else
            k++;
    }
    while (k>0) //mentre non sono arrivato alla radice o ho trovato un nodo senza predecessore
    {
        P.inpila(T[k].legginodo()); //inpilo il nodo
        k=T[k].leggipredecessore(); //passo al predecessore
    }
    if (k==0) //se mi sono fermato alla radice (l'ho saltata)
    {
        P.inpila(T[k].legginodo()); //inpilo la radice
    }
    else //altrimenti mi sono fermato in un nodo isolato
    {
        svuotaPila(P);//svuota la pila perchè non esiste un cammino dalla radice a d
    }
    return(P); //restituisco la pila
}

void Mappa::indicazioni(Coda< Grafo<etichetta,peso>::nodo > C) //stampa a video del cammino (questo metodo è richiamato quando ho già il cammino sul file)
{
    Grafo<etichetta,peso>::nodo s,d;
    string sorg,dest,nuova,vecchia,via;
    float distanza,dist_totale=0,tempo,tempo_totale=0; //informazioni sul costo del cammino
    s=C.leggicoda(); //nodo sorgente
    C.fuoricoda();
    d=C.leggicoda(); //nodo destinazione
    C.fuoricoda();
    sorg=mappa->legginodo(s).leggiluogo(); //campo nome dell'etichetta della sorgente
    dest=mappa->legginodo(d).leggiluogo(); //campo nome dell'etichetta della destinazione
    vecchia=mappa->leggiarco(s,d).leggidirezione(); //leggo la direzione dal peso dell'arco che va da sorgente a destinazione
    nuova=vecchia;
    distanza=mappa->leggiarco(s,d).leggilunghezza(); //leggo la lunghezza dal peso dell'arco che va da sorgente a destinazione
    tempo=mappa->leggiarco(s,d).leggitempo(); //leggo il tempo dal peso dell'arco che va da sorgente a destinazione
    dist_totale+=distanza; //aggiorno distanza totale
    tempo_totale+=tempo; //aggiorno tempo totale
    via=mappa->leggiarco(s,d).legginome(); //leggo il nome della via dal peso dell'arco che va da sorgente a destinazione
    //stampa prima indicazione usando riferimenti assoluti
    if ( (vecchia=="scendi") )
    {
        interfaccia.scrivi_parziale("Da ");
        interfaccia.scrivi_parziale(sorg);
        interfaccia.scrivi_parziale(" scendere e proseguire per ");
        interfaccia.scrivi_parziale(distanza);
        interfaccia.scrivi_parziale(" metri fino a raggiungere ");
        interfaccia.scrivi(dest);
        interfaccia.a_capo();
    }
    else
    {
        if ( (vecchia=="sali") )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" salire e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        else
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" dirigersi verso ");
            interfaccia.scrivi_parziale(nuova);
            interfaccia.scrivi_parziale(" per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
    }
    while(!C.codavuota()) //finchè ci sono altri nodi nella sequenza
    {
        s=d; //la vecchia destinazione diventa sorgente
        sorg=dest;
        d=C.leggicoda(); //nuovo nodo destinazione
        C.fuoricoda();
        dest=mappa->legginodo(d).leggiluogo(); //campo nome dell'etichetta della destinazione
        vecchia=nuova; //tengo conto della vecchia direzione (in assoluto) per calcolare la direzione dello spostamento (in relativo)
        nuova=mappa->leggiarco(s,d).leggidirezione(); //leggo la direzione dal peso dell'arco che va da sorgente a destinazione
        distanza=mappa->leggiarco(s,d).leggilunghezza(); //leggo la lunghezza dal peso dell'arco che va da sorgente a destinazione
        tempo=mappa->leggiarco(s,d).leggitempo(); //leggo il tempo dal peso dell'arco che va da sorgente a destinazione
        dist_totale+=distanza;
        tempo_totale+=tempo;
        via=mappa->leggiarco(s,d).legginome(); //leggo il nome della via dal peso dell'arco che va da sorgente a destinazione
        //gli IF che seguono sono eslcusivi per cui non c'è bisogno di annidarli
        if (vecchia==nuova) //se lo spostamento di prima e il corrente hanno stesso verso e direzione
        {
            //allora bisogna proseguire diritto/lungo la strada e non stampo il nome della via perchè è sempre la stessa)
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (vecchia=="est" && nuova=="sud") || (vecchia=="sud" && nuova=="ovest") || (vecchia=="ovest" && nuova=="nord") || (vecchia=="nord" && nuova=="est") )
        {
            //se il nuovo spostamento è a destra rispetto al vecchio bisogna svoltare a destra
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" girare a destra e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (vecchia=="est" && nuova=="nord") || (vecchia=="sud" && nuova=="est") || (vecchia=="ovest" && nuova=="sud") || (vecchia=="nord" && nuova=="ovest") )
        {
            //se il nuovo spostamento è a destra rispetto al vecchio bisogna svoltare a sinistra
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" girare a sinistra e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (nuova=="scendi") )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" scendere e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (nuova=="sali") )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" salire e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
    }
    interfaccia.scrivi_parziale("Distanza dal punto in cui ti trovi : \t\t");
    interfaccia.scrivi_parziale(dist_totale);
    interfaccia.scrivi(" metri.");
    interfaccia.scrivi_parziale("Tempo per raggiungere la destinazione : \t");
    interfaccia.scrivi_parziale(tempo_totale);
    interfaccia.scrivi(" secondi.");
    system("pause");
}

void Mappa::indicazioni_file(ofstream& f,Pila< Grafo<etichetta,peso>::nodo > P,Grafo<etichetta,peso>::nodo s,Grafo<etichetta,peso>::nodo d)
{
    //analogo al precedente, ma viene richiamato quando il cammino non esiste su file ed è calcolato (in più c'è il salvataggio del cammino sul file)
    f<<distanza_tempo<<","<<evita_sterrato<<","<<evita_pedaggi<<","; //salvo le impostazioni
    f<<mappa->legginodo(s).leggiID(); //salvo sorgente
    f<<","<<mappa->legginodo(d).leggiID(); //salvo destinazione
    string sorg,dest,nuova,vecchia,via;
    float distanza,dist_totale=0,tempo,tempo_totale=0;
    s=P.leggipila(); //nodo sorgente
    P.fuoripila();
    d=P.leggipila(); //nodo destinazione
    P.fuoripila();
    sorg=mappa->legginodo(s).leggiluogo(); //campo nome dell'etichetta della sorgente
    dest=mappa->legginodo(d).leggiluogo(); //campo nome dell'etichetta della destinazione
    vecchia=mappa->leggiarco(s,d).leggidirezione(); //leggo la direzione dal peso dell'arco che va da sorgente a destinazione
    nuova=vecchia;
    distanza=mappa->leggiarco(s,d).leggilunghezza(); //leggo la lunghezza dal peso dell'arco che va da sorgente a destinazione
    tempo=mappa->leggiarco(s,d).leggitempo(); //leggo il tempo dal peso dell'arco che va da sorgente a destinazione
    dist_totale+=distanza;
    tempo_totale+=tempo;
    via=mappa->leggiarco(s,d).legginome(); //leggo il nome della via dal peso dell'arco che va da sorgente a destinazione
    //stampa prima indicazione usando riferimenti assoluti
    if ( (vecchia=="scendi") )
    {
        interfaccia.scrivi_parziale("Da ");
        interfaccia.scrivi_parziale(sorg);
        interfaccia.scrivi_parziale(" scendere e proseguire per ");
        interfaccia.scrivi_parziale(distanza);
        interfaccia.scrivi_parziale(" metri fino a raggiungere ");
        interfaccia.scrivi(dest);
        interfaccia.a_capo();
    }
    else
    {
        if ( (vecchia=="sali") )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" salire e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        else
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" dirigersi verso ");
            interfaccia.scrivi_parziale(nuova);
            interfaccia.scrivi_parziale(" per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
    }
    f<<","<<mappa->legginodo(s).leggiID(); //salvo nuovamente sorgente
    f<<","<<mappa->legginodo(d).leggiID(); //salvo nuovamente destinazione
    while(!P.pilavuota()) //finchè ci sono altri nodi nella sequenza
    {
        s=d; //la vecchia destinazione diventa sorgente
        sorg=dest;
        d=P.leggipila(); //nuovo nodo destinazione
        P.fuoripila();
        dest=mappa->legginodo(d).leggiluogo(); //campo nome dell'etichetta della destinazion
        vecchia=nuova; //tengo conto della vecchia direzione (in assoluto) per calcolare la direzione dello spostamento (in relativo)
        nuova=mappa->leggiarco(s,d).leggidirezione(); //leggo la direzione dal peso dell'arco che va da sorgente a destinazione
        distanza=mappa->leggiarco(s,d).leggilunghezza(); //leggo la lunghezza dal peso dell'arco che va da sorgente a destinazione
        tempo=mappa->leggiarco(s,d).leggitempo(); //leggo il tempo dal peso dell'arco che va da sorgente a destinazione
        dist_totale+=distanza;
        tempo_totale+=tempo;
        via=mappa->leggiarco(s,d).legginome(); //leggo il nome della via dal peso dell'arco che va da sorgente a destinazione
        //gli IF che seguono sono eslcusivi per cui non c'è bisogno di annidarli
        if (vecchia==nuova) //se lo spostamento di prima e il corrente hanno stesso verso e direzione
        {
            //allora bisogna proseguire diritto
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (vecchia=="est" && nuova=="sud") || (vecchia=="sud" && nuova=="ovest") || (vecchia=="ovest" && nuova=="nord") || (vecchia=="nord" && nuova=="est") )
        {
            //se il nuovo spostamento è a destra rispetto al vecchio bisogna svoltare a destra
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" girare a destra e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (vecchia=="est" && nuova=="nord") || (vecchia=="sud" && nuova=="est") || (vecchia=="ovest" && nuova=="sud") || (vecchia=="nord" && nuova=="ovest") )
        {
            //se il nuovo spostamento è a destra rispetto al vecchio bisogna svoltare a sinistra
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" girare a sinistra e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }
        if ( (nuova=="scendi" ) )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" scendere e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();

        }
        if ( (nuova=="sali" ) )
        {
            interfaccia.scrivi_parziale("Da ");
            interfaccia.scrivi_parziale(sorg);
            interfaccia.scrivi_parziale(" salire e proseguire per ");
            interfaccia.scrivi_parziale(distanza);
            interfaccia.scrivi_parziale(" metri fino a raggiungere ");
            interfaccia.scrivi(dest);
            interfaccia.a_capo();
        }

        f<<","<<mappa->legginodo(d).leggiID(); //salvo gli altri nodi della sequenza
    }
    interfaccia.scrivi_parziale("Distanza dal punto in cui ti trovi : \t\t");
    interfaccia.scrivi_parziale(dist_totale);
    interfaccia.scrivi(" metri.");
    interfaccia.scrivi_parziale("Tempo per raggiungere la destinazione : \t");
    interfaccia.scrivi_parziale(tempo_totale);
    interfaccia.scrivi(" secondi.");
    interfaccia.a_capo();
    f<<endl;
    f.close();
    f.clear();
}

void Mappa::cambia_opzioni()//permette di cambiare le opzioni su cui si baserà il calcolo del cammino migliore tramite un menu
{
    char orizz=205; //carattere per la stampa delle cornici
    int scelta;
    do
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        fflush(stdin);
        interfaccia.scrivi("\t\t\t\t\t\t\t\tOPZIONI PER LA SCELTA DEL CAMMINO");
        for (int i=0; i<100; i++)
            interfaccia.scrivi_carattere(orizz);
        interfaccia.a_capo();
        interfaccia.scrivi_parziale("1) CRITERIO : ");
        if (distanza_tempo)
            cout<<"distanza"<<endl;
        else
            cout<<"tempo"<<endl;
        cout<<"2) EVITARE STRADE NON ASFALTATE : ";
        if (evita_sterrato)
            cout<<"si"<<endl;
        else
            cout<<"no"<<endl;
        cout<<"3) EVITARE STRADE CON PEDAGGIO : ";
        if (evita_pedaggi)
            cout<<"si"<<endl;
        else
            cout<<"no"<<endl;
        for (int i=0; i<100; i++)
            cout<<"_";
        cout<<"Selezionare il parametro da cambiare (premere 0 per uscire dalle opzioni) : ";
        cin>>scelta;
        if (cin.fail())
        {
            scelta=4;
            cin.clear();
        }
        switch (scelta)
        {
        case 1:
            distanza_tempo=!distanza_tempo;
            break;
        case 2:
            evita_sterrato=!evita_sterrato;
            break;
        case 3:
            evita_pedaggi=!evita_pedaggi;
            break;
        case 0:
            cout<<"Ritorno al menu principale ..."<<endl;
            break;
        default:
            cout<<"Input non valido, inserire un input corretto"<<endl;
            //system("pause");
            break;
        }
    }
    while (scelta!=0);
}

//Inizio modifica
void Mappa::setsuggerimenti(ifstream& file) //costruisce l'albero dei suggerimenti da file
{
    char b[100]; //array di caratteri d'appoggio
    int cont = 0;
    if(!file.eof())
    {
        do
        {
            file.getline(b,100,','); //leggo dal file "Mappa.nav" una stringa di caratteri fino a che non incontra un punto e virgola
            if(b[0] >= 'A' && b[0] <= 'Z') //se il primo carattere è una lettera maiuscola allora è un luogo o un indirizzo e quindi viene inserito
            {
                do //scandisce l'array e inserisce lettera per lettera il luogo o l'indirizzo nell'albero
                {
                    if(na.foglia(n)) //se il nodo dell'albero non ha figli allora inserisco direttamente la lettera dell'albero come primo figlio...
                    {
                        inssottoalbero(b[cont],n,n);
                        na.scrivinodo(b[cont++],n); //inserisco l'elemento
                    }
                    else //... altrimenti lo inserisco come fratello dei figli già presenti, a meno che quella lettera non è già presente tra i figli
                    {
                        nalbero<char>::nodo f = n;
                        n = na.primofiglio(f);
                        inssottoalbero(b[cont],f,n);
                        na.scrivinodo(b[cont++],n); //inserisco l'elemento
                    }
                }
                while(b[cont] != '\0');
            }
            cont = 0;
            n = na.radice(); //una volta inserito un luogo o un indirizzo ritorno alla radice e ricomincio il ciclo...
        }
        while(!file.eof());//... finchè non finisce il file
    }
}

string Mappa::getsuggerimenti(string input,string Partarr) //ritorna la stringa presa in input o scelta tra i suggerimenti messi a disposizione e ne stampa a video i risultati in tempo reale
{
    char orizz=205; //caratteri per la stampa delle cornici
    string app,partarr = minuscolo(Partarr);
    char ch;
    int length,scelta;
    //system("cls"); windows
    system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
    interfaccia.scrivi_parziale("Scelta del luogo di ");
    interfaccia.scrivi_parziale(Partarr);
    interfaccia.a_capo();
    for (int i=0; i<100; i++)
        interfaccia.scrivi_carattere(orizz);
    interfaccia.scrivi_parziale("Inserisci il luogo di ");
    interfaccia.scrivi_parziale(partarr);
    interfaccia.scrivi(" o digita:");
    interfaccia.scrivi("- '?' per scegliere tra i suggerimenti delle parole");
    interfaccia.scrivi("- '*' per scegliere tra i suggerimenti delle frasi");
    interfaccia.scrivi("- '&' per scegliere tra la cronologia");
    interfaccia.scrivi("- 'invio' per scegliere tra tutti i luoghi");
    interfaccia.a_capo();
    interfaccia.scrivi_parziale("--> ");
    fflush(stdin);
    ch = std::cin.get();
    //ch = getch(); //prendo in input un carattere
    Pila<char> p; //pila di appoggio per i suggerimenti
    ins = new Lista<char*>; //lista che conterrà tutti i suggerimenti possibili a partire dalla parola scritta in input
    Lista<char*>::posizione pos = ins->primolista();
    while(ch != '\n') //se il carattere digitato è diverso dall'invio allora incomincio la ricerca
    {
        na.annullavisita(na.radice()); //annullo la visita dei nodi dell'albero segnati come visitati in modo da non compromettere la ricerca dei suggerimenti
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi_parziale("Scelta del luogo di ");
        interfaccia.scrivi_parziale(Partarr);
        interfaccia.a_capo();
        for (int i=0; i<100; i++)
            interfaccia.scrivi_carattere(orizz);
        interfaccia.scrivi_parziale("Inserisci il luogo di ");
        interfaccia.scrivi_parziale(partarr);
        interfaccia.scrivi(" o digita:");
        interfaccia.scrivi("- '?' per scegliere tra i suggerimenti delle parole");
        interfaccia.scrivi("- '*' per scegliere tra i suggerimenti delle frasi");
        interfaccia.scrivi("- '&' per scegliere tra la cronologia");
        interfaccia.scrivi("- 'invio' per scegliere tra tutti i luoghi");
        interfaccia.a_capo();
        interfaccia.scrivi_parziale("--> ");
        if(ch == 8 && input.size() > 0) //--------------+
        {
            //                                            |
            app.assign(input,0,input.length()-1); //    +-\ se il carattere digitato è uguale al backspace e se precedentemente è già
            ch = input[input.length()-1]; //            +-/ stato digitato qualcosa allora cancella l'ultimo carattere digitato dalla stringa
            input.assign(app); //                       |
        } //--------------------------------------------+
        else if(ch != 8) //-----------------------------+
        {
            //                                            |
            if(ch != 63 && ch != 42 && ch != 38) //     |   se il carattere digitato è diverso dal backspace
            {
                //                                        +-> e se è diverso da '*', '?' e '&' (caratteri speciali che spiegherò successivamente)
                input.append(1,ch); //                  |   allora inserisco il carattere preso in input nella stringa
            } //                                        |
        } //--------------------------------------------+
        char* parola = new char[100];
        length = input.copy(parola,100,0); //copio il contenuto della stringa in un array di caratteri di appoggio che mi servirà per la ricerca
        parola[length] = '\0';
        interfaccia.scrivi(input);
        if(ch == 38) //--------------------------------+
        {
            //                                           |
            if(partarr.compare("partenza") == 0) //    |
            {
                //                                       |
                settapartenzacrono(); //               |   se il carattere digitato è uguale a '&' allora inserisco la partenza
            } //                                       +-\ o la destinazione dalla cronologia, partenza o destinazione identificati
            else //                                    +-/ dalla stringa presente in "partarr", e ritorno "&" per avvisare la funzione
            {
                //                                       |   da cui questa è stata richiamata che l'inserimento è avenuto tramite cronologia
                settaarrivocrono(); //                 |
            } //                                       |
            return "&"; //                             |
        } //-------------------------------------------+
        else if(ch != 63 || (ch == 63 && length == 0)) //se il carattere che è stato digitato è diverso da '?', oppure se è uguale a '?' e precedentemente non è stato digitato alcun carattere, allora procedo con i suggerimenti dei luoghi e degli indirizzi completi
        {
            for(int j=0; j<100; j++)
            {
                interfaccia.scrivi_parziale("_");
            }
            interfaccia.a_capo();
            interfaccia.scrivi("Suggerimenti frasi:");
            interfaccia.a_capo();
            nalbero<char>::nodo* nodi = new nalbero<char>::nodo[100];
            char* parola1;
            char* parola2;
            ins = new Lista<char*>;
            pos = ins->primolista();
            int i = 0;
            if(length >= 1) //-----------------------------------+
            {
                //                                                 |-\ se si è digitato almeno un carattere allora procedo con la ricerca di quel nodo nell'albero
                ricercanodo(i,nodi,parola[0],na.radice()); //    |-/ che contiene quel carattere il cui padre contiene uno spazio e lo salvo in un array
            } //-------------------------------------------------+
            int j = i;
            if(j != 0 && length == 1) //se ho trovato almeno un nodo e se si è digitato un solo carattere allora...
            {
                do
                {
                    j--;
                    parola1 = new char[100];
                    parola2 = new char[100];
                    input.copy(parola2,100,0); //... copio il contenuto della stringa degli input in un array di char di appoggio...
                    parola2[1] = '\0';
                    na.annullavisita(na.radice()); //... annullo la visita dei nodi dell'albero segnati come visitati in modo da non compromettere la ricerca dei suggerimenti...
                    while(ritornafrase(parola2,nodi[j])) //... e mi salvo tutto il sottoalbero di ciascun nodo in un array che ad ogni ciclo inizializzo ogni volta
                    {
                        nalbero<char>::nodo temp = na.padre(nodi[j]);
                        while(temp != na.radice()) //------------+
                        {
                            //                                     |   se il nodo di partenza non è figlio della radice allora
                            p.inpila(na.legginodo(temp)); //     +-> procedo a ritroso nell'albero salvando in una pila il contenuto
                            temp = na.padre(temp); //            |   di ciascun nodo fino ad arrivare alla radice
                        } //-------------------------------------+
                        int l = 0;
                        while(!p.pilavuota()) //-----------------+
                        {
                            //                                     |   se il nodo di partenza non è figlio della radice allora
                            parola1[l++] = p.leggipila(); //     +-> il contenuto della pila lo salvo dentro un altro array di appoggio
                            p.fuoripila(); //                    |   in modo da avere la parte iniziale del luogo o indirizzo
                        } //-------------------------------------+
                        parola1[l] = '\0';
                        strcat(parola1,parola2); //appendo all'ultimo array utilizzato il contenuto dell'array dove è memorizzata una stringa presa dal sottoalbero del nodo di partenza
                        ins->inslista(parola1,pos); //salvo quindi il luogo o indirizzo completo ottenuto in una lista
                        parola2 = new char[100];
                        parola1 = new char[100];
                        input.copy(parola2,100,0);
                        parola2[1] = '\0';
                    }
                    nalbero<char>::nodo temp = na.padre(nodi[j]); //----+
                    while(temp != na.radice()) //                       |
                    {
                        //                                                |
                        p.inpila(na.legginodo(temp)); //                |
                        temp = na.padre(temp); //                       |
                    } //                                                |
                    int l = 0; //                                       |
                    while(!p.pilavuota()) //                            +-> faccio per un'ultima volta i passaggi all'interno del while precedente
                    {
                        //                                                |
                        parola1[l++] = p.leggipila(); //                |
                        p.fuoripila(); //                               |
                    } //                                                |
                    parola1[l] = '\0'; //                               |
                    strcat(parola1,parola2); //                         |
                    ins->inslista(parola1,pos); //----------------------+
                    epurazione(); // procedo con l'eliminazione degli eventuali doppioni
                }
                while(j > 0); //finchè l'array dei nodi che ho trovato non termina
            }
            else if(length > 1 && ch != 63 && i != 0) //se sono stati digitati più caratteri l'ultimo è diverso da '?' ed è stato trovato almeno un nodo allora...
            {
                do //finchè non controllo tutti i nodi trovati (rigo 898)...
                {
                    j--;
                    nalbero<char>::nodo tempo = nodi[j];
                    int l = 1;
                    bool ok = true;
                    while(ok && parola[l] != '\0') //... finchè dalla parola digitata si ottengono dei suggerimenti...
                    {
                        tempo = na.primofiglio(tempo);
                        while(tolower(na.legginodo(tempo)) != tolower(parola[l]) && na.succnodo(tempo) != tempo && na.succnodo(tempo) != na.primofratello(tempo)) //----+
                        {
                            //                                                                                                                                            |-\ ... finchè uno dei figli non contiene il carattere presente nella stringa digitata
                            tempo = na.succnodo(tempo); //                                                                                                              |-/ e finchè ci sono altri fratelli, allora vado al fratello successivo...
                        } //--------------------------------------------------------------------------------------------------------------------------------------------+
                        if(tolower(na.legginodo(tempo)) == tolower(parola[l])) //---+
                        {
                            //                                                        +-\ ... se il nodo contiene il carattere in posizione l della stringa allora
                            l++; //                                                 +-/ incremento il contatore di quest'ultima e passo alla lettera successiva...
                        } //--------------------------------------------------------+
                        else //-----------------+
                        {
                            //                    +-\ ...altrimenti setto il booleano a false in quanto non sono
                            ok = false; //      +-/ stati trovati suggerimenti in quel nodo per quella stringa
                        } //--------------------+
                    }
                    if(parola[l] == '\0' && ok) //----------------------------------+
                    {
                        //                                                            |
                        parola1 = new char[100]; //                                 |
                        parola2 = new char[100]; //                                 |
                        input.copy(parola2,100,0); //                               |
                        na.annullavisita(na.radice()); //                           |
                        while(ritornafrase(parola2,tempo)) //                       |
                        {
                            //                                                        |
                            nalbero<char>::nodo temp = na.padre(nodi[j]); //        |
                            while(temp != na.radice()) //                           |
                            {
                                //                                                    |
                                p.inpila(na.legginodo(temp)); //                    |
                                temp = na.padre(temp); //                           |
                            } //                                                    |
                            l = 0; //                                               |
                            while(!p.pilavuota()) //                                |
                            {
                                //                                                    |
                                parola1[l++] = p.leggipila(); //                    |
                                p.fuoripila(); //                                   |
                            } //                                                    |
                            parola1[l] = '\0'; //                                   |
                            strcat(parola1,parola2); //                             +-\ se ho trovato almeno un suggerimento procedo a salvarli
                            ins->inslista(parola1,pos); //                          +-/ con lo stesso procedimento di prima (righe 906 - 948)
                            parola2 = new char[100]; //                             |
                            parola1 = new char[100]; //                             |
                            input.copy(parola2,100,0); //                           |
                        } //                                                        |
                        nalbero<char>::nodo temp = na.padre(nodi[j]); //            |
                        while(temp != na.radice()) //                               |
                        {
                            //                                                        |
                            p.inpila(na.legginodo(temp)); //                        |
                            temp = na.padre(temp); //                               |
                        } //                                                        |
                        l = 0; //                                                   |
                        while(!p.pilavuota()) //                                    |
                        {
                            //                                                        |
                            parola1[l++] = p.leggipila(); //                        |
                            p.fuoripila(); //                                       |
                        } //                                                        |
                        parola1[l] = '\0'; //                                       |
                        strcat(parola1,parola2); //                                 |
                        ins->inslista(parola1,pos); //                              |
                        epurazione(); //                                            |
                    } //------------------------------------------------------------+
                }
                while(j > 0);
            }
            pos = ins->primolista(); //ora procedo con la stampa: ci sono due diversi tipi di stampe:
            if(ch != 42 || (ch == 42 && length == 0)) //------------+
            {
                //                                                    |
                if(length >= 1 && !ins->listavuota()) //            |
                {
                    //                                                |
                    do //                                           |
                    {
                        //                                            |
                        interfaccia.scrivi(ins->leggilista(pos));// |
                        pos = ins->succlista(pos); //               |   1) se l'ultimo carattere digitato è diverso da '*' o se è uguale ad esso ma non è
                    } //                                            +-> stato digitato niente in precedenza, avvio la stampa normale, ovvero metto a
                    while(!ins->finelista(pos)); //                 |   video uno sotto l'altro tutti i suggerimenti dei luoghi e degli indirizzi trovati
                } //                                                |
                for(int j=0; j<100; j++) //                         |
                {
                    //                                                |
                    interfaccia.scrivi_parziale("_"); //            |
                } //                                                |
                interfaccia.a_capo(); //                            |                                     |
            } //----------------------------------------------------+
            else // 2)altrimenti procedo come segue:
            {
                do
                {
                    //system("cls"); windows
                    system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI //-------------------------------------------------------+
                    interfaccia.scrivi_parziale("Scelta del luogo di ");//                  |
                    interfaccia.scrivi(Partarr);//                                          |
                    for (i=0; i<100; i++)
                        interfaccia.scrivi_carattere(orizz); //           |
                    interfaccia.scrivi_parziale("Inserisci il luogo ");
                    interfaccia.scrivi_parziale(partarr);
                    interfaccia.scrivi(" o digita:");
                    interfaccia.scrivi("- '?' per scegliere tra i suggerimenti delle parole;");
                    interfaccia.scrivi("- '*' per scegliere tra i suggerimenti delle frasi;");
                    interfaccia.scrivi("- 'invio' per scegliere tra tutti i luoghi;");
                    interfaccia.scrivi("- '&' per scegliere tra la cronologia.");
                    interfaccia.a_capo();
                    interfaccia.scrivi_parziale("--> ");                                //  +-> pulisco lo schermo e ristampo tutto...
                    interfaccia.scrivi(input); //                                           |
                    for(int j=0; j<100; j++) //                                             |
                    {
                        //                                                                    |
                        interfaccia.scrivi_parziale("_");//                                 |
                    } //                                                                    |
                    interfaccia.a_capo();
                    interfaccia.scrivi("Suggerimenti frasi:");
                    interfaccia.a_capo();
                    i = 0;
                    do //-------------------------------------------------------------------+
                    {
                        //      |
                        interfaccia.scrivi_parziale(i+1);                               //  |
                        interfaccia.scrivi_parziale(") ");                             //    |
                        interfaccia.scrivi(ins->leggilista(pos)); //                            +-\ ... poi stampo i suggerimenti
                        pos = ins->succlista(pos); //                                       +-/ uno sotto l'altro numerandoli...
                        i++; //                                                             |
                    } //--------------------------------------------------------------------+
                    while(!ins->finelista(pos));
                    for(int j=0; j<100; j++)
                    {
                        interfaccia.scrivi_parziale("_");
                    }
                    interfaccia.a_capo();
                    interfaccia.scrivi_parziale("Digita il numero del suggerimento che si desidera: ");
                    fflush(stdin); //                                                       |
                    cin>>scelta; //                                                         |
                    if (cin.fail()) //                                                      +-\ ... faccio scegliere all'utente
                    {
                        //                                                                    +-/ il suggerimento che desidera...
                        scelta = i+1; //                                                    |
                        cin.clear(); //                                                     |
                    } //--------------------------------------------------------------------+
                    pos = ins->primolista();
                    if(scelta <= i && scelta > 0) //------------+
                    {
                        //                                        |
                        i = 1; //                               |
                        while(i < scelta) //                    |
                        {
                            //                                    |   ... se l'utente ha effettuato la scelta giusta
                            pos = ins->succlista(pos); //       +-> allora ritorno direttamente la stringa alla
                            i++; //                             |   funzione chiamante per successive elaborazioni...
                        } //                                    |
                        input = ins->leggilista(pos); //        |
                        return input; //                        |
                    } //----------------------------------------+
                    else //-------------------------------------------------------------+
                    {
                        //                                                                |
                        interfaccia.scrivi("Input non valido, inserisci un input corretto");    //  +-\ ...altrimenti faccio ripetere la scelta
                        interfaccia.scrivi_parziale(" ");//                             +-/ finchè non è nel range di quelle possibili
                        //system("pause"); //                                             |
                    } //----------------------------------------------------------------+
                }
                while(scelta > i);
            }
        }
        ins = new Lista<char*>; //da quì in poi il procedimento si ripete per le singole parole, seguendo lo stesso ragionamento fatto fin'ora
        pos = ins->primolista(); //commenterò solo quelle righe di codice che si differenziano da quelle precedenti
        parola = new char[100];
        length = input.length();
        input.copy(parola,100,0);
        parola[length] = '\0';
        for(int j=0; j<100; j++)
        {
            interfaccia.scrivi_parziale("_");
        }
        interfaccia.a_capo();
        interfaccia.scrivi("Suggerimenti parole:");
        interfaccia.a_capo();
        nalbero<char>::nodo* nodi = new nalbero<char>::nodo[100];
        int i = 0;
        if(length >= 1)
        {
            ricercanodo(i,nodi,parola[0],na.radice());
        }
        int j = i;
        if(length >= 1 && ch != ' ' && j != 0)
        {
            do
            {
                j--;
                nalbero<char>::nodo tempo = nodi[j];
                int l = 1;
                bool ok = true;
                while(ok && parola[l] != '\0')
                {
                    tempo = na.primofiglio(tempo);
                    while(tolower(na.legginodo(tempo)) != tolower(parola[l]) && na.succnodo(tempo) != tempo && na.succnodo(tempo) != na.primofratello(tempo))
                    {
                        tempo = na.succnodo(tempo);
                    }
                    if(tolower(na.legginodo(tempo)) == tolower(parola[l]))
                    {
                        l++;
                    }
                    else
                    {
                        ok = false;
                    }
                }
                if(parola[l] == '\0' && ok)
                {
                    int l = input.length()-1;
                    while(l >= 0 && input[l] != ' ') //-----+
                    {
                        //                                    +-\ siccome nella stringa presa in input possono trovarsi degli spazi,
                        l--; //                             +-/ scorro all'indietro quest'ultima fino a quando non trovo uno spazio...
                    } //------------------------------------+
                    char* parola2 = new char[100];
                    input.copy(parola2,100,l+1); //... dopodichè mi salvo l'ultima parola digitata in un array di appoggio
                    parola2[input.length()-l-1] = '\0';
                    na.annullavisita(na.radice());
                    while(ritornaparola(parola2,tempo)) //------+
                    {
                        //                                        |
                        ins->inslista(parola2,pos); //          |   mi salvo solo il sottoalbero di ciascun nodo trovato
                        parola2 = new char[100]; //             +-> nella ricerca precedente (riga 1120) fino a che non
                        input.copy(parola2,100,l+1); //         |   trovo uno spazio o finchè non arrivo ad un nodo foglia
                        parola2[input.length()-l-1] = '\0'; //  |
                    } //----------------------------------------+
                    ins->inslista(parola2,pos);
                    epurazione();
                    parola2 = new char[100];
                }
            }
            while(j > 0);
        }
        pos = ins->primolista(); //ora procedo con la stampa: anche quì ci sono due diversi tipi di stampe:
        if(ch != 63 || (ch == 63 && length == 0)) //--------+
        {
            //                                                |
            if(length >= 1 && !ins->listavuota()) //        |
            {
                //                                            |
                do //                                       |
                {
                    //                                        |
                    interfaccia.scrivi(ins->leggilista(pos));
                    pos = ins->succlista(pos); //           |   1) se l'ultimo carattere digitato è diverso da '?' o se è uguale ad esso ma non è
                } //                                        |-> stato digitato niente in precedenza, avvio la stampa normale, ovvero metto a
                while(!ins->finelista(pos)); //             |   video uno sotto l'altro tutti i suggerimenti delle parole trovate
            } //                                            |
            for(int j=0; j<100; j++) //                     |
            {
                //                                            |
                interfaccia.scrivi_parziale("_");//         |
            } //                                            |
            interfaccia.a_capo();                        // |                                 |
        } //------------------------------------------------+
        else // 2)altrimenti procedo come segue:
        {
            do
            {
                //system("cls"); windows
                system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI //-------------------------------------------------------+
                interfaccia.scrivi_parziale("Scelta del luogo di ");//                  |
                interfaccia.scrivi(partarr);//                                          |
                for (i=0; i<100; i++)
                    interfaccia.scrivi_carattere(orizz);//            |
                interfaccia.scrivi_parziale("Inserisci il luogo ");//                   |
                interfaccia.scrivi_parziale(partarr);                               //  |
                interfaccia.scrivi(" o digita:");//                                     |
                interfaccia.scrivi("- '?' per scegliere tra i suggerimenti delle parole;");
                interfaccia.scrivi("- '*' per scegliere tra i suggerimenti delle frasi;");
                interfaccia.scrivi("- 'invio' per scegliere tra tutti i luoghi;");//    |
                interfaccia.scrivi("- '&' per scegliere tra la cronologia.");//         |
                interfaccia.a_capo();//                                                 |
                interfaccia.scrivi_parziale("--> ");                                //  +-> pulisco lo schermo e ristampo tutto...
                interfaccia.scrivi(input);//                                            |
                for(j=0; j<100; j++) //                                                 |
                {
                    //                                                                    |
                    interfaccia.scrivi_parziale("_");           //                      |                                           |
                } //                                                                    |
                interfaccia.a_capo();//                                                 |
                interfaccia.scrivi("Suggerimenti parole:");//                          |
                interfaccia.a_capo();                           //----------------------+
                i = 0;
                do //-------------------------------------------------------------------+
                {
                    //                                                                    |
                    interfaccia.scrivi_parziale(i+1);
                    interfaccia.scrivi_parziale(") ");
                    interfaccia.scrivi(ins->leggilista(pos));
                    pos = ins->succlista(pos); //                                       |
                    i++; //                                                             |
                } //--------------------------------------------------------------------+
                while(!ins->finelista(pos));
                for(j=0; j<100; j++)
                {
                    interfaccia.scrivi_parziale("_");
                }
                interfaccia.a_capo();
                interfaccia.scrivi_parziale("Digita il numero del suggerimento che si desidera: ");
                fflush(stdin); //                                                       |
                cin>>scelta; //                                                         |
                if (cin.fail()) //                                                      +-\ ... faccio scegliere all'utente
                {
                    //                                                                    +-/ il suggerimento che desidera...
                    scelta = i+1; //                                                    |
                    cin.clear(); //                                                     |
                } //--------------------------------------------------------------------+
                pos = ins->primolista();
                if(scelta <= i && scelta > 0) //------------------------------------+
                {
                    //                                                                |
                    j = 1; //                                                       |
                    while(j < scelta) //                                            |
                    {
                        //                                                            |
                        pos = ins->succlista(pos); //                               |
                        j++; //                                                     |   ... se l'utente ha effettuato la scelta giusta, allora nella stringa degli input
                    } //                                                            +-> partendo dalla fine vado a ritroso fino a che non arrivo all'inizio dell'ultima
                    j = input.length()-1; //                                        |   parola, poi appendo il suggerimento a partire da quel punto e continuo la ricerca...
                    while(j >= 0 && input[j] != ' ') //                             |
                    {
                        //                                                            |
                        j--; //                                                     |
                    } //                                                            |
                    input.append(ins->leggilista(pos),input.length()-j-1,100); //   |
                } //----------------------------------------------------------------+
                else //-------------------------------------------------------------+
                {
                    //                                                                |
                    interfaccia.scrivi("Input non valido, inserisci un input corretto"); //  +-\ ...altrimenti faccio ripetere la scelta
                    interfaccia.scrivi_parziale(" "); //                            |        +-/ ...finchè non è nel range di quelle possibili
                    //system("pause"); //                                             |
                } //----------------------------------------------------------------+
            }
            while(scelta > i);
        }
        if(ch != 63) //---------+
        {
            //                    |
            fflush(stdin); //   +-> se l'utente non ha chiesto i suggerimenti delle parole ('?') allora mi metto in attesa di un nuovo carattere...
            ch = std::cin.get(); //    |
        } //--------------------+
        else //-----------------------------------------+
        {
            //                                            |   ... altrimenti salvo l'ultimo carattere della sringa nella variabile ch,
            ch = input[input.length()-1]; //            +-\ che è quella dove salvo normalmente l'input da tastiera, e lo elimino
            app.assign(input,0,input.length()-1); //    +-/ dalla stringa, in modo che, al successivo giro, mi riaggiunga l'ultimo
            input.assign(app); //                       |   carattere e mi faccia uscire gli eventuali altri suggerimenti
        } //--------------------------------------------+
    }
    return input;
}

void Mappa::setcronologia(fstream& file) //carica la cronologia salvata in un file
{
    string b;
    if(!file.eof())
    {
        getline(file,b); //leggo una riga da file
        while(b[0] != ',') //finchè è diversa da ',', separatore tra cronologia delle partenze e cronologia degli arrivi...
        {
            partenze.inpila(b); //... inserisco nella pila delle partenze il contenuto della riga...
            getline(file,b); //... e leggo una nuova riga
        }
        getline(file,b);
        while(!file.eof()) //-----------+
        {
            //                            |
            arrivi.inpila(b); //        +-> finchè non arrivo alla fine del file faccio la stessa cosa per le destinazioni
            getline(file,b); //         |
        } //----------------------------+
    }
}

void Mappa::salvacronologia(fstream& file) //salva la cronologia delle partenze e degli arrivi su file
{
    file.open("Cronologia.odb",fstream::out);

    stampaPila(partenze,file,'\n');
    svuotaPila(partenze);
    file<<','<<endl; //quando la pila delle partenze è vuota, inserisco una virgola
    stampaPila(arrivi,file,'\n');
    svuotaPila(arrivi);
    file.close();
    file.clear();
}

void Mappa::aggiungiacrono(string luogo) //aggiungi partenza o destinazione appena digitata nella cronologia: banale
{
    if(luogo.compare("partenza") == 0)
    {
        partenze.inpila(legginomepartenza());
    }
    if(luogo.compare("arrivo") == 0)
    {
        arrivi.inpila(legginomearrivo());
    }
}

int Mappa::stampacrono(string luogo) //stampa la cronologia delle partenze o delle destinazioni ritornando il numero degli elementi
{
    Pila<string> temp; //mi creo una pila di appoggio che mi servirà più avanti
    int i = 0;
    if(luogo.compare("partenza") == 0) //se devo stampare la cronologia delle partenze allora...
    {
        while(!partenze.pilavuota()) //... finchè la pila non è vuota...
        {
            interfaccia.scrivi_parziale(" ");
            interfaccia.scrivi_parziale(i+1);
            interfaccia.scrivi_parziale(") ");
            interfaccia.scrivi(partenze.leggipila()); //... metto a video l'elemento della testa...
            temp.inpila(partenze.leggipila()); //... salvo il contenuto nella pila d'appoggio che mi sono creato in precedenza
            partenze.fuoripila(); //... ed elimino la testa della pila principale
            i++;
        }
        while(!temp.pilavuota()) //una volta stampato tutto il contenuto...
        {
            partenze.inpila(temp.leggipila()); //... riempio nuovamente la pila principale con gli stessi elementi e lo stesso ordine in cui li avevo precedentemente...
            temp.fuoripila(); //... grazie alla pila d'appoggio che mi sono creato e questa la svuoto perchè ormai non mi serve più
        }
    }
    else //---------------------------------------------------------+
    {
        //                                                            |
        while(!arrivi.pilavuota()) //                               |
        {
            //                                                        |
            interfaccia.scrivi_parziale(" ");//                     |
            interfaccia.scrivi_parziale(i+1);//                     |
            interfaccia.scrivi_parziale(") ");//                    |
            interfaccia.scrivi(arrivi.leggipila());   //            |
            temp.inpila(arrivi.leggipila()); //                     |
            arrivi.fuoripila(); //                                  |
            i++; //                                                 +-> ... altrimenti eseguo lo stesso procedimento con la cronologia delle destinazioni
        } //                                                        |
        while(!temp.pilavuota()) //                                 |
        {
            //                                                        |
            arrivi.inpila(temp.leggipila()); //                     |
            temp.fuoripila(); //                                    |
        } //                                                        |
    } //------------------------------------------------------------+
    return i;
}

void Mappa::cronologia() //setta il nodo di partenza o arrivo a partire dalla cronologia: banale
{
    int scelta;
    char orizz=205; //caratteri per la stampa delle cornici
    do
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        interfaccia.scrivi("Cronologia");
        for (int i=0; i<100; i++)
            interfaccia.scrivi_carattere(orizz);
        interfaccia.scrivi("Visualizzare la cronologia:");
        interfaccia.a_capo();
        interfaccia.scrivi("1) Partenze");
        interfaccia.scrivi("2) Arrivi");
        for (int i=0; i<100; i++)
            interfaccia.scrivi_parziale("_");
        interfaccia.a_capo();
        interfaccia.scrivi_parziale("Selezionare operazione o premi '0' per annullare: ");
        cin>>scelta;
        if (cin.fail())
        {
            scelta = 3;
            cin.clear();
        }
        switch(scelta)
        {
        case 0:
            interfaccia.scrivi("Annullamento...");
            break;
        case 1:
            settapartenzacrono();
            break;
        case 2:
            settaarrivocrono();
            break;
        default:
            interfaccia.scrivi("Input non valido, inserire un input corretto");
            //system("pause");
            break;
        }
    }
    while(scelta < 0 || scelta > 2);
}

void Mappa::settapartenzacrono() //setta la partenza da quelle disponibili nella cronologia delle partenze
{
    int scelta,i;
    string part;
    Pila<string> temp;
    Grafo<etichetta,peso>::nodo temp1;
    do
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        i = stampacrono("partenza"); //stampo la cronologia delle partenze
        cout<<endl;
        for(int j=0; j<100; j++)
        {
            cout<<"_";
        }
        cout<<endl;
        cout<<"Scegli il luogo da aggiungere o premi '0' per annullare: ";
        cin>>scelta;
        if (cin.fail())
        {
            scelta = i + 1;
            cin.clear();
        }
        if(scelta >= 0 && scelta <= i)
        {
            if(scelta == 0) //----------------------+
            {
                //                                    +-\ se inserisco '0' allora
                cout<<"Annullamento..."<<endl; //   +-/ annullo l'inserimento
            } //------------------------------------+
            else
            {
                int j = 0;
                while(!partenze.pilavuota() && j < scelta - 1) //-------+
                {
                    //                                                    |
                    temp.inpila(partenze.leggipila()); //               +-\ arrivo all'elemento della cronologia scelto dall'utente senza
                    partenze.fuoripila(); //                            +-/ perdere gli eventuali altri elementi della cronologia più recenti
                    j++; //                                             |
                } //----------------------------------------------------+
                part = partenze.leggipila(); //dopodichè salvo in contenuto in una stringa
                temp1 = nodo_da_input(part); //se non ho inserito numero civico cerco nei luoghi e nelle vie
                if (temp1 != *fittizio)
                {
                    partenza = temp1; //se ho avuto un occorrenza setto partenza
                }
                while(!temp.pilavuota()) //---------------------+
                {
                    //                                        |
                    partenze.inpila(temp.leggipila()); //   +-> riempio nuovamente la pila con gli eventuali elementi tolti precedentemente
                    temp.fuoripila(); //                    !
                } //----------------------------------------+
            }
        }
        else
        {
            cout<<"Input non valido, inserire un input corretto"<<endl;
            //system("pause");
            break;
        }
    }
    while(scelta < 0 || scelta > i);
}

void Mappa::settaarrivocrono() //setta la destinazione da quelle disponibili nella cronologia delle destinazioni: esattamente come il metodo precedente
{
    int scelta,i;
    string arr;
    Pila<string> temp;
    Grafo<etichetta,peso>::nodo temp1;
    do
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        i = stampacrono("arrivo");
        cout<<endl;
        for(int j=0; j<100; j++)
        {
            cout<<"_";
        }
        cout<<endl;
        if(i==0)
        {
            do
            {
                cout<<"La cronologia e' vuota premi '0' per tornare al menu' proncipale: ";
                cin>>scelta;
            }
            while((scelta != i));

        }
        else
        {
            do
            {
                cout<<"Digita il numero del luogo di destinazione: ";
                cin>>scelta;
            }
            while(!(scelta >= 0 && scelta <= i));
        }

        if (cin.fail())
        {
            scelta = i + 1;
            cin.clear();
        }
        if(scelta >= 0 && scelta <= i)
        {
            if(scelta == 0)
            {
                cout<<"Annullamento..."<<endl;
            }
            else
            {
                int j = 0;
                while(!arrivi.pilavuota() && j < scelta - 1)
                {
                    temp.inpila(arrivi.leggipila());
                    arrivi.fuoripila();
                    j++;
                }
                arr = arrivi.leggipila();
                temp1 = nodo_da_input(arr);
                if (temp1 != *fittizio)
                {
                    arrivo = temp1;
                }
                while(!temp.pilavuota())
                {
                    arrivi.inpila(temp.leggipila());
                    temp.fuoripila();
                }
            }
        }
        else
        {
            cout<<"Input non valido, inserire un input corretto"<<endl;
            //system("pause");
            break;
        }
    }
    while(scelta < 0 || scelta > i);
}

void Mappa::canccronologia() //cancella la cronologia delle partenze o degli arrivi: banale
{
    int scelta;
    char orizz=205; //caratteri per la stampa delle cornici
    do
    {
        //system("cls"); windows
        system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI
        cout<<"Cancella cronologia"<<endl;
        for (int i=0; i<100; i++)
            cout<<orizz;
        cout<<"Cancellare la cronologia:"<<endl<<endl<<"1) Partenze"<<endl<<"2) Arrivi"<<endl;
        for (int i=0; i<100; i++)
            cout<<'_';
        cout<<endl<<"Selezionare operazione o premi '0' per annullare: ";
        cin>>scelta;
        if (cin.fail())
        {
            scelta = 3;
            cin.clear();
        }
        cin.clear();
        cout.clear();
        fflush(stdin);
        switch(scelta)
        {
        case 0:
            cout<<"Annullamento..."<<endl;
            break;
        case 1:
            svuotaPila(partenze);
            break;
        case 2:
            svuotaPila(arrivi);
            break;
        default:
            cout<<"Input non valido, inserire un input corretto"<<endl;
            break;
        }
    }
    while(scelta < 0 || scelta > 2);
}

bool Mappa::ritornafrase(char* par,nalbero<char>::nodo nod) //ritorna true se è stata trovato un percorso non visitato dal nodo dato in input a una foglia, false altrimenti
{
    int cont = 0;
    while(par[cont] != '\0') //-----+
    {
        //                            +-\ finchè non arriva a fine parola
        cont++; //                  +-/ incrementa il contatore
    } //----------------------------+
    nalbero<char>::nodo temp = nod;
    while(!na.leggivisita(temp)) //finchè non trova un nodo già visitato...
    {
        if(!na.foglia(temp)) //... se il nodo non è una foglia...
        {
            temp = na.primofiglio(temp);//... allora vai a primo figlio...
            while(na.leggivisita(temp) && !na.finefratelli(temp) && na.succnodo(temp) != temp) //---+
            {
                //                                                                                    +-\ ... se temp è già stato visitato ed ha fratelli allora vado ai fratelli successivi
                temp = na.succnodo(temp); //                                                        +-/ fino a quando non trovo un nodo non visitato o arrivo all'ultimo fratello...
            } //------------------------------------------------------------------------------------+
            par[cont++] = na.legginodo(temp); //... e a questo punto inserisco in par l'elemento del nodo dove sono arrivato...
        }
        else //-----------------------------+
        {
            //                                +-\ ... altrimenti setto la
            na.settavisita(temp,true); //   +-/ visita per uscire dal ciclo
        } //--------------------------------+
    }
    par[cont] = '\0';
    if(na.foglia(temp)) //a questo punto, se sono arrivato ad una foglia, procedo a settare come visitato il primo antenato che ha un unico percorso che va' da quel nodo alla foglia temp
    {
        na.settavisita(temp,false); //risetto la foglia come non visitata
        nalbero<char>::nodo temp1 = temp;
        while((na.succnodo(temp1) == temp1 || na.leggivisita(temp1) || (na.succnodo(temp1) != temp1 && na.leggivisita(na.succnodo(temp1)))) && temp1 != nod) //-----+
        {
            //                                                                                                                                                        +-\ finchè il padre è figlio unico o è già stato
            temp1 = na.padre(temp1); //                                                                                                                             +-/ visitato o non è la radice, vado al padre
        } //--------------------------------------------------------------------------------------------------------------------------------------------------------+
        na.settavisita(temp1,true); //una volta uscito dal ciclo setto come visitato il nodo in questione
    }
    return !(!na.foglia(temp) || na.leggivisita(nod));
}

bool Mappa::ritornaparola(char* par,nalbero<char>::nodo nod) //ritorna true se è stata trovato un percorso non visitato dal nodo dato in input a una foglia o ad un nodo che contiene uno spazio, false altrimenti
{
    int cont = 0;
    while(par[cont] != '\0') //-----+
    {
        //                            +-\ finchè non arriva a fine parola
        cont++; //                  +-/ incrementa il contatore
    } //----------------------------+
    nalbero<char>::nodo temp = nod;
    while(!na.leggivisita(temp)) //finchè non trova un nodo già visitato...
    {
        if(!na.foglia(temp) && na.legginodo(temp) != ' ') //... se il nodo non è una foglia e l'elemento che contiene non è uno spazio...
        {
            temp = na.primofiglio(temp);//... allora vai a primo figlio...
            while(na.leggivisita(temp) && !na.finefratelli(temp) && na.succnodo(temp) != temp) //---+
            {
                //                                                                                    +-\ ... se temp è già stato visitato ed ha fratelli allora vado ai fratelli successivi
                temp = na.succnodo(temp); //                                                        +-/ fino a quando non trovo un nodo non visitato o arrivo all'ultimo fratello...
            } //------------------------------------------------------------------------------------+
            if(na.legginodo(temp) != ' ') //... se l'elemento non è uguale a uno spazio
            {
                par[cont] = na.legginodo(temp); //... a questo punto inserisco in par l'elemento del nodo dove sono arrivato...
                cont++;
            }
        }
        else //-----------------------------+
        {
            //                                +-\ ... altrimenti setto la
            na.settavisita(temp,true); //   +-/ visita per uscire dal ciclo
        } //--------------------------------+
    }
    par[cont] = '\0';
    if(na.foglia(temp) || na.legginodo(temp) == ' ') //a questo punto, se sono arrivato ad una foglia, procedo a settare come visitato il primo antenato che ha un unico percorso che va' da quel nodo alla foglia temp
    {
        na.settavisita(temp,false); //risetto la foglia come non visitata
        nalbero<char>::nodo temp1 = temp;
        while((na.succnodo(temp1) == temp1 || na.leggivisita(temp1) || (na.succnodo(temp1) != temp1 && na.leggivisita(na.succnodo(temp1)))) && temp1 != nod) //-----+
        {
            //                                                                                                                                                        +-\ finchè il padre è figlio unico o è già stato
            temp1 = na.padre(temp1); //                                                                                                                             +-/ visitato o non è la radice, vado al padre
        } //--------------------------------------------------------------------------------------------------------------------------------------------------------+
        na.settavisita(temp1,true); //una volta uscito dal ciclo setto come visitato il nodo in questione
    }
    return !((!na.foglia(temp) && na.legginodo(temp) != ' ') || (na.leggivisita(nod)));
}

void Mappa::ricercanodo(int& i,nalbero<char>::nodo* nodi,char e,nalbero<char>::nodo nod) //cerca all'interno dell'albero se è presente un nodo avente l'elemento passato in input
{
    if(!na.nalberovuoto()) //se 'albero non è vuoto procedo con la visita simmetrica...
    {
        if(!na.foglia(nod))
        {
            nalbero<char>::nodo temp = na.primofiglio(nod);
            ricercanodo(i,nodi,e,temp);
        }
        if(tolower(na.legginodo(nod)) == tolower(e) && na.legginodo(na.padre(nod)) == ' ') //---+
        {
            //                                                                                    +-\ ... se il nodo contiene l'elemento passato in input e il padre
            nodi[i++] = nod; //                                                                 +-/ ha come elemento uno spazio allora inserisco il nodo nell'array
        } //------------------------------------------------------------------------------------+
        if(na.succnodo(nod) != nod && na.succnodo(nod) != na.primofratello(nod))
        {
            nalbero<char>::nodo temp = na.succnodo(nod);
            ricercanodo(i,nodi,e,temp);
        }
    }
}

void Mappa::epurazione() //elimina eventuali parole presenti più di una volta all'interno della lista di quelle trovate nell'albero durante la ricerca dei suggerimenti
{
    if(!ins->listavuota())
    {
        Lista<char*>::posizione temp = ins->primolista();
        Lista<char*>::posizione cont = ins->succlista(temp);
        char* e = new char[100];
        while(!ins->finelista(temp))
        {
            e = ins->leggilista(temp);
            while(!ins->finelista(cont))
            {
                int i = 0;
                while(e[i] != '\0' && tolower(e[i]) == tolower(ins->leggilista(cont)[i]))
                {
                    i++;
                }
                if(e[i] == '\0' && e[i] == ins->leggilista(cont)[i])
                {
                    ins->canclista(cont);
                }
                else
                {
                    cont = ins->succlista(cont);
                }
            }
            temp = ins->succlista(temp);
            cont = ins->succlista(temp);
        }
    }
}

void Mappa::inssottoalbero(char e,nalbero<char>::nodo& nodp,nalbero<char>::nodo& nodf) //inserisce il nodo la cui posizione sarà identificata da due nodi
{
    if(nodp == nodf) //se i due puntatori puntano alla stessa cella allora...
    {
        nalbero<char>::nodo fig = na.nuovonodo(); //creo una nuova cella
        na.insarcofratelloprec(fig); //... setto temporaneamente come fratello precedente se stesso...
        na.insarcofratellosucc(fig); //... setto temporaneamente come fratello successivo se stesso...
        na.insarcopadre(nodp,fig); //... inserisco l'arco al padre...
        na.settavisita(fig,false); //... setto la visita a false...
        na.insarcofratello(fig,fig); //... setto definitivamente i fratelli (che in questo caso corrispondono a se stesso perchè è figlio unico)...
        na.settafiglio(fig); //... setto come figlio la cella stessa...
        nodf = fig; //... nodf che passo da input lo faccio puntare alla nuova cella creata...
        na.inccont(); //... incremento il contatore dei nodi dell'albero...
    }
    else if(nodp != nodf && controllo(e,nodf)) //... altrimenti se nodp punta al padre e nodf punta al figlio e se l'elemento da inserire non è già presente tra i figli di nodp...
    {
        nalbero<char>::nodo fig = na.nuovonodo(); //creo una nuova cella
        na.insarcofratelloprec(fig); //-----+
        na.insarcofratellosucc(fig); //     +-\ si procede come sopra
        na.insarcopadre(nodp,fig); //       +-/ (righi 81 - 86)
        na.settavisita(fig,false); //-------+
        na.insarcofratello(nodf,fig); //... setto definitivamente i fratelli (che in questo caso avverrà in ordine alfabetico)...
        na.settafiglio(fig); //---------+
        nodf = fig; //                  +-> si procede come sopra (righi 88 - 90)
        na.inccont(); //----------------+
    }
}

bool Mappa::controllo(char elem,nalbero<char>::nodo& nod) //ritorna true se tra i fratelli del nodo passato in input c'è lo stesso elemento passato anch'esso in input, false altrimenti
{
    nod = na.precnodo(na.primofratello(nod));
    bool diverso = true;
    do
    {
        nod = na.succnodo(nod);
        diverso = tolower(na.legginodo(nod)) != tolower(elem);
    }
    while(diverso && !na.finefratelli(nod));
    return diverso;
}

// Inizio Modifica Angelo Petronelli
Luogo Mappa::get_luogo(int id)
{
    return riferimenti[id-1-(inizio_mappa-1)].leggietichetta();
    // leggietichetta() restituisce un Luogo
    // (id – 1) perchè il vettore ‘riferimenti[]’ che contiene le coppie nodo_etichetta parte da
    // 0 mentre l’ ID dei luoghi parte da 1.
}

int Mappa::luogo_adiacente(int id, int direz)
{
    string direzioni;
    direzioni=get_luogo(id).leggidirezioni();
    return atoi(direzioni.substr(2*direz-2, 2).c_str());
}

string Mappa::get_nome_luogo(int id)
{
    return get_luogo(id).leggiluogo();
}

void Mappa::set_partenza_gioco(int id)
{
    partenza = riferimenti[id-1-(inizio_mappa-1)].legginodo();
    // legginodo(int) restituisce un Nodo
    // (id – 1) perchè il vettore ‘riferimenti[]’ che contiene le coppie nodo_etichetta parte da
    // 0 mentre l’ ID dei luoghi parte da 1.
}

void Mappa::set_destinazione_gioco()
{
    arrivo = *fittizio;
}
// Fine Modifica
