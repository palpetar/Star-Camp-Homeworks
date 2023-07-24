#include <stdio.h>
#include <math.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt);

void print_dest(int dest[], size_t newsize){
    printf("New size: %ld\nArray: ", newsize);
    for(int i = 0; i < newsize; i++){
        printf("%d ", dest[i]);
    }
    printf("\n");
}

int isEven(int a){
    return a % 2 == 0 ? 1 : 0;
}

int isPrime(int num){
    if(num <= 1) return 0;
    if(num == 2 || num == 3) return 1;

    for(int i = 2; i <= sqrt(num);i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int isPositive(int a){
    return a >= 0 ? 1 : 0;
}

int add(int a){
    return a;
}

int addMul(int a){
    return a * a;
}

static int set_bits_counter = 0;

int add_num_set_bits(int a){
    int temp = a;
    while(temp){
        set_bits_counter += temp & 1;
        temp = temp >> 1;
    }
    return a;
}

int main(void){
    int arr[4] = {9, 6, 13, -5};
    int dest[10];
    size_t newsize;
    //filter_and_map(arr, 8, isEven, add, dest, &newsize);
    //filter_and_map(arr, 8, isPrime, addMul, dest, &newsize);
    filter_and_map(arr, 4, isPositive, add_num_set_bits, dest, &newsize);
    print_dest(dest, newsize);
    printf("%d", set_bits_counter);
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt){

    size_t counter = 0;
    for(size_t i = 0; i < n; i++){
        if(filter_f(arr[i]) == 1){
            dest[counter++] = map_f(arr[i]);
        }
    }
    *dest_cnt = counter;
}