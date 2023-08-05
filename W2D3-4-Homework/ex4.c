#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    
    if(maskArr == NULL){
        perror("Pointer to NULL");
        exit(-1);
    }

    for(size_t i = 0; i < nitems; i++){
        maskArr[i] = maskArr[i] & ~(1 << bit_index);
    }

    return 0;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    
    if(maskArr == NULL){
        perror("Pointer to NULL");
        exit(-1);
    }

    for(size_t i = 0; i < nitems; i++){
        maskArr[i] = maskArr[i] | (1 << bit_index);
    }

    return 0;
}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index){

    int flag = 0;
    int prev_flag = 0;

    for(size_t i = 1; i < len; i++){
        flag = !!(maskArr[i] & (1 << bit_index));
        prev_flag = !!(maskArr[i - 1] & (1 << bit_index));
        if(flag != prev_flag){
            return -1;
        }
    }

    return flag;

}

void print_binary_array(uint32_t *arr, size_t nitems) {
    for (size_t i = 0; i < nitems; i++) {
        printf("arr[%ld]: ", i);
        for (int j = 31; j >= 0; j--) {
            printf("%d", (arr[i] >> j) & 1);
        }
        printf("\n");
    }
}

int main(void) {
    uint32_t arr[] = { 0b11111111111111111111111111111111
    , 0b10101010101010101010101010101010
    , 0b01010101010101010101010101010101
    };

    size_t nitems = sizeof(arr) / sizeof(arr[0]);

    printf("Before clearBits:\n");
    print_binary_array(arr, nitems);

    size_t bit_index_to_clear = 4;

    clearBits(arr, nitems, bit_index_to_clear);

    printf("After clearBits:\n");
    print_binary_array(arr, nitems);

    printf("Before setBits:\n");
    print_binary_array(arr, nitems);

    size_t bit_index_to_set = 8; 

    setBits(arr, nitems, bit_index_to_set);

    printf("After setBits:\n");
    print_binary_array(arr, nitems);
    size_t bit_index_to_check = 9;

    int result = checkBits(arr, nitems, bit_index_to_check);

    printf("checkBits result for bit at index %ld: %d\n", bit_index_to_check, result);

    return 0;
}
