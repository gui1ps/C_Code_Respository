#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *direita,*esquerda;
    
}no;

no* iniciar(no *raiz,int num){
    if(raiz==NULL){
        no *aux=(no*)malloc(sizeof(no));
        aux->valor=num;
        aux->direita=NULL;
        aux->esquerda=NULL;

        return aux;
    }
    else{
        if(num<raiz->valor){
            raiz->esquerda=iniciar(raiz->esquerda,num);
        }
        else{
            raiz->direita=iniciar(raiz->direita,num);
        }
        return raiz;
    }
}

void imprimirV1(no *raiz){
    if(raiz){
        printf("%d\n",raiz->valor);
        imprimirV1(raiz->esquerda);
        imprimirV1(raiz->direita);
    }
}

void imprimirV2(no *raiz){
    if(raiz){
        imprimirV2(raiz->esquerda);
        printf("%d\n",raiz->valor);
        imprimirV2(raiz->direita);
    }
}

int main(){
    no *raiz=NULL;
    int op,valor;

    do{

        printf("\nINSERIR [1] | IMPRIMIR [2] | SAIR [0]\n");
        fflush(stdin);
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            printf("\nDIGITE UM VALOR: \n");
            fflush(stdin);
            scanf("%d",&valor);
            raiz=iniciar(raiz,valor);
            break;
        case 2:
            printf("\nPRIMEIRA IMPRESSAO:\n");
            imprimirV1(raiz);
            printf("\nSEGUNDA IMPRESSAO:\n");
            imprimirV2(raiz);
            printf("\n");
            break;
        case 0:
            printf("SAINDO!");
        default:
            printf("INVÁLIDO!");
            break;
        }

    }while (op!=0);
    
    return 0;
}