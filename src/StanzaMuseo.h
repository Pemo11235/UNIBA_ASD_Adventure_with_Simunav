#ifndef STANZAMUSEO_H
#define STANZAMUSEO_H

#include<string>

using namespace std;

class StanzaMuseo
{
public:
    StanzaMuseo();
    //StanzaMuseo(const StanzaMuseo&);
    void setdescrizione(string);
    string getdescrizione();
    void settitolo(string);
    string gettitolo();
    bool operator == (StanzaMuseo);
    //void operator = (const StanzaMuseo&);
private:
    string descrizione,titolo;
};

//HEADER aggiunto da ANTONIO PASTORELLI

#endif // STANZAMUSEO_H
