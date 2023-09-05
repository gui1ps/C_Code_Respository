#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int spaces;
    int *elements;
}dy_arr;

void increment(dy_arr *arr){
    arr->spaces++;
    arr->elements=realloc(arr->elements,arr->spaces);
}

int main(){
    dy_arr arr;
    arr.spaces=1;
    arr.elements=calloc(arr.spaces,(sizeof(arr.elements)));
    arr.elements[0]=50;
    increment(&arr);

    for(int i=0; i<arr.spaces;i++)
        printf("ELEMENTO %d: %d\n",i,arr.elements[i]);

    return 0;
}