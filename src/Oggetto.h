#ifndef H_OGGETTO
#define H_OGGETTO

#include <string>

using namespace std;

class Oggetto
{
public:
    Oggetto();
    Oggetto(string n, int c, int l, int w);
    // Modifica Gallone - dichiaro i nuovi costruttori
    Oggetto(string n, int c, int l,int w,int v, string cat);
    Oggetto(string n, int c, int l,int w, string cat);

    //fine modifica Gallone


    Oggetto(string n, int c, int l,int w, float p); //MODIFICA D-R(D'Orsi):Negozio + Banca
    //START DAMONE
    //Oggetto(string n, int c, int l, string d);
    //END DAMONE




    string get_nome();
    int get_codice();
    int get_luogo();
    void set_luogo(int &l);

    // Avventura estesa
    string get_descrizione();
    double get_valore();
    int get_peso();


    void set_nome(string);
    void set_descrizione(string);
    void set_valore(double);
    void set_peso(double);

    void set_luogo_n(int);	 //Modifica DELLA FOLGORE GRAZIA
    void set_isVeicolo(bool);  //Modifica DELLA FOLGORE GRAZIA
    bool is_Veicolo();	 //Modifica DELLA FOLGORE GRAZIA

    float get_prezzo();		 //MODIFICA D-R(D'Orsi):Negozio + Banca
    void set_prezzo(float);	 //MODIFICA D-R(D'Orsi):Negozio + Banca
    // Modifica Gallone - dichiaro i nuovi metodi
    int get_valore_e();
    string get_categoria();


    //inizio modifiche ROSA CHIARAPPA
    void set_rubato(bool);
    bool get_rubato();
    // fine modifiche ROSA CHIARAPPA


private:
    string nome;
    int codice;
    int luogo; //Luogo posizione;
    // Avventura estesa
    string descrizione;
    double valore;
    double peso;
    float prezzo; //MODIFICA D-R(D'Orsi):Negozio + Banca
    bool veicolo; //Modifica DELLA FOLGORE GRAZIA
    // modifica Gallone - dichiaro le nuove variabili
    int valore_e;
    string category;


    bool rubato; //modifiche ROSA CHIARAPPA

};

#endif
