/* 
  Realizzazione: Coda con lista
  Autore: Rosa Chiarappa   
*/  

#ifndef CODA_H_
#define CODA_H_
#include "Lista.h"
#include <iostream>

template <class tipoelem> 
class Coda
{
    public:
 
		Coda(); 
        ~Coda(); 
        void creacoda(); 
        bool codavuota(); 
        void incoda(tipoelem); 
        tipoelem leggicoda(); 
        void fuoricoda(); 

    private:
        Lista<tipoelem> codaL;
};

template<class tipoelem>
Coda<tipoelem>::Coda() 
{ 
	creacoda();
};

template<class tipoelem>
Coda<tipoelem>::~Coda()
{
    codaL.~Lista(); 
};

template<class tipoelem>
void Coda<tipoelem>::creacoda()
{
    codaL.crealista();
};

template<class tipoelem>
bool Coda<tipoelem>::codavuota()
{
    return(codaL.listavuota());
};

template<class tipoelem>
void Coda<tipoelem>::incoda(tipoelem elem)
{
    typename Lista<tipoelem>::posizione pos=codaL.primolista(); 
    
    while(!codaL.finelista(pos)) 
    {
        pos=codaL.succlista(pos);
    }
    
    codaL.inslista(elem,pos); 
};

template<class tipoelem> 
tipoelem Coda<tipoelem>::leggicoda()
{
    if(!codavuota()) 
        return(codaL.leggilista(codaL.primolista()));
};

template<class tipoelem>
void Coda<tipoelem>::fuoricoda()
{
    typename Lista<tipoelem>::posizione pos=codaL.primolista(); 
    if(!codavuota()) 
        codaL.canclista(pos); 
};

#endif
