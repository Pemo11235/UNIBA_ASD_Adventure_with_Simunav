#include "ServizioTrasporti.h"
#include "Trasporto.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
ServizioTrasporti::ServizioTrasporti() {};

ServizioTrasporti::ServizioTrasporti(ifstream &t)
{
    trasporti.crealista();
    posiz p = trasporti.primolista();
    string buffer;
    int i;
    string estratto;
    Trasporto trasporto;
    while (!t.eof())
    {
        i = 0;
        getline(t, buffer);
        estratto = estrai_stringa(buffer, i, ',');
        trasporto.set_partenza(atoi(estratto.c_str()));
        estratto = estrai_stringa(buffer, i, ',');
        trasporto.set_arrivo(atoi(estratto.c_str()));
        estratto = estrai_stringa(buffer, i, ',');
        trasporto.set_mappa(estratto);
        trasporti.inslista(trasporto, p);
        p = trasporti.succlista(p);
    }
    t.close();
    t.clear();
}

ServizioTrasporti::~ServizioTrasporti()
{

    svuotaLista(trasporti);
}

void ServizioTrasporti::cerca_trasporto(int n)
{
    posiz p;
    bool trovato = false;
    p = trasporti.primolista();
    trovato = (trasporti.leggilista(p).get_partenza() == n);
    while (!(trovato))
    {
        p = trasporti.succlista(p);
        trovato = (trasporti.leggilista(p).get_partenza() == n);
    }
    indice = p;
}

int ServizioTrasporti::get_luogo()
{
    return (trasporti.leggilista(indice).get_arrivo());
};

string ServizioTrasporti::get_map()
{
    return (trasporti.leggilista(indice).get_mappa());
};

string ServizioTrasporti::estrai_stringa(string s, int &i, char fine)
{
    string estratto = "";
    while (s[i] != fine && i < s.length())
    {
        estratto += s[i];
        i++;
    }
    i++;
    return (estratto);
}

void ServizioTrasporti::stampa_trasporti()
{
    posiz p = trasporti.primolista();
    while (!trasporti.finelista(p))
    {
        cout << trasporti.leggilista(p).get_partenza() << " - " << trasporti.leggilista(p).get_arrivo() << " - " << trasporti.leggilista(p).get_mappa().c_str() << endl;
        p = trasporti.succlista(p);
    }
}

/*
 * @author Andrea Esposito & Alessandro Annese
 */
void ServizioTrasporti::operator=(const ServizioTrasporti& s)
{
    indice = s.indice;
    copiaLista(trasporti, s.trasporti);
}
