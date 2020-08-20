//
// Created by Frast on 12/12/2017.
//
#include <iostream>

#pragma once
#define NMAX 1024

template<class T>
class Coda {
public:


    Coda();

    ~Coda();

    void creacoda();

    bool codavuota();

    void fuoricoda();

    T leggicoda();

    void incoda(T);

private:
    typedef T tipoelem;
    typedef int posizione;
    tipoelem vett[NMAX];
    int testa;
    int fondo;
};

template<class tipoelem>
Coda<tipoelem>::Coda() {
    creacoda();
}

template<class tipoelem>
Coda<tipoelem>::~Coda() {

}

template<class tipoelem>
void Coda<tipoelem>::creacoda() {
    fondo = 0;
    testa = 0;
}

template<class tipoelem>
bool Coda<tipoelem>::codavuota() {
    return (fondo == 0);
}

template<class tipoelem>
void Coda<tipoelem>::fuoricoda() {
    if (!codavuota()) {
        int i;
        for (i = testa; i < fondo - 1; i++) {
            vett[i] = vett[i + 1];
        }
        fondo--;
    } else {
        std::cout << "La Coda è vuota" << std::endl;
    }
}

template<class tipoelem>
tipoelem Coda<tipoelem>::leggicoda() {
    return vett[testa];
}

template<class tipoelem>
void Coda<tipoelem>::incoda(tipoelem a) {
    if (fondo < NMAX) {
        vett[fondo] = a;
        fondo++;
    }

}
