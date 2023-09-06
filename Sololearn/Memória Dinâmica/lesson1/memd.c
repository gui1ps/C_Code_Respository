#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nome;
}nome;



int main(){
    int n,tam;

    printf("Quantidade de nomes: ");
    scanf("%d",&n);

    nome nomes[n];

    if(nomes!=NULL){
        for(int i=0; i<n;i++){
            printf("Tamanho do nome %d: \n",(i+1));
            scanf("%d",&tam);
            fflush(stdin);
            nomes[i].nome=calloc(tam,sizeof(char));
            printf("Nome :");
            gets(nomes[i].nome);
            fflush(stdin);
        }

        for(int i=0; i<n;i++){
            printf("Nome: %s | [%d]\n",nomes[i].nome,i);
            free(nomes[i].nome);
        }
    }
    else
        printf("Erro ao alocar memoria");

    return 0;
}