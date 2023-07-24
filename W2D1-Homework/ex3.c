#include <stdio.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt);

int isPositive(int a){
    return a > 0 ? 1 : 0;
}

int addOne(int a){
    return a++;
}

int main(void){
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t newsize;
    filter_and_map(arr, 8, isPositive, addOne, dest, &newsize);

    printf("New size: %ld\n Array:", newsize);
    for(int i = 0; i < newsize; i++){
        printf("%d ", dest[i]);
    }
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