#include <stdlib.h>
#include <stdio.h>

void selection_sort(int num[], int tam);

int main (int argc, int *argv[]){
    int v[] = {25,57,48,37,12,92,86,33};
    int tam = (sizeof(v)/sizeof(int));
    selection_sort(v, tam);

    sytem("PAUSE");
    return 0;
}

void selection_sort(int num[], int tam){
    int i, j, min, aux;
    for (i = 0; i < (tam-1); i++){
        min = i;
        for (j = (i+1); j < tam; j++){
            if(num[j] < num[min])
                min = j;

            if(i != min){
                aux = num[i];
                num[i] = num[min];
                num[min] = aux;
            }
        }
    }
}