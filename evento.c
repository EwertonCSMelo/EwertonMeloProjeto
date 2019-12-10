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
        printf("Alternativas para evento: \n");
        printf("(1) Palestra; \n");
        printf("(2) Cursos; \n");
        printf("(3) Grupos;  \n");
        printf("(4) Oficinas; \n");
        printf("(5) Mostrar Palestrantes; \n");
        printf("(0) Sair\n");
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

            printf("Digite o horario da palestra (hhmm):");
            setbuf(stdin,NULL);
            fgets(pal.horario,tamNome*sizeof(char),stdin);
            strtok(pal.horario,"\n");
            if (strcmp (pal.horario, "1300") == 1)
            {
                printf("As palestras devem ocorrer de manhã!!!\n");
                printf("Digite o horario da palestra (hhmm):");
                setbuf(stdin,NULL);
                fgets(pal.horario,tamNome*sizeof(char),stdin);
                strtok(pal.horario,"\n");
            }

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
            informaSala(pal.local);

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

            printf("Digite o horario do curso (hhmm):");
            setbuf(stdin,NULL);
            fgets(cursos.horario,tamNome*sizeof(char),stdin);
            strtok(cursos.horario,"\n");
            if (strcmp (cursos.horario, "1300") == -1)
            {
                printf("Os cursos devem ocorrer a tarde!!!\n");
                printf("Digite o horario do curso (hhmm):");
                setbuf(stdin,NULL);
                fgets(cursos.horario,tamNome*sizeof(char),stdin);
                strtok(cursos.horario,"\n");
            }

            printf("Digite a carga horaria do curso:");
            scanf("%d",&cursos.cargaHoraria);

            printf("Local Sala1 ou Sala2:");
            scanf("%d",&cursos.local);

            if (cursos.local==Sala1)
            {
                cursos.local=local;
            }

            if (cursos.local==Sala2)
            {
                cursos.local=local;
            }
            salvaCursos(&cursos);
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

            printf("Digite o horario do grupo (hhmm):");
            setbuf(stdin,NULL);
            fgets(grupos.horario,tamNome*sizeof(char),stdin);
            strtok(grupos.horario,"\n");
            if (strcmp (cursos.horario, "1300") == -1)
            {
                printf("Os grupos devem ocorrer a tarde!!!\n");
                printf("Digite o horario do grupo (hhmm):");
                setbuf(stdin,NULL);
                fgets(grupos.horario,tamNome*sizeof(char),stdin);
                strtok(grupos.horario,"\n");
            }

            printf("Digite a carga horaria da palestra: ");
            scanf("%d",&grupos.cargaHoraria);

            printf("Local Sala1 ou Sala2: ");
            scanf("%d",&grupos.local);

            if (grupos.local==Sala3)
            {
                grupos.local=local;
            }

            salvaGrupos(&grupos);
            break;

        case Oficinas:
            system("cls");
            printf("Digite o CPF do mediador:");
            setbuf(stdin,NULL);
            fgets(oficinas.cpf,tamNome*sizeof(char),stdin);
            strtok(oficinas.cpf,"\n");

            printf("Digite o tema da oficina:");
            setbuf(stdin,NULL);
            fgets(oficinas.tema,tamNome*sizeof(char),stdin);
            strtok(oficinas.tema,"\n");

            printf("Digite o horario da oficina (hhmm):");
            setbuf(stdin,NULL);
            fgets(oficinas.horario,tamNome*sizeof(char),stdin);
            strtok(oficinas.horario,"\n");
            if (strcmp (cursos.horario, "1300") == -1)
            {
                printf("As oficinas devem ocorrer a tarde!!!\n");
                printf("Digite o horario da oficina (hhmm):");
                setbuf(stdin,NULL);
                fgets(oficinas.horario,tamNome*sizeof(char),stdin);
                strtok(oficinas.horario,"\n");
            }

            printf("Digite a carga horaria da palestra:");
            scanf("%d",&oficinas.cargaHoraria);

            printf("Local Lab1 ou Lab2:");
            scanf("%d",&oficinas.local);

            if (oficinas.local==Lab1)
            {
                oficinas.local=local;
            }

            if (oficinas.local==Lab2)
            {
                oficinas.local=local;
            }
            salvaGrupos(&oficinas);
            break;
            //Verificando a participacao do palestrante esta correta
            checarCPF(&pal,&cursos,&oficinas,pal.cpf);
            checarCPF(&pal,&cursos,&oficinas,grupos.cpf);
            checarCPF(&pal,&cursos,&oficinas,oficinas.cpf);

            checarParticipantes(&cursos,&oficinas,cursos.cpf);
            checarParticipantes(&cursos,&oficinas,oficinas.cpf);
            system("pause");

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
        printf("Impossivel criar o arquivo %s\n","Grupo.dat");
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
        printf("Impossivel criar o arquivo %s\n","Oficinas.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(OFICINA),1,fp); // int sera o nome da struct

    fclose(fp);
}

