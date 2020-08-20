#ifndef BINALBERI_H_INCLUDED
#define BINALBERI_H_INCLUDED
#include "Nodo_Albero_Binario.h"

/**
*   Realizzazione dell'ALBERO BINARIO totalmente dinamica.
*   Riferimento al padre, al figlio sinistro e al figlio destro di un nodo.
*  author: Regina Zaccaria.
*/
template <class TIPOETICHETTA>
class BinAlbero{

    public:
       //DEFINIZIONE DEL NODO
       typedef Cella_Binalbero<TIPOETICHETTA>* Nodo;
       //DICHIARAZIONE NODO NULLO
       static constexpr Nodo nil=nullptr;
       //COSTRUTTORE
       BinAlbero();
       //DISTRUTTORE
       ~BinAlbero();
       //METODO CHE CREA UN ALBERO BINARIO
       void creabinalbero();
       //METODO CHE RESTITUISCE VERO SE L'ABERO BINARIO È VUOTO, FALSO ALTRIMENTI
       bool binalberovuoto()const;
       //METODO CHE RESTITUISCE LA RADICE DELL'ALBERO BINARIO
       Nodo binradice()const;
       //METODO CHE PASSATO UN NODO RESTITUISCE IL SUO PADRE
       Nodo binpadre(Nodo)const;
       //METODO CHE RESTITUISCE VERO SE IL FIGLIO SINISTRO DEL NODO PASSATO NON ESISTE, FALSO ALTRIMENTI
       bool sinistrovuoto(Nodo)const;
       //METODO CHE RESTITUISCE VERO SE IL FIGLIO DESTRO DEL NODO PASSATO NON ESISTE, FALSO ALTRIMENTI
       bool destrovuoto(Nodo)const;
       //METODO CHE RESTITUISCE IL FIGLIO SINISTRO DEL NODO PASSATO
       Nodo figliosinistro(Nodo)const;
       //METODO CHE RESTITUISCE IL FIGLIO DESTRO DEL NODO PASSATO
       Nodo figliodestro(Nodo)const;
       //METODO CHE DATI DUE ALBERI, CREA UNA RADICE NULLA ALL'ALBERO BINARIO IMPLICITO,
       //INSERISCE COME FIGLIO SINISTRO LA RADICE DEL PRIMO ALBERO PASSATO E COPIATI I SUOI DISCENDENTI,
       //E INSERISCE COME FIGLIO DESTRO IL SECONDO ALBERO PASSATO E COPIATI I SUOI DISCENDENTI.
       void costrbinalbero(BinAlbero<TIPOETICHETTA>&,BinAlbero<TIPOETICHETTA>&);
       //METODO CHE PASSATO UN NODO LO CANCELLA E CANCELLA TUTTI I SUOI DISCENDENTI
       void cancsottobinalbero(Nodo);
       //METODO CHE PASSATO UN NODO RESTITUISCE LA SUA ETICHETTA
       TIPOETICHETTA legginodo(Nodo)const;
       //METODO CHE PASSATO UN NODO SCRIVE AL SUO INTERNO L'ETICHETTA DI TIPO TIPOELEM
       void scrivinodo(Nodo, TIPOETICHETTA);
       //METODO CHE INSERISCE LA RADICE NULLA
       void insbinradice();
       //METODO CHE INSERISCE COME FIGLIO SINISTRO IL NODO PASSATO
       void insfigliosinistro(Nodo);
       //METODO CHE INSERISCE COME FIGLIO DESTRO IL NODO PASSATO
       void insfigliodestro(Nodo);

    private:
        Nodo radice;
};


template <class TIPOETICHETTA>
BinAlbero<TIPOETICHETTA>::BinAlbero(){
    creabinalbero();
}

template <class TIPOETICHETTA>
BinAlbero<TIPOETICHETTA>::~BinAlbero(){
   /* if(radice!=nil)
        cancsottobinalbero(binradice());
    */

}

