#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ENCEC.h"
#define capMax 150

void acrescentarCongressista(PESSOA *congressista)
{
    lerNome(congressista);

    lerCPF(congressista);

    lerIdentidade(congressista);

    lerRua(congressista);

    lerNumero(congressista);

    lerBairro(congressista);

    lerCidade(congressista);

    lerEstado(congressista);

    lerPais(congressista);

    lerCEP(congressista);

    lerNumCelular(congressista);

    lerEMAIL(congressista);

}
