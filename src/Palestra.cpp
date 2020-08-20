#include "Palestra.h"

Lista<string> Palestra::listaSchede; //Lista contenente i nomi delle schede
Dizionario<string,Scheda> Palestra::schede;
Coda<int> fila;

void Palestra::usaTerminale()
{
    cout << "Benvenuto nella palestra personale del secondo pilota!\n";
    cout << "Se non sei stato invitato ti conviene sparire prima che torni :)\n";
    int n = 0;
    string scelta;
    bool menu = true;
    while(menu)
    {
        cout << "\nCosa vuoi sapere ?\n";
        cout << "1. Allenamento\n2. Panca\n3. Tapis\n4. Schede\n0. Esci\n";
        getline(cin, scelta);
        stringstream(scelta) >> n;
        switch (n)
        {
        case 1:
            cout << "\nUsa la panca per migliorare la tua costituzione fisica\n";
            cout << "o il tapis roulant per aumentare la tua resistenza.\n";
            cout << "Con una migliore costituzione sarai piu' resistente alle ferite\n";
            cout << "e con una maggiore resistenza potrai muoverti piu' velocemente per l'astronave" << endl;
            break;
        case 2:
            cout << "\nQuando ti eserciti con la panca ogni ripetizione aumenterà leggermente la tua costituzione\n" ;
            cout << "ma ricorda: fare gli addominali stanca! Fai una pausa tra una serie e l'altra\n";
            cout << "oppure ogni ripetizione diventerà piu' difficile da eseguire" << endl;
            break;
        case 3:
            cout << "Ogni minuto passato sul tapis roulant aumenterà leggermente la tua resistenza\n";
            cout << "ma ricorda: un minuto di corsa corrisponde a tre secondi di tempo reale;\n";
            cout << "se pensi di correre a lungo ti conviene trovarti qualcosa da fare nel frattempo !" << endl;
            break;
        case 4:
            cout << "Usa le schede per creare un programma di allenamento personalizzato.\n";
            cout << "Quando crei una scheda con lo stesso nome di una già esistente la sovrascriverai.\n";
            cout << "Una volta creata e avviata una scheda eseguirai in ordine tutti gli esercizi\n";
            cout << "contenuti per il numero di volte specificato. Davvero comodo !" << endl;
            break;
        case 0:
            menu = false;
            break;
        default:
            cout << "Comando non riconosciuto" << endl;
        }
    }
}

void Palestra::usaTapis(StatoFisico& stato, int ripetizioni)
{
    int numeroPersone = rand()%10;
    for(int i = 0; i < numeroPersone; i++)
    {
        fila.incoda(i);
    }
    for(int i = numeroPersone; i>0; i-- )
    {
        cout << "Ci sono: " << i << "persone prima di te, attendi il tuo turno \n";
        fila.fuoricoda();
        Sleep(2000);
    }
    cout << "E' il tuo turno " << endl;
    if (stato.getResistenza() <= StatoFisico::MAX_RES)
    {
        cout << "E' ora di correre !\n";
        for (int i = 0; i < ripetizioni; i++)
        {
            cout << "Mancano " << ripetizioni - i << " minuti !\n";
            Sleep(3000);
        }
        float aumento_res =  (float)ripetizioni / 10;
        stato.setResistenza(stato.getResistenza() + aumento_res);
        cout << "La tua resistenza è aumentata di: " << aumento_res << "\n";
        cout << "Resistenza attuale: " << stato.getResistenza() << endl;
    }
    else
        cout << "La tua resistenza non puo aumentare ulteriormente !" << endl;
}

void Palestra::usaPanca(StatoFisico& stato, int ripetizioni)
{
    int numeroPersone = rand()%10;
    for(int i = 0; i < numeroPersone; i++)
    {
        fila.incoda(i);
    }
    for(int i = numeroPersone; i>0; i-- )
    {
        cout << "Ci sono: " << i << " persone prima di te, attendi il tuo turno \n";
        fila.fuoricoda();
        Sleep(2000);
    }
    if (stato.getCostituzione() <= StatoFisico::MAX_COS)
    {
        int millis = 1000;
        cout << "Faro' un po' di addominali !\n";
        for (int i = 1; i < ripetizioni; i++)
        {
            Sleep(millis); //Ogni ripetizione richiede un pò più di tempo
            cout << i << " ! Mancano " << ripetizioni - i << " ripetizioni !\n";
            millis *= 1.2;
        }
        float aumento_cos =  (float)ripetizioni / 10;
        stato.setCostituzione(stato.getCostituzione() + aumento_cos);
        cout << "La tua costituzione è aumentata di: " << aumento_cos << "\n";
        cout << "Costituzione attuale: " << stato.getCostituzione() << endl;
    }
    else
        cout << "La tua costituzione non puo aumentare ulteriormente !" << endl;
}

