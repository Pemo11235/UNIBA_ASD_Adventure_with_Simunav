#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define DIM_MAX 30

class Appunto
{
public:
    Appunto();
    void Scrivi(string);
    void Leggi(string);
    void Cancella(string);

private:
    FILE *nota;

};
