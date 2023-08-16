#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void parent_process(int pipe1[2], int pipe2[2], int pipe3[2]) {

}

void process_A(int pipe1[2], int pipe2[2]) {

}

void process_B(int pipe2[2], int pipe3[2]) {

}

int main(void) {
    int pipe1[2], pipe2[2], pipe3[2];

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        exit(1);
    }

    pid_t pid_A = fork();

    if(pid_A == 0){

        pid_t pid_B = fork();
    
        if(pid_B == 0){

        }
    
    } else {

        srand(time(NULL));

        int arr[10];
        for(int i = 0; i < 10; i++){
            arr[i] = 1 + rand()%100;
        }

        
        
    }

}