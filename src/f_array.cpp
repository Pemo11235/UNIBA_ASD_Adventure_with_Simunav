#include "f_array.h"    //li ho creati per controllare l array degli oggetti

void svuota_array(int n[], int dim)
{
    for(int i = 0; i < dim; i++)
        n[i] = NULLV;
}

bool controllo_array(int n[], int dim)
{
    bool ris = true;
    for (int i = 0; i < dim && ris == true; i++)
        ris = (n[i] == NULLV);
    return ris;
}



