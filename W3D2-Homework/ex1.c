#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void printf_time(const char *format, ...){
    

    time_t cur_time;

    time(&cur_time);
    va_list args;
    va_start(args, format); 

    printf("%s", ctime(&cur_time));
    vprintf(format, args);

    va_end(args);
    
}


int main(void){

    printf_time("%d %d", 10, 20);
    return 0;
}