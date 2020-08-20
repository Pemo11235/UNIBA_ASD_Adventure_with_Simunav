#ifndef DOMANDA_H
#define DOMANDA_H
#include "string"
using namespace std;

class Domanda
{
public:
    Domanda();
    Domanda(const Domanda& ); //costruttore di copia
    virtual ~Domanda();
    Domanda(int, string);//costruttore codice-domanda
    int leggicodice();//funzione che ritorna il codice della domanda
    string leggidomanda();//funzione che ritorna la stringa contenente la domanda con le relative possibilità di risposta

private:
    string domanda;
    int codicedomanda;
};



#endif // DOMANDA_H
