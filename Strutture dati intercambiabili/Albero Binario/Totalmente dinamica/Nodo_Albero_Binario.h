#ifndef NODO_ALBERO_BINARIO_H_INCLUDED
#define NODO_ALBERO_BINARIO_H_INCLUDED

template <class TIPOETICHETTA>
    class Cella_Binalbero{
        public:
            Cella_Binalbero();
            ~Cella_Binalbero();

            void setFiglioSx(Cella_Binalbero<TIPOETICHETTA>*);
            void setFiglioDx(Cella_Binalbero<TIPOETICHETTA>*);
            void setPadre(Cella_Binalbero<TIPOETICHETTA>*);
            void setEtichetta(TIPOETICHETTA&);
            Cella_Binalbero<TIPOETICHETTA>* getFiglioSx();
            Cella_Binalbero<TIPOETICHETTA>* getFiglioDx();
            Cella_Binalbero<TIPOETICHETTA>* getPadre();
            TIPOETICHETTA getEtichetta();
            bool operator == (Cella_Binalbero<TIPOETICHETTA>);
            Cella_Binalbero(const Cella_Binalbero& );
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
