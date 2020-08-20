#include "risposta.h"

risposta::risposta()
{
    risp = "Non selezionato";
    esatto = false;
}

risposta::~risposta()
{}

void risposta::operator =(risposta r)
{
    set_risp(r.get_risp());
    set_esatto(r.get_esatto());
}

void risposta::set_risp(string r)
{
    risp = r;
}

void risposta::set_esatto(bool e)
{
    esatto = e;
}

string risposta::get_risp()
{
    return risp;
}

bool risposta::get_esatto()
{
    return esatto;
}
