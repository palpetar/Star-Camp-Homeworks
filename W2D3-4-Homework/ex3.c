#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef struct Point{
    double x;
    double y;
    double z;
} Point;

typedef struct Human{
    double weight_kg;
    uint16_t height_cm;
} Human;

void* findMax(void *arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){

    void *result = arr;

    for(size_t i = 1; i < n; i++){
        if(cmp(result, arr) == 1){
            result = arr;
        }
        arr+=elem_s;
    }    
    return result;

}

int cmpInt(const void* a, const void* b){
    return *(int*)a > *(int*)b ? -1 : 1; 
}

int cmpUInt64(const void* a, const void* b){
    return *(uint64_t*)a > *(uint64_t*)b ? -1 : 1;
}

int cmpDist(const void* a, const void* b){
    Point p1 = *(Point*)a;
    Point p2 = *(Point*)b;
    double dist1 = sqrt(pow(p1.x, 2) + pow(p1.y, 2) + pow(p1.z, 2));
    double dist2 = sqrt(pow(p2.x, 2) + pow(p2.y, 2) + pow(p2.z, 2));
    return dist1 > dist2 ? -1 : 1;
}

int cmpBMI(const void* a, const void* b){
    Human h1 = *(Human*)a;
    Human h2 = *(Human*)b;
    double bmi1 = h1.weight_kg / ((h1.height_cm * h1.height_cm / 10000));
    double bmi2 = h2.weight_kg / ((h2.height_cm * h2.height_cm / 10000));
    return bmi1 > bmi2 ? 1 : -1;
}

int main(void){

    /* int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
	int* max = findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
	printf("%d", *max);	// should print 100 
    */


    /* uint64_t arr[] = {12, 453, 5642245, 10, 5464, 75656};
    uint64_t *max = findMax(arr, sizeof(arr)/sizeof(uint64_t), sizeof(uint64_t), cmpUInt64);

    printf("%lu", *max);
    */
/* 	
    Point arr[] = {
    {1.5, 2.3, 4.8},
    {9.2, 6.1, 3.7},
    {0.0, 5.5, 2.2},
    {7.3, 8.9, 1.0},
    {3.6, 4.1, 6.9}
    };  
    Point *max = findMax(arr, sizeof(arr)/sizeof(Point), sizeof(Point), cmpDist);
    printf("Point with biggest distance: x: %.2lf, y: %.2lf, z: %.2lf", max -> x, max -> y, max -> z);
 */

    Human arr[] = {
    {70.5, 175},
    {62.0, 160},
    {80.2, 185},
    {55.7, 150},
    {90.0, 195}
    };
    Human *max = findMax(arr, sizeof(arr)/sizeof(Human), sizeof(Human), cmpBMI);
    printf("Human smallest BMI: Weight: %.2lf, Height: %d", max -> weight_kg, max -> height_cm);

    return 0;
}