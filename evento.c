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
        cabecalho();
        printf("\n\n");
        printf("\t\t\t\t\tAlternativas para evento: \n");
        printf("\t\t\t(1) Palestras");
        printf("\t\t\t\t\t(2) Cursos \n");
        printf("\t\t\t(3) Grupos ");
        printf("\t\t\t\t\t(4) Oficinas \n");
        printf("\t\t\t(5) Mostrar Palestras ");
        printf("\t\t\t\t(6) Mostrar Cursos \n");
        printf("\t\t\t(7) Mostrar Grupos ");
        printf("\t\t\t\t(8) Mostrar Oficinas \n");
        printf("\t\t\t(9) Editar Palestras");
        printf("\t\t\t\t(10) Editar Cursos\n");
        printf("\t\t\t(11) Editar Grupos");
        printf("\t\t\t\t(12) Editar Oficinas\n");
        printf("\t\t\t(13) Excluir Palestras");
        printf("\t\t\t\t(14) Excluir Cursos\n");
        printf("\t\t\t(15) Excluir Grupos");
        printf("\t\t\t\t(16) Excluir Oficinas\n");
        printf("\t\t\t(0) Sair\n");
        printf("\t\t\tOpcao: ");
        scanf("%d", &tipo);

        switch (tipo)
        {
        case Palestra:

            system("cls");
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(pal.cpf,tamNome*sizeof(char),stdin);
            strtok(pal.cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(pal.nome,tamNome*sizeof(char),stdin);
            strtok(pal.nome,"\n");

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
            //Verificando a participacao do palestrante esta correta
            checarCPF(&pal,&cursos,&oficinas,pal.cpf);
            checarCPF(&pal,&cursos,&oficinas,grupos.cpf);
            checarCPF(&pal,&cursos,&oficinas,oficinas.cpf);
            break;

        case Cursos:
            system("cls");
            printf("Digite o CPF do mediador:");
            setbuf(stdin,NULL);
            fgets(cursos.cpf,tamNome*sizeof(char),stdin);
            strtok(cursos.cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(pal.nome,tamNome*sizeof(char),stdin);
            strtok(pal.nome,"\n");

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
            //Verificando a participacao do palestrante esta correta
            checarCPF(&pal,&cursos,&oficinas,pal.cpf);
            checarCPF(&pal,&cursos,&oficinas,grupos.cpf);
            checarCPF(&pal,&cursos,&oficinas,oficinas.cpf);
            checarParticipantes(&cursos,&oficinas,cursos.cpf);
            checarParticipantes(&cursos,&oficinas,oficinas.cpf);
            system("pause");
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

            printf("Digite a carga horaria do grupo: ");
            scanf("%d",&grupos.cargaHoraria);

            printf("Local Auditorio3, Sala1 ou Sala2: ");
            scanf("%d",&grupos.local);

            salvaGrupos(&grupos);
            //Verificando a participacao do palestrante esta correta
            checarCPF(&pal,&cursos,&oficinas,pal.cpf);
            checarCPF(&pal,&cursos,&oficinas,grupos.cpf);
            checarCPF(&pal,&cursos,&oficinas,oficinas.cpf);
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
            salvaOficinas(&oficinas);
            checarParticipantes(&cursos,&oficinas,cursos.cpf);
            checarParticipantes(&cursos,&oficinas,oficinas.cpf);
            system("pause");
            break;
        case 5:
            printPalestra(&pal, pal.nParticipantes);
            break;
        case 6:
            printCursos(&cursos, cursos.nParticipantes);
            break;
        case 7:
            printGrupos(&grupos, grupos.nParticipantes);
            break;
        case 8:
            printOficinas(&oficinas,oficinas.nParticipantes);
            break;

        case 9:
            editarPalestra(&pal, pal.nParticipantes);
            reSalvaPalestra(&pal);
            break;
        case 10:
            editarCursos(&cursos, cursos.nParticipantes);
            reSalvaCursos(&cursos);
            break;
        case 11:
            editarGrupos(&grupos, grupos.nParticipantes);
            reSalvaGrupos(&grupos);
            break;
        case 12:
            editarOficinas(&oficinas, oficinas.nParticipantes);
            reSalvaOficinas(&oficinas);
            break;
        case 13:
            excluirPalestra(&pal, pal.nParticipantes);
            reSalvaPalestra(&pal);
            break;
        case 14:
            excluirCursos(&cursos, cursos.nParticipantes);
            reSalvaCursos(&cursos);
            break;
        case 15:
            excluirGrupos(&grupos, grupos.nParticipantes);
            reSalvaGrupos(&grupos);
            break;
        case 16:
            excluirOficinas(&oficinas, oficinas.nParticipantes);
            reSalvaOficinas(&oficinas);
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
        printf("Impossivel criar o arquivo %s\n","Curso.dat");
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
    case 1:
        return "Auditorio1";
    case 2:
        return "Auditorio2";
    case 3:
        return "Auditorio3";
    case      4:
        return "Sala1";
    case      5:
        return "Sala2";
    case      6:
        return "Sala3";
    case       7:
        return "Lab1";
    case       8:
        return "Lab2";
    default:
        return "Nao ha local!!!";

    }
}


void printPalestra(PALESTRA *dados, int numPart)
{
    FILE *fp;
    numPart=0;
    if((fp=fopen("Palestra.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Palestra.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(PALESTRA),1,fp)==1)
        {
            system("cls");
            cabecalho();
            printf("\n\n");
            printf("\t\t\t\t\CPF: %s\n",dados[numPart].cpf);
            printf("\t\t\t\t\Nome: %s\n",dados[numPart].nome);
            printf("\t\t\t\t\Tema: %s\n",dados[numPart].tema);
            printf("\t\t\t\t\Horario: %s\n",dados[numPart].horario);
            printf("\t\t\t\t\Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("\t\t\t\t\Numero de Participantes: %d\n", dados[numPart].nParticipantes);
            printf("\t\t\t\t\Local: %d\n",dados[numPart].local);
            system("\t\t\t\t\pause");
            numPart++;
        }
      }
}

void printCursos(CURSO *dados, int numPart)
{
    FILE *fp;
    numPart=0;
    if((fp=fopen("Curso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Curso.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(CURSO),1,fp))
        {
            system("cls");
            cabecalho();
            printf("\n\n");
            printf("\t\t\t\t\CPF: %s\n",dados[numPart].cpf);
            printf("\t\t\t\t\Nome: %s\n",dados[numPart].nome);
            printf("\t\t\t\t\Tema: %s\n",dados[numPart].tema);
            printf("\t\t\t\t\Horario: %s\n",dados[numPart].horario);
            printf("\t\t\t\t\Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("\t\t\t\t\Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("\t\t\t\t\Capacidade: %d", dados[numPart].capacidade);
            printf("\t\t\t\t\Local: %d",dados[numPart].local);
            numPart++;

        }
    }
}

void printGrupos(GRUPO *dados, int numPart)
{
    FILE *fp;
    numPart=0;
    if((fp=fopen("Grupo.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Grupo.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(GRUPO),1,fp))
        {   system("cls");
            cabecalho();
            printf("\n\n");
            printf("\t\t\t\t\CPF: %s\n",dados[numPart].cpf);
            printf("\t\t\t\t\Nome: %s\n",dados[numPart].nome);
            printf("\t\t\t\t\Tema: %s\n",dados[numPart].tema);
            printf("\t\t\t\t\Horario: %s\n",dados[numPart].horario);
            printf("\t\t\t\t\Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("\t\t\t\t\Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("\t\t\t\t\Local: %d",dados[numPart].local);
            numPart++;
        }
    }
}

void printOficinas(OFICINA *dados, int numPart)
{
    FILE *fp;
    numPart=0;
    if((fp=fopen("Oficinas.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Oficinas.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(OFICINA),1,fp))
        {   cabecalho();
            printf("\n\n");
            printf("\t\t\t\t\CPF: %s\n",dados[numPart].cpf);
            printf("\t\t\t\t\Nome: %s\n",dados[numPart].nome);
            printf("\t\t\t\t\Tema: %s\n",dados[numPart].tema);
            printf("\t\t\t\t\Horario: %s\n",dados[numPart].horario);
            printf("\t\t\t\t\Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("\t\t\t\t\Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("\t\t\t\t\Capacidade: %d", dados[numPart].capacidade);
            printf("\t\t\t\t\Local: %d",dados[numPart].local);
            numPart++;
        }
    }
}
void reSalvaPalestra(PALESTRA *dados)
{
    FILE *fp;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Palestra.dat","wb"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(dados,sizeof(PALESTRA),1,fp); // int sera o nome da struct

    fclose(fp);
}


void reSalvaCursos(CURSO *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Curso.dat","wb"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Curso.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(CURSO),1,fp); // int sera o nome da struct

    fclose(fp);
}

void reSalvaGrupos(GRUPO *dados)
{
    FILE *fp;
    int i;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Grupo.dat","wb"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Grupo.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(GRUPO),1,fp); // int sera o nome da struct

    fclose(fp);
}

void reSalvaOficinas(OFICINA *dados)
{
    FILE *fp;

    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Oficinas.dat","wb"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Oficinas.dat");
        exit(1);
    }

    fwrite(&dados,sizeof(OFICINA),1,fp); // int sera o nome da struct

    fclose(fp);
}


void editarPalestra(PALESTRA *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
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
            printf("Local: %d",informaSala(dados[numPart].local));
            numPart++;
        }
    }

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        printf("Escolha o que deseja alterar:\n");
        printf("(1) Palestrante\n");
        printf("(2) Tema\n");
        printf("(3) Horario\n");
        printf("(4) Carga Horaria\n");
        printf("(5) Numero de Participantes\n");
        printf("(6) Local\n");
        printf("(0) Sair\n");
        switch(op)
        {
        case 1:
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].cpf,tamNome*sizeof(char),stdin);
            strtok(dados[cont].cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].nome,tamNome*sizeof(char),stdin);
            strtok(dados[cont].nome,"\n");
            break;

        case 2:
            printf("Digite o tema da palestra:");
            setbuf(stdin,NULL);
            fgets(dados[cont].tema,tamNome*sizeof(char),stdin);
            strtok(dados[cont].tema,"\n");
            break;

        case 3:
            printf("Digite o horario da palestra (hhmm):");
            setbuf(stdin,NULL);
            fgets(dados[cont].horario,tamNome*sizeof(char),stdin);
            strtok(dados[cont].horario,"\n");
            break;

        case 4:
            printf("Digite a carga horaria da palestra:");
            scanf("%d",&dados[cont].cargaHoraria);
            break;

        case 5:
            printf("Digite o numero de participantes:");
            scanf("%d",&dados[cont].nParticipantes);
            break;
        case 6:
            printf("Digite o local: Auditorio1, Auditorio2, Auditorio3, Sala1, Sala2,Sala3,Lab1,Lab2");
            scanf("%d",&dados[cont].local);
            break;
        }

    }
}
void editarCursos(CURSO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Curso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Curso.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(CURSO),1,fp))
        {
            printf("CPF: %s\n",dados[numPart].cpf);
            printf("Nome: %s\n",dados[numPart].nome);
            printf("Tema: %s\n",dados[numPart].tema);
            printf("Horario: %s\n",dados[numPart].horario);
            printf("Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("Local: %d",informaSala(dados[numPart].local));
            numPart++;
        }
    }

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        printf("Escolha o que deseja alterar:\n");
        printf("(1) Palestrante\n");
        printf("(2) Tema\n");
        printf("(3) Horario\n");
        printf("(4) Carga Horaria\n");
        printf("(5) Numero de Participantes\n");
        printf("(6) Local\n");
        printf("(0) Sair\n");
        switch(op)
        {
        case 1:
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].cpf,tamNome*sizeof(char),stdin);
            strtok(dados[cont].cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].nome,tamNome*sizeof(char),stdin);
            strtok(dados[cont].nome,"\n");
            break;

        case 2:
            printf("Digite o tema do curso:");
            setbuf(stdin,NULL);
            fgets(dados[cont].tema,tamNome*sizeof(char),stdin);
            strtok(dados[cont].tema,"\n");
            break;

        case 3:
            printf("Digite o horario do curso (hhmm):");
            setbuf(stdin,NULL);
            fgets(dados[cont].horario,tamNome*sizeof(char),stdin);
            strtok(dados[cont].horario,"\n");
            break;

        case 4:
            printf("Digite a carga horaria da palestra:");
            scanf("%d",&dados[cont].cargaHoraria);
            break;

        case 5:
            printf("Digite o numero de participantes:");
            scanf("%d",&dados[cont].nParticipantes);
            break;

        case 6:
            printf("Digite o local: Sala1, Sala2");
            scanf("%d",&dados[cont].local);
            break;
        }

    }
}

