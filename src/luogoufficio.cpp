#include "luogoufficio.h"


luogoufficio::luogoufficio(string desc,string dir)
{
    leggiluogo() = desc;
    leggidirezioni() = dir;
}
luogoufficio::luogoufficio()
{
    //leggiluogo = l.leggiluogo();
    //leggidirezioni= l.leggidirezioni();
}
luogoufficio::~luogoufficio() {};

/*void luogoufficio::crea_documento(){
    int num_casuale;
    //srand((unsigned)time(NULL));
    num_casuale=rand()% 12;
    int i;
    Documenti doc_creat;
    for (i=1; i<doc_creat.get_n_documenti(); i++){
        if (doc_creat.get_codice_documento(i)== i)
        {
            //doc_creat.inserisci()
        }
    }
}

*/
