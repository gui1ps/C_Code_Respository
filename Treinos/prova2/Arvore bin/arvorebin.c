#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no* direito;
    struct no* esquerdo;
}no;

typedef struct arvore{
    no*raiz;
}arvore;

no* alloc(){
    no* novo_no=(no*)malloc(sizeof(no));
    novo_no->direito=NULL;
    novo_no->esquerdo=NULL;
    printf("VALOR: \n");
    scanf("%d",&novo_no->val);
    return novo_no;
}

arvore* iniciar(){
    arvore *nova_arvore=(arvore*)malloc(sizeof(arvore));
    no* raiz=alloc();
    nova_arvore->raiz=raiz;
    return nova_arvore;
}


void posicionar_no(no *ptr,no* novo_no){
    if(novo_no->val>ptr->val){
        if(ptr->direito==NULL){
            ptr->direito=novo_no;
        }
        else{
            posicionar_no(ptr->direito,novo_no);
        }
    }else{
        if(ptr->esquerdo==NULL){
            ptr->esquerdo=novo_no;
        }
        else{
            posicionar_no(ptr->esquerdo,novo_no);
        }
    }
}

void add_no(no *ptr){
    no* novo_no=alloc();
    posicionar_no(ptr,novo_no);
}

void imprimir(no* no){
    if(no != NULL){

        if(no->esquerdo!=NULL){
        printf("\n%d<--",no->esquerdo->val);
        }

        printf("{%d}",no->val);

        if(no->direito!=NULL){
            printf("-->%d\n",no->direito->val);
        }

        imprimir(no->esquerdo);
        imprimir(no->direito);
    }
}

void liberar(no* ptr){
    if(ptr->direito!=NULL){
        liberar(ptr->direito);
    }
    if(ptr->esquerdo!=NULL){
        liberar(ptr->esquerdo);
    }
    free(ptr);
}

int main(){
    arvore* arvore=iniciar();
    add_no(arvore->raiz);
    add_no(arvore->raiz);
    add_no(arvore->raiz);
    add_no(arvore->raiz);
    add_no(arvore->raiz);
    add_no(arvore->raiz);
    imprimir(arvore->raiz);
    liberar(arvore->raiz);
    return 0;
}