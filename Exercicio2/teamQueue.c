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
    int num_of_elements;
    int* elements;
} typedef team_t;

node_t* create_new_node(int value){
  node_t *new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

queue_t* create_new_queue(){
    queue_t *new_queue = (queue_t*) malloc(sizeof(queue_t));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

void enqueue(queue_t* queue, int value){
    node_t *new_node = create_new_node(value);

    // Se a cabeça for nula insere o novo elemento no começo da fila
    if(queue->head == NULL)
        queue->head = new_node;

    // Se a cauda não for nula significa que que já existe ao menos 1 elemento na fila, dessa forma podendo linka-lo com a nova cauda inserida
    if (queue->tail != NULL){
        queue->tail->next = new_node;
    } 
    
    printf("\nEnfileirando %d", new_node->value);
    queue->tail = new_node;
}

void dequeue(queue_t* queue){
    if (queue->head == NULL) return; 
  
    // Salva a cabeça atual para liberar a memória e move a fila um nó para frente
    node_t* temp = queue->head;

    printf("\nRemovendo: %d", queue->head->value);
    queue->head = queue->head->next;
  
    // Caso a nova cabeça seja nula, significa que a fila está vazia
    if (queue->head == NULL)
        queue->tail = NULL;
  
    free(temp);
}

void fill_teams(team_t *teams[], int num_teams){
    int num_of_elements;

    for (int i = 0; i < num_teams; i++){

        scanf("%d", &num_of_elements);
        team_t *new_team = (team_t*) malloc(sizeof(team_t));

        new_team->team_index = i;
        new_team->num_of_elements = num_of_elements;
        new_team->elements = (int*) malloc(sizeof(int) * num_of_elements);

        for (int j = 0, element; j < num_of_elements; j++){
            scanf("%d", &element);
            new_team->elements[j] = element;
        }

        teams[i] = new_team;
    }
}

void print_queue(queue_t *queue){
    node_t* temp = queue->head;

    printf("\nMinha fila:\n");
    while(temp != NULL){
        printf(" -> %d", temp->value);
        temp = temp->next;
    }
}

int main(void){
    int scenario = 1, num_teams;

    do {
        printf("Scenario #%d\n", scenario);

        // Lendo a quantidade de times e estabelecendo o critério de parada do programa
        scanf("%d", &num_teams);
        printf("%d", num_teams);

        if(num_teams == 0) exit(0);

        // Criando a estrutura de times
        team_t *teams[num_teams];
        teams[num_teams] = (team_t*) malloc(sizeof(team_t) * num_teams);

        queue_t *queue = create_new_queue();

        fill_teams(teams, num_teams);
        //commandsLoop(queue, teams);

        // Libera o espaco dos ponteiros usados
        free(queue);
        free(teams[num_teams]);

        // Incrementa o cenario
        scenario++;
        printf("\n");
    } while (num_teams != 0);

    return 0;
}