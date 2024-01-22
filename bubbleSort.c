#include <stdio.h>
#include <stdlib.h>

void bubbleSortIterativo(int *v, int tam);
void passagem(int n, int *v, int tam);

int main(int argc, char *argv[]){
    int v[] = {25,57,48,37,12,92,86,33};
    int tam = (sizeof(v)/sizeof(int));
    passagem(0, v,tam); //exibe o vetor antes da primeira passagem
    bubbleSortIterativo(v,tam);

    return 0;
}

void bubbleSortIterativo(int *v, int tam){
    int troca = 0; //verifica se houve troca
    int aux,i,j;
    for(i=tam-1; i>0; i--){
        troca = 0; //cada nova passagem. troca assume FALSE
        for(j=0; j<i; j++){
            if(v[j] > v[j+1]){ //se a posição atual é maior que
                aux=v[j];      //o próximo, troca ambos
                v[j]=v[j+1];
                v[j+1]=aux;
                troca=1;        //informa que houve troca
            }
        passagem(tam-i, v, tam); //exibe o resultado da passagem
            if(troca==0)   //se não houve troca, v está ordenado e termina
                break;
        }
        }
}

void passagem(int n, int *v, int tam){
    int i;
    printf("Passagem %i:", n);
    for(i=0; i<tam; i++)
        printf("%i", v[i]);
    printf("\n");
}
