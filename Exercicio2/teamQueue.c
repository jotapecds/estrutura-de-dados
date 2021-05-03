#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
    int value;
    struct Element* next;
    int team_index;
} typedef element_t;

void printList(element_t *head){
    element_t* temp = head;

    while(temp != NULL){
        printf(" -> %d", temp->value);
        temp = temp->next;    
    }
}

int main(void){

    element_t *head, e1, e2, e3;

    e1.value = 24;
    e2.value = 10;
    e3.value = 54;

    head = &e3;
    e3.next = &e2;
    e2.next = &e1;
    e1.next = NULL;

    printList(head);


    // int tam_total_vet = 10000,
    //     tam_atual_vet = 0,
    //     linha,
    //     *vet = (int *) malloc(tam_total_vet * sizeof(int));

    // if(vet == NULL){   
    //     printf("Erro! Memoria insuficiente");
    //     return 0;
    // }

    // while (scanf("%d", &linha) == 1){
    //     vet[tam_atual_vet] = linha;
    //     tam_atual_vet++;
    // }

    // for(int i=0; i<tam_atual_vet; i++){
    //     printf("Linha %d -> %d \n", i, vet[i]);
    // }

    return 0;
}