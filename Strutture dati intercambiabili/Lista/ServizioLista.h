/*
Realizzazione: Funzioni di servizio per la struttura dati Lista
Autore: Alessandro Annese
*/
#ifndef SERVIZIOLISTA_H
#define SERVIZIOLISTA_H

#include "Lista.h"
#include <iostream>

using namespace std;

template <class tipoelem>
void stampaLista(Lista<tipoelem> l)
{
    cout << "[";
    typename Lista<tipoelem>::posizione p;
    p = l.primolista();
    while(!l.finelista(p))
        {
            if(!l.finelista(l.succlista(p)))
            {
                cout << l.leggilista(p) <<  ",";
            }
            else
            {
                cout << l.leggilista(p);
            }
            p = l.succlista(p);
        }
    cout << "]";
}

template <class tipoelem>
void epurazioneLista(Lista<tipoelem> &l)
{
    typename Lista<tipoelem>::posizione p, j, r;
    p = l.primolista();
    while(!l.finelista(p))
    {
            j = l.succlista(p);
            while(!l.finelista(j))
                {
                if(l.leggilista(p) == l.leggilista(j))
                    {
                        r = l.preclista(j);
                        l.canclista(j);
                        j = l.succlista(r);
                    }
                else
                    j = l.succlista(j);

                }
        p = l.succlista(p);
    }
}


template <class tipoelem>
void fusioneLista(Lista<tipoelem> & a, Lista<tipoelem> & b, Lista<tipoelem> & f)
{
    typename Lista<tipoelem>::posizione pa, pb, pf;

    pa = a.primolista();
    pb = b.primolista();
    pf = f.primolista();

    while(!a.finelista(pa) && !b.finelista(pb))
        {
            if(a.leggilista(pa) < b.leggilista(pb))
            {
                f.inslista(a.leggilista(pa),pf);
                pa = a.succlista(pa);
            }
            else
            {
                f.inslista(b.leggilista(pb),pf);
                pb = b.succlista(pb);
            }
            pf = f.succlista(pf);
        }

    while(!a.finelista(pa))
        {
            f.inslista(a.leggilista(pa),pf);
            pa = a.succlista(pa);
            pf = f.succlista(pf);
        }

    while(!b.finelista(pb))
        {
            f.inslista(b.leggilista(pb),pf);
            pb = b.succlista(pb);
            pf = f.succlista(pf);
        }
}

template <class tipoelem>
bool ricercaLista(tipoelem e, Lista<tipoelem> & l)
{
	typename Lista<tipoelem>::posizione corrente = l.primolista();
    bool trovato = false, continua = true;
    while( (!l.finelista(corrente)) && (trovato == false) && (continua) )
        {
            if(l.leggilista(corrente) > e)
                continua = false;
            else
                if(l.leggilista(corrente) == e)
                    trovato = true;

            corrente = l.succlista(corrente);
        }
    return trovato;
}

template <class tipoelem>
void naturalMegeSort(Lista<tipoelem> &l)
{
    int numero_catene;
    do{
        Lista<tipoelem> a,b;
        distribuisci(l,a,b);
        numero_catene=0;
        l.crealista();
        fondi(l,a,b,numero_catene);
    }while(numero_catene != 1);
}

template <class tipoelem>
void distribuisci(Lista<tipoelem> &l,Lista<tipoelem> &a,Lista<tipoelem> &b)
{
    typename Lista<tipoelem>::posizione pl,pa,pb;
    pl=l.primolista();
    pa=a.primolista();
    pb=b.primolista();
    do{
        copiaCatena(a,pa,l,pl);
        if(!l.finelista(pl))
        {
            copiaCatena(b,pb,l,pl);
        }
    }while(!l.finelista(pl));
}

template <class tipoelem>
void fondi(Lista<tipoelem> &l, Lista<tipoelem> &a, Lista<tipoelem> &b, int &numero_catene)
{
    typename Lista<tipoelem>::posizione pa, pb, pl;
    pa=a.primolista();
    pb=b.primolista();
    pl=l.primolista();

    while( !a.finelista(pa) && !b.finelista(pb) )
        {
            fondiCatena(l,pl,a,pa,b,pb);
            numero_catene++;
        }

    while(!a.finelista(pa))
        {
            copiaCatena(l,pl,a,pa);
            numero_catene++;
        }

    while(!b.finelista(pb))
        {
            copiaCatena(l,pl,b,pb);
            numero_catene++;
        }
}

