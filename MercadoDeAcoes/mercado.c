#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc mercado.c -o mercado -Wno-unused-result
//Menus
int menuPrincipal(); 
int menuOpCompras(); 
int vendas();
void limpar(); 
void limparComPause();
typedef struct Acoes{
  int qtdCompra;
  float valorCompra;
  struct Acoes *prox; 
} acoesCompra;

void inserir_Compras();
void listar_compras();

acoesCompra *petraCompra, *petraVenda;

int main(void){
  acoesCompra *ini_compra = NULL;
  acoesCompra *prox_compra = NULL;
  int opPrincipal = 0;
  int opCompra; 
  ini_compra = (acoesCompra*)malloc(sizeof(acoesCompra));
  while(opPrincipal != 4){
    
    printf("Digite a opção que deseja\n");
    printf("(1) - Oferta de compra\n");
    printf("(2) - Oferta de venda\n");
    printf("(3) - Listar ofertas\n");
    printf("(4) - Sair\n");
    scanf("%d", &opPrincipal); 
    getchar();
    limpar();
    switch(opPrincipal){
      case 1:{
        printf("(1) - Inserir oferta de compra\n");
        printf("(2) - Listar ofertas de compra\n");
        printf("(3) - Voltar\n");
        scanf("%d", &opCompra);
        switch(opCompra){
          case 1:{
            if(ini_compra == NULL)
              exit(1); 
            prox_compra = ini_compra;
            inserir_Compras(&ini_compra, &prox_compra);
            limparComPause();
            break;
          }
          case 2:{
            listar_compras(ini_compra, prox_compra); 
            limparComPause();
            break;
          }
          default:{

            break; 
          }
        }
        limparComPause();
        break;
      }
      case 2:{
        printf("Venda\n");
        limparComPause(); 
        break;
      }
      case 3:{
        printf("Listagem\n");
        limparComPause();
        break;
      }
      default:{
        printf("Saindo\n");
        limpar();  
        break;
      }
    break; 
    }
  }
}

void inserir_Compras(acoesCompra *ini_compra, acoesCompra *prox_compra){
  int resp; 
  printf("Insira a quantidade da compra: ");
  scanf("%d", &prox_compra->qtdCompra);
  printf("Insira o valor da compra: ");
  scanf("%f", &prox_compra->valorCompra);
  prox_compra -> prox = (acoesCompra*)malloc(sizeof(acoesCompra));
  prox_compra = prox_compra -> prox; 
  
}

void listar_compras(acoesCompra *ini_compra, acoesCompra *prox_compra){
  char nome[10] = "SemNome"; 
  prox_compra -> prox = NULL;
  prox_compra = ini_compra;
  while(prox_compra != NULL){
    printf("--------------------------------\n");
    printf("Nome       Valor      Quantidade\n");
    printf("%s    %.2f        %d\n", nome, prox_compra -> valorCompra, prox_compra -> qtdCompra);
    printf("--------------------------------\n");
    prox_compra = prox_compra -> prox; 
    }
}


void limpar(){
  system("clear || cls"); 
}
void limparComPause(){
  printf("Clique para voltar...\n");
  getchar(); 
  system("clear || cls"); 
}