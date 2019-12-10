#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "ENCEC.h"
#define tamNome 30

int main()
{
    char simbolo=178;
    int i,j,k;
    system("color 9E");
   // HideCursor();

        for(i=0; i<120; i++)
        {
            printf("%c",simbolo);
        }

        printf("\n");
        for(j=0; j<27; j++)
          {
            printf("%c%c\n",simbolo,simbolo);
            }

        for(i=0; i<120; i++)
        {
            printf("%c",simbolo);
        }


    system("pause");





    encec();
}
