#include <stdlib.h>
#include <stdio.h>

void insertionSortIterativo(int num[], int tam);

int main(int argc, int *argv[]){
    int v[] = {25,57,48,37,12,92,86,33};
    int tam = (sizeof(v)/sizeof(int));
    insertionSortIterativo(v, tam);

    return 0;
}

void insertionSortIterativo(int num[], int tam){
    int i,j, chave;
    for(i=1; i<tam; i++){
        chave=num[i];
        j=i-1;

        while(j >=0 && chave < num[j]){ //Enquanto não achar
            num[j+1]=num[j];            //a posição da chave,
            j=j-1;                      //j é determinado.
        }
        num[j+1]=chave; //quando encontrar a posição, insere a chave
    }
}