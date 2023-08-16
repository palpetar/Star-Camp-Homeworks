#include <stdio.h>
#include <stdlib.h>

void fun(char *filename){
    FILE *file;

    file = fopen(filename, "r");
    char current = 1;
    while((current = fgetc(file)) != EOF){
        printf("%c", current);
    }
    
}

int main(int argc, char* argv[]){

    if(argc <= 1){
        printf("%s\n", argv[0]);
    } else {
        for(int i = 1; i < argc; i++){
            fun(argv[i]);
        }
    }

}