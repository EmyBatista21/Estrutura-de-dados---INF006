#include <stdio.h>
#include <stdlib.h>

//gcc listaSimples.c -o simples -Wno-unused-result

typedef struct ponto{
  int x, y;
  struct ponto * prox; 
}t_ponto;

int main(void){
  int resp;
  t_ponto *ini_ponto = NULL;
  t_ponto *prox_ponto = NULL;
  ini_ponto = (t_ponto*)malloc(sizeof(t_ponto));
  if(ini_ponto == NULL)
    exit(1);
  prox_ponto = ini_ponto;
  while(1){
    printf("Digite x:");
    scanf("%d", &prox_ponto -> x);
    printf("Digite y:");
    scanf("%d", &prox_ponto -> y);
    printf("Deseja continuar? <1> SIM <outro valor> NAO:\n");
    scanf("%d", &resp);
    if(resp == 1){
      prox_ponto -> prox = (t_ponto*)malloc(sizeof(t_ponto));
      prox_ponto = prox_ponto -> prox; 
    }else
      break; 
  }
  prox_ponto -> prox = NULL;
  prox_ponto = ini_ponto; 
  while(prox_ponto != NULL){
    printf("x: %d, y: %d\n", prox_ponto -> x, prox_ponto -> y);
    prox_ponto = prox_ponto -> prox; 
  }
}