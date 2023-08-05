#include <stdio.h>

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

int main(void){

    int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
	int* max = findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
	printf("%d", *max);	// should print 100
	return 0;
 

}