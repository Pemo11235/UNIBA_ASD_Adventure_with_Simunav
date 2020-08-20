/*
Template: Cella per Lista con Doppi Puntatori
Autore: A. Annese
*/
#ifndef CELLA_L_DP_H_
#define CELLA_L_DP_H_

template <class tipoelem>
class Cella_L_DP{
public:
    Cella_L_DP();
    ~Cella_L_DP();

    tipoelem getElem() const;
    void setElem(tipoelem);
    Cella_L_DP<tipoelem>* getSucc() const;
    void setSucc(Cella_L_DP<tipoelem>*);
    Cella_L_DP<tipoelem>* getPrec() const;
    void setPrec(Cella_L_DP<tipoelem>*);
private:
    tipoelem elem;
    Cella_L_DP<tipoelem>* succ;
    Cella_L_DP<tipoelem>* prec;
};

template <class tipoelem>
Cella_L_DP<tipoelem>::Cella_L_DP()
{
    succ = nullptr;
    prec = nullptr;
}

template <class tipoelem>
Cella_L_DP<tipoelem>::~Cella_L_DP(){}

template <class tipoelem>
tipoelem Cella_L_DP<tipoelem>::getElem() const
{
    return elem;
}

template <class tipoelem>
void Cella_L_DP<tipoelem>::setElem(tipoelem e)
{
    elem = e;
}

template <class tipoelem>
Cella_L_DP<tipoelem>* Cella_L_DP<tipoelem>::getSucc() const
{
    return succ;
}

template <class tipoelem>
void Cella_L_DP<tipoelem>::setSucc(Cella_L_DP<tipoelem>* e)
{
    succ = e;
}

template <class tipoelem>
Cella_L_DP<tipoelem>* Cella_L_DP<tipoelem>::getPrec() const
{
    return prec;
}

template <class tipoelem>
void Cella_L_DP<tipoelem>::setPrec(Cella_L_DP<tipoelem>* e)
{
    prec = e;
}

#endif //CELLA_L_DP_H_
