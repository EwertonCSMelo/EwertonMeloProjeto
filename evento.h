#ifndef EVENTO_HEADER
#define EVENTO_HEADER
#define capMax 150
#include <time.h>
#include <windows.h>

/*struct tm
{
int tm_sec; //representa os segundos de 0 a 59
int tm_min; //representa os minutos de 0 a 59
int tm_hour; //representa as horas de 0 a 24
int tm_mday: //dia do mês de 1 a 31
int tm_mon; //representa os meses do ano de 0 a 11
int tm_year; //representa o ano a partir de 1900
int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
int tm_yday; // dia do ano de 1 a 365
int tm_isdst; //indica horário de verão se for diferente de zero
};*/

typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int local;
} PALESTRA;


typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int capacidade;
    int local;
} CURSO;

typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int capacidade;
    char local;
} GRUPO;

typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int capacidade;
    char local;
} OFICINA;

typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
} INSCCURSO;

typedef struct
{
    char cpf[tamNome];
    char nome[tamNome];
    char tema[tamNome];
} INSCOFICINA;


void checarCPF(PALESTRA *dados1,CURSO *dados2, OFICINA *dados3,char var);
void checarParticipantes(INSCCURSO *dados1,INSCOFICINA *dados2,char var);
void salvaPalestra(PALESTRA *dados);
void salvaCursos(CURSO *dados);
void salvaGrupos(GRUPO *dados);
char informaSala(int local);


#endif // ENCEC_HEADER
