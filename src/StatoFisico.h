#ifndef STATOFISICO_H
#define STATOFISICO_H

/*
*Progetto AMS
*Classe che implementa le caratteristiche fisiche del personaggio
*/
class StatoFisico
{
public:
    StatoFisico();
    ~StatoFisico();

    inline float getCostituzione()
    {
        return costituzione;
    }
    inline void setCostituzione(float cos)
    {
        costituzione = cos;
    }
    inline float getResistenza()
    {
        return resistenza;
    }
    inline void setResistenza(float res)
    {
        resistenza = res;
    }
    bool feritaEvitata(int random);
    float riduciTempo(float time);
    const static int MAX_COS;
    const static int MAX_RES;

private:
    float costituzione;
    float resistenza;
};

#endif // STATOFISICO_H