void checarCPF(PALESTRA *dados1,CURSO *dados2, OFICINA *dados3,char var)
{
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
        fseek(fp, sizeof(PALESTRA), SEEK_SET);

        while(fread(&dados1, sizeof(PALESTRA),1, fp)==1)
        {
            if(dados1->cpf==var)
            {
                contPal++;
            }
        }
        if (contPal>=1)
        {
            printf("Palestrante ja cadastrado em %d palestra(s)!\n",contPal);
        }
        close(fp);
    }
//Testando se o palestrante esta inscrito em algum curso
    if((fp=fopen("Curso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Curso.dat");
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
            printf("Palestrante ja cadastrado em %d curso(s)!",contCurso);
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
            printf("Palestrante ja cadastrado em %d oficina(s)!",contOfic);
        }
        close(fp);
    }
}

void checarParticipantes(INSCCURSO *dados1,INSCOFICINA *dados2,char var)
{
    FILE *fp;
    int i=0;
    int contPart=0;
    int contCurso=0;
    int contOfic=0;

    if((fp=fopen("partCurso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","partCurso.dat");
    }
    else
    {
        fseek(fp, sizeof(PALESTRA), SEEK_SET);
        while(fread(&dados1, sizeof(INSCCURSO),1, fp)==1)
        {
            if(dados1->cpf==var)
            {
                contPart++;
            }
        }
        if (contPart>=1)
        {
            printf("Palestrante ja cadastrado em %d curso(s)...\n",contPart);
        }
        close(fp);
    }
//Testando se o palestrante esta inscrito em algum curso
    if((fp=fopen("partOficina.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Curso.dat");
    }
    else
    {
        while(fread(&dados2, sizeof(CURSO),1, fp)==1)
        {
            if(dados2->cpf==var)
            {
                contOfic++;
            }
        }
        if (contOfic>=1)
        {
            printf("Palestrante ja cadastrado em %d curso(s)...",contOfic);
        }
        close(fp);
    }
}

void partCursos(CURSO *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("partCurso.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","partCurso.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(CURSO),1,fp); // int sera o nome da struct

    fclose(fp);
}

void partOficina(OFICINA *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("partOficina.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","partOficina.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(CURSO),1,fp); // int sera o nome da struct

    fclose(fp);
}

void inscreverParticipante()
{
    INSCCURSO cursos;
    INSCOFICINA oficinas;
    int op;

    printf("Incricao (1) Curso (2) Oficina:");
    scanf("%d",op);
    if(op==1)
    {
        system("cls");
        printf("Digite o CPF do mediador:");
        setbuf(stdin,NULL);
        fgets(cursos.cpf,tamNome*sizeof(char),stdin);
        strtok(cursos.cpf,"\n");

        printf("Digite o tema do curso:");
        setbuf(stdin,NULL);
        fgets(cursos.tema,tamNome*sizeof(char),stdin);
        strtok(cursos.tema,"\n");
        partCursos(&cursos);
    }
    else
    {
        system("cls");
        printf("Digite o CPF do mediador:");
        setbuf(stdin,NULL);
        fgets(oficinas.cpf,tamNome*sizeof(char),stdin);
        strtok(oficinas.cpf,"\n");

        printf("Digite o tema da oficina:");
        setbuf(stdin,NULL);
        fgets(oficinas.tema,tamNome*sizeof(char),stdin);
        strtok(oficinas.tema,"\n");
        partOficina(&oficinas);

    }
}

char informaSala(int local)
{
    switch(local)
    {
    case Auditorio1:
        return "Auditorio1";
    case Auditorio2:
        return "Auditorio2";
    case Auditorio3:
        return "Auditorio3";
    case      Sala1:
        return "Sala1";
    case      Sala2:
        return "Sala2";
    case      Sala3:
        return "Sala3";
    case       Lab1:
        return "Lab1";
    case       Lab2:
        return "Lab2";
    default:
        return "Nao ha local!!!";

    }
}


void lerPalestra(PALESTRA *dados, int numPart)
{
    FILE *fp;
    numPart=0;
    if((fp=fopen("Palestra.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Palestra.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(PALESTRA),1,fp))
        {
            printf("CPF: %s\n",dados[numPart].cpf);
            printf("Nome: %s\n",dados[numPart].nome);
            printf("Tema: %s\n",dados[numPart].tema);
            printf("Horario: %s\n",dados[numPart].horario);
            printf("Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("Local: %s",informaSala(dados[numPart].local));
            numPart++;

        }
    }

}


/*void printArq(ENCEC *pessoa, int numCongressistas)
{
    FILE *fp;
    int i;
    //Abrir o Arquivo DADOS.DAT
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
*/

