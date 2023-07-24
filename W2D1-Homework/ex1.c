#include <stdio.h>

double cube_root(double a);

int main(void){
    double number = 64;

    double result = cube_root(number);
    printf("%.2lf", result);

    return 0;
}

double cube_root(double input){

    if(input == 0) return 0;
    if(input < 0) return -cube_root(-input);

    double approximation = input / 3;

    for(int i = 0; i < 100; i++){
        approximation = (2 * approximation + input / (approximation * approximation)) / 3;
        //approximation = approximation - (approximation * approximation * approximation - input) / (approximation * approximation) / 3;
    }

    return approximation;
}
