#include <stdio.h>
#include <stdlib.h>
#define TAM 10


// gcc pilha.c -o pilha


void push();
int pop();
void imprimePilha(); 
void limpar();

int pilha[TAM];
int topo = 0; 
int main(void){
  int op, numero;
  int resp = 0;
  
  while(resp != 4){
    printf("(1) - Push    (2) - Pop    (3) - Pilha    (4) - Sair\n");
    scanf("%d", &op);
    switch(op){
      case 1:
        printf("Insira um numero: ");
        scanf("%d", &numero);
        push(numero); 
        limpar(); 
        break;
      case 2:
        pop(); 
        limpar();
        break;
      case 3:
        limpar();
        imprimePilha();
        printf("Clique para voltar...\n");
        getchar(); 
        getchar(); 
        limpar();
        break; 
      default:
        resp = 4;
        printf("Encerrando..."); 
        break; 
    }
  }
}

void push(int a){
  pilha[topo] = a; //pilha[topo++] = a; 
  topo++;
}

int pop(){
  int x;
  topo--;
  x = pilha[topo];
  return x; //return pilha[--topo]; 
}

void imprimePilha(){
  int i;
  for(i = 0; i < topo; i++){
    printf("%d\n", pilha[i]); 
  }
}

void limpar(){
  system("clear || cls");
}

