#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no* prox;
    struct no* ant;
    int index;
} no;

typedef struct {
    no* topo;
    no* fundo;
    int qntItens;
} pilha;

pilha* iniciarpilha() {
    pilha* ptr = (pilha*)malloc(sizeof(pilha));
    ptr->fundo = NULL;
    ptr->topo = ptr->fundo;
    ptr->qntItens = 0;
    return ptr;
}

int pilhaVazia(pilha* ptr) {
    return ptr->qntItens == 0;
}

no* criarNo(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->val = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    novo->index=NULL;
    return novo;
}

void push(pilha* ptr, int val) {
    no* novoNo = criarNo(val);
    if (pilhaVazia(ptr)) {
        ptr->fundo = ptr->topo = novoNo;
        novoNo->index=0;
    } else {
        no* aux = ptr->topo;
        ptr->topo->prox = novoNo;
        novoNo->ant = aux;
        ptr->topo = novoNo;
        novoNo->index=novoNo->ant->index+1;
    }
    ptr->qntItens++;
}

void pop(pilha* ptr) {
    if (!pilhaVazia(ptr)) {
        no* topoAntigo = ptr->topo;
        ptr->topo = topoAntigo->ant;
        free(topoAntigo);
        if (ptr->topo == NULL) {
            ptr->fundo = NULL;
        } else {
            ptr->topo->prox = NULL;
        }
        ptr->qntItens--;
    }
}

void lerPilha(pilha* ptr) {
    if (pilhaVazia(ptr)) {
        printf("A pilha está vazia.\n");
        return;
    }

    no* no = ptr->fundo;
    while (no != NULL) {
        printf("VALOR: %d [%d]\n", no->val,no->index);
        no=no->prox;
    }
}

void liberarPilha(pilha* ptr) {
    while (!pilhaVazia(ptr)) {
        pop(ptr);
    }
}

void encherPilha(pilha *pilha){
    push(pilha,1);
    push(pilha,2);
    push(pilha,3);
    push(pilha,4);
}

void subistituir(pilha *pilha, no *node, int index){
    no* no = pilha->fundo;
    while (no != NULL) {
        if(no->index==index){
            no->ant->prox=node;
            node->index=no->index;
            node->prox=no->prox;
            free(no);
            break;
        }
        else{
        no=no->prox;
        }
    }
}

void sobrescrever(pilha *pilha,no* node, int val){
    int indextopo=pilha->topo->index;
    subistituir(pilha,node,val);
    node->prox=NULL;
    while (indextopo!=node->index) {
        pop(pilha);
        indextopo--;
    }
}

int main() {
    pilha *pilha;
    pilha = iniciarpilha();
    encherPilha(pilha);
    int val;
    int resp;
    printf("\nESCOLHA O VALOR DO ITEM (inteiro):\n");
    scanf("%d",&val);
    no *novoItem=criarNo(val);
    do{
        printf("\nFORMACAO ATUAL DA PILHA: \n");
        lerPilha(pilha);
        printf("\n");
        printf("O QUE VOCE DESEJA FAZER?: \n[0] SAIR\n[1] Definir o item i como o segundo elemento a partir do topo da pilha, deixando a pilha sem seus dois elementos superiores (obs: no final, o item i sera o topo da pilha)\n[2] Definir o item i como o segundo elemento a partir do topo da pilha, deixando a pilha inalterada (obs: alterar o segundo elemento)\n[3] Dado um inteiro n, definir o item i como o n-esimo elemento a partir do topo da pilha, deixando a pilha sem seus n elementos superiores (obs: no final, o item i sera o topo da pilha)\n[4] Dado um inteiro n, definir o item i como o n-esimo elemento a partir do topo da pilha, deixando a pilha inalterada\n[5] Definir o item i como o ultimo elemento da pilha, deixando a pilha vazia (ou somente com o item i)\n[6] Definir o item i como o ultimo elemento da pilha, deixando a pilha inalterada\n[7] Definir o item i como o terceiro elemento a partir do final da pilha\n");
        scanf("%d",&resp);
        switch (resp)
        {
        case 0:
            printf("\nSAINDO...\n");
            liberarPilha(pilha);
            free(pilha);
            //system("cls");
            break;
        
        case 1:
            sobrescrever(pilha,novoItem,1);
            //system("cls");
            break;

        case 2:
            subistituir(pilha,novoItem,(pilha->topo->index)-1);
            break;

        case 3:
            printf("\nINDEX: \n");
            scanf("%d",&val);
            sobrescrever(pilha,novoItem,val);
            //system("cls");
            break;

        case 4:
            printf("\nINDEX: \n");
            scanf("%d",&val);
            subistituir(pilha,novoItem,val);
            //system("cls");
            break;
        
        case 5:
            liberarPilha(pilha);
            push(pilha,novoItem->val);
            //system("cls");
            break;
        
        case 6:
            subistituir(pilha,novoItem,pilha->topo->index);
            //system("cls");
            break;

        case 7:
            subistituir(pilha,novoItem,(pilha->topo->index)-2);
            //system("cls");
            break;

        default:
            printf("\nCOMANDO INVÁLIDO!\n");
            //system("cls");
            break;
        }
    }while (resp!=0);
   
    
    return 0;
}
