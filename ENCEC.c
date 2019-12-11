/*
Esta funcao insere e conta o numero de participantes no Congresso
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "ENCEC.h"
#define capMax 150
#define tamDoc 15

/*void *alocaMemoria(ENCEC *p,int numCongressistas)
{
    p=(ENCEC*)malloc(numCongressistas*sizeof(ENCEC));
}

void liberaMemoria(ENCEC *p,int numCongressistas)
{
    free(p);
}*/


void encec()
{
    PESSOA participante[10];  //Definindo a variavel dado como tipo dados pessoais
    PESSOA palestrante[10];
    PESSOA organizador[10];
    ENCEC *evento;
    int contaParticipante=0;    //Conta o numero de contatos existentes no evento
    int contaPalestrante=0;
    int contaOrganizador=0;
    int editarParticipante=1;  //Verifica se sera inserido um novo participante
    int opcao=-1;
    int i;
    system("color 9E");
    HideCursor();


//    textcolor(128);
    while(opcao!=0)
    {
        setlocale(LC_ALL,"");
        system("cls");
        cabecalho();
        printf("\n\n\n\n");
        printf("\t\t\t\t\t(1)Editar participantes\n");
        printf("\t\t\t\t\t(2)Editar Evento \n");
        printf("\t\t\t\t\t(0)Sair \n");
        printf("\t\t\t\t\t Opcao: ");
        scanf("%d",&opcao);
        switch(opcao)
        {

        case 1:

            while (editarParticipante!=0) //Laco responsavel pelo acrescimo e contagem de pessoas no evento
            {
                system("cls");
                cabecalho();
                printf("\n\n\n");
                printf("\t\t\t\t\t(1) Acrescentar Congressista\n");
                printf("\t\t\t\t\t(2) Acrescentar Palestrante\n");
                printf("\t\t\t\t\t(3) Acrescentar Organizadores\n");
                printf("\t\t\t\t\t(4) Mostrar Congressista\n");
                printf("\t\t\t\t\t(5) Mostrar Palestrante\n");
                printf("\t\t\t\t\t(6) Mostrar Organizadores\n");
                printf("\t\t\t\t\t(7) Editar Congressista\n");
                printf("\t\t\t\t\t(8) Editar Palestrante\n");
                printf("\t\t\t\t\t(9) Editar Organizadores\n");
                printf("\t\t\t\t\t(10) Remover Congressista\n");


                printf("\t\t\t\t\t(0) Sair do menu\n\n\n");

                printf("\t\t\t\t\tEscolha uma opcao: ");
                scanf("%d",&editarParticipante);

                if (editarParticipante!=0)
                {

                    switch(editarParticipante)
                    {
                    case 1:
                        acrescentarCongressista(&participante[contaParticipante++]);
                        salvaCongressista(&participante[contaParticipante]);
                        break;
                    case 2:
                        acrescentarPalestrante(&palestrante[contaPalestrante++]);
                        salvaPalestrante(&palestrante[contaPalestrante]);
                        break;
                    case 3:
                        acrescentarOrganizador(&organizador[contaOrganizador++]);
                        salvaOrganizadores(&organizador[contaOrganizador]);
                        break;
                    case 4:
                        mostrarDados(&participante,contaParticipante);
                        break;
                    case 5:
                        mostrarDados(&palestrante,contaPalestrante);
                        break;
                    case 6:
                        mostrarDados(&organizador,contaOrganizador);
                        break;
                    case 7:
                        editarDados(&participante,contaParticipante);
                        break;
                    case 8:
                        editarDados(&palestrante,contaPalestrante);
                        break;
                    case 9:
                        editarDados(&organizador,contaOrganizador);
                        break;
                    case 10:
                        removerDados(&participante,contaParticipante);
                        contaParticipante--;
                        break;

                    default:
                        printf("Opcao invalida");
                    }

                }

                break;
            case 2:
                organizarEvento(evento);
                break;

            }

        }

    }
}

