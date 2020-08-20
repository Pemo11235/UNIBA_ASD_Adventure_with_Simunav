#ifndef SERVIZIOINSIEME_H_INCLUDED
#define SERVIZIOINSIEME_H_INCLUDED

#include "Insieme.h"

/**
 * @brief Svuota un insieme.
 * @param[in] i L'insieme da svuotare.
 * @pre i deve essere un insieme valido.
 * @post i = {}.
 */
template <class TipoElem>
void svuotaInsieme(Insieme<TipoElem>& i);

/* ======= Implementation ======= */

template <class TipoElem>
void svuotaInsieme(Insieme<TipoElem>& i)
{
    Insieme<TipoElem> temp;
    // L'intersezione con un insieme vuoto è vuota
    i.intersezione(temp);
}

#endif // SERVIZIOINSIEME_H_INCLUDED
