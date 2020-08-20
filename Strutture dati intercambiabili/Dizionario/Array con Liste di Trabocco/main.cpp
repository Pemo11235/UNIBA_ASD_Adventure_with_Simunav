/*
 @ main.cpp
 Autore: Rosa Chiarappa
*/

#include <iostream>
#include <stdlib.h> 
#include "Dizionario.h"

int main(){
	Dizionario<int,int> Dizionarioprova;
	Dizionarioprova.crea();

	cout<<"--------------Inserimento-----------------\n\n";
	cout <<"Inserisci tre valori:\t";
	int i;
	int j;
	int d;
	cin >> i;
	cin >> j;
	cin >> d;
	cout <<"Inserisci tre chiavi:\t";
	int k;
	int l;	
	int m;
	cin >> k;
	cin >> l;
	cin >> m;
	Dizionarioprova.inserisci(k,i);
	Dizionarioprova.inserisci(l,j);
	Dizionarioprova.inserisci(m,d);
	cout <<"\n\n";

	
		cout<<"--------------Aggiorna-----------------\n\n";
		cout << "Quale chiave vuoi aggiornare?\n Le chavi inserite sono: \n 1) " << k << " \n 2) " << l << " \n 3) " << m << " \n\n";
		int agg;
		cin >> agg;
		cout << "\n\n";
		cout << "Che valore vuoi inserire? \n\n";
		int agg2;
		cin >> agg2;
		cout <<"\n\n";
		
	    Dizionarioprova.aggiorna(agg, agg2);
		cout << "Aggiornato! Adesso il tuo dizionario e': \n\n";
		int b; 
		for (b=1; b<4; b++){ 
		cout <<	Dizionarioprova.recupera(b);
}
	
	cout << "--------------Rimozione-----------------\n\n";
	
	while (!Dizionarioprova.vuoto()){	
	cout <<"Vuoi cancellare un elemento?[si = 1/ no = 2]\n\n";
	int s;
	cin >> s;
	
	if (s == 1){
		cout << "Quale chiave vuoi cancellare?\n Le chavi inserite sono: \n 1) " << k << " \n 2) " << l << " \n 3) " << m << " \n\n";
		int canc;
		cin >> canc;
	Dizionarioprova.cancella(canc);
	cout << "Il valore con la chiave "  << canc << " e' stato cancellato. \n\n";
	cout << "Adesso il tuo dizionario e': \n\n";
		int n;
		for (n=4; n=7; n++){
	cout <<	Dizionarioprova.recupera(n);
	}
}
	else if (s == 2){
		cout << "Non verra' eliminato nessun elemento.\n\n";
		cout << "\n\n";
		cout << "Vuoi uscire dal programma? [si = 1/ no = 2]\n";
		int a;
		cin >> a;
		if (a == 1){
		  exit(EXIT_SUCCESS);
	}
		else {
		cout << "\n\n";
		continue;
	}
	}
}

cout << "Il dizionario è vuoto.\n\n";

system ("pause");


}

