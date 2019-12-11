#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include "ENCEC.h"


int main()
{
    system("color 9E");
    HideCursor();
    setlocale(LC_ALL,"");
    cabecalho();
    abrirArquivos();
    encec();
}

