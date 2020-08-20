#include "Bacheca.h"

Bacheca :: Bacheca()
{
    CreaBacheca();
}

Bacheca :: ~Bacheca() {}

void Bacheca :: CreaBacheca()
{
    messCancellabili = 0;
}

void Bacheca :: StampaBacheca()
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    string temp;

    if(!BachecaVuota())
    {
        p=bacheca.primolista();

        while(!bacheca.finelista(p))
        {
            temp=bacheca.leggilista(p);
            if(temp[0]=='*')
                temp.erase(0,1);
            cout << " - " << temp << "\n\n";
            p=bacheca.succlista(p);
        }
    }
    else
        cout << "                                   NON CI SONO AVVISI IN BACHECA\n\n";
}

void Bacheca :: StampaMessCancellabili()
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    string temp;
    int i=1;

    p=bacheca.primolista();
    temp=bacheca.leggilista(p);

    while(!bacheca.finelista(p))
    {
        if(temp[0] != '*')
        {
            cout << i << " - " << temp << "\n\n";
            i++;
        }
        p=bacheca.succlista(p);
        if(!bacheca.finelista(p))
        {
            temp=bacheca.leggilista(p);
        }
    }
}

int Bacheca :: GetMessCancellabili()
{
    return messCancellabili;
}


bool Bacheca :: BachecaPiena()
{
    return messCancellabili == MAXMESSUTENTE;
}

bool Bacheca :: BachecaVuota()
{
    return bacheca.listavuota();
}

void Bacheca :: SalvaBacheca(ofstream &f)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    string temp;
    int i;

    p=bacheca.primolista();
    while(!bacheca.finelista(p))
    {
        temp=bacheca.leggilista(p);
        for(i=0; i < temp.length(); i++)
            if(temp[i]==' ')
                temp[i]='_';
        f.write(temp.c_str(), temp.length());
        f << '\n';
        p=bacheca.succlista(p);
    }
}

void Bacheca :: CaricaBacheca(ifstream &f)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    string temp, s;

    CancellaBacheca();
    p=bacheca.primolista();

    while(!f.eof())
    {
        f >> temp;
        if(temp.compare(s)!= 0)
        {
            s=temp;
            for(int i=0; i < temp.size(); i++)
                if(temp[i]=='_')
                    temp[i]=' ';
            bacheca.inslista(temp,p);//Modifica PMF
        }
    }
}

void Bacheca :: CancellaBacheca()
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    if(!BachecaVuota())
    {
        p=bacheca.primolista();
        while(!bacheca.finelista(p))
            bacheca.canclista(p);
    }
}

bool Bacheca :: EsisteMessaggio(string s)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    string temp;
    bool flag=false;

    p=bacheca.primolista();
    while(!bacheca.finelista(p) && flag == false)
    {
        temp=bacheca.leggilista(p);
        if(temp[0]=='*' && s[0]!='*')
            temp.erase(0,1);
        if(temp == s)
            flag=true;
        p=bacheca.succlista(p);
    }
    return flag;
}

void Bacheca :: NuovoMessaggio(string avviso)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    bool flag=false;
    int i=0;

    while(i < avviso.length() && flag == false)
    {
        if(avviso[i] != ' ')
            flag=true;
        i++;
    }
    if(flag)
    {
        if(avviso.length() > LUNG)
            avviso.erase(LUNG, avviso.length()-LUNG);
        if(avviso[0]=='*')
            avviso.erase(0, 1);
        while(avviso[0] == ' ')
            avviso.erase(0, 1);
        for(i=0; i < avviso.length(); i++)
            avviso[i]=tolower(avviso[i]);
        if(!EsisteMessaggio(avviso))
        {
            p=bacheca.primolista();
            bacheca.inslista(avviso,p);//Modifica PMF
            messCancellabili++;
        }
        else
            cout << "\n\nAVVISO GIA' PRESENTE!\n";
    }
    else
        cout << "\nNON PUOI INSERIRE MESSAGGI VUOTI\n";
}

void Bacheca :: NuovoMessaggioGioco(string avviso)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    if(!EsisteMessaggio(avviso))
    {
//<<<<<<< HEAD
        p=bacheca.preclista(bacheca.primolista());
      //  bacheca.inslista(avviso,p);//Modifica PMF
//=======
        p=bacheca.primolista();
        bacheca.inslista(avviso,p);//Modifica PMF
//>>>>>>> master
        cout << "\n\nNUOVO AVVISO IN BACHECA\n\n";
    }
}

void Bacheca :: CancellaMessaggio(int c)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    int i=1;

    if(c > 0 && c <= GetMessCancellabili())
    {
        p=bacheca.primolista();
        while(i < c && !bacheca.finelista(p))
        {
            i++;
            p=bacheca.succlista(p);
        }
        bacheca.canclista(p);
        messCancellabili--;
    }
    else
        cout << "\n\nINPUT NON VALIDO!";
}

void Bacheca ::CancellaMessaggioGioco(string avviso)
{

    //Lista_template_vettore <string,MAXMESSUTENTE> ::posizione p; // Modifica PMF(ufficio)
    //ListaDP<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili

    Lista<string>::posizione p;//MODIFICA D-R(D-R):Uniformità Strutture Intercambiabili
    bool flag=false;

    p=bacheca.primolista();
    while(!bacheca.finelista(p) && flag == false)
    {
        string temp=bacheca.leggilista(p);
        if(temp==avviso)
        {
            bacheca.canclista(p);
            flag=true;
        }
        p=bacheca.succlista(p);
    }
}




