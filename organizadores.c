#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ENCEC.h"
#define capMax 150

void acrescentarOrganizador(PESSOA *organizador)
{
    lerNome(organizador);

    lerCPF(organizador);

    lerIdentidade(organizador);

    lerRua(organizador);

    lerNumero(organizador);

    lerBairro(organizador);

    lerCidade(organizador);

    lerEstado(organizador);

    lerPais(organizador);

    lerCEP(organizador);

    lerNumCelular(organizador);

    lerEMAIL(organizador);
}
