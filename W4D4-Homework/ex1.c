#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_NUM 16

sem_t semaphorec;

void* routine(void *args){
    int *index = (int*)args;
    printf("User [%d] is waiting in queue to enter...\n", *index);
    sem_wait(&semaphorec);
    printf("User [%d] has entered the system...\n", *index);
    sleep(3);
    printf("User [%d] is leaving the system...\n", *index);
    sem_post(&semaphorec);
    printf("User [%d] left the system successfully!\n", *index);
    free(index);
}


int main(void){
    sem_init(&semaphorec, 0, 32);

    pthread_t threads[THREAD_NUM];

    for(int i = 0; i < THREAD_NUM; i++){
        int *index = malloc(sizeof(int));
        *index = i;
        if(pthread_create(threads + i, NULL, routine, index) != 0){
            perror("Error creating thread");
            exit(-1);
        }
        
    }
    
    for (int i = 0; i < THREAD_NUM; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
        perror("Error joining thread");
        exit(-1);
    }
}

    sem_destroy(&semaphorec);
}