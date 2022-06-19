#include <stdio.h>
#include <locale.>

typedef struct{
  int dia, mes, ano; 
}Data;

typedef struct{
  char nome[50];
  Data data;
}Pessoa; 

typedef struct no{
  Pessoa p;
  struct no *proximo;
}

Pessoa ler_pessoa(){
  printf("Digite seu nome:");
  scanf("%s", p.nome);
  printf("Digite sua data de nascimento (dd/mm/aaaa)");
  scanf("%d %d %d", p.data.dia, p.data.mes, p.data.ano);
  return p; 
}