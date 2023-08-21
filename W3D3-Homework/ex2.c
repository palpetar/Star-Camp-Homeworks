#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int val;
} Data;

typedef struct Node{
    Data d;
    struct Node *next;
} Node;

typedef struct LL{
    Node *head;
    Node *tail;
} LL;


void print_linked_list(LL *ll){
    Node *head = ll -> head;
    if(head == NULL){
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    printf("%d ", head -> d.val);
    while((head -> next) != NULL){
        head = head -> next;
        printf("%d ", head -> d.val);
    }
    printf("\n");
}

void push_back(Data data, LL *ll){

    Node **head = &(ll -> head);
    Node **tail = &(ll -> tail);
    Node *n = malloc(sizeof(Node));
    n -> d = data;
    n -> next = NULL;

    if(*head == NULL){        
        *head = n;
        *tail = n;
        return;
    }

    (*tail) -> next = n;
    *tail = (*tail) -> next;
}

void push_front(Data data, LL *ll){
    Node **head = &(ll -> head);
    Node *n = malloc(sizeof(Node));
    n -> d = data;
    if(*head == NULL){
        n -> next = NULL;
        *head = n;
        ll -> tail = n;
    } else {
        n -> next = *head;
        *head = n;
    }
}

void pop_back(LL *ll, Data *result){
    Node **head = &(ll -> head);
    Node **tail = &(ll -> tail);
    if(!(*head)){
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    if((*head) -> next == NULL){
        *result = (*head) -> d;
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    Node *cur_node = *head;
    while(cur_node -> next -> next != NULL){
        cur_node = cur_node -> next;
    }
    *result = cur_node -> next -> d;
    free(cur_node -> next);
    cur_node -> next = NULL;
    *tail = cur_node;

}

void pop_front(LL *ll, Data *result){
    Node **head = &(ll->head);

    if(*head == NULL) {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    
    if(result != NULL) {
        *result = (*head)->d;
    }
    Node *second_node = (*head)->next;
    free(*head);
    *head = second_node;

    if(*head == NULL) {
        ll->tail = NULL;
    }
}

LL* init_linked_list(){
    LL *ll = (LL*)malloc(sizeof(LL));
    if(!ll){ // If NULL pointer
        perror("Could not malloc\n");
        exit(-1);
    }
    ll -> head = NULL;
    ll -> tail = NULL;
    return ll;
}

void deinit_linked_list(LL *ll){
    while(!ll->head){
        pop_front(ll, NULL);
    }
    free(ll);
}