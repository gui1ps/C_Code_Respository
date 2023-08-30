#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union 
{
   int x;
   char y;
}teste;

void modifica(teste *ptr);



int main(){
    teste t1;
    teste *ptr=&t1;
    modifica(ptr);
    printf("%d\n",t1.x);
    printf("%c\n",t1.y);
    return 0;
}

void modifica(teste *ptr){
    ptr->x=10;
    ptr->y='o';
}