#include "StatoFisico.h"
const int StatoFisico::MAX_COS = 50;
const int StatoFisico::MAX_RES = 50;
StatoFisico::StatoFisico()
{
    costituzione = 0;
    resistenza = 0;
}

StatoFisico::~StatoFisico()
{

}

float StatoFisico::riduciTempo(float time)
{
    if (resistenza == MAX_RES && costituzione == MAX_COS)
    {
        time -= (time / 100) * 75;
    }
    else
    {
        time -= (time / 100) * costituzione;
    }
    return time;
}

bool StatoFisico::feritaEvitata(int random)
{
    bool fer = false;
    random = (random % 99) + 1;
    if (resistenza == MAX_RES && costituzione == MAX_COS)
    {
        fer = (random <= 75);
    }
    else
    {
        fer = (random <= resistenza);
    }
    return fer;
}
