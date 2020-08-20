/**  
 * @file Grafo.h  
 * Definizione struttura dati Grafo realizzata mediante Vettore di Liste di Adiacenza
 * @author sconosciuto, modificato da Graziano Montanaro. 
 * @date Anno Accademico 2018/19.  
 */  

#ifndef _GRAFO_H
#define _GRAFO_H

#include <iostream>
#include <cstdlib>
#include "Lista.h"
#include "Adiacenza.h"

//definizione della classe grafo (orientato, etichettato e pesato)
//realizzazione tramite vettore (di lunghezza maxnodi) con liste (monodirezionali dinamiche) di adiacenza

template<class tipoElem,class tipoPeso> class Grafo
{
public:

    //dichiarazioni di tipo
    typedef unsigned int nodo; //identificatore del nodo : il nodo è identificato da un intero (indice del vettore)
    typedef Adiacenza<nodo,tipoPeso> adiacente; //tipo dell'elemento che farà parte della lista di adiacenza
    //     adiacente = (rif.nodo adiac | peso arco)

    typedef struct //definizione dell'elemento del vettore
    {
        tipoElem etichetta; //etichetta del nodo di tipo tipoElem
        bool esiste; //campo booleano che indica se il nodo fa parte del grafo
        Lista<adiacente> adiac; //lista di adiacenza
    } cellaGrafo;


    Grafo(); // costruttore
    ~Grafo(); // distruttore


    unsigned int n_nodi();

    //operatori di specifica
    void creagrafo();
    bool grafovuoto() const;
    void insnodo(nodo&);
    void insarco(nodo,nodo);
    void cancnodo(nodo);
    void cancarco(nodo,nodo);
    Lista<nodo> adiacenti(nodo) const;
    bool esistenodo(nodo) const;
    bool esistearco(nodo,nodo) const;
    void scrivinodo(tipoElem,nodo);
    tipoElem legginodo(nodo) const;
    void scriviarco(tipoPeso,nodo,nodo);
    tipoPeso leggiarco(nodo,nodo);

private:
    cellaGrafo table[1000]; //Dimensiono il vettore
    unsigned int maxnodi; //dimensione del vettore
    unsigned int nelementi; //indica quanti nodi effettivamente ci sono nel grafo
    nodo primolibero() const; //operatore ausiliare : restituisce la prima posizione libera del vettore (in modo da non avere un vettore "sparso")



};

//n viene passato nel crea grafo
template<class tipoElem,class tipoPeso> Grafo<tipoElem,tipoPeso>::Grafo() //costruttore specifico
{
    creagrafo();
}

template<class tipoElem,class tipoPeso> Grafo<tipoElem,tipoPeso>::~Grafo() //distruttore
{

}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::creagrafo() //crea il grafo
{
    maxnodi = 1000;
    nelementi=0; //dico che ci sono 0 nodi
    for (int i=0; i<1000; i++) //inizializzo il vettore mettendo a false l'appartenenza di tutti nodi
    {
        table[i].esiste=false;
    }
}

