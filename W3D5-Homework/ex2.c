#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    char filename[100];

    scanf("%s", filename);

    FILE *file;
    file = fopen(filename, "r");
    if(file != NULL){
        fclose(file);
        perror("File already exists");
        exit(-1);
    }
    file = fopen(filename, "w");

    for(int i = 1; i < argc; i++){
        char *current = argv[i];
        fputs(current, file);
        fputc('\n', file);
    }


    fclose(file);
    return 0;
}