#ifndef STATO_H
#define STATO_H
#include "Oggetti.h"
#include "f_array.h"
#include "Pila.h"
#define MAX 24
#define NULLV -99

class Stato
{
public:
    Stato();
    virtual ~Stato();
    void set_luogo(int);
    void set_passo(int);
    void set_tempo(int);
    void set_ogg(int*);
    void set_parete_stagna(int);
    void set_cabina(int);

    int get_passo();
    int get_tempo();
    int get_luogo();
    int* get_ogg();
    int get_parete_stagna();
    int get_cabina();

    bool stato_completo();		 // boolean per verificare se lo stato è completo o meno
    void unisci(Stato);			 //se lo stato attuale non è completo lo unisco a quello precedente
    void differenza(Stato, int); // per confrontare due stati

private:
    int oggetti[MAX];
    int luogo_attuale;
    int tempo;
    int passo_soluzione;
    int parete_stagna;
    int cabina;

    bool is_null(int); 		  //controlla se l'intero passato è null (cioè = 0)
    bool is_null(int[], int); //controlla se il puntatore all'intero è null (lo utilizzo per l array di oggetti)
    // overloading di funzioni, a seconda dei parametri, le funzioni con lo stesso nome svolgono compiti diversi

};

#endif // STATO_H