template <class TIPOETICHETTA>
 void BinAlbero<TIPOETICHETTA>::creabinalbero(){
    radice=nil;
    }

template <class TIPOETICHETTA>
    bool BinAlbero<TIPOETICHETTA>::binalberovuoto()const{
        if(radice==nil)
            return true;
        else
            return false;
    }

template <class TIPOETICHETTA>
    typename BinAlbero<TIPOETICHETTA>::Nodo BinAlbero<TIPOETICHETTA>::binradice()const{
        return radice;
    }

template <class TIPOETICHETTA>
    typename BinAlbero<TIPOETICHETTA>::Nodo BinAlbero<TIPOETICHETTA>::binpadre(Nodo padre)const{
        return padre->getPadre();
    }

template <class TIPOETICHETTA>
    bool BinAlbero<TIPOETICHETTA>::sinistrovuoto(Nodo sx)const{
        if(sx->getFiglioSx()==nil)
            return true;
        else
            return false;
    }

template <class TIPOETICHETTA>
    bool BinAlbero<TIPOETICHETTA>::destrovuoto(Nodo dx)const{
        if(dx->getFiglioDx()==nil)
            return true;
        else
            return false;
    }

template <class TIPOETICHETTA>
    typename BinAlbero<TIPOETICHETTA>::Nodo BinAlbero<TIPOETICHETTA>::figliosinistro(Nodo sx)const{
            return sx->getFiglioSx();
    }

template <class TIPOETICHETTA>
    typename BinAlbero<TIPOETICHETTA>::Nodo BinAlbero<TIPOETICHETTA>::figliodestro(Nodo dx)const{
        return dx->getFiglioDx();
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::costrbinalbero(BinAlbero<TIPOETICHETTA> &A,BinAlbero<TIPOETICHETTA> &B){
        radice=new Nodo;
        radice->setPadre(nil);

        if(!A.binalberovuoto()){
            radice->setFiglioSx(A.binradice());
            radice->getFiglioSx()->setPadre(radice);
        }
        else
            radice->setFiglioSx(nil);


        if(!B.binalberovuoto()){
            radice->setFiglioDx(B.binradice());
            radice->getFiglioDx()->setPadre(radice);
        }
        else
            radice->setFiglioDx(nil);
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::cancsottobinalbero(Nodo r){

        if(!sinistrovuoto(r))
            cancsottobinalbero(r->getFiglioSx());

        if(!destrovuoto(r))
            cancsottobinalbero(r->getFiglioDx());

        if(radice!=r)
        {
            Nodo temp;
            temp=binpadre(r);

            if(temp->getFiglioSx()==r)
                temp->setFiglioSx(nil);
            else
                temp->setFiglioDx(nil);
        }
        else
            radice=nil;

       delete r;

    }

template <class TIPOETICHETTA>
    TIPOETICHETTA BinAlbero<TIPOETICHETTA>::legginodo(Nodo n)const{
        return n->getEtichetta();
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::scrivinodo(Nodo n, TIPOETICHETTA e){
        n->setEtichetta(e);
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::insbinradice(){
        radice= new Cella_Binalbero<TIPOETICHETTA>;
        radice->setFiglioDx(nil);
        radice->setFiglioSx(nil);
        radice->setPadre(nil);
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::insfigliosinistro(Nodo n){
        Nodo temp = new Cella_Binalbero<TIPOETICHETTA>;
        n->setFiglioSx(temp);
        temp->setPadre(n);
        temp->setFiglioDx(nil);
        temp->setFiglioSx(nil);
    }

template <class TIPOETICHETTA>
    void BinAlbero<TIPOETICHETTA>::insfigliodestro(Nodo n){
        Nodo temp = new Cella_Binalbero<TIPOETICHETTA>;
        n->setFiglioDx(temp);
        temp->setPadre(n);
        temp->setFiglioDx(nil);
        temp->setFiglioSx(nil);
    }

#endif // BINALBERI_H_INCLUDED
