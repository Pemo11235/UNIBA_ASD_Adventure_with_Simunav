/*
 Realizzazione: Dizionario con vettore ordinato
 Autore: Rosa Chiarappa
*/  

#ifndef _DIZIONARIOL_H
#define _DIZIONARIOL_H
#include <iostream>
#include "Entry.h"
#include <cstdlib>
#define MAX 101
using namespace std;

template <typename K, class E>// E=tipoelemento, K=tipochiave
class Dizionario 
{ 
typedef Entry<K, E> entry;

	public:

		Dizionario();
		~Dizionario();
		void crea(); 
		bool appartiene(const K&); 
		void inserisci(K, E); 
		E recupera(const K&); 
		void aggiorna(const K&, const E&); 
		void cancella(const K&); 
		
			//operatori di servizio
		unsigned int dimensione(); 
		bool vuoto(); 	
		E stampa(int &);
		
	private:

		entry* diz;
		int nelementi;

};

template<typename K, typename E>
Dizionario<K, E>::Dizionario() 
{
	crea();
}

template<typename K, typename E>
Dizionario<K, E>::~Dizionario() {}


template<typename K, typename E>
void Dizionario<K, E>::crea() 
{
	diz=new entry[MAX];
	nelementi=0;
}

template<typename K, typename E>
bool Dizionario<K, E>::appartiene(const K &chiave) 
{
	bool trovato=false;
	int p,u,med;
	
	p=0;
	u=nelementi-1;
	
	while(p<=u && !trovato)
	{
		med=(p+u)/2;
		
		if(diz[med].get_key()==chiave)
		{
			trovato=true;
		}
		else if(diz[med].get_key() < chiave)
		{
			p=med+1;
		}
		else
		{
			u=med-1;
		}
		
	}
	return trovato;
}

template<typename K, typename E>
void Dizionario<K, E>::inserisci(K chiave, E elemento) 
{	
	int i=nelementi;
	if(i==0)
	{
		diz[0].set_value(elemento);
		diz[0].set_key(chiave);
	}
	else
	{
		while(i>0 && diz[i-1].get_key() > chiave)
		{
			diz[i].set_value(diz[i-1].get_value());
			diz[i].set_key(diz[i-1].get_key());
			i--;
		}
		diz[i].set_value(elemento);
		diz[i].set_key(chiave);
	}
	nelementi++;
}

template<typename K, typename E>
void Dizionario<K, E>::cancella(const K &chiave) 
{
	bool trovato=false;
	if(nelementi>0)
	{
		for(int i=0; i<nelementi; i++)
		{
			if(diz[i].get_key()==chiave)
			{
				trovato=true;
			}
			
			if(trovato)
			{
				diz[i].set_key(diz[i+1].get_key());
				diz[i].set_value(diz[i+1].get_value());
			}
		}
		if(trovato)
		{
			nelementi--;
		}
	}
}


template<typename K, typename E>
E Dizionario<K, E>::recupera(const K &chiave) 
{
	int p,u,med;
	p=0;
	u=nelementi-1;
	
	while(p<=u)
	{
		med=(p+u)/2;
		
		if(diz[med].get_key()==chiave)
		{
			return diz[med].get_value();
		}
		else if(diz[med].get_key() < chiave)
		{
			p=med+1;
		}
		else
		{
			u=med-1;
		}
		
	}
}


template<typename K, typename E>
void Dizionario<K, E>::aggiorna(const K &chiave, const E &elemento) 
{
	bool trovato=false;
	int p,u,med;
	
	p=0;
	u=nelementi-1;
	
	while(p<=u && !trovato)
	{
		med=(p+u)/2;
		
		if(diz[med].get_key()==chiave)
		{
			trovato=true;
			diz[med].set_key(chiave);
			diz[med].set_value(elemento);
		}
		else if(diz[med].get_key() < chiave)
		{
			p=med+1;
		}
		else
		{
			u=med-1;
		}
		
	}
}

template<typename K, typename E>
unsigned int Dizionario<K, E>::dimensione() {
	return nelementi;
}

template<typename K, typename E>
bool Dizionario<K, E>::vuoto() {
	return (nelementi == 0);
}


template<typename K, typename E>
E Dizionario<K, E>::stampa(int &j){

		int i;
		for(i=0;i<=nelementi;i++){
			if (i==j){
		return diz[i].get_value();
	}
		}
}
	
#endif
