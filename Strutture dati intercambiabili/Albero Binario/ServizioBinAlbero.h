#ifndef SERVIZIOALBEROBIN_H
#define SERVIZIOALBEROBIN_H

#include <sstream>
#include <exception>
#include <fstream>

#include "BinAlbero.h"
#include "Coda.h"
#include "Pila.h"

template <class T>
void visita(BinAlbero<T>&);

template <class T>
void visitaPreordine(BinAlbero<T>&, typename BinAlbero<T>::Nodo, int);

template <class T>
void visitaPostordine(BinAlbero<T>&, typename BinAlbero<T>::Nodo, int);

template <class T>
void visitaSimmetrica(BinAlbero<T>&, typename BinAlbero<T>::Nodo,int);

template <class T>
void visitaAmpiezza(BinAlbero<T>&, typename BinAlbero<T>::Nodo);

/**
 * @pre L'albero binario deve essere vuoto
 */
template <class T>
void inputAlberoBinDaFile(BinAlbero<T>&, std::ifstream&);

template <class T>
void outputAlberoBinSuFile(BinAlbero<T>&, std::ofstream&);

// Implementazione

template <class T>
void visita(BinAlbero<T>& t)
{
    if(!t.binAlberoVuoto())
        visitaPreordine(t, t.radicebinalbero(), 0);
    else
        std::cout << "Albero vuoto\n";
}

template <class T>
void visitaPreordine(BinAlbero<T>& t, typename BinAlbero<T>::Nodo n, int numberOfTabs)
{
    for(int i = 0; i < numberOfTabs; i++)
        std::cout << "\t";
    std::cout << "[";
    if (n != BinAlbero<T>::NODO_NULLO)
    {
        std::cout << t.legginodo(n) << "\n"; // esame del nodo
        visitaPreordine(t, t.figliosinistro(n), numberOfTabs + 1);
        visitaPreordine(t, t.figliodestro(n), numberOfTabs + 1);
        for(int i = 0; i < numberOfTabs; i++)
            std::cout << "\t";
    }
    std::cout << "]\n";
}

template <class T>
void visitaPostordine(BinAlbero<T>& t, typename BinAlbero<T>::Nodo n, int numberOfTabs)
{
    for(int i = 0; i < numberOfTabs; i++)
        std::cout << "\t";
    std::cout << "[";
    if (n != BinAlbero<T>::NODO_NULLO)
    {
        visitaPostordine(t, t.figliosinistro(n), numberOfTabs + 1);
        visitaPostordine(t, t.figliodestro(n), numberOfTabs + 1);
        std::cout << t.legginodo(n) << " "; // esame del nodo
        for(int i = 0; i < numberOfTabs; i++)
            std::cout << "\t";
    }
    std::cout << "]\n";
}

template <class T>
void visitaSimmetrica(BinAlbero<T>& t, typename BinAlbero<T>::Nodo n, int numberOfTabs)
{
    for(int i = 0; i < numberOfTabs; i++)
        std::cout << "\t";
    std::cout << "[";
    if (n != BinAlbero<T>::NODO_NULLO)
    {
        visitaSimmetrica(t, t.figliosinistro(n), numberOfTabs + 1);
        std::cout << t.legginodo(n) << " "; // esame del nodo
        visitaSimmetrica(t, t.figliodestro(n), numberOfTabs + 1);
        for(int i = 0; i < numberOfTabs; i++)
            std::cout << "\t";
    }
    std::cout << "]\n";
}

template <class T>
void visitaAmpiezza(BinAlbero<T>& t, typename BinAlbero<T>::Nodo n)
{
    if (n!=BinAlbero<T>::NODO_NULLO)
    {
        Coda<typename BinAlbero<T>::Nodo> s;
        s.incoda(n);
        while (!s.codavuota())
        {
            typename BinAlbero<T>::Nodo nn=s.leggicoda(); // visito un nodo ...
            std::cout << t.legginodo(nn) << " ";
            s.fuoricoda();
            if (!t.sinistrovuoto(nn))
                s.incoda(t.figliosinistro(nn)); // ... e accodo i figli
            if (!t.destrovuoto(nn))
                s.incoda(t.figliodestro(nn));
        }
    }
}

