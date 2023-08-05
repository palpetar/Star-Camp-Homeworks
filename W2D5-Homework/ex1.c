#include <stdio.h>
#include <inttypes.h>

void swapBytes(uint16_t* word){
    int first = !!((*word) & 1);
    int last = !!((*word) & (1 << 15));
    if(first == 0){
        *word &= ~(1 << 15);
    } else {
        *word |= (1 << 15);
    }
    if(last == 0){
        *word &= ~1;
    } else {
        *word |= 1;
    }

}


void print_binary_number(uint16_t mask) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (mask >> i) & 1);
    }
    printf("\n");
}


int main(void){

    uint16_t mask = 0b1111111111111110;

    printf("Binary number before swap: \n");
    print_binary_number(mask);
    swapBytes(&mask);
    printf("Binary number after swap: \n");
    print_binary_number(mask);

    return 0;
}