#ifndef BATTERIA_H
#define BATTERIA_H
#include <iostream>
#include <string>

using namespace std;

class Batteria
{
    public:
        Batteria();
        virtual ~Batteria();
        int get_stato();
        string get_modello();
        void set_stato(int stat);
        void set_modello(string mod);

    private:
        int stato;
        string modello;
};

#endif // BATTERIA_H
