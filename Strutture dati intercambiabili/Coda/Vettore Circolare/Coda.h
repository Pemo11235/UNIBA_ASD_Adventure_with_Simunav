//
// Created by Gianluca on 20/10/2018.
//

#ifndef CODA_CIRCOLARE_CODA_H
#define CODA_CIRCOLARE_CODA_H
#define NMAX 1024
#include <iostream>

using namespace std;

template<class T>
class Coda {
public:


    Coda();
    ~Coda();
    void creacoda();
    bool codavuota();
    T leggicoda();
    void incoda(T);
    void fuoricoda();
private:
    typedef T tipoelem;
    T elementi[NMAX];
    int testa;
    int lunghezza;
};

template<class T>
Coda<T>::Coda() {
    creacoda();
}

template<class T>
Coda<T>::~Coda() {}

template<class T>
void Coda<T>::creacoda() {
    testa = 0;
    lunghezza = 0;
}

template<class T>
bool Coda<T>::codavuota() {
    return (lunghezza == 0);
}

template<class T>
T
Coda<T>::leggicoda() {
    return elementi[testa];
}

template<class T>
void Coda<T>::incoda(tipoelem e) {
    if (lunghezza < NMAX) {
        elementi[(testa + lunghezza) % NMAX] = e;
        lunghezza++;
    } else {
        cout << "\n \n \n ERRORE! La coda e' piena! " << "\n \n \n";
    }
}

template<class T>
void Coda<T>::fuoricoda() {
    testa = (testa + 1) % NMAX;
    lunghezza--;
}


#endif //CODA_CIRCOLARE_CODA_H
