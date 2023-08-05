#include <stdio.h>
#include <inttypes.h>


typedef struct my_double{
    uint64_t mantissa: 52;
    uint64_t exponent: 11;
    uint64_t sign: 1;
} my_double;

typedef union D{
    double d;
    my_double b;
} D;

void print_bits(uint64_t number, size_t nbits){
    for(size_t i = nbits; i > 0; i--){
        printf("%ld", (number >> (i - 1)) & 1);
    }
    printf(" ");
}

void print_double_bits(double num){
    D val;
    val.d = num;
    printf("Bits of double %lf:\n", num);
    print_bits(val.b.sign, 1);
    print_bits(val.b.exponent, 11);
    print_bits(val.b.mantissa, 52);
    printf("\n");
}

void print_double_decimal(double num){
    D val;
    val.d = num;
    printf("Sign: %lu\n", val.b.sign);
    printf("Exponent: %lu\n", val.b.exponent);
    printf("Mantissa: %lu\n", val.b.mantissa);
}

int main(void){

    print_double_bits(3.14);
    print_double_decimal(3.14);
    return 0;
}