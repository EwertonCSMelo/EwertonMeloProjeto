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
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(pal.cpf,tamNome*sizeof(char),stdin);
            strtok(pal.cpf,"\n");

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
            checarCPF(pal.cpf);
            break;

        case Cursos:
            system("cls");
            printf("Digite o CPF do mediador:");
            setbuf(stdin,NULL);
            fgets(cursos.cpf,tamNome*sizeof(char),stdin);
            strtok(cursos.cpf,"\n");

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
            salvaCursos(cursos);
            checarCPF(cursos.cpf);
            break;

        case Grupos:
            system("cls");
            printf("Digite o CPF do mediador:");
            setbuf(stdin,NULL);
            fgets(grupos.cpf,tamNome*sizeof(char),stdin);
            strtok(grupos.cpf,"\n");

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
            salvaGrupos(grupos);
            checarCPF(grupos.cpf);
            break;

        case Oficinas:
            system("cls");
            printf("Digite o CPF do mediador:");
            setbuf(stdin,NULL);
            fgets(oficinas.cpf,tamNome*sizeof(char),stdin);
            strtok(oficinas.cpf,"\n");

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
            salvaGrupos(oficinas);
            checarCPF(oficinas.cpf);
            break;

        }
    }
}

void salvaPalestra(PALESTRA *dados)
{
    FILE *fp;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Palestra.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(dados,sizeof(PALESTRA),1,fp); // int sera o nome da struct

    fclose(fp);
}


void salvaCursos(CURSO *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Curso.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","cursos.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(CURSO),1,fp); // int sera o nome da struct

    fclose(fp);
}

void salvaGrupos(GRUPO *dados)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Grupo.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","grupos.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(GRUPO),1,fp); // int sera o nome da struct

    fclose(fp);
}

salvaOficinas(OFICINA *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Oficinas.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","oficinas.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(OFICINA),1,fp); // int sera o nome da struct

    fclose(fp);
}

void checarCPF(char var)
{
    PALESTRA *dados1;
    CURSO *dados2;
    OFICINA *dados3;

    FILE *fp;
    int i=0;
    int contPal=0;
    int contCurso=0;
    int contOfic=0;

    if((fp=fopen("Palestra.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Palestra.dat");
    }
    else
    {
        //fseek(fp, sizeof(PALESTRA), SEEK_SET);

        while(fread(&dados1, sizeof(PALESTRA),1, fp)==1)
        {
            if(dados1->cpf==var)
            {
                contPal++;
            }
        }
        if (contPal>=1)
        {
            printf("Palestrante ja cadastrado em %d palestra...\n",contPal);
        }
        close(fp);
    }
//Testando se o palestrante esta inscrito em algum curso
    if((fp=fopen("Curso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Palestra.dat");
    }
    else
    {
        //fseek(fp, sizeof(PALESTRA), SEEK_SET);

        while(fread(&dados2, sizeof(CURSO),1, fp)==1)
        {
            if(dados2->cpf==var)
            {
                contCurso++;
            }
        }
        if (contPal>=1)
        {
            printf("Palestrante ja cadastrado em %d curso(s)...",contCurso);
        }
        close(fp);
    }
//Testando se o palestrante esta inscrito em alguma oficina
    if((fp=fopen("Oficinas.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Oficinas.dat");
    }
    else
    {
        //fseek(fp, sizeof(PALESTRA), SEEK_SET);

        while(fread(&dados3, sizeof(OFICINA),1, fp)==1)
        {
            if(dados3->cpf==var)
            {
                contOfic++;
            }
        }
        if (contOfic>=1)
        {
            printf("Palestrante ja cadastrado em %d oficina(s)...",contOfic);
        }
        close(fp);
    }



}