void editarDados(PESSOA *p, int np)
{
    int i,opcao,encontrado=0;
    char CPF[tamDoc];
    system("cls");
    printf("CPF: ");
    setbuf(stdin,NULL);
    fgets(CPF,tamDoc*sizeof(char),stdin);
    strtok(CPF,"\n");


    for(i=0; i<np; i++)
    {
        system("cls");
        printf("procurando.");
        Sleep(600);
        system("cls");
        printf("procurando..");
        system("cls");
        printf("procurando...");
        system("cls");
        Sleep(600);
        if(strcmp(CPF, p[i].cpf)==0)
        {
            encontrado=1;
        }
    }

    if (encontrado==0)
    {
        printf("Participante nao encontrado!!!\n\n\n");
        system ("pause");
    }
    //   printDados(&p[i].contato);
    if (encontrado==1)
    {
        while (opcao!=0)
        {
            system("cls");
            cabecalho();
            printf("\n\n\n");
            printf("\t\t\t\t\t Escolha uma opcao: \n\n\n");
            printf("\t\t\t\t\t(1) Alterar Nome\n");
            printf("\t\t\t\t\t(2) Alterar CPF\n");
            printf("\t\t\t\t\t(3) Alterar Identidade\n");
            printf("\t\t\t\t\t(4) Alterar rua\n");
            printf("\t\t\t\t\t(5) Alterar bairro\n");
            printf("\t\t\t\t\t(6) Alterar cidade\n");
            printf("\t\t\t\t\t(7) Alterar estado\n");
            printf("\t\t\t\t\t(8) Alterar pais\n");
            printf("\t\t\t\t\t(9) Alterar cep\n");
            printf("\t\t\t\t\t(10) Alterar numero\n");
            printf("\t\t\t\t\t(11) Alterar Numero do Celular\n");
            printf("\t\t\t\t\t(12) Alterar Email\n");
            printf("\t\t\t\t\t(0) Voltar para o programa\n");
            printf("\n");
            printf("\t\t\t\t\tOpcao: ");
            scanf("%d",&opcao);

            if(opcao!=0)
            {
                switch(opcao)
                {
                case 1:
                    lerNome(p);
                    break;

                case 2:
                    lerCPF(p);
                    break;

                case 3:
                    lerIdentidade(p);
                    break;

                case 4:
                    lerRua(p);
                    break;

                case 5:
                    lerNumero(p);
                    break;

                case 6:
                    lerBairro(p);
                    break;

                case 7:
                    lerCidade(p);
                    break;

                case 8:
                    lerEstado(p);
                    break;

                case 9:
                    lerPais(p);
                    break;

                case 10:
                    lerCEP(p);
                    break;

                case 11:
                    lerNumCelular(p);
                    break;

                case 12:
                    lerEMAIL(p);
                    break;
                }
            }
        }
    }
}


void mostrarDados(PESSOA *p, int np)
{
    int i;
    system("cls");
    for (i=0; i<np; i++)
    {
        printf("Nome: ");
        printf("%s\n", strupr(p[i].nome));

        printf("CPF: ");
        printf("%s\n",p[i].cpf);

        printf("Identidade: ");
        printf("%s\n",p[i].id);

        printf("Rua: ");
        printf("%s\n",strupr(p[i].ende.rua));

        printf("Numero: ");
        printf("%d\n",p[i].ende.numero);

        printf("Bairro: ");
        printf("%s\n",strupr(p[i].ende.bairro));

        printf("Cidade: ");
        printf("%s\n",strupr(p[i].ende.cidade));

        printf("Estado: ");
        printf("%s\n",strupr(p[i].ende.estado));

        printf("Pais: ");
        printf("%s\n",p[i].ende.pais);

        printf("CEP: ");
        printf("%d\n",p[i].ende.cep);

        printf("Telefone: ");
        printf("%s\n",p[i].ende.numCelular);

        printf("EMAIL: ");
        printf("%s\n",p[i].ende.email);
        printf("\n\n --------------------------------------- \n\n");
    }
    system("pause");
}


void removerDados(PESSOA *p, int nc)
{
    char cpf[tamDoc];
    int i,pos,achou;

    system("cls");
    printf("CPF:");
    setbuf(stdin, NULL); // Limpar a stream antes de pegar os dados.
    fgets(cpf, tamDoc, stdin);
    strtok(cpf, "\n");//limpando o '\n'
    achou=-1;
    for(i=0; i<nc; i++)
    {
        achou=strcmp(cpf, p[i].cpf);
        if (achou==0)
        {
            achou=1;
            pos=i;
            break;
        }
    }

    if(achou==0)
    {
        printf("Contato nao localizado\n\n\n");
        system ("pause");
    }

    if (achou == 1)
    {
        for (i=pos; i<nc-1; i++)
        {
            strcpy(p[i].nome, p[i+1].nome);
            strcpy(p[i].cpf, p[i+1].cpf);
            strcpy(p[i].id, p[i+1].id);
            strcpy(p[i].ende.rua, p[i+1].ende.rua);
            p[i].ende.numero=p[i+1].ende.numero;
            strcpy(p[i].ende.bairro, p[i+1].ende.bairro);
            strcpy(p[i].ende.cidade, p[i+1].ende.cidade);
            strcpy(p[i].ende.estado, p[i+1].ende.estado);
            strcpy(p[i].ende.pais, p[i+1].ende.pais);
            p[i].ende.cep=p[i+1].ende.cep;
            strcpy(p[i].ende.numCelular, p[i+1].ende.numCelular);
            strcpy(p[i].ende.email, p[i+1].ende.email);

        }
    }
}



