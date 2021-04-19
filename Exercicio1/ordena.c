/**
* $ gcc -o ordena ordena.c -Wall
* $ ./ordena < 1.in
*/

#include <stdio.h>
#include <stdlib.h>

int bubble_sort (int vet[], int tam);
int merge_sort(int vet[], int esq, int dir);
int merge(int vet[], int esq, int meio, int dir);
int quick_sort(int *a, int inicio, int fim);
int particionar(int *a, int inicio, int final);

int main(int argc, char *argv[]) {

    int tam_total_vet = 10000,
        tam_atual_vet = 0,
        linha,

        *vet = (int *) malloc(tam_total_vet * sizeof(int));

    if(vet == NULL) {
        printf("Erro! Memoria insuficiente");
         return 0;
    }

    while (scanf("%d", &linha) == 1){
        vet[tam_atual_vet] = linha;
        tam_atual_vet++;
    }

    if(argc == 1){
        if(!bubble_sort(vet, tam_atual_vet))
            printf("Erro!");
    }
    else if(strcmp(argv[1], "-m") == 0){
        if(!merge_sort(vet, tam_atual_vet))
            printf("Erro!");
    }
    else if(strcmp(argv[1], "-q") == 0){
        if(!quick_sort(vet, tam_atual_vet))
            printf("Erro!");
    }

    for(int i = 0; i < tam_atual_vet; i++){
        printf("%d \n", vet[i]);
    }

    return 0;
}