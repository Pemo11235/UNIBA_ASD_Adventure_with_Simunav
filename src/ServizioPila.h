#ifndef _SERVIZIOPILA_H
#define _SERVIZIOPILA_H

#include <iostream>

#include "Pila.h"

template <class tipoElem>
void stampaPila(Pila<tipoElem> &p,std::ostream& o,char separatore)
{
	if(!p.pilavuota())
    {
		tipoElem elem = p.leggipila();
		o<< elem <<separatore;
		p.fuoripila();
		stampaPila(p,o,separatore);
		p.inpila(elem);
    }
}

template <class tipoElem>
void svuotaPila(Pila<tipoElem> &p)
{
	while(!p.pilavuota())
    {
        p.fuoripila();
    }
}
#endif // _SERVIZIOPILA_H
