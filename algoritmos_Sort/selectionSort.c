#include <stdio.h>
#define tam 5

//gcc selectionSort.c -o selection
void selectionSort(int vetor[]); 
int main(void)
{
    int vetor[] = {8, 7, 5, 3, 1}; 
    int menor, i;
    printf("Antes da ordenação - ");
    for(i = 0; i < tam; i++){
        if(vetor[i] != vetor[tam - 1]){
          printf("%d, ", vetor[i]);
        } else
          printf("%d", vetor[i]);
    }
    selectionSort(vetor);
}

void selectionSort(int vetor[]){
    int i, j, aux;
    int min_posicao;
    for(j = 0; j < tam; j++){
        min_posicao = j; 
        for(i = j; i < tam; i++){
        if(vetor[i] < vetor[min_posicao])
            min_posicao = i; 
        }
        if(vetor[j] > vetor[min_posicao]){
            aux = vetor[j];
            vetor[j] = vetor[min_posicao];
            vetor[min_posicao] = aux; 
        }
    }
    
    
    printf("\nDepois da ordenação - ");
    for(i = 0; i < tam; i++){
        if(vetor[i] != vetor[tam - 1]){
          printf("%d, ", vetor[i]);
        } else
          printf("%d", vetor[i]);
    }
}