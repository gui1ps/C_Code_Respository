#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[20];
    char cor[10];
    char marca[10];

}caracs;

typedef struct no
{
    caracs *caracteristica;
    struct no *prox;
}no;

no* add(no*ptr){
    no* novo=(no*)malloc(sizeof(no));
    printf("\nNOME DO NOVO AVIAO:\n");
    fflush(stdin);
    fgets(novo->caracteristica->nome,20,stdin);
    printf("\nCOR DO NOVO AVIAO:\n");
    fflush(stdin);
    fgets(novo->caracteristica->cor,10,stdin);
    printf("\nMARCA DO NOVO AVIAO:\n");
    fflush(stdin);
    fgets(novo->caracteristica->marca,10,stdin);
    novo->prox=ptr;

    return novo;
}

void ler(no* ptr){
    no* aux=ptr;
    while (aux!=NULL)
    {
        printf("\n-----------------------------\nNOME DO AVIAO: %s\nCOR DO AVIAO: %s\nMARCA DO AVIAO: %s\n-----------------------------\n",aux->caracteristica->nome,aux->caracteristica->cor,aux->caracteristica->marca);
        aux=aux->prox;
    }
    
}

int contar(no* ptr){
    int cont=0;
    for(no* aux=ptr;aux!=NULL;aux=aux->prox){
        cont=cont+1;
    }
    return cont;
}

int matarLista(no*ptr){
    no* prox=ptr->prox;
    free(ptr->caracteristica);
    free(ptr);
    if(prox!=NULL){
    matarLista(prox);
    }else{
        ptr=NULL;
        return 1;
    }
}

void matarUm(no *ptr){
    free(ptr->caracteristica);
    free(ptr);
}

int verVazio(no* ptr){
    if(ptr==NULL){
        return 1;
    }else{
        return 0;
    }
}

no* retornaPrimeiro(no*ptr){
    if(verVazio(ptr)==1){
        return NULL;
    }
    else{
        if(ptr->prox==NULL){
            return ptr;
        }else{
            for(no* aux=ptr;aux!=NULL;aux=aux->prox){
                if(aux->prox->prox==NULL){
                    return aux->prox;
                }
            }
        }
    }
}

void mostrarPrimeiro(no* ptr){
    if(retornaPrimeiro(ptr)==NULL){
        printf("\nA LISTA E VAZIA!!\n");
    }
    else{
        printf("\n NOME DO PRIMEIRO AVIAO: %s\nCOR DO PRIMEIRO AVIAO: %s\nMARCA DO PRIMEIRO AVIAO: %s ",retornaPrimeiro(ptr)->caracteristica->nome,retornaPrimeiro(ptr)->caracteristica->cor,retornaPrimeiro(ptr)->caracteristica->marca);
    }
}

void liberarPrimeiro(no *ptr){
    for(no* aux=ptr;aux!=NULL;aux=aux->prox){
                if(aux->prox==retornaPrimeiro(ptr)){
                    matarUm(retornaPrimeiro(ptr));
                    aux->prox=NULL;
                }
            }
}

int main(){
    int anws;
    no *ptr=NULL;

    do
    {
        printf("\nADICIONAR AVIAO NA FILA [1] | LIBERAR PRIMEIRO AVIAO [2] | LISTAR A QUANTIDADE DE AVIOES NA FILA [3] | LISTAR TODOS OS AVIOES DA FILA [4] | LISTAR CARACTERISTICAS DO PROXIMO AVIAO A DECOLAR [5] | SAIR [0]\n");
        scanf("%d",&anws);
        switch (anws)
        {
        case 1:
            ptr=add(ptr);
            break;
        
        case 2:
            liberarPrimeiro(ptr);
            break;
        
        case 4:
            ler(ptr);
            break;

        case 3:
            printf("QUANTIDADE DE AVIOES: %d",contar(ptr));
            break;

        case 5:
            mostrarPrimeiro(ptr);
            break;

        case 0:
            printf("SAINDO!...");
            matarLista(ptr);
            break;

        default:
            break;
        }
    } while (anws!=0);
    
    
    return 0;
}