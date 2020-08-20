#include "Appunto.h"

Appunto::Appunto()
{}
void Appunto::Scrivi(string codice)
{
    char FILE_NAME[DIM_MAX];
    strcpy(FILE_NAME,codice.c_str()); /*converte una stringa in stile c++ in una in stile c */
    nota = fopen(FILE_NAME,"w+");
    cout<<"Inserisci testo ,per terminare la scrittura digita il carattere * e il ritorno a capo"<<endl;
    char ch;
    ch = getchar();
    while(ch!= '*' && ch != feof(nota))
    {
        fputc(ch,nota);
        ch = getchar();
    }
    fclose(nota);
}

void Appunto::Leggi(string codice)
{
    char FILE_NAME[DIM_MAX];
    strcpy(FILE_NAME,codice.c_str());
    nota = fopen(FILE_NAME,"r");
    while (!feof(nota))
    {
        char Ch = getc(nota);
        cout<<Ch;
    }
    cout<<endl;
    fclose(nota); // chiusura del file
}
void Appunto::Cancella(string codice)
{
    char FILE_NAME[DIM_MAX];
    strcpy(FILE_NAME,codice.c_str());
    remove(FILE_NAME);
}