void editarGrupos(GRUPO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Grupo.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Grupo.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(GRUPO),1,fp))
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

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        printf("Escolha o que deseja alterar:\n");
        printf("(1) Palestrante\n");
        printf("(2) Tema\n");
        printf("(3) Horario\n");
        printf("(4) Carga Horaria\n");
        printf("(5) Numero de Participantes\n");
        printf("(6) Local\n");
        printf("(0) Sair\n");
        switch(op)
        {
        case 1:
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].cpf,tamNome*sizeof(char),stdin);
            strtok(dados[cont].cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].nome,tamNome*sizeof(char),stdin);
            strtok(dados[cont].nome,"\n");
            break;

        case 2:
            printf("Digite o tema do curso:");
            setbuf(stdin,NULL);
            fgets(dados[cont].tema,tamNome*sizeof(char),stdin);
            strtok(dados[cont].tema,"\n");
            break;

        case 3:
            printf("Digite o horario do curso (hhmm):");
            setbuf(stdin,NULL);
            fgets(dados[cont].horario,tamNome*sizeof(char),stdin);
            strtok(dados[cont].horario,"\n");
            break;

        case 4:
            printf("Digite a carga horaria da palestra:");
            scanf("%d",&dados[cont].cargaHoraria);
            break;

        case 5:
            printf("Digite o numero de participantes:");
            scanf("%d",&dados[cont].nParticipantes);
            break;

        case 6:
            printf("Digite o local: Sala1, Sala2");
            scanf("%d",&dados[cont].local);
            break;
        }

    }
}

