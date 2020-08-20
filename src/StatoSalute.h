#ifndef STATOSALUTE_H
#define STATOSALUTE_H

#include "Ferita.h"
#include "Lista.h"

class StatoSalute
{
public:
    StatoSalute(); //Costruttore di default
    bool Ferito(); //Restituisce true se il personaggio è ferito, false altrimenti
    void Cura(); //Cura il personaggio ripristinando lo stato di salute
    void SetFerita(Ferita); //Setta la ferita e aggiorna stato salute
    int GetPenalita(); //Restituisce la penalità subita dal Giocatore
    int GetStatoSalute(); //Restituisce lo Stato di Salute
    //INIZIO MODIFICHE GIOVANNI CASTELLANA
    void SetStatoSalute(int); //Aggiorna lo Stato di Salute
    void Miracolo(); //Cura il personaggio da una ferita
    //FINE MODIFICHE GIOVANNI CASTELLANA
    Lista<Ferita> Get_Ferite(); //Restituisce l'elenco di Ferite contratte dal giocatore
    void Aggiorna_Stato(); //Aggiorna StatoSalute e PenalitaMosse del personaggio
    bool Ferita_Contratta(Ferita); //Restituisce true se la Ferita è già stata contratta, false altrimenti
private:
    int Salute; //Stato di Salute del Giocatore: può variare 0≤x≤100
    int PenalitaMosse; //Penalità movimento del Giocatore: può variare 0≤x≤4
    Lista<Ferita> Ferite; //Insieme di Ferite (eventualmente vuoto) contratte dal Giocatore
};

#endif // STATOSALUTE_H
