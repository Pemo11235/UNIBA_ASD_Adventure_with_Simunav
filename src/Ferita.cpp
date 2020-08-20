#include "Ferita.h"

Ferita::Ferita()
{
}

Ferita::Ferita(string name, string description, int code, int damage)
{
    Nome=name;
    Descrizione=description;
    Codice=code;
    Danno_Salute=damage;
}

string Ferita::GetNome()
{
    return(Nome);
}

string Ferita::GetDescrizione()
{
    return(Descrizione);
}

int Ferita::GetCodice()
{
    return(Codice);
}

int Ferita::GetDannoSalute()
{
    return(Danno_Salute);
}
