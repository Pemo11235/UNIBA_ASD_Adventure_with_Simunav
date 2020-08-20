#ifndef PERSONAGGI_H_
#define PERSONAGGI_H_

#include <iostream>
#include <cstring>
#include <stdarg.h>
#include "Dialogo.h" //Aggiunta D'Andria Dresda al progetto di Federica Forte


using namespace std;

class Personaggi
{

public:
    Personaggi();
    ~Personaggi();
    //Setter
    void setNome(string);
    void setFrasi(string,string);
    void setLuogo(int);
    void setOgg(bool,int);
    void setOgg(bool,int,int);
    void setDialogo(Dialogo*); //aggiunta D'Andria Dresda al progetto di Federica Forte
    void setFrasiconOgg1(string,string);
    void setFrasiconOgg2(string,string);
    //Getter
    string getNome();
    int getLuogo();
    bool getIfNec();
    Dialogo* getDialogo(); //aggiunta D'Andria Dresda al progetto di Federica Forte
    int get_ogg1();
    int get_ogg2();
    //Metodi
    void SelezionaFrase();
    void SelezionaFrase1();
    void SelezionaFrase2();
    void stampa();

private:
    string nome;
    string fraseAiuto;
    string fraseAiutoconOgg1;
    string fraseAiutoconOgg2;
    string fraseIntralcio;
    string fraseIntralcioconOgg1;
    string fraseIntralcioconOgg2;
    int luogo;
    int ogg1,ogg2;
    bool ogg_necessario;
    Dialogo dialogo; //Aggiunta D'Andria Dresda al progetto di Federica Forte

};

#endif /* PERSONAGGI_H_ */

