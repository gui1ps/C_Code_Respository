#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    union
    {
        char cpf[30];
        char rg[30];
    }id;
    
}pessoa;



int main(){
    pessoa p1;
    strcpy(p1.id.rg,"321");
    strcpy(p1.id.cpf,"123");

    printf("%s\n",p1.id.cpf);
    printf("%s\n",p1.id.rg);
    return 0;
}