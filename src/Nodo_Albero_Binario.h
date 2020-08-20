#ifndef NODO_ALBERO_BINARIO_H_INCLUDED
#define NODO_ALBERO_BINARIO_H_INCLUDED

/**
*   Realizzazione del Nodo dell'albero binario.
*   Il nodo conterrà riferimento al FIGLIO SINISTRO,
*   riferimento al FIGLIO DESTRO e riferimento al PADRE.
*   Inoltre avrà un campo ETICHETTA di tipo TIPOETICHETTA.
*/
template <class TIPOETICHETTA>
    class Cella_Binalbero{
        public:
            //COSTRUTTORE
            Cella_Binalbero();
            //DISTRUTTORE
            ~Cella_Binalbero();
            //METODO CHE SETTA IL FIGLIO SINISTRO
            void setFiglioSx(Cella_Binalbero<TIPOETICHETTA>*);
            //METODO CHE SETTA IL FIGLIO DESTRO
            void setFiglioDx(Cella_Binalbero<TIPOETICHETTA>*);
            //METODO CHE SETTA IL PADRE
            void setPadre(Cella_Binalbero<TIPOETICHETTA>*);
            //METODO CHE SETTA L'ETICHETTA
            void setEtichetta(TIPOETICHETTA&);
            //METODO CHE RESTITUISCE IL RIFERIMENTO AL FIGLIO SINISTRO
            Cella_Binalbero<TIPOETICHETTA>* getFiglioSx();
            //METODO CHE RESTITUISCE IL RIFERIMENTO AL FIGLIO DESTRO
            Cella_Binalbero<TIPOETICHETTA>* getFiglioDx();
            //METODO CHE RESTITUISCE IL RIFERIMENTO AL PADRE
            Cella_Binalbero<TIPOETICHETTA>* getPadre();
            //METODO CHE RESTITUISCE L'ETICHETTA
            TIPOETICHETTA getEtichetta();
            //OVERLOAD DELL'OPERATORE ==
            bool operator == (Cella_Binalbero<TIPOETICHETTA>);
            //COSTRUTTORE DI COPIA
            Cella_Binalbero(const Cella_Binalbero& );
            //OVERLOAD DELL'OPERATORE =
            void operator=(const Cella_Binalbero& );
        private:
            Cella_Binalbero<TIPOETICHETTA>* FiglioDx;
            Cella_Binalbero<TIPOETICHETTA>* FiglioSx;
            Cella_Binalbero<TIPOETICHETTA>* Padre;
            TIPOETICHETTA etichetta;
    };


template <class TIPOETICHETTA>
    Cella_Binalbero<TIPOETICHETTA>::Cella_Binalbero(){
        FiglioDx=nullptr;
        FiglioSx=nullptr;
        Padre=nullptr;
    }

template <class TIPOETICHETTA>
    Cella_Binalbero<TIPOETICHETTA>::~Cella_Binalbero(){
    }

template <class TIPOETICHETTA>
    void Cella_Binalbero<TIPOETICHETTA>::setFiglioSx(Cella_Binalbero<TIPOETICHETTA>* sx){
        FiglioSx=sx;
    }

template <class TIPOETICHETTA>
    void Cella_Binalbero<TIPOETICHETTA>::setFiglioDx(Cella_Binalbero<TIPOETICHETTA>* dx){
        FiglioDx=dx;
    }

template <class TIPOETICHETTA>
    void Cella_Binalbero<TIPOETICHETTA>::setPadre(Cella_Binalbero<TIPOETICHETTA>* p){
        Padre=p;
    }

template <class TIPOETICHETTA>
    void Cella_Binalbero<TIPOETICHETTA>::setEtichetta(TIPOETICHETTA& e){
        etichetta=e;
    }

template <class TIPOETICHETTA>
    Cella_Binalbero<TIPOETICHETTA>* Cella_Binalbero<TIPOETICHETTA>::getFiglioSx(){
        return FiglioSx;
    }

template <class TIPOETICHETTA>
    Cella_Binalbero<TIPOETICHETTA>* Cella_Binalbero<TIPOETICHETTA>::getFiglioDx(){
        return FiglioDx;
    }

template <class TIPOETICHETTA>
    Cella_Binalbero<TIPOETICHETTA>* Cella_Binalbero<TIPOETICHETTA>::getPadre(){
        return Padre;
    }

template <class TIPOETICHETTA>
    TIPOETICHETTA Cella_Binalbero<TIPOETICHETTA>::getEtichetta(){
        return etichetta;
    }

template <class TIPOETICHETTA>
    bool Cella_Binalbero<TIPOETICHETTA>::operator == (Cella_Binalbero<TIPOETICHETTA>  b){
        if(getEtichetta()==b.getEtichetta())
            return true;
        else
            return false;
    }
    template <class TIPOETICHETTA>
   Cella_Binalbero<TIPOETICHETTA>::Cella_Binalbero(const Cella_Binalbero& c){
     etichetta=c.getEtichetta();
     FiglioDx=c.getFiglioDx();
     FiglioSx=c.getFiglioSx();
     Padre=c.getPadre();
 }

 template <class TIPOETICHETTA>
 void Cella_Binalbero<TIPOETICHETTA>::operator=(const Cella_Binalbero& c ){
    etichetta=c.getEtichetta();
    Padre=c.getPadre();
    FiglioDx=c.getFiglioDx();
    FiglioSx=c.getFiglioSx();
 }
#endif // NODO_ALBERO_BINARIO_H_INCLUDED
