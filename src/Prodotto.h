#ifndef PRODOTTO_H_INCLUDED
#define PRODOTTO_H_INCLUDED

#include <string>
using namespace std;

class Prodotto
{
public:
    Prodotto();
    Prodotto(string,float,int, int);
    ~Prodotto();
    float getCosto();
    string getNome();
    int getQuantita();
    int getCodice();
    void setQuantita(int);


private:
    float costo;
    int codice;
    string nome;
    int quantita;



};




#endif // PRODOTTO_H_INCLUDED
