#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(double *arr, int num){
    for(int i = 0; i < num; i++){
        printf("%.1lf ", arr[i]);
    }
    printf("\n");
}

int main(void){
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    double *arr = malloc(sizeof(double) * n);
    for(int i = 0; i < n; i++){
        arr[i] = 0.1 + (double)(rand() % 10) / 10;
    }
    print_arr(arr, n);
    int m;
    scanf("%d", &m);
    m += n;
    arr = realloc(arr, sizeof(double) * m);
    for(int i = n; i < m; i++){
        arr[i] = 0.1 + (double)(rand() % 10) / 10;
    }
    print_arr(arr, m);
    int p;
    scanf("%d", &p);
    p += m;
    arr = realloc(arr, sizeof(double) * p);
    for(int i = m; i < p; i++){
        arr[i] = 0.1 + (double)(rand() % 10) / 10;
    }
    print_arr(arr, p);
    free(arr);
    return 0;
}