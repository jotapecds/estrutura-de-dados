/**
* $ gcc -o ordena ordena.c -Wall
* $ ./ordena < 1.in
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int *vet = (int *) malloc(10000 * sizeof(int));
    int i = 0;
    int linha;

    while (scanf("%d", &linha) == 1){
        vet[i] = linha;
        // printf("-> %d\n", vet[i]);
        i++;
    }



    return 0;
}