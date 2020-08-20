#include "Vocabolo.h"

Vocabolo::Vocabolo()
{
    parola = "";
    codice = 0;
}

void Vocabolo::set(string p, int c)
{
    parola = p;
    codice = c;
}

string Vocabolo::get_parola()
{
    return parola;
}

int Vocabolo::get_codice()
{
    return codice;
}


