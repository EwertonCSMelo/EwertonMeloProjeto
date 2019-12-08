#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ENCEC.h"
#define capMax 150

void acrescentarPalestrante(PESSOA *palestrante)
{

    lerNome(palestrante);

    lerCPF(palestrante);

    lerIdentidade(palestrante);

    lerRua(palestrante);

    lerNumero(palestrante);

    lerBairro(palestrante);

    lerCidade(palestrante);

    lerEstado(palestrante);

    lerPais(palestrante);

    lerCEP(palestrante);

    lerNumCelular(palestrante);

    lerEMAIL(palestrante);
}

