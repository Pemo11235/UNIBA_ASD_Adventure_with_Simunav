#ifndef ALBERONARIO_H
#define ALBERONARIO_H
#include <exception>
#include "BinAlbero.h"
/**
* Realizzazione dell'albero ennario attraverso l'albero binario.
* La memorizzazione dell'albero avviene  nel seguente modo:
*   1. il PRIMOFIGLIO sarà FIGLIO SINISTRO.
*   2. il SUCCFRATELLO sarà FIGLIO DESTRO.
*
* author: Regina Zaccaria.
*/
template <class tipoelem>
class Albero{

public:
    //DEFINIZIONE DI NODO
    typedef typename BinAlbero<tipoelem>::Nodo nodo;
    //DEFINIZIONE DI NODO NULLO
    static constexpr typename BinAlbero<tipoelem>::Nodo nil =BinAlbero<tipoelem>::nil;
    //COSTRUTTORE
    Albero();
    //COSTRUTTORE DI COPIA
    Albero(const Albero&);
    //DISTRUTTORE
    virtual ~Albero();
    //METODO CHE CREA ALBERONARIO
    void creaalbero();
    //METODO CHE RESTITUISCE VERO SE L'ALBERO È VUOTO, FALSO ALTRIMENTI
    bool alberovuoto() const;
    //METODO CHE INSERISCE UN NODO NULLO COME RADICE
    void insradice();
    //METODO CHE RESTITUISCE IL NODO DELLA RADICE
    nodo radice() const;
    //METODO CHE RESTITUISCE IL NODO PADRE DEL NODO PASSATO
    nodo padre(nodo);
    //METODO CHE RESTITUISCE VERO SE IL NODO PASSATO È FOGLIA (QUINDI NON HA FIGLI), FALSO ALTRIMENTI
    bool foglia(nodo) const;
    //METODO CHE RESTITUISCE IL NODO PRIMOFIGLIO DI UN NODO PASSATO
    nodo primofiglio(nodo) const;
    //METODO CHE RESTITUISCE VERO SE IL NODO PASSATO NON HA FRATELLI SUCCESSIVI, FALSO ALTRIMENTI
    bool ultimofratello(nodo) const;
    //METODO CHE RESTITUISCE IL NODO FRATELLO SUCCESSIVO DEL NODO PASSATO
    nodo succfratello(nodo)const;
    //METODO CHE INSERISCE LA RADICE, E TUTTI I SUOI DISCENDENTI, DELL'ALBERO PASSATO COME NODO PRIMOFIGLIO DEL NODO PASSATO
    void insprimosottoalbero(nodo, Albero&);
    //METODO CHE INSERISCE LA RADICE, E TUTTI I SUOI DISCENDENTI, DELL'ALBERO PASSATO COME UN NODO FRATELLO SUCCESSIVO DEL NODO PASSATO
    void inssottoalbero(nodo, Albero&);
    //METODO CHE PASSATO UN NODO CANCELLA LO STESSO E TUTTI I SUOI DISCENDENTI
    void cancsottoalbero(nodo);
    //METODO CHE SCRIVE L'ETICHETTA DI TIPO TIPOELEM ALL'INTERNO DEL NODO PASSATO
    void scrivinodo(nodo&, tipoelem);
    //METODO CHE RESTITUISCE L'ETICHETTA DEL NODO PASSATO
    tipoelem legginodo(nodo) const;

private:

    BinAlbero<tipoelem> tree;
    //METODO CHE COPIA UN ALBERO PASSATO PARTENDO DAL NODO SINISTRO
    void copia_albero_sx(const BinAlbero<tipoelem>& ,const nodo& ,nodo);
    //METODO CHE COPIA L'ALBERO PASSATO PARTENDO DAL NODO DESTRO
    void copia_albero_dx(const BinAlbero<tipoelem>& ,const nodo& ,nodo);
};


template <class tipoelem>
Albero<tipoelem>::Albero(){
    creaalbero();
}

template <class tipoelem>
Albero<tipoelem>::Albero(const Albero& a){
    if(!a.tree.binalberovuoto())
    {
        tree.insbinradice();
        nodo n = tree.binradice();
        nodo secondo_albero = a.tree.binradice();
        tree.scrivinodo(n, a.tree.legginodo(secondo_albero));

        if(a.tree.sinistrovuoto(a.tree.binradice()))
        {
            if(!a.tree.destrovuoto(a.tree.binradice()))
                    copia_albero_dx(a.tree,a.tree.figliodestro(a.tree.binradice()),tree.binradice());
        }
        else
            copia_albero_sx(a.tree,a.tree.figliosinistro(a.tree.binradice()),tree.binradice());
    }
}

template <class tipoelem>
Albero<tipoelem>::~Albero(){
    //RICHIAMA AUTOMATICAMENTE IL DISTRUTTORE
    //DELL'ALBERO BINARIO
}

template <class tipoelem>
void Albero<tipoelem>::creaalbero(){
    //RICHIAMA AUTOMATICAMENTE IL COSTRUTTORE
    //DELL'ALBERO BINARIO
}


template <class tipoelem>
bool Albero<tipoelem>::alberovuoto() const{
    return tree.binalberovuoto();
}

template <class tipoelem>
void Albero<tipoelem>::insradice(){
    tree.insbinradice();
}

template <class tipoelem>
typename Albero<tipoelem>::nodo Albero<tipoelem>::radice() const{
  return tree.binradice();
}

