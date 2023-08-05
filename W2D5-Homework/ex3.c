#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <string.h>
#define ID_LEN 10


typedef struct Person{
    char name[100];
    char id[ID_LEN];
    unsigned short birthYear;
    unsigned char birthMonth;
    unsigned char birthDay;
    char gender;
} Person;

srand = (time(NULL));

void* init_array(size_t capacity){
    Person *arr = malloc(sizeof(Person) * capacity);
    return arr;
}

int addPerson(Person *arr, char *name, unsigned short birthYear, unsigned char birthDay, char gender){
    
    Person p_to_add = malloc(sizeof(Person));
    p_to_add = { name, "TdDDsfAAst", birthYear, (rand()%12 + 1), birthDay, gender};
    arr++ = &p_to_add;
    return 0;
}

int removePerson(Person *arr, char *id){
    
    while(arr){
        if(strcmp(arr -> id, id) == 0){
            free(*arr);
            return 0;
        }
    }

    return -1;

}

void readPerson(Person *arr){
    Person p_to_add = malloc(sizeof(Person));
    scanf("%s %s %hu %hhu %hhu %c", &p_to_add.name, &p_to_add.id, &p_to_add.birthYear, &p_to_add.birthMonth, &p_to_add.birthDay, &p_to_add.gender);
    arr++ = &p_to_add;
}

int printPerson(Person *arr, char *id){
    while(arr){
        if(strcmp(arr -> id, id) == 0){
            printf("Name: %s\n", person->name);
            printf("ID: %s\n", person->id);
            printf("Birth Date: %hu-%hhu-%hhu\n", person->birthDay, person->birthMonth, person->birthYear);
            printf("Gender: %c\n", person->gender);
            return 0;
        }
    }
    return -1;
}

int main(void){

    

    return 0;
}