void editarOficinas(GRUPO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Oficinas.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Oficinas.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(OFICINA),1,fp))
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

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        printf("Escolha o que deseja alterar:\n");
        printf("(1) Palestrante\n");
        printf("(2) Tema\n");
        printf("(3) Horario\n");
        printf("(4) Carga Horaria\n");
        printf("(5) Numero de Participantes\n");
        printf("(6) Local\n");
        printf("(0) Sair\n");
        switch(op)
        {
        case 1:
            printf("Digite o CPF do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].cpf,tamNome*sizeof(char),stdin);
            strtok(dados[cont].cpf,"\n");

            printf("Digite o nome do palestrante:");
            setbuf(stdin,NULL);
            fgets(dados[cont].nome,tamNome*sizeof(char),stdin);
            strtok(dados[cont].nome,"\n");
            break;

        case 2:
            printf("Digite o tema do curso:");
            setbuf(stdin,NULL);
            fgets(dados[cont].tema,tamNome*sizeof(char),stdin);
            strtok(dados[cont].tema,"\n");
            break;

        case 3:
            printf("Digite o horario do curso (hhmm):");
            setbuf(stdin,NULL);
            fgets(dados[cont].horario,tamNome*sizeof(char),stdin);
            strtok(dados[cont].horario,"\n");
            break;

        case 4:
            printf("Digite a carga horaria da palestra:");
            scanf("%d",&dados[cont].cargaHoraria);
            break;

        case 5:
            printf("Digite o numero de participantes:");
            scanf("%d",&dados[cont].nParticipantes);
            break;

        case 6:
            printf("Digite o local: Sala1, Sala2");
            scanf("%d",&dados[cont].local);
            break;
        }

    }
}

