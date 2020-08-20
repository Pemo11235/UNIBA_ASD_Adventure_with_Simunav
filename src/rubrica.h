#ifndef RUBRICA_H
#define RUBRICA_H
#include <iostream>
#include <string>
using namespace std;
class Rubrica
{
public:
    Rubrica();
    ~Rubrica();
    string get_nome() ;       //restituisce il valore, di tipo stringa, del nome
    string get_cognome();    //restituisce il valore, di tipo stringa, del cognome
    string get_interno();    //restituisce il valore, di tipo stringa, di Interno (luogo n cui è situato il personaggio ricercato nella rubrica)
    string get_telefono();   //restituisce il valore, di tipo stringa, del numero telefonico
    string get_descrizione();//restituisce il valore, di tipo stringa, della descrizione riguardante al personaggio
    void set_descrizione(string);  //imposta la descrizione riguardante al personaggio
    void set_nome(string);         //imposta il nome del personaggio
    void set_cognome(string);      //imposta il cognome del personaggio
    void set_interno(string);      //imposta il luogo in cui si trova il personaggio
    void set_telefono(string);     //imposta il numero telefonico del personaggio
private:
    string nome, cognome, interno, telefono, descrizione;
};
#endif // RUBRICA_H

