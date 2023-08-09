#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <math.h>

int main(void){

    int fd[3][2];

    for(int i = 0; i < 3; i++){
        if(pipe(fd[i]) == -1){
            perror("Error running pipe");
            exit(-1);
        }
    }


    int pid = fork();

    int myValue;

    if(pid == 0){
        int pid_2 = fork();

        if(pid_2 == 0){
            
            close(fd[0][0]);
            close(fd[0][1]);
            close(fd[1][1]);
            close(fd[2][0]);

            if(read(fd[1][0], &myValue, sizeof(myValue)) == -1){
                perror("Error running read in CHILD_2");
                exit(-1);
            }
            
            if(myValue % 2 == 0){
                myValue = pow(myValue, 2);
            } else {
                myValue /= 2;
            }

            if(write(fd[2][1], &myValue, sizeof(myValue)) == -1){
                perror("Error running read in CHILD_2");
                exit(-1);
            }

            close(fd[1][0]);
            close(fd[2][1]);

        } else {

            close(fd[1][0]);
            close(fd[0][1]);
            close(fd[2][0]);
            close(fd[2][1]);


            if(read(fd[0][0], &myValue, sizeof(myValue)) == -1){
                perror("Error running read in CHILD_1");
                exit(-1);
            }

            myValue *= 3;

            if(write(fd[1][1], &myValue, sizeof(myValue)) == -1){
                perror("Error running write in CHILD_1");
                exit(-1);
            }

            close(fd[0][0]);
            close(fd[1][1]);
        }

    } else {

        close(fd[0][0]);
        close(fd[1][0]);
        close(fd[1][1]);
        close(fd[2][1]);

        myValue = 7;

        if(write(fd[0][1], &myValue, sizeof(myValue)) == -1){
            perror("Error running write in PARENT");
            exit(-1);
        }

        if(read(fd[2][0], &myValue, sizeof(myValue)) == -1){
            perror("Error running read in CHILD_2");
            exit(-1);
        }
        printf("%d", myValue);

        close(fd[0][1]);
        close(fd[2][0]);


    }



    return 0;
}