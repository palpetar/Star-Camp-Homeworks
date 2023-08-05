#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define COUNT 5

typedef struct Book{
    char title[150];
    char author[100];
    int pages;
    double price;
} Book;

void fill_arr(Book *arr){
    const char POSSIBLE_CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    for(int i = 0; i < COUNT; i++){
        for(int j = 0; j < 10 + rand()%10; j++){
            arr[i].title[j] = POSSIBLE_CHARS[rand()%strlen(POSSIBLE_CHARS)];
            arr[i].author[j] = POSSIBLE_CHARS[rand()%strlen(POSSIBLE_CHARS)];
        }
        arr[i].pages = 5 + rand()%1996;
        arr[i].price = (100 + rand()%90000)/100;
    }
}

int cmp_title_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;

    return b1.title[0] - b2.title[0];
}

int cmp_title_dsc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;

    return -(b1.title[0] - b2.title[0]);
}

int cmp_author_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;

    return b1.author[0] - b2.author[0];
}

int cmp_author_dsc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    
    return -(b1.author[0] - b2.author[0]);
}


int cmp_pages_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    
    return b1.pages - b2.pages;
}

int cmp_pages_dsc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    
    return -(b1.pages - b2.pages);
}

int cmp_price_asc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    
    return (b1.price > b2.price) ? 1 : -1;
}

int cmp_price_dsc(const void *a, const void *b){
    Book b1 = *(Book*)a;
    Book b2 = *(Book*)b;
    
    return (b1.price > b2.price) ? -1 : 1;
}


void print_elems(Book *arr){
    for(int i = 0; i < COUNT; i++){
        printf("Title: %s\t\tAuthod: %s\t\tPages: %d\t\tPrice:%.2lf\n", arr -> title, arr -> author, arr -> pages,arr -> price);
        arr++;
    }
    printf("\n");
}


int main(void){
    Book *arr = malloc(sizeof(Book) * COUNT);

    fill_arr(arr);

    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_title_asc);
    printf("Sorted by title (ascending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_title_dsc);
    printf("Sorted by title (descending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_author_asc);
    printf("Sorted by author (ascending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_author_dsc);
    printf("Sorted by author (descending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_pages_asc);
    printf("Sorted by pages (ascending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_pages_dsc);
    printf("Sorted by pages (descending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_price_asc);
    printf("Sorted by price (ascending):\n");
    print_elems(arr);

    qsort(arr, COUNT, sizeof(Book), cmp_price_dsc);
    printf("Sorted by price (descending):\n");
    print_elems(arr);

    free(arr);


    return 0;
}