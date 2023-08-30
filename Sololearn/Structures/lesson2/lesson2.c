#include <stdio.h>
#include <stdlib.h>

struct person{
    char name[50];
};

void printobject(struct person *st){
    printf("NAME: %s",st->name);
}

int main(){
    struct person p1;
    gets(p1.name);
    printobject(&p1);
    return 0;
}