#ifndef EVENTO_HEADER
#define EVENTO_HEADER
#define capMax 150


typedef struct
{
    char cpf[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int local;
} PALESTRA;


typedef struct
{
    char cpf[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} CURSO;

typedef struct
{
    char cpf[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} GRUPO;

typedef struct
{
    char cpf[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} OFICINA;

void checarCPF(PALESTRA *dados,char var);

#endif // ENCEC_HEADER
