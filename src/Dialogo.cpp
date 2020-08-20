#include "Dialogo.h"

Dialogo::Dialogo() {}
Dialogo::~Dialogo() {
}

Dialogo::Dialogo(const Dialogo& d){
        personaggio = d.personaggio;
        stato = d.stato;
        dialogo = Albero<Domanda>(d.dialogo);
    }

Dialogo::Dialogo(string nomepersonaggio){
    this->personaggio=nomepersonaggio;
    this->stato=1;
}

void Dialogo::setstato(int numero){
    this->stato=numero;
}

int Dialogo::getstato(){
    return (this->stato);
}
string Dialogo::leggiPersonaggio(){
    return (this->personaggio);
}

void Dialogo::inseriscidomanda(int codice, string frase){
    if (codice==1)
        inseriscipresentazione(frase);
    else
    {
        Albero<Domanda>::nodo indicenodo=Albero<Domanda>::nil;
        int codicedacercare=0;
        int modulocodice=codice%10;
        if(modulocodice==1){
            codicedacercare=(codice-1)/10;
            indicenodo = trovanodo(dialogo.radice(),codicedacercare);
            inserisciprimaopzione(indicenodo,codice,frase);
        }
        else{
            codicedacercare=codice-1;
            indicenodo = trovanodo(dialogo.radice(),codicedacercare);
            inserisciopzionesuccessiva(indicenodo,codice,frase);
        }
    }
}

Albero<Domanda>::nodo Dialogo::trovanodo(Albero<Domanda>::nodo indice, int codice){
    Albero<Domanda>::nodo nodo;
    Albero<Domanda>::nodo nododaritornare=Albero<Domanda>::nil;

    if(codice==dialogo.legginodo(indice).leggicodice())
        nododaritornare=indice;

    else{
        if(!dialogo.foglia(indice)){
            nodo=dialogo.primofiglio(indice);
            while(!dialogo.ultimofratello(nodo) && nododaritornare==Albero<Domanda>::nil){
                nododaritornare=trovanodo(nodo,codice);
                nodo=dialogo.succfratello(nodo);
            }
            if (nododaritornare==Albero<Domanda>::nil)
                nododaritornare=trovanodo(nodo,codice);
        }
    }
   return nododaritornare;
}


void Dialogo::inseriscipresentazione(string presentazione){
    Domanda saluto = Domanda(1,presentazione);
    Albero<Domanda>::nodo nodosaluto;
    dialogo.insradice();
    nodosaluto=dialogo.radice();
    dialogo.scrivinodo(nodosaluto,saluto);
}

void Dialogo::inserisciprimaopzione(Albero<Domanda>::nodo domandacorrente,int codice, string frase){
    Albero<Domanda> alberoopzione;
    Albero<Domanda>::nodo nodoopzione;
    Domanda nuovadomanda= Domanda(codice,frase);
    alberoopzione.insradice();
    nodoopzione=alberoopzione.radice();
    alberoopzione.scrivinodo(nodoopzione, nuovadomanda);
    dialogo.insprimosottoalbero(domandacorrente,alberoopzione);
}

void Dialogo::inserisciopzionesuccessiva(Albero<Domanda>::nodo nodoprecedente,int codice, string frase){
    Albero<Domanda> alberoopzione;
    Albero<Domanda>::nodo nodoopzione;
    Domanda nuovadomanda= Domanda(codice,frase);
    alberoopzione.insradice();
    nodoopzione=alberoopzione.radice();
    alberoopzione.scrivinodo(nodoopzione, nuovadomanda);
    dialogo.inssottoalbero(nodoprecedente,alberoopzione);
}

void Dialogo::visualizzadomande(){
    int domandadavisualizzare=this->stato;

    Albero<Domanda>::nodo indicenodo=Albero<Domanda>::nil;
    indicenodo = trovanodo(dialogo.radice(),domandadavisualizzare);
    cout<<dialogo.legginodo(indicenodo).leggidomanda();
}

void Dialogo::cambiastato(int risposta){
    int statosuccessivo=(this->stato)*10+risposta;
    Albero<Domanda>::nodo nodosuccessivo=Albero<Domanda>::nil;
    nodosuccessivo = trovanodo(dialogo.radice(),statosuccessivo);
    if(nodosuccessivo!=Albero<Domanda>::nil)
        this->stato=statosuccessivo;
    else
        cout<< "Risposta non valida\n";
    visualizzadomande();
}

bool Dialogo::rispondi(int risposta){
    if (risposta==0)
        return true;
    else{
        cambiastato(risposta);
        return false;
    }
}

bool Dialogo::dialogoVuoto(){
    return(dialogo.alberovuoto());
}

bool Dialogo::isFoglia(){
    int domandadavisualizzare=this->stato;
    Albero<Domanda>::nodo indicenodo=Albero<Domanda>::nil;
    indicenodo = trovanodo(dialogo.radice(),domandadavisualizzare);
    return(dialogo.foglia(indicenodo));
}

