#include <iostream>
#include <stdlib.h> 
#include "Coda.h"

using namespace std;

int main(){
	
		Coda<int> Codaprova;
		
		Codaprova.creacoda();
		int a, b, c;
		
	cout << "--------------Inserimento-----------------\n\n";
		cout << "Inserisci 3 elementi da mettere in coda: ";
		cin >> a;
		cin >> b;
		cin >> c;
		Codaprova.incoda(a);
		Codaprova.incoda(b);
		Codaprova.incoda(c);
		
	cout << "--------------Stampa-----------------\n\n";
		cout << Codaprova.leggicoda(); 
		cout << "\n\n";
	
	
	cout << "--------------Rimozione-----------------\n\n";
	   while (!Codaprova.codavuota()){	
	   
	    cout << "Vuoi rimuovere il primo elemento? [si = 1 / no = 2]\n\n";
		int i;
		cin >> i;
	
	if (i == 1) {
		 Codaprova.fuoricoda();
		 cout << "Adesso l'elemento in testa e':\t";
		 cout << Codaprova.leggicoda();
	 	 cout << "\n\n";
    }
	else if (i == 2){
		cout << "Non verra' eliminato nessun elemento.\n";
		cout << "Il primo elemento e':\t ";
		cout << Codaprova.leggicoda();
		cout << "\n\n";
		cout << "Vuoi sucire dal programma? [si = 1/ no =2]\n";
		int a;
		cin >> a;
		if (a == 1)
		   exit(EXIT_SUCCESS);
		else 
		cout << "\n\n";
		continue;
	}
}

cout << "Adesso la coda e' vuota.\n\n\n";

		system ("pause");
}
	
