/*
 * UfficioPostale.cpp
 *
 *  Created on: 21/giu/2016
 *      Author: Germano G
 */

#include "UfficioPostale.h"

UfficioPostale::UfficioPostale()
{
    invia_Richiesta_Pacco=false;
    invia_Richiesta_Suggerimento=false;
    ritirato_Pacco=false;
    ritirato_Suggerimento=false;
}

UfficioPostale::~UfficioPostale()
{
}

int UfficioPostale::randomFila()
{
    return(rand() %11);
}

void UfficioPostale::set_Pacco(bool b)
{
    invia_Richiesta_Pacco = b ;
}
void UfficioPostale::set_Suggerimento(bool c)
{
    invia_Richiesta_Suggerimento = c;
}

bool UfficioPostale::get_Pacco()
{
    return(invia_Richiesta_Pacco);
}
bool UfficioPostale::get_Suggerimento()
{
    return(invia_Richiesta_Suggerimento);
}

void UfficioPostale::set_ritiratoPacco(bool d)
{
    ritirato_Pacco=d;
}
void UfficioPostale::set_ritiratoSuggerimento(bool e)
{
    ritirato_Suggerimento=e;
}

bool UfficioPostale::get_ritiratoPacco()
{
    return(ritirato_Pacco);
}

bool UfficioPostale::get_ritiratoSuggerimento()
{
    return(ritirato_Suggerimento);
}


