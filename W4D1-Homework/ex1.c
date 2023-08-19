#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define ARRAY_SIZE 10

void parent_process(int pipe1[2], int pipe2[2], int pipe3[2]) {
    srand(time(NULL));
    int *arr = malloc(sizeof(int) * ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand()%100;
    }
    if(write(pipe1[1], arr, sizeof(int) * ARRAY_SIZE) == -1){
        perror("Write to A failed");
        exit(-1);
    }
    int result;
    if(read(pipe3[0], &result, sizeof(result)) == -1){
        perror("Read from B failed");
        exit(-1);
    }
    printf("%d", result);
    free(arr);
}

void process_A(int pipe1[2], int pipe2[2]) {
    int *arr;
    if(read(pipe1[0], arr, sizeof(int) * ARRAY_SIZE) == -1){
        perror("Read from Parent failed");
        exit(-1);
    }
    int sum = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        sum += arr[i];
    }
    if(write(pipe2[1], &sum, sizeof(sum)) == -1){
        perror("Write to B failed");
        exit(-1);
    }
    
}

void process_B(int pipe2[2], int pipe3[2]) {
    int sum;
    if(read(pipe2[0], &sum, sizeof(sum)) == -1){
        perror("Read from A failed");
        exit(-1);
    }
    sum *= sum;
    if(write(pipe3[1], &sum, sizeof(sum)) == -1){
        perror("Write to parent failed");
        exit(-1);
    }
}

int main(void) {
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Pipe creation failed.");
        exit(-1);
    }

    pid_t pid_A = fork();

    if(pid_A == 0){
        
        process_A(pipe1, pipe2);

        pid_t pid_B = fork();
    
        if(pid_B == 0){
            process_B(pipe2, pipe3);
        }
    
    } else {
        parent_process(pipe1, pipe2, pipe3);
    }

}