void excluirPalestra(PALESTRA *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
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
            printf("Local: %d",informaSala(dados[numPart].local));
            numPart++;
        }
    }

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        strcpy(dados[cont].cpf, dados[cont+1].cpf);
        strcpy(dados[cont].nome, dados[cont+1].nome);
        strcpy(dados[cont].tema, dados[cont+1].tema);
        strcpy(dados[cont].horario, dados[cont+1].horario);
        dados[cont].cargaHoraria= dados[cont+1].cargaHoraria;
        dados[cont].nParticipantes, dados[cont+1].nParticipantes;
        dados[cont].local=dados[cont+1].local;
        numPart--;
        cont--;
    }

}

void excluirCursos(CURSO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Curso.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Curso.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(CURSO),1,fp))
        {
            printf("CPF: %s\n",dados[numPart].cpf);
            printf("Nome: %s\n",dados[numPart].nome);
            printf("Tema: %s\n",dados[numPart].tema);
            printf("Horario: %s\n",dados[numPart].horario);
            printf("Carga Horaria: %d\n",dados[numPart].cargaHoraria);
            printf("Numero de Participantes: %d", dados[numPart].nParticipantes);
            printf("Local: %d",informaSala(dados[numPart].local));
            numPart++;
        }
    }

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        strcpy(dados[cont].cpf, dados[cont+1].cpf);
        strcpy(dados[cont].nome, dados[cont+1].nome);
        strcpy(dados[cont].tema, dados[cont+1].tema);
        strcpy(dados[cont].horario, dados[cont+1].horario);
        dados[cont].cargaHoraria= dados[cont+1].cargaHoraria;
        dados[cont].nParticipantes, dados[cont+1].nParticipantes;
        dados[cont].local=dados[cont+1].local;
        numPart--;
        cont--;
    }
}

