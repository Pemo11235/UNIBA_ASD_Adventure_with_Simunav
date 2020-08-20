#ifndef CANZONE_H
#define CANZONE_H
#include <iostream>
#include <string>
using namespace std;
class Canzone
{
public:
    Canzone();
    ~Canzone();
    string get_nome() ;       //restituisce il valore, di tipo stringa, del nome
    string get_artista();    //restituisce il valore, di tipo stringa, dell'artista
    int get_anno();    //restituisce il valore, di tipo intero dell'anno del brano
    void set_nome(string);  //imposta il nome del brano
    void set_artista(string);         //imposta il nome dell'artista
    void set_anno(int);      //imposta l'anno del brano
    friend ostream& operator<<(ostream& os, const Canzone& canz); //OVERLOAD Dell'operatore COUT
private:
    string nome, artista;
    int anno;
};
#endif // CANZONE_H
