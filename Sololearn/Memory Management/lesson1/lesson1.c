#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

typedef struct
{
    char nome[30];
    int id;
}aluno;

void consultanome(aluno *ptr);
void definenome(aluno *ptr,char nome[30]);

int main(){
    aluno a1;
    aluno *ptr=&a1;
    definenome(ptr,"Guilherme");
    consultanome(ptr);
    return 0;
}

void consultanome(aluno *ptr){
    printf("NOME: %s",ptr->nome);
}
void definenome(aluno *ptr,char nome[30]){
    strcpy(ptr->nome,nome);
}