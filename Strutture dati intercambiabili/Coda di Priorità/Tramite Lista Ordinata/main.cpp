/*
 Definizione del main per il test della struttura
 Autore: Matteo Luceri
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Servizi_Coda_Con_Priorita.h"
#include <stdlib.h>
#include <exception>
#include "Coda_Con_Priorita.h"
#include "Elemento_Coda_Con_Priorita.h"
using namespace std;

int main(){
	//CREO LA STRUTTURA
	Prioricoda<int> p;
	p.creaprioricoda();

	// INPUT
	cout << "TEST :\t\tCoda con priorita` tramite una lista ordinata.\nRICORDA:\tValore di priorita` minore indica priorita` maggiore !\n\nAcquisisco una coda con priorita` dal file 'input.txt'. ";
	system("pause");
	std::ifstream file("src\\input.txt", ios::in);
	inputPrioriCodaDaFile(p, file);

	//STAMPA VIDEO
	cout << "\nLa coda acquisita e` la seguente:\n";
	stampaPrioriCoda(p);

	int z = 0;
	while (z == 0 ) {


		cout << "\nQuali operazioni intendi effettuare?\n\t1) Inserisci elemento;\n\t2) Visualizza elemento con priorita` massima;\n\t3) Cancella elemento con priorita` massima;\n\t4) Verifica se la coda e` vuota;\n\t5) Verifica appartenenza di un elemento.\n\t6) Stampa la coda con priorita` su file 'output.txt'\n\t7) Esci\n\n";
		int x;
		cin>>x;
		switch (x)
		{
		case 1:
			// INSERIMENTO
				cout <<"Vuoi inserire un nuovo elemento nella coda con priorita`?[si = 1/ no = 2]\n\n";
				int r;
				cin >> r;
				cout << "\n\n";
				if (r == 1) {
					cout<< "Inserimento elemento:\n";
					Priorielem<int> nuovo ;
					int prio,elem;
					cout<< "\t- Inserisci priorita`:";
					cin>> prio;
					cout<< "\t- Inserisci informazione:";
					cin>> elem;
					nuovo.scrivipriorita(prio);
					nuovo.scrivielem(elem);

					p.inserisci(nuovo);

					cout << "\nLa coda aggiornata e` la seguente:\n";
					stampaPrioriCoda(p);
				} else if (r == 2) {
					cout << "Non verra' inserito nessun elemento.\n\n";
					cout << "\n\n";

				}
		break;
		case 2:
			cout<< "L'elemento con priorita` massima e`:"<<p.min();
			cout << "\nLa coda di riferimento e` la seguente:\n";
			stampaPrioriCoda(p);

		break;
		case 3: {
			// CANCELLA MIN
			int l = 0;
			while (!p.insiemevuoto() && l == 0){
				cout <<"Vuoi cancellare l'elemento con priorita` massima?[si = 1/ no = 2]\n\n";
				int s;
				cin >> s;
				cout << "\n\n";
				if (s == 1) {
					cout << "L'elemento"  << p.min() << " e' stato cancellato. \n\n";
					p.cancellamin();
					cout << "\nLa coda aggiornata e` la seguente:\n";
					stampaPrioriCoda(p);
				} else if (s == 2){
					cout << "Non verra' eliminato nessun elemento.\n\n";
					cout << "\n\n";
					l++;
				}
			}
		}
		break;
		case 4:
			cout<< "La coda e`: ";

			if (p.insiemevuoto()){
				cout<<"vuota";
			} else {
				cout<<"piena";
			}
		break;
		case 5: {
			Priorielem<int> nuovoa;
			int elem;
			bool app;
			cout<<"Inserisci l'elemento di cui cui si vuole verificare l'appartenenza:\n";
			cin >> elem;
			nuovoa.scrivielem(elem);
			app = p.appartiene(nuovoa);
			cout<< "L'elemento "<< elem;
			if (app == true) {
				cout<< " appartiene";
			} else {
				cout<< " non appartiene";
			}
			cout<< " alla coda con priorita`.\n\n";

			cout << "\nLa coda di riferimento e` la seguente:\n";
			stampaPrioriCoda(p);

		}
		break;
		case 6:
			cout <<"Vuoi stampare su file la coda con priorita`?[si = 1/ no = 2]\n\n";
			int q;
			cin >> q;
			cout << "\n\n";
			if (q == 1) {
				std::ofstream fileout("src\\output.txt", ios::out);
				cout<< "Stampa in corso. . .";
				outputPrioriCodaSuFile(p,fileout);

			}
		break;
		case 7:
			z++;
		break;
		default:
			z=0;
		}
	}




//system ("pause");
}
