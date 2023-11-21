#include <stdio.h> 
#include <stdlib.h>

typedef struct no{
    int val;
    struct no* prox;
}no;

typedef struct fila
{
    no* primeiro;
    no* ultimo;
}fila;

int setval(){
    int randomVal;
    printf("VALOR: "); 
    scanf("%d",&randomVal);
    return randomVal;
}

no* alloc(){
    no* novno_no=(no*)malloc(sizeof(no));
    novno_no->val=setval();
    novno_no->prox=NULL;
    return novno_no;
}

fila* iniciarFila(){
    fila* nova_fila=(fila*)malloc(sizeof(fila));
    nova_fila->primeiro=nova_fila->ultimo=alloc();
    return nova_fila;
}

int filaVazia(fila* fila){
    if(fila->primeiro==NULL){
        return 1;
    }else{
        return 0;
    }
}

void add(fila* fila){
    if(filaVazia(fila)==1){
        fila->primeiro=fila->ultimo=alloc();
    }else{
        fila->ultimo=fila->ultimo->prox=alloc();
    }
}

void remover(fila* fila){
    if(fila->primeiro->prox!=NULL){
        no* aux=fila->primeiro->prox;
        free(fila->primeiro);
        fila->primeiro=aux;
    }else{
        free(fila->primeiro);
        fila->primeiro=NULL;
    }
}

void ler(fila* fila){
    if(filaVazia(fila)==1){
        printf("A FILA ESTA VAZIA!\n");
    }else{
        for(no*aux=fila->primeiro;aux!=NULL;aux=aux->prox){
            printf("%d\n",aux->val);
        }
    }
}

void liberarFila(fila* fila){
    for(no*aux=fila->primeiro;aux!=NULL;aux=aux->prox){
            free(aux);
        }
}

int main(){
    //AINDA NÃO FOI FEITO UM MENU POIS ESTOU APENAS TESTANDO
    fila* fila=iniciarFila();
    add(fila);
    add(fila);
    add(fila);
    ler(fila);
    printf("----------\n");
    remover(fila);
    ler(fila);
    printf("----------\n");
    remover(fila);
    remover(fila);
    remover(fila);
    ler(fila);
    printf("----------\n");
    add(fila);
    ler(fila);
    printf("----------\n");
    remover(fila);
    ler(fila);
    printf("----------\n");
    liberarFila(fila);
    free(fila);
    return 0;
}