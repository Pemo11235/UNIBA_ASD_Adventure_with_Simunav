/** 
 * @file CellaNodo.h 
 * Definizione della Cella presente nel vettore di Nodi di Grafo.h ( matrice di adiacenza) 
 * @author Graziano Montanaro. 
 * @date Anno Accademico 2018/19. 
 */ 

#ifndef CellaNodo_H_INCLUDED
#define CellaNodo_H_INCLUDED

template <class tipoElem>
class CellaNodo
{
public:
    CellaNodo();
    CellaNodo(const CellaNodo<tipoElem>&);
    ~CellaNodo();
    void setPresente(bool);
    void setEtichetta(tipoElem );
    void setArchi(int);
    void setIndice(unsigned int);
    unsigned int getIndice();
    bool getPresente();
    tipoElem getEtichetta();
    int getArchi();
    bool operator == (const CellaNodo<tipoElem>&);
    bool operator != (const CellaNodo<tipoElem>&);
    void operator = (const CellaNodo<tipoElem>&);

private:
    bool presente;
    tipoElem etichetta;
    int archi;
    unsigned int indice;
};

template <class tipoElem>
CellaNodo<tipoElem>::CellaNodo()
{
    presente = false;
    etichetta = tipoElem();
    archi = 0;
    indice = 0;
}

template <class tipoElem>
CellaNodo<tipoElem>::CellaNodo(const CellaNodo<tipoElem>& n)
{
    presente = n.presente;
    etichetta = n.etichetta;
    archi = n.archi;
    indice = n.indice;
}

template <class tipoElem>
CellaNodo<tipoElem>::~CellaNodo()
{

}


template <class tipoElem>
void CellaNodo<tipoElem>::setPresente(bool b)
{
    presente = b;
}

template <class tipoElem>
void CellaNodo<tipoElem>::setEtichetta(tipoElem e)
{
    etichetta = e;
}

template <class tipoElem>
void CellaNodo<tipoElem>::setArchi(int a)
{
    archi = a;
}

template <class tipoElem>
void CellaNodo<tipoElem>::setIndice(unsigned int a)
{
    indice = a;
}

template <class tipoElem>
unsigned int CellaNodo<tipoElem>::getIndice()
{
    return indice;
}

template <class tipoElem>
tipoElem CellaNodo<tipoElem>::getEtichetta()
{
    return etichetta;
}

template <class tipoElem>
bool CellaNodo<tipoElem>::getPresente()
{
    return presente;
}



template <class tipoElem>
int CellaNodo<tipoElem>::getArchi()
{
    return archi;
}

template <class tipoElem>
bool CellaNodo<tipoElem>:: operator ==(const CellaNodo<tipoElem>& n)
{
    return etichetta == n.etichetta;
}

template <class tipoElem>
bool CellaNodo<tipoElem>:: operator !=(const CellaNodo<tipoElem>& n)
{
    return etichetta != n.etichetta;
}

template <class tipoElem>
void CellaNodo<tipoElem>:: operator = (const CellaNodo<tipoElem>& n)
{
    presente = n.presente;
    etichetta = n.etichetta;
    archi = n.archi;
    indice = n.indice;
}

#endif // CellaNodo_H_INCLUDED
