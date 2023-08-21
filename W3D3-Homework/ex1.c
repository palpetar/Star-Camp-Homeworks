#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

typedef struct Deque {
    Node *front, *rear;
    int size, capacity;
} Deque;

Deque* init_deque(int n){
    Deque *arr = malloc(sizeof(Deque) * n);
    arr -> capacity = n;
    arr -> size = 0;
    arr -> front = NULL;
    arr -> rear = NULL;
    return arr;
}

void insert_front(Deque *arr, int val){
    
    if(arr -> size == arr -> capacity){
        perror("Deque is already full");
        exit(-1);
    }
    Node *new_node = malloc(sizeof(Node));
    new_node -> data = val;
    if(arr -> size == 0){
        new_node -> prev = NULL;
        new_node -> next = NULL;
        arr -> front = new_node;
        arr -> rear = new_node;
        arr -> size = arr -> size + 1;
    } else {
        new_node -> prev = NULL;
        new_node -> next = arr -> front;
        arr -> front -> prev = new_node;
        arr -> size = arr -> size + 1;
    }
}

void insert_rear(Deque *arr, int val){
    if(arr -> size == arr -> capacity){
        perror("Deque is already full");
        exit(-1);
    }
    Node *new_node = malloc(sizeof(Node));
    new_node -> data = val;
    if(arr -> size == 0){
        new_node -> prev = NULL;
        new_node -> next = NULL;
        arr -> front = new_node;
        arr -> rear = new_node;
        arr -> size = arr -> size + 1;
    } else {
        new_node -> next = NULL;
        new_node -> prev = arr -> rear;
        arr -> rear -> next = new_node;
        arr -> size = arr -> size + 1;
    }
}

int pop_front(Deque *arr){
    if(arr -> size <= 0){
        perror("Empty Deque");
        exit(-1);
    }

    int result = arr -> front -> data;
    if(arr -> size == 1){
        free(arr -> front);
        arr -> front = NULL;
        arr -> rear = NULL;
        arr -> size = 0;
    } else {
        arr -> front -> next -> prev == NULL;
        free(arr -> front);
    }

    return result;
}

int pop_rear(Deque *arr){
    if(arr -> size <= 0){
        perror("Empty Deque");
        exit(-1);
    }
    int result = arr -> rear -> data;
    if(arr -> size == 1){
        free(arr -> front);
        arr -> front = NULL;
        arr -> rear = NULL;
        arr -> size = 0;
    } else {
        arr -> rear -> prev -> next == NULL;
        free(arr -> rear);
    }

    return result;
}

void print_deque(Deque *arr) {
    Node *current = arr->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void){

    Deque *deque = init_deque(5);

    insert_front(deque, 5);
    insert_front(deque, 10);
    insert_front(deque, 15);

    insert_rear(deque, 20);
    insert_rear(deque, 25);

    printf("Deque after inserts:\n");
    print_deque(deque);

    int front_value = pop_front(deque);
    printf("Popped from front: %d\n", front_value);

    int rear_value = pop_rear(deque);
    printf("Popped from rear: %d\n", rear_value);

    printf("Deque after pops:\n");
    print_deque(deque);
    return 0;
}