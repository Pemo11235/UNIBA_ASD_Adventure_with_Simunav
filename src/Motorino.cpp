/* METODO DELLA CLASSE MOTORINO */

#include "Motorino.h"

//Motorino::Motorino(string n, int c, int l){
//
//     Veicolo::set_numero_ruote(2);
//     Veicolo::set_indice_di_consumo(5);
//     Veicolo::set_nome ( n);
//     Veicolo::set_codice (c);
//     Veicolo::set_luogo (l);
//     Veicolo::set_livello_benzina(0); //inizializzo il livello benzina a 0
//}

Motorino::Motorino()
{
    Veicolo::set_indice_di_consumo(2);
    Veicolo::set_livello_benzina(0);
}


//int Motorino::get_luogo(){
//    return Oggetto::get_luogo();
//}

void Motorino::pieno_benzina()
{
    Veicolo::set_livello_benzina(20);
}