template <class tipoelem>
void copiaCatena(Lista<tipoelem> &s, typename Lista<tipoelem>:: posizione &ps, Lista<tipoelem> &l,typename Lista<tipoelem>::posizione &pl)
{
    bool finecatena = false;

    do{
        copia(l,pl,s,ps,finecatena);
    }while(!finecatena);
}

template <class tipoelem>
void fondiCatena(Lista<tipoelem> &l,typename Lista<tipoelem>::posizione &pl, Lista<tipoelem> &a, typename Lista<tipoelem>::posizione &pa, Lista<tipoelem> &b, typename Lista<tipoelem>::posizione &pb)
{
    bool finecatena = false;
    do{
        if( a.leggilista(pa) < b.leggilista(pb) )
        {
            copia(a,pa,l,pl,finecatena);
            if(finecatena)
                copiaCatena(l,pl,b,pb);
        }
        else
        {
            copia(b,pb,l,pl,finecatena);
            if(finecatena)
                copiaCatena(l,pl,a,pa);
        }
    }while(!finecatena);
}

template <class tipoelem>
void copia(Lista<tipoelem> &l, typename Lista<tipoelem>::posizione &pl, Lista<tipoelem> &s, typename Lista<tipoelem>::posizione &ps, bool &finecatena)
{
    tipoelem e = l.leggilista(pl);
    s.inslista(e,ps);
    pl = l.succlista(pl);
    ps = s.succlista(ps);

    if(l.finelista(pl))
        finecatena = true;
    else
       finecatena = (e > l.leggilista(pl));
}

template <class tipoelem>
typename Lista<tipoelem>::posizione NIL(Lista<tipoelem> & l)
{
    typename Lista<tipoelem>::posizione p = l.primolista();
    while(!l.finelista(l.succlista(p)))
        {
            p = l.succlista(p);
        }
    return p;
}


template <class tipoelem>
typename Lista<tipoelem>::posizione listMatching(Lista<tipoelem> &text,Lista<tipoelem> &pattern)
{
    bool trovato = false;
    Lista<typename Lista<tipoelem>::posizione> s;

    typename Lista<typename Lista<tipoelem>::posizione>::posizione ps = s.primolista();
    typename Lista<tipoelem>::posizione pt = text.primolista(), pp = pattern.primolista();


    typename Lista<tipoelem>::posizione inizio = pt, temp;

    while(!text.finelista(pt) && !pattern.finelista(pp) && !trovato)
        {
            if(text.leggilista(pt)==pattern.leggilista(pp))
            {
                s.inslista(pt,ps);
                ps=s.succlista(ps);
                pt=text.succlista(pt);
                pp=pattern.succlista(pp);
                if(pattern.finelista(pp))
                {
                    trovato=true;
                }
            }
            else
            {
                s.inslista(pt,ps);
                temp = Calcolo_Successivo(pattern,s,text);
                if(temp == NIL(text))
                {
                    pt = text.succlista(pt);
                }
                else
                {
                    pt = temp;
                }
                inizio=pt;
                pp=pattern.primolista();
                s.crealista();
                ps=s.primolista();
            }
        }

    if(trovato)
        return inizio;
    else
        return NIL(text);
}

template <class tipoelem>
typename Lista<tipoelem>::posizione Calcolo_Successivo(Lista<tipoelem> &pattern, Lista<typename Lista<tipoelem>::posizione> & s, Lista<tipoelem> &text)
{
    typename Lista<tipoelem>::posizione temp = NIL(text);
    typename Lista<typename Lista<tipoelem>::posizione>::posizione ps = s.primolista();
    bool esci = false;
    if(!s.listavuota())
    {
       s.canclista(ps);
       ps = s.primolista();
    }

    if(!s.listavuota())
    {
        while(!s.finelista(s.primolista()) && esci)
            {
                if(pattern.leggilista(pattern.primolista())==text.leggilista(s.leggilista(s.primolista())))
                {
                    temp =  s.leggilista(ps);
                    esci = true;
                }
                else
                {
                    s.canclista(ps);
                    ps = s.primolista();
                }
            }
    }
    return temp;
}
#endif
