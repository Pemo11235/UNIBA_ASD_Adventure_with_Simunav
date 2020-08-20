#ifndef albero_H
#define albero_H

#include "Cellaalbero.h"
#include <ctype.h>

//realizzazione di un Albero ennario dinamico

template<class T> class Albero{
public:
    //dichiarazioni di tipo
    typedef T tipoelem;
    typedef cellaalbero<T>* nodo;

    //costruttore e distruttore di default
    Albero();
    ~Albero();

    void creaalbero(); //--------------------------+
    bool alberovuoto(); //                         |
    void inssottoalbero(nodo&,nodo&); //            |
    nodo radice(); //                               |
    void cancnodo(nodo&); //                        |
    nodo padre(nodo); //                            |
    nodo succnodo(nodo); //                         |
    nodo precnodo(nodo); //                         |
    nodo primofiglio(nodo); //                      |-> operatori di specifica
    nodo primofratello(nodo); //                    |
    bool finefratelli(nodo); //                     |
    bool foglia(nodo); //                           |
    tipoelem legginodo(nodo); //                    |
    void scrivinodo(tipoelem,nodo); //              |
    void contanodi(nodo); //                        |
    void azzeranum(); //                            |
    void annullavisita(nodo); //--------------------+
    void settavisita(nodo,bool); //
    void settafiglio(nodo); //
    bool leggivisita(nodo); //
    nodo nuovonodo(); //
    void inccont(); //



    void insarcofratellosucc(nodo); //
    void insarcofratelloprec(nodo); //
    void insarcopadre(nodo&,nodo&); //operatore ausiliario: setta gli archi tra nodo padre e nodo figlio
    void insarcofratello(nodo&,nodo&); //operatore ausiliario: setta gli archi tra nodi fratelli




private:
    nodo n; //puntatore alla radie dell'Albero
    int cont,num; //cont: numero di nodi dell'Albero; num: numero di nodi da un nodo qualunque dell'Albero fino alle foglie

    //friend bool controllo(char,cellaalbero<char>*&,Albero<char>); //funzione specifica per il navigatore
};

template<class T> Albero<T>::Albero() //costruttore generico
{
    creaalbero();
    cont = 0;
    azzeranum();
}

template<class T> Albero<T>::~Albero() //distruttore generico
{

}

template<class T> void Albero<T>::creaalbero() //crea l'Albero ennario
{
    n = new cellaalbero<T>; //mi creo una nuova cella
    n->setpadre(n); //------+
    n->setsucc(n); //       +-\ setto tutti i puntatori
    n->setprec(n); //       +-/ a se stesso (Albero vuoto)
    n->setfiglio(n); //-----+
    scrivinodo(' ',n); //inserisco uno spazio perch� mi servir� per la ricerca dei suggerimenti
    n->setvisita(false); //setto la visita a false
}

template<class T> bool Albero<T>::alberovuoto() //restituisce true se l'Albero � vuoto, false altrimenti
{
    return cont == 0;
}

template<class T> void Albero<T>::inssottoalbero(nodo& nodp, nodo& nodf) //inserisce il nodo la cui posizione sar� identificata da due nodi
{
    if(nodp == nodf) //se i due puntatori puntano alla stessa cella allora...
    {
        cellaalbero<T>* fig = new cellaalbero<T>; //creo una nuova cella
        fig->setsucc(fig); //... setto temporaneamente come fratello precedente se stesso...
        fig->setprec(fig); //... setto temporaneamente come fratello successivo se stesso...
        insarcopadre(nodp,fig); //... inserisco l'arco al padre...
        fig->setvisita(false); //... setto la visita a false...
        insarcofratello(fig,fig); //... setto definitivamente i fratelli (che in questo caso corrispondono a se stesso perch� � figlio unico)...
        fig->setfiglio(fig); //... setto come figlio la cella stessa...
        nodf = fig; //... nodf che passo da input lo faccio puntare alla nuova cella creata...
        cont++; //... incremento il contatore dei nodi dell'Albero...
    }
    else if(nodp != nodf) //... altrimenti se nodp punta al padre e nodf punta al figlio e se l'elemento da inserire non � gi� presente tra i figli di nodp...
    {
        cellaalbero<T>* fig = new cellaalbero<T>; //creo una nuova cella
        fig->setsucc(fig); //---------------------------+
        fig->setprec(fig); //                           +-\ si procede come sopra
        insarcopadre(nodp,fig); //                      +-/ (righi 81 - 86)
        fig->setvisita(false); //-----------------------+
        insarcofratello(nodf,fig); //... setto definitivamente i fratelli (che in questo caso avverr� in ordine alfabetico)...
        fig->setfiglio(fig); //-----+
        nodf = fig; //              +-> si procede come sopra (righi 88 - 90)
        cont++; //------------------+
    }
}

