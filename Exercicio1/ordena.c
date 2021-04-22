/**
* Aluno: João Pedro Coelho de Souza
* DRE 119152051 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bubble_sort (int vet[], int tam){
    if(vet == NULL || tam < 0)
        return 1;

    int aux;

    for (int i = 1; i < tam; i++){
        for (int j = 0; j < tam - i; j++){
            if (vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    return 0;
}

int merge(int vet[], int esq, int meio, int dir){
    int i = esq,
        j = meio,
        k = 0,
        tam = dir - esq;

    int *aux = (int*) malloc(tam * sizeof(int));

    while(i < meio && j < dir){
        if(vet[i] <= vet[j])
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    }

    while(i < meio)
        aux[k++] = vet[i++];

    while(j < dir)
        aux[k++] = vet[j++];

    for (i = esq; i < dir; ++i)
        vet[i] = aux[i-esq];

    free(aux);

    return 0;
}

int merge_sort(int vet[], int esq, int dir){
    if(vet == NULL || esq < 0 || dir < 0)
        return 1;

    int meio;
    if (esq < dir - 1){
        meio = (esq + dir) / 2;

        merge_sort(vet, esq, meio);
        merge_sort(vet, meio, dir);

        merge(vet, esq, meio, dir);
    }
    return 0;
}

int partition(int vet[], int ini, int fim){
    int pivot = vet[fim],
        i = ini,
        aux;

    for(int j = ini; j < fim; j++){
        if(vet[j] <= pivot){
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
            i++;
        }
    }

    aux = vet[i];
    vet[i] = vet[fim];
    vet[fim] = aux;

    return i;
}

int quick_sort(int vet[], int ini, int fim){
    if(vet == NULL || ini < 0 || fim < 0)   
        return 1;

    int pivot;
    if(fim > ini){
        pivot = partition(vet, ini, fim - 1);
        quick_sort(vet, ini, pivot - 1);
        quick_sort(vet, pivot + 1, fim);
    }

    return 0;
}

int main(int argc, char *argv[]){

    int tam_total_vet = 10000,
        tam_atual_vet = 0,
        linha,
        *vet = (int *) malloc(tam_total_vet * sizeof(int));

    if(vet == NULL){   
        printf("Erro! Memoria insuficiente");
        return 0;
    }

    while (scanf("%d", &linha) == 1){
        vet[tam_atual_vet] = linha;
        tam_atual_vet++;
    }

    if(argc == 1){
        if(bubble_sort(vet, tam_atual_vet) == 1){
            printf("Erro!");
            return 0;
        }
    }
    else if(strcmp(argv[1], "-m") == 0){
        if(merge_sort(vet, 0, tam_atual_vet) == 1){
            printf("Erro!");
            return 0;
        }
    }
    else if(strcmp(argv[1], "-q") == 0){
        if(quick_sort(vet, 0, tam_atual_vet) == 1){
            printf("Erro!");
            return 0;
        }
    }

    for(int i = 0; i < tam_atual_vet; i++){
        printf("%d \n", vet[i]);
    }

    return 0;
}