#include "Personaggi.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdarg.h>

using namespace std;

Personaggi::Personaggi() {}

Personaggi::~Personaggi() {}

void Personaggi::setNome( string a)
{
    nome=a;
    ogg_necessario=false;
}

void Personaggi::setFrasi(string a,string b)
{
    fraseAiuto=a;
    fraseIntralcio=b;
}

void Personaggi::setLuogo(int a)
{
    luogo=a;
}

string Personaggi::getNome()
{
    return nome;
}

int Personaggi::getLuogo()
{
    return luogo;
}

void Personaggi::SelezionaFrase()
{
    int v;
    v= rand()  % 2;
    if(v==1)
    {

        cout<<fraseAiuto<<endl;
    }
    else if(v==0)
    {
        cout<<fraseIntralcio<<endl;
    }
    else
    {
        cout<<"error"<<endl;
    }
}

void Personaggi::stampa()
{
    cout<<nome<<" ti dice"<<endl;
    SelezionaFrase();
}

void Personaggi::setOgg(bool a,int o1, int o2)
{
    ogg_necessario=a;
    ogg1=o1;
    ogg2=o2;
}

void Personaggi::setOgg(bool a, int o1)
{
    setOgg(a, o1, 0);
}

bool Personaggi::getIfNec()
{
    return ogg_necessario;
}

int Personaggi::get_ogg1()
{
    return ogg1;
}

int Personaggi::get_ogg2()
{
    return ogg2;
}


void Personaggi::setFrasiconOgg1(string a, string b)
{
    fraseAiutoconOgg1=a;
    fraseIntralcioconOgg1=b;
}

void Personaggi::setFrasiconOgg2(string a, string b)
{
    fraseAiutoconOgg2=a;
    fraseIntralcioconOgg2=b;
}
void Personaggi::SelezionaFrase1()
{
    int v;
    v= rand()  % 2;
    if(v==1)
    {
        cout<<nome<<" ti dice"<<endl;
        cout<<fraseAiutoconOgg1<<endl;
        cout<<endl;
    }
    else if(v==0)
    {
        cout<<nome<<" ti dice"<<endl;
        cout<<fraseIntralcioconOgg1<<endl;
    }
    else
    {
        cout<<"error"<<endl;
    }
}
void Personaggi::SelezionaFrase2()
{
    int v;
    v= rand()  % 2;
    if(v==1)
    {
        cout<<nome<<" ti dice"<<endl;
        cout<<fraseAiutoconOgg2<<endl;
        cout<<endl;
    }
    else if(v==0)
    {
        cout<<nome<<" ti dice"<<endl;
        cout<<fraseIntralcioconOgg2<<endl;
    }
    else
    {
        cout<<"error"<<endl;
    }
}

//inizio modifiche D'Andria Dresda al progetto di Federica Forte
void Personaggi::setDialogo(Dialogo *dialogodainserire)
{
    this->dialogo=*dialogodainserire;
}

Dialogo* Personaggi::getDialogo()
{
    return (&this->dialogo);
}
//fine modifiche
