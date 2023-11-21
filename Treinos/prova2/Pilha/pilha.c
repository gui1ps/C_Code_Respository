#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//CONTEXTO DO CÓDIGO: PILHA DE FUNCIONÁRIO PARA LIBERAR

typedef struct funcionario{
    char nome[20];
    struct funcionario* prox;
}funcionario;

typedef struct pilha{
    funcionario* ultimo;
}pilha;

char* definirNome(){
    char* nomeRand=(char*)malloc(20*sizeof(char));
    printf("PRIMEIRO NOME DO FUNCIONARIO: ");
    fgets(nomeRand,20,stdin);
    return nomeRand;
}

funcionario* alloc(){
    funcionario* novo_funcionario=(funcionario*)malloc(sizeof(funcionario));
    strcpy(novo_funcionario->nome,definirNome());
    novo_funcionario->prox=NULL;
    return novo_funcionario;
}

pilha* iniciarPilha(){
    pilha* nova_pilha=(pilha*)malloc(sizeof(pilha));
    nova_pilha->ultimo=alloc();
    return nova_pilha;
}

int pilhaVazia(pilha* pilha){
    if(pilha->ultimo==NULL){
        return 1;
    }else{
        return 0;
    }
}

void adicionar(pilha* pilha){
    funcionario* aux=pilha->ultimo;
    pilha->ultimo=alloc();
    pilha->ultimo->prox=aux;
}

void remover(pilha* pilha){
    if(!pilhaVazia(pilha)){
        if(pilha->ultimo->prox!=NULL){
            funcionario* aux=pilha->ultimo->prox;
            free(pilha->ultimo);
            pilha->ultimo=aux;
        }else{
            free(pilha->ultimo);
            pilha->ultimo=NULL;
        }
    }else{
        printf("A PILHA ESTA VAZIA!\n");
    }
}

void lerPilha(pilha* pilha){
    if(!pilhaVazia(pilha)){
        for(funcionario*aux=pilha->ultimo;aux!=NULL;aux=aux->prox){
            printf("%s\n",aux->nome);
        }
    }else{
        printf("A PILHA ESTA VAZIA!\n");
    }
}

void liberarPilha(pilha* pilha){
    while (!pilhaVazia(pilha))
    {
            remover(pilha);
    }
    free(pilha);
}

int main(){
    pilha* minhaPilha = iniciarPilha();

    adicionar(minhaPilha);
    adicionar(minhaPilha);
    adicionar(minhaPilha);
    lerPilha(minhaPilha);

    printf("-------\n");
    remover(minhaPilha);
    lerPilha(minhaPilha);
    printf("-------\n");
    
    remover(minhaPilha);
    remover(minhaPilha);
    remover(minhaPilha);
    lerPilha(minhaPilha);
    printf("-------\n");

    liberarPilha(minhaPilha);
    return 0;
}