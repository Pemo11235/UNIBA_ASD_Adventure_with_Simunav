#ifndef H_TRASPORTO
#define H_TRASPORTO

#include <string>
using namespace std;

class Trasporto
{

private:
    int partenza;                   //Luogo di partenza
    int arrivo;                     //Luogo di arrivo
    string mappa;                   //Mappa di arrivo

public:
    Trasporto();                    //Costruttore
    ~Trasporto();                   //Distruttore

    int get_partenza();             //Restituisce il codice del luogo di partenza
    int get_arrivo();               //Restituisce il codice del luogo di arrivo
    string get_mappa();             //Restituisce il nome della mappa di arrivo
    void set_partenza(int n);       //Inserisce il codice del luogo di partenza
    void set_arrivo(int n);         //Inserisce il codice del luogo di arrivo
    void set_mappa(string s);       //Inserisce il nome della mappa di arrivo
};

#endif
