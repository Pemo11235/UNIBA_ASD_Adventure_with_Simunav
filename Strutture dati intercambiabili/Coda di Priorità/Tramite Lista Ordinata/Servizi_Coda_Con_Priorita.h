/*
 Definizione dei servizi per la struttura Coda Con Priorità
 Autore: 	Sconosciuto
 Modificata da: Matteo Luceri
*/


#ifndef SERVIZI_CODA_CON_PRIORITA_H_
#define SERVIZI_CODA_CON_PRIORITA_H_

#include <string>
#include <iostream>
#include <fstream>
#include <exception>

#include "Coda_Con_Priorita.h"

template <class T>
void stampaPrioriCoda(Prioricoda<T>&);

template <class T>
void inputPrioriCodaDaFile(Prioricoda<T>&, std::ifstream&);

template <class T>
void outputPrioriCodaSuFile(Prioricoda<T>&, std::ofstream&);

// Implementazione

template <class T>
void stampaPrioriCoda(Prioricoda<T>& p)
{
	if(!p.insiemevuoto())
	{
		typename Prioricoda<T>::tipoelem el = p.min();
		std::cout << el.leggielem() << " - con priorita: " << el.leggipriorita() << std::endl;
		p.cancellamin();

		stampaPrioriCoda(p);

		p.inserisci(el);
	}
}

template <class T>
void inputPrioriCodaDaFile(Prioricoda<T>& p, std::ifstream& file)
{
	if(!file.fail())
	{
		if(file.peek() != ifstream::traits_type::eof())
			while(!file.eof())
			{
				T content;
				string s;
				getline(file, s,',');
				file >> content;
				typename Prioricoda<T>::tipoelem::priorita priori = (typename Prioricoda<T>::tipoelem::priorita) atof(s.c_str());
				p.inserisci(typename Prioricoda<T>::tipoelem(priori, content));
			}
	}
	else
		throw std::runtime_error("Errore di apertura del file");
}

template <class T>
void outputPrioriCodaSuFile(Prioricoda<T>& p, std::ofstream& file)
{
	if(!file.fail())
	{
		if(!p.insiemevuoto())
		{
			typename Prioricoda<T>::tipoelem el = p.min();
			file << el.leggipriorita() << "," << el.leggielem() << std::endl;
			p.cancellamin();

			outputPrioriCodaSuFile(p, file);

			p.inserisci(el);
		}
	}
	else
		throw std::runtime_error("Errore di apertura del file");
}

#endif /* SERVIZI_CODA_CON_PRIORITA_H_ */
