#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5


typedef struct Book{
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;

int cmp_title_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return strcmp(b1.title, b2.title);
}

int cmp_title_des(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return -(strcmp(b1.title, b2.title));
}

int cmp_author_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return strcmp(b1.author, b2.author);
}

int cmp_author_des(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return -(strcmp(b1.author, b2.author));
}

int cmp_pages_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return b1.pages > b2.pages;
}

int cmp_pages_des(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return !(b1.pages > b2.pages);
}

int cmp_price_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return (b1.price - b2.price)*100;
}

int cmp_price_des(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    return -(b1.price - b2.price)*100;
}

void print_elems(Book *arr){
    for(int i = 0; i < COUNT; i++){
        printf("Title: %s\t\tAuthor: %s\t\tPages: %d\t\tPrice:%.2lf\n", arr -> title, arr -> author, arr -> pages, arr -> price);
        arr++;
    }
    printf("\n");
}

int main(void){

    srand(time(NULL));
    Book *arr = malloc(sizeof(Book) * COUNT);
    const char POSSIBLE_CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < COUNT; i++){
        for(int j = 0; j < 10 + rand()%10; j++){
            arr[i].title[j] = POSSIBLE_CHARS[rand()%strlen(POSSIBLE_CHARS)];
            arr[i].author[j] = POSSIBLE_CHARS[rand()%strlen(POSSIBLE_CHARS)];
        }
        arr[i].pages = 5 + rand()%1996;
        arr[i].price = (100 + rand()%990000)/100;
    }
    
    printf("Original Array:\n");
    print_elems(arr);

    printf("Sorting by title (ascending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_title_asc);
    print_elems(arr);

    printf("Sorting by title (descending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_title_des);
    print_elems(arr);

    printf("Sorting by author (ascending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_author_asc);
    print_elems(arr);

    printf("Sorting by author (descending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_author_des);
    print_elems(arr);

    printf("Sorting by pages (ascending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_pages_asc);
    print_elems(arr);

    printf("Sorting by pages (descending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_pages_des);
    print_elems(arr);

    printf("Sorting by price (ascending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_price_asc);
    print_elems(arr);

    printf("Sorting by price (descending):\n");
    qsort(arr, COUNT, sizeof(Book), cmp_price_des);
    print_elems(arr);



    free(arr);
    return 0;
}