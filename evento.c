#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ENCEC.h"
#include "evento.h"

void organizarEvento()
{
    PALESTRA pal;
    CURSO cursos;
    GRUPO grupos;
    OFICINA oficinas;
    int tipo=-1,i=0;
    int nParticipantes, local;

    while(tipo!=0)
    {
        system("cls");
        printf("Tipo de evento: (1) Palestra; (2) Cursos; (3) Grupos e (4) Oficinas (0) Sair\n");
        printf("Opcao: ");
        scanf("%d", &tipo);

        switch (tipo)
        {
        case Palestra:

            system("cls");
            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(pal.palestrante,tamNome*sizeof(char),stdin);
            strtok(pal.palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(pal.tema,tamNome*sizeof(char),stdin);
            strtok(pal.tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(pal.horario,tamNome*sizeof(char),stdin);
            strtok(pal.horario,"\n");

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&pal.cargaHoraria);

            printf("Digite o numero de participantes:");
            scanf("%d",&pal.nParticipantes);

            if(pal.nParticipantes>=100&&pal.nParticipantes<=150)
            {
                pal.local=Auditorio1;
            }

            if(pal.nParticipantes>=50&&pal.nParticipantes<=100)
            {
                pal.local=Auditorio2;
            }

            if(pal.nParticipantes<=50)
            {
                pal.local=Auditorio3;
            }
            salvaPalestra(&pal);
            break;

        case Cursos:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(cursos.palestrante,tamNome*sizeof(char),stdin);
            strtok(cursos.palestrante,"\n");

            printf("Digite o tema do curso:");
            setbuf(stdin,NULL);
            fgets(cursos.tema,tamNome*sizeof(char),stdin);
            strtok(cursos.tema,"\n");

            printf("Digite o horario do curso:");
            setbuf(stdin,NULL);
            fgets(cursos.horario,tamNome*sizeof(char),stdin);
            strtok(cursos.horario,"\n");

            printf("Digite a carga horaria do curso:");
            scanf("%d",&cursos.cargaHoraria);

            printf("Local Sala1 ou Sala2:");
            scanf("%d",cursos.local);

            if (cursos.local==Sala1)
            {
                cursos.local=local;
            }

            if (cursos.local==Sala2)
            {
                cursos.local=local;
            }
            break;

        case Grupos:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(grupos.palestrante,tamNome*sizeof(char),stdin);
            strtok(grupos.palestrante,"\n");

            printf("Digite o tema da discussao:");
            setbuf(stdin,NULL);
            fgets(grupos.tema,tamNome*sizeof(char),stdin);
            strtok(grupos.tema,"\n");

            printf("Digite o horario do grupo:");
            setbuf(stdin,NULL);
            fgets(grupos.horario,tamNome*sizeof(char),stdin);
            strtok(grupos.horario,"\n");

            printf("Digite a carga horaria da palestra: ");
            scanf("%d",&grupos.cargaHoraria);

            printf("Local Sala1 ou Sala2: ");
            scanf("%d",&grupos.local);

            if (grupos.local==Sala3)
            {
                grupos.local=local;
            }

            /*   if (local==Sala4)
               {
                   evento->local=local;
               }*/

            break;

        case Oficinas:
            system("cls");
            printf("Digite o nome do mediador:");
            setbuf(stdin,NULL);
            fgets(oficinas.palestrante,tamNome*sizeof(char),stdin);
            strtok(oficinas.palestrante,"\n");

            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(oficinas.tema,tamNome*sizeof(char),stdin);
            strtok(oficinas.tema,"\n");

            printf("Digite o horario da palestra:");
            setbuf(stdin,NULL);
            fgets(oficinas.horario,tamNome*sizeof(char),stdin);
            strtok(oficinas.horario,"\n");

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&oficinas.cargaHoraria);

            printf("Local Lab1 ou Lab2:");
            scanf("%d",oficinas.local);

            if (oficinas.local==Lab1)
            {
                oficinas.local=local;
            }

            if (oficinas.local==Lab2)
            {
                oficinas.local=local;
            }
            break;

        }
    }
}

void salvaPalestra(PALESTRA *var)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Palestra.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(&var,sizeof(PALESTRA),1,fp); // int sera o nome da struct

    fclose(fp);
}


void checarPalestrante(PALESTRA *pessoa)
{
    FILE *fp;
    int contPessoa=0;

    if((fp=fopen("Palestra.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Palestrante.dat");
    }
    else
    {
        while(fread(&pessoa,sizeof(ENCEC),1,fp))
        {
            printf("Nome: %s CPF: %s \n",pessoa->nome,pessoa->cpf);
            contPessoa++;
        }
    }

}

void salvaCursos(ENCEC *cursos, int capacidade)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("cursos.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","cursos.dat");
        exit(1);
    }

    fwrite(&cursos[i],sizeof(ENCEC),1,fp); // int sera o nome da struct

    fclose(fp);
}

void salvaGrupos(ENCEC *grupos, int capacidade)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("grupos.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","grupos.dat");
        exit(1);
    }

    fwrite(&grupos[i],sizeof(ENCEC),1,fp); // int sera o nome da struct

    fclose(fp);
}

salvaOficinas(ENCEC *oficinas, int capacidade)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("oficinas.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","oficinas.dat");
        exit(1);
    }

    fwrite(&oficinas[i],sizeof(ENCEC),1,fp); // int sera o nome da struct

    fclose(fp);
}
