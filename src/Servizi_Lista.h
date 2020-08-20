#ifndef SERVIZI_LISTA_H
#define SERVIZI_LISTA_H

#include <cstdlib>
#include<iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node * precedente;
    Node * successivo;
};

template <class T>

class Servizi_Lista
{
protected:

    Node<T> * pinizio, * pfine;

public:

    Servizi_Lista()
    {
        this->pinizio = NULL;
        this->pfine = NULL;
    }

    ~Servizi_Lista()
    {
        Node<T> * temp = this->pinizio;
        while( temp != NULL )
        {
            this->pinizio = temp->successivo;
            delete temp;
            temp = this->pinizio;
        }
    }


    void insListaTesta( T data )
    {
        Node<T> * n = new Node<T>();
        n->data = data;
        n->successivo = NULL;
        n->precedente = NULL;

        if( this->pinizio == NULL )
        {
            this->pinizio = this->pfine = n;
        }
        else
        {
            (this->pinizio)->precedente = n;
            n->successivo = this->pinizio;
            this->pinizio = n;
        }
    }

    void insListaCoda( T data )
    {
        Node<T> * n = new Node<T>();
        n->data = data;
        n->successivo = NULL;
        n->precedente = NULL;
        if( this->pinizio == NULL )
        {

            this->pinizio = this->pfine = n;
        }
        else
        {
            n->precedente = this->pfine;
            (this->pfine)->successivo = n;
            this->pfine = n;
        }
    }

    T get( int index )
    {
        int counter;
        Node<T> * iterator = this->pinizio;
        for( counter = 0; iterator != NULL; counter++ )
        {
            if( counter == index )
                return iterator->data;
            iterator = iterator->successivo;
        }
        T boh;
        return boh;
    }

    bool cancLista( int index )
    {
        Node<T> * iterator = this->pinizio;
        for( int i = 0; iterator != NULL; i++ )
        {
            if( i == index )
            {
                Node<T> * temp;
                if( iterator == this->pinizio && iterator == this->pfine )
                {
                    this->pinizio = this->pfine = NULL;
                }
                else if( iterator == this->pinizio )
                {
                    temp = iterator->successivo;
                    temp->precedente = NULL;
                    this->pinizio = iterator->successivo;
                }
                else if( iterator == this->pfine )
                {
                    temp = iterator->precedente;
                    temp->successivo = NULL;
                    this->pfine = iterator->precedente;
                }
                else
                {
                    temp = iterator->precedente;
                    temp->successivo = iterator->successivo;
                    temp = iterator->successivo;
                    temp->precedente = iterator->precedente;
                }
                delete iterator;
                return true;
            }
            iterator = iterator->successivo;
        }
        return false;
    }

    int count()
    {
        int counter;
        Node<T> * iterator = this->pinizio;
        for( counter = 0; iterator != NULL; counter++ )
            iterator = iterator->successivo;
        return counter;
    }



};

#endif
