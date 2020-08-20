#ifndef _VIALUOGO_H
#define _VIALUOGO_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Vialuogo
{
    friend ostream& operator<<(ostream& os, const Vialuogo& v); //overload output
public:
    //costruttore
    Vialuogo();

    //distruttore di default

    //setter e getter
    void scrivinome(string);
    void scrivimin(unsigned int);
    void scrivimax(unsigned int);
    string legginome() const;
    unsigned int leggimin() const;
    unsigned int leggimax() const;


    //sovraccarichi
    void operator =(Vialuogo);
    bool operator ==(Vialuogo);

private:
    string nome;
    unsigned int min,max;
};

#endif
