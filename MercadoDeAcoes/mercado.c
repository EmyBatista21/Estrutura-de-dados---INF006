#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc mercado.c -o mercado -Wno-unused-result
// Protótipos das funções
// Menus
int menuPrincipal();
int menuCompras();
int vendas();
void limpar();
void limparComPause();
void inserir_Compras();
void listar_compras();

// Cria um tipo para guardar os dados das ações
typedef struct Acoes {
  int qtdCompra;
  float valorCompra;
  struct Acoes *prox;
} acoesCompra;

// Cria duas opções de transação do tipo acoes
acoesCompra *petraCompra, *petraVenda;

// Função principal, chamada de subfunções 
int main(void) {
  int i = 0;
  // Cria um ponteiro para o inicio da lista e para o proximo
  acoesCompra *ini_compra = NULL;
  acoesCompra *prox_compra = NULL;
  int opPrincipal = 0;
  int opCompra;
  // Aloca espaço na memória para o inicio da lista
  ini_compra = (acoesCompra *)malloc(sizeof(acoesCompra));

  // Repete até que o usuário queira sair (4)
  while (opPrincipal != 4) {
    // Menu Principal
    opPrincipal = menuPrincipal();
    switch (opPrincipal) {
      case 1: {
        // Menu de Compras
        opCompra = menuCompras();
        switch (opCompra) {
          case 1: {
            if (i > 0) {
              prox_compra->prox = (acoesCompra *)malloc(sizeof(acoesCompra));
              prox_compra = prox_compra->prox;
            }
            i++;
            if (ini_compra == NULL)
              exit(1);
            prox_compra = ini_compra;
            inserir_Compras(&ini_compra, &prox_compra);
            limparComPause();
            break;
          }
          case 2: {
            listar_compras(ini_compra, prox_compra);
            getchar();
            limparComPause();
            break;
          }
          default: {
            break;
          }
        }
        //limparComPause();
        break;
      }
      case 2: {
        printf("Venda\n");
        limparComPause();
        break;
      }
      case 3: {
        printf("Listagem\n");
        limparComPause();
        break;
      }
      default: {
        printf("Saindo\n");
        limpar();
        break;
      } 
    }
    break;
  }
}

int menuPrincipal(){
  int opPrincipal;
  printf("Digite a opção que deseja\n");
  printf("(1) - Oferta de compra\n");
  printf("(2) - Oferta de venda\n");
  printf("(3) - Listar ofertas\n");
  printf("(4) - Sair\n");
  scanf("%d", &opPrincipal);
  getchar();
  limpar();
  return opPrincipal; 
}

int menuCompras(){
  int opCompra; 
  printf("(1) - Inserir oferta de compra\n");
  printf("(2) - Listar ofertas de compra\n");
  printf("(3) - Voltar\n");
  scanf("%d", &opCompra);
  return opCompra; 
}

void inserir_Compras(acoesCompra *ini_compra, acoesCompra *prox_compra) {
  int resp;
  printf("Insira a quantidade da compra: ");
  scanf("%d", &prox_compra->qtdCompra);
  printf("Insira o valor da compra: ");
  scanf("%f", &prox_compra->valorCompra);
  /*prox_compra->prox = (acoesCompra *)malloc(sizeof(acoesCompra));
  prox_compra = prox_compra->prox;*/
}

void listar_compras(acoesCompra *ini_compra, acoesCompra *prox_compra) {
  char nome[10] = "SemNome";
  prox_compra->prox = NULL;
  prox_compra = ini_compra;
  do {
    printf("--------------------------------\n");
    printf("Nome       Valor      Quantidade\n");
    printf("%s      %.2f        %d\n", nome, prox_compra->valorCompra, prox_compra->qtdCompra);
    printf("--------------------------------\n");
    prox_compra = prox_compra->prox;
  } while (prox_compra != NULL);
}

void limpar() { 
  system("clear || cls"); 
}
void limparComPause() {
  printf("Clique para voltar...\n");
  getchar();
  system("clear || cls");
}