template<class tipoElem,class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::grafovuoto() const //restituisce true se il grafo è vuoto, false altrimenti
{
    return (nelementi==0);
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::insnodo(nodo &n) //inserisce il nodo che sarà identificato dall'indice n
{
    //passaggio del parametro per indirizzo perchè la variabile sarà modificata
    if (!esistenodo(n) && nelementi<1000) // precondizione nodo non appartenente
    {
        n=primolibero(); //la posizione in cui metterò il nodo del vettore sarà la prima libera
        table[n].esiste=true; //setto a true il suo campo esiste
        nelementi++; //aumento il contatore di nodi del grafo
    }
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::insarco(nodo n,nodo m) //inserisce l'arco che esce dal nodo n ed entra in m
{
    if (esistenodo(n) && esistenodo(m) && !esistearco(n,m))//precondizione nodi appartenenti e arco non esistente
    {
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista();
        adiacente temp; //creo l'elemento da inserire
        temp.scrivinodo(m); //setto l'adiacente
        table[n].adiac.inslista(temp,indice); //inserisco il nodo m negli adiacenti di n (in prima posizione)
    }
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::cancnodo(nodo n) //elimina il nodo n
{
    if (esistenodo(n))// 1)---------------------------+
    {
        //|
        if (table[n].adiac.listavuota())// 2)         //|
        {
            //|
            bool libero=true;                           //|
            int i=0;                                    //|
            while (i<maxnodi && libero)                 //|
            {
                //|--- precondizione : nodo esistente 1),che non ha archi uscenti 2) nè entranti 3)
                if (esistenodo(i))                        //|
                {
                    //|
                    libero=!esistearco(i,n);                //|
                }                                         //|
                i++;                                      //|
            }                                           //|
            if (libero)// 3)------------------------------+
            {
                table[n].esiste=false; //adesso quel nodo non esiste più
                table[n].etichetta=NULL; //svuoto l'etichetta
                nelementi--; //e ho un nodo in meno nel grafo
            }
        }
    }
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::cancarco(nodo n,nodo m)  //elimina l'arco che esce da n ed entra in m
{
    if (esistenodo(n) && esistenodo(m) && esistearco(n,m))//precondizione nodi appartenenti e arco esistente
    {
        bool cancellato=false;
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista();
        while (!table[n].adiac.finelista(indice) && !cancellato) //scandisco la lista finchè non cancello l'elemento
        {
            if (table[n].adiac.leggilista(indice).legginodo()==m) //se trovo l'elemento lo cancello
            {
                table[n].adiac.canclista(indice); //elimino l'elemento
                cancellato=true;
            }
            else indice=table[n].adiac.succlista(indice);
        }
    }
}

template<class tipoElem,class tipoPeso>
Lista<typename Grafo<tipoElem,tipoPeso>::nodo> Grafo<tipoElem,tipoPeso>::adiacenti(nodo n) const //restituisce la lista di adiacenti di n
{
    Lista<nodo> lista; //lista da restituire
    adiacente temp; //comodo
    if (esistenodo(n)) // precondizione nodo appartenente al grafo
    {
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista(); //indice di scansione della lista di adiacenti (lista di adiacente)
        typename Lista<nodo>::posizione indice2=lista.primolista(); //indice di scansione della lista di adiacendi da restituitre (lista di nodo)
        while (!table[n].adiac.finelista(indice)) //scansione della prima lista
        {
            temp=table[n].adiac.leggilista(indice); //lettura di adiacente
            lista.inslista(temp.legginodo(),indice2); //inserisco (in coda) nella lista da restituire solo il riferimento al nodo adiacente (senza il peso dell'arco)
            indice=table[n].adiac.succlista(indice);
            indice2=lista.succlista(indice2);
        }
    }
    return(lista);
}

template<class tipoElem,class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::esistenodo(nodo n) const //restituisce true se il nodo appartiene al grafo, false altrimenti
{
    if (n<=maxnodi) return (table[n].esiste);
    else return false;
}

template<class tipoElem,class tipoPeso>
bool Grafo<tipoElem,tipoPeso>::esistearco(nodo n,nodo m) const //restituisce true se il nodo n ha un arco uscente verso m, false altrimenti
{
    bool esiste=false;
    if (esistenodo(n) && esistenodo(m)) //precondizione nodi appartenenti al grafo
    {
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista();
        while (!table[n].adiac.finelista(indice) && !esiste) //scandisco la lista finchè non trovo l'elemento o è finita
        {
            if (table[n].adiac.leggilista(indice).legginodo()==m) esiste=true;
            indice=table[n].adiac.succlista(indice);
        }
    }
    return (esiste);
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::scrivinodo(tipoElem val,nodo n) //scrive l'etichetta del nodo n
{
    if (esistenodo(n)) //precondizione nodo appartenente al grafo
        table[n].etichetta=val;
}

template<class tipoElem,class tipoPeso>
 tipoElem Grafo<tipoElem,tipoPeso>::legginodo(nodo n) const //restituisce l'etichetta del nodo n
{
    tipoElem e;
    if (esistenodo(n)) //precondizione nodo appartenente al grafo
        e=table[n].etichetta;
    return (e);
}

template<class tipoElem,class tipoPeso>
void Grafo<tipoElem,tipoPeso>::scriviarco(tipoPeso val,nodo n,nodo m) //scrive il peso dell'arco che va dal nodo n al nodo m
{
    if (esistenodo(n) && esistenodo(m)) //precondizione nodi appartenenti al grafo (c'è anche arco appartenenente ma non conviene altrimenti c'è una scansione solo per vedere
    {
        //se esiste e poi si farebbe la seconda scansione per aggiornare
        bool aggiornato=false;                                                      //quindi si fa un'unica scansione in cui si ricerca e si aggiorna)
        adiacente temp(m,val);
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista();
        while (!table[n].adiac.finelista(indice) && !aggiornato) //scandisco la lista finchè non trovo l'elemento o è finita
        {
            if (table[n].adiac.leggilista(indice).legginodo()==m)
            {
                table[n].adiac.scrivilista(temp,indice);
                aggiornato=true;
            }
            indice=table[n].adiac.succlista(indice);
        }
    }
}

template<class tipoElem,class tipoPeso>
tipoPeso Grafo<tipoElem,tipoPeso>::leggiarco(nodo n,nodo m) //restituisce il peso dell'arco che va da n a m
{
    tipoPeso a;
    if (esistenodo(n) && esistenodo(m)) //precondizione nodi appartenenti al grafo (c'è anche arco appartenenente ma non conviene altrimenti c'è una scansione solo per vedere
    {
        //se esiste e poi si farebbe la seconda scansione per la lettura                                                                 //quindi si fa un'unica scansione in cui si ricerca e si legge)
        bool letto=false;
        typename Lista<adiacente>::posizione indice=table[n].adiac.primolista();
        while (!table[n].adiac.finelista(indice) && !letto) //scandisco la lista finchè non trovo l'elemento o è finita
        {
            if (table[n].adiac.leggilista(indice).legginodo()==m)
            {
                a=table[n].adiac.leggilista(indice).leggipeso();
                letto=true;
            }
            indice=table[n].adiac.succlista(indice);
        }
    }
    return(a);
}


//operatori ausiliare

template<class tipoElem,class tipoPeso>
unsigned int Grafo<tipoElem,tipoPeso>::primolibero() const //restituisce la prima posizione del vettore libera
{
    nodo i=-1;
    bool libero=false;
    while (!libero) //scorre il vettore finchè non trova una posizione libera
    {
        //il controllo è solo su libero perchè so che mi fermerò per forza poichè questo metodo viene chiamato solo se il vettore non è pieno
        i++;
        libero=!table[i].esiste;
    }
    return (i);
}


template<class tipoElem,class tipoPeso> unsigned int Grafo<tipoElem,tipoPeso>::n_nodi()
{
    return nelementi;
}


#endif