void lerNome(PESSOA *p)
{
    system("cls");
    printf("Nome: ");
    setbuf(stdin,NULL);
    fgets(p->nome,tamNome*sizeof(char),stdin);
    strtok(p->nome,"\n");
}

void lerCPF(PESSOA *p)
{
    system("cls");
    printf("CPF: ");
    setbuf(stdin,NULL);
    fgets(p->cpf,tamDoc*sizeof(char),stdin);
    strtok(p->cpf,"\n");
}

void lerIdentidade(PESSOA *p)
{
    system("cls");
    printf("Identidade: ");
    setbuf(stdin,NULL);
    fgets(p->id,tamDoc*sizeof(char),stdin);
    strtok(p->id,"\n");
}

void lerRua(PESSOA *p)
{
    system("cls");
    printf("Rua: ");
    setbuf(stdin,NULL);
    fgets(p->ende.rua,tamNome*sizeof(char),stdin);
    strtok(p->ende.rua,"\n");
}
void lerNumero(PESSOA *p)
{
    system("cls");
    printf("Numero: ");
    scanf("%d",&p->ende.numero);
}

void lerBairro(PESSOA *p)
{
    system("cls");
    printf("Bairro: ");
    setbuf(stdin,NULL);
    fgets(p->ende.bairro,tamNome*sizeof(char),stdin);
    strtok(p->ende.bairro,"\n");
}

void lerCidade(PESSOA *p)
{
    system("cls");
    printf("Cidade: ");
    setbuf(stdin,NULL);
    fgets(p->ende.cidade,tamNome*sizeof(char),stdin);
    strtok(p->ende.cidade,"\n");
}

void lerEstado(PESSOA *p)
{
    system("cls");
    printf("Estado: ");
    setbuf(stdin,NULL);
    fgets(p->ende.estado,tamNome*sizeof(char),stdin);
    strtok(p->ende.estado,"\n");
}

void lerPais(PESSOA *p)
{
    system("cls");
    printf("Pais: ");
    setbuf(stdin,NULL);
    fgets(p->ende.pais,tamNome*sizeof(char),stdin);
    strtok(p->ende.pais,"\n");
}
void lerCEP(PESSOA *p)
{
    system("cls");
    printf("CEP: ");
    scanf("%d",&p->ende.cep);
}
void lerNumCelular(PESSOA *p)
{
    system("cls");
    printf("Telefone: ");
    setbuf(stdin,NULL);
    fgets(p->ende.numCelular,tamNome*sizeof(char),stdin);
    strtok(p->ende.numCelular,"\n");
}

void lerEMAIL(PESSOA *p)
{
    system("cls");
    printf("EMAIL: ");
    setbuf(stdin,NULL);
    fgets(p->ende.email,tamNome*sizeof(char),stdin);
    strtok(p->ende.email,"\n");
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void salvaCongressista(PESSOA *dados)
{
    FILE *fp;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Congressista.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(dados,sizeof(PESSOA),1,fp); // int sera o nome da struct

    fclose(fp);
}

void salvaPalestrante(PESSOA *dados)
{
    FILE *fp;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Palestrante.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(dados,sizeof(PESSOA),1,fp); // int sera o nome da struct

    fclose(fp);
}
void salvaOrganizadores(PESSOA *dados)
{
    FILE *fp;
    /*Abrir o Arquivo DADOS.DAT */
    if ((fp = fopen("Organizadores.dat","ab"))==NULL)
    {
        printf("Impossivel criar o arquivo %s\n","Palestra.dat");
        exit(1);
    }

    fwrite(dados,sizeof(PESSOA),1,fp); // int sera o nome da struct

    fclose(fp);
}

void cabecalho()

{
    int i;
    printf("\n\t ");
    for (i=0; i<103; i++)
    {
        printf("_");
    }
    printf("\n");

    printf("\t|");

    for(i=0; i<103; i++)
    {
        printf(" ");
    }
    printf("|\n\t|");
    for(i=0; i<103; i++)
    {
        printf(" ");
    }
    printf("|\n\t|");
    printf("\t\t\t ENCONTRO CAMPINENSE DOS ESTUDANTES DE COMPUTAÇÃO - ENCEC\t\t\t|\n");
    printf("\t|\t\t\t UNIVERSIDADE ESTADUAL DA PARAIBA - UEPB\t\t\t\t\t|\n");
    printf("\t|\t\t\t LABORATORIO DE COMPUTAÇÃO I- LAB1\t\t\t\t\t\t|\n");
    printf("\t|");
    for(i=0; i<103; i++)
    {
        printf(" ");
    }
    printf("|\n");

    printf("\t|");
    for(i=0; i<103; i++)
    {
        printf("_");
    }
    printf("|\n");
}


