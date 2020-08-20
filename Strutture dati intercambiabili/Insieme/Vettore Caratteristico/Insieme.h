/**
 * @file Insieme.h
 * Definizione della struttura dati "Insieme".
 * @note Definizione di Insieme per la realizzazione tramite vettore caratteristico.
 * @warning Per una limitazione del C++, i tipi di elemento
 * accettatto normalmente è l'intero. Per tutti i tipi di
 * elemento differenti è necessario definire (all'interno
 * della definizione del tipo) il cast a intero.
 * @author Sconosciuto, modificato da Andrea Esposito.
 * @date Anno Accademico 2018/19.
 */
#ifndef INSIEME_H_
#define INSIEME_H_

/**
 * @brief Insieme
 * Questa classe contiene tutti gli operatori tipici della struttura
 * dati "Insieme".
 * @author Sconosciuto, modificato da Andrea Esposito.
 */
template<class TipoElem>
class Insieme
{
public:
	Insieme();
	Insieme(const Insieme&);
	~Insieme();

    /**
     * @brief Crea un insieme vuoto.
     * @post Il nuovo insieme i è l'insieme vuoto (i={}).
     */
    void creainsieme();

    /**
	 * @brief Controlla se l'insieme è vuoto.
	 * @return true se l'insieme è vuoto, false altrimenti.
	 */
	bool insiemevuoto() const;

    /**
	 * @brief controlla se un elemento appartiene all'insieme.
	 * @param[in] e L'elemento da controllare
	 * @return true se l'elemento appartiene all'insieme, false altrimenti.
	 */
	bool appartiene(const TipoElem& e) const;

    /**
	 * @brief Inserisce un elemento nell'insieme.
	 * @param[in] e L'elemento da aggiungere
	 * @post L'elemento e è aggiunto all'insieme.
	 */
	void inserisci(const TipoElem& e);

	/**
	 * @brief Rimuove un elemento dall'insieme.
	 * @param[in] e L'elemento da rimuovere.
	 * @post L'elemento e è rimosso dall'insieme.
	 */
	void cancella(const TipoElem& e);

    /**
	 * @brief Unione (matematica) di due insiemi.
	 * @param[in] i Insieme da unire.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * iniziali e gli elementi dell'insieme i.
	 */
	void unione(const Insieme& i);

    /**
	 * @brief Intersezione (matematica) di due insiemi.
	 * @param[in] i Insieme da intersecare.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * presenti sia nell'insieme iniziale che in i.
	 */
	void intersezione(const Insieme& i);

    /**
	 * @brief Differenza (matematica) di due insiemi.
	 * @param[in] i Insieme da sottrarre.
	 * @pre i deve essere un insieme valido.
	 * @post L'insieme conterrè tutti e soli gli elementi
	 * iniziali che non appartengono anche a i.
	 */
	void differenza(const Insieme& i);
private:
    static constexpr int DIMINSIEME = 100;
	bool vettore[DIMINSIEME];
};

template<class TipoElem>
Insieme<TipoElem>::Insieme()
{
	creainsieme();
}

template <class TipoElem>
Insieme<TipoElem>::Insieme(const Insieme<TipoElem>& i)
{
	for(int el = 0; el < DIMINSIEME; el++)
		vettore[el] = i.vettore[el];
}

template<class TipoElem>
Insieme<TipoElem>::~Insieme() {}

template <class TipoElem>
void Insieme<TipoElem>::creainsieme()
{
	for(int i = 0; i < DIMINSIEME; i++)
		vettore[i] = false;
}

template<class TipoElem>
bool Insieme<TipoElem>::insiemevuoto() const
{
	bool foundElement = false;
    for(int i = 0; i < DIMINSIEME && !foundElement; i++)
        foundElement = vettore[i];
	
	return !foundElement;
}

template<class TipoElem>
bool Insieme<TipoElem>::appartiene(const TipoElem& e) const
{
	if(static_cast<int>(e) >= 1 && static_cast<int>(e) <= DIMINSIEME)
		return vettore[static_cast<int>(e) - 1];
	else
		return false;
}

template<class TipoElem> 
void Insieme<TipoElem>::inserisci(const TipoElem& e)
{
	if(!appartiene(e) && static_cast<int>(e) >= 1 && static_cast<int>(e) <= DIMINSIEME)
		vettore[static_cast<int>(e) - 1] = true;
}
template<class TipoElem> 
void Insieme<TipoElem>::cancella(const TipoElem& e)
{
	if(appartiene(e) && static_cast<int>(e) >= 1 && static_cast<int>(e) <= DIMINSIEME)
		vettore[static_cast<int>(e) - 1] = false;
}

template<class TipoElem> 
void Insieme<TipoElem>::unione(const Insieme<TipoElem>& i)
{
	for (int index = 0; index < DIMINSIEME; index++)
        vettore[index] = (vettore[index] || i.vettore[index]);
}

template<class TipoElem> 
void Insieme<TipoElem>::intersezione(const Insieme<TipoElem>& i)
{
	for(int index = 0; i < DIMINSIEME; index++)
        vettore[index] = (vettore[index] && i.vettore[index]);
}

template<class TipoElem>
void Insieme<TipoElem>::differenza(const Insieme<TipoElem>& i)
{
	for(int index = 0; index < DIMINSIEME; index++)
		vettore[index] = (vettore[index] && !i.vettore[index]);
}

#endif // INSIEME_H_
