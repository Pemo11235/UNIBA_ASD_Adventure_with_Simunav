#ifndef _VIA_H
#define _VIA_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Via
{
    friend ostream& operator<<(ostream& os, const Via& v); //overload output
public:

    //costruttori
    Via();

    //distruttore di default

    //setter e getter
    string legginome() const;
    string leggidirezione() const;
    float leggilunghezza() const;
    float leggitempo() const;
    bool leggiasfalto() const;
    bool leggipedaggio() const;
    void scrivinome(string);
    void scrividirezione(string);
    void scrivilunghezza(float);
    void scrivitempo(float);
    void scriviasfalto(bool);
    void scrivipedaggio(bool);

    //sovraccarichi
    void operator =(Via);
    bool operator ==(Via);

private:
    string nome,direzione;
    float lunghezza,tempo;
    bool asfalto,pedaggio;
};

#endif
