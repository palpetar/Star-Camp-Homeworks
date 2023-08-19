#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREADS 7
#define INIT_BALANCE 1000


typedef struct BankAccount{
    int balance;
} BankAccount;

BankAccount account;
pthread_mutex_t myMutex;

void* deposit(void *arg){
    int amount = *(int*)arg;
    pthread_mutex_lock(&myMutex);
    account.balance += amount;
    pthread_mutex_unlock(&myMutex);
}

void* withdraw(void *arg){
    int amount = *(int*)arg;
    pthread_mutex_lock(&myMutex);
    account.balance -= amount;
    pthread_mutex_unlock(&myMutex);
}

int main(void){

    account.balance = INIT_BALANCE;

    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&myMutex, NULL);

    int deposit_amount = 200;
    int withdraw_amount = 150;
    
    for(int i = 0; i < NUM_THREADS; i++){
        if(i % 2 == 0){
            pthread_create(&threads[i], NULL, &deposit, &deposit_amount);
        } else{
            pthread_create(&threads[i], NULL, &withdraw, &withdraw_amount);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("%d", account.balance);
    pthread_mutex_destroy(&myMutex);


    return 0;
}