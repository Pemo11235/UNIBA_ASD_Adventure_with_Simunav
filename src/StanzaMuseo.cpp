#include "StanzaMuseo.h"
#include <iostream>
#include <cstdlib>

using namespace std;

StanzaMuseo::StanzaMuseo()
{
    descrizione = "";
    titolo = "";
}

void StanzaMuseo::setdescrizione(string s)
{

    descrizione = s;

}

void StanzaMuseo::settitolo(string s)
{

    titolo = s;

}

string StanzaMuseo::getdescrizione()
{

    return(descrizione);

}

string StanzaMuseo::gettitolo()
{

    return(titolo);

}

bool StanzaMuseo::operator==(StanzaMuseo s)
{
    return((gettitolo()==s.gettitolo()) && (getdescrizione()==s.getdescrizione()));
}

ostream& operator<<(ostream& os,  StanzaMuseo& s) //sovraccarico output
{
    os<<"Titolo: "<<s.gettitolo()<<",Descrizione: "<<s.getdescrizione();
    return(os);
}
//Implementaione di StanzaMuseo.h aggiunta da ANTONIOPASTORELLI
