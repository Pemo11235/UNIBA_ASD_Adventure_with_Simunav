#ifndef DIALOGO_H
#define DIALOGO_H
#include "AlberoNario.h"
#include "Domanda.h"
#include "math.h"
#include <iostream>
#include "Pila.h"
using namespace std;
class Dialogo{
public:
    Dialogo();
    Dialogo(string);
    Dialogo(const Dialogo& );
    virtual ~Dialogo();
    //funzione ricorsiva che fa ritornare il nodo domanda corrispondente al codice richiesto
    Albero<Domanda>::nodo trovanodo(Albero<Domanda>::nodo, int);

    string leggiPersonaggio();
    int getstato();
    void setstato(int);

    //metodi usati per costruire l'albero dialogo
    void inseriscidomanda(int,string);
    void inseriscipresentazione(string);
    void inserisciprimaopzione(Albero<Domanda>::nodo,int, string);
    void inserisciopzionesuccessiva(Albero<Domanda>::nodo,int, string);

    //metodo che visualizza a video la domanda allo stato corrente
    void visualizzadomande();
    // metodo che cambia lo stato del dialogo in base alla risposta data
    void cambiastato(int);
    //metodo che riceve la risposta e controlla la sua validità
    bool rispondi(int);
    //funzione che ritorna true quando il dialogo è vuoto
    bool dialogoVuoto();
    //funzione che ritorna true quando si raggiunge una foglia dell'albero del dialogo
    bool isFoglia();

private:
    string personaggio;//nome personaggio a cui è associato il dialogo
    int stato;//stato attuale del dialogo
    Albero<Domanda> dialogo;//albero contenente le domande del dialogo
};


#endif // DIALOGO_H
