#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no* prox;
}no;

int listaVazia(no* ptr){
    if(ptr==NULL){
        return 1;
    }else{
        return 0;
    }
}

int definirNumero(){
    int num;
    printf("VALOR DO NOVO NO: ");
    scanf("%d",&num);
    return num;
}

no* alloc(){
    no*novo_no=(no*)malloc(sizeof(no));
    if(novo_no){
        novo_no->val=definirNumero();
        return novo_no;
    }else{
        printf("FALHA AO ALOCAR NOVO NO!\n");
    }
}

no* add(no* ptr){
    no*novo_no=alloc();
    novo_no->prox=ptr;
    return novo_no;
}

void excluirLista(no* ptr){
    no* aux;
    while (ptr != NULL){
        aux = ptr;
        ptr = ptr->prox;
        free(aux);
    }
}

void lerLista(no* ptr){
    if(!listaVazia(ptr)){
        for(no* aux=ptr;aux!=NULL;aux=aux->prox){
            printf("%d\n",aux->val);
        }
    }else{
        printf("LISTA VAZIA!!\n");
    }
}

int main(){
    no* noh=NULL;
    noh=add(noh);
    noh=add(noh);
    noh=add(noh);
    lerLista(noh);
    excluirLista(noh);
    return 0;
}