void Palestra::usaSchede(StatoFisico& stato)
{
    string menu = "\n1. Crea una scheda\n2. Cancella una scheda\n3. Allenati con una scheda\n";
    bool sceltaMenu = true;
    string scelta;
    int n;
    while (sceltaMenu)
    {
        if (Palestra::listaSchede.listavuota())
        {
            cout << "Non ci sono schede\n";
            cout << "Cosa vuoi fare ?\n";
            cout << "1. Crea una scheda\n0. Esci" << endl;

            getline(cin, scelta);
            stringstream(scelta) >> n;
            switch (n)
            {
            case 1:
                creaScheda();
                break;
            case 0:
                sceltaMenu = false;
                break;
            default:
                cout << "Comando non riconosciuto" << endl;
            }
        }
        else
        {
            cout << "Schede di allenamento: \n";
            stampaSchede();
            cout << "Cosa vuoi fare ? " << menu << endl;
            getline(cin, scelta);
            stringstream(scelta) >> n;
            switch (n)
            {
            case 1:
                creaScheda();
                break;
            case 2:
                cancellaSchede();
                break;
            case 3:
                eseguiScheda(stato);
                sceltaMenu = false;
                break;
            case 0:
                sceltaMenu = false;
                break;
            default:
                cout << "Comando non riconosciuto" << endl;
            }
        }
    }
}

void Palestra::stampaSchede()
{
    Lista<string>::posizione pos = listaSchede.primolista();
    while (!listaSchede.finelista(pos))
    {
        cout << "- " << listaSchede.leggilista(pos) << endl;
        pos = listaSchede.succlista(pos);
    }
}

void Palestra::creaScheda()
{
    cout << "Scrivi il nome della nuova scheda: ";
    bool inserimento = true;
    string input, name, esercizio;
    int ripetizioni;
    getline(cin, name);
    cout << "\n";
    Scheda scheda = Scheda(name);

    while (inserimento)
    {
        cout << "Che esercizio vuoi aggiungere ? (panca o tapis): ";
        getline(cin, esercizio);
        cout << "\n";
        if (esercizio != "panca" && esercizio != "tapis")
        {
            cout << "Scrivi 'panca' o 'tapis'" << endl;
        }
        else
        {
            do
            {
                if (esercizio == "panca")
                {
                    cout << "Quante ripetizioni vuoi fare ?: ";
                }
                else
                {
                    cout << "Quanti minuti vuoi correre ?: ";
                }
                getline(cin, input);
                cout << "\n";
                stringstream(input) >> ripetizioni;
                if (ripetizioni < 1)
                {
                    cout << "Inserisci un numero maggiore di 0 !\n";
                }
            }
            while (ripetizioni < 1);
            scheda.addEsercizio(esercizio, ripetizioni);
            bool ins_es = true;
            while (ins_es)
            {
                cout << "Inserire un altro esercizio s/n?: ";
                char risp;
                getline(cin, input);
                cout << endl;
                risp = input[0];
                tolower(risp);
                switch(risp)
                {
                case 's':
                    ins_es = false;
                    break;
                case 'n':
                    inserimento = false;
                    ins_es = false;
                    break;
                default:
                    cout << "Rispondi 's' o 'n'\n";
                }
            }
        }
    }
    Palestra::schede.inserisci(name, scheda);

    Lista<string>::posizione pos = listaSchede.primolista();
    while (!listaSchede.finelista(pos))
    {
        if(listaSchede.leggilista(pos) == name)
        {
            listaSchede.canclista(pos);
        }
        pos = listaSchede.succlista(pos);
    }
    listaSchede.inslista(name,pos);
}

void Palestra::cancellaSchede()
{
    cout << "Inserisci il nome della scheda che vuoi cancellare: ";
    string input;
    getline(cin, input);
    cout << endl;
    if (schede.appartiene(input))
    {
        schede.cancella(input);
        Lista<string>::posizione pos = listaSchede.primolista();
        while (!listaSchede.finelista(pos))
        {
            if(listaSchede.leggilista(pos) == input)
            {
                listaSchede.canclista(pos);
            }
            if(!listaSchede.finelista(pos))
            {
            pos = listaSchede.succlista(pos);
            }
        }
    }
    else
    {
        cout << "Scheda non trovata" << endl;
    }
}

void Palestra::eseguiScheda(StatoFisico& stato)
{
    cout << "Inserisci il nome della scheda che vuoi eseguire: ";
    string input;
    getline(cin, input);
    cout << endl;
    if (schede.appartiene(input))
    {
        Coda<Scheda::Esercizio> ese = schede.recupera(input).getEsercizi();
        while(!ese.codavuota())
        {
            if(ese.leggicoda().tipo == "panca")
            {
                usaPanca(stato, ese.leggicoda().ripetizioni);
                ese.fuoricoda();
            }
            else if(ese.leggicoda().tipo == "tapis")
            {
                usaTapis(stato, ese.leggicoda().ripetizioni);
                ese.fuoricoda();
            }
            else
            {
                cout << "Errore: tipo di esercizio non valido" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Scheda non trovata" << endl;
    }
}

