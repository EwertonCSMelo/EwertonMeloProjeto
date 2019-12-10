#ifndef ENCEC_HEADER
#define ENCEC_HEADER
#define tamNome 30
#define tamDoc 15
#define capMax 150
enum eventos {Palestra=1, Cursos, Grupos, Oficinas};

enum Local {Auditorio1=1, Auditorio2, Auditorio3, Sala1, Sala2,Sala3,Lab1,Lab2};

enum participantes {Congressista=1,Palestrante,Organizador};


typedef struct endereco
{
    char rua[tamNome];
    char bairro[tamNome];
    char cidade[tamNome];
    char estado[tamNome];
    char pais[tamNome];
    int  cep;
    int  numero;
    char numCelular[tamNome];
    char email[tamNome];
} ENDERECO;

typedef struct pessoa
{
    char nome[tamNome];
    char cpf[tamDoc];
    char id[tamDoc]; //identidade
    ENDERECO ende;
} PESSOA;

typedef struct
{
    int capacidadeMin;
    int capacidadeMax;
    int local;
    int cargaHoraria;
    char horario[tamNome];
    char tema[tamNome];
    char palestrante[tamNome];
    char membrosMesa[tamNome];
    char Oficinas[tamNome];
    char Grupos[tamNome];
    char Palestra[tamNome];
    char Cursos[tamNome];
} ENCEC;

void encec();
void lerNome(PESSOA *p);
void lerCPF(PESSOA *p);
void lerIdentidade(PESSOA *p);
void lerRua(PESSOA *p);
void lerNumero(PESSOA *p);
void lerBairro(PESSOA *p);
void lerCidade(PESSOA *p);
void lerEstado(PESSOA *p);
void lerPais(PESSOA *p);
void lerCEP(PESSOA *p);
void lerNumCelular(PESSOA *p);
void lerEMAIL(PESSOA *p);
void removerDados(PESSOA *p, int nc);
void editarDados(PESSOA *p, int np);
void acrescentarCongressista(PESSOA *congressista);
void mostrarCongressista(PESSOA *pessoa);
void acrescentarPalestrante(PESSOA *palestrante);
void mostrarPalestrante(PESSOA *pessoa);
void acrescentarOrganizador(PESSOA *organizador);
void mostrarOrganizador(PESSOA *organizador);
void *alocaMemoria(ENCEC *p,int numCongressistas);
void liberaMemoria(ENCEC *p,int numCongressistas);
void printArq(ENCEC *pessoa, int numCongressistas);
void lerArqBin();
void printArq(ENCEC *pessoa, int numCongressistas);
void organizarEvento();
void HideCursor();
#endif // ENCEC_HEADER

