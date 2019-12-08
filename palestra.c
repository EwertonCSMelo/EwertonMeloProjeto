#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamNome 30
#include "ENCEC.h"


void organizarEvento()
{
    int tipo=-1,i=0;
    int nParticipantes, local;
    ENCEC evento;

    printf("oi");
    system("pause");
    while(tipo!=0)
    {
        printf("Tipo de evento: (1) Palestra; (2) Cursos; (3) Grupos e (4) Oficinas (0) Sair\n");
        printf("Opcao: ");
        scanf("%d", &tipo);

        switch (tipo)
        {
        case Palestra:
            system("cls");
            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(evento.palestrante,tamNome*sizeof(char),stdin);
            strtok(evento.palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(palestra[i].tema,tamNome*sizeof(char),stdin);
            strtok(palestra[i].tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(palestra[i].horario,tamNome*sizeof(char),stdin);
            strtok(palestra[i].horario,"\n");

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&palestra[i].cargaHoraria);

            printf("Digite o numero de participantes:");
            scanf("%d",nParticipantes);

            if(nParticipantes>=100&&nParticipantes<=150)
            {
                palestra[i].local=Auditorio1;
            }

            if(nParticipantes>=50&&nParticipantes<=100)
            {
                palestra[i].local=Auditorio2;
            }

            if(nParticipantes<=50)
            {
                palestra[i].local=Auditorio3;
            }

            break;

        case Cursos:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(curso[i].palestrante,tamNome*sizeof(char),stdin);
            strtok(curso[i].palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(curso[i].tema,tamNome*sizeof(char),stdin);
            strtok(curso[i].tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(curso[i].horario,tamNome*sizeof(char),stdin);
            strtok(curso[i].horario,"\n");

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&curso[i].cargaHoraria);

            printf("Local Sala1 ou Sala2:");
            scanf("%d",local);

            if (local==Sala1)
            {
                curso[i].local=local;
            }

            if (local==Sala2)
            {
                curso[i].local=local;
            }


            break;

        case Grupos:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(grupo[i].palestrante,tamNome*sizeof(char),stdin);
            strtok(grupo[i].palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(grupo[i].tema,tamNome*sizeof(char),stdin);
            strtok(grupo[i].tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(grupo[i].horario,tamNome*sizeof(char),stdin);
            strtok(grupo[i].horario,"\n");

            printf("Digite a carga horaria da palestra: ");
            scanf("%d",&grupo[i].cargaHoraria);

            printf("Local Sala1 ou Sala2: ");
            scanf("%d",local);

            if (local==Sala3)
            {
                grupo[i].local=local;
            }

            /*   if (local==Sala4)
               {
                   grupo[i].local=local;
               }*/

            break;

            case Oficinas:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(oficina[i].palestrante,tamNome*sizeof(char),stdin);
            strtok(oficina[i].palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(oficina[i].tema,tamNome*sizeof(char),stdin);
            strtok(oficina[i].tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(oficina[i].horario,tamNome*sizeof(char),stdin);
            strtok(oficina[i].horario,"\n");

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&oficina[i].cargaHoraria);

            printf("Local Lab1 ou Lab2:");
            scanf("%d",local);

            if (local==Lab1)
            {
                oficina[i].local=local;
            }

            if (local==Lab2)
               {
                   grupo[i].local=local;
               }
            break;

        }
    }
}

void printArq(ENCEC *pessoa, int numCongressistas)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("DADOS.DAT","wb"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","DADOS.DAT");
        exit(1);
    }

    for (i=0; i<numCongressistas; i++)
    {
        fwrite(&pessoa[i],sizeof(ENCEC),1,fp); // int sera o nome da struct
    }

    fclose(fp);
}

void lerArqBin(PESSOA *pessoa, int numCongressistas)
{

    FILE *fp;
    int contPessoa;
    contPessoa=numCongressistas;
    if((fp=fopen("DADOS.DAT","ab"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","DADOS.DAT");
    }
    else
    {
        while(fread(&pessoa[contPessoa],sizeof(ENCEC),1,fp))
        {
            printf("Nome: %s CPF: %s \n",pessoa[contPessoa].nome,pessoa[contPessoa].cpf);
            contPessoa++;
        }
    }

}
