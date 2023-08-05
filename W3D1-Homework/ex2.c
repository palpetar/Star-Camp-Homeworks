#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int *arr;
    size_t capacity, cur_elem_count;
} Stack;

Stack init_stack(size_t n) {
    Stack res;
    res.capacity = n;
    res.cur_elem_count = 0;
    res.arr = (int *)calloc(n, sizeof(int));
    return res;
}

int push(Stack *s, int data) {
    if (s -> cur_elem_count < s -> capacity) {
        s -> arr[s->cur_elem_count] = data;
        s -> cur_elem_count++;
        return 0;
    } else {
        return -1;
    }
}

int pop(Stack *s) {
    if (s -> cur_elem_count <= 0) {
        return -1;
    } else {
        int elem = s -> arr[s -> cur_elem_count - 1];
        s -> cur_elem_count--;
        return elem;
    }
}

void print_elems(Stack s) {
    for (int i = 0; i < s.cur_elem_count; i++) {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}

int result_reverse_polish_notation(char *input){
    Stack s = init_stack(strlen(input));

    char *token = strtok((char *)input, " ");

    while(token){
        if((strcmp(token, "+") == 0) || (strcmp(token, "-") == 0 || (strcmp(token, "*") == 0))){
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            if (strcmp(token, "+") == 0) {
                push(&s, operand1 + operand2);
            } else if (strcmp(token, "-") == 0) {
                push(&s, operand1 - operand2);
            } else {
                push(&s, operand1 * operand2);
            }
        } else{
            int num = atoi(token);
            push(&s, num);
        }
        token = strtok(NULL, " ");
    }

    int result = pop(&s);
    free(s.arr);
    return result;

}

int main(void){

    char input[100];
    scanf("%s", input);

    int result = result_reverse_polish_notation(input);
    printf("Result: %d\n", result);

    return 0;
}