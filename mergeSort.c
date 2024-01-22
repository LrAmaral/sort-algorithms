#include <stdio.h>
#include <stdio.h>

void merge(int vec[], int vecSize);
void mergeSort(int vec[], int vecSize);

int main(int argc, int *argv[]){
    int v[] = {25,57,48,37,12,92,86,33};
    int tam = (sizeof(v)/sizeof(int));

    mergeSort(v,tam);
    merge(v,tam);

    system("PAUSE");
    return 0;
}

void mergeSort(int vec[], int vecSize){
    int mid;
    if(vecSize > 1){                        //Se o vetor tem tamanho > 1
        mid = vecSize/2;                    // mid = valor do meio do vetor
        mergeSort(vec,mid);                 //chama mergeSort para a 1a. metade
        mergeSort(vec + mid, vecSize - mid); //chama mergeSort para a 2a. metade
        merge(vec,vecSize);                  //aplica o merge para unir as metades
    }
}

void merge(int vec[], int vecSize){
    int mid, i, j, k;                   //recebe o vetor e seu tamanho
    int *tmp;

    tmp = (int *) malloc(vecSize * sizeof(int));  //Aloca um vetor temporário de mesmo tamanho
    if(!tmp) exit(1);                             //servirá para receber os valores ordenados

    mid = vecSize/2; //calcula o meio do vetor
    i=0;
    j=mid;
    k=0; //k controlará a próxima posição a receber um valor ordenado em tmp

    while(i < mid && j < vecSize)   //enquanto i não chegou ao meio e j não chegou ao final
        if(vec[i] <= vec[j])        //caso o valor da primeira metade (i) seja menor que o 
            tmp[k++] = vec[i++];    // valor da segunda metade (j), então o vetor temporário
        else                        //tmp na posição(k) recebe o valor da primeira metade,1
            tmp[k++] = vec[j++];    //caso contrário, da segunda metade e incrementa i ou j + k

    if(i==mid)                      //caso i==mid, então todos os valores da primeira metade já estão em tmp,
        while(j < vecSize)          //portanto basta copiar todos os valores da segunda metade (j) para tmp
            tmp[k++] = vec[j++];    //enquanto incrementa j e k
    else                            //se i != mid, então todos os valores da segunda metade já estão em tmp,
        while(i < mid)              //então basta copiar todos da primeira metade (i) para tmp
            tmp[k++] = vec[i++];    //incrementando i e k
    
    for(i=0; i<vecSize; i++)        //transfere os valores ordenados em tmp de volta para o vetor original
        vec[i] = tmp[i];

    free(tmp);                      //desaloca o vetor temporário
}

