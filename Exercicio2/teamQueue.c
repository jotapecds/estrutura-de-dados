#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int value;
  struct Node *next;
} typedef node_t;

struct Queue {
  node_t *head; 
  node_t *tail;
} typedef queue_t;

struct Team {
    int team_index;
    int num_elements;
    int* elements;
} typedef team_t;

node_t* create_new_node(int value) {
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

queue_t* create_new_queue(){
    queue_t *new_queue = (queue_t*) malloc(sizeof(queue_t));
    new_queue->head = new_queue->tail = NULL;
    return new_queue;
}

void enqueue(queue_t* queue, int value){
    node_t *temp = create_new_node(value);
  
    // Se a fila estiver vazia, o elemento inserido será tanto o primeiro quanto o último da fila
    if (queue->tail == NULL) {
        queue->head = queue->tail = temp;
        return;
    }
  
    // Caso contrário, a cauda atual passa a apontar para a nova cauda
    queue->tail->next = temp;
    queue->tail = temp;
}

void dequeue(queue_t* queue){
    if (queue->head == NULL) return;
  
    // Armazena a cabeça atual e move a fila um nó para frente
    node_t* temp = queue->head;
    queue->head = queue->head->next;
  
    // Caso a nova cabeça seja nula, significa que a fila está vazia
    if (queue->head == NULL)
        queue->tail = NULL;
  
    free(temp);
}

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