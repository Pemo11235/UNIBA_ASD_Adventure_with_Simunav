#ifndef ATTIVITA_H
#define ATTIVITA_H
#include <iostream>
#include <string>

using namespace std;

class Attivita
{
    public:
        Attivita();
        virtual ~Attivita();
        string get_data();
        string get_descrizione();
        string get_autore();
        void set_data(string d);
        void set_descrizione(string desc);
        void set_autore(string a);

    private:
        string data;
        string descrizione;
        string autore;
};

#endif // ATTIVITA_H
