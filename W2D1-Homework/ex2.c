#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8

void printValue(const void* valuePtr, uint8_t flag);

int main(void){

    int i = 23;
    printValue(&i, TINT);
    char c = 'B';
    printValue(&c, TCHAR);
    double d = 3.14;
    printValue(&d, TDOUBLE);
    float f = 5.34;
    printValue(&f, TFLOAT);
    uint8_t i8 = 34;
    printValue(&i8, TUINT8_T);
    uint16_t i16 = 657;
    printValue(&i16, TUINT16_T);
    uint32_t i32 = 54423;
    printValue(&i32, TUINT32_T);
    uint64_t i64 = 64441254;
    printValue(&i64, TUINT64_T);
    return 0;
}

void printValue(const void* valuePtr, uint8_t flag){
    switch(flag){
        case 1:
            int *p_int = valuePtr;
            printf("%d\n", *p_int);
            break;
        case 2:
            char *p_char = valuePtr;
            printf("%c\n", *p_char);
            break;
        case 3:
            double *p_double = valuePtr;
            printf("%.2lf\n", *p_double);
            break;
        case 4:
            float *p_float = valuePtr;
            printf("%.2f\n", *p_float);
            break;
        case 5:
            uint8_t *p_ushort = valuePtr;
            printf("%hu\n", *p_ushort);
            break;
        case 6:
            uint16_t *p_uint = valuePtr;
            printf("%u\n", *p_uint);
            break;
        case 7:
            uint32_t *p_ulong = valuePtr;
            printf("%lu\n", *p_ulong);
            break;
        case 8:
            uint64_t *p_longlong = valuePtr;
            printf("%llu\n", *p_longlong);
            break;
    }
}