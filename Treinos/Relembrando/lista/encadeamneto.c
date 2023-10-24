#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no *ptr;
}no;

no* add(no *ptr,int val);

void matarLista(no *ptr){
   while (ptr!=NULL)
   {
    no* prox=ptr->ptr;
    free(ptr);
    ptr=prox;
   }
    
}
void lerLista(no *ptr);

void removerPrimeiro(no *ptr){
    no* aux;
    aux=ptr;

    if(aux->ptr==NULL){
        free(aux);
    }
    else{
        while (aux->ptr->ptr!=NULL)
        {
            aux=aux->ptr;
        }
        free(aux->ptr);
        aux->ptr=NULL;
    }
}

int listaVazia(no*ptr){
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    no *lista=NULL;
    lista=add(lista,10);
    no *aux=lista;
    lista=add(lista,11);
    lista=add(lista,12);
    lerLista(lista);
    printf("\n-------------------\n");
    printf("%d\n",aux->val);
    removerPrimeiro(lista);
    printf("\n-------------------\n");
    printf("%d\n",aux->val);
    printf("\n-------------------\n");
    lerLista(lista);
    return 0;
}

no* add(no *ptr,int val){
    no *new=(no *)malloc(sizeof(no));
    new->val=val;
    new->ptr=ptr;
    return new;
};

void lerLista(no *ptr){
    no *aux=ptr;
    while (aux!=NULL)
    {
        if(aux->ptr!=NULL){
            printf("\nVAL: %d | PROX: %d\n",aux->val,aux->ptr->val);
        }
        else{
            printf("\nVAL: %d | PROX: NULL\n",aux->val);
        }
        aux=aux->ptr;
    }  
}