template<class T> cellaalbero<T>* Albero<T>::radice() //ritorna la radice dell'Albero
{
    return n;
}

template<class T> void Albero<T>::insarcopadre(nodo& p,nodo& f) //setta il padre
{
    if(foglia(p)) //se p � foglia allora...
    {
        p->setfiglio(f); //... allora setto f come figlio di p
    }
    f->setpadre(p); //comunque poi setto p come padre si f
}

template<class T> void Albero<T>::insarcofratello(nodo& f1,nodo& f2) //setta i fratelli di f2
{
    if(f1 != f2) //se f1 ed f2 puntano a celle diverse
    {
        int con = 0;
        f1 = precnodo(primofratello(f1)); //mi posiziono all'ultimo fratello di f1
        do //dopodiche entro nel ciclo
        {
            if(con > 0) //il settaggio delle visite deve iniziare dal primo fratello in poi
            {
                f1->setvisita(true);
            }
            f1 = succnodo(f1); //faccio puntare f1 al fratello successivo
            con++; //incremento il contatore
        }
        while(f1 < f2 && !f1->getvisita()); //finch� il nodo di f1 � minore di f2 e il nodo non risulta visitato
        if(f1->getvisita() || f1 > f2) //se f1 � stato visitato o se il contenuto di f1 � maggiore del contenuto di f2 allora...
        {
            precnodo(f1)->setsucc(f2); //-------+
            f2->setprec(precnodo(f1)); //       +-\ ... inserisco f2 tra f1
            f1->setprec(f2); //                 +-/ e il suo precedente...
            f2->setsucc(f1); //-----------------+
            if(f1 > f2 && con == 1) //... inoltre se f2 � il primo fratello allora...
            {
                padre(f2)->setfiglio(f2); //setto f2 come primo figlio del padre
            }
        }
        cellaalbero<T>* temp = f2; //a questo punto creo un nuovo puntatore e lo faccio puntare alla cella puntata da f2...
        do //-------------------------------+
        { //                                |
            temp->setvisita(false); //      +-\ ... e annullo tutte
            temp = succnodo(temp); //       +-/ le eventuali visite
        } //                                |
        while(temp != f2); //---------------+
    }
}

template<class T> void Albero<T>::cancnodo(nodo& nod) //cancella il nodo dato in input
{
    cellaalbero<T>* temp1 = nod; //mi creo un nuovo puntatore e lo faccio puntare al nodo dato in input
    cellaalbero<T>* temp2; //mi creo un secondo puntatore
    nod = succnodo(nod); //nod lo faccio puntare al fratello successivo
    if(!alberovuoto()) //se l'Albero non � vuoto allora...
    {
        temp2 = temp1; //... faccio puntare temp2 alla cella puntata da temp1...
        temp1 = precnodo(temp1); //... temp1 lo facco puntare alla cella precedente...
        if(succnodo(temp1) != temp1 && precnodo(temp1) != temp1) //... se la cella ha fratelli allora...
        {
            if(temp2 == primofratello(temp2)) //--------+
            { //                                        +-\ ... se temp2 � anche il primo fratello allora
                padre(temp2)->setfiglio(nod); //        +-/ setto nod come primo figlio del padre...
            } //----------------------------------------+
            temp2->setsucc(temp2); //-------+
            temp2->setprec(temp2); //       +-\ ... setto i collegamenti tra
            temp1->setsucc(nod); //         +-/ temp1 e nod e isolo temp2...
            nod->setprec(temp1); //---------+
        }
        else //... altrimenti...
        {
            if(temp2 == primofratello(temp2)) //------------+
            { //                                            +-\ ... temp2 � anche il primo fratello e quindi
                padre(temp2)->setfiglio(padre(temp2)); //   +-/ cancello temp2 come primo figlio del padre...
            } //--------------------------------------------+
        }
        temp2->setpadre(temp2); //... isolo completamente la cella...
        azzeranum(); //... azzero il contatore...
        contanodi(temp2); //... conto il numero di celle del sottoalbero di temp2...
        cont -= num; //... e sottraggo il valore appena calcolato dal numero totale dei nodi
    }
}

template<class T> cellaalbero<T>* Albero<T>::padre(nodo nod) //restituisce il padre del nodo dato in input
{
    return nod->getpadre();
}

template<class T> cellaalbero<T>* Albero<T>::succnodo(nodo nod) //restituisce il fratello successivo del nodo dato in input
{
    return nod->getsucc();
}

template<class T> cellaalbero<T>* Albero<T>::precnodo(nodo nod) //restituisce il fratello precedente del nodo dato in input
{
    return nod->getprec();
}

template<class T> cellaalbero<T>* Albero<T>::primofiglio(nodo nod) //restituisce il primo figlio del nodo dato in input
{
    return nod->getfiglio();
}

template<class T> cellaalbero<T>* Albero<T>::primofratello(nodo nod) //restituisce il primo fratello del nodo dato in input
{
    return primofiglio(padre(nod));
}

template<class T> bool Albero<T>::finefratelli(nodo nod) //ritorna true se il nodo � l'ultimo dei fratelli, false altrimenti
{
    return nod == precnodo(primofratello(nod));
}

template<class T> bool Albero<T>::foglia(nodo nod) //ritorna true se il nodo � una foglia dell'Albero, false altrimenti
{
    return nod == primofiglio(nod);
}

template<class T> T Albero<T>::legginodo(nodo nod) //ritorna l'elemento contenuto nel nodo dato in input
{
    return nod->getelem();
}

template<class T> void Albero<T>::scrivinodo(tipoelem e,nodo nod) //setta l'elemento all'interno del nodo dato in input
{
    nod->setelem(e);
}

template<class T> void Albero<T>::contanodi(nodo nod) //conteggio dei nodi del sottoalbero a partire dal nodo dato in input
{
    if(!alberovuoto()) //se l'Albero non � vuoto...
    { //... procedo con la invisita:
        if(!foglia(nod)) //---------------------------------+
        { //                                                |
            cellaalbero<T>* temp = primofiglio(nod); //    +-> 1) se il nodo non � una foglia allora vado al primo figlio
            contanodi(temp); //                             |
        } //------------------------------------------------+
        num++; //2) se sono arrivato ad una foglia incremento il contatore
        if(succnodo(nod) != nod && succnodo(nod) != primofratello(nod)) //------+
        { //                                                                    |
            cellaalbero<T>* temp = succnodo(nod); //                           +-> 3) se possiede dei fratelli allora vado a al fratello successivo
            contanodi(temp); //                                                 |
        } //--------------------------------------------------------------------+
    }
}

template<class T> void Albero<T>::azzeranum() //azzera in numero dei nodi di un sottoalbero
{
    num = 0;
}

template<class T> void Albero<T>::annullavisita(nodo nod) //annulla le eventuali visite effettuate ai nodi settandole a false
{
    if(!alberovuoto()) //se l'Albero non � vuoto...
    { //... procedo con la invisita:
        if(!foglia(nod)) //---------------------------------+
        { //                                                |
            cellaalbero<T>* temp = primofiglio(nod); //    +-> 1) se il nodo non � una foglia allora vado al primo figlio
            annullavisita(temp); //                         |
        } //------------------------------------------------+
        nod->setvisita(false); //2) se sono arrivato ad una foglia setto la visita del nodo a false
        if(succnodo(nod) != nod && succnodo(nod) != primofratello(nod)) //------+
        { //                                                                    |
            cellaalbero<T>* temp = succnodo(nod); //                           +-> 3) se possiede dei fratelli allora vado a al fratello successivo
            annullavisita(temp); //                                             |
        } //--------------------------------------------------------------------+
    }
}

template<class T> void Albero<T>::settavisita(nodo nod,bool b) //
{
    nod->setvisita(b);
}

template<class T> void Albero<T>::insarcofratellosucc(nodo nod) //
{
    nod->setsucc(nod);
}

template<class T> void Albero<T>::insarcofratelloprec(nodo nod) //
{
    nod->setprec(nod);
}

template<class T> void Albero<T>::settafiglio(nodo nod) //
{
    nod->setfiglio(nod);
}

template<class T> void Albero<T>::inccont() //
{
    cont++;
}

#endif // albero_H