void excluirGrupos(GRUPO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Grupo.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Grupo.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(GRUPO),1,fp))
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

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        strcpy(dados[cont].cpf, dados[cont+1].cpf);
        strcpy(dados[cont].nome, dados[cont+1].nome);
        strcpy(dados[cont].tema, dados[cont+1].tema);
        strcpy(dados[cont].horario, dados[cont+1].horario);
        dados[cont].cargaHoraria= dados[cont+1].cargaHoraria;
        dados[cont].nParticipantes, dados[cont+1].nParticipantes;
        dados[cont].local=dados[cont+1].local;
        numPart--;
        cont--;
    }

}


void excluirOficinas(GRUPO *dados, int numPart)
{
    FILE *fp;
    int op,cont;
    char CPF[tamDoc];
    numPart=0;

    if((fp=fopen("Oficinas.dat","rb"))==NULL)
    {
        printf("Impossivel ler o arquivo %s\n","Oficinas.dat");
    }
    else
    {
        while(fread(&dados[numPart],sizeof(OFICINA),1,fp))
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

    system("cls");
    printf("Digite o CPF do palestrante:");
    setbuf(stdin,NULL);
    fgets(CPF,tamNome*sizeof(char),stdin);
    strtok(CPF,"\n");

    cont=0;
    while(strcmp(CPF,dados[cont].cpf)!=0)
    {
        cont++;
    }
    if(strcmp(CPF,dados[cont].cpf)!=0&&cont==numPart)
    {
        printf("Palestrante não encontrado");
    }
    else
    {
        strcpy(dados[cont].cpf, dados[cont+1].cpf);
        strcpy(dados[cont].nome, dados[cont+1].nome);
        strcpy(dados[cont].tema, dados[cont+1].tema);
        strcpy(dados[cont].horario, dados[cont+1].horario);
        dados[cont].cargaHoraria= dados[cont+1].cargaHoraria;
        dados[cont].nParticipantes, dados[cont+1].nParticipantes;
        dados[cont].local=dados[cont+1].local;
        numPart--;
        cont--;
    }
}

void abrirArquivos()
{
     FILE *fp;
     fp = fopen("Palestra.dat","wb");
     fclose(fp);

     fp = fopen("Curso.dat","wb");
     fclose(fp);

     fp = fopen("Grupo.dat","wb");
     fclose(fp);

     fp = fopen("Oficinas.dat","wb");
     fclose(fp);

     fp=fopen("partCurso.dat","wb");
     fclose(fp);

     fp=fopen("partOficina.dat","wb");
     fclose(fp);

}

