#ifndef STATO_COMANDO_H
#define STATO_COMANDO_H

#include <string>
#include "Stato.h"


class stato_comando
{
public:
    stato_comando();
    stato_comando(Stato, string);
    virtual ~stato_comando();
    void set_stato(Stato);
    void set_comando(string);
    Stato get_stato();
    string get_comando();

private:
    Stato stato;
    string comando;

};

#endif // STATO_COMANDO_H
