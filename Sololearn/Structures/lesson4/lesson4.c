#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char titulo[20];
   char descricao[200];
   int dia,mes,ano,id;
}tarefa;

typedef struct
{
   tarefa lis[50];
}lista_tarefa;

int incluir(lista_tarefa *ptr,tarefa t);
void print_tarefas(lista_tarefa *ptr);


int main(){
    lista_tarefa l1;
    tarefa t1={"Tarefa 1","Descricao da tarefa 1",10,10,2010,23};
    incluir(&l1,t1);
    print_tarefas(&l1);
    return 0;
}

int incluir(lista_tarefa *ptr,tarefa t){
    static int index=0;
    if(index<=50){
        ptr->lis[index]=t;
        index++;
    }
    else{
        printf("Impoissivel incluir mais contatos na sua lista!");
    }
}

void print_tarefas(lista_tarefa *ptr){
    for(int i=0;i<50;i++){
        printf("\n%s\n",ptr->lis[i].titulo);
        printf("%s\n",ptr->lis[i].descricao);
        printf("%d/%d/%d\n",ptr->lis[i].dia,ptr->lis[i].mes,ptr->lis[i].ano);
        printf("%d\n",ptr->lis[i].id);
        printf("-------------------\n");
    }
}