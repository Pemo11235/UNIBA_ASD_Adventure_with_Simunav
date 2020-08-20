/** 
 * @file CellaGrafo.h 
 * Definizione della Cella presente nella matrice di Grafo.h ( matrice di adiacenza) 
 * @author Graziano Montanaro. 
 * @date Anno Accademico 2018/19. 
 */  


#ifndef CELLAGRAFO_H_INCLUDED
#define CELLAGRAFO_H_INCLUDED


template <class tipoPeso>
class CellaGrafo
{
public:
    CellaGrafo();
    CellaGrafo(const CellaGrafo<tipoPeso>& );
    ~CellaGrafo();
    void setUsato(bool);
    void setPeso(tipoPeso);
    bool getUsato();
    tipoPeso getPeso();
    bool operator == ( const CellaGrafo<tipoPeso> & );
    bool operator != ( const CellaGrafo<tipoPeso> &);
    void operator = ( const CellaGrafo<tipoPeso> & );
private:
    bool usato;
    tipoPeso peso;
};

template <class tipoPeso>
CellaGrafo<tipoPeso>::CellaGrafo()
{
    usato = false;
    peso = tipoPeso();
}

template <class tipoPeso>
CellaGrafo<tipoPeso>::CellaGrafo(const CellaGrafo<tipoPeso>& c)
{
    usato = c.usato;
    peso = c.peso;
}

template <class tipoPeso>
CellaGrafo<tipoPeso>::~CellaGrafo()
{

}

template <class tipoPeso>
void CellaGrafo<tipoPeso>::setUsato(bool b)
{
    usato = b;
}

template <class tipoPeso>
void CellaGrafo<tipoPeso>::setPeso(tipoPeso p)
{
    peso = p;
}

template <class tipoPeso>
bool CellaGrafo<tipoPeso>::getUsato()
{
    return usato;
}

template <class tipoPeso>
tipoPeso CellaGrafo<tipoPeso>::getPeso()
{
    return peso;
}

template <class tipoPeso>
bool CellaGrafo<tipoPeso>::operator == (const CellaGrafo<tipoPeso> & c)
{
    return peso == c.peso;
}

template <class tipoPeso>
bool CellaGrafo<tipoPeso>::operator != (const CellaGrafo<tipoPeso> & c)
{
    return peso != c.peso;
}

template <class tipoPeso>
void CellaGrafo<tipoPeso>::operator = (const CellaGrafo<tipoPeso> & c)
{
    peso = c.peso;
    usato = c.usato;
}

#endif // CELLAGRAFO_H_INCLUDED
