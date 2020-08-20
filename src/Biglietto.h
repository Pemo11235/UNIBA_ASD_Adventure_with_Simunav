#ifndef BIGLIETTO_H
#define BIGLIETTO_H

#include <string>
using namespace std;

class Biglietto
{
public:
    Biglietto(string, int);
    Biglietto();
    ~Biglietto();
    string getDestinazione() const;
    int getCosto() const;

private:
    string destinazione;
    int costo;
};

#endif

