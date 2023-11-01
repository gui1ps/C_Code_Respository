#include <stdlib.h>
#include <stdio.h>

typedef struct noh
{
    int val;
    int nivel;
    struct noh *esquerda;
    struct noh *direita;
    struct noh *anterior;
}noh;

typedef struct celulaNoh{
    int index;
    struct celulaNoh *proximaCelula;
    struct celulaNoh *celulaAnterior;
    struct noh* conteudo;

}celulaNoh;

typedef struct escadaDeNiveis
{
    celulaNoh *nohNivel;
    celulaNoh *nohProxNivel;
    celulaNoh *nohDoNivelAnterior;
}escadaDeNiveis;

typedef struct 
{
    escadaDeNiveis* escada;
    noh *raiz;
}arvoreBinaria;

escadaDeNiveis* criarNovaEscada(escadaDeNiveis *ptr,celulaNoh *noh){
    escadaDeNiveis* escadaNova=(escadaDeNiveis *)malloc(sizeof(escadaDeNiveis));
    escadaNova->nohNivel=noh;
    escadaNova->nohDoNivelAnterior=ptr;
    ptr->nohProxNivel=escadaNova;
    escadaNova->nohProxNivel=NULL;
    return escadaNova;
}

int main(){

    return 0;
}