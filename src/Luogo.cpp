#include "Luogo.h"

Luogo::Luogo() //costruttore generico
{
    id=0;
    nome="Non selezionato";
    direzioni="000000000000";
}

void Luogo::scriviID(unsigned int i)
{
    id=i;
}

unsigned int Luogo::leggiID() const
{
    return(id);
}

void Luogo::scriviluogo(string s)
{
    nome=s;
}

string Luogo::leggiluogo() const
{
    return(nome);
}

//Inizio modifica Angelo Petronelli
void Luogo::scrividirezioni(string d)
{
    direzioni=d;
}

string Luogo::leggidirezioni() const
{
    return(direzioni);
}
// fine modifica

void Luogo::insvia(Vialuogo v)
{
    Lista<Vialuogo>::posizione pos=vie.primolista();
    vie.inslista(v,pos);
}

Lista<Vialuogo> Luogo::leggivie() const
{
    return(vie);
}

//sovraccarichi
void Luogo::operator =(Luogo l) //assegnamento
{
    scriviID(l.leggiID());
    scriviluogo(l.leggiluogo());
    // Vaira - Assegnamento oggetto DescData all'oggetto Luogo corrente
    setDescData(l.getDescData());
    // Modifica Angelo Petronelli
    scrividirezioni(l.leggidirezioni());
    // fine modifica
    copiaLista(vie,l.leggivie());
}

bool Luogo::operator ==(Luogo l) //uguaglianza
{
    return (leggiID()==l.leggiID() && leggiluogo()==l.leggiluogo() && leggidirezioni()==l.leggidirezioni());
}

bool Luogo::operator!=(const Luogo& l)
{
    return (leggiID()!=l.leggiID() || leggiluogo()!=l.leggiluogo() || leggidirezioni()!=l.leggidirezioni());
}

//INIZIO modifiche DELLA FOLGORE GRAZIA
bool Luogo::leggi_predefinito() {
    if (id>=45)
        return true;
    else
        return false;
}
//FINE modifiche DELLA FOLGORE GRAZIA

// Vaira [Donati] - Reimplementazione dei metodi per le descrizioni dinamiche

string Luogo::getDescrizione()
{
    return descrizioni->getDescription();
}

void Luogo::setDescData(DescData* descData)
{
    descrizioni = descData;
}

DescData* Luogo::getDescData() const
{
    return descrizioni;
}
// END Vaira [Donati]

//MODIFICA D-R(Colturi):Luoghi a Pagamento
Lista<string> Luogo::Carica_descLuoghiPag()
{
    Lista<string> desc;
    ifstream file;

    file.open("desc_luoghi_pag.txt");
    if(file.is_open())
    {
        string buffer;
        int idLuogo=0, numRighe=0;
        while(getline(file, buffer))
        {
            if(numRighe==0)
            {
                stringstream ss(buffer);
                ss >> idLuogo >> numRighe;
            }
            else
            {
                if(idLuogo == id)
                {
                    Lista<string>::posizione pos = desc.primolista();
                    desc.inslista(buffer,pos); // inserimento delle descrizioni lette
                }
                numRighe--;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Errore nell'apertura del file!" << endl;
    }
    return desc;
}

//MODIFICA D-R(Colturi):Luoghi a Pagamento
void Luogo::Leggi_descLuoghiPag(Lista<string> desc,int luogo_attuale)
{
    Lista<string>::posizione posAtt= desc.primolista();

    if(desc.listavuota())
    {
        cout << " Nessun evento in programma." << endl;
        cout << endl;
    }
    if(desc.finelista(posAtt))
    {
        posAtt = desc.primolista();
    }

    Lista<string>::posizione pos = desc.primolista();
    bool ok = false;

    while(!desc.finelista(pos) && !ok)//controllo se non è¨ fine lista e se la posizione  è valida
    {
        if(pos==posAtt)
        {
            ok = true;
        }
        pos = desc.succlista(pos);
    }

    if(!ok)//altro controllo nell' eventualità  che falliscano le prime condizioni
    {
        posAtt = desc.primolista();
    }

    string txt = desc.leggilista(posAtt);
    posAtt = desc.succlista(posAtt);
    leggi_str(txt,luogo_attuale);




}
//MODIFICA D-R(Colturi):Luoghi a Pagamento
void Luogo::leggi_str(string stampa, int luogo_attuale)
{
    int pos1, pos2, pos3, pos4,pos5;

    pos1 = stampa.find("*");
    cout << stampa.substr(0,pos1-1) << endl;

    pos2 = stampa.find("/");
    cout << stampa.substr(pos1+1,pos2-pos1-1) << endl;

    pos3 = stampa.find("+");
    cout << stampa.substr(pos2+1,pos3-pos2-1) << endl;

    pos4 = stampa.find("%");
    cout << stampa.substr(pos3+1,pos4-pos3-1) << endl;

    if(luogo_attuale == 16 || luogo_attuale ==17)
    {
        pos5 = stampa.find("&");
        cout << stampa.substr(pos4+1,pos5-pos4-1) << endl;

        cout << stampa.substr(pos5+1) << endl;
    }

}