/**
 * @pre L'albero binario deve essere vuoto
 */
template <class T>
void inputAlberoBinDaFile(BinAlbero<T>& t, std::ifstream& file)
{
	if(t.binAlberoVuoto())
	{
		if(!file.fail())
		{
			T content;
			int riga = 0;
			Coda<typename BinAlbero<T>::Nodo> c;
			if(file.peek() != std::ifstream::traits_type::eof())
			{
				std::string s;
				while(getline(file, s))
				{
					std::stringstream ss(s);
					++riga;
					if(s != "")
						ss >> content;

					if(riga == 1)
					{
						t.insbinradice();
						t.scriviNodo(content, t.radicebinalbero());
						c.incoda(t.radicebinalbero());
					}
					else
					{
						typename BinAlbero<T>::Nodo genitore = c.leggicoda();

						if(riga % 2 == 0)
						{
							if(s != "")
							{
								if(genitore != BinAlbero<T>::NODO_NULLO)
								{
									t.insfigliosinistro(genitore);
									t.scriviNodo(content, t.figliosinistro(genitore));
									c.incoda(t.figliosinistro(genitore));
								}
							}
							else
								c.incoda(BinAlbero<T>::NODO_NULLO);
						}
						else
						{
							if(s != "")
							{
								if(genitore != BinAlbero<T>::NODO_NULLO)
								{
									t.insfigliodestro(genitore);
									t.scriviNodo(content, t.figliodestro(genitore));
									c.incoda(t.figliodestro(genitore));
								}
							}
							else
								c.incoda(BinAlbero<T>::NODO_NULLO);

							c.fuoricoda();
						}

					}

				}
			}
		}
		else
			throw std::runtime_error("Errore di apertura del file");
	}
	else
		throw std::invalid_argument("Albero non vuoto");
}

template <class T>
void outputAlberoBinSuFile(BinAlbero<T>& t, std::ofstream& file)
{
	if(!file.fail())
	{
		if(!t.binAlberoVuoto())
		{
			std::stringstream ss;

			int rigaFile = 0;

			struct coppiaNodoRiga
			{
				typename BinAlbero<T>::Nodo nodo;
				int rigaFileTarget;
			};

			Coda<int> codaIndici;
			Coda<coppiaNodoRiga> codaNodiRighe;

			codaNodiRighe.incoda({t.radicebinalbero(), 1});

			while(!codaNodiRighe.codavuota())
			{
				++rigaFile;

				typename BinAlbero<T>::Nodo nodoCorrente = codaNodiRighe.leggicoda().nodo;

				while(rigaFile != codaNodiRighe.leggicoda().rigaFileTarget)
				{
					ss << std::endl;
					++rigaFile;
				}

				if(nodoCorrente != BinAlbero<T>::NODO_NULLO)
				{
					if(!t.sinistrovuoto(nodoCorrente))
						codaNodiRighe.incoda({t.figliosinistro(nodoCorrente), rigaFile * 2});
					else
						codaNodiRighe.incoda({BinAlbero<T>::NODO_NULLO, rigaFile * 2});

					if(!t.destrovuoto(nodoCorrente))
						codaNodiRighe.incoda({t.figliodestro(nodoCorrente), rigaFile * 2 + 1});
					else
						codaNodiRighe.incoda({BinAlbero<T>::NODO_NULLO, rigaFile * 2 + 1});
				}

				if(nodoCorrente != BinAlbero<T>::NODO_NULLO)
					ss << t.legginodo(nodoCorrente);
				ss << std::endl;

				codaNodiRighe.fuoricoda();
			}

			//Rimozione delle righe vuote alla fine della stringa generata
			std::string str = ss.str();
			str.erase(str.find_last_not_of("\n") + 1);

			file << str;
		}
	}
	else
		throw std::runtime_error("Errore di apertura del file");
}

#endif // SERVIZIOALBEROBIN_H
