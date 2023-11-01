#include <stdlib.h>
#include <stdio.h>

typedef struct noh
{
    int val;
    int nivel;
    struct noh *proximoDoMesmoNivel;
    struct noh *esquerda;
    struct noh *direita;
}noh;

typedef struct escadaDeNiveis
{
    noh *nohUltimoNivel;
    noh *nohDoNivelAnterior;
}escadaDeNiveis;


typedef struct 
{
    escadaDeNiveis* escada;
    noh *raiz;
}arvoreBinaria;

int verificarEscada(arvoreBinaria* avb){
    if(avb->escada==NULL){
        return 1;
    }
    return 0;
}

escadaDeNiveis* adicionarNovaCelula(noh* noh, arvoreBinaria* avb){
    escadaDeNiveis* novaEscada=(escadaDeNiveis*)malloc(sizeof(escadaDeNiveis));
    novaEscada->nohUltimoNivel=noh;
    novaEscada->nohDoNivelAnterior=avb->escada->nohUltimoNivel;
    return novaEscada;
}

noh* adicionarNoh(noh*ptr){
    noh* novo=(noh*)malloc(sizeof(noh));
    novo->proximoDoMesmoNivel=ptr;
    return novo;
}

arvoreBinaria* iniciarArvore(){
    arvoreBinaria* novaArvore=(arvoreBinaria*)malloc(sizeof(arvoreBinaria));
    noh *raizDaArvore=(noh*)malloc(sizeof(noh));
    fflush(stdin);
    printf("VALOR PARA A RAIZ: ");
    scanf("%d",raizDaArvore->val);
    raizDaArvore->nivel=0;
    novaArvore->raiz=raizDaArvore;
    novaArvore->escada->nohUltimoNivel=raizDaArvore;
    novaArvore->escada->nohDoNivelAnterior=NULL;
    raizDaArvore->proximoDoMesmoNivel=NULL;
    return novaArvore;
}

void adicionarNovoNoh(){
    
}

int main(){
    arvoreBinaria* arvoreInicial=iniciarArvore();
    return 0;
}