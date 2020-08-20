#include <iostream>  // MODIFICA D-R(D'Orsi):Negozio + Banca
#include <cstdlib>   // MODIFICA D-R(D'Orsi):Negozio + Banca
#include "Interfaccia.h"


using namespace std;

Interfaccia::Interfaccia()
{
    //cout << "Interfaccia avviata" << endl;
}

int Interfaccia::menuPrincipale()
{
    int scelta;

    scrivi(" ---- Menu ---- ");
    scrivi("1 - nuova partita");
    scrivi("2 - ricarica partita salvata");
    scrivi("0 - Esci");
    do
    {
        scelta = leggi_intero("Che intendi fare [0-2]? ");
    }
    while (scelta < 0 || scelta > 2);
    return scelta;
}

void Interfaccia::saluto()
{
    cout << "Arrivederci!" << endl;
}

void Interfaccia::scrivi(string testo)
{
    cout << testo << endl;
}

void Interfaccia::scrivi_parziale(string testo)
{
    cout << testo;
}

void Interfaccia::scrivi_parziale(int n)
{
    cout << n;
}

// Inizio modifica Angelo Petronelli
void Interfaccia::scrivi_carattere(char c)
{
    cout << c;
}
// fine modifica

// MODIFICA D-R(D'Orsi):Negozio + Banca
void Interfaccia::scrivi_float( float numero )
{
    cout << numero;
}

// MODIFICA D-R(D'Orsi):Negozio + Banca
float Interfaccia::leggi_float(string domanda)
{
    float risposta;

    cout << domanda << endl;
    cin >> risposta;
    return risposta;
}

void Interfaccia::a_capo()
{
    cout << endl;
}

int Interfaccia::leggi_intero(string domanda)
{
    int risposta;

    cout << domanda << endl;
    cin >> risposta;
    return risposta;
}

string Interfaccia::leggi_stringa(string domanda)
{
    string risposta;

    cout << domanda << endl;
    getline(cin, risposta);
    return risposta;
}


string Interfaccia::leggi_comando()
{
    string risposta;
    fflush(stdin);
    cin.clear();
    do
    {
        cout << "Cosa devo fare?" << endl;
        getline(cin, risposta);
    }
    while (risposta[0] == '\0');
    cout << endl;
    return risposta;
}

void Interfaccia::disegna_scena(Luogo luogo)
{
    /*
     * Vaira - Check sull'ultimo luogo visitato. Se l'ultimo luogo
     * visitato è uguale a quello attuale (passato come parametro)
     * l'oggetto DescData abbinato al luogo viene reinizializzato.
     * */
    if (luogo == ultimoLuogo)
        luogo.getDescData()->initialize();
    else
        ultimoLuogo = luogo;
    cout << "\nSei " << luogo.getDescrizione() << "." << endl;
}

void Interfaccia::elenca_oggetti(Oggetti oggetti, string premessa)
{

//_MODIFICHE_ML
    //Modifica Mirco Sternativo
    int n_oggettiZ = oggetti.get_n_oggettiZ();

    if (n_oggettiZ > 0)
    {
        cout << premessa;
        for (int i = 1; i <= n_oggettiZ; i++)
        {
            cout << "\n- " << oggetti.get_oggetto(i).get_nome();

            if (i == n_oggettiZ)
            {
                cout << ".";
            }
            else
            {
                cout << ";";
            }
        }
        cout << endl;
    }
    //fine modifiche
    /*int n_oggetti = oggetti.get_n_oggetti();

    if (n_oggetti > 0)
    {
        cout << premessa;
        //Inizio modifica Gallone - Modifico il metodo in modo che mi faccia vedere i differenti attributi di ogni oggetto
        // in base al particolare oggetto
        for (int i = 1; i <= n_oggetti; i++)
        {


            if (oggetti.get_oggetto(i).get_luogo() == 21 || oggetti.get_oggetto(i).get_luogo() == 22)
            {
                if (i == n_oggetti)
                    cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ", Valore energetico: " << oggetti.get_oggetto(i).get_valore_e() << ", Categoria: " << oggetti.get_oggetto(i).get_categoria() << ".";
                else
                    cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ", Valore energetico: " << oggetti.get_oggetto(i).get_valore_e() << ", Categoria: " << oggetti.get_oggetto(i).get_categoria() << ";";
            }
            else if (oggetti.get_oggetto(i).get_luogo() == 0)
            {


                if (oggetti.get_oggetto(i).get_codice() < 80 ||  oggetti.get_oggetto(i).get_codice() > 94 ) //da modificare in base al numero di oggetti
                {
                    if (i==n_oggetti)
                        cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ".";
                    else
                        cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ";";
                }
            }
            else
            {
                if (i == n_oggetti)
                    cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ".";
                else
                    cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ";";
            }
        	}

        //Fine Modifica Gallone*/
//FINE_MODIFICHE_ML

}



//inizio modifiche ROSA CHIARAPPA

void Interfaccia::elenca_rubati(Oggetti oggetti, string premessa)
{
    int n_oggetti = oggetti.get_n_oggetti();

    cout << premessa;

    for (int i = 1; i <= n_oggetti; i++)
    {
        if (oggetti.get_oggetto(i).get_luogo() == 0)
        {
            if (oggetti.get_oggetto(i).get_rubato() == true)
            {

                cout << "\n- " << oggetti.get_oggetto(i).get_nome() << ".\n";

            }
        }
    }
}

//fine modifiche ROSA CHIARAPPA





void Interfaccia::pausa()
{
    string invio;

    cout << "\n- Premi <invio> per continuare -\n";
    getline(cin, invio);
    //system("clear"); //linux os  //Modificato da ANTONIO PASTORELLI    windows os
    system("cls"); //linux os  //Modificato da ANTONIO PASTORELLI


    cout << endl;
}

char Interfaccia:: leggi_carattere(string s)
{
    char c;
    cout << s << " ";
    cin >> c;
    return c;
}
