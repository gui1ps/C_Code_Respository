#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr=calloc(1,sizeof(*ptr));
    printf("---SEM VALOR COLOCADO---\n");
    printf("LOCAL: %p\n",ptr);
    printf("CONTEUDO: %d\n",*ptr);
    printf("---VALOR COLOCADO---\n");
    *ptr=50;
    printf("LOCAL: %p\n",ptr);
    printf("CONTEUDO: %d\n",*ptr);
    printf("---LIBERADO---\n");
    ptr=realloc(ptr,2*(sizeof(*ptr)));
    printf("LOCAL: %p\n",ptr);
    printf("CONTEUDO: %d\n",*ptr);
    printf("------\n");
    printf("LOCAL: %p\n",(ptr+4));
    printf("CONTEUDO: %d\n",*(ptr+4));
    return 0;
}