template <class tipoelem>
typename Albero<tipoelem>::nodo Albero<tipoelem>::padre(typename Albero<tipoelem>::nodo n){
    return tree.binpadre(n);
}

template <class tipoelem>
bool Albero<tipoelem>::foglia(typename Albero<tipoelem>::nodo n) const{
  if(tree.sinistrovuoto(n))
    return true;
  else
    return false;
}

template <class tipoelem>
typename Albero<tipoelem>::nodo Albero<tipoelem>::primofiglio(typename Albero<tipoelem>::nodo n) const{
    return tree.figliosinistro(n);
}

template <class tipoelem>
bool Albero<tipoelem>::ultimofratello(typename Albero<tipoelem>::nodo n) const{
    if(tree.destrovuoto(n))
        return true;
    else
        return false;
}

template <class tipoelem>
typename Albero<tipoelem>::nodo Albero<tipoelem>::succfratello(typename Albero<tipoelem>::nodo n)const{
    return tree.figliodestro(n);
}

template<class tipoelem>
void Albero<tipoelem>::copia_albero_sx(const BinAlbero<tipoelem>& other, const nodo& radice_sottoalbero, nodo nodo_padre)
{
	tree.insfigliosinistro(nodo_padre);
	nodo sx = tree.figliosinistro(nodo_padre);
	tree.scrivinodo(sx, other.legginodo(radice_sottoalbero));

	if(!other.sinistrovuoto(radice_sottoalbero))
		copia_albero_sx(other, other.figliosinistro(radice_sottoalbero), sx);
	if(!other.destrovuoto(radice_sottoalbero))
		copia_albero_dx(other, other.figliodestro(radice_sottoalbero), sx);
}

template <class tipoelem>
void Albero<tipoelem>::copia_albero_dx(const BinAlbero<tipoelem>& other, const nodo& radice_sottoalbero, nodo nodo_padre)
{
	tree.insfigliodestro(nodo_padre);
	nodo dx = tree.figliodestro(nodo_padre);
	tree.scrivinodo(dx, other.legginodo(radice_sottoalbero));

	if(!other.sinistrovuoto(radice_sottoalbero))
		copia_albero_sx(other, other.figliosinistro(radice_sottoalbero), dx);
	if(!other.destrovuoto(radice_sottoalbero))
		copia_albero_dx(other, other.figliodestro(radice_sottoalbero), dx);
}

template <class tipoelem>
void Albero<tipoelem>::insprimosottoalbero(typename Albero<tipoelem>::nodo n, Albero& a){
   nodo temp;
       if(tree.sinistrovuoto(n)){
        copia_albero_sx(a.tree,a.tree.binradice(),n);
       }
       else{
        Albero<tipoelem> T;
        T.insradice();
        temp=T.radice();
        T.scrivinodo(temp,tree.legginodo(tree.figliosinistro(n)));

        if(tree.sinistrovuoto(tree.figliosinistro(n))){
            if(!tree.destrovuoto(tree.figliosinistro(n))){
                    copia_albero_dx(tree,tree.figliodestro(tree.figliosinistro(n)),temp);
            }
        }
        else{
            copia_albero_sx(tree,tree.figliosinistro(tree.figliosinistro(n)),temp);
        }

        tree.cancsottobinalbero(tree.figliosinistro(n));

        copia_albero_sx(a.tree,a.tree.binradice(),n);
        temp=tree.figliosinistro(n);
        copia_albero_dx(T.tree,T.radice(),temp);
       }
}


template <class tipoelem>
void Albero<tipoelem>::inssottoalbero(typename Albero<tipoelem>::nodo n, Albero& a){
    /* L'albero è ottenuto aggiungendo il sottoalbero a di radice r dove r diventa il fratello successivo
    di n. n non è la radice*/

     nodo temp;
    if(n!=tree.binradice()){
            if(tree.destrovuoto(n)){
                copia_albero_dx(a.tree,a.radice(),n);
            }
            else{
                Albero<tipoelem> T;
                T.insradice();

                temp=T.radice();
                T.scrivinodo(temp,tree.legginodo(tree.figliodestro(n)));

                if(tree.sinistrovuoto(tree.figliodestro(n))){
                        if(!tree.destrovuoto(tree.figliodestro(n))){
                            copia_albero_dx(tree,tree.figliodestro(tree.figliodestro(n)),temp);
                        }
                }
                else{
                    copia_albero_sx(tree,tree.figliosinistro(tree.figliodestro(n)),temp);
                }

                cancsottoalbero(tree.figliodestro(n));

                copia_albero_dx(a.tree,a.radice(),n);
                temp=tree.figliodestro(n);
                copia_albero_dx(T.tree,T.radice(),temp);

            }
    }

}

template <class tipoelem>
void Albero<tipoelem>::cancsottoalbero(typename Albero<tipoelem>::nodo n){
    /* L'albero è ottenuto togliendo il sottoalbero di radice n e tutti i suoi discendenti*/
    tree.cancsottobinalbero(n);
}

template <class tipoelem>
void Albero<tipoelem>::scrivinodo(typename Albero<tipoelem>::nodo& n, tipoelem elem){
    tree.scrivinodo(n,elem);
}

template <class tipoelem>
tipoelem Albero<tipoelem>::legginodo(typename Albero<tipoelem>::nodo n) const{
    return tree.legginodo(n);
}

#endif // ALBERONARIO_H
