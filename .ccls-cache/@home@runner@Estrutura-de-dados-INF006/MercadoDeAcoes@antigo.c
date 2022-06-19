#include <stdio.h>
#include <stdlib.h>

// gcc antigo.c -o antigo -Wno-unused-result
//Menus
int menuPrincipal(); 
int menuOpCompras(); 
int compras(int ini_compra, int prox_compra);
int vendas();
void press();
typedef struct compras{
  int qtdCompra;
  float valorCompra;
  struct compras *prox; 
} ofertas_compras;

typedef struct vendas{
  int qtdVenda;
  int valorVenda;
  struct vendas *proxVenda;
} ofertas_vendas;

int main(void){
  int op = 0;  
  int opCompra;
  int resp = 0; 
  char nome[10] = "PETR4"; 
  ofertas_compras *ini_compra = NULL;
  ofertas_compras *prox_compra = NULL;
  ini_compra = (ofertas_compras*)malloc(sizeof(ofertas_compras));
  prox_compra = ini_compra;
  while(op != 3){
    op = menuPrincipal(); 
    if(op == 1){
      opCompra = menuOpCompras(); 
      if(opCompra == 1){
        if(ini_compra == NULL)
          exit(1);
        while(1){
          printf("Insira a quantidade da compra: ");
          scanf("%d", &prox_compra->qtdCompra);
          printf("Insira o valor da compra: ");
          scanf("%f", &prox_compra->valorCompra);
          printf("Deseja inserir mais ofertas?: <1> Sim: ");
          scanf("%d", &resp);
          getchar();
          system("clear || cls");
          if(resp == 1){
            prox_compra -> prox = (ofertas_compras*)malloc(sizeof(ofertas_compras));
            prox_compra = prox_compra -> prox; 
          }else  
            break;
        }
      }else{
        prox_compra -> prox = NULL;
        prox_compra = ini_compra;
        do{
          printf("--------------------------------\n");
          printf("Nome       Valor      Quantidade\n");
          printf("%s      %.2f        %d\n", nome, prox_compra -> valorCompra, prox_compra -> qtdCompra);
          printf("--------------------------------\n");
          prox_compra = prox_compra -> prox; 
          }while(prox_compra != NULL);
      }
    }else if(op == 2){
      printf("Campo em construção\n");
      press(); 
    }else if(op == 3){
      printf("Saindo!\n");
      press();
    }
  }
  return 0; 
}
int menuPrincipal(){
  int op; 
  printf("Insira a opção desejada\n");
  printf("1 - Opcoes de compra\n");
  printf("2 - Opcoes de venda\n");
  printf("3 - Sair\n");
  scanf("%d", &op);
  system("clear || cls");
  return op;
}
int menuOpCompras(){
  int opCompra;
  printf("1 - Para inserir oferta\n");
  printf("2 - Para mostrar ofertas\n");
  printf("3 - Voltar\n");
  scanf("%d", &opCompra); 
  system("clear || cls");
  return opCompra;
}
int inserir_oferta(){
  
}
void press(){
  printf("Pressione para voltar...");
  getchar();
  system("clear || cls");
}