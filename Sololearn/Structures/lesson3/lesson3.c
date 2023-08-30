#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char num[20];
    char email[40];
    int idade;
}contato;

void printcontato(contato *ptr);
void registracontato(contato *ptr,char name[50], char num[30], char mail[40], int i);

int main(){
    contato c1;
    registracontato(&c1,"Carlos","35221238","carlos@gmail.com",13);
    printcontato(&c1);

    return 0;
}

void printcontato(contato *ptr){
    printf("Nome: %s\n",ptr->nome);
    printf("Numero: %s\n",ptr->num);
    printf("Email: %s\n",ptr->email);
    printf("Idade: %d\n",ptr->idade);
}

void registracontato(contato *ptr,char name[50], char num[30], char mail[40], int i){
    strcpy(ptr->nome,name);
    strcpy(ptr->num,num);
    strcpy(ptr->email,mail);
    ptr->idade=i;
}