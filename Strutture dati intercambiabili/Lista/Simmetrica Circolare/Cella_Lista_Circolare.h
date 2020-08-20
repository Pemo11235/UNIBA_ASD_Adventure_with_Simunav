//Cella per Lista con Puntatori Circolare
//Modificata da A.Annese
#ifndef Cella_L_Circolare_H
#define Cella_L_Circolare_H

template<class X> 
class Cella_L_Circ
{
public:
    typedef X tipoelem;

    void scrivicella(tipoelem);
    tipoelem leggicella() const;
    void scrivisucc(Cella_L_Circ<X>*);
    Cella_L_Circ<X>* leggisucc() const;

private:
    tipoelem elemento; //informazione
    Cella_L_Circ<X>* succ; //riferimento al nodo successivo
};


template <class X> 
void Cella_L_Circ<X>::scrivicella(tipoelem elem)
{
    elemento=elem;
}

template <class X> 
X Cella_L_Circ<X>::leggicella() const
{
    return (elemento);
}

template <class X> 
void Cella_L_Circ<X>::scrivisucc(Cella_L_Circ<X>* pos)
{
    succ=pos;
}

template <class X> Cella_L_Circ<X>* Cella_L_Circ<X>::leggisucc() const
{
    return (succ);
}

#endif // Cella_L_Circolare_H
