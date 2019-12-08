#ifndef EVENTO_HEADER
#define EVENTO_HEADER
#define capMax 150


typedef struct
{
    char palestrante[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    int local;
} PALESTRA;


typedef struct
{
    char palestrante[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} CURSO;

typedef struct
{
    char palestrante[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} GRUPO;

typedef struct
{
    char palestrante[tamNome];
    char tema[tamNome];
    char horario[tamNome];
    int cargaHoraria;
    int nParticipantes;
    char local;
} OFICINA;

void salvaPalestra(PALESTRA *var);

#endif // ENCEC_HEADER
