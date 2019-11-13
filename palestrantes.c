#define tamNome 30

typedef struct{
     char nome[tamNome];
     int  cpf;
     int  identidade;
     int  diaNasc;
     int  mesNasc;
     int  anoNasc;
}PALESTRANTE;

typedef struct{
     char rua[tamNome];
     char bairro[tamNome];
     char cidade[tamNome];
     char pais[tamNome];
     int  cep;
     int  numero;
     int  numCelular;
     char email[tamNome];
     PALESTRANTE p;
}DADOSPALESTRANTE;
