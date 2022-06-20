#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc mercado.c -o exe -Wno-unused-result

struct Acoes
{
  int qtd;
  float val;
	struct Acoes *prox;
};
typedef struct Acoes acoes;

float cotacoes[3] = {0, 0, 0};
int anular = 0, resto = 0, tr = 0;

acoes *petr4c = NULL;
acoes *petr4v = NULL;
acoes *itsa4c = NULL; 
acoes *itsa4v = NULL;
acoes *usim5c = NULL; 
acoes *usim5v = NULL;



//---------------------------------------------------------------------------------------------
/*INSERÇÃO DE OFERTAS DE COMPRA E VENDAS*/
void inserirCompra(acoes **p, float valor, int quantidade){
  acoes *aux, *novo = malloc(sizeof(acoes));

    if(novo){
        novo->val = valor;
        novo->qtd = quantidade;

        if(*p == NULL){ // Se a lista estiver vazia
            novo->prox = NULL;
            *p = novo;
        }
        else if(novo->val > (*p)->val){ // Se o novo valor for menor que o valor atual
            novo->prox = *p;
            *p = novo;
        }
        else{ // Se a lista não for nula e o novo valor for maior, insere nas proximas posições da lista para inserir na ordem crescente
            aux = *p;
            while(aux->prox && novo->val < aux->prox->val)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//---------------------------------------------------------------------------------------------

void inserirVenda(acoes **p, float valor, int quantidade){
  acoes *aux, *novo = malloc(sizeof(acoes));  

    if(novo){
        novo->val = valor;
        novo->qtd = quantidade;
        
        if(*p == NULL){ // Se a lista estiver vazia
            novo->prox = NULL;
            *p = novo;
        }
        else if(novo->val < (*p)->val){ // Se o novo valor for menor que o valor atual
            novo->prox = *p;
            *p = novo;
        }
        else{ // Se a lista não for nula e o novo valor for maior, insere nas proximas posições da lista para inserir na ordem crescente
            aux = *p;
            while(aux->prox && novo->val > aux->prox->val)
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//---------------------------------------------------------------------------------------------

acoes *compra(float Val, int Qtd , acoes *ptr, int num){
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) { 
		if (busca->val <= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n-------------------------------\n");
      printf("| TRANSAÇÃO REALIZADA: $%.2f |\n", cotacoes[num]);
      printf("-------------------------------\n");
      printf("-> %.2f & %.2f\n", Val, busca->val);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        printf("> %d\n",Qtd);
        return ptr;
      }
      else{
        if (anterior != NULL){ //primeiro elemento da lista
          tr = 1;
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  }
        else{
          tr = 1;
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  };
      }
		};
    tr = 0;
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//---------------------------------------------------------------------------------------------

acoes *venda(float Val, int Qtd , acoes *ptr, int num){
	acoes* busca; 
	acoes* anterior;
	anterior = NULL;
	busca = ptr;
	while (busca != NULL) {
		if (busca->val >= Val) {
      cotacoes[num] = (busca->val - Val)/2 + Val;
      printf("\n-------------------------------\n");
      printf("| TRANSAÇÃO REALIZADA: $%.2f |\n", cotacoes[num]);
      printf("-------------------------------\n");
      printf("-> %.2f & %.2f\n", busca->val, Val);
      if(busca->qtd > Qtd){
        busca->qtd = busca->qtd - Qtd;
        anular = 1;
        printf("> %d",Qtd);
        return ptr;
      }
      else{
        if (anterior != NULL){
          tr = 1;
          resto = Qtd - busca->qtd;
				  anterior->prox = busca -> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  }
        else{
          tr = 1;
          resto = Qtd - busca->qtd;
				  ptr = busca-> prox;
          anular = 0;
          printf("> %d", busca->qtd);
				  return ptr;
			  };
      }
		};
    tr = 0;
    resto = Qtd;
    anular = 0;
		anterior = busca;
		busca = busca->prox;
	}
  return ptr;
}

//---------------------------------------------------------------------------------------------

void consulta_ofertas(acoes* p1, acoes* p2, char* nome){
	acoes *referencia;
  int cCont = 1;
  int vCont = 1;
  printf("\n###############################\n");
  if(nome == "PETR4"){
    printf("Cotação para %s: %.2f\n", nome, cotacoes[0]);
  }else if(nome == "ITSA4"){
    printf("Cotação para %s: %.2f\n", nome, cotacoes[1]);
  }else{
    printf("Cotação para %s: %.2f\n", nome, cotacoes[3]);
  }
  printf("-------------------------\n");
  printf("---------------------------------\n");
  printf("|            COMPRA             |\n");
  printf("---------------------------------\n");
	for(referencia= p2;referencia!= NULL; referencia=referencia->prox){
		if(referencia->qtd != 0){
      printf("  %d  |  %s  |  %d  |  %.1f  |\n", cCont, nome, referencia ->qtd, referencia ->val); 
      printf("--------------------------------\n");
      cCont++;
    }
	}
  printf("---------------------------------\n");
  printf("|             VENDA             |\n");
  printf("---------------------------------\n");
  for(referencia= p1;referencia!= NULL; referencia=referencia->prox){
    if(referencia->qtd != 0){
		  printf("  %d  |  %s  |  %d  |  %.1f  |\n", vCont, nome, referencia ->qtd, referencia ->val); 
      printf("--------------------------------\n");
      vCont++;
    }
	}
  printf("Pressione Para Voltar...");
  getchar();
  system("clear || cls");
}

//---------------------------------------------------------------------------------------------

int menu(){
  int opcao;
  printf("____________________________\n");
  printf("|    DISCIPLINA - INF006    |\n");
  printf("|ALUNA - EMELI SILVA BATISTA|\n");
  printf("|  MATRICULA - 20212160052  |\n");
  printf("----------------------------\n");
  printf("  ||                   ||   \n");
  printf("----- MERCADO SIMULADO -----\n");
  printf("(1) - Inserir oferta de compra\n");
  printf("(2) - Inserir oferta de venda\n");
  printf("(3) - Carregar ofertas via arquivo\n");
  printf("(4) - Consultar ofertas\n");
  printf("(5) - Sair\n");
	scanf("%d",&opcao);
  system("clear || cls");
  return opcao;
}

//---------------------------------------------------------------------------------------------
void titulos(){
  printf("(1) - PETR4\n(2) - ITSA4\n(3) - USIM5\n(4) - Voltar\n->");
}
//---------------------------------------------------------------------------------------------


int main() {
	int opcao = 0;
  
  while(opcao != 5){
    opcao = menu();
    switch(opcao){
      case 1:{ // Referente a compra de titulos
        int tit, q;
        float v;
        printf("\nDeseja comprar qual título?: \n");
        titulos();
        scanf("%d",&tit);
        getchar();
        switch(tit){ // Compras
          case 1:{ // Caso queira comprar Petra4
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor que deseja comprar as ações: ");
            scanf("%f",&v);
            getchar();
            petr4v = compra(v, q, petr4v, 0);
            if(anular == 0 && tr == 0){
              inserirCompra(&petr4c, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirCompra(&petr4c, v, resto);
            };
            consulta_ofertas(petr4v, petr4c, "PETR4");
            break;
          }
          case 2:{ // Caso queira comprar Itsa4 
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor que deseja comprar as ações ");
            scanf("%f",&v);
            getchar();
            itsa4v = compra(v, q, itsa4v, 1);
            if(anular == 0 && tr == 0){
              inserirCompra(&itsa4c, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirCompra(&itsa4c, v, resto);
            };
            consulta_ofertas(itsa4v, itsa4c, "ITSA4");
            break;
          }
          case 3:{ // Caso queira comprar Usim5
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor de cada ação: ");
            scanf("%f",&v);
            getchar();
            usim5v = compra(v, q, usim5v, 2);
            if(anular == 0 && tr == 0){
              inserirCompra(&usim5c, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirCompra(&usim5c, v, resto);
            };
            consulta_ofertas(usim5v, usim5c, "USIM5");
            break;
          }
          case 4:{ // Voltar para o menu principal
            system("clear || cls"); 
            break;
          }
        }
        break;
      }
      case 2:{ // Vendas
        int tit, q;
        float v;
        printf("Deseja vender qual título?: \n");
        titulos();
        scanf("%d",&tit);
        getchar();
        switch(tit){ // Caso queira vender Petra4
          case 1:{
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor de cada ação: ");
            scanf("%f",&v);
            getchar();
            petr4c = venda(v, q, petr4c, 0);
            if(anular == 0 && tr == 0){
              inserirVenda(&petr4v, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirVenda(&petr4v, v, resto);
            };
            consulta_ofertas(petr4v, petr4c, "PETR4");
          break;
          }
          case 2:{ // Caso queira vender Itsa4
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor de cada ação: ");
            scanf("%f",&v);
            getchar();
            itsa4c = venda(v, q, itsa4c, 1);
            if(anular == 0 && tr == 0){
              inserirVenda(&itsa4v, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirVenda(&itsa4v, v, resto);
            };
            consulta_ofertas(itsa4v, itsa4c, "ITSA4");
          break;
          }
          case 3:{ // Caso queira vendar Usim5
            printf("Informe a quantidade de ações: ");
            scanf("%d",&q);
            getchar();
            printf("Informe o valor de cada ação: ");
            scanf("%f",&v);
            getchar();
            usim5c = venda(v, q, usim5c, 2);
            if(anular == 0 && tr == 0){
              inserirVenda(&usim5v, v, q);
            }
            else if(anular == 0 && tr == 1){
              inserirVenda(&usim5v, v, resto);
            };
            consulta_ofertas(usim5v, usim5c, "USIM5");
            break;
          }
          default:{
            system("clear || cls");
            break;
          }
        }
        break;
      }
      case 3:{
        int qt;
        float vl;
        FILE *ofs;
        int tit, tipo;
        printf("\nDeseja carregar de qual título?: \n");
        titulos();
        scanf("%d",&tit);
        getchar();
        switch(tit){
          case 1:{
            printf("(1) - COMPRA    (2) - VENDA   (3) - VOLTAR\n-> ");
            scanf("%d",&tipo);
            getchar();
            switch(tipo){
              case 1:{
                if((ofs = fopen("arquivos/petr4C.txt","r")) != NULL) { //*Inserir mais titulos* 
                  fscanf(ofs,"%d%f",&qt, &vl);
                  petr4v = compra(vl, qt, petr4v, 0);
                  if(anular == 0 && tr == 0){
                    inserirCompra(&petr4c, vl, qt);
                  }
                  else if(anular == 0 && tr == 1){
                    inserirCompra(&petr4c, vl, resto);
                  };
                  consulta_ofertas(petr4v, petr4c, "PETR4");
                }
                fclose(ofs);
                break;
              }
              case 2:{
                if((ofs = fopen("arquivos/petr4V.txt","r")) != NULL) {
                  fscanf(ofs,"%d%f",&qt, &vl);
                  petr4c = venda(vl, qt, petr4c, 0);
                  if(anular == 0 && tr == 0){
                    inserirVenda(&petr4v, vl, qt);
                  }
                  else if(anular == 0 && tr == 1){
                    inserirCompra(&petr4v, vl, resto);
                  };
                  consulta_ofertas(petr4v, petr4c, "PETR4");
                }
                fclose(ofs);
                break;
              }
              default:{
                system("clear || cls");
                break; 
              }
            }
            break;
          }
          case 2:{
            break;
          }
          default:{
            system("clear || cls");
            break;
          }
        }
        break;
      }
      case 4:{
        int tit;
        printf("Deseja consultar qual título?: \n");
        titulos();
        scanf("%d",&tit);
        getchar();
        switch(tit){
          case 1:{
            printf("\n-\n-\n-\n-\n-\n");
            consulta_ofertas(petr4v, petr4c, "PETR4");
            break;
          }
          case 2:{
            printf("\n-\n-\n-\n-\n-\n");
            consulta_ofertas(itsa4v, itsa4c, "ITSA4");
            break;
          }
          case 3:{
            printf("\n-\n-\n-\n-\n-\n");
            consulta_ofertas(usim5v, usim5c, "USIM5");
            break;
          }
          default:{
            system("clear || cls");
            break;
          }
        }
        break;
      }
      default:{
        acoes *petr4c = NULL;
        free(petr4c); 
        free(petr4v);
        free(itsa4c);
        free(itsa4v);
        free(usim5c);
        free(usim5v);
        printf("Saindo..\n");
        return 0;
      }
    